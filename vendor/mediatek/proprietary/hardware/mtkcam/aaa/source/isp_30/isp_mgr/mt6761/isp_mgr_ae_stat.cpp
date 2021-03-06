/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
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
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#define LOG_TAG "isp_mgr_ae_stat"

#ifndef ENABLE_MY_LOG
    #define ENABLE_MY_LOG       (0)
#endif

#include <cutils/properties.h>
#include <aaa_types.h>
#include <aaa_error_code.h>
#include <aaa_log.h>
//#include <mtkcam/drv/iopipe/CamIO/INormalPipe.h>
//#include <mtkcam/imageio/ispio_stddef.h>
#include <drv/isp_reg.h>
#include "isp_mgr.h"
#include <iopipe/CamIO/INormalPipe.h>
#include <private/aaa_utils.h>
#include <array>

using namespace NSIspTuningv3;

#define MY_INST NS3Av3::INST_T<ISP_MGR_AE_STAT_CONFIG_T>
static std::array<std::array<MY_INST, SENSOR_IDX_MAX>, EISP_MGR_REG_SET_NUM> gMultiton;

using namespace NSCam::NSIoPipeIsp3::NSCamIOPipe;

namespace NSIspTuningv3
{

#define IOPIPE_SET_MODUL_ENABLE(i4SensorIndex, module, enable) \
        { \
            if (MTRUE != sendAENormalPipe(i4SensorIndex, NSImageioIsp3::NSIspio::EPIPECmd_SET_MODULE_EN, module, enable, MNULL)) \
            { \
                MY_ERR("EPIPECmd_SET_MODULE_EN ConfigHWReg fail"); \
            } \
        }
#define IOPIPE_GET_MODUL_HANDLE(i4SensorIndex, module, handle) \
        { \
            if (MTRUE != sendAENormalPipe(i4SensorIndex, NSImageioIsp3::NSIspio::EPIPECmd_GET_MODULE_HANDLE, module, (MINTPTR)&handle, (MINTPTR)(&("isp_mgr_ae_stat")))) \
            { \
                MY_ERR("EPIPECmd_GET_MODULE_HANDLE ConfigHWReg fail"); \
            } \
        }
#define IOPIPE_SET_MODUL_CFG_DONE(i4SensorIndex, handle) \
        { \
            if (MTRUE != sendAENormalPipe(i4SensorIndex, NSImageioIsp3::NSIspio::EPIPECmd_SET_MODULE_CFG_DONE, handle, MNULL, MNULL)) \
            { \
                MY_ERR("EPIPECmd_SET_MODULE_CFG_DONE ConfigHWReg fail"); \
            } \
        }
#define IOPIPE_RELEASE_MODUL_HANDLE(i4SensorIndex, handle) \
        { \
            if (MTRUE != sendAENormalPipe(i4SensorIndex, NSImageioIsp3::NSIspio::EPIPECmd_RELEASE_MODULE_HANDLE, handle, (MINTPTR)(&("isp_mgr_ae_stat")), MNULL)) \
            { \
                MY_ERR("EPIPECmd_RELEASE_MODULE_HANDLE ConfigHWReg fail"); \
            } \
            handle = (MUINTPTR)NULL; \
        }

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// AE Statistics Config
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ISP_MGR_AE_STAT_CONFIG_T&
ISP_MGR_AE_STAT_CONFIG_T::
getInstance(ESensorDev_T const eSensorDev, ESensorTG_T const eSensorTG)
{
    auto i4SensorIdx = NS3Av3::mapSensorDevToIdx(eSensorDev);
    auto i4TGIdx = (eSensorTG == ESensorTG_1)? EISP_MGR_TG_1_IDX : EISP_MGR_TG_2_IDX;

    if(i4SensorIdx >= SENSOR_IDX_MAX || i4SensorIdx < 0) {
        MY_LOG("[%s] Unsupport sensor Index: %d\n", __FUNCTION__, i4SensorIdx);
    }

    MY_INST& rSingleton = gMultiton[i4TGIdx][i4SensorIdx];
    std::call_once(rSingleton.onceFlag, [&] {
        rSingleton.instance = std::make_unique<ISP_MGR_AE_STAT_CONFIG_T>(eSensorDev, eSensorTG);
    } );

    return *(rSingleton.instance);
}

MBOOL
ISP_MGR_AE_STAT_CONFIG_T::
config(MINT32 i4SensorIndex, AE_STAT_PARAM_T& rAEStatConfig)
{
    char value[PROPERTY_VALUE_MAX] = {'\0'};
    property_get("vendor.debug.isp_mgr_ae.enable", value, "1"); // temp for debug
    m_bDebugEnable = atoi(value);

    addressErrorCheck("Before ISP_MGR_AE_STAT_CONFIG_T::apply()");

    if (m_eSensorTG == ESensorTG_1) {
        // CAM_AE_HST_CTL
#if 1   // disable first for verify AAO statistic output
        reinterpret_cast<ISP_CAM_AE_HST_CTL_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_CTL))->AE_HST0_EN = rAEStatConfig.rAEHistWinCFG[0].bAEHistEn;
        reinterpret_cast<ISP_CAM_AE_HST_CTL_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_CTL))->AE_HST1_EN = rAEStatConfig.rAEHistWinCFG[1].bAEHistEn;
        reinterpret_cast<ISP_CAM_AE_HST_CTL_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_CTL))->AE_HST2_EN = rAEStatConfig.rAEHistWinCFG[2].bAEHistEn;
        reinterpret_cast<ISP_CAM_AE_HST_CTL_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_CTL))->AE_HST3_EN = rAEStatConfig.rAEHistWinCFG[3].bAEHistEn;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_HST_CTL : %d/%d/%d/%d", __FUNCTION__,
                    rAEStatConfig.rAEHistWinCFG[0].bAEHistEn,
                    rAEStatConfig.rAEHistWinCFG[1].bAEHistEn,
                    rAEStatConfig.rAEHistWinCFG[2].bAEHistEn,
                    rAEStatConfig.rAEHistWinCFG[3].bAEHistEn);
