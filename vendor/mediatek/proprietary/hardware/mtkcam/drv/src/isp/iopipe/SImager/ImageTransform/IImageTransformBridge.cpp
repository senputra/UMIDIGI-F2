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
#define LOG_TAG "MtkCam/ImageTranform"
//
#include <mtkcam/utils/std/ULog.h>
#include "MyUtils.h"
#include <utils/threads.h>
//
CAM_ULOG_DECLARE_MODULE_ID(MOD_SIMAGER);
#define MY_LOGV(fmt, arg...)    CAM_ULOGMV("(%d)[%s] " fmt, ::gettid(), __FUNCTION__, ##arg)
#define MY_LOGD(fmt, arg...)    CAM_ULOGMD("(%d)[%s] " fmt, ::gettid(), __FUNCTION__, ##arg)
#define MY_LOGI(fmt, arg...)    CAM_ULOGMI("(%d)[%s] " fmt, ::gettid(), __FUNCTION__, ##arg)
#define MY_LOGW(fmt, arg...)    CAM_ULOGMW("(%d)[%s] " fmt, ::gettid(), __FUNCTION__, ##arg)
#define MY_LOGE(fmt, arg...)    CAM_ULOGME("(%d)[%s] " fmt, ::gettid(), __FUNCTION__, ##arg)

//
#include <mtkcam/drv/iopipe/SImager/IImageTransform.h>
#include "./inc/ImageTransform.h"
//
using namespace android;
using namespace NSCam::NSIoPipe::NSSImager;


/*******************************************************************************
*
********************************************************************************/


/*******************************************************************************
*
********************************************************************************/
class IImageTransformBridge : public IImageTransform
{
    friend  class   IImageTransform;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Implementation.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
protected:  ////
    mutable android::Mutex      mLock;
    android::Mutex&             getLockRef()    { return mLock; }
    MUINT32                     mu4InitRefCount;

protected:  ////    Implementor.
    ImageTransform*            mpImageTransformImp;
    inline  ImageTransform const*   getImp() const  { return mpImageTransformImp; }
    inline  ImageTransform*         getImp()        { return mpImageTransformImp; }

protected:  ////    Constructor/Destructor.
                    IImageTransformBridge(ImageTransform*const pImageTransform);
                    ~IImageTransformBridge();

private:    ////    Disallowed.
                    IImageTransformBridge(IImageTransformBridge const& obj);
    IImageTransformBridge&  operator=(IImageTransformBridge const& obj);
    MBOOL check10BitsFmt(MINT iFormat);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Interfaces.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public:     ////    Instantiation.
    virtual MVOID   destroyInstance();

public:     ////    Attributes.
    virtual MINT32      getLastErrorCode() const;


   //
public:     ////    Operations.
    virtual  MBOOL    execute(
                          IImageBuffer const *pSrcBuf,
                          IImageBuffer const * pDstBuf_0,
                          IImageBuffer const * pDstBuf_1,
                          MRect const rROI,
                          MUINT32 const u4Transform_0,
                          MUINT32 const u4TimeOutInMs,
                          struct timeval *endTime,
                          MBOOL const bNeedDump
                      );
    virtual  MBOOL    execute(
                          IImageBuffer const *pSrcBuf,
                          IImageBuffer const * pDstBuf_0,
                          IImageBuffer const * pDstBuf_1,
                          MRect const rROI_0,
                          MRect const rROI_1,
                          MUINT32 const u4Transform_0,
                          MUINT32 const u4Transform_1,
                          MUINT32 const u4TimeOutInMs,
                          struct timeval *endTime,
                          MBOOL const bNeedDump
                      );

    virtual MBOOL     setPQParameter(const PQParam& p __attribute__((unused)));

    virtual const map<int,PQParam>&  getPQParameter() const;

    virtual MBOOL     setSensorIndex(MINT32 iSensorIdx);

    virtual MVOID     setDumpInfo(const DumpInfos& info);
};


/*******************************************************************************
*
********************************************************************************/
IImageTransform*
IImageTransform::
createInstance(const char* sUserName, MINT32 sensorIndex)
{
    ImageTransform* pImageTransformImp = new ImageTransform(sUserName, sensorIndex);
    if  ( ! pImageTransformImp )
    {
        MY_LOGE("[IImageTransform] fail to new ImageTransform");
        return  NULL;
    }
    //
    IImageTransformBridge*  pIImageTransform = new IImageTransformBridge(pImageTransformImp);
    if  ( ! pIImageTransform )
    {
        MY_LOGE("[IImageTransform] fail to new IImageTransformBridge");
        delete  pImageTransformImp;
        return  NULL;
    }
    //
    return  pIImageTransform;
    return NULL;
}


/*******************************************************************************
*
********************************************************************************/
MVOID
IImageTransformBridge::
destroyInstance()
{
    delete  mpImageTransformImp;  //  Firstly, delete the implementor here instead of destructor.
    mpImageTransformImp = NULL;
    delete  this;       //  Finally, delete myself.
}


/*******************************************************************************
*
********************************************************************************/
IImageTransformBridge::
IImageTransformBridge(ImageTransform*const pImageTransform)
    : IImageTransform()
    , mLock()
    , mu4InitRefCount(0)
    , mpImageTransformImp(pImageTransform)
{
}


