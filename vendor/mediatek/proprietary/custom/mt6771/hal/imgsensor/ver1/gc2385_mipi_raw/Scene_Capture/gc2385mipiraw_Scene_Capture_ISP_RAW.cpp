/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2020. All rights reserved.
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

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#include "camera_custom_nvram.h"
#include "gc2385mipiraw_Scene_Capture.h"

const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0000 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0001 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0002 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0003 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0004 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0005 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0006 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0007 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0008 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0009 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0010 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0011 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0012 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0013 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0014 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0015 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0016 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0017 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0018 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_DBS_T gc2385mipiraw_DBS_0019 = {
        .sigma     ={.bits={.DBS_OFST=5, .rsv_12=0, .DBS_SL=21, .rsv_24=0}},
    .bstbl_0   ={.bits={.DBS_BIAS_Y0=4, .DBS_BIAS_Y1=2, .DBS_BIAS_Y2=1, .DBS_BIAS_Y3=0}},
    .bstbl_1   ={.bits={.DBS_BIAS_Y4=0, .DBS_BIAS_Y5=0, .DBS_BIAS_Y6=0, .DBS_BIAS_Y7=0}},
    .bstbl_2   ={.bits={.DBS_BIAS_Y8=0, .DBS_BIAS_Y9=0, .DBS_BIAS_Y10=0, .DBS_BIAS_Y11=0}},
    .bstbl_3   ={.bits={.DBS_BIAS_Y12=0, .DBS_BIAS_Y13=0, .DBS_BIAS_Y14=0, .rsv_24=0}},
    .ctl       ={.bits={.DBS_HDR_GNP=0, .rsv_3=0, .DBS_SL_EN=0, .rsv_5=0, .DBS_LE_INV_CTL=0, .DBS_EDGE=15, .DBS_HDR_GAIN=64, .DBS_HDR_GAIN2=8}},
    .sigma_2   ={.bits={.DBS_MUL_B=96, .DBS_MUL_GB=96, .DBS_MUL_GR=96, .DBS_MUL_R=96}},
    .ygn       ={.bits={.DBS_YGN_B=32, .rsv_6=0, .DBS_YGN_GB=32, .rsv_14=0, .DBS_YGN_GR=32, .rsv_22=0, .DBS_YGN_R=32, .rsv_30=0}},
    .sl_y12    ={.bits={.DBS_SL_Y1=0, .rsv_10=0, .DBS_SL_Y2=0, .rsv_26=0}},
    .sl_y34    ={.bits={.DBS_SL_Y3=0, .rsv_10=0, .DBS_SL_Y4=0, .rsv_26=0}},
    .sl_g12    ={.bits={.DBS_SL_G1=0, .rsv_10=0, .DBS_SL_G2=0, .rsv_26=0}},
    .sl_g34    ={.bits={.DBS_SL_G3=0, .rsv_10=0, .DBS_SL_G4=0, .rsv_26=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0000 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0001 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0002 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0003 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0004 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0005 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0006 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0007 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0008 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0009 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0010 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0011 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0012 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0013 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0014 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0015 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0016 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0017 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0018 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_ADBS_T gc2385mipiraw_ADBS_0019 = {
        .gray_bld_0={.bits={.ADBS_LUMA_MODE=0, .rsv_1=0, .ADBS_BLD_MXRT=0, .rsv_24=0}},
    .gray_bld_1={.bits={.ADBS_BLD_LOW=269, .rsv_12=0, .ADBS_BLD_SLP=341, .rsv_28=0}},
    .bias_lut_r0={.bits={.ADBS_BIAS_R0=0, .ADBS_BIAS_R1=0, .ADBS_BIAS_R2=0, .ADBS_BIAS_R3=0}},
    .bias_lut_r1={.bits={.ADBS_BIAS_R4=0, .ADBS_BIAS_R5=0, .ADBS_BIAS_R6=0, .ADBS_BIAS_R7=0}},
    .bias_lut_r2={.bits={.ADBS_BIAS_R8=0, .ADBS_BIAS_R9=0, .ADBS_BIAS_R10=0, .ADBS_BIAS_R11=0}},
    .bias_lut_r3={.bits={.ADBS_BIAS_R12=0, .ADBS_BIAS_R13=0, .ADBS_BIAS_R14=0, .rsv_24=0}},
    .bias_lut_g0={.bits={.ADBS_BIAS_G0=0, .ADBS_BIAS_G1=0, .ADBS_BIAS_G2=0, .ADBS_BIAS_G3=0}},
    .bias_lut_g1={.bits={.ADBS_BIAS_G4=0, .ADBS_BIAS_G5=0, .ADBS_BIAS_G6=0, .ADBS_BIAS_G7=0}},
    .bias_lut_g2={.bits={.ADBS_BIAS_G8=0, .ADBS_BIAS_G9=0, .ADBS_BIAS_G10=0, .ADBS_BIAS_G11=0}},
    .bias_lut_g3={.bits={.ADBS_BIAS_G12=0, .ADBS_BIAS_G13=0, .ADBS_BIAS_G14=0, .rsv_24=0}},
    .bias_lut_b0={.bits={.ADBS_BIAS_B0=0, .ADBS_BIAS_B1=0, .ADBS_BIAS_B2=0, .ADBS_BIAS_B3=0}},
    .bias_lut_b1={.bits={.ADBS_BIAS_B4=0, .ADBS_BIAS_B5=0, .ADBS_BIAS_B6=0, .ADBS_BIAS_B7=0}},
    .bias_lut_b2={.bits={.ADBS_BIAS_B8=0, .ADBS_BIAS_B9=0, .ADBS_BIAS_B10=0, .ADBS_BIAS_B11=0}},
    .bias_lut_b3={.bits={.ADBS_BIAS_B12=0, .ADBS_BIAS_B13=0, .ADBS_BIAS_B14=0, .rsv_24=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0000 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7936, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0001 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7936, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0002 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7936, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0003 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7936, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0004 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7936, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0005 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7936, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0006 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7936, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0007 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7936, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0008 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7936, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0009 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7936, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0010 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7936, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0011 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7936, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0012 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7935, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0013 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7934, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0014 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7934, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0015 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7934, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0016 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7934, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0017 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7934, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0018 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7934, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_OBC_T gc2385mipiraw_OBC_0019 = {
        .offst0    ={.bits={.OBC_OFST_B=7936, .rsv_13=0}},
    .offst1    ={.bits={.OBC_OFST_GR=7936, .rsv_13=0}},
    .offst2    ={.bits={.OBC_OFST_GB=7936, .rsv_13=0}},
    .offst3    ={.bits={.OBC_OFST_R=7936, .rsv_13=0}},
    .gain0     ={.bits={.OBC_GAIN_B=546, .rsv_13=0}},
    .gain1     ={.bits={.OBC_GAIN_GR=546, .rsv_13=0}},
    .gain2     ={.bits={.OBC_GAIN_GB=546, .rsv_13=0}},
    .gain3     ={.bits={.OBC_GAIN_R=546, .rsv_13=0}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0000 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=0, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=150, .BPC_TH_Y=300, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=550, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=150, .BPC_DK_TH_XB=700, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=27, .BPC_C_TH_Y=128, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=250, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=6, .BPC_C_TH_SLB=2}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0001 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=101, .BPC_TH_Y=251, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=501, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=101, .BPC_DK_TH_XB=651, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=147, .BPC_C_TH_Y=281, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=494, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0002 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=101, .BPC_TH_Y=251, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=501, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=101, .BPC_DK_TH_XB=651, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=147, .BPC_C_TH_Y=281, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=494, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0003 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=125, .BPC_TH_Y=275, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=525, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=125, .BPC_DK_TH_XB=675, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=68, .BPC_C_TH_Y=186, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=348, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=7, .BPC_C_TH_SLB=3}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0004 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=101, .BPC_TH_Y=251, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=501, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=101, .BPC_DK_TH_XB=651, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=147, .BPC_C_TH_Y=281, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=494, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0005 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=500, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=650, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=149, .BPC_C_TH_Y=283, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=497, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0006 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=500, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=650, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=149, .BPC_C_TH_Y=283, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=497, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0007 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=500, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=650, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=149, .BPC_C_TH_Y=284, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=498, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0008 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=500, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=650, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=149, .BPC_C_TH_Y=284, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=498, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0009 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=500, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=650, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=149, .BPC_C_TH_Y=284, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=498, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0010 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=500, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=650, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=149, .BPC_C_TH_Y=284, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=498, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0011 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=500, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=650, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=149, .BPC_C_TH_Y=284, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=498, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0012 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=500, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=650, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=149, .BPC_C_TH_Y=284, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=498, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0013 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=500, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=650, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=149, .BPC_C_TH_Y=284, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=498, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0014 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=1024, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=1024, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=2, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=3, .BPC_RANK_IDXG=3, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=140, .BPC_C_TH_Y=284, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=1024, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0015 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=1024, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=1024, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=2, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=3, .BPC_RANK_IDXG=3, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=140, .BPC_C_TH_Y=284, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=1024, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0016 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=1024, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=1024, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=2, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=3, .BPC_RANK_IDXG=3, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=140, .BPC_C_TH_Y=284, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=1024, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0017 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=1024, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=1024, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=2, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=3, .BPC_RANK_IDXG=3, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=140, .BPC_C_TH_Y=284, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=1024, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0018 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=500, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=650, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=149, .BPC_C_TH_Y=284, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=498, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_BPC_T gc2385mipiraw_BNR_BPC_0019 = {
        .con       ={.bits={.BPC_EN=1, .rsv_1=0, .BPC_LUT_EN=1, .BPC_TABLE_END_MODE=1, .rsv_6=0, .BPC_AVG_MODE=0, .rsv_9=0, .BPC_DTC_MODE=0, .BPC_CS_MODE=2, .BPC_CRC_MODE=0, .BPC_EXC=1, .BPC_BLD_MODE=1, .BNR_LE_INV_CTL=0, .BNR_OSC_COUNT=5, .BNR_EDGE=15}},
    .th1       ={.bits={.BPC_TH_LWB=100, .BPC_TH_Y=250, .BPC_BLD_SLP0=5}},
    .th2       ={.bits={.BPC_TH_UPB=500, .rsv_12=0, .BPC_BLD0=0, .rsv_23=0, .BPC_BLD1=64, .rsv_31=0}},
    .th3       ={.bits={.BPC_TH_XA=0, .BPC_TH_XB=400, .BPC_TH_SLA=12, .BPC_TH_SLB=3}},
    .th4       ={.bits={.BPC_DK_TH_XA=100, .BPC_DK_TH_XB=650, .BPC_DK_TH_SLA=9, .BPC_DK_TH_SLB=3}},
    .dtc       ={.bits={.BPC_RNG=1, .BPC_CS_RNG=3, .rsv_7=0, .BPC_CT_LV=0, .rsv_12=0, .BPC_TH_MUL=10, .rsv_20=0, .BPC_NO_LV=3, .rsv_27=0}},
    .cor       ={.bits={.BPC_DIR_MAX=25, .BPC_DIR_TH=5, .BPC_RANK_IDXR=1, .BPC_RANK_IDXG=1, .rsv_22=0, .BPC_DIR_TH2=5}},
    .th1_c     ={.bits={.BPC_C_TH_LWB=149, .BPC_C_TH_Y=284, .rsv_24=0}},
    .th2_c     ={.bits={.BPC_C_TH_UPB=498, .rsv_12=0, .BPC_RANK_IDXB=1, .BPC_BLD_LWB=200, .rsv_28=0}},
    .th3_c     ={.bits={.BPC_C_TH_XA=160, .BPC_C_TH_XB=700, .BPC_C_TH_SLA=8, .BPC_C_TH_SLB=4}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0000 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=1, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=0, .NR1_CT_THRD=0, .rsv_14=0, .NR1_MBND=1023, .rsv_26=0, .NR1_CT_SLOPE=0, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0001 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0002 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0003 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0004 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0005 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0006 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0007 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0008 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0009 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0010 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0011 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0012 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0013 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0014 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0015 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0016 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0017 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0018 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_NR1_T gc2385mipiraw_BNR_NR1_0019 = {
        .con       ={.bits={.rsv_0=0, .NR1_CT_EN=0, .rsv_5=0}},
    .ct_con    ={.bits={.NR1_CT_MD=0, .NR1_CT_MD2=1, .NR1_CT_THRD=30, .rsv_14=0, .NR1_MBND=160, .rsv_26=0, .NR1_CT_SLOPE=1, .NR1_CT_DIV=0}},
    .ct_con2   ={.bits={.NR1_CT_LWB=0, .rsv_12=0, .NR1_CT_UPB=0, .rsv_28=0}},
    .ct_con3   ={.bits={.NR1_CT_LSP=1, .rsv_5=0, .NR1_CT_USP=1, .rsv_13=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0000 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0001 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0002 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0003 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0004 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0005 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0006 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0007 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0008 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0009 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0010 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0011 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0012 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0013 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0014 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0015 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0016 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0017 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0018 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_BNR_PDC_T gc2385mipiraw_BNR_PDC_0019 = {
        .con       ={.bits={.PDC_EN=1, .rsv_1=0, .PDC_CT=1, .rsv_5=0, .PDC_MODE=1, .rsv_10=0, .PDC_OUT=1, .rsv_17=0}},
    .gain_l0   ={.bits={.PDC_GCF_L00=256, .rsv_12=0, .PDC_GCF_L10=0, .rsv_28=0}},
    .gain_l1   ={.bits={.PDC_GCF_L01=0, .rsv_12=0, .PDC_GCF_L20=0, .rsv_28=0}},
    .gain_l2   ={.bits={.PDC_GCF_L11=0, .rsv_12=0, .PDC_GCF_L02=0, .rsv_28=0}},
    .gain_l3   ={.bits={.PDC_GCF_L30=0, .rsv_12=0, .PDC_GCF_L21=0, .rsv_28=0}},
    .gain_l4   ={.bits={.PDC_GCF_L12=0, .rsv_12=0, .PDC_GCF_L03=0, .rsv_28=0}},
    .gain_r0   ={.bits={.PDC_GCF_R00=256, .rsv_12=0, .PDC_GCF_R10=0, .rsv_28=0}},
    .gain_r1   ={.bits={.PDC_GCF_R01=0, .rsv_12=0, .PDC_GCF_R20=0, .rsv_28=0}},
    .gain_r2   ={.bits={.PDC_GCF_R11=0, .rsv_12=0, .PDC_GCF_R02=0, .rsv_28=0}},
    .gain_r3   ={.bits={.PDC_GCF_R30=0, .rsv_12=0, .PDC_GCF_R21=0, .rsv_28=0}},
    .gain_r4   ={.bits={.PDC_GCF_R12=0, .rsv_12=0, .PDC_GCF_R03=0, .rsv_28=0}},
    .th_gb     ={.bits={.PDC_GTH=200, .rsv_12=0, .PDC_BTH=40, .rsv_28=0}},
    .th_ia     ={.bits={.PDC_ITH=0, .rsv_12=0, .PDC_ATH=300, .rsv_28=0}},
    .th_hd     ={.bits={.PDC_NTH=80, .rsv_12=0, .PDC_DTH=512, .rsv_28=0}},
    .sl        ={.bits={.PDC_GSL=8, .PDC_BSL=6, .PDC_ISL=7, .PDC_ASL=7, .PDC_GCF_NORM=13, .rsv_20=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0000 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0001 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0002 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0003 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0004 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0005 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0006 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0007 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0008 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0009 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0010 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0011 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0012 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0013 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0014 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0015 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0016 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0017 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0018 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RMM_T gc2385mipiraw_RMM_0019 = {
        .osc       ={.bits={.RMM_OSC_TH=1004, .RMM_SEDIR_SL=4, .rsv_15=0, .RMM_SEBLD_WD=1, .RMM_LEBLD_WD=1, .RMM_LE_INV_CTL=0, .RMM_EDGE=15}},
    .mc        ={.bits={.RMM_MO_EDGE=1, .rsv_1=0, .RMM_MO_EN=1, .rsv_3=0, .RMM_MOBLD_FT=4, .rsv_7=0, .RMM_MOTH_RATIO=2, .rsv_13=0, .RMM_HORI_ADDWT=4, .rsv_21=0}},
    .mc2       ={.bits={.RMM_MOSE_TH=128, .rsv_12=0, .RMM_MOSE_BLDWD=5, .rsv_20=0}},
    .ma        ={.bits={.RMM_MASE_RATIO=8, .rsv_5=0, .RMM_OSBLD_WD=4, .RMM_MASE_BLDWD=8, .RMM_SENOS_LEFAC=8, .rsv_21=0, .RMM_SEYOS_LEFAC=8, .rsv_29=0}},
    .tune      ={.bits={.RMM_PSHOR_SEEN=1, .RMM_PS_BLUR=1, .rsv_2=0, .RMM_OSC_REPEN=1, .RMM_SOFT_TH_EN=0, .RMM_LE_LOWPA_EN=0, .RMM_SE_LOWPA_EN=0, .RMM_PSSEC_ONLY=0, .rsv_9=0, .RMM_OSCLE_ONLY=0, .rsv_13=0, .RMM_PS_TH=128, .RMM_MOLE_DIREN=1, .RMM_MOSE_DIREN=1, .RMM_MO_2DBLD_EN=1, .rsv_31=0}},
    .ridx      ={.bits={.RMM_OSC_IDX=255, .RMM_PS_IDX=16, .RMM_MOSE_IDX=12, .rsv_25=0}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0000 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=4, .RNR_RNG2=6, .RNR_RNG3=8, .RNR_RNG4=12, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=53, .RNR_SSL_C1=20, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0001 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=4, .RNR_RNG2=6, .RNR_RNG3=8, .RNR_RNG4=12, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=20, .RNR_SSL_C1=53, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0002 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=4, .RNR_RNG2=6, .RNR_RNG3=8, .RNR_RNG4=12, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=20, .RNR_SSL_C1=53, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0003 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=4, .RNR_RNG2=6, .RNR_RNG3=8, .RNR_RNG4=12, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=20, .RNR_SSL_C1=53, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0004 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=4, .RNR_RNG2=6, .RNR_RNG3=8, .RNR_RNG4=12, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=20, .RNR_SSL_C1=53, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0005 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=4, .RNR_RNG2=6, .RNR_RNG3=8, .RNR_RNG4=12, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=21, .RNR_SSL_C1=52, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0006 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=4, .RNR_RNG2=6, .RNR_RNG3=8, .RNR_RNG4=12, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=27, .RNR_SSL_C1=46, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0007 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=4, .RNR_RNG2=6, .RNR_RNG3=8, .RNR_RNG4=12, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=35, .RNR_SSL_C1=38, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0008 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=4, .RNR_RNG2=6, .RNR_RNG3=8, .RNR_RNG4=12, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=42, .RNR_SSL_C1=31, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0009 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=4, .RNR_RNG2=6, .RNR_RNG3=8, .RNR_RNG4=12, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=48, .RNR_SSL_C1=25, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0010 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=4, .RNR_RNG2=6, .RNR_RNG3=8, .RNR_RNG4=12, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=48, .RNR_SSL_C1=25, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0011 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=4, .RNR_RNG2=6, .RNR_RNG3=8, .RNR_RNG4=12, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=47, .RNR_SSL_C1=26, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0012 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=4, .RNR_RNG2=7, .RNR_RNG3=9, .RNR_RNG4=13, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=44, .RNR_SSL_C1=29, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0013 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=4, .RNR_RNG2=7, .RNR_RNG3=10, .RNR_RNG4=15, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=40, .RNR_SSL_C1=33, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0014 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=5, .RNR_RNG2=8, .RNR_RNG3=12, .RNR_RNG4=17, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=36, .RNR_SSL_C1=37, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0015 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=5, .RNR_RNG2=9, .RNR_RNG3=13, .RNR_RNG4=18, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=31, .RNR_SSL_C1=42, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0016 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=5, .RNR_RNG2=10, .RNR_RNG3=15, .RNR_RNG4=20, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=27, .RNR_SSL_C1=46, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0017 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=5, .RNR_RNG2=10, .RNR_RNG3=15, .RNR_RNG4=20, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=27, .RNR_SSL_C1=46, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0018 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=5, .RNR_RNG2=10, .RNR_RNG3=15, .RNR_RNG4=20, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=27, .RNR_SSL_C1=46, .RNR_STH_C1=53}}

};
const ISP_NVRAM_RNR_T gc2385mipiraw_RNR_0019 = {
        .con1      ={.bits={.RNR_RAT=256, .RNR_EPS=1, .rsv_17=0}},
    .vc0       ={.bits={.RNR_VC0_R=392, .RNR_VC0_G=392, .RNR_VC0_B=392, .rsv_27=0}},
    .vc1       ={.bits={.RNR_VC1_R=185, .RNR_VC1_G=185, .RNR_VC1_B=185, .rsv_27=0}},
    .rng       ={.bits={.RNR_RNG1=5, .RNR_RNG2=10, .RNR_RNG3=15, .RNR_RNG4=20, .rsv_24=0}},
    .con2      ={.bits={.RNR_MED_RAT=64, .RNR_PRF_RAT=0, .RNR_RAD=5, .RNR_CTHR=15, .RNR_CTHL=12, .rsv_29=0}},
    .con3      ={.bits={.RNR_FL_MODE=0, .RNR_GD_RAT=63, .RNR_LLP_RAT=0, .RNR_INT_OFST=16, .rsv_23=0}},
    .sl        ={.bits={.RNR_SL_EN=1, .RNR_SL_Y2=350, .RNR_SL_Y1=175, .rsv_21=0}},
    .ssl_sth   ={.bits={.RNR_SSL_C2=20, .RNR_STH_C2=27, .RNR_SSL_C1=46, .RNR_STH_C1=53}}

};