#else
        reinterpret_cast<ISP_CAM_AE_HST_CTL_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_CTL))->AE_HST0_EN = 0;
        reinterpret_cast<ISP_CAM_AE_HST_CTL_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_CTL))->AE_HST1_EN = 0;
        reinterpret_cast<ISP_CAM_AE_HST_CTL_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_CTL))->AE_HST2_EN = 0;
        reinterpret_cast<ISP_CAM_AE_HST_CTL_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_CTL))->AE_HST3_EN = 0;
#endif
        // CAM_AE_GAIN2_0
        reinterpret_cast<ISP_CAM_AE_RAWPREGAIN2_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_GAIN2_0))->RAWPREGAIN2_R = m_rIspAEPreGain2.i4R;
        reinterpret_cast<ISP_CAM_AE_RAWPREGAIN2_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_GAIN2_0))->RAWPREGAIN2_G = m_rIspAEPreGain2.i4G;
        // CAM_REG_AE_GAIN2_1
        reinterpret_cast<ISP_CAM_AE_RAWPREGAIN2_1_T*>(REG_INFO_VALUE_PTR(CAM_AE_GAIN2_1))->RAWPREGAIN2_B = m_rIspAEPreGain2.i4B;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_GAIN2 : %d/%d/%d", __FUNCTION__,
                    m_rIspAEPreGain2.i4R,
                    m_rIspAEPreGain2.i4G,
                    m_rIspAEPreGain2.i4B);
        // CAM_AE_LMT2_0
        reinterpret_cast<ISP_CAM_AE_RAWLIMIT2_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_LMT2_0))->AE_LIMIT2_R = 0xFFF;
        reinterpret_cast<ISP_CAM_AE_RAWLIMIT2_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_LMT2_0))->AE_LIMIT2_G = 0xFFF;
        // CAM_AE_LMT2_1
        reinterpret_cast<ISP_CAM_AE_RAWLIMIT2_1_T*>(REG_INFO_VALUE_PTR(CAM_AE_LMT2_1))->AE_LIMIT2_B = 0xFFF;
        // CAM_AE_RC_CNV_0
        reinterpret_cast<ISP_CAM_AE_MATRIX_COEF0_T*>(REG_INFO_VALUE_PTR(CAM_AE_RC_CNV_0))->RC_CNV00 = 0x200;
        reinterpret_cast<ISP_CAM_AE_MATRIX_COEF0_T*>(REG_INFO_VALUE_PTR(CAM_AE_RC_CNV_0))->RC_CNV01 = 0x000;
        // CAM_AE_RC_CNV_1
        reinterpret_cast<ISP_CAM_AE_MATRIX_COEF1_T*>(REG_INFO_VALUE_PTR(CAM_AE_RC_CNV_1))->RC_CNV02 = 0x000;
        reinterpret_cast<ISP_CAM_AE_MATRIX_COEF1_T*>(REG_INFO_VALUE_PTR(CAM_AE_RC_CNV_1))->RC_CNV10 = 0x000;
        // CAM_AE_RC_CNV_2
        reinterpret_cast<ISP_CAM_AE_MATRIX_COEF2_T*>(REG_INFO_VALUE_PTR(CAM_AE_RC_CNV_2))->RC_CNV11 = 0x200;
        reinterpret_cast<ISP_CAM_AE_MATRIX_COEF2_T*>(REG_INFO_VALUE_PTR(CAM_AE_RC_CNV_2))->RC_CNV12 = 0x000;
        // CAM_AE_RC_CNV_3
        reinterpret_cast<ISP_CAM_AE_MATRIX_COEF3_T*>(REG_INFO_VALUE_PTR(CAM_AE_RC_CNV_3))->RC_CNV20 = 0x000;
        reinterpret_cast<ISP_CAM_AE_MATRIX_COEF3_T*>(REG_INFO_VALUE_PTR(CAM_AE_RC_CNV_3))->RC_CNV21 = 0x000;
        // CAM_AE_RC_CNV_4
        reinterpret_cast<ISP_CAM_AE_MATRIX_COEF4_T*>(REG_INFO_VALUE_PTR(CAM_AE_RC_CNV_4))->RC_CNV22 = 0x200;
        reinterpret_cast<ISP_CAM_AE_MATRIX_COEF4_T*>(REG_INFO_VALUE_PTR(CAM_AE_RC_CNV_4))->AE_RC_ACC = 0x09;
        // CAM_AE_YGAMMA_0
        reinterpret_cast<ISP_CAM_AE_YGAMMA_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_YGAMMA_0))->Y_GMR1 = 0x10;
        reinterpret_cast<ISP_CAM_AE_YGAMMA_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_YGAMMA_0))->Y_GMR2 = 0x20;
        reinterpret_cast<ISP_CAM_AE_YGAMMA_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_YGAMMA_0))->Y_GMR3 = 0x40;
        reinterpret_cast<ISP_CAM_AE_YGAMMA_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_YGAMMA_0))->Y_GMR4 = 0x60;
        // CAM_AE_YGAMMA_1
        reinterpret_cast<ISP_CAM_AE_YGAMMA_1_T*>(REG_INFO_VALUE_PTR(CAM_AE_YGAMMA_1))->Y_GMR5 = 0x80;
        // CAM_AE_HST_SET
        reinterpret_cast<ISP_CAM_AE_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_SET))->AE_HST0_BIN = rAEStatConfig.rAEHistWinCFG[0].uAEHistBin;
        reinterpret_cast<ISP_CAM_AE_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_SET))->AE_HST1_BIN = rAEStatConfig.rAEHistWinCFG[1].uAEHistBin;
        reinterpret_cast<ISP_CAM_AE_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_SET))->AE_HST2_BIN = rAEStatConfig.rAEHistWinCFG[2].uAEHistBin;
        reinterpret_cast<ISP_CAM_AE_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_SET))->AE_HST3_BIN = rAEStatConfig.rAEHistWinCFG[3].uAEHistBin;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_HST_SET_BIN : %d/%d/%d/%d", __FUNCTION__,
                    rAEStatConfig.rAEHistWinCFG[0].uAEHistBin,
                    rAEStatConfig.rAEHistWinCFG[1].uAEHistBin,
                    rAEStatConfig.rAEHistWinCFG[2].uAEHistBin,
                    rAEStatConfig.rAEHistWinCFG[3].uAEHistBin);
        reinterpret_cast<ISP_CAM_AE_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_SET))->AE_HST0_COLOR = rAEStatConfig.rAEHistWinCFG[0].uAEHistOpt;
        reinterpret_cast<ISP_CAM_AE_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_SET))->AE_HST1_COLOR = rAEStatConfig.rAEHistWinCFG[1].uAEHistOpt;
        reinterpret_cast<ISP_CAM_AE_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_SET))->AE_HST2_COLOR = rAEStatConfig.rAEHistWinCFG[2].uAEHistOpt;
        reinterpret_cast<ISP_CAM_AE_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST_SET))->AE_HST3_COLOR = rAEStatConfig.rAEHistWinCFG[3].uAEHistOpt;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_HST_SET_COLOR : %d/%d/%d/%d", __FUNCTION__,
                    rAEStatConfig.rAEHistWinCFG[0].uAEHistOpt,
                    rAEStatConfig.rAEHistWinCFG[1].uAEHistOpt,
                    rAEStatConfig.rAEHistWinCFG[2].uAEHistOpt,
                    rAEStatConfig.rAEHistWinCFG[3].uAEHistOpt);
        // CAM_AE_HST0_RNG
        reinterpret_cast<ISP_CAM_AE_HST0_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST0_RNG))->AE_HST0_X_LOW = rAEStatConfig.rAEHistWinCFG[0].uAEHistXLow;
        reinterpret_cast<ISP_CAM_AE_HST0_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST0_RNG))->AE_HST0_X_HI = rAEStatConfig.rAEHistWinCFG[0].uAEHistXHi;
        reinterpret_cast<ISP_CAM_AE_HST0_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST0_RNG))->AE_HST0_Y_LOW = rAEStatConfig.rAEHistWinCFG[0].uAEHistYLow;
        reinterpret_cast<ISP_CAM_AE_HST0_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST0_RNG))->AE_HST0_Y_HI = rAEStatConfig.rAEHistWinCFG[0].uAEHistYHi;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_HST0_RNG : %d/%d/%d/%d", __FUNCTION__,
                    rAEStatConfig.rAEHistWinCFG[0].uAEHistXLow,
                    rAEStatConfig.rAEHistWinCFG[0].uAEHistXHi,
                    rAEStatConfig.rAEHistWinCFG[0].uAEHistYLow,
                    rAEStatConfig.rAEHistWinCFG[0].uAEHistYHi);
        // CAM_AE_HST1_RNG
        reinterpret_cast<ISP_CAM_AE_HST1_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST1_RNG))->AE_HST1_X_LOW = rAEStatConfig.rAEHistWinCFG[1].uAEHistXLow;
        reinterpret_cast<ISP_CAM_AE_HST1_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST1_RNG))->AE_HST1_X_HI = rAEStatConfig.rAEHistWinCFG[1].uAEHistXHi;
        reinterpret_cast<ISP_CAM_AE_HST1_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST1_RNG))->AE_HST1_Y_LOW = rAEStatConfig.rAEHistWinCFG[1].uAEHistYLow;
        reinterpret_cast<ISP_CAM_AE_HST1_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST1_RNG))->AE_HST1_Y_HI = rAEStatConfig.rAEHistWinCFG[1].uAEHistYHi;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_HST1_RNG : %d/%d/%d/%d", __FUNCTION__,
                    rAEStatConfig.rAEHistWinCFG[1].uAEHistXLow,
                    rAEStatConfig.rAEHistWinCFG[1].uAEHistXHi,
                    rAEStatConfig.rAEHistWinCFG[1].uAEHistYLow,
                    rAEStatConfig.rAEHistWinCFG[1].uAEHistYHi);
        // CAM_AE_HST2_RNG
        reinterpret_cast<ISP_CAM_AE_HST2_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST2_RNG))->AE_HST2_X_LOW = rAEStatConfig.rAEHistWinCFG[2].uAEHistXLow;
        reinterpret_cast<ISP_CAM_AE_HST2_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST2_RNG))->AE_HST2_X_HI = rAEStatConfig.rAEHistWinCFG[2].uAEHistXHi;
        reinterpret_cast<ISP_CAM_AE_HST2_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST2_RNG))->AE_HST2_Y_LOW = rAEStatConfig.rAEHistWinCFG[2].uAEHistYLow;
        reinterpret_cast<ISP_CAM_AE_HST2_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST2_RNG))->AE_HST2_Y_HI = rAEStatConfig.rAEHistWinCFG[2].uAEHistYHi;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_HST2_RNG : %d/%d/%d/%d", __FUNCTION__,
                    rAEStatConfig.rAEHistWinCFG[2].uAEHistXLow,
                    rAEStatConfig.rAEHistWinCFG[2].uAEHistXHi,
                    rAEStatConfig.rAEHistWinCFG[2].uAEHistYLow,
                    rAEStatConfig.rAEHistWinCFG[2].uAEHistYHi);
        // CAM_AE_HST3_RNG
        reinterpret_cast<ISP_CAM_AE_HST3_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST3_RNG))->AE_HST3_X_LOW = rAEStatConfig.rAEHistWinCFG[3].uAEHistXLow;
        reinterpret_cast<ISP_CAM_AE_HST3_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST3_RNG))->AE_HST3_X_HI = rAEStatConfig.rAEHistWinCFG[3].uAEHistXHi;
        reinterpret_cast<ISP_CAM_AE_HST3_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST3_RNG))->AE_HST3_Y_LOW = rAEStatConfig.rAEHistWinCFG[3].uAEHistYLow;
        reinterpret_cast<ISP_CAM_AE_HST3_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_HST3_RNG))->AE_HST3_Y_HI = rAEStatConfig.rAEHistWinCFG[3].uAEHistYHi;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_HST3_RNG : %d/%d/%d/%d", __FUNCTION__,
                    rAEStatConfig.rAEHistWinCFG[3].uAEHistXLow,
                    rAEStatConfig.rAEHistWinCFG[3].uAEHistXHi,
                    rAEStatConfig.rAEHistWinCFG[3].uAEHistYLow,
                    rAEStatConfig.rAEHistWinCFG[3].uAEHistYHi);
        // CAM_AE_STAT_EN
        CAM_REG_AE_STAT_EN AeStatEn;
        AeStatEn.Raw = 0;
        AeStatEn.Bits.AE_TSF_STAT_EN = m_bEnableTSFConfig;
        REG_INFO_VALUE(CAM_AE_STAT_EN) = (MUINT32)AeStatEn.Raw;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_STAT_EN : %d", __FUNCTION__,
                    m_rIspRegInfo[ERegInfo_CAM_AE_STAT_EN].val);

        m_bTG1Init = MTRUE;
        apply_TG1(i4SensorIndex);
    }
    else {
        // CAM_AE_D_HST_CTL
        reinterpret_cast<ISP_CAM_AE_D_HST_CTL_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST_CTL))->AE_HST0_EN = rAEStatConfig.rAEHistWinCFG[0].bAEHistEn;
        reinterpret_cast<ISP_CAM_AE_D_HST_CTL_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST_CTL))->AE_HST1_EN = rAEStatConfig.rAEHistWinCFG[1].bAEHistEn;
        reinterpret_cast<ISP_CAM_AE_D_HST_CTL_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST_CTL))->AE_HST2_EN = rAEStatConfig.rAEHistWinCFG[2].bAEHistEn;
        reinterpret_cast<ISP_CAM_AE_D_HST_CTL_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST_CTL))->AE_HST3_EN = rAEStatConfig.rAEHistWinCFG[3].bAEHistEn;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_D_HST_CTL : %d/%d/%d/%d", __FUNCTION__,
                    rAEStatConfig.rAEHistWinCFG[0].bAEHistEn,
                    rAEStatConfig.rAEHistWinCFG[1].bAEHistEn,
                    rAEStatConfig.rAEHistWinCFG[2].bAEHistEn,
                    rAEStatConfig.rAEHistWinCFG[3].bAEHistEn);
        // CAM_AE_D_GAIN2_0
        reinterpret_cast<ISP_CAM_AE_D_RAWPREGAIN2_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_GAIN2_0))->RAWPREGAIN2_R = m_rIspAEPreGain2.i4R;
        reinterpret_cast<ISP_CAM_AE_D_RAWPREGAIN2_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_GAIN2_0))->RAWPREGAIN2_G = m_rIspAEPreGain2.i4G;
        // CAM_REG_AE_D_GAIN2_1
        reinterpret_cast<ISP_CAM_AE_D_RAWPREGAIN2_1_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_GAIN2_1))->RAWPREGAIN2_B = m_rIspAEPreGain2.i4B;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_D_GAIN2 : %d/%d/%d", __FUNCTION__,
                    m_rIspAEPreGain2.i4R,
                    m_rIspAEPreGain2.i4G,
                    m_rIspAEPreGain2.i4B);
        // CAM_AE_D_LMT2_0
        reinterpret_cast<ISP_CAM_AE_D_RAWLIMIT2_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_LMT2_0))->AE_LIMIT2_R = 0xFFF;
        reinterpret_cast<ISP_CAM_AE_D_RAWLIMIT2_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_LMT2_0))->AE_LIMIT2_G = 0xFFF;
        // CAM_AE_D_LMT2_1
        reinterpret_cast<ISP_CAM_AE_D_RAWLIMIT2_1_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_LMT2_1))->AE_LIMIT2_B = 0xFFF;
        // CAM_AE_D_RC_CNV_0
        reinterpret_cast<ISP_CAM_AE_D_MATRIX_COEF0_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_RC_CNV_0))->RC_CNV00 = 0x200;
        reinterpret_cast<ISP_CAM_AE_D_MATRIX_COEF0_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_RC_CNV_0))->RC_CNV01 = 0x000;
        // CAM_AE_D_RC_CNV_1
        reinterpret_cast<ISP_CAM_AE_D_MATRIX_COEF1_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_RC_CNV_1))->RC_CNV02 = 0x000;
        reinterpret_cast<ISP_CAM_AE_D_MATRIX_COEF1_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_RC_CNV_1))->RC_CNV10 = 0x000;
        // CAM_AE_D_RC_CNV_2
        reinterpret_cast<ISP_CAM_AE_D_MATRIX_COEF2_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_RC_CNV_2))->RC_CNV11 = 0x200;
        reinterpret_cast<ISP_CAM_AE_D_MATRIX_COEF2_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_RC_CNV_2))->RC_CNV12 = 0x000;
        // CAM_AE_D_RC_CNV_3
        reinterpret_cast<ISP_CAM_AE_D_MATRIX_COEF3_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_RC_CNV_3))->RC_CNV20 = 0x000;
        reinterpret_cast<ISP_CAM_AE_D_MATRIX_COEF3_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_RC_CNV_3))->RC_CNV21 = 0x000;
        // CAM_AE_D_RC_CNV_4
        reinterpret_cast<ISP_CAM_AE_D_MATRIX_COEF4_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_RC_CNV_4))->RC_CNV22 = 0x200;
        reinterpret_cast<ISP_CAM_AE_D_MATRIX_COEF4_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_RC_CNV_4))->AE_RC_ACC = 0x09;
        // CAM_AE_D_YGAMMA_0
        reinterpret_cast<ISP_CAM_AE_D_YGAMMA_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_YGAMMA_0))->Y_GMR1 = 0x10;
        reinterpret_cast<ISP_CAM_AE_D_YGAMMA_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_YGAMMA_0))->Y_GMR2 = 0x20;
        reinterpret_cast<ISP_CAM_AE_D_YGAMMA_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_YGAMMA_0))->Y_GMR3 = 0x40;
        reinterpret_cast<ISP_CAM_AE_D_YGAMMA_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_YGAMMA_0))->Y_GMR4 = 0x60;
        // CAM_AE_D_YGAMMA_1
        reinterpret_cast<ISP_CAM_AE_D_YGAMMA_1_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_YGAMMA_1))->Y_GMR5 = 0x80;
        // CAM_AE_D_HST_SET
        reinterpret_cast<ISP_CAM_AE_D_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST_SET))->AE_HST0_BIN = rAEStatConfig.rAEHistWinCFG[0].uAEHistBin;
        reinterpret_cast<ISP_CAM_AE_D_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST_SET))->AE_HST1_BIN = rAEStatConfig.rAEHistWinCFG[1].uAEHistBin;
        reinterpret_cast<ISP_CAM_AE_D_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST_SET))->AE_HST2_BIN = rAEStatConfig.rAEHistWinCFG[2].uAEHistBin;
        reinterpret_cast<ISP_CAM_AE_D_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST_SET))->AE_HST3_BIN = rAEStatConfig.rAEHistWinCFG[3].uAEHistBin;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_D_HST_SET_BIN : %d/%d/%d/%d", __FUNCTION__,
                    rAEStatConfig.rAEHistWinCFG[0].uAEHistBin,
                    rAEStatConfig.rAEHistWinCFG[1].uAEHistBin,
                    rAEStatConfig.rAEHistWinCFG[2].uAEHistBin,
                    rAEStatConfig.rAEHistWinCFG[3].uAEHistBin);
        reinterpret_cast<ISP_CAM_AE_D_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST_SET))->AE_HST0_COLOR = rAEStatConfig.rAEHistWinCFG[0].uAEHistOpt;
        reinterpret_cast<ISP_CAM_AE_D_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST_SET))->AE_HST1_COLOR = rAEStatConfig.rAEHistWinCFG[1].uAEHistOpt;
        reinterpret_cast<ISP_CAM_AE_D_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST_SET))->AE_HST2_COLOR = rAEStatConfig.rAEHistWinCFG[2].uAEHistOpt;
        reinterpret_cast<ISP_CAM_AE_D_HST_SET_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST_SET))->AE_HST3_COLOR = rAEStatConfig.rAEHistWinCFG[3].uAEHistOpt;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_D_HST_SET_COLOR : %d/%d/%d/%d", __FUNCTION__,
                    rAEStatConfig.rAEHistWinCFG[0].uAEHistOpt,
                    rAEStatConfig.rAEHistWinCFG[1].uAEHistOpt,
                    rAEStatConfig.rAEHistWinCFG[2].uAEHistOpt,
                    rAEStatConfig.rAEHistWinCFG[3].uAEHistOpt);
        // CAM_AE_D_HST0_RNG
        reinterpret_cast<ISP_CAM_AE_D_HST0_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST0_RNG))->AE_HST0_X_LOW = rAEStatConfig.rAEHistWinCFG[0].uAEHistXLow;
        reinterpret_cast<ISP_CAM_AE_D_HST0_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST0_RNG))->AE_HST0_X_HI = rAEStatConfig.rAEHistWinCFG[0].uAEHistXHi;
        reinterpret_cast<ISP_CAM_AE_D_HST0_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST0_RNG))->AE_HST0_Y_LOW = rAEStatConfig.rAEHistWinCFG[0].uAEHistYLow;
        reinterpret_cast<ISP_CAM_AE_D_HST0_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST0_RNG))->AE_HST0_Y_HI = rAEStatConfig.rAEHistWinCFG[0].uAEHistYHi;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_D_HST0_RNG : %d/%d/%d/%d", __FUNCTION__,
                    rAEStatConfig.rAEHistWinCFG[0].uAEHistXLow,
                    rAEStatConfig.rAEHistWinCFG[0].uAEHistXHi,
                    rAEStatConfig.rAEHistWinCFG[0].uAEHistYLow,
                    rAEStatConfig.rAEHistWinCFG[0].uAEHistYHi);
        // CAM_AE_D_HST1_RNG
        reinterpret_cast<ISP_CAM_AE_D_HST1_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST1_RNG))->AE_HST1_X_LOW = rAEStatConfig.rAEHistWinCFG[1].uAEHistXLow;
        reinterpret_cast<ISP_CAM_AE_D_HST1_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST1_RNG))->AE_HST1_X_HI = rAEStatConfig.rAEHistWinCFG[1].uAEHistXHi;
        reinterpret_cast<ISP_CAM_AE_D_HST1_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST1_RNG))->AE_HST1_Y_LOW = rAEStatConfig.rAEHistWinCFG[1].uAEHistYLow;
        reinterpret_cast<ISP_CAM_AE_D_HST1_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST1_RNG))->AE_HST1_Y_HI = rAEStatConfig.rAEHistWinCFG[1].uAEHistYHi;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_D_HST1_RNG : %d/%d/%d/%d", __FUNCTION__,
                    rAEStatConfig.rAEHistWinCFG[1].uAEHistXLow,
                    rAEStatConfig.rAEHistWinCFG[1].uAEHistXHi,
                    rAEStatConfig.rAEHistWinCFG[1].uAEHistYLow,
                    rAEStatConfig.rAEHistWinCFG[1].uAEHistYHi);
        // CAM_AE_D_HST2_RNG
        reinterpret_cast<ISP_CAM_AE_D_HST2_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST2_RNG))->AE_HST2_X_LOW = rAEStatConfig.rAEHistWinCFG[2].uAEHistXLow;
        reinterpret_cast<ISP_CAM_AE_D_HST2_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST2_RNG))->AE_HST2_X_HI = rAEStatConfig.rAEHistWinCFG[2].uAEHistXHi;
        reinterpret_cast<ISP_CAM_AE_D_HST2_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST2_RNG))->AE_HST2_Y_LOW = rAEStatConfig.rAEHistWinCFG[2].uAEHistYLow;
        reinterpret_cast<ISP_CAM_AE_D_HST2_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST2_RNG))->AE_HST2_Y_HI = rAEStatConfig.rAEHistWinCFG[2].uAEHistYHi;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_D_HST2_RNG : %d/%d/%d/%d", __FUNCTION__,
                    rAEStatConfig.rAEHistWinCFG[2].uAEHistXLow,
                    rAEStatConfig.rAEHistWinCFG[2].uAEHistXHi,
                    rAEStatConfig.rAEHistWinCFG[2].uAEHistYLow,
                    rAEStatConfig.rAEHistWinCFG[2].uAEHistYHi);
        // CAM_AE_D_HST3_RNG
        reinterpret_cast<ISP_CAM_AE_D_HST3_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST3_RNG))->AE_HST3_X_LOW = rAEStatConfig.rAEHistWinCFG[3].uAEHistXLow;
        reinterpret_cast<ISP_CAM_AE_D_HST3_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST3_RNG))->AE_HST3_X_HI = rAEStatConfig.rAEHistWinCFG[3].uAEHistXHi;
        reinterpret_cast<ISP_CAM_AE_D_HST3_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST3_RNG))->AE_HST3_Y_LOW = rAEStatConfig.rAEHistWinCFG[3].uAEHistYLow;
        reinterpret_cast<ISP_CAM_AE_D_HST3_RNG_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_HST3_RNG))->AE_HST3_Y_HI = rAEStatConfig.rAEHistWinCFG[3].uAEHistYHi;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_D_HST3_RNG : %d/%d/%d/%d", __FUNCTION__,
                    rAEStatConfig.rAEHistWinCFG[3].uAEHistXLow,
                    rAEStatConfig.rAEHistWinCFG[3].uAEHistXHi,
                    rAEStatConfig.rAEHistWinCFG[3].uAEHistYLow,
                    rAEStatConfig.rAEHistWinCFG[3].uAEHistYHi);
        // CAM_AE_D_STAT_EN
        CAM_REG_AE_D_STAT_EN AeDStatEn;
        AeDStatEn.Raw = 0;
        AeDStatEn.Bits.AE_TSF_STAT_EN = m_bEnableTSFConfig;
        REG_INFO_VALUE(CAM_AE_D_STAT_EN) = (MUINT32)AeDStatEn.Raw;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_D_STAT_EN : %d", __FUNCTION__,
                    m_rIspRegInfo[ERegInfo_CAM_AE_D_STAT_EN].val);

        m_bTG2Init = MTRUE;
        apply_TG2(i4SensorIndex);
    }

    addressErrorCheck("After ISP_MGR_AWB_STAT_CONFIG_T::apply()");

    return MTRUE;
}

