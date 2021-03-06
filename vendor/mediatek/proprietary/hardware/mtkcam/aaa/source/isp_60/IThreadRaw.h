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
/**
* @file IThread3A.h
* @brief Declarations of 3A Thread Interface Class
*/

#ifndef _ITHREAD_RAW_H_
#define _ITHREAD_RAW_H_

#include <aaa_types.h>
#include "I3AWrapper.h"

namespace NS3Av3
{
typedef enum
{
    E_3AEvent_NONE = 0,
    E_3AEvent_AE_I2C,
    E_3AEvent_Flash_On,
    E_3AEvent_Flash_Off,
    E_3AEvent_MainFlash_On,
    E_3AEvent_CCU_CB
} E_3AEvent_T;

class IThreadRaw
{

public:
    struct AFParam_T
    {
        MINT32                  i4MagicNum;
        MUINT32                 u4AfMode;
        MBOOL                   bEnable3ASetParams;
        MBOOL                   bFaceDetectEnable;
        MBOOL                   bImplicitTrig;
        MUINT8                  u1AfTrig;
        MUINT8                  u1AfPause;
        MUINT8                  u1MZOn;
        MUINT8                  u1PrecapTrig;
        MUINT8                  u1FlashTrigAF;
        MFLOAT                  fFocusDistance;
        CameraFocusArea_T       rFocusAreas;
        CameraArea_T            rScaleCropArea;
        MUINT32                 u4AFNVRAMIndex;
        MUINT8                  u1CaptureIntent;
        MUINT8                  u1ZSDCaptureIntent;

        AFParam_T()
            : i4MagicNum(0)
            , u4AfMode(0)
            , bEnable3ASetParams(MFALSE)
            , bFaceDetectEnable(MFALSE)
            , bImplicitTrig(MFALSE)
            , u1AfTrig(0)
            , u1AfPause(0)
            , u1MZOn(255)
            , u1PrecapTrig(0)
            , u1FlashTrigAF(0)
            , fFocusDistance(0)
            , u4AFNVRAMIndex(0)
            , u1CaptureIntent(0)
            , u1ZSDCaptureIntent(0)
            {
                memset(&rFocusAreas, 0, sizeof(CameraFocusArea_T));
                memset(&rScaleCropArea, 0, sizeof(CameraArea_T));
            }
    };
    struct ReqQ_T
    {
        ECmd_T      eCmd;
        AFParam_T   rParam;

        ReqQ_T(){eCmd = ECmd_CameraPreviewStart;}
        ReqQ_T(ECmd_T _eCmd, const AFParam_T& _rParam)
            : eCmd(_eCmd), rParam(_rParam) {}
    };
    struct EventQ_T
    {
        E_3AEvent_T eEvent;
        MINT32      i4Opt;

        EventQ_T(){eEvent = E_3AEvent_NONE; i4Opt = 0;}
        EventQ_T(E_3AEvent_T _eEvent, MINT32 _i4Opt)
            : eEvent(_eEvent), i4Opt(_i4Opt) {}
    };


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Interfaces.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //
public:
    static IThreadRaw* createInstance(I3AWrapper* pHal3A, MINT32 iSensorDev, MINT32 iSensorIdx);
    virtual MBOOL destroyInstance() = 0;
    virtual MVOID postToEventThread(E_3AEvent_T eEvent, MINT32 opt = 0) = 0;
    virtual MVOID enableAFThread(MVOID* pTaskMgr) = 0;
    virtual MVOID disableAFThread() = 0;
    virtual MVOID pauseAFThread() = 0;
    virtual MVOID resumeAFThread() = 0;
    virtual MBOOL sendRequest(ECmd_T const eCmd, MUINTPTR const i4Arg = 0) = 0;
    virtual MVOID notifyPreStop() = 0;
    /**
    * @brief create AE thread
    */
    virtual MVOID createEventThread() = 0;
    /**
    * @brief destroy Event thread
    */
    virtual MVOID destroyEventThread() = 0;
    /**
    * @brief get AF result
    */
    virtual MBOOL getCurrResult4AF(MINT32& i4MagicNumber, AFParam_T& AFParam) = 0;

protected:  //    Ctor/Dtor.
        IThreadRaw(){}
        virtual ~IThreadRaw(){}

        IThreadRaw(const IThreadRaw&);
        IThreadRaw& operator=(const IThreadRaw&);
};
}; // namespace NS3Av3
#endif //_ITHREAD_3A_H_
