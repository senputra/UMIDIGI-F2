/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2016. All rights reserved.
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

// External SIM [Start]
/*****************************************************************************
 * Include
 *****************************************************************************/
 
#include <telephony/mtk_ril.h>
#include "RfxMessageId.h"
#include "RfxStringData.h"
#include "RfxVoidData.h"
#include "RfxVsimOpEventData.h"
#include "rfx_properties.h"
#include "RmcCommSimUrcHandler.h"
#include "RfxRilUtils.h"
#include "RfxVsimEventData.h"
#include "RfxVsimOpIndicationData.h"
#include "RmcVsimRequestHandler.h"
#include "RmcVsimUrcHandler.h"

const char* vSimUrcList[] = {
    "+ERSAIND:",
    "+ERSAAUTH:",
    "+ERSIMAUTH:",
};

RFX_REGISTER_DATA_TO_URC_ID(RfxVsimOpIndicationData, RFX_MSG_URC_SIM_VSIM_OPERATION_INDICATION);

RFX_IMPLEMENT_HANDLER_CLASS(RmcVsimUrcHandler, RIL_CMD_PROXY_URC);

/*****************************************************************************
 * Class RfxController
 *****************************************************************************/
RmcVsimUrcHandler::RmcVsimUrcHandler(int slot_id, int channel_id) :
    RmcSimBaseHandler(slot_id, channel_id) {
    setTag(String8("RmcVsimUrc"));
}

RmcVsimUrcHandler::~RmcVsimUrcHandler() {
}

const char** RmcVsimUrcHandler::queryUrcTable(int *record_num) {
    const char **p = vSimUrcList;
    *record_num = sizeof(vSimUrcList)/sizeof(char*);
    return p;
}

RmcSimBaseHandler::SIM_HANDLE_RESULT RmcVsimUrcHandler::needHandle(
        const sp<RfxMclMessage>& msg) {
    RmcSimBaseHandler::SIM_HANDLE_RESULT result = RmcSimBaseHandler::RESULT_IGNORE;
    char* ss = msg->getRawUrc()->getLine();
    //logD(mTag, "[VSIM]needHandle: ss = %s", ss);

    if (strStartsWith(ss, "+ERSAIND:") ||
        strStartsWith(ss, "+ERSAAUTH:") ||
        strStartsWith(ss, "+ERSIMAUTH:")) {
        result = RmcSimBaseHandler::RESULT_NEED;
    }
    return result;
}

void RmcVsimUrcHandler::handleUrc(const sp<RfxMclMessage>& msg, RfxAtLine *urc) {
    String8 ss(urc->getLine());

    if (strStartsWith(ss, "+ERSAIND:")) {
        handleVsimEventDetected(msg);
    } else if (strStartsWith(ss, "+ERSAAUTH:") ||
               strStartsWith(ss, "+ERSIMAUTH:")) {
        handleVsimAuthEventDetected(msg);
    }
}

