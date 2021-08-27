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
#define LOG_TAG "aaa_state_pcap_n3d"

#ifndef ENABLE_MY_LOG
    #define ENABLE_MY_LOG       (1)
#endif

#include <aaa_types.h>
#include <aaa_error_code.h>
#include <aaa_log.h>

#include <aaa_hal.h>
#include <state_mgr_n3d/aaa_state_n3d.h>
#include <state_mgr/aaa_state_mgr.h>
#include <aaa_scheduler.h>
#include <ae_mgr_if.h>
#include <flash_mgr.h>
#include <af_mgr_if.h>
#include <afo_buf_mgr.h>
#include <awb_mgr_if.h>
#include <aao_buf_mgr.h>
#include <lsc_mgr2.h>
#include <awb_param.h>
#include <awb_tuning_custom.h>
#include <flash_awb_param.h>
#include <flash_awb_tuning_custom.h>
#include <aaa_common_custom.h>
#include <flash_param.h>
#include <flash_tuning_custom.h>
#include <kd_camera_feature.h>
#include <mtkcam/featureio/flicker_hal_base.h>
#include <aaa_sensor_mgr.h>
#include <aaa_sensor_buf_mgr.h>

#include <mtkcam/featureio/ISync3A.h>

using namespace NS3A;
using namespace NSIspTuning;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  StatePrecaptureN3d
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
StatePrecaptureN3d::
StatePrecaptureN3d(MINT32 sensorDevId, StateMgr* pStateMgr)
    : StatePrecapture(sensorDevId, pStateMgr)
{
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  eIntent_CameraPreviewStart
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT
StatePrecaptureN3d::
sendIntent(intent2type<eIntent_CameraPreviewStart>)
{
    MY_LOG("sendIntent(intent2type<eIntent_CameraPreviewStart>)  line=%d, PvMode=%d\n"
        , __LINE__
        , m_pHal3A->get3APreviewMode());
    MRESULT err = S_3A_OK;
    MBOOL bRet = MTRUE;
    // Get parameters
    Param_T rParam;
    m_pStateMgr->m_bHasAEEverBeenStable = MFALSE;
    m_pHal3A->getParams(rParam);

    //if (m_pHal3A->get3APreviewMode() != EPv_Normal) {
if (ENABLE_3A_GENERAL & m_pHal3A->m_3ACtrlEnable) {
    // ----- 3A mgr uninit operations go here -----
if (ENABLE_AWB & m_pHal3A->m_3ACtrlEnable) {
    // AWB uninit
    if (!IAwbMgr::getInstance().uninit(m_SensorDevId)) {
        MY_ERR("IAwbMgr::getInstance().uninit() fail\n");
        return E_3A_ERR;
    }
}
if (ENABLE_AE & m_pHal3A->m_3ACtrlEnable) {
    // AE uninit
    err = IAeMgr::getInstance().uninit(m_SensorDevId);
    if (FAILED(err)) {
        MY_ERR("IAeMgr::getInstance().uninit() fail\n");
        return err;
    }
}
if (ENABLE_AF & m_pHal3A->m_3ACtrlEnable) {
    // AF uninit
    err = IAfMgr::getInstance().uninit(m_SensorDevId);
    if (FAILED(err)) {
        MY_ERR("IAfMgr::getInstance().uninit() fail\n");
        return err;
    }
}
if (ENABLE_FLASH & m_pHal3A->m_3ACtrlEnable) {
    //Flash uninit
    // Flash turnOffFlashDevice + uninit
    FlashMgr::getInstance().turnOffFlashDevice(m_SensorDevId);
    if (!FlashMgr::getInstance().uninit(m_SensorDevId)) {
        MY_ERR("FlashMgr::getInstance().uninit() fail\n");
        return E_3A_ERR;
    }
}
if (ENABLE_FLICKER & m_pHal3A->m_3ACtrlEnable) {
    FlickerHalBase::getInstance().close(m_SensorDevId);
}
}
    //}

if (ENABLE_3A_GENERAL & m_pHal3A->m_3ACtrlEnable) {
if (ENABLE_AAOBUF & m_pHal3A->m_3ACtrlEnable) {
    // AAO DMAInit + AAStatEnable
    if (!IAAOBufMgr::getInstance().DMAInit(m_SensorDevId)) {
        MY_ERR("IAAOBufMgr::getInstance().DMAInit() fail");
        return E_3A_ERR;
    }
    if (!IAAOBufMgr::getInstance().AAStatEnable(m_SensorDevId, MTRUE)) {
        MY_ERR("IAAOBufMgr::getInstance().AAStatEnable() fail");
        return E_3A_ERR;
    }

    if (!IAEBufMgr::getInstance().DMAInit(m_SensorDevId)) {
        MY_ERR("IAEBufMgr::getInstance().DMAInit() fail");
        return E_3A_ERR;
    }

    if (!IAEBufMgr::getInstance().AAStatEnable(m_SensorDevId, MTRUE)) {
        MY_ERR("IAEBufMgr::getInstance().AAStatEnable() fail");
        return E_3A_ERR;
    }
}
if (ENABLE_AFOBUF & m_pHal3A->m_3ACtrlEnable) {
    // AFO DMAInit + AFStatEnable
    if (!IAFOBufMgr::getInstance().DMAInit(m_SensorDevId)) {
        MY_ERR("IAFOBufMgr::getInstance().DMAInit() fail");
        return E_3A_ERR;
    }
    if (!IAFOBufMgr::getInstance().AFStatEnable(m_SensorDevId, MTRUE)) {
        MY_ERR("IAFOBufMgr::getInstance().AFStatEnable() fail");
        return E_3A_ERR;
    }
}
if (ENABLE_FLASH & m_pHal3A->m_3ACtrlEnable) {
    // Flash init
    if (!FlashMgr::getInstance().init(m_SensorDevId, m_pHal3A->getSensorOpenIdx())) {
        MY_ERR("FlashMgr::getInstance()->init(i4SensorDev) fail\n");
        return E_3A_ERR;
    }
    bRet = (m_pHal3A->get3APreviewMode() == EPv_Normal)
        ? FlashMgr::getInstance().cameraPreviewStart(m_SensorDevId)
        : FlashMgr::getInstance().videoPreviewStart(m_SensorDevId);
    if (!bRet) {
        MY_ERR("FlashMgr::getInstance().cameraPreviewStart or videoPreviewStart fail, PvMode = %d\n"
            , m_pHal3A->get3APreviewMode());
        return E_3A_ERR;
    }
}
    IAwbMgr::getInstance().setStrobeMode(m_SensorDevId,
        (FlashMgr::getInstance().isAFLampOn(m_SensorDevId)) ? AWB_STROBE_MODE_ON : AWB_STROBE_MODE_OFF);

if (ENABLE_AWB & m_pHal3A->m_3ACtrlEnable) {
    // AWB init
    bRet = (m_pHal3A->get3APreviewMode() == EPv_Normal)
        ? IAwbMgr::getInstance().cameraPreviewInit(m_SensorDevId, m_pHal3A->getSensorOpenIdx(), rParam)
        : IAwbMgr::getInstance().camcorderPreviewInit(m_SensorDevId, m_pHal3A->getSensorOpenIdx(), rParam);
    if (!bRet) {
        MY_ERR("IAwbMgr::getInstance().cameraPreviewReinit or camcorderPreviewInit fail, PvMode = %d\n"
            , m_pHal3A->get3APreviewMode());
        return E_3A_ERR;
    }
}
    IAeMgr::getInstance().setStrobeMode(m_SensorDevId,
        (FlashMgr::getInstance().isAFLampOn(m_SensorDevId)) ? MTRUE : MFALSE);

if (ENABLE_AE & m_pHal3A->m_3ACtrlEnable) {
    // AE init
    err = (m_pHal3A->get3APreviewMode() == EPv_Normal)
        ? IAeMgr::getInstance().cameraPreviewInit(m_SensorDevId, m_pHal3A->getSensorOpenIdx(), rParam)
        : IAeMgr::getInstance().camcorderPreviewInit(m_SensorDevId, m_pHal3A->getSensorOpenIdx(), rParam);
    if (FAILED(err)) {
        MY_ERR("IAeMgr::getInstance().cameraPreviewReinit or camcorderPreviewInit fail, PvMode = %d\n"
            , m_pHal3A->get3APreviewMode());
        return err;
    }
}
if (ENABLE_AF & m_pHal3A->m_3ACtrlEnable) {
    // AF init
    err = IAfMgr::getInstance().init(m_SensorDevId, m_pHal3A->getSensorOpenIdx());
    if (FAILED(err)) {
        MY_ERR("IAfMgr::getInstance().init() fail\n");
        return err;
    }

    IAfMgr::getInstance().setAF_IN_HSIZE(m_SensorDevId);
    //FIXME: IAfMgr::getInstance().setFlkWinConfig(m_SensorDevId);

}
#if 0
if (ENABLE_ISPTUNE & m_pHal3A->m_3ACtrlEnable) {
    IspTuningMgr::getInstance().validatePerFrame(m_SensorDevId, MTRUE);
}
#endif

if (ENABLE_FLICKER & m_pHal3A->m_3ACtrlEnable) {
   MY_LOG("FlickerHalBase sensor index: %d", m_pHal3A->getSensorOpenIdx());
   AAASensorMgr::getInstance().setFlickerFrameRateActive(m_SensorDevId, 1);
   FlickerHalBase::getInstance().open(m_SensorDevId, m_pHal3A->getSensorOpenIdx(), m_pHal3A->getTGInfo());
}
    /*NeedUpdate*///FlickerHalBase::getInstance()->cameraPreviewStart();
}
    // Reset frame count to -2
    m_pStateMgr->resetFrameCount();
    m_pStateMgr->transitState(eState_Precapture, eState_CameraPreview);

    return S_3A_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  eIntent_VsyncUpdate
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT
StatePrecaptureN3d::
sendIntent(intent2type<eIntent_VsyncUpdate>)
{
    MRESULT err = S_3A_OK;
    BufInfo_T rBufInfo;

    MY_LOG("[StatePrecapture::sendIntent]<eIntent_VsyncUpdate> line=%d, frameCnt=%d, EPrecapState=%d"
        , __LINE__
        , m_pStateMgr->getFrameCount()
        , static_cast<int>(m_pStateMgr->getPrecapState()));

    if(m_pHal3A->isReadyToCapture())
    {
        MY_LOG("VsyncUpdate ReadyToCapture=1, skip");
        return S_3A_OK;
    }

if (ENABLE_3A_GENERAL & m_pHal3A->m_3ACtrlEnable) {
if (ENABLE_AAOBUF & m_pHal3A->m_3ACtrlEnable) {
    // Dequeue AAO DMA buffer
        IAAOBufMgr::getInstance().dequeueHwBuf(m_SensorDevId, rBufInfo);
}
}
    m_pStateMgr->mAFStateCntSet.resetAll(); //reset all AFState cnt, flags
    if (m_pStateMgr->getPrecapState() == ePrecap_AF_BeforeFlash)
    {
        err = sendPrecapIntent(intent2type<eIntent_VsyncUpdate>(), state2type<ePrecap_AF_BeforeFlash>());
        if (err != S_3A_OK) MY_ERR("sendPrecapIntent(eIntent_VsyncUpdate, ePrecap_AF_BeforeFlash) return(%d)\n", err);
    }
    if ((m_pStateMgr->getPrecapState() == ePrecap_AE) && (m_pStateMgr->mAFStateCntSet.bNeedToDoPrecapAF == 0))
    {
        err = sendPrecapIntent(intent2type<eIntent_VsyncUpdate>(), state2type<ePrecap_AE>(), &rBufInfo);
        if (err != S_3A_OK) MY_ERR("sendPrecapIntent(eIntent_VsyncUpdate, ePrecap_AE) return(%d)\n", err);
    }
    //Note: not "else if ..." because after AE finishes, flash should continue to make Precapture faster.
    if ((m_pStateMgr->getPrecapState() == ePrecap_Flash) && (m_pStateMgr->mAFStateCntSet.bNeedToDoPrecapAF == 0))
    {
        err = sendPrecapIntent(intent2type<eIntent_VsyncUpdate>(), state2type<ePrecap_Flash>(), &rBufInfo);
        if (err != S_3A_OK) MY_ERR("sendPrecapIntent(eIntent_VsyncUpdate, ePrecap_Flash) return(%d)\n", err);
    }
    if ((m_pStateMgr->getPrecapState() == ePrecap_AF_AfterFlash) && (m_pStateMgr->mAFStateCntSet.bNeedToDoPrecapAF == 0))
    {
        err = sendPrecapIntent(intent2type<eIntent_VsyncUpdate>(), state2type<ePrecap_AF_AfterFlash>());
        if (err != S_3A_OK) MY_ERR("sendPrecapIntent(eIntent_VsyncUpdate, ePrecap_AF_AfterFlash) return(%d)\n", err);
    }


if (ENABLE_3A_GENERAL & m_pHal3A->m_3ACtrlEnable) {
if (ENABLE_LSC & m_pHal3A->m_3ACtrlEnable) {
if (ENABLE_AWB & m_pHal3A->m_3ACtrlEnable) {
    //FIXME: move all TSF parameter mapping operations and print log into a common function
    // TSF
    AWB_OUTPUT_T rAWBOutput;
    IAwbMgr::getInstance().getAWBOutput(m_SensorDevId, rAWBOutput);
    LscMgr2::TSF_AWB_INFO rAwbInfo;
    rAwbInfo.m_i4LV        = IAeMgr::getInstance().getLVvalue(m_SensorDevId, MTRUE);
    rAwbInfo.m_u4CCT    = IAwbMgr::getInstance().getAWBCCT(m_SensorDevId);
    rAwbInfo.m_RGAIN    = rAWBOutput.rAWBInfo.rCurrentAWBGain.i4R;
    rAwbInfo.m_GGAIN    = rAWBOutput.rAWBInfo.rCurrentAWBGain.i4G;
    rAwbInfo.m_BGAIN    = rAWBOutput.rAWBInfo.rCurrentAWBGain.i4B;
    rAwbInfo.m_FLUO_IDX = rAWBOutput.rAWBInfo.i4FluorescentIndex;
    rAwbInfo.m_DAY_FLUO_IDX = rAWBOutput.rAWBInfo.i4DaylightFluorescentIndex;

    LscMgr2::getInstance(static_cast<ESensorDev_T>(m_SensorDevId))->updateTsf(
        LscMgr2::E_TSF_CMD_RUN, &rAwbInfo, reinterpret_cast<MVOID *>(rBufInfo.virtAddr));

    MY_LOG("lv %d, cct %d, rgain %d, bgain %d, ggain %d, fluo idx %d, day flou idx %d\n",
        rAwbInfo.m_i4LV,
        rAwbInfo.m_u4CCT,
        rAwbInfo.m_RGAIN,
        rAwbInfo.m_GGAIN,
        rAwbInfo.m_BGAIN,
        rAwbInfo.m_FLUO_IDX,
        rAwbInfo.m_DAY_FLUO_IDX
        );
}
}
if (ENABLE_AAOBUF & m_pHal3A->m_3ACtrlEnable) {
    // Enqueue AAO DMA buffer
    IAAOBufMgr::getInstance().enqueueHwBuf(m_SensorDevId, rBufInfo);
    // Update AAO DMA address
    IAAOBufMgr::getInstance().updateDMABaseAddr(m_SensorDevId);
}
}

    //Note: not "else if ...", if flash finishes this frame, then we announce ReadyToCapture to Middleware
    if ((m_pStateMgr->getPrecapState() == ePrecap_Num) && (m_pStateMgr->mAFStateCntSet.bNeedToDoPrecapAF == 0))
    {
        // at this moment, all operation of Precapture must have finished. Then wait for Capture command
        if(FlashMgr::getInstance().isFlashOnCapture(m_SensorDevId)) FlashMgr::getInstance().setCapPara(m_SensorDevId);
        m_pStateMgr->resetPrecapState();
        m_pHal3A->notifyReadyToCapture();

        MINT32 i4SyncOpt = ISync3A::E_SYNC3A_DO_AE_PRECAP|ISync3A::E_SYNC3A_DO_AWB;
        // 2A sync: independent AE/AWB
        MY_LOG("[%s]PreCap Sync 2A: Sensor(%d) =============", __FUNCTION__, m_SensorDevId);
        MINT32 i4Sync = ISync3AMgr::getSync3A(ISync3AMgr::E_SYNC3AMGR_CAPTURE)->sync(m_SensorDevId, i4SyncOpt);
        MY_LOG("[%s]PreCap Sync 2A: Sensor(%d) Ready to validate (%d)", __FUNCTION__, m_SensorDevId, i4Sync);

        m_pHal3A->mpCbSet->doNotifyCb(I3ACallBack::eID_NOTIFY_READY2CAP, 0, 0, 0);
        MY_LOG("VsyncUpdate notifyReadyToCapture, resetPrecapState");
    }

    return  err;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  eIntent_Uninit
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT
StatePrecaptureN3d::
sendIntent(intent2type<eIntent_Uninit>)
{
    MY_LOG("sendIntent(intent2type<eIntent_Uninit>)  line=%d", __LINE__);
    MRESULT err = S_3A_OK;

if (ENABLE_3A_GENERAL & m_pHal3A->m_3ACtrlEnable) {

    // ----- 3A mgr uninit operations go here -----
if (ENABLE_AWB & m_pHal3A->m_3ACtrlEnable) {
    // AWB uninit
    if (!IAwbMgr::getInstance().uninit(m_SensorDevId)) {
        MY_ERR("IAwbMgr::getInstance().uninit() fail\n");
        return E_3A_ERR;
    }
}
if (ENABLE_AE & m_pHal3A->m_3ACtrlEnable) {
    // AE uninit
    err = IAeMgr::getInstance().uninit(m_SensorDevId);
    if (FAILED(err)) {
        MY_ERR("IAeMgr::getInstance().uninit() fail\n");
        return err;
    }
}
if (ENABLE_AF & m_pHal3A->m_3ACtrlEnable) {
    // AF uninit
    err = IAfMgr::getInstance().uninit(m_SensorDevId);
    if (FAILED(err)) {
        MY_ERR("IAfMgr::getInstance().uninit() fail\n");
        return err;
    }
}
if (ENABLE_FLASH & m_pHal3A->m_3ACtrlEnable) {
    //Flash uninit
    // Flash turnOffFlashDevice + uninit
    FlashMgr::getInstance().turnOffFlashDevice(m_SensorDevId);
    if (!FlashMgr::getInstance().uninit(m_SensorDevId)) {
        MY_ERR("FlashMgr::getInstance().uninit() fail\n");
        return E_3A_ERR;
    }
}
if (ENABLE_FLICKER & m_pHal3A->m_3ACtrlEnable) {
    FlickerHalBase::getInstance().close(m_SensorDevId);
}
    // ----- Uninit operations go here -----
if (ENABLE_AAOBUF & m_pHal3A->m_3ACtrlEnable) {
    // AAO DMA buffer uninit
    if (!IAAOBufMgr::getInstance().uninit(m_SensorDevId)) {
        MY_ERR("IAAOBufMgr::getInstance().uninit() fail");
        return E_3A_ERR;
    }
    if (!IAEBufMgr::getInstance().uninit(m_SensorDevId)) {
        MY_ERR("IAEBufMgr::getInstance().uninit() fail");
        return E_3A_ERR;
    }
}

if (ENABLE_AFOBUF & m_pHal3A->m_3ACtrlEnable) {
    // AFO DMA buffer uninit
    if (!IAFOBufMgr::getInstance().uninit(m_SensorDevId)) {
        MY_ERR("IAFOBufMgr::getInstance().uninit() fail");
        return E_3A_ERR;
    }
}
}


    // State transition: eState_Capture --> eState_Uninit
    m_pStateMgr->transitState(eState_Precapture, eState_Uninit);

    return  S_3A_OK;
}


MRESULT
StatePrecaptureN3d::
sendPrecapIntent(intent2type<eIntent_VsyncUpdate>, state2type<ePrecap_AE>, MVOID* pBufInfo)
{
    MY_LOG("StatePrecapture::sendIntent(eIntent_VsyncUpdate, ePrecap_AE)");

    MRESULT err = S_3A_OK;
    MBOOL bIsStrobeFired = MFALSE;
    BufInfo_T* pBuf = reinterpret_cast<BufInfo_T*>(pBufInfo);
    MINT32 i4SceneLv = 80;
    MINT32 i4AoeCompLv = 80;
    MBOOL bAEStable = MTRUE;

if (!(
(ENABLE_3A_GENERAL & m_pHal3A->m_3ACtrlEnable) &&
(ENABLE_AE & m_pHal3A->m_3ACtrlEnable) &&
(ENABLE_AWB & m_pHal3A->m_3ACtrlEnable)
))
{m_pStateMgr->proceedPrecapState();return err;}

if (ENABLE_3A_GENERAL & m_pHal3A->m_3ACtrlEnable) {
if (ENABLE_AE & m_pHal3A->m_3ACtrlEnable) {
    // Update frame count
    m_pStateMgr->updateFrameCount();
    // One-shot AE or strobe AE
    /*NeedUpdate*///CPTLog(Event_Pipe_3A_AE, CPTFlagStart);    // Profiling Start.
    IAeMgr::getInstance().doPreCapAE(m_SensorDevId, m_pStateMgr->getFrameCount(),
                                    bIsStrobeFired, reinterpret_cast<MVOID *>(pBuf->virtAddr),
                                    m_pScheduler->jobAssignAndTimerStart(E_Job_AeFlare), MTRUE, 1);
    m_pScheduler->jobTimerEnd(E_Job_AeFlare);
    i4SceneLv = IAeMgr::getInstance().getLVvalue(m_SensorDevId, MFALSE);
    i4AoeCompLv = IAeMgr::getInstance().getAOECompLVvalue(m_SensorDevId, MFALSE);
    bAEStable = IAeMgr::getInstance().IsAEStable(m_SensorDevId);

    // workaround for iVHDR
    MUINT32 u4AFSGG1Gain;
    IAeMgr::getInstance().getAESGG1Gain(m_SensorDevId, &u4AFSGG1Gain);
    IAfMgr::getInstance().setSGGPGN(m_SensorDevId, (MINT32) u4AFSGG1Gain);

    /*NeedUpdate*///CPTLog(Event_Pipe_3A_AE, CPTFlagEnd);     // Profiling End.
}
if (ENABLE_AWB & m_pHal3A->m_3ACtrlEnable) {
    if(bAEStable) // AE is stable
    {
        m_pStateMgr->m_bIsFocuseFinish = MTRUE;

        IAeMgr::getInstance().doBackAEInfo(m_SensorDevId);

        // One-shot AWB without strobe
        IAwbMgr::getInstance().doPreCapAWB(m_SensorDevId, i4AoeCompLv, reinterpret_cast<MVOID *>(pBuf->virtAddr), MFALSE);

        // both one-shot AE and one-shot AWB are done
        m_pStateMgr->proceedPrecapState();
    }
    else
    {
        // apply AE if not stable yet.
        //IAeMgr::getInstance().doPreCapAE(m_SensorDevId, m_pStateMgr->getFrameCount(), bIsStrobeFired, reinterpret_cast<MVOID *>(pBuf->virtAddr), E_AE_AE_APPLY, MFALSE, 1);
        if (IAeMgr::getInstance().IsNeedUpdateSensor(m_SensorDevId))
        {
            m_pHal3A->postToAESenThread(MFALSE);
            m_pHal3A->postToAESenThread(MTRUE);
        }
    }
}

}
    return err;
}


MRESULT
StatePrecaptureN3d::
sendPrecapIntent(intent2type<eIntent_VsyncUpdate>, state2type<ePrecap_Flash>, MVOID* pBufInfo)
{
    MY_LOG("StatePrecapture::sendIntent(eIntent_VsyncUpdate, ePrecap_Flash)");
    m_pStateMgr->proceedPrecapState();

    return S_3A_OK;
}

MRESULT
StatePrecaptureN3d::
sendPrecapIntent(intent2type<eIntent_VsyncUpdate>, state2type<ePrecap_AF_BeforeFlash>)
{
    MY_LOG("StatePrecapture::sendIntent(eIntent_VsyncUpdate, ePrecap_AF_BeforeFlash)");
    m_pStateMgr->proceedPrecapState();

    return S_3A_OK;
}


MRESULT
StatePrecaptureN3d::
sendPrecapIntent(intent2type<eIntent_VsyncUpdate>, state2type<ePrecap_AF_AfterFlash>)
{
    MY_LOG("StatePrecapture::sendIntent(eIntent_VsyncUpdate, ePrecap_AF_AfterFlash)");
    m_pStateMgr->proceedPrecapState();

    return S_3A_OK;
}

