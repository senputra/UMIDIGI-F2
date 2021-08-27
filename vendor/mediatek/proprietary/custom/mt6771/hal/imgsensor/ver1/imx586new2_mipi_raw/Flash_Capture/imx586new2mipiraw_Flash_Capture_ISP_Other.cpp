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
#include "imx586new2mipiraw_Flash_Capture.h"

const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0020 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0021 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0022 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0023 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0024 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0025 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0026 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0027 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0028 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0029 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0030 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0031 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0032 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0033 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0034 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0035 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0036 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0037 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0038 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_CCR_T imx586new2mipiraw_NBC2_CCR_0039 = {
    .con     ={.bits={.NBC2_CCR_EN=0, .NBC2_CCR_SL2_LINK=1, .NBC2_CCR_SL2_MODE=0, .rsv_4=0, .NBC2_CCR_OR_MODE=0, .rsv_6=0, .NBC2_CCR_UV_GAIN_MODE=1, .rsv_9=0, .NBC2_CCR_UV_GAIN2=0, .rsv_23=0, .NBC2_CCR_Y_CPX3=255}},
    .ylut    ={.bits={.NBC2_CCR_Y_CPX1=32, .NBC2_CCR_Y_CPX2=96, .NBC2_CCR_Y_SP1=24, .rsv_23=0, .NBC2_CCR_Y_CPY1=16, .rsv_31=0}},
    .uvlut   ={.bits={.NBC2_CCR_UV_X1=5, .NBC2_CCR_UV_X2=37, .NBC2_CCR_UV_X3=255, .NBC2_CCR_UV_GAIN1=64, .rsv_31=0}},
    .ylut2   ={.bits={.NBC2_CCR_Y_SP0=16, .rsv_7=0, .NBC2_CCR_Y_SP2=0, .rsv_15=0, .NBC2_CCR_Y_CPY0=0, .rsv_23=0, .NBC2_CCR_Y_CPY2=64, .rsv_31=0}},
    .sat_ctrl={.bits={.NBC2_CCR_MODE=1, .rsv_1=0, .NBC2_CCR_CEN_U=0, .rsv_10=0, .NBC2_CCR_CEN_V=0, .rsv_18=0}},
    .uvlut_sp={.bits={.NBC2_CCR_UV_GAIN_SP1=64, .rsv_10=0, .NBC2_CCR_UV_GAIN_SP2=0, .rsv_26=0}},
    .hue1    ={.bits={.NBC2_CCR_HUE_X1=0, .rsv_9=0, .NBC2_CCR_HUE_X2=16, .rsv_25=0}},
    .hue2    ={.bits={.NBC2_CCR_HUE_X3=270, .rsv_9=0, .NBC2_CCR_HUE_X4=286, .rsv_25=0}},
    .hue3    ={.bits={.NBC2_CCR_HUE_SP1=128, .NBC2_CCR_HUE_SP2=127, .NBC2_CCR_HUE_GAIN1=64, .rsv_23=0, .NBC2_CCR_HUE_GAIN2=0, .rsv_31=0}},
    .l4lut1  ={.bits={.NBC2_CCR_SL2_X1=64, .NBC2_CCR_SL2_X2=128, .NBC2_CCR_SL2_X3=192, .rsv_24=0}},
    .l4lut2  ={.bits={.NBC2_CCR_SL2_GAIN0=16, .rsv_6=0, .NBC2_CCR_SL2_GAIN1=20, .rsv_14=0, .NBC2_CCR_SL2_GAIN2=24, .rsv_22=0, .NBC2_CCR_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3  ={.bits={.NBC2_CCR_SL2_SP0=8, .rsv_6=0, .NBC2_CCR_SL2_SP1=8, .rsv_14=0, .NBC2_CCR_SL2_SP2=16, .rsv_22=0, .NBC2_CCR_SL2_SP3=16, .rsv_30=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0020 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0021 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0022 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0023 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0024 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0025 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0026 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0027 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0028 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0029 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0030 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0031 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0032 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0033 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0034 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0035 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0036 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0037 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0038 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const ISP_NVRAM_ABF_T imx586new2mipiraw_NBC2_ABF_0039 = {
    .con1    ={.bits={.NBC2_ABF_EN=0, .rsv_1=0, .NBC2_ABF_BIL_IDX=2, .NBC2_ABF_NSR_IDX=1, .rsv_12=0}},
    .con2    ={.bits={.NBC2_ABF_BF_U_OFST=20, .rsv_6=0}},
    .rcon    ={.bits={.NBC2_ABF_R1=190, .rsv_9=0, .NBC2_ABF_R2=322, .rsv_25=0}},
    .ylut    ={.bits={.NBC2_ABF_Y0=0, .NBC2_ABF_Y1=1, .NBC2_ABF_Y2=150, .NBC2_ABF_Y3=186}},
    .cxlut   ={.bits={.NBC2_ABF_CX0=126, .NBC2_ABF_CX1=138, .NBC2_ABF_CX2=196, .NBC2_ABF_CX3=210}},
    .cylut   ={.bits={.NBC2_ABF_CY0=132, .NBC2_ABF_CY1=140, .NBC2_ABF_CY2=184, .NBC2_ABF_CY3=205}},
    .ysp     ={.bits={.NBC2_ABF_Y_SP0=511, .rsv_10=0, .NBC2_ABF_Y_SP1=1010, .rsv_26=0}},
    .cxsp    ={.bits={.NBC2_ABF_CX_SP0=56, .rsv_10=0, .NBC2_ABF_CX_SP1=988, .rsv_26=0}},
    .cysp    ={.bits={.NBC2_ABF_CY_SP0=64, .rsv_10=0, .NBC2_ABF_CY_SP1=1000, .rsv_26=0}},
    .clp     ={.bits={.NBC2_ABF_STHRE_R=250, .NBC2_ABF_STHRE_G=250, .NBC2_ABF_STHRE_B=250, .rsv_24=0}},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0060 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0061 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0062 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0063 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0064 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0065 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0066 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0067 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0068 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0069 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0070 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0071 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0072 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0073 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0074 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0075 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0076 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0077 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0078 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_STRUCT imx586new2mipiraw_SWNR_0079 = {
    .NR={.NR_K=300, .NR_S=30, .NR_SD=1, .NR_BLD_W=32, .NR_BLD_TH=5, .NR_SMTH=0, .NR_NTRL_TH_1_Y=255, .NR_NTRL_TH_2_Y=255, .NR_NTRL_TH_1_UV=255, .NR_NTRL_TH_2_UV=255},
    .HFG={.HFG_ENABLE=0, .HFG_GSD=1, .HFG_SD0=55552, .HFG_SD1=56905, .HFG_SD2=46189, .HFG_TX_S=128, .HFG_LCE_LINK_EN=0, .HFG_LUMA_CPX1=64, .HFG_LUMA_CPX2=128, .HFG_LUMA_CPX3=192, .HFG_LUMA_CPY0=32, .HFG_LUMA_CPY1=28, .HFG_LUMA_CPY2=24, .HFG_LUMA_CPY3=20, .HFG_LUMA_SP0=-4, .HFG_LUMA_SP1=-4, .HFG_LUMA_SP2=-4, .HFG_LUMA_SP3=-4},
    .CCR={.CCR_ENABLE=0, .CCR_CEN_U=0, .CCR_CEN_V=0, .CCR_Y_CPX1=32, .CCR_Y_CPX2=96, .CCR_Y_CPY1=16, .CCR_Y_SP1=24, .CCR_UV_X1=5, .CCR_UV_X2=37, .CCR_UV_X3=255, .CCR_UV_GAIN1=64, .CCR_UV_GAIN2=0, .CCR_UV_GAIN_SP1=64, .CCR_UV_GAIN_SP2=0, .CCR_Y_CPX3=224, .CCR_Y_CPY0=0, .CCR_Y_CPY2=64, .CCR_Y_SP0=16, .CCR_Y_SP2=25, .CCR_UV_GAIN_MODE=0, .CCR_MODE=0, .CCR_OR_MODE=0, .CCR_HUE_X1=0, .CCR_HUE_X2=16, .CCR_HUE_X3=270, .CCR_HUE_X4=286, .CCR_HUE_SP1=-128, .CCR_HUE_SP2=127, .CCR_HUE_GAIN1=64, .CCR_HUE_GAIN2=0},
};
const NVRAM_CAMERA_FEATURE_SWNR_THRES_STRUCT imx586new2mipiraw_SWNR_THRES_0003 = {
    1600, 60000, 2
};
