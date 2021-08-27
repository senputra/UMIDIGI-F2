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

#define LOG_TAG "MtkCam/CamAdapter"
//
#include <mtkcam/utils/fwk/MtkCamera.h>
//
#include <inc/CamUtils.h>
using namespace android;
using namespace MtkCamUtils;
//
#include <inc/ImgBufProvidersManager.h>
//
#include <mtkcam/v1/IParamsManager.h>
#include <mtkcam/v1/ICamAdapter.h>
#include <inc/BaseCamAdapter.h>
#include "inc/MtkDefaultCamAdapter.h"
#include "inc/IState.h"
using namespace NSMtkDefaultCamAdapter;
//
#include "core/camshot/inc/CamShotUtils.h"

/******************************************************************************
*
*******************************************************************************/
#define MY_LOGV(fmt, arg...)        CAM_LOGV("(%d)(%d)(%s)[%s] " fmt, ::gettid(), getOpenId(), getName(), __FUNCTION__, ##arg)
#define MY_LOGD(fmt, arg...)        CAM_LOGD("(%d)(%d)(%s)[%s] " fmt, ::gettid(), getOpenId(), getName(), __FUNCTION__, ##arg)
#define MY_LOGI(fmt, arg...)        CAM_LOGI("(%d)(%d)(%s)[%s] " fmt, ::gettid(), getOpenId(), getName(), __FUNCTION__, ##arg)
#define MY_LOGW(fmt, arg...)        CAM_LOGW("(%d)(%d)(%s)[%s] " fmt, ::gettid(), getOpenId(), getName(), __FUNCTION__, ##arg)
#define MY_LOGE(fmt, arg...)        CAM_LOGE("(%d)(%d)(%s)[%s] " fmt, ::gettid(), getOpenId(), getName(), __FUNCTION__, ##arg)
#define MY_LOGA(fmt, arg...)        CAM_LOGA("(%d)(%d)(%s)[%s] " fmt, ::gettid(), getOpenId(), getName(), __FUNCTION__, ##arg)
#define MY_LOGF(fmt, arg...)        CAM_LOGF("(%d)(%d)(%s)[%s] " fmt, ::gettid(), getOpenId(), getName(), __FUNCTION__, ##arg)
//
#define MY_LOGV_IF(cond, ...)       do { if ( (cond) ) { MY_LOGV(__VA_ARGS__); } }while(0)
#define MY_LOGD_IF(cond, ...)       do { if ( (cond) ) { MY_LOGD(__VA_ARGS__); } }while(0)
#define MY_LOGI_IF(cond, ...)       do { if ( (cond) ) { MY_LOGI(__VA_ARGS__); } }while(0)
#define MY_LOGW_IF(cond, ...)       do { if ( (cond) ) { MY_LOGW(__VA_ARGS__); } }while(0)
#define MY_LOGE_IF(cond, ...)       do { if ( (cond) ) { MY_LOGE(__VA_ARGS__); } }while(0)
#define MY_LOGA_IF(cond, ...)       do { if ( (cond) ) { MY_LOGA(__VA_ARGS__); } }while(0)
#define MY_LOGF_IF(cond, ...)       do { if ( (cond) ) { MY_LOGF(__VA_ARGS__); } }while(0)


/******************************************************************************
*   Function Prototype.
*******************************************************************************/
//
bool
createShotInstance(
    sp<IShot>&          rpShot,
    uint32_t const      u4ShotMode,
    int32_t const       i4OpenId,
    sp<IParamsManager>  pParamsMgr
);
//

/******************************************************************************
*
*******************************************************************************/
bool
CamAdapter::
updateShotInstance()
{
    uint32_t const u4ShotMode = mpDefaultCtrlNode->getShotMode();
    MY_LOGD("ShotMode(%d)",u4ShotMode);
    return  createShotInstance(mpShot, u4ShotMode, getOpenId(), getParamsManager());
}


