/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2017. All rights reserved.
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
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

package com.mediatek.opcommon.telephony;

public interface MtkRILConstantsOp {
    /*********************************************************************************/
    /*  Vendor request                                                               */
    /*********************************************************************************/
    int RIL_REQUEST_VENDOR_OP_BASE = 11000;
    int RIL_REQUEST_SET_DIGITS_LINE = RIL_REQUEST_VENDOR_OP_BASE + 1;
    int RIL_REQUEST_SET_TRN = RIL_REQUEST_VENDOR_OP_BASE + 2;
    int RIL_REQUEST_DIAL_FROM = RIL_REQUEST_VENDOR_OP_BASE + 3;
    int RIL_REQUEST_SEND_USSI_FROM = RIL_REQUEST_VENDOR_OP_BASE + 4;
    int RIL_REQUEST_CANCEL_USSI_FROM = RIL_REQUEST_VENDOR_OP_BASE + 5;
    int RIL_REQUEST_SET_EMERGENCY_CALL_CONFIG = RIL_REQUEST_VENDOR_OP_BASE + 6;
    int RIL_REQUEST_SET_DISABLE_2G = RIL_REQUEST_VENDOR_OP_BASE + 7;
    int RIL_REQUEST_GET_DISABLE_2G = RIL_REQUEST_VENDOR_OP_BASE + 8;
    int RIL_REQUEST_DEVICE_SWITCH = RIL_REQUEST_VENDOR_OP_BASE + 9;
    int RIL_REQUEST_CANCEL_DEVICE_SWITCH = RIL_REQUEST_VENDOR_OP_BASE + 10;
    int RIL_REQUEST_SET_INCOMING_VIRTUAL_LINE = RIL_REQUEST_VENDOR_OP_BASE + 11;
    int RIL_REQUEST_EXIT_SCBM = RIL_REQUEST_VENDOR_OP_BASE + 12;
    int RIL_REQUEST_SEND_RSU_REQUEST = RIL_REQUEST_VENDOR_OP_BASE + 13;
    int RIL_REQUEST_SWITCH_RCS_ROI_STATUS = RIL_REQUEST_VENDOR_OP_BASE + 15;
    int RIL_REQUEST_UPDATE_RCS_CAPABILITIES = RIL_REQUEST_VENDOR_OP_BASE + 16;
    int RIL_REQUEST_UPDATE_RCS_SESSION_INFO = RIL_REQUEST_VENDOR_OP_BASE + 17;
    /*********************************************************************************/
    /*  Vendor unsol                                                                 */
    /*********************************************************************************/
    int RIL_UNSOL_VENDOR_OP_BASE = 12000;
    int RIL_UNSOL_DIGITS_LINE_INDICATION = RIL_UNSOL_VENDOR_OP_BASE + 1;
    int RIL_UNSOL_GET_TRN_INDICATION = RIL_REQUEST_VENDOR_OP_BASE + 2;
    int RIL_UNSOL_MELOCK_NOTIFICATION = RIL_UNSOL_VENDOR_OP_BASE + 3;
    int RIL_UNSOL_ENTER_SCBM = RIL_UNSOL_VENDOR_OP_BASE + 4;
    int RIL_UNSOL_EXIT_SCBM = RIL_UNSOL_VENDOR_OP_BASE + 5;
    int RIL_UNSOL_RSU_EVENT = RIL_UNSOL_VENDOR_OP_BASE + 6;
}