MBOOL
ISP_MGR_AE_STAT_CONFIG_T::
apply_TG1(MINT32 i4SensorIndex)
{
    Mutex::Autolock lock(mLock_TG1);
    CAM_LOGD("%s(): m_eSensorDev = %d, i4SensorIndex = %d\n", __FUNCTION__, m_eSensorDev, i4SensorIndex);

    MUINTPTR handle;

    if(m_bTG1Init == MFALSE) {
        CAM_LOGD("%s(): AE don't configure TG1\n", __FUNCTION__);
        return MTRUE;
    }

    // set module register
    IOPIPE_GET_MODUL_HANDLE(i4SensorIndex, NSImageioIsp3::NSIspio::EModule_AE, handle);
    if ((MUINTPTR)NULL != handle) {
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_HST_CTL, m_rIspRegInfo[ERegInfo_CAM_AE_HST_CTL].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_GAIN2_0, m_rIspRegInfo[ERegInfo_CAM_AE_GAIN2_0].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_GAIN2_1, m_rIspRegInfo[ERegInfo_CAM_AE_GAIN2_1].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_LMT2_0, m_rIspRegInfo[ERegInfo_CAM_AE_LMT2_0].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_LMT2_1, m_rIspRegInfo[ERegInfo_CAM_AE_LMT2_1].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_RC_CNV_0, m_rIspRegInfo[ERegInfo_CAM_AE_RC_CNV_0].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_RC_CNV_1, m_rIspRegInfo[ERegInfo_CAM_AE_RC_CNV_1].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_RC_CNV_2, m_rIspRegInfo[ERegInfo_CAM_AE_RC_CNV_2].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_RC_CNV_3, m_rIspRegInfo[ERegInfo_CAM_AE_RC_CNV_3].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_RC_CNV_4, m_rIspRegInfo[ERegInfo_CAM_AE_RC_CNV_4].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_YGAMMA_0, m_rIspRegInfo[ERegInfo_CAM_AE_YGAMMA_0].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_YGAMMA_1, m_rIspRegInfo[ERegInfo_CAM_AE_YGAMMA_1].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_HST_SET, m_rIspRegInfo[ERegInfo_CAM_AE_HST_SET].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_HST0_RNG, m_rIspRegInfo[ERegInfo_CAM_AE_HST0_RNG].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_HST1_RNG, m_rIspRegInfo[ERegInfo_CAM_AE_HST1_RNG].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_HST2_RNG, m_rIspRegInfo[ERegInfo_CAM_AE_HST2_RNG].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_HST3_RNG, m_rIspRegInfo[ERegInfo_CAM_AE_HST3_RNG].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_STAT_EN, m_rIspRegInfo[ERegInfo_CAM_AE_STAT_EN].val);
        IOPIPE_SET_MODUL_CFG_DONE(i4SensorIndex, handle); // set module config done
        IOPIPE_RELEASE_MODUL_HANDLE(i4SensorIndex, handle); // release handle
    }

    return MTRUE;
}

