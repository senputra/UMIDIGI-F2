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

#ifndef _MY_HDR_H_
#define _MY_HDR_H_

/*******************************************************************************
*
*******************************************************************************/
//should be 0
#define HDR_DEBUG_SAVE_SOURCE_IMAGE                (0)
#define HDR_DEBUG_SAVE_SMALL_IMAGE                (0)
#define HDR_DEBUG_SAVE_NORMALIZED_SMALL_IMAGE    (0)
#define HDR_DEBUG_SAVE_SE_IMAGE                    (0)
#define HDR_DEBUG_SAVE_WEIGHTING_MAP            (0)
#define HDR_DEBUG_SAVE_DOWNSCALED_WEIGHTING_MAP    (0)
#define HDR_DEBUG_SAVE_BLURRED_WEIGHTING_MAP    (0)
#define HDR_DEBUG_SAVE_HDR_RESULT                (0)
#define HDR_DEBUG_SAVE_HDR_NR                    (0)

#define HDR_DEBUG_SAVE_POSTVIEW                 (0)
#define HDR_DEBUG_SAVE_RESIZE_HDR_RESULT        (0)
#define HDR_DEBUG_SAVE_HDR_JPEG                 (0)

#define HDR_DEBUG_OFFLINE_SOURCE_IMAGE             (0)
#define HDR_DEBUG_SKIP_HANDLER                   (0)
#define HDR_DEBUG_SKIP_3A                          (0)
#define HDR_DEBUG_SKIP_MODIFY_POLICY            (0)
#define HDR_DEBUG_SKIP_EXIF                     (0)
#define HDR_DEBUG_SKIP_REUSE_BUFFER             (1)     // since buffer allocation is very fast, we didn't need reuse buffer

//should be 1
#define HDR_SPEEDUP_JPEG                        (1)


#define HDR_PROFILE_CAPTURE                        (0)        // General.
#define HDR_PROFILE_CAPTURE2                    (1)        // In capture().
#define HDR_PROFILE_CAPTURE3                    (0)        // In createFullFrame().
#define HDR_PROFILE_MET                         (0)

#define HDR_AE_12BIT_FLARE                      (1)     // 1:12bit, 0:8bit

#define HDR_BURST_JPEG_SIZE                     (0)     // 0:Full size 1:Jpeg size

/*******************************************************************************
*
*******************************************************************************/
#include <utils/Errors.h>

#include <IShot.h>

#include <mtkcam/camshot/_callbacks.h> //workaround for ISImager.h

#include <mtkcam/iopipe/SImager/ISImager.h>
#include <fcntl.h>
#include <mtkcam/hwutils/CameraProfile.h>  // For CPTLog*()/AutoCPTLog class.
#include <mtkcam/hal/IHalSensor.h>
using namespace CPTool;
#include "camera_custom_hdr.h"    // For HDR Customer Parameters in Customer Folder.

#include "Hdr.h"
#include <mtkcam/camshot/_params.h>
#include <mtkcam/featureio/capturenr.h>
#include <mtkcam/featureio/aaa_hal_common.h>
#include <mtkcam/v1/common.h>

#define PTHREAD_MUTEX_INITIALIZER_LOCK  {{1}}

/*******************************************************************************
*
*******************************************************************************/

#define DEBUG_LOG_TAG                "HdrShot"

#define HDR_LOGV(x, ...)   CAM_LOGV("[%s] " x, DEBUG_LOG_TAG, ##__VA_ARGS__)
#define HDR_LOGD(x, ...)   CAM_LOGD("[%s] " x, DEBUG_LOG_TAG, ##__VA_ARGS__)
#define HDR_LOGI(x, ...)   CAM_LOGI("[%s] " x, DEBUG_LOG_TAG, ##__VA_ARGS__)
#define HDR_LOGW(x, ...)   CAM_LOGW("[%s] " x, DEBUG_LOG_TAG, ##__VA_ARGS__)
#define HDR_LOGE(x, ...)   CAM_LOGE("[%s] <%s:#%d>" x, DEBUG_LOG_TAG, \
                                 __FILE__, __LINE__, ##__VA_ARGS__)

#define HDR_LOGD_IF(cond, ...)  do { if ((cond)) HDR_LOGD(__VA_ARGS__); } while (0)
#define HDR_LOGI_IF(cond, ...)  do { if ((cond)) HDR_LOGI(__VA_ARGS__); } while (0)
#define HDR_LOGW_IF(cond, ...)  do { if ((cond)) HDR_LOGW(__VA_ARGS__); } while (0)
#define HDR_LOGE_IF(cond, ...)  do { if ((cond)) HDR_LOGE(__VA_ARGS__); } while (0)

// ---------------------------------------------------------------------------

#define FUNCTION_LOG_START      HDR_LOGV("[%s] +", __FUNCTION__)
#define FUNCTION_LOG_END        HDR_LOGV("[%s] - ret(%d)", __FUNCTION__, ret)
#define FUNCTION_LOG_END_MUM    HDR_LOGV("[%s] -", __FUNCTION__)


#define CHECK_OBJECT(x)         do { if (x == NULL) { HDR_LOGE("Null %s Object", #x); return MFALSE;}} while(0)
#define CHECK_RET(fmt, arg...)  do { if( !ret ){ HDR_LOGE(fmt, ##arg); ret = MFALSE; goto lbExit; }} while(0)


/*******************************************************************************
*
*******************************************************************************/
#if (HDR_PROFILE_CAPTURE || HDR_PROFILE_CAPTURE2 || HDR_PROFILE_CAPTURE3)
    class MyDbgTimer
    {
    protected:
        char const*const    mpszName;
        mutable MINT32      mIdx;
        MINT32 const        mi4StartUs;
        mutable MINT32      mi4LastUs;

    public:
        MyDbgTimer(char const*const pszTitle)
            : mpszName(pszTitle)
            , mIdx(0)
            , mi4StartUs(getUs())
            , mi4LastUs(getUs())
        {
        }

        inline MINT32 getUs() const
        {
            struct timeval tv;
            ::gettimeofday(&tv, NULL);
            return tv.tv_sec * 1000000 + tv.tv_usec;
        }

        inline MBOOL print(char const*const pszInfo = "") const
        {
            MINT32 const i4EndUs = getUs();
            if  (0==mIdx)
            {
                HDR_LOGD("[%s] %s:(%d-th) ===> [start-->now: %d ms]", mpszName, pszInfo, mIdx++, (i4EndUs-mi4StartUs)/1000);
                HDR_LOGD("[%s] %s:(%d-th) ===> [start-->now: %d ms]\n", mpszName, pszInfo, mIdx++, (i4EndUs-mi4StartUs)/1000);
            }
            else
            {
                HDR_LOGD("[%s] %s:(%d-th) ===> [start-->now: %d ms] [last-->now: %d ms]", mpszName, pszInfo, mIdx++, (i4EndUs-mi4StartUs)/1000, (i4EndUs-mi4LastUs)/1000);
                HDR_LOGD("[%s] %s:(%d-th) ===> [start-->now: %d ms] [last-->now: %d ms]\n", mpszName, pszInfo, mIdx++, (i4EndUs-mi4StartUs)/1000, (i4EndUs-mi4LastUs)/1000);
            }
            mi4LastUs = i4EndUs;

            //sleep(4); //wait 1 sec for AE stable

            return  MTRUE;
        }
    };
#endif  // (HDR_PROFILE_CAPTURE || HDR_PROFILE_CAPTURE2)


/*******************************************************************************
*
*******************************************************************************/
#endif  //  _MY_HDR_H_