void RmcVsimUrcHandler::handleVsimAuthEventDetected (const sp<RfxMclMessage>& msg) {
    // In case of receving +ERSAAUTH event, we need to occupy RF in AKA-SIM slot. (stack 2 in modem)
    RIL_VsimOperationEvent event;
    int event_type = 0;
    RfxAtLine *line = msg->getRawUrc();
    char rsim_prop[RFX_PROPERTY_VALUE_MAX] = {0};
    char akasim_prop[RFX_PROPERTY_VALUE_MAX] = {0};
    String8 ss(line->getLine());
    int err = 0;
    int slotId = 0;

    memset(&event, 0, sizeof(event));
//    logD(mTag, "[VSIM]handleVsimAuthEventDetected: ss = %s", (char*)line->getLine());

    if (strStartsWith(ss, "+ERSAAUTH:")) {
        RmcCommSimUrcHandler::setMdWaitingResponse(m_slot_id, VSIM_MD_WAITING_APDU);
        sendEvent(RFX_MSG_EVENT_SIM_VSIM_AUTH_REQUEST, RfxStringData((char*)line->getLine()),
                  RIL_CMD_PROXY_11, m_slot_id);

        return ;
    } else if (strStartsWith(ss, "+ERSIMAUTH:")) {

        /**
         * [+ERSIMAUTH URC Command Usage]
         * +ERSAAUTH: <type>
         *
         * <type>:
         * 0 (abort authenication procedure)
         * 1 (complete authenication procedure)
         */

        line->atTokStart(&err);
        if (err < 0) {
            goto done;
        }

        event_type = line->atTokNextint(&err);
        if (err < 0) {
            logE(mTag, "[VSIM]onVsimAuthEventDetected get type fail!");
            goto done;
        }

        switch (event_type) {
            case 0:
                // Abort authenication, send notify to Jave layer directly
                logD(mTag, "[VSIM]handleVsimAuthAckEvent: auth abort");
                rfx_property_get("vendor.gsm.prefered.rsim.slot", rsim_prop, "-1");

                if (atoi(rsim_prop) == -1) {
                    goto done;
                }
                slotId = atoi(rsim_prop);

                RfxRilUtils::setRsimAuthOngoing(m_slot_id, 0);
                RfxRilUtils::setRsimAuthOngoing(slotId, 0);
                event.eventId = MSG_ID_UICC_AUTHENTICATION_ABORT_IND;
                break;
            case 1:
                // Complete authenication, send notify to Jave layer directly
                logD(mTag, "[VSIM]handleVsimAuthAckEvent: auth abort");
                RfxRilUtils::setRsimAuthOngoing(m_slot_id, 0);
                event.eventId = MSG_ID_UICC_AUTHENTICATION_DONE_IND;
                break;
            default:
                logD(mTag, "[VSIM]onVsimAuthEventDetected: +ERSIMAUTH: unsupport type");
        }

        if (RmcVsimRequestHandler::isInternalTestVsimComponent() == 0) {
            // Release AKA SIM stack
            rfx_property_get("vendor.gsm.prefered.aka.sim.slot", akasim_prop, "-1");

            if (atoi(akasim_prop) == -1) {
                goto done;
            }
            sendEvent(RFX_MSG_EVENT_SIM_VSIM_RELEASE_AKA_SIM, RfxVoidData(), RIL_CMD_PROXY_11,
                      m_slot_id);
        }
    }

done:
    logD(mTag, "[VSIM]onVsimAuthEventDetected: eventId = %d", event.eventId);
    sp<RfxMclMessage> unsol = RfxMclMessage::obtainUrc(RFX_MSG_URC_SIM_VSIM_OPERATION_INDICATION,
                                                       m_slot_id,
                                                       RfxVsimOpIndicationData((void*)&event,
                                                                               sizeof(event)));

    responseToTelCore(unsol);
}