MBOOL
ISP_MGR_AE_STAT_CONFIG_T::
apply_TG2(MINT32 i4SensorIndex)
{
    Mutex::Autolock lock(mLock_TG2);
    CAM_LOGD("%s(): m_eSensorDev = %d, i4SensorIndex = %d\n", __FUNCTION__, m_eSensorDev, i4SensorIndex);

    MUINTPTR handle;

    if(m_bTG2Init == MFALSE) {
        CAM_LOGD("%s(): AE don't configure TG2\n", __FUNCTION__);
        return MTRUE;
    }

    // set module register
    IOPIPE_GET_MODUL_HANDLE(i4SensorIndex, NSImageioIsp3::NSIspio::EModule_AE_D, handle);
    if ((MUINTPTR)NULL != handle) {
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_HST_CTL, m_rIspRegInfo[ERegInfo_CAM_AE_D_HST_CTL].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_GAIN2_0, m_rIspRegInfo[ERegInfo_CAM_AE_D_GAIN2_0].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_GAIN2_1, m_rIspRegInfo[ERegInfo_CAM_AE_D_GAIN2_1].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_LMT2_0, m_rIspRegInfo[ERegInfo_CAM_AE_D_LMT2_0].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_LMT2_1, m_rIspRegInfo[ERegInfo_CAM_AE_D_LMT2_1].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_RC_CNV_0, m_rIspRegInfo[ERegInfo_CAM_AE_D_RC_CNV_0].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_RC_CNV_1, m_rIspRegInfo[ERegInfo_CAM_AE_D_RC_CNV_1].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_RC_CNV_2, m_rIspRegInfo[ERegInfo_CAM_AE_D_RC_CNV_2].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_RC_CNV_3, m_rIspRegInfo[ERegInfo_CAM_AE_D_RC_CNV_3].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_RC_CNV_4, m_rIspRegInfo[ERegInfo_CAM_AE_D_RC_CNV_4].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_YGAMMA_0, m_rIspRegInfo[ERegInfo_CAM_AE_D_YGAMMA_0].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_YGAMMA_1, m_rIspRegInfo[ERegInfo_CAM_AE_D_YGAMMA_1].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_HST_SET, m_rIspRegInfo[ERegInfo_CAM_AE_D_HST_SET].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_HST0_RNG, m_rIspRegInfo[ERegInfo_CAM_AE_D_HST0_RNG].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_HST1_RNG, m_rIspRegInfo[ERegInfo_CAM_AE_D_HST1_RNG].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_HST2_RNG, m_rIspRegInfo[ERegInfo_CAM_AE_D_HST2_RNG].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_HST3_RNG, m_rIspRegInfo[ERegInfo_CAM_AE_D_HST3_RNG].val);
        IOPIPE_SET_MODUL_REG(handle, CAM_AE_D_STAT_EN, m_rIspRegInfo[ERegInfo_CAM_AE_D_STAT_EN].val);
        IOPIPE_SET_MODUL_CFG_DONE(i4SensorIndex, handle); // set module config done
        IOPIPE_RELEASE_MODUL_HANDLE(i4SensorIndex, handle); // release handle
    }

    return MTRUE;
}

