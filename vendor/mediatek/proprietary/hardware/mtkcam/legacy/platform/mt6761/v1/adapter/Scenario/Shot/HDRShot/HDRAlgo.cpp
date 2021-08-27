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
#include "MyHdr.h"




#define MHAL_CAM_THUMB_ADDR_OFFSET  (64 * 1024)

#define DEALLOCMEM(imem)        do {deallocBuffer(imem); imem=NULL;} while(0)

//systrace
#if 1
#ifndef ATRACE_TAG
#define ATRACE_TAG                           ATRACE_TAG_CAMERA
#endif
#include <utils/Trace.h>

#define HDR_TRACE_CALL()                      ATRACE_CALL()
#define HDR_TRACE_NAME(name)                  ATRACE_NAME(name)
#define HDR_TRACE_BEGIN(name)                 ATRACE_BEGIN(name)
#define HDR_TRACE_END()                       ATRACE_END()
#else
#define HDR_TRACE_CALL()
#define HDR_TRACE_NAME(name)
#define HDR_TRACE_BEGIN(name)
#define HDR_TRACE_END()
#endif


using namespace android;
using namespace NSShot;
using namespace android::NSShot;
using namespace NSCam;
using namespace NS3A;
using namespace NSCamShot;

//#undef HDR_DEBUG_OUTPUT_FOLDER
//#define HDR_DEBUG_OUTPUT_FOLDER       "/storage/sdcard0/DCIM/Camera"


///////////////////////////////////////////////////////////////////////////
/// @brief Do small image normalization.
///
/// @return SUCCDSS (TRUE) or Fail (FALSE).
///////////////////////////////////////////////////////////////////////////
MBOOL
HdrShot::do_Normalization(unsigned int method)
{
    HDR_TRACE_CALL();

    MBOOL  ret = MTRUE;
    MUINT32 u4OutputFrameNum = OutputFrameNumGet();

    HDR_PIPE_CONFIG_PARAM rHdrPipeConfigParam;
    rHdrPipeConfigParam.eHdrRound = 1;

    rHdrPipeConfigParam.u4SourceImgWidth = mu4W_yuv;
    rHdrPipeConfigParam.u4SourceImgHeight = mu4H_yuv;
    for (MUINT32 i = 0; i < u4OutputFrameNum; i++)
    {
        rHdrPipeConfigParam.pSourceImgBufAddr[i] = (MUINT8 *)mpSourceImgBuf[i]->getBufVA(0);
        rHdrPipeConfigParam.pSmallImgBufAddr[i] = (MUINT8 *)mpSmallImgBuf[i]->getBufVA(0);
    }
    CAM_LOGD("[do_Normalization] method =%d", method);
    rHdrPipeConfigParam.manual_PreProcType = (method?1:0); // 1: rank image, 0: normalization

    ret = ret
        &&  mpHdrHal->HdrSmallImgBufSet(rHdrPipeConfigParam)
        &&  mpHdrHal->Do_Normalization()
            ;

    // Save normalized small image for debug.
    if(HDR_DEBUG_SAVE_NORMALIZED_SMALL_IMAGE || mDebugMode) {
        for (MUINT32 i = 0; i < u4OutputFrameNum; i++)
        {
            char szFileName[100];
            if(method) {
                ::sprintf(szFileName, HDR_DEBUG_OUTPUT_FOLDER "%04d_3_normalized_rank_mpSmallImgBuf[%d]_%dx%d.y", mu4RunningNumber, i, mu4W_small, mu4H_small);
            } else {
                ::sprintf(szFileName, HDR_DEBUG_OUTPUT_FOLDER "%04d_3_normalized_notrank_mpSmallImgBuf[%d]_%dx%d.y", mu4RunningNumber, i, mu4W_small, mu4H_small);
            }
            mpSmallImgBuf[i]->saveToFile(szFileName);
        }
    }

    return  ret;
}


