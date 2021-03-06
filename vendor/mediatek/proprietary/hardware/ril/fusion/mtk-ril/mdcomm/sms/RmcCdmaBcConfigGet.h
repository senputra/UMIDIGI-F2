/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2017. All rights reserved.
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
#ifndef __RMC_CDMA_BC_CONFIG_GET_H__
#define __RMC_CDMA_BC_CONFIG_GET_H__
/*****************************************************************************
 * Include
 *****************************************************************************/
#include "common/RmcData.h"
#include "common/RmcMessageHandler.h"
#include "RmcCdmaBcRangeParser.h"

/*****************************************************************************
 * Class RmcCdmaGetBcConfigReq
 *****************************************************************************/
class RmcCdmaGetBcConfigReq : RmcMultiAtReq {
    RFX_DECLARE_DATA_CLASS(RmcCdmaGetBcConfigReq);

// External Method
public:
    // Check if broadcast is activate in modem
    //
    // RETURNS: true if broadcast is activate in mode
    bool isBcActivate() {
        return m_mode == 1;
    }

    // Get the ranges of the channels
    //
    // RETURNS: ranges of channel
    const Vector<Range> &getChannels() const {
        return m_channels;
    }

    // Get the ranges of the languages
    //
    // RETURNS: ranges of the languages
    const Vector<Range> &getLanguages() const {
        return m_languages;
    }

// Override
protected:
    virtual RmcAtSendInfo* onGetFirstAtInfo(RfxBaseHandler *h);
    virtual RmcAtSendInfo* onGetNextAtInfo(const String8 & cmd,RfxBaseHandler * h);
    virtual bool onHandleIntermediates(const String8 & cmd,RfxAtLine * line,RfxBaseHandler * h);

// Implementation
private:
    int m_mode;
    Vector<Range> m_channels;
    Vector<Range> m_languages;
};

/*****************************************************************************
 * Class RmcCdmaGetBcConfigRsp
 *****************************************************************************/
class RmcCdmaGetBcConfigRsp : public RmcVoidRsp {
    RFX_DECLARE_DATA_CLASS(RmcCdmaGetBcConfigRsp);
// Constructor / Destructor
public:
    RmcCdmaGetBcConfigRsp(Vector<RIL_CDMA_BroadcastSmsConfigInfo> infos, RIL_Errno e);
// Implementation
private:
    Vector<RIL_CDMA_BroadcastSmsConfigInfo> m_infos;
    Vector<RIL_CDMA_BroadcastSmsConfigInfo *> m_pInfos;
};


/*****************************************************************************
 * Class RmcCdmaBcGetConfigHdlr
 *****************************************************************************/
class RmcCdmaBcGetConfigHdlr : public RmcBaseRequestHandler {
// Constructor / Destructor
public:
    RmcCdmaBcGetConfigHdlr(RfxBaseHandler *h) :RmcBaseRequestHandler(h) {
    }

    virtual ~RmcCdmaBcGetConfigHdlr() {
    }
// Override
public:
    virtual RmcBaseRspData *onGetRspData(RmcBaseReqData *req);
};
#endif /* __RMC_CDMA_BC_CONFIG_GET_H__ */
