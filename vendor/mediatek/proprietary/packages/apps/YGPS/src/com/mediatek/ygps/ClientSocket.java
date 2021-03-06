/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

package com.mediatek.ygps;

import android.util.Log;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;



/**
 * Client socket, used to connect with GPS server and communicate with PMTK.
 * command
 *
 * @author mtk54046
 * @version 1.0
 */
public class ClientSocket {

    private static final int MASK_8_BIT = 0xFF;
    private static final int SOCKET_TIME_OUT_TIME = 2000;
    private static final int BUFFER_SIZE = 1024;
    private static final String TAG = "YGPS/ClientSocket";
    private static final int SERVER_PORT = 7000;
    private Socket mClientSocket = null;
    private DataInputStream mDataInput = null;
    private DataOutputStream mDataOutput = null;
    private String mCommand = null;
    private String mResponse = null;
    private BlockingQueue<String> mCommandQueue = null;
    private YgpsActivity mCallBack = null;
    private Thread mSendThread = null;
    private byte[] mDataBuffer = null;
    private static final String[][] CMD_RESPONSE = {
        {"PMTK605", "$PMTK705"},
        {"PMTK837", "PMTK001"},
    };
    /**
     * Constructor, initial parameters and start thread to send/receive.
     *
     * @param callBack
     *            Callback when message received
     */
    public ClientSocket(YgpsActivity callBack) {
        this.mCallBack = callBack;
        mCommandQueue = new LinkedBlockingQueue<String>();
        mDataBuffer = new byte[BUFFER_SIZE];
        mSendThread = new Thread(new Runnable() {

            public void run() {
                while (true) {
                    try {
                        mCommand = mCommandQueue.take();
                        Log.v(TAG, "Queue take command:" + mCommand);
                    } catch (InterruptedException ie) {
                        Log.w(TAG, "Take command interrupted:" + ie.getMessage());
                        return;
                    }
                    openClient();
                    if (null != mDataOutput && null != mDataInput) {
                        try {
                            // in = new
                            // DataInputStream(localSocket.getInputStream());
                            mDataOutput.writeBytes(mCommand);
                            mDataOutput.write('\r');
                            mDataOutput.write('\n');
                            mDataOutput.flush();
                            String result = null;
                            int line = 0;
                            int count = -1;
                            String tarRes = "PMTK";
                            for (String[] pair: CMD_RESPONSE) {
                                if (mCommand.contains(pair[0])) {
                                    tarRes = pair[1];
                                    break;
                                }
                            }
                            long startTime = System.currentTimeMillis();
                            while ((count = mDataInput.read(mDataBuffer)) != -1) {

                                line++;
                                result = new String(mDataBuffer, 0, count);
                                if (result.contains(tarRes)) {
                                    int startIndex = result.indexOf(tarRes);
                                    String strTemp = result.substring(startIndex);
                                    int endIndex = strTemp.indexOf("*");
                                    if (endIndex != -1) {
                                        mResponse = strTemp.substring(0, endIndex);
                                        if (ClientSocket.this.mCallBack != null) {
                                            ClientSocket.this.mCallBack.onResponse(mResponse);
                                        }
                                    }
                                    break;
                                }
                                long receiveTime = System.currentTimeMillis();
                                if ((receiveTime - startTime) > SOCKET_TIME_OUT_TIME) {
                                    Log.e(TAG, "check time timeout");
                                    break;
                                }
                            }
                        } catch (IOException e) {
                            Log.w(TAG, "sendCommand IOException: " + e.getMessage());
                        }
                    }

                    mCommand = null;
                    closeClient();
                }
            }
        });
        mSendThread.start();
    }

    /**
     * Start client socket and connect with server.
     */
    private void openClient() {
        Log.v(TAG, "enter startClient");
        if (null != mClientSocket && mClientSocket.isConnected()) {
            Log.i(TAG, "localSocket has started, return");
            return;
        }
        try {
            mClientSocket = new Socket("127.0.0.1", SERVER_PORT);
            mClientSocket.setSoTimeout(SOCKET_TIME_OUT_TIME);
            mDataOutput = new DataOutputStream(mClientSocket.getOutputStream());
            mDataInput = new DataInputStream(mClientSocket.getInputStream());
        } catch (UnknownHostException e) {
            Log.e(TAG, e.getMessage());
        } catch (IOException e) {
            Log.e(TAG, e.getMessage());
        }
    }

    /**
     * Stop client socket and disconnect with server.
     */
    private void closeClient() {
        Log.v(TAG, "enter closeClient");
        try {
            if (null != mDataInput) {
                mDataInput.close();
            }
            if (null != mDataOutput) {
                mDataOutput.close();
            }
            if (null != mClientSocket) {
                mClientSocket.close();
            }
        } catch (IOException e) {
            Log.e(TAG, "closeClient IOException: " + e.getMessage());
        } finally {
            mClientSocket = null;
            mDataInput = null;
            mDataOutput = null;
        }
    }

    /**
     * Finalize communicate with socket server.
     */
    void endClient() {
        Log.v(TAG, "enter endClient");
        mSendThread.interrupt();
        Log.i(TAG, "Queue remaining:" + mCommandQueue.size());
        closeClient();
        mCallBack = null;
    }

    /**
     * Send command to socket server.
     *
     * @param command
     *            Command need to send
     */
    void sendCommand(String command) {
        String sendComm = "$" + command + "*" + calcCS(command);
        Log.i(TAG, "Send command: " + sendComm);
        if (!mSendThread.isAlive()) {
            Log.w(TAG, "sendThread is not alive");
            mSendThread.start();
        }
        if (command.equals(sendComm) || mCommandQueue.contains(sendComm)) {
            Log.i(TAG, "send command return because of hasn't handle the same");
            return;
        }
        try {
            mCommandQueue.put(sendComm);
        } catch (InterruptedException ie) {
            Log.e(TAG, "send command interrupted:" + ie.getMessage());
        }
    }

    /**
     * Calculate check sum for PMTK command.
     *
     * @param command
     *            The command need to send
     * @return The check sum string
     */
    private String calcCS(String command) {
        if (null == command || "".equals(command)) {
            return "";
        }
        byte[] ba = command.toUpperCase().getBytes();
        int temp = 0;
        for (byte b : ba) {
            temp ^= b;
        }
        return String.format("%1$02x", temp & MASK_8_BIT).toUpperCase();
    }
}
