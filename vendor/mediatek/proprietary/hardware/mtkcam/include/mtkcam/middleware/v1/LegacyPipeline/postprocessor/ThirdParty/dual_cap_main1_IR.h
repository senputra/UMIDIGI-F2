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
 * MediaTek Inc. (C) 2017. All rights reserved.
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
//
// main1 frame
// IMGO RAW: YES
// RRZO RAW: YES
//
PIPELINE_TABLE_BEGIN(BackgroundServiceData, PP, DUAL_CAP_MAIN1_IR)
    // ==================================================================
    // Create metadata table
    // ==================================================================
    METADATA_BEGIN(BGMetaTbl)
        METADATA_STREAM_ADD("App:Meta:Control", eSTREAMID_META_APP_CONTROL, IN, 0, 0, APP)
        METADATA_STREAM_ADD("Hal:Meta:Control", eSTREAMID_META_HAL_CONTROL, IN, 0, 0, HAL)
    METADATA_END()
    // ==================================================================
    // Create image table
    // ==================================================================
    IMAGE_BEGIN(BGImgStreamTbl)
        IMAGE_STREAM_ADD("Hal:Image:TP_YUV_00",     eSTREAMID_IMAGE_PIPE_YUV_00,        INOUT, 0, 0, CAM_SW_READWRITE_HW_READWRITE, eImgFmt_YV12, MSize(1, 1), 0, 0, HAL_PROVIDER)
        IMAGE_STREAM_ADD("Hal:Image:TP_YUV_01",     eSTREAMID_IMAGE_PIPE_YUV_01,        INOUT, 0, 0, CAM_SW_READWRITE_HW_READWRITE, eImgFmt_YV12, MSize(1, 1), 0, 0, HAL_PROVIDER)
        IMAGE_STREAM_ADD("Hal:Image:TP_YUV_02",     eSTREAMID_IMAGE_PIPE_YUV_02,        INOUT, 0, 0, CAM_SW_READWRITE_HW_READWRITE, eImgFmt_YV12, MSize(1, 1), 0, 0, HAL_PROVIDER)
    IMAGE_END()
    // ==================================================================
    // Create node table
    // ==================================================================
    NODE_BEGIN(BGConnectSetting)
        NODE_ADD(eNODEID_TPNode,  -1)
    NODE_END()
PIPELINE_TABLE_END()