/******************************************************************************
*
*******************************************************************************/
status_t
CamAdapter::
prepareToCapture()
{
    status_t status = NO_ERROR;
    sp<ZipImageCallbackThread> pCallbackThread;
    sp<ICaptureCmdQueThread> pCaptureCmdQueThread = mpCaptureCmdQueThread;
    bool hasExtCallback = true;
    //
    if( PARAMSMANAGER_MAP_INST(eMapAppMode)->stringFor(mpParamsMgr->getHalAppMode()) == MtkCameraParameters::APP_MODE_NAME_DEFAULT )
    {
        hasExtCallback = false;
    }
    pCallbackThread = new ZipImageCallbackThread(
                            mspStateManager.get(),
                            mpCamMsgCbInfo,
                            hasExtCallback
                            );
    //
    if  ( !pCallbackThread.get() || OK != (status = pCallbackThread->run("CamAdapter::prepareToCapture") ) )
    {
        MY_LOGE(
            "Fail to run CallbackThread - CallbackThread.get(%p), status[%s(%d)]",
            pCallbackThread.get(), ::strerror(-status), -status
        );
        goto lbExit;
    }
    mpZipCallbackThread = pCallbackThread;
    pCallbackThread = 0;
    //
lbExit:
    return status;
}


/******************************************************************************
*
*******************************************************************************/
bool
CamAdapter::
waitForShotDone()
{
    sp<ZipImageCallbackThread> pCallbackThread = mpZipCallbackThread.promote();
    //  wait for capture callback is done
    if  ( pCallbackThread.get() )
    {
        MY_LOGD("doCallback(ZipImageCallbackThread::callback_type_exit)");
        pCallbackThread->doCallback(ZipImageCallbackThread::callback_type_exit);
        MY_LOGD("wait for capture callback done +");
        pCallbackThread->join();
        MY_LOGD("wait for capture callback done -");
        pCallbackThread = 0;
        mpZipCallbackThread = 0;
    }
    return true;
}


/******************************************************************************
*
*******************************************************************************/
bool
CamAdapter::
isTakingPicture() const
{
    bool ret =  mpStateManager->isState(IState::eState_PreCapture) ||
                mpStateManager->isState(IState::eState_Capture) ||
                mpStateManager->isState(IState::eState_PreviewCapture) ||
                mpStateManager->isState(IState::eState_VideoSnapshot);
    if  ( ret )
    {
        MY_LOGD("isTakingPicture(1):%s", mpStateManager->getCurrentState()->getName());
    }
    //
    return  ret;
}