///////////////////////////////////////////////////////////////////////////
/// @brief Do SE to get GMV.
///
/// @return SUCCDSS (TRUE) or Fail (FALSE).
///////////////////////////////////////////////////////////////////////////
MBOOL
HdrShot::do_SE(void)
{
    HDR_TRACE_CALL();

    MBOOL  ret = MTRUE;
    MUINT32 u4OutputFrameNum = OutputFrameNumGet();

    // Prepare SE Input Info.
    HDR_PIPE_SE_INPUT_INFO rHdrPipeSEInputInfo;
    rHdrPipeSEInputInfo.u2SEImgWidth    = mu4W_se;
    rHdrPipeSEInputInfo.u2SEImgHeight = mu4H_se;
    for (MUINT32 i = 0; i < u4OutputFrameNum; i++)
    {
        rHdrPipeSEInputInfo.pSEImgBufAddr[i] = (MUINT8 *)mpSEImgBuf[i]->getBufVA(0);
    }

    // Do SE.
    ret = mpHdrHal->Do_SE(rHdrPipeSEInputInfo);

    return  ret;
}


///////////////////////////////////////////////////////////////////////////
/// @brief Do Feature Extraction.
///
/// @return SUCCDSS (TRUE) or Fail (FALSE).
///////////////////////////////////////////////////////////////////////////
MBOOL
HdrShot::do_FeatureExtraction(void)
{
    HDR_TRACE_CALL();

    MBOOL  ret = MTRUE;
    MUINT32 u4OutputFrameNum = OutputFrameNumGet();

    //     Config MAV hal init Info.
    HDR_PIPE_FEATURE_EXTRACT_INPUT_INFO rHdrPipeFeatureExtractInputInfo;
    rHdrPipeFeatureExtractInputInfo.u2SmallImgW = mu4W_small;
    rHdrPipeFeatureExtractInputInfo.u2SmallImgH = mu4H_small;
    for (MUINT32 i = 0; i < u4OutputFrameNum; i++)
    {
        rHdrPipeFeatureExtractInputInfo.pSmallImgBufAddr[i] = (MUINT8 *)mpSmallImgBuf[i]->getBufVA(0);
    }
    //     Assign working buffer
    rHdrPipeFeatureExtractInputInfo.pWorkingBuffer = (MUINT8 *)mpHdrWorkingBuf->getBufVA(0);

    //     Do Feature Extraction and Feature Matching.
    ret = mpHdrHal->Do_FeatureExtraction(rHdrPipeFeatureExtractInputInfo);
    CAM_LOGD("[do_FeatureExtraction] ret =%d", ret);

    // NOTE: due to MAV cannot be used by multiple users
    // use this lock to guarantee the MAV lifecycle
    mMAVLock.unlock();

    return  ret;
}


///////////////////////////////////////////////////////////////////////////
/// @brief Do Alignment.
///
/// @return SUCCDSS (TRUE) or Fail (FALSE).
///////////////////////////////////////////////////////////////////////////
MBOOL
HdrShot::do_Alignment(void)
{
    HDR_TRACE_CALL();

    MBOOL  ret = MTRUE;
    MUINT32 u4OutputFrameNum = OutputFrameNumGet();

    ret = ret
        && mpHdrHal->HdrWorkingBufSet((MUINT8*)mpHdrWorkingBuf->getBufVA(0)
                                    , mpHdrWorkingBuf->getBufSizeInBytes(0)
                                    )
        &&  do_SetBmapBuffer()
        &&  mpHdrHal->Do_Alignment()
        ;

    return  ret;
}


MBOOL
HdrShot::do_SetBmapBuffer(void)
{
    HDR_TRACE_CALL();

    MBOOL  ret = MTRUE;

    // Set the resulting Weighting Map.
    CAM_LOGD("[do_SetBmapBuffer] bmap_width=%d", mHdrSetBmapInfo.bmap_width);
    CAM_LOGD("[do_SetBmapBuffer] bmap_height=%d", mHdrSetBmapInfo.bmap_height);
    CAM_LOGD("[do_SetBmapBuffer] bmap_image_size=%d", mHdrSetBmapInfo.bmap_image_size);
    for(MUINT32 i=0; i<OutputFrameNumGet(); i++) {
        CAM_LOGD("[do_SetBmapBuffer] bmap_image_addr[%d]=%p"
                , i
                , mHdrSetBmapInfo.bmap_image_addr[i]);
    }
    ret = mpHdrHal->WeightingMapInfoSet(&mHdrSetBmapInfo);

    return ret;
}


