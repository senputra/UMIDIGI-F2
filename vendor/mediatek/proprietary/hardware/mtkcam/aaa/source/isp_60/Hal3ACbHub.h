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

#ifndef _HAL_3A_CBHUB_H_
#define _HAL_3A_CBHUB_H_

#include <I3AWrapper.h>
#include <mtkcam/utils/std/Log.h>
#include <mtkcam/def/common.h>
#include <mtkcam/utils/std/common.h>
#include <mutex>
#include <cutils/properties.h>
#include <mtkcam/aaa/IDngInfo.h>
#include <mtkcam/utils/std/Trace.h>
#include <mtkcam/drv/iopipe/CamIO/Cam_Notify.h>

#include <af_mgr/af_mgr_if.h>
#include <pd_mgr_if.h>
#include <ae_mgr/ae_mgr_if.h>
#include <awb_mgr/awb_mgr_if.h>
#if CAM3_FLICKER_FEATURE_EN
#include <flicker_hal_if.h>
#endif
#if CAM3_LSC_FEATURE_EN
#include <lsc/ILscMgr.h>
#endif
// ResultPool and config header
#include <IResultPool.h>
#include <isp_config/af_config.h>
#include <isp_config/isp_pdo_config.h>
#include <isp_config/ae_config.h>
#include <isp_config/awb_config.h>
#include <isp_config/isp_flicker_config.h>
#include <isp_config/isp_pdo_config.h>
#include <ResultPool4LSCConfig.h>

#define ENABLEISP 0

namespace NS3Av3
{

class Hal3ACbHub;

/******** Hal3AReconfigCb is a Dynamic Binning Callback Class
  *               This class is for Dynamic Binning Callback, not made for static declaration
  *               The instance would be included in Hal3ACbHub
  *               And the lifecyle is controlled by Hal3ACbHub
  ***************************************************************/
class Hal3AReconfigCb : public P1_TUNING_NOTIFY
{
public:

    Hal3AReconfigCb(MINT32 i4SensorDev);

    virtual ~Hal3AReconfigCb();

    virtual const char* TuningName(){ return "Hal3AReconfigCb"; };

    virtual void p1TuningNotify(MVOID* pIn, MVOID* pOut);

    // For the future use: MVOID API for Hal3ACbHub to set Param;
    // MVOID SetParam(struct );

private:
    MINT32          m_i4SensorDev;
    IResultPool*    m_pResultPoolObj;
};

#if ENABLEISP
/******** P1RegDumpCb is a P1 Dump Callback Class
  *               This class is for P1 dump, not made for static declaration
  *               The instance would be included in Hal3ACbHub
  *               And the lifecyle is controlled by Hal3ACbHub
  ***************************************************************/
class P1RegDumpCb : public P1_TUNING_NOTIFY
{
public:
    MUINT32 mSensorDev;
    P1RegDumpCb(MINT32 i4SensorDev);
    virtual ~P1RegDumpCb();
    virtual void p1TuningNotify(MVOID *pInput, MVOID *pOutput);
    virtual const char* TuningName() { return "Dump P1 HW Reg"; }
};
#endif

/******** Hal3ACbHub is a Hub for integrating all potential callbacks that are registered by other modules
  *               This class SHOULD COLLECT callbacks which would be initialized with itself ('this' pointer)
  *               All the sub-classes do the callback function via Hal3ACbHub
  *               And the lifecyle is controlled by Hal3ARawImp
  ******************************************************************************/
class Hal3ACbHub
{
friend class Hal3AReconfigCb;

public:

    Hal3ACbHub(MINT32 i4SensorDev);

    ~Hal3ACbHub();

    MVOID* getCallbackAddr(MINT32 Choice);

private:
    MINT32              m_i4SensorDev;
    Hal3AReconfigCb*    m_pReconfigCb;
#if ENABLEISP
    P1RegDumpCb*        m_pP1RegDumpCb;
#endif
};


};

#endif
