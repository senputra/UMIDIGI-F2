/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

/****************************************************************
 * Licensed to the Apache Software Foundation (ASF) under one   *
 * or more contributor license agreements.  See the NOTICE file *
 * distributed with this work for additional information        *
 * regarding copyright ownership.  The ASF licenses this file   *
 * to you under the Apache License, Version 2.0 (the            *
 * "License"); you may not use this file except in compliance   *
 * with the License.  You may obtain a copy of the License at   *
 *                                                              *
 *   http://www.apache.org/licenses/LICENSE-2.0                 *
 *                                                              *
 * Unless required by applicable law or agreed to in writing,   *
 * software distributed under the License is distributed on an  *
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY       *
 * KIND, either express or implied.  See the License for the    *
 * specific language governing permissions and limitations      *
 * under the License.                                           *
 ****************************************************************/

package org.apache.james.mime4j.decoder;


import java.io.IOException;
import java.io.InputStream;

/**
 * Performs Quoted-Printable decoding on an underlying stream.
 * @version $Id: QuotedPrintableInputStream.java,v 1.3 2004/11/29 13:15:47 ntherning Exp $
 */
public class QuotedPrintableInputStream extends InputStream {
    private InputStream stream;
    ByteQueue byteq = new ByteQueue();
    ByteQueue pushbackq = new ByteQueue();
    private byte state = 0;

    public QuotedPrintableInputStream(InputStream stream) {
        this.stream = stream;
    }

    /**
     * Closes the underlying stream.
     *
     * @throws IOException on I/O errors.
     */
    public void close() throws IOException {
        stream.close();
    }

    public int read() throws IOException {
        fillBuffer();
        if (byteq.count() == 0)
            return -1;
        else {
            byte val = byteq.dequeue();
            if (val >= 0)
                return val;
            else
                return val & 0xFF;
        }
    }

    /**
     * Pulls bytes out of the underlying stream and places them in the
     * pushback queue.  This is necessary (vs. reading from the
     * underlying stream directly) to detect and filter out "transport
     * padding" whitespace, i.e., all whitespace that appears immediately
     * before a CRLF.
     *
     * @throws IOException Underlying stream threw IOException.
     */
    private void populatePushbackQueue() throws IOException {
        //Debug.verify(pushbackq.count() == 0, "PopulatePushbackQueue called when pushback queue was not empty!");

        if (pushbackq.count() != 0)
            return;

        while (true) {
            int i = stream.read();
            switch (i) {
                case -1:
                    // stream is done
                    pushbackq.clear();  // discard any whitespace preceding EOF
                    return;
                case ' ':
                case '\t':
                    pushbackq.enqueue((byte) i);
                    break;
                case '\r':
                case '\n':
                    pushbackq.clear();  // discard any whitespace preceding EOL
                    pushbackq.enqueue((byte) i);
                    return;
                default:
                    pushbackq.enqueue((byte) i);
                    return;
            }
        }
    }

    /**
     * Causes the pushback queue to get populated if it is empty, then
     * consumes and decodes bytes out of it until one or more bytes are
     * in the byte queue.  This decoding step performs the actual QP
     * decoding.
     *
     * @throws IOException Underlying stream threw IOException.
     */
    private void fillBuffer() throws IOException {
        byte msdChar = 0;  // first digit of escaped num
        while (byteq.count() == 0) {
            if (pushbackq.count() == 0) {
                populatePushbackQueue();
                if (pushbackq.count() == 0)
                    return;
            }

            byte b = (byte) pushbackq.dequeue();

            switch (state) {
                case 0:  // start state, no bytes pending
                    if (b != '=') {
                        byteq.enqueue(b);
                        break;  // state remains 0
                    } else {
                        state = 1;
                        break;
                    }
                case 1:  // encountered "=" so far
                    if (b == '\r') {
                        state = 2;
                        break;
                    } else if ((b >= '0' && b <= '9') || (b >= 'A' && b <= 'F') || (b >= 'a' && b <= 'f')) {
                        state = 3;
                        msdChar = b;  // save until next digit encountered
                        break;
                    } else if (b == '=') {
                        /*
                         * Special case when == is encountered.
                         * Emit one = and stay in this state.
                         */
                        byteq.enqueue((byte) '=');
                        break;
                    } else {
                        state = 0;
                        byteq.enqueue((byte) '=');
                        byteq.enqueue(b);
                        break;
                    }
                case 2:  // encountered "=\r" so far
                    if (b == '\n') {
                        state = 0;
                        break;
                    } else {
                        state = 0;
                        byteq.enqueue((byte) '=');
                        byteq.enqueue((byte) '\r');
                        byteq.enqueue(b);
                        break;
                    }
                case 3:  // encountered =<digit> so far; expecting another <digit> to complete the octet
                    if ((b >= '0' && b <= '9') || (b >= 'A' && b <= 'F') || (b >= 'a' && b <= 'f')) {
                        byte msd = asciiCharToNumericValue(msdChar);
                        byte low = asciiCharToNumericValue(b);
                        state = 0;
                        byteq.enqueue((byte) ((msd << 4) | low));
                        break;
                    } else {
                        state = 0;
                        byteq.enqueue((byte) '=');
                        byteq.enqueue(msdChar);
                        byteq.enqueue(b);
                        break;
                    }
                default:  // should never happen
                    state = 0;
                    byteq.enqueue(b);
                    break;
            }
        }
    }

    /**
     * Converts '0' => 0, 'A' => 10, etc.
     * @param c ASCII character value.
     * @return Numeric value of hexadecimal character.
     */
    private byte asciiCharToNumericValue(byte c) {
        if (c >= '0' && c <= '9') {
            return (byte) (c - '0');
        } else if (c >= 'A' && c <= 'Z') {
            return (byte) (0xA + (c - 'A'));
        } else if (c >= 'a' && c <= 'z') {
            return (byte) (0xA + (c - 'a'));
        } else {
            /*
             * This should never happen since all calls to this method
             * are preceded by a check that c is in [0-9A-Za-z]
             */
            throw new IllegalArgumentException((char) c
                    + " is not a hexadecimal digit");
        }
    }

}