///////////////////////////////////////////////////////////////////////////
/// @brief Get original Weighting Table.
///
/// @return SUCCDSS (TRUE) or Fail (FALSE).
///////////////////////////////////////////////////////////////////////////
MBOOL
HdrShot::do_OriWeightMapGet(void)
{
    HDR_TRACE_CALL();

    MBOOL  ret = MTRUE;
    MUINT32 u4OutputFrameNum = OutputFrameNumGet();

    // Get the resulting Weighting Map.
    mpHdrHal->WeightingMapInfoGet(OriWeight);
    // Show obtained OriWeightingTbl info.

    for (MUINT32 i = 0; i < u4OutputFrameNum; i++) {
        CAM_LOGD("[do_OriWeightMapGet] OriWeight[%d]->W/H: (%d, %d). Addr: %p."
                , i
                , OriWeight[i]->weight_table_width
                , OriWeight[i]->weight_table_height
                , OriWeight[i]->weight_table_data
                );
        if(OriWeight[i]->weight_table_data != mHdrSetBmapInfo.bmap_image_addr[i]) {
            CAM_LOGE("OriWeight[%d]->weight_table_data=%p, it should be %p, error!!"
                    , i
                    , OriWeight[i]->weight_table_data
                    , mHdrSetBmapInfo.bmap_image_addr[i]);
        }
    }

    if(HDR_DEBUG_SAVE_WEIGHTING_MAP || mDebugMode) {
        for (MUINT32 i = 0; i < u4OutputFrameNum; i++)
        {
            char szFileName[100];
            ::sprintf(szFileName, HDR_DEBUG_OUTPUT_FOLDER "%04d_5_WeightMap%d_%dx%d.y", mu4RunningNumber, i, OriWeight[i]->weight_table_width, OriWeight[i]->weight_table_height);
            dumpToFile(szFileName, OriWeight[i]->weight_table_data, OriWeight[i]->weight_table_width * OriWeight[i]->weight_table_height);
        }
    }

    return  ret;
}


///////////////////////////////////////////////////////////////////////////
/// @brief Do Down-scale Weighting Map.
///
/// @return SUCCDSS (TRUE) or Fail (FALSE).
///////////////////////////////////////////////////////////////////////////
MBOOL
HdrShot::do_DownScaleWeightMap(void)
{
    HDR_TRACE_CALL();

    MBOOL  ret = MTRUE;
    MUINT32 u4OutputFrameNum = OutputFrameNumGet();

    for (MUINT32 i = 0; i < u4OutputFrameNum; i++)
    {
        CPTLog(Event_HdrShot_DownSize, CPTFlagStart);

        IImageBuffer *pImageWeighting = makeBufferAlias(mWeightingBuf[i]
                                                , OriWeight[i]->weight_table_width
                                                , OriWeight[i]->weight_table_height
                                                , eImgFmt_Y800
                                                );

        ret = CDPResize(pImageWeighting
                        , mpDownSizedWeightMapBuf[i]
                        , 0
                        );

        removeBufferAlias(mWeightingBuf[i], pImageWeighting);

        CPTLog(Event_HdrShot_DownSize, CPTFlagEnd);
    }

    if(HDR_DEBUG_SAVE_DOWNSCALED_WEIGHTING_MAP || mDebugMode) {
        for (MUINT32 i = 0; i < u4OutputFrameNum; i++)
        {
            char szFileName[100];
            ::sprintf(szFileName, HDR_DEBUG_OUTPUT_FOLDER "%04d_6_mpDownSizedWeightMapBuf[%d]_%dx%d.y", mu4RunningNumber, i, mu4W_dsmap, mu4H_dsmap);
            mpDownSizedWeightMapBuf[i]->saveToFile(szFileName);
        }
    }

    return  ret;
}


///////////////////////////////////////////////////////////////////////////
/// @brief Do Up-scale Weighting Map.
///
/// @return SUCCDSS (TRUE) or Fail (FALSE).
///////////////////////////////////////////////////////////////////////////
MBOOL
HdrShot::do_UpScaleWeightMap(void)
{
    HDR_TRACE_CALL();

    MBOOL  ret = MTRUE;

    MUINT32 u4OutputFrameNum = OutputFrameNumGet();

    // Up-sample Down-sized Weighting Map to make them blurry. And Save them for debug.
    for (MUINT32 i = 0; i < u4OutputFrameNum; i++)
    {
        CPTLog(Event_HdrShot_UpSize, CPTFlagStart);
        ret = CDPResize(mpDownSizedWeightMapBuf[i]
                        , mpBlurredWeightMapBuf[i]
                        , 0
                        );
        CPTLog(Event_HdrShot_UpSize, CPTFlagEnd);
    }

    // Show info.
    for (MUINT32 i = 0; i < u4OutputFrameNum; i++)
        CAM_LOGV("[do_UpScaleWeightMap] BlurredWeight[%d]->W/H: (%d, %d). Addr: %p."
                , i
                , BlurredWeight[i]->weight_table_width
                , BlurredWeight[i]->weight_table_height
                , BlurredWeight[i]->weight_table_data
                );

    if(HDR_DEBUG_SAVE_BLURRED_WEIGHTING_MAP || mDebugMode) {
        for (MUINT32 i = 0; i < u4OutputFrameNum; i++)
        {
            char szFileName[100];
            ::sprintf(szFileName, HDR_DEBUG_OUTPUT_FOLDER "%04d_7_blurred_WeightMap%d_%dx%d.y", mu4RunningNumber, i, BlurredWeight[i]->weight_table_width, BlurredWeight[i]->weight_table_height);
            dumpToFile(szFileName, BlurredWeight[i]->weight_table_data, BlurredWeight[i]->weight_table_width * BlurredWeight[i]->weight_table_height);
        }
    }

    return  ret;
}


