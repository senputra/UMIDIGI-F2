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

#ifndef _MTK_HARDWARE_MTKCAM_INCLUDE_MTKCAM_PIPELINE_MODEL_IPIPELINEMODELCALLBACK_H_
#define _MTK_HARDWARE_MTKCAM_INCLUDE_MTKCAM_PIPELINE_MODEL_IPIPELINEMODELCALLBACK_H_
//
#include "types.h"
//
#include <utils/RefBase.h>


namespace NSCam {
namespace v3 {
namespace pipeline {
namespace model {


/******************************************************************************
 *
 ******************************************************************************/
class IPipelineModelCallback : public virtual android::RefBase
{
public:     ////    Interfaces.

    virtual auto    onFrameUpdated(
                        UserOnFrameUpdated const& params
                        ) -> void                                           = 0;

    /**
     * This method is called when some (but not all) result metadata are available.
     *
     * For each frame, some result metadata might be available earlier than others.
     * For performance-oriented use-cases, applications should query the metadata they need to make
     * forward progress from the partial results and avoid waiting for the completed result.
     */
    virtual auto    onMetaResultAvailable(
                        UserOnMetaResultAvailable&& arg
                    ) -> void                                               = 0;

    /**
     * This method is called when some (input or output) image buffers are released.
     *
     * When acquiring image stream buffers from the image buffer provider (set on configure()),
     * this method must be used for the client to check a buffer's status.
     */
    virtual auto    onImageBufferReleased(
                        UserOnImageBufferReleased&& arg
                    ) -> void                                               = 0;

    /**
     * This method is called when a request has fully completed no matter whether
     * the processing for that request succeeds or not.
     */
    virtual auto    onRequestCompleted(
                        UserOnRequestCompleted&& arg
                    ) -> void                                               = 0;

};


/******************************************************************************
 *
 ******************************************************************************/
};  //namespace model
};  //namespace pipeline
};  //namespace v3
};  //namespace NSCam
#endif  //_MTK_HARDWARE_MTKCAM_INCLUDE_MTKCAM_PIPELINE_MODEL_IPIPELINEMODELCALLBACK_H_