/******************************************************************************
*
*******************************************************************************/
status_t
CamAdapter::
takePicture()
{
    status_t status = OK;

    sp<ZipImageCallbackThread> pCallbackThread = mpZipCallbackThread.promote();
    //if case : not zsd shot, zsd hdr and zsd mfll shot, exit zipimage callback thread
    //else if case : zsd shot, need wait shot complete but cannot wait jpeg callback done(will cause deadlock)
    //else case : zsd hdr and zsd mfll shot, do nothing
    if( pCallbackThread.get() &&
        pCallbackThread->getShotMode() != eShotMode_ZsdShot &&
        pCallbackThread->getShotMode() != eShotMode_ZsdHdrShot &&
        pCallbackThread->getShotMode() != eShotMode_ZsdMfllShot &&
        pCallbackThread->getShotMode() != eShotMode_FaceBeautyShotCc )
    {
        pCallbackThread->doCallback(ZipImageCallbackThread::callback_type_exit);
        pCallbackThread->join();
        pCallbackThread = 0;
        mpZipCallbackThread = 0;
    }
    else if( pCallbackThread.get() &&
             pCallbackThread->getShotMode() == eShotMode_ZsdShot &&
             mpStateManager->isState(IState::eState_PreviewCapture) )
    {
        MY_LOGD("zsd shot still in PreviewCapture state, start wait Preview state");
        IStateManager::StateObserver stateWaiter(mpStateManager);
        mpStateManager->registerOneShotObserver(&stateWaiter);
        if( OK != stateWaiter.waitState(IState::eState_Preview) )
        {
            MY_LOGW("fail to wait preview state");
        }
    }

    pCallbackThread = mpZipCallbackThread.promote();
    if( !pCallbackThread.get() )
    {
        if( OK != (status = prepareToCapture()) )
        {
            MY_LOGE("failed to prepareToCapture");
            goto lbExit;
        }
    }

    pCallbackThread = mpZipCallbackThread.promote();
    pCallbackThread->incShotCount();
    pCallbackThread = 0;
    //
    if( !mpDefaultCtrlNode->updateShotMode() )
    {
        MY_LOGE("update shot mode failed");
        status = INVALID_OPERATION;
        goto lbExit;
    }
    //
    mShotMode = mpDefaultCtrlNode->getShotMode();
    mbTakePicPrvNotStop = false;
    //
    if(mpStateManager->isState(IState::eState_Recording))
    {
        if( ::strcmp(mpParamsMgr->getStr(MtkCameraParameters::KEY_VIDEO_FRAME_FORMAT), MtkCameraParameters::PIXEL_FORMAT_BITSTREAM) == 0 ||
            mpParamsMgr->getInt(CameraParameters::KEY_PREVIEW_FRAME_RATE) > 30)
        {
            MY_LOGE("Not support VSS");
            status = INVALID_OPERATION;
            goto lbExit;
        }
        else
        {
            MY_LOGD("It is recording state, just capture.");
            mbTakePicPrvNotStop = true;
        }
    }
    else
    {
        if(mpParamsMgr->getInt(MtkCameraParameters::KEY_CAMERA_MODE) != MtkCameraParameters::CAMERA_MODE_NORMAL)
        {
            if(mShotMode == eShotMode_ZsdShot || mShotMode == eShotMode_ContinuousShotCc || mShotMode == eShotMode_FaceBeautyShotCc)
            {
                MY_LOGD("Take picture without stopping preview");
                mbTakePicPrvNotStop = true;
            }
            // if in ZSD extension mode, related activity in default control node need to done first
            else if(mShotMode == eShotMode_ZsdHdrShot)
            {
                MY_LOGD("HDR shot in ZSD flow");
                mbTakePicPrvNotStop = true;
                mpDefaultCtrlNode->startZsdExtShot(ZSDEXT_HDR);
            }
            else if(mShotMode == eShotMode_ZsdMfllShot)
            {
                MY_LOGD("MFLL shot in ZSD flow");
                mbTakePicPrvNotStop = true;

                /**
                 *  To re-check MFLL info, because there's a case like:
                 *    1. AIS is enabled
                 *    2. The current ISO is not greater than tuning threshold,
                 *       it means that no Multi-Frame Blending (MFB) need.
                 *
                 *  In this case, we need to adjust EXP/ISO but no need to do MFB.
                 */
                sp<IParamsManager> pParamsMgr = getParamsManager();
                NS3A::CaptureParam_T Cap3AParamMfll;
                MUINT32 mfbNumber;
                MBOOL isUpdateAE;
                NSCamShot::getMFLLCapInfo(pParamsMgr->getMultFrameBlending(),
                                          getOpenId(),
                                          Cap3AParamMfll,
                                          mfbNumber,
                                          isUpdateAE);
                MY_LOGD("ZsdExtShot: mfb(%d), frames(%d)", pParamsMgr->getMultFrameBlending(), mfbNumber);
                /* if mfb number is 1, reset mShotMode to ZsdShot */
                if (mfbNumber <= 1) {
                    MY_LOGD("ZsdExtShot: ZSD+AIS+singleShot");
                    /**
                     *  Here, we re-set eShotMode back to ZsdShot but
                     *  we still start ZsdExtShot with ZSDEXT_MFLL for adjusting
                     *  exposure/iso before dequeue buffer from CapBufMgr. And
                     *  the exposure/iso will be rollback after capture done too.
                     */
                    mpDefaultCtrlNode->setShotMode(eShotMode_ZsdShot);
                    mShotMode = eShotMode_ZsdShot;
                }

                mpDefaultCtrlNode->startZsdExtShot(ZSDEXT_MFLL,mfbNumber);
            }
        }
        //
        if(!mbTakePicPrvNotStop)
        {
            status = mpStateManager->getCurrentState()->onPreCapture(this);
            if(OK != status)
            {
                goto lbExit;
            }
            //
            status = mpStateManager->getCurrentState()->onStopPreview(this);
            if(OK != status)
            {
                goto lbExit;
            }
        }
    }
    //
    status = mpStateManager->getCurrentState()->onCapture(this);
    //
    if(OK != status)
    {
        goto lbExit;
    }
    //
lbExit:
    return status;
}