///////////////////////////////////////////////////////////////////////////
/// @brief Do Fusion.
///
/// @return SUCCDSS (TRUE) or Fail (FALSE).
///////////////////////////////////////////////////////////////////////////
MBOOL
HdrShot::do_Fusion(void)
{
    HDR_TRACE_CALL();

    MBOOL  ret = MTRUE;
    MUINT32 u4OutputFrameNum = OutputFrameNumGet();

    //[ION]
    ret = ret && mpHdrHal->ResultBufferSet((MUINT8 *)mBlendingBuf->getBufVA(0)
                                            , mBlendingBuf->getBufSizeInBytes(0)
                                            );

    // Do Fusion.
    ret = ret && mpHdrHal->Do_Fusion(BlurredWeight);

    return  ret;
}


///////////////////////////////////////////////////////////////////////////
/// @brief Do .
///
/// @return SUCCDSS (TRUE) or Fail (FALSE).
///////////////////////////////////////////////////////////////////////////
MBOOL
HdrShot::do_HdrCroppedResultGet(void)
{
    HDR_TRACE_CALL();

    MBOOL  ret = MTRUE;

    // Get HDR result.
    ret = mpHdrHal->HdrCroppedResultGet(mrHdrCroppedResult);
    MUINT32 u4HdrCroppedResultSize = mrHdrCroppedResult.output_image_width
                                        * mrHdrCroppedResult.output_image_height
                                        * 3 / 2
                                        ;

    CAM_LOGD("[do_HdrCroppedResultGet] rCroppedHdrResult:: W/H: (%d, %d). Addr: %p. Size: %d."
            , mrHdrCroppedResult.output_image_width
            , mrHdrCroppedResult.output_image_height
            , mrHdrCroppedResult.output_image_addr
            , u4HdrCroppedResultSize);  // *3/2: YUV420 size.

    if(HDR_DEBUG_SAVE_HDR_RESULT || mDebugMode)
    {
        char szFileName[100];
        ::sprintf(szFileName, HDR_DEBUG_OUTPUT_FOLDER "%04d_8_HdrResult_%dx%d.i420", mu4RunningNumber, mrHdrCroppedResult.output_image_width, mrHdrCroppedResult.output_image_height);
        dumpToFile(szFileName, mrHdrCroppedResult.output_image_addr, u4HdrCroppedResultSize);
    }

    return  ret;
}


///////////////////////////////////////////////////////////////////////////
/// @brief Do .
///
/// @return SUCCDSS (TRUE) or Fail (FALSE).
///////////////////////////////////////////////////////////////////////////
MBOOL
HdrShot::do_CroppedPostviewResize(void)
{
    HDR_TRACE_CALL();

    MBOOL  ret = MTRUE;

    // Resize to original image size and convert to YUV22.
    if(mTestMode) {
        mPostviewWidth = 800;
        mPostviewHeight = 600;
        mPostviewFormat = eImgFmt_YV12;
    }

    IImageBuffer *pImageCropped = makeBufferAlias(mpHdrWorkingBuf
                                                    , mRotPicWidth
                                                    , mRotPicHeight
                                                    , eImgFmt_YUY2
                                                    );
    if(!pImageCropped) {
        CAM_LOGE("pImageHdr error!!");
        ret = MFALSE;
        goto lbExit;
    }

    ret = CDPResize(pImageCropped
                    , mpPostviewImgBuf
                    , 0);

    removeBufferAlias(mpHdrWorkingBuf, pImageCropped);


    if(CUST_HDR_DEBUG || HDR_DEBUG_SAVE_POSTVIEW || mDebugMode)
    {
        char szFileName[100];
        ::sprintf(szFileName, HDR_DEBUG_OUTPUT_FOLDER "%04d_9_final_HdrPostview_%dx%d.yv12", mu4RunningNumber, mPostviewWidth, mPostviewHeight);
        mpPostviewImgBuf->saveToFile(szFileName);
    }

lbExit:
    return  ret;
}