MBOOL
ISP_MGR_AE_STAT_CONFIG_T::
apply()
{
    return MTRUE;
}

MBOOL
ISP_MGR_AE_STAT_CONFIG_T::
setAEconfigParam(MBOOL bTSF)
{
    CAM_LOGD("[AEconfig] bTSF = %d -> %d \n", m_bEnableTSFConfig, bTSF);
    m_bEnableTSFConfig = bTSF;
    return MTRUE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// AE RAW Pre-gain2
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL
ISP_MGR_AE_STAT_CONFIG_T::
setIspAEPreGain2(MINT32 i4SensorIndex, AWB_GAIN_T& rIspAWBGain)
{
    m_rIspAEPreGain2 = rIspAWBGain;

    if (m_eSensorTG == ESensorTG_1) {
        // CAM_AE_GAIN2_0
        reinterpret_cast<ISP_CAM_AE_RAWPREGAIN2_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_GAIN2_0))->RAWPREGAIN2_R = m_rIspAEPreGain2.i4R;
        reinterpret_cast<ISP_CAM_AE_RAWPREGAIN2_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_GAIN2_0))->RAWPREGAIN2_G = m_rIspAEPreGain2.i4G;
        // CAM_REG_AE_GAIN2_1
        reinterpret_cast<ISP_CAM_AE_RAWPREGAIN2_1_T*>(REG_INFO_VALUE_PTR(CAM_AE_GAIN2_1))->RAWPREGAIN2_B = m_rIspAEPreGain2.i4B;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_GAIN2 : %d/%d/%d", __FUNCTION__,
                    m_rIspAEPreGain2.i4R,
                    m_rIspAEPreGain2.i4G,
                    m_rIspAEPreGain2.i4B);

        apply_TG1(i4SensorIndex);
    } else {
        // CAM_AE_D_GAIN2_0
        reinterpret_cast<ISP_CAM_AE_D_RAWPREGAIN2_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_GAIN2_0))->RAWPREGAIN2_R = m_rIspAEPreGain2.i4R;
        reinterpret_cast<ISP_CAM_AE_D_RAWPREGAIN2_0_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_GAIN2_0))->RAWPREGAIN2_G = m_rIspAEPreGain2.i4G;
        // CAM_REG_AE_D_GAIN2_1
        reinterpret_cast<ISP_CAM_AE_D_RAWPREGAIN2_1_T*>(REG_INFO_VALUE_PTR(CAM_AE_D_GAIN2_1))->RAWPREGAIN2_B = m_rIspAEPreGain2.i4B;
        CAM_LOGD_IF(m_bDebugEnable, "[%s] CAM_AE_D_GAIN2 : %d/%d/%d", __FUNCTION__,
                    m_rIspAEPreGain2.i4R,
                    m_rIspAEPreGain2.i4G,
                    m_rIspAEPreGain2.i4B);

        apply_TG2(i4SensorIndex);
    }

    return MTRUE;
}

MBOOL
ISP_MGR_AE_STAT_CONFIG_T::
sendAENormalPipe( MINT32 i4SensorIndex, MINT32 cmd, MINTPTR arg1, MINTPTR arg2, MINTPTR arg3)
{
    MBOOL ret = MFALSE;

    INormalPipe_FrmB* pPipe = INormalPipe_FrmB::createInstance(i4SensorIndex, LOG_TAG);
    if(pPipe==NULL)
    {
        MY_ERR( "Fail to create NormalPipe");
    }
    else
    {
        ret = pPipe->sendCommand( cmd, arg1, arg2, arg3);
        pPipe->destroyInstance( LOG_TAG);
    }

    return ret;
}

}