/******************************************************************************
*
*******************************************************************************/
status_t
CamAdapter::
cancelPicture()
{
    if( mpStateManager->isState(IState::eState_Capture) ||
        mpStateManager->isState(IState::eState_PreviewCapture) ||
        mpStateManager->isState(IState::eState_VideoSnapshot))
    {
        mpStateManager->getCurrentState()->onCancelCapture(this);
    }
    return OK;
}


/******************************************************************************
*
*******************************************************************************/
status_t
CamAdapter::
setCShotSpeed(int32_t i4CShotSpeed)
{
    if(i4CShotSpeed <= 0 )
    {
        MY_LOGE("cannot set continuous shot speed as %d fps)", i4CShotSpeed);
        return BAD_VALUE;
    }

    sp<IShot> pShot = mpShot;
    if( pShot != 0 )
    {
        pShot->sendCommand(eCmd_setCShotSpeed, i4CShotSpeed, 0);
    }

    return OK;
}


/******************************************************************************
*   CamAdapter::takePicture() -> IState::onCapture() ->
*   IStateHandler::onHandleCapture() -> CamAdapter::onHandleCapture()
*******************************************************************************/
status_t
CamAdapter::
onHandleCapture()
{
    status_t status = DEAD_OBJECT;
    sp<ZipImageCallbackThread> pCallbackThread = mpZipCallbackThread.promote();
    sp<ICaptureCmdQueThread> pCaptureCmdQueThread = mpCaptureCmdQueThread;
    bool isZsdWithFlash = false;
    //
    if( !pCallbackThread.get() )
    {
        MY_LOGE("no callback thread");
        goto lbExit;
    }
    //
    if( mpDefaultCtrlNode->getShotMode() == eShotMode_NormalShot &&
        mName == MtkCameraParameters::APP_MODE_NAME_MTK_ZSD )
    {
        isZsdWithFlash = true;
    }
    pCallbackThread->setShotMode(mShotMode, IState::eState_Idle, isZsdWithFlash);
    pCallbackThread = 0;
    //
    if  ( pCaptureCmdQueThread != 0 ) {
        status = pCaptureCmdQueThread->onCapture();
    }
    //
lbExit:
    return  status;
}


/******************************************************************************
*
*******************************************************************************/
status_t
CamAdapter::
onHandleCaptureDone()
{
    if(mpResMgrDrv)
    {
        ResMgrDrv::MODE_STRUCT mode;
        mpResMgrDrv->getMode(&mode);
        mode.scenSw = ResMgrDrv::SCEN_SW_CAM_IDLE;
        mpResMgrDrv->setMode(&mode);
    }
    //
    mpStateManager->transitState(IState::eState_Idle);
    return  OK;
}


/******************************************************************************
*   CamAdapter::cancelPicture() -> IState::onCancelCapture() ->
*   IStateHandler::onHandleCancelCapture() -> CamAdapter::onHandleCancelCapture()
*******************************************************************************/
status_t
CamAdapter::
onHandleCancelCapture()
{
    MY_LOGD("");
    sp<IShot> pShot = mpShot;
    if  ( pShot != 0 )
    {
        pShot->sendCommand(eCmd_cancel);
    }
    //
    return  OK;
}


/******************************************************************************
*   CamAdapter::takePicture() -> IState::onCapture() ->
*   IStateHandler::onHandleCapture() -> CamAdapter::onHandleCapture()
*******************************************************************************/
status_t
CamAdapter::
onHandlePreviewCapture()
{
    status_t status = DEAD_OBJECT;
    sp<ZipImageCallbackThread> pCallbackThread = mpZipCallbackThread.promote();
    sp<ICaptureCmdQueThread> pCaptureCmdQueThread = mpCaptureCmdQueThread;
    //
    if( !pCallbackThread.get() )
    {
        MY_LOGE("no callback thread");
        goto lbExit;
    }
    //
    pCallbackThread->setShotMode(mShotMode, IState::eState_Preview);
    pCallbackThread = 0;
    //
    if  ( pCaptureCmdQueThread != 0 ) {
        status = pCaptureCmdQueThread->onCapture();
    }
    //
lbExit:
    return  status;

}