void RmcVsimUrcHandler::handleVsimEventDetected(const sp<RfxMclMessage>& msg) {
    RIL_VsimOperationEvent event;
    int event_type;
    int err = 0;
    RfxAtLine *line = msg->getRawUrc();

    memset(&event, 0, sizeof(event));
    // 256 bytes for data + 5 bytes header information: CLA,INS,P1,P2,P3 */
    //  #define APDU_REQ_MAX_LEN (261)
    // 256 bytes for data + 2 bytes status word SW1 and SW2 */
    //  #define APDU_RSP_MAX_LEN (258)
    //  --> Need to *2, since the received data is hex string.

    /**
     * [+ERSAIND URC Command Usage]
     * +ERSAIND: <msg_id>[, <parameter1> [, <parameter2> [, <\A1K>]]]
     *
     * <msg_id>:
     * 0 (APDU indication) // Send APDU to AP
     *       <parameter1>: command apdu // APDU data need send to card (string)
     * 1 (card reset indication)
     * 2 (power-down indication)
     *       <parameter1>: mode // Not define mode yet, [MTK]0 is default
     * 3 (vsim trigger plug out)
     * 4 (vsim trigger plug in)
     */

    line->atTokStart(&err);
    if (err < 0) {
        goto done;
    }

    event_type = line->atTokNextint(&err);
    if (err < 0) {
        logE(mTag, "[VSIM]onVsimEventDetected get type fail!");
        goto done;
    }

    if ((RfxRilUtils::isVsimEnabledBySlot(m_slot_id) == 0 ||
        RmcVsimRequestHandler::isBeingPlugOut(m_slot_id) == 1) &&
        (event_type == 0 || event_type == 1)) {
        RmcCommSimUrcHandler::setMdWaitingResponse(m_slot_id, event_type);
        sendEvent(RFX_MSG_EVENT_SIM_VSIM_SEND_ERROR_RESPONSE, RfxVoidData(), RIL_CMD_PROXY_11,
                  m_slot_id);
        logW(mTag, "[VSIM] onVsimEventDetected received URC during vsim disabled.");
        return;
    }

    switch (event_type) {
        case 0:
            event.eventId = MSG_ID_UICC_APDU_REQUEST; //REQUEST_TYPE_APDU_EVENT;

            if (line->atTokHasmore()) {
                event.data = line->atTokNextstr(&err);
                if (err < 0) {
                    logE(mTag, "[VSIM]onVsimEventDetected get string fail!");
                    goto done;
                }

                event.data_length = strlen(event.data);
             }
            RmcCommSimUrcHandler::setMdWaitingResponse(m_slot_id, VSIM_MD_WAITING_APDU);
            break;
        case 1:
            logD(mTag, "[VSIM]onVsimEventDetected: card reset request");
            RmcCommSimUrcHandler::setMdWaitingResponse(m_slot_id, VSIM_MD_WAITING_ATR);
            event.eventId = MSG_ID_UICC_RESET_REQUEST; //REQUEST_TYPE_ATR_EVENT;
            RmcVsimRequestHandler::setVerifiedVsimClient(0);
            if (!RfxRilUtils::isVsimClientConnected()) {
                RIL_VsimEvent event;
                event.transaction_id = 0;
                event.eventId = REQUEST_TYPE_PLUG_OUT;
                event.sim_type = 0;
                sendEvent(RFX_MSG_EVENT_SIM_VSIM_PLUG_OUT,
                          RfxVsimEventData(&event, sizeof(RIL_VsimEvent)),
                          RIL_CMD_PROXY_11, m_slot_id);
                logW(mTag,
                     "[VSIM]onVsimEventDetected: recevied VSIM reset under VSIM client disconnected. %d",
                     RFX_MSG_EVENT_SIM_VSIM_PLUG_OUT);
                return;
            }
            break;
        case 2:
            logD(mTag, "[VSIM]onVsimEventDetected: card power down");
            RmcCommSimUrcHandler::setMdWaitingResponse(m_slot_id, VSIM_MD_WAITING_RESET);
            return;
            /*event.eventId = REQUEST_TYPE_CARD_POWER_DOWN;
            event.result = 0;   //Use result filed to record mode information
            if (line->atTokHasmore()) {
                 event.result = line->atTokNextint(&err);
                 if (err < 0) {
                     logE(mTag, "[VSIM]onVsimEventDetected get power down mode fail!");
                     goto done;
                 }
            }
            break;*/
        case 3:
            logD(mTag, "[VSIM]onVsimEventDetected: VSIM_TRIGGER_PLUG_OUT");
            RmcCommSimUrcHandler::setVsimPlugInOutEvent(m_slot_id, VSIM_TRIGGER_PLUG_OUT);
            return;
        case 4:
            logD(mTag, "[VSIM]onVsimEventDetected: VSIM_TRIGGER_PLUG_IN");
            RmcCommSimUrcHandler::setVsimPlugInOutEvent(m_slot_id, VSIM_TRIGGER_PLUG_IN);
            return;
        default:
            logD(mTag, "[VSIM]onVsimEventDetected: unsupport type");
    }

done:
    sp<RfxMclMessage> unsol = RfxMclMessage::obtainUrc(RFX_MSG_URC_SIM_VSIM_OPERATION_INDICATION,
                                                       m_slot_id,
                                                       RfxVsimOpIndicationData((void*)&event,
                                                                               sizeof(event)));

    responseToTelCore(unsol);
}


// External SIM [End]