/*******************************************************************************
*
********************************************************************************/
IImageTransformBridge::
~IImageTransformBridge()
{
}

/*******************************************************************************
*
********************************************************************************/
MINT32
IImageTransformBridge::
getLastErrorCode() const
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->getLastErrorCode();
}


/*******************************************************************************
*
********************************************************************************/
MBOOL
IImageTransformBridge::
execute(
        IImageBuffer const *pSrcBuf,
        IImageBuffer const * pDstBuf_0,
        IImageBuffer const * pDstBuf_1,
        MRect const rROI,
        MUINT32 const u4Transform_0,
        MUINT32 const u4TimeOutInMs,
        struct timeval *endTime,
        MBOOL const bNeedDump
       )
{
    Mutex::Autolock _lock(mLock);
    MINT srcFormat = pSrcBuf ? pSrcBuf->getImgFormat() : eImgFmt_UNKNOWN;
    MBOOL bBypassISP = this->check10BitsFmt(srcFormat);
    return bBypassISP ? getImp()->executeByPassISP(pSrcBuf, pDstBuf_0, pDstBuf_1, rROI, u4Transform_0, u4TimeOutInMs, endTime) :
                        getImp()->execute(pSrcBuf, pDstBuf_0, pDstBuf_1, rROI, u4Transform_0, u4TimeOutInMs, MTRUE, endTime);
}


/*******************************************************************************
*
********************************************************************************/
MVOID
IImageTransformBridge::
setDumpInfo(const DumpInfos& info)
{
    Mutex::Autolock _lock(mLock);
    return getImp()->setDumpInfo(info);
}

/*******************************************************************************
*
********************************************************************************/
MBOOL
IImageTransformBridge::
setPQParameter(const PQParam& p __attribute__((unused)))
{
    Mutex::Autolock _lock(mLock);
    return getImp()->setPQParameter(p);
}


/*******************************************************************************
*
********************************************************************************/
MBOOL
IImageTransformBridge::
setSensorIndex(MINT32 iSensorIdx)
{
    Mutex::Autolock _lock(mLock);
    return getImp()->setSensorIndex(iSensorIdx);
}

/*******************************************************************************
*
********************************************************************************/
const map<int,IImageTransform::PQParam>&
IImageTransformBridge::
getPQParameter() const
{
    Mutex::Autolock _lock(mLock);
    return getImp()->getPQParameter();
}

/*******************************************************************************
*
********************************************************************************/

MBOOL
IImageTransformBridge::
check10BitsFmt(MINT srcFormat)
{
    return (srcFormat == eImgFmt_MTK_YUV_P210  || srcFormat == eImgFmt_MTK_YVU_P210
                    || srcFormat == eImgFmt_MTK_YUV_P210_3PLANE
                    || srcFormat == eImgFmt_MTK_YUV_P010 || srcFormat == eImgFmt_MTK_YVU_P010
                    || srcFormat == eImgFmt_MTK_YUV_P010_3PLANE);
}

/*******************************************************************************
*
********************************************************************************/
MBOOL
IImageTransformBridge::
execute(
        IImageBuffer const *pSrcBuf,
        IImageBuffer const * pDstBuf_0,
        IImageBuffer const * pDstBuf_1,
        MRect const rROI_0,
        MRect const rROI_1,
        MUINT32 const u4Transform_0,
        MUINT32 const u4Transform_1,
        MUINT32 const u4TimeOutInMs,
        struct timeval *endTime,
        MBOOL const bNeedDump
        )
{
    Mutex::Autolock _lock(mLock);
    MINT srcFormat = pSrcBuf ? pSrcBuf->getImgFormat() : eImgFmt_UNKNOWN;
    MBOOL bBypassISP = this->check10BitsFmt(srcFormat);
    MBOOL bSinglePort = DpIspStream::queryMultiPortSupport(DpIspStream::ISP_ZSD_STREAM) == 1;
    // MDP Hardware only support one rotate output operation once
    MBOOL bDiffRotation = u4Transform_0 != 0 && u4Transform_1 != 0;

    if ((bSinglePort || bDiffRotation) && !bBypassISP)
    {
        MBOOL r = MTRUE;
        r &= getImp()->execute(pSrcBuf, pDstBuf_0, nullptr, rROI_0, u4Transform_0, u4TimeOutInMs, pDstBuf_1 == nullptr, endTime);
        if(pDstBuf_1 != nullptr)
            r &= getImp()->execute(pSrcBuf, nullptr, pDstBuf_1, rROI_1, u4Transform_1, u4TimeOutInMs, MTRUE, endTime);
        return r;
    }
    else
        return bBypassISP ? getImp()->executeByPassISP(pSrcBuf, pDstBuf_0, pDstBuf_1, rROI_0, rROI_1, u4Transform_0, u4Transform_1, u4TimeOutInMs, endTime)
                          : getImp()->execute(pSrcBuf, pDstBuf_0, pDstBuf_1, rROI_0, rROI_1, u4Transform_0, u4Transform_1, u4TimeOutInMs, endTime);
}


////////////////////////////////////////////////////////////////////////////////