/******************************************************************************
*
*******************************************************************************/
status_t
CamAdapter::
onHandlePreviewCaptureDone()
{
    if(mpResMgrDrv)
    {
        ResMgrDrv::MODE_STRUCT mode;
        mpResMgrDrv->getMode(&mode);
        mode.scenSw = ResMgrDrv::SCEN_SW_ZSD;
        mpResMgrDrv->setMode(&mode);
    }
    //
    mpStateManager->transitState(IState::eState_Preview);

    // if in ZSD ext mode after shot finish, stop ZHDR mode in default control node
    if(mpDefaultCtrlNode->getZsdExtMode() != ZSDEXT_OFF)
    {
        mpDefaultCtrlNode->stopZsdExtShot();
    }
    //
    if( mShotMode == eShotMode_ContinuousShotCc )
    {
        mpDefaultCtrlNode->setShotMode(0);
    }
    return  OK;
}


/******************************************************************************
*   CamAdapter::cancelPicture() -> IState::onCancelCapture() ->
*   IStateHandler::onHandleCancelCapture() -> CamAdapter::onHandleCancelCapture()
*******************************************************************************/
status_t
CamAdapter::
onHandleCancelPreviewCapture()
{
    return  onHandleCancelCapture();
}


/******************************************************************************
*
*
*******************************************************************************/
status_t
CamAdapter::
onHandleVideoSnapshot()
{
    status_t status = DEAD_OBJECT;
    sp<ZipImageCallbackThread> pCallbackThread = mpZipCallbackThread.promote();
    sp<ICaptureCmdQueThread> pCaptureCmdQueThread = mpCaptureCmdQueThread;
    //
    if( !pCallbackThread.get() )
    {
        MY_LOGE("no callback thread");
        goto lbExit;
    }
    //
    pCallbackThread->setShotMode(mShotMode, IState::eState_Recording);
    pCallbackThread = 0;
    //
    if  ( pCaptureCmdQueThread != 0 ) {
        status = pCaptureCmdQueThread->onCapture();
    }
    //
lbExit:
    return  status;

}


/******************************************************************************
*
*
*******************************************************************************/
status_t
CamAdapter::
onHandleVideoSnapshotDone()
{
    if(mpResMgrDrv)
    {
        ResMgrDrv::MODE_STRUCT mode;
        mpResMgrDrv->getMode(&mode);
        if(mpParamsMgr->getInt(CameraParameters::KEY_PREVIEW_FRAME_RATE) <= 30)
        {
            mode.scenSw = ResMgrDrv::SCEN_SW_VIDEO_REC;
        }
        else
        {
            mode.scenSw = ResMgrDrv::SCEN_SW_VIDEO_REC_HS;
        }
        mpResMgrDrv->setMode(&mode);
    }
    //
    if(mpStateManager->isState(IState::eState_VideoSnapshot))
    {
        mpStateManager->transitState(IState::eState_Recording);
    }
    return  OK;
}


/******************************************************************************
*
*
*******************************************************************************/
status_t
CamAdapter::
onHandleCancelVideoSnapshot()
{
    //TBD
    return  OK;
}