///////////////////////////////////////////////////////////////////////////
/// @brief Do HDR noise reduction.
///
/// @return SUCCDSS (TRUE) or Fail (FALSE).
///////////////////////////////////////////////////////////////////////////
MBOOL
HdrShot::do_HdrNR(void)
{
    HDR_TRACE_CALL();

    MBOOL ret = MTRUE;

    IImageBuffer *pImageCropped;
    IImageBuffer *pImageHdrNr;
    pImageCropped = makeBufferAlias(mBlendingBuf
                                , mrHdrCroppedResult.output_image_width
                                , mrHdrCroppedResult.output_image_height
                                , eImgFmt_I420
                                );
    CHECK_OBJECT(pImageCropped);

    if(HDR_DEBUG_SAVE_HDR_NR || mDebugMode)
    {
        char szFileName[100];
        ::sprintf(szFileName, HDR_DEBUG_OUTPUT_FOLDER "%04d_8_NR_HdrCroppedBuf_%dx%d.i420", mu4RunningNumber, mrHdrCroppedResult.output_image_width, mrHdrCroppedResult.output_image_height);
        pImageCropped->saveToFile(szFileName);
    }


    pImageHdrNr = makeBufferAlias(mpHdrWorkingBuf
                            , mRotPicWidth
                            , mRotPicHeight
                            , eImgFmt_YUY2
                            );
    CHECK_OBJECT(pImageHdrNr);



    // crop for jpeg
    MRect srcRect(MPoint(0, 0), MSize(mrHdrCroppedResult.output_image_width, mrHdrCroppedResult.output_image_height));
    MRect dstRect(MPoint(0, 0), MSize(mShotParam.mi4PictureWidth, mShotParam.mi4PictureHeight));

    //calculate crop
    {

        MFLOAT fSrcRatio = srcRect.s.w / (MFLOAT)(srcRect.s.h);
        MFLOAT fDesRatio = dstRect.s.w / (MFLOAT)(dstRect.s.h);

        if( fSrcRatio > fDesRatio)
        {
            dstRect.s.h = srcRect.s.h;
            dstRect.s.w = dstRect.s.h * fDesRatio;

        }
        else
        {
            dstRect.s.w = srcRect.s.w;
            dstRect.s.h = dstRect.s.w / fDesRatio;
        }

    }
    MRect cropRect;
    if(mHDRShotMode == eShotMode_ZsdHdrShot){
        cropRect = calCrop(srcRect, dstRect, mShotParam.mu4ZoomRatio);
        CAM_LOGD("zoom(%d)", mShotParam.mu4ZoomRatio);
    } else {
        // Already apply ZoomRatio in source image, don't need to crop with zoom ratio here.
        cropRect = calCrop(srcRect, dstRect, 100);
        CAM_LOGD("zoom(%d)", 100);
    }

    CAM_LOGD("srcRect xywh(%d,%d,%d,%d)", srcRect.p.x, srcRect.p.y, srcRect.s.w, srcRect.s.h);
    CAM_LOGD("dstRect xywh(%d,%d,%d,%d)", dstRect.p.x, dstRect.p.y, dstRect.s.w, dstRect.s.h);
    CAM_LOGD("cropRect xywh(%d,%d,%d,%d)", cropRect.p.x, cropRect.p.y, cropRect.s.w, cropRect.s.h);

    CAM_LOGD("mNrtype(%d)", mNrtype);
    switch(mNrtype)
    {
        case ECamShot_NRTYPE_NONE:
            {
                 //  resize yuv buffer
                ret = ret && convertImage(pImageCropped
                            , pImageHdrNr
                            , mShotParam.mu4Transform
                            , MTRUE
                            , cropRect
                            );
                CHECK_RET("convertImage fail, error!!");

                if( HDR_DEBUG_SAVE_HDR_NR || mDebugMode )
                {
                    char szFileName[100];
                    ::sprintf(szFileName, HDR_DEBUG_OUTPUT_FOLDER "%04d_8_NR_HdrNoNrBlendingBuf_%dx%d.yuy2", mu4RunningNumber, pImageHdrNr->getImgSize().w, pImageHdrNr->getImgSize().h);
                    pImageHdrNr->saveToFile(szFileName);
                }

            }
            break;
        case ECamShot_NRTYPE_HWNR:
            {


                IImageBuffer *pImageHwNrWorkingBuf;

                ret = ret && allocBuffer(&pImageHwNrWorkingBuf, mrHdrCroppedResult.output_image_width, mrHdrCroppedResult.output_image_height, eImgFmt_YUY2);

                CHECK_RET("allocate pImageHwNrWorkingBuf fail, error!!");

                ret = ret && convertImage(pImageCropped, pImageHwNrWorkingBuf);

                CHECK_RET("convertImage fail, error!!");

                if( HDR_DEBUG_SAVE_HDR_NR || mDebugMode )
                {
                    char szFileName[100];
                    ::sprintf(szFileName, HDR_DEBUG_OUTPUT_FOLDER "%04d_8_NR_HdrHwNrWorkingBuf1_%dx%d.yuy2", mu4RunningNumber, mrHdrCroppedResult.output_image_width, mrHdrCroppedResult.output_image_height);
                    pImageHwNrWorkingBuf->saveToFile(szFileName);
                }

                ret = ret && doHwNR(getOpenId()
                                    , pImageHwNrWorkingBuf
                                    , pImageHdrNr
                                    , NULL
                                    , cropRect
                                    , mShotParam.mu4Transform
                                    , EIspProfile_MFB_MultiPass_ANR_1 );

                CHECK_RET("do HWNR failed, error!!");

                DEALLOCMEM(pImageHwNrWorkingBuf);

                if( HDR_DEBUG_SAVE_HDR_NR || mDebugMode )
                {
                    char szFileName[100];
                    ::sprintf(szFileName, HDR_DEBUG_OUTPUT_FOLDER "%04d_8_NR_HdrHwNrBlendingBuf_%dx%d.yuy2", mu4RunningNumber, pImageHdrNr->getImgSize().w, pImageHdrNr->getImgSize().h);
                    pImageHdrNr->saveToFile(szFileName);
                }
             }
            break;

        case ECamShot_NRTYPE_SWNR:
            {


                SwNR *swnr = new SwNR(getOpenId());
                ret = ret && swnr->doSwNR(pImageCropped);
                delete swnr;
                CHECK_RET("do swnr fail, error!!");

                ret = ret && pImageCropped->syncCache(eCACHECTRL_FLUSH);    //cpu->hw
                CHECK_RET("flush cache cpu->hw fail, error!!");

                if( HDR_DEBUG_SAVE_HDR_NR || mDebugMode )
                {
                    char szFileName[100];
                    ::sprintf(szFileName, HDR_DEBUG_OUTPUT_FOLDER "%04d_8_NR_HdrSwNrBlendingBuf_%dx%d.i420", mu4RunningNumber, pImageCropped->getImgSize().w, pImageCropped->getImgSize().h);
                    pImageCropped->saveToFile(szFileName);
                }

                ret = ret && convertImage( pImageCropped
                                           , pImageHdrNr
                                           , mShotParam.mu4Transform
                                           , MTRUE
                                           , cropRect
                                           );
                CHECK_RET("convertImage fail, error!!");


                if( HDR_DEBUG_SAVE_HDR_NR || mDebugMode )
                {
                    char szFileName[100];
                    ::sprintf(szFileName, HDR_DEBUG_OUTPUT_FOLDER "%04d_8_NR_HdrSwNrForJpegBuf_%dx%d.yuy2", mu4RunningNumber, pImageHdrNr->getImgSize().w, pImageHdrNr->getImgSize().h);
                    pImageHdrNr->saveToFile(szFileName);
                }
            }
            break;

        default:
             CAM_LOGD("Wrong Nr Type %d", mNrtype);
             ret = MFALSE;

    }


lbExit:

    if(pImageCropped != NULL)
    {
        ret = ret && removeBufferAlias(mBlendingBuf, pImageCropped);

    }
    if(pImageHdrNr != NULL)
    {
        ret = ret && removeBufferAlias(mpHdrWorkingBuf, pImageHdrNr);
    }

    return ret;
}