/******************************************************************************
*
*******************************************************************************/
bool
CamAdapter::
onCaptureThreadLoop()
{
    bool ret = false;
    MUINT32 transform = 0;
    ResMgrDrv::MODE_STRUCT mode;
    //
    if(mpResMgrDrv)
    {
        mpResMgrDrv->getMode(&mode);
    }
    //
    //  [1] transit to "Capture" state.
    if(mpStateManager->isState(IState::eState_Idle))
    {
        mpStateManager->transitState(IState::eState_Capture);
        if(mShotMode == eShotMode_ContinuousShot)
        {
            mode.scenSw = ResMgrDrv::SCEN_SW_CAM_CSHOT;
        }
        else
        {
            mode.scenSw = ResMgrDrv::SCEN_SW_CAM_CAP;
        }
    }
    else
    if(mpStateManager->isState(IState::eState_Preview))
    {
        mpStateManager->transitState(IState::eState_PreviewCapture);
        if(mShotMode == eShotMode_ContinuousShotCc)
        {
            mode.scenSw = ResMgrDrv::SCEN_SW_CAM_CSHOT;
        }
        else
        {
            mode.scenSw = ResMgrDrv::SCEN_SW_ZSD;
        }
    }
    else
    if(mpStateManager->isState(IState::eState_Recording))
    {
        mpStateManager->transitState(IState::eState_VideoSnapshot);
        mode.scenSw = ResMgrDrv::SCEN_SW_VIDEO_VSS;
    }
    //
    if(mpResMgrDrv)
    {
        mpResMgrDrv->setMode(&mode);
    }
    //
    if( mpStateManager->isState(IState::eState_VideoSnapshot) &&
        (   mpDefaultCtrlNode->isRecBufSnapshot() ||
            mbLowPowerVideoRecord == MTRUE))
    {
        if(mpRecBufSnapshotlNode != NULL)
        {
            mpRecBufSnapshotlNode->takePicture(
                                        mpParamsMgr->getInt(CameraParameters::KEY_JPEG_THUMBNAIL_WIDTH),
                                        mpParamsMgr->getInt(CameraParameters::KEY_JPEG_THUMBNAIL_HEIGHT),
                                        mpParamsMgr->getInt(CameraParameters::KEY_ROTATION),
                                        mpParamsMgr->getInt(CameraParameters::KEY_JPEG_QUALITY),
                                        mpParamsMgr->getInt(CameraParameters::KEY_JPEG_THUMBNAIL_QUALITY),
                                        this);
        }
    }
    else
    {
        //
        //  [2.1] update mpShot instance.
        ret = updateShotInstance();
        sp<IShot> pShot = mpShot;
        //
        //  [2.2] return if no shot instance.
        if  ( ! ret || pShot == 0 )
        {
            #warning "[TODO] perform a dummy compressed-image callback or CAMERA_MSG_ERROR to inform app of end of capture?"
            MY_LOGE("updateShotInstance(%d), pShot.get(%p)", ret, pShot.get());
            goto lbExit;
        }
        else
        {
            //  [3.1] prepare parameters
            sp<IParamsManager> pParamsMgr = getParamsManager();
            //
            int iPictureWidth = 0, iPictureHeight = 0;
            if(mpStateManager->isState(IState::eState_VideoSnapshot))
            {
                mpDefaultCtrlNode->getVideoSnapshotSize(iPictureWidth, iPictureHeight);
            }
            else
            {
                pParamsMgr->getPictureSize(&iPictureWidth, &iPictureHeight);
            }
            //
            int iPreviewWidth = 0, iPreviewHeight = 0;
            pParamsMgr->getPreviewSize(&iPreviewWidth, &iPreviewHeight);
            String8 s8DisplayFormat = mpImgBufProvidersMgr->queryFormat(IImgBufProvider::eID_DISPLAY);
            if  ( String8::empty() == s8DisplayFormat ) {
                MY_LOGW("Display Format is empty");
            }
            //
            bool setCapBufMgr = MFALSE;
            if(mName == MtkCameraParameters::APP_MODE_NAME_MTK_ZSD ||       //ZSD preview
                    mpStateManager->isState(IState::eState_VideoSnapshot) ) //VSS shot
            {
                setCapBufMgr = MTRUE;
            }
            // convert rotation to transform
            MINT32 rotation = pParamsMgr->getInt(CameraParameters::KEY_ROTATION);
            //
            switch(rotation)
            {
                case 0:
                    transform = 0;
                    break;
                case 90:
                    transform = eTransform_ROT_90;
                    break;
                case 180:
                    transform = eTransform_ROT_180;
                    break;
                case 270:
                    transform = eTransform_ROT_270;
                    break;
                default:
                    break;
            }

            //  [3.2] prepare parameters: ShotParam
            ShotParam shotParam;
            shotParam.miPictureFormat           = NSCam::Utils::Format::queryImageFormat(pParamsMgr->getStr(CameraParameters::KEY_PICTURE_FORMAT));
            if  ( 0 != iPictureWidth && 0 != iPictureHeight )
            {
                shotParam.mi4PictureWidth       = iPictureWidth;
                shotParam.mi4PictureHeight      = iPictureHeight;
            }
            else
            {   //  When 3rd-party apk sets "picture-size=0x0", replace it with "preview-size".
                shotParam.mi4PictureWidth       = iPreviewWidth;
                shotParam.mi4PictureHeight      = iPreviewHeight;
            }
            shotParam.miPostviewDisplayFormat   = NSCam::Utils::Format::queryImageFormat(s8DisplayFormat.string());
            shotParam.miPostviewClientFormat    = NSCam::Utils::Format::queryImageFormat(pParamsMgr->getStr(CameraParameters::KEY_PREVIEW_FORMAT));
            shotParam.mi4PostviewWidth          = iPreviewWidth;
            shotParam.mi4PostviewHeight         = iPreviewHeight;
            shotParam.ms8ShotFileName           = pParamsMgr->getStr(MtkCameraParameters::KEY_CAPTURE_PATH);
            shotParam.mu4ZoomRatio              = pParamsMgr->getZoomRatio();
            shotParam.mu4ShotCount              = pParamsMgr->getInt(MtkCameraParameters::KEY_BURST_SHOT_NUM);
            shotParam.mu4Transform              = transform;
            shotParam.mu4MultiFrameBlending     = pParamsMgr->getMultFrameBlending();
            //
            //  [3.3] prepare parameters: JpegParam
            JpegParam jpegParam;
            jpegParam.mu4JpegQuality            = pParamsMgr->getInt(CameraParameters::KEY_JPEG_QUALITY);
            jpegParam.mu4JpegThumbQuality       = pParamsMgr->getInt(CameraParameters::KEY_JPEG_THUMBNAIL_QUALITY);
            jpegParam.mi4JpegThumbWidth         = pParamsMgr->getInt(CameraParameters::KEY_JPEG_THUMBNAIL_WIDTH);
            jpegParam.mi4JpegThumbHeight        = pParamsMgr->getInt(CameraParameters::KEY_JPEG_THUMBNAIL_HEIGHT);
            jpegParam.ms8GpsLatitude            = pParamsMgr->getStr(CameraParameters::KEY_GPS_LATITUDE);
            jpegParam.ms8GpsLongitude           = pParamsMgr->getStr(CameraParameters::KEY_GPS_LONGITUDE);
            jpegParam.ms8GpsAltitude            = pParamsMgr->getStr(CameraParameters::KEY_GPS_ALTITUDE);
            jpegParam.ms8GpsTimestamp           = pParamsMgr->getStr(CameraParameters::KEY_GPS_TIMESTAMP);
            jpegParam.ms8GpsMethod              = pParamsMgr->getStr(CameraParameters::KEY_GPS_PROCESSING_METHOD);
            //
            //  [4.1] perform Shot operations.
            if(!mbTakePicPrvNotStop)
            {
                if(mShotMode == eShotMode_ContinuousShot)
                {
                    mpDefaultBufHdl->mapPort(DefaultBufHandler::eBuf_Disp, PASS2_PRV_DST_0, 10, MTRUE);
                    mpDefaultBufHdl->mapPort(DefaultBufHandler::eBuf_Disp, PASS2_CAP_DST_0, 10);
                }
                else
                {
                    mpDefaultBufHdl->mapPort(DefaultBufHandler::eBuf_Disp, PASS2_PRV_DST_0, 6*100, MTRUE);
                    mpDefaultBufHdl->mapPort(DefaultBufHandler::eBuf_Disp, PASS2_CAP_DST_0, 6*100);
                }
            }
            //check if raw16 CB is enable
            if( mEnRaw16CB == 1 )//CAMERA_CMD_ENABLE_RAW16_CALLBACK
            {
                MY_LOGD("adapter.capture: mEnRaw16CB == 1 to enableDataMsg(NSShot::EIShot_DATA_MSG_RAW)");
                pShot->enableDataMsg(NSShot::EIShot_DATA_MSG_RAW);
            }
            //
            if( mShotMode == eShotMode_ZsdShot )
            {
                MUINT32 width = 0, height = 0;
                if( shotParam.mu4Transform & eTransform_ROT_90 ) // 90(=4), 270(=7)
                {
                    width    = shotParam.mi4PictureHeight;
                    height   = shotParam.mi4PictureWidth;
                }
                else
                {
                    width    = shotParam.mi4PictureWidth;
                    height   = shotParam.mi4PictureHeight;
                }
                allocateReuseZsdP2outBuf(width, height);
            }
            else
            {
                freeReuseZsdP2outBuf();
            }

            ret =
                    pShot->sendCommand(eCmd_reset)
                &&  pShot->setCallback(this)
                &&  pShot->sendCommand(eCmd_setShotParam, (MUINTPTR)&shotParam, sizeof(ShotParam))
                &&  pShot->sendCommand(eCmd_setJpegParam, (MUINTPTR)&jpegParam, sizeof(JpegParam))
                &&  pShot->sendCommand(eCmd_setPrvBufHdl, (MUINTPTR)mpDefaultBufHdl, sizeof(DefaultBufHandler))
                &&  ( (mShotMode == eShotMode_ZsdShot) ?
                        pShot->sendCommand(eCmd_setP2outBuf, (MUINTPTR)reuseZsdP2outBuf) :
                        MTRUE )
                &&  ( setCapBufMgr ?
                        pShot->sendCommand(eCmd_setCapBufMgr, (MUINTPTR)mpCapBufMgr, sizeof(CapBufMgr)) :
                        MTRUE )
                &&  pShot->sendCommand(eCmd_capture)
                    ;
            if  ( ! ret )
            {
                MY_LOGE("fail to perform shot operations");
            }
            //
            if(!mbTakePicPrvNotStop)
            {
                mpDefaultBufHdl->unmapPort(DefaultBufHandler::eBuf_Disp);
            }
        }
        //
        //
        lbExit:
        //
        //  [5.1] uninit shot instance.
        MY_LOGD("free shot instance: (mpShot/pShot)=(%p/%p)", mpShot.get(), pShot.get());
        mpShot = NULL;
        pShot  = NULL;
        //
        //  [5.2] notify capture done.
    }
    //
    mpStateManager->getCurrentState()->onCaptureDone(this);
    //
    //
    return  true;
}


/******************************************************************************
*
*******************************************************************************/
void
CamAdapter::
allocateReuseZsdP2outBuf(MINT32 w, MINT32 h)
{
    if( w == 0 || h == 0 )
    {
        freeReuseZsdP2outBuf();
        return;
    }

    if( reuseZsdP2outBuf != NULL )
    {
        if( w == reuseZsdP2outBuf->getImgSize().w && h == reuseZsdP2outBuf->getImgSize().h )
        {
            return;
        }
        else
        {
            freeReuseZsdP2outBuf();//reallocate
        }
    }

    IImageBufferAllocator* allocator = IImageBufferAllocator::getInstance();
    if( allocator == NULL )
    {
        return;
    }
    MUINT32 fmt = eImgFmt_YUY2;
    MINT32 bufBoundaryInBytes[] = {0,0,0};
    MUINT32 planeCount = 0, bufStridesInBytes[] = {0,0,0};

    planeCount = NSCam::Utils::Format::queryPlaneCount(fmt);
    for (MUINT32 i = 0; i < planeCount; i++)
    {
        bufStridesInBytes[i] = NSCam::Utils::Format::queryPlaneWidthInPixels(fmt, i, w) * NSCam::Utils::Format::queryPlaneBitsPerPixel(fmt, i) / 8;
    }

    IImageBufferAllocator::ImgParam imgParam(
                                        fmt,
                                        MSize(w,h),
                                        bufStridesInBytes,
                                        bufBoundaryInBytes,
                                        planeCount);
    reuseZsdP2outBuf = allocator->alloc(LOG_TAG, imgParam);
    allocator = NULL;
    if ( reuseZsdP2outBuf == NULL )
    {
        return;//fail
    }
    if ( !reuseZsdP2outBuf->lockBuf( LOG_TAG, eBUFFER_USAGE_SW_MASK | eBUFFER_USAGE_HW_MASK ) )
    {
        return;//fail
    }
    if ( !reuseZsdP2outBuf->syncCache(eCACHECTRL_INVALID) )
    {
        return;//fail
    }
    MY_LOGD("buffer allocated");
    return;
}


/******************************************************************************
*
*******************************************************************************/
void
CamAdapter::
freeReuseZsdP2outBuf()
{
    if( reuseZsdP2outBuf )
    {
        IImageBufferAllocator* allocator = IImageBufferAllocator::getInstance();
        reuseZsdP2outBuf->unlockBuf( LOG_TAG );
        if( allocator )
        {
            allocator->free( reuseZsdP2outBuf );
            MY_LOGD("free buffer done");
        }
        else
        {
            MY_LOGW("get IImageBufferAllocator instance fail");
        }
        allocator = NULL;
        reuseZsdP2outBuf = NULL;
    }
    return;
}


