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
#include <cutils/properties.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/md5.h>
#include <openssl/x509.h>
#include <telephony/mtk_ril.h>
#include "RfxIntsData.h"
#include "RfxLog.h"
#include "RfxRilUtils.h"
#include "RfxStringData.h"
#include "RfxVoidData.h"
#include "RfxVsimEventData.h"
#include "RfxVsimOpEventData.h"
#include "RfxVsimOpIndicationData.h"
#include "RmcCommSimUrcHandler.h"
#include "RmcVsimRequestHandler.h"
#include "RmcVsimUrcHandler.h"
#include "libmtkrilutils.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "usim_fcp_parser.h"
#ifdef __cplusplus
}
#endif

int RmcVsimRequestHandler::sVerifiedVsimClient = 0;
int RmcVsimRequestHandler::sBeingPlugOut[MAX_SIM_COUNT] = {0};

static const int chVsimReqList[] = {
    RFX_MSG_REQUEST_SIM_VSIM_NOTIFICATION,
    RFX_MSG_REQUEST_SIM_VSIM_OPERATION,
};

static const int chVsimEventList[] = {
    RFX_MSG_EVENT_SIM_VSIM_PLUG_OUT,
    RFX_MSG_EVENT_SIM_VSIM_AUTH_REQUEST,
    RFX_MSG_EVENT_SIM_VSIM_RELEASE_AKA_SIM,
    RFX_MSG_EVENT_SIM_VSIM_SEND_ERROR_RESPONSE,
    RFX_MSG_EVENT_VSIM_RELEASE_RF,
};

RFX_REGISTER_DATA_TO_REQUEST_ID(RfxVsimEventData, RfxIntsData,
        RFX_MSG_REQUEST_SIM_VSIM_NOTIFICATION);
RFX_REGISTER_DATA_TO_REQUEST_ID(RfxVsimOpEventData, RfxIntsData,
        RFX_MSG_REQUEST_SIM_VSIM_OPERATION);

RFX_REGISTER_DATA_TO_EVENT_ID(RfxVsimEventData, RFX_MSG_EVENT_SIM_VSIM_PLUG_OUT);
RFX_REGISTER_DATA_TO_EVENT_ID(RfxStringData, RFX_MSG_EVENT_SIM_VSIM_AUTH_REQUEST);
RFX_REGISTER_DATA_TO_EVENT_ID(RfxVoidData, RFX_MSG_EVENT_SIM_VSIM_RELEASE_AKA_SIM);
RFX_REGISTER_DATA_TO_EVENT_ID(RfxVoidData, RFX_MSG_EVENT_SIM_VSIM_SEND_ERROR_RESPONSE);
RFX_REGISTER_DATA_TO_EVENT_ID(RfxVoidData, RFX_MSG_EVENT_VSIM_RELEASE_RF);

/*****************************************************************************
 * Class RfxController
 *****************************************************************************/

RmcVsimRequestHandler::RmcVsimRequestHandler(int slot_id, int channel_id):
    RmcSimBaseHandler(slot_id, channel_id) {
        setTag(String8("RmcVsimRequest"));
}

RmcVsimRequestHandler::~RmcVsimRequestHandler() {
}

const int* RmcVsimRequestHandler::queryTable(int channel_id, int *record_num) {
    if (channel_id == RIL_CMD_PROXY_11) {
        *record_num = sizeof(chVsimReqList)/sizeof(int);
        return chVsimReqList;
    } else {
        // No request registered!
    }
    return NULL;
}

const int* RmcVsimRequestHandler::queryEventTable(int channel_id, int *record_num) {
    if (channel_id == RIL_CMD_PROXY_11) {
        *record_num = sizeof(chVsimEventList)/sizeof(int);
        return chVsimEventList;
    }
    return NULL;
}

RmcSimBaseHandler::SIM_HANDLE_RESULT RmcVsimRequestHandler::needHandle(
        const sp<RfxMclMessage>& msg) {
    int request = msg->getId();
    RmcSimBaseHandler::SIM_HANDLE_RESULT result = RmcSimBaseHandler::RESULT_IGNORE;

    switch(request) {
        case RFX_MSG_REQUEST_SIM_VSIM_NOTIFICATION:
        case RFX_MSG_REQUEST_SIM_VSIM_OPERATION:
        case RFX_MSG_EVENT_SIM_VSIM_AUTH_REQUEST:
        case RFX_MSG_EVENT_SIM_VSIM_RELEASE_AKA_SIM:
        case RFX_MSG_EVENT_SIM_VSIM_SEND_ERROR_RESPONSE:
        case RFX_MSG_EVENT_SIM_VSIM_PLUG_OUT:
        case RFX_MSG_EVENT_VSIM_RELEASE_RF:
            result = RmcSimBaseHandler::RESULT_NEED;
            break;
        default:
            logE(mTag, "Not support the request!");
            break;
    }
    return result;
}

void RmcVsimRequestHandler::handleRequest(const sp<RfxMclMessage>& msg) {
    int request = msg->getId();
    switch(request) {
        case RFX_MSG_REQUEST_SIM_VSIM_NOTIFICATION:
            handleVsimNotification(msg);
            break;
        case RFX_MSG_REQUEST_SIM_VSIM_OPERATION:
            handleVsimOperation(msg);
            break;
        default:
            logE(mTag, "Not support the request!");
            break;
    }
}

void RmcVsimRequestHandler::handleEvent(const sp<RfxMclMessage>& msg) {
    int event = msg->getId();
    switch(event) {
        case RFX_MSG_EVENT_SIM_VSIM_PLUG_OUT:
            handleVsimNotification(msg);
            break;
        case RFX_MSG_EVENT_SIM_VSIM_AUTH_REQUEST:
            handleVsimAuthRequestEvent(msg);
            break;
        case RFX_MSG_EVENT_SIM_VSIM_RELEASE_AKA_SIM:
            handleReleaseAkaSim();
            break;
        case RFX_MSG_EVENT_SIM_VSIM_SEND_ERROR_RESPONSE:
            sendVsimErrorResponse();
            break;
        case RFX_MSG_EVENT_VSIM_RELEASE_RF:
            handleReleaseRf();
            break;
        default:
            logD(mTag, "Not support the event %d!", event);
            break;
    }
}

/**
 * [AT+ERSA AT Command Usage]
 * AT+ERSA = <msg_id>[, <parameter1> [, <parameter2> [, <\A1K>]]]
 *
 * <msg_id>:
 * 0 (APDU request)  // Send APDU execute result to MD
 *       <parameter1>: apdu_status // failure or success, 1: success, 0: failure
 *       <parameter2>: response apdu segment  // The return data from card (string)
 * 1 (event: card reset)
 *       <parameter1>: ATR // (string)
 * 2 (event: card error)
 *       <parameter1>: error cause // Not define the error code yet, currently MD only handle driver's hot swap signal (recovery is trigger by Status Word)
 * 3 (event: card hot swap out)
 * 4 (event: card hot swap in)
 */
void RmcVsimRequestHandler::handleVsimNotification(const sp<RfxMclMessage>& msg) {
    sp<RfxAtResponse> p_response;
    int err;
    String8 cmd("");
    RIL_Errno ret = RIL_E_SUCCESS;
    RIL_VsimEvent *event = (RIL_VsimEvent *)msg->getData()->getData();
    int datalen = msg->getData()->getDataLength();
    sp<RfxMclMessage> response;
    UICC_Status sim_status = UICC_ABSENT;
    int mdOff = getNonSlotMclStatusManager()->getBoolValue(RFX_STATUS_KEY_MODEM_POWER_OFF, false);

    logD(mTag, "[VSIM]requestVsimNotification, event_Id: %d, sim_type: %d, datalen: %d",
         event->eventId, event->sim_type, datalen);

    // Check if any not response URC, if so send error response first.
    if (RmcCommSimUrcHandler::getMdWaitingResponse(m_slot_id) != VSIM_MD_WAITING_RESET) {
        if (event->eventId == REQUEST_TYPE_ENABLE_EXTERNAL_SIM ||
            event->eventId == REQUEST_TYPE_PLUG_IN) {
            sendVsimErrorResponse();
        }
    }

    if (event->eventId == REQUEST_TYPE_ENABLE_EXTERNAL_SIM) {
        setExternalSimProperty(m_slot_id, (char*)"vendor.gsm.external.sim.enabled", (char*)"1");
        if (isBeingPlugOut(m_slot_id) == 1) {
            logW(mTag, "[VSIM]Enable vsim when it is being plug out.");
            int count = 0;
            while((true == getNonSlotMclStatusManager()->getBoolValue(
                    RFX_STATUS_KEY_CAPABILITY_SWITCH_URC_CHANNEL, false)) && count < 100) {
                usleep(500*1000);
                count++;
            }
            if (100 == count) {
                logE(mTag, "[VSIM]Switch URC channel didn't finish.");
                ret = RIL_E_GENERIC_FAILURE;
                goto done;
            }
            atSendCommand("AT+ERSA=3");
            sBeingPlugOut[m_slot_id] = 0;
        }
        if (RfxRilUtils::isNonDsdaRemoteSupport()) {
            if (event->sim_type == SIM_TYPE_REMOTE_SIM) {
                rfx_property_set("vendor.gsm.prefered.rsim.slot",
                                 String8::format("%d", m_slot_id).string());
            }
            int count = 0;
            do {
                sim_status = getSimStatus();
                if (UICC_BUSY == sim_status) {
                    usleep(200*1000);
                    count++;
                }
            } while((UICC_BUSY == sim_status) && count < 10);
            cmd.append("AT+EAPVSIM=1,0,1");

        } else if (RfxRilUtils::isSwitchVsimWithHotSwap()) {
            int count = 0;
            do {
                sim_status = getSimStatus();
                if (UICC_BUSY == sim_status) {
                    usleep(200*1000);
                    count++;
                }
            } while((UICC_BUSY == sim_status) && count < 10);
            cmd.append("AT+EAPVSIM=1,1");
        } else {
            response = RfxMclMessage::obtainResponse(
                    msg->getId(), ret,
                    RfxVsimEventData((void*)event, sizeof(RIL_VsimEvent)), msg, false);
            responseToTelCore(response);
            return;
        }
    } else if (event->eventId == REQUEST_TYPE_DISABLE_EXTERNAL_SIM) {
        setExternalSimProperty(m_slot_id, (char*)"vendor.gsm.external.sim.enabled", (char*)"0");
        setExternalSimProperty(m_slot_id, (char*)"vendor.gsm.external.sim.inserted", (char*)"0");
        setExternalSimProperty(m_slot_id, (char*)"persist.vendor.radio.external.sim", (char*)"0");
        setExternalSimProperty(m_slot_id, (char*)"persist.vendor.radio.vsim.timeout", (char*)"");
        char property[RFX_PROPERTY_VALUE_MAX] = {0};
        rfx_property_get("vendor.gsm.prefered.aka.sim.slot", property, "-1");
        if (atoi(property) == m_slot_id) {
            rfx_property_set("vendor.gsm.prefered.aka.sim.slot", "-1");
        }
        memset(property, 0, sizeof(property));
        rfx_property_get("vendor.gsm.prefered.rsim.slot", property, "-1");
        if (atoi(property) == m_slot_id) {
            rfx_property_set("vendor.gsm.prefered.rsim.slot", "-1");
        }
        if (RmcCommSimUrcHandler::getMdWaitingResponse(m_slot_id) != VSIM_MD_WAITING_RESET) {
            sendVsimErrorResponse();
        }
        if (isBeingPlugOut(m_slot_id) == 1) {
            logW(mTag, "[VSIM]Disable vsim when it is being plug out.");
            atSendCommand("AT+ERSA=3");
            sBeingPlugOut[m_slot_id] = 0;
        }
        if (RfxRilUtils::isNonDsdaRemoteSupport()) {
            // Modem SIM hot plug limitation, it need to wait for get non-BUSY sim state to trigger
            // AP VSIM hot plug command.
            int count = 0;
            do {
                sim_status = getSimStatus();
                if (UICC_BUSY == sim_status) {
                    usleep(200*1000);
                    count++;
                }
            } while((UICC_BUSY == sim_status) && count < 10);

            if (RfxRilUtils::isExternalSimOnlySlot(m_slot_id) > 0 &&
                !RfxRilUtils::isNonDsdaRemoteSupport()) {
                cmd.append("AT+EAPVSIM=1,0,1");
            } else {
                cmd.append("AT+EAPVSIM=0,0,1");
            }
        } else if (RfxRilUtils::isSwitchVsimWithHotSwap()) {
            cmd.append("AT+EAPVSIM=0");
        } else {
            response = RfxMclMessage::obtainResponse(
                    msg->getId(), ret,
                    RfxVsimEventData((void*)event, sizeof(RIL_VsimEvent)), msg, false);
            responseToTelCore(response);
            return;
        }
    } else if (event->eventId == REQUEST_TYPE_PLUG_IN) {
        char property[RFX_PROPERTY_VALUE_MAX] = {0};
        getMSimProperty(m_slot_id, (char*)"vendor.gsm.external.sim.enabled", property);
        if (atoi(property) != 0) {
            setExternalSimProperty(m_slot_id, (char*)"vendor.gsm.external.sim.inserted",
                            (char*)String8::format("%d", event->sim_type).string());
        }
        sBeingPlugOut[m_slot_id] = 0;
        if (RfxRilUtils::isNonDsdaRemoteSupport()) {
            // Modem SIM hot plug limitation, it need to wait for get non-BUSY sim state to trigger
            // AP VSIM hot plug command.
            int count = 0;
            do {
                sim_status = getSimStatus();
                if (UICC_BUSY == sim_status) {
                    usleep(200*1000);
                    count++;
                }
            } while((UICC_BUSY == sim_status) && count < 10);

            if (event->sim_type == SIM_TYPE_LOCAL_SIM) {
                cmd.append("AT+EAPVSIM=1,1,1");
            } else if (event->sim_type == SIM_TYPE_REMOTE_SIM) {
                cmd.append("AT+ERSIM");
            }
        } else {
            cmd.append("AT+ERSA=4");
        }
    } else if (event->eventId == REQUEST_TYPE_PLUG_OUT) {
        if (RmcCommSimUrcHandler::getMdWaitingResponse(m_slot_id) != VSIM_MD_WAITING_RESET) {
            sendVsimErrorResponse();
        }
        if (getNonSlotMclStatusManager()->getBoolValue(
                RFX_STATUS_KEY_CAPABILITY_SWITCH_URC_CHANNEL, false)) {
            logW(mTag, "[VSIM] Plug out VSIM when switching channel.");
            sBeingPlugOut[m_slot_id] = 1;
            goto done;
        } else {
            setExternalSimProperty(
                    m_slot_id, (char*)"vendor.gsm.external.sim.inserted", (char*)"0");
            cmd.append("AT+ERSA=3");
        }
    } else if (event->eventId == REQUEST_TYPE_SET_PERSIST_TYPE) {
        setExternalSimProperty(m_slot_id, (char*)"persist.vendor.radio.external.sim",
                        (char*)String8::format("%d", event->sim_type).string());
        goto done;
    } else if (event->eventId == REQUEST_TYPE_SET_MAPPING_INFO) {
        if (event->sim_type == SIM_TYPE_REMOTE_SIM) {
            rfx_property_set("vendor.gsm.prefered.rsim.slot",
                             (char*)String8::format("%d", m_slot_id).string());
            goto done;
        } else {
            rfx_property_set("vendor.gsm.prefered.aka.sim.slot",
                             (char*)String8::format("%d", m_slot_id).string());
            cmd.append("AT+ERSIMAKA=1");
        }
    } else if (event->eventId == REQUEST_TYPE_RESET_MAPPING_INFO) {
        if (event->sim_type == SIM_TYPE_REMOTE_SIM) {
            rfx_property_set("vendor.gsm.prefered.rsim.slot", "-1");
        }
        goto done;
    } else if (event->eventId == EVENT_TYPE_SEND_RSIM_AUTH_IND) {
        if (RfxRilUtils::getRsimAuthOngoing(m_slot_id) != 1) {
            // Start to RSIM authenication procedure, we need to occupy RF for AKA-SIM
            setVsimAuthTimeoutDuration();
            cmd.append("AT+ERSIMAUTH=1");
            RfxRilUtils::setRsimAuthOngoing(m_slot_id, 1);
        } else {
            logI(mTag, "[VSIM] RSIM_AUTH_IND when RF is already occupied.");
            goto done;
        }
    } else if (event->eventId == EVENT_TYPE_RECEIVE_RSIM_AUTH_RSP) {
        if (RfxRilUtils::getRsimAuthOngoing(m_slot_id) == 1) {
            // Complete RSIM authenication procedure, we need to release RF for AKA-SIM
            cmd.append("AT+ERSIMAUTH=0");
            RfxRilUtils::setRsimAuthOngoing(m_slot_id, 0);
        } else {
            logI(mTag, "[VSIM] RSIM_AUTH_RSP when RF is already released.");
            goto done;
        }
    } else if (event->eventId == REQUEST_TYPE_SET_TIMEOUT_TIMER) {
        setExternalSimProperty(m_slot_id, (char*)"vendor.gsm.external.sim.timeout",
                        (char*)String8::format("%d", event->sim_type).string());
        goto done;
    } else if (event->eventId == REQUEST_TYPE_SET_PERSIST_TIMEOUT) {
        setExternalSimProperty(m_slot_id, (char*)"persist.vendor.radio.vsim.timeout",
                        (char*)String8::format("%d", event->sim_type).string());
        goto done;
    } else if (event->eventId == EVENT_TYPE_RSIM_AUTH_DONE) {
        rfx_property_set("vendor.gsm.prefered.aka.sim.slot", "-1");
        cmd.append("AT+ERSIMAKA=0");
    } else if (event->eventId == EVENT_TYPE_EXTERNAL_SIM_CONNECTED) {
        rfx_property_set("vendor.gsm.external.sim.connected",
                         String8::format("%d", event->sim_type).string()); //reuse sim_type as connected flag
        if (event->sim_type == 0) {
            handleVsimDisconnected();
        }
        goto done;
    } else {
        logE(mTag, "[VSIM] requestVsimNotification wrong event id.");
        ret = RIL_E_GENERIC_FAILURE;
        goto done;
    }

    if (mdOff == 0 || ((event->eventId == EVENT_TYPE_SEND_RSIM_AUTH_IND) ||
        (event->eventId == EVENT_TYPE_RECEIVE_RSIM_AUTH_RSP))) {

        p_response = atSendCommand(cmd);
        cmd.clear();

        err = p_response->getError();
        if (err < 0) {
            logE(mTag, "[VSIM] requestVsimNotification Fail");
            ret = RIL_E_GENERIC_FAILURE;
            goto done;
        }

        if (0 == p_response->getSuccess()) {
            switch (p_response->atGetCmeError()) {
                logD(mTag, "[VSIM] requestVsimNotification p_response = %d /n",
                        p_response->atGetCmeError());
                default:
                    ret = RIL_E_GENERIC_FAILURE;
                    goto done;
            }
        }
    } else {
        logE(mTag, "[VSIM] requestVsimNotification s_md_off, return error.");
        ret = RIL_E_GENERIC_FAILURE;
        goto done;
    }

done:
    response = RfxMclMessage::obtainResponse(
            msg->getId(), ret,
            RfxVsimEventData((void*)event, sizeof(RIL_VsimEvent)), msg, false);
    responseToTelCore(response);
    logD(mTag, "[VSIM] requestVsimNotification Done");
}

void RmcVsimRequestHandler::handleVsimOperation(const sp<RfxMclMessage>& msg) {
    sp<RfxAtResponse> p_response;
    int err;
    String8 cmd("");
    RIL_Errno ret = RIL_E_SUCCESS;

    RIL_VsimOperationEvent *response = (RIL_VsimOperationEvent *)msg->getData()->getData();
    int datalen = msg->getData()->getDataLength();
    sp<RfxMclMessage> rsp;

    if (RmcCommSimUrcHandler::getMdWaitingResponse(m_slot_id) == VSIM_MD_WAITING_RESET) {
        ret = RIL_E_GENERIC_FAILURE;
        logW(mTag,"[VSIM] requestVsimOperation no urc waiting.");
        goto done;
    }

    if (response->eventId == MSG_ID_UICC_RESET_RESPONSE &&
        RmcCommSimUrcHandler::getMdWaitingResponse(m_slot_id) == VSIM_MD_WAITING_ATR) {
        cmd.append(String8::format("AT+ERSA=1, %d, \"%s\"",
                   ((response->result < 0) ? 0 : 1), response->data));
        RmcCommSimUrcHandler::setMdWaitingResponse(m_slot_id, VSIM_MD_WAITING_RESET);
    } else if (response->eventId == MSG_ID_UICC_APDU_RESPONSE &&
               RmcCommSimUrcHandler::getMdWaitingResponse(m_slot_id) == VSIM_MD_WAITING_APDU) {
        cmd.append(String8::format("AT+ERSA=0, \"%s\"", response->data));
        RmcCommSimUrcHandler::setMdWaitingResponse(m_slot_id, VSIM_MD_WAITING_RESET);
    } else if (response->eventId == MSG_ID_UICC_TEST_MODE_REQUEST) {
        setVerifiedVsimClient(checkIsTestVsimComponent((unsigned char *)response->data,
                strlen(response->data)));
        goto done;
    } else {
        logD(mTag, "[VSIM]requestVsimOperation, eventId not support: %d",
             response->eventId);
        goto done;
    }

    p_response = atSendCommand(cmd);
    cmd.clear();
    err = p_response->getError();
    if (err < 0) {
        logE(mTag, "[VSIM] requestVsimOperation Fail");
        ret = RIL_E_GENERIC_FAILURE;
        goto done;
    }

    if (0 == p_response->getSuccess()) {
        switch (p_response->atGetCmeError()) {
            logE(mTag, "[VSIM] requestVsimOperation p_response = %d /n",
                    p_response->atGetCmeError());
            default:
                ret = RIL_E_GENERIC_FAILURE;
                goto done;
        }
    }

done:
    rsp = RfxMclMessage::obtainResponse(msg->getId(), ret, RfxIntsData(), msg, false);
    responseToTelCore(rsp);
}

void RmcVsimRequestHandler::handleVsimDisconnected() {
    for (int i = 0; i < RfxRilUtils::rfxGetSimCount(); i++) {
        int waiting_response = RmcCommSimUrcHandler::getMdWaitingResponse(i);
        if (waiting_response == VSIM_MD_WAITING_APDU) {
            sendEvent(RFX_MSG_EVENT_SIM_VSIM_SEND_ERROR_RESPONSE, RfxVoidData(), RIL_CMD_PROXY_11,
                      i);
        }
        int auth_ongoing = RfxRilUtils::getRsimAuthOngoing(i);
        int aka_slot = getAkaSimSlot();
        if (auth_ongoing == 1 && i == aka_slot) {
            sendEvent(RFX_MSG_EVENT_VSIM_RELEASE_RF, RfxVoidData(), RIL_CMD_PROXY_11, i);
        }
        logI(mTag, "[VSIM] handleVsimDisconnected sim:%d, aka:%d, waiting:%d, authOngoing:%d", i,
             aka_slot, waiting_response, auth_ongoing);
    }
}

void RmcVsimRequestHandler::sendVsimErrorResponse() {
    RIL_Errno ret = RIL_E_SUCCESS;
    sp<RfxAtResponse> p_response;
    int err;
    String8 cmd("");

    logE(mTag, "[VSIM] sendVsimErrorResponse modem waiting:%d",
         RmcCommSimUrcHandler::getMdWaitingResponse(m_slot_id));

    if (RmcCommSimUrcHandler::getMdWaitingResponse(m_slot_id) == VSIM_MD_WAITING_RESET) {
        ret = RIL_E_GENERIC_FAILURE;
        goto done;
    }
    logE(mTag, "[VSIM]sendVsimErrorResponse2 %d",
         RmcCommSimUrcHandler::getMdWaitingResponse(m_slot_id));

    if (RmcCommSimUrcHandler::getMdWaitingResponse(m_slot_id) == VSIM_MD_WAITING_ATR) {
        cmd.append(String8::format("AT+ERSA=%d, 0, \"0000\"", VSIM_MD_WAITING_ATR));
    } else if (RmcCommSimUrcHandler::getMdWaitingResponse(m_slot_id) == VSIM_MD_WAITING_APDU) {
        cmd.append(String8::format("AT+ERSA=%d,\"0000\"", VSIM_MD_WAITING_APDU));
    } else {
        ret = RIL_E_GENERIC_FAILURE;
        goto done;
    }
    logE(mTag, "[VSIM]sendVsimErrorResponse3");
    RmcCommSimUrcHandler::setMdWaitingResponse(m_slot_id, VSIM_MD_WAITING_RESET);

    p_response = atSendCommand(cmd);
    cmd.clear();
    err = p_response->getError();
    if (err < 0) {
        logE(mTag, "[VSIM] sendVsimErrorResponse Fail");
        ret = RIL_E_GENERIC_FAILURE;
        goto done;
    }

    if (0 == p_response->getSuccess()) {
        switch (p_response->atGetCmeError()) {
            logD(mTag, "[VSIM] sendVsimErrorResponse p_response = %d /n",
                 p_response->atGetCmeError());
            default:
                ret = RIL_E_GENERIC_FAILURE;
                goto done;
        }
    }
done:
    logD(mTag, "[VSIM] sendVsimErrorResponse ret:%d", ret);
}

int RmcVsimRequestHandler::isSingeleRfRemoteSimSupport() {
    char property_value[RFX_PROPERTY_VALUE_MAX] = { 0 };
    rfx_property_get("ro.vendor.mtk_non_dsda_rsim_support", property_value, "0");
    return atoi(property_value);
}

void RmcVsimRequestHandler::setVsimAuthTimeoutDuration() {
    RIL_Errno ret = RIL_E_SUCCESS;
    sp<RfxAtResponse> p_response;
    String8 cmd("");
    char vsim_timeout_prop[RFX_PROPERTY_VALUE_MAX] = {0};
    int err;

    getMSimProperty(m_slot_id, (char*)"vendor.gsm.external.sim.timeout",
            vsim_timeout_prop);

    int timeOut = (isInternalTestVsimComponent() == 1) ? (atoi(vsim_timeout_prop) + 1) : 6;

    /* AT+ERSIMATO  - Sets the RSIM Authentication Time Out value
     * AT+ERSIMATO=<RSIM_Auth_Time_Out>
     *
     * < RSIM_Auth_Time_Out > Integer type: Timer value in seconds
     *
     * success: OK
     * fail: ERROR
     *
     * Timer T with the set value started on AT+ERSIMAUTH = <Start>
     * Expects the AT+ERSIMAUTH = <Finish/Abort> before the expiry of the timer T.
     * If Timer T expired before Finish/Abort then URC +ERSIMAUTH: 0 sent on AKASIM to indicate abort of Auth procedure.
     */
    cmd.append(String8::format("AT+ERSIMATO=%d", timeOut));

    p_response = atSendCommand(cmd);
    cmd.clear();
    err = p_response->getError();

    if (err < 0) {
        logE(mTag, "[VSIM] setVsimAuthTimeoutDuration Fail");
        ret = RIL_E_GENERIC_FAILURE;
        goto done;
    }

    if (0 == p_response->getSuccess()) {
        switch (p_response->atGetCmeError()) {
            logD(mTag, "[VSIM] setVsimAuthTimeoutDuration p_response = %d /n",
                 p_response->atGetCmeError());
            default:
                ret = RIL_E_GENERIC_FAILURE;
                goto done;
        }
    }

done:
    logD(mTag, "[VSIM] sendVsimErrorResponse ret:%d", ret);
}

void RmcVsimRequestHandler::handleVsimAuthRequestEvent(const sp<RfxMclMessage>& msg) {
    char* urc = (char *) msg->getData()->getData();
    String8 ss(urc);
    RIL_VsimOperationEvent event;
    int event_type;
    int err = 0;
    RfxAtLine *pLine = NULL;

    memset(&event, 0, sizeof(event));
    pLine = new RfxAtLine(urc, NULL);
//    logD(mTag, "[VSIM]handleVsimAuthRequestEvent: urc = %s", urc);

    if (strStartsWith(urc, "+ERSAAUTH:")) {
        logD(mTag, "[VSIM]handleVsimAuthRequestEvent: +ERSAAUTH");
        /**
             * [+ERSAATUH URC Command Usage]
             * +ERSAAUTH: <type>, "APDU"
             *
             * <type>:
             * 0 (start authenication procedure)
             */
        pLine->atTokStart(&err);
        logD(mTag, "[VSIM]handleVsimAuthRequestEvent: err %d", err);
        if (err < 0) {
            goto done;
        }
        event_type = pLine->atTokNextint(&err);
        logD(mTag, "[VSIM]handleVsimAuthRequestEvent: err2 %d", err);
        if (err < 0) {
            logE(mTag, "[VSIM]handleVsimAuthRequestEvent get type fail!");
            goto done;
        }

        if (RfxRilUtils::isVsimEnabledBySlot(m_slot_id) == 0 && (event_type == 0)) {
            sendVsimErrorResponse();
            logD(mTag, "[VSIM] handleVsimAuthRequestEvent received URC during vsim disabled.");
            delete(pLine);
            return;
        }
        logD(mTag, "[VSIM]handleVsimAuthRequestEvent: event_type %d", event_type);

        switch (event_type) {
            case 0:
                // Authencation procedure, notify ExternalSimMgr to occupy AKA-SIM's RF
                RfxRilUtils::setRsimAuthOngoing(m_slot_id, 1);
                event.eventId = MSG_ID_UICC_AUTHENTICATION_REQUEST_IND;

                if(pLine->atTokHasmore()){
                    event.data = pLine->atTokNextstr(&err);
                    if(err < 0) goto done;

                    event.data_length = strlen(event.data);
                }
                break;

            default:
                logD(mTag,"[VSIM]handleVsimAuthRequestEvent: +ERSAAUTH unsupport type");
        }
    }

done:
    logD(mTag, "[VSIM]handleVsimAuthRequestEvent: eventId = %d", event.eventId);
    sp<RfxMclMessage> unsol = RfxMclMessage::obtainUrc(RFX_MSG_URC_SIM_VSIM_OPERATION_INDICATION,
                                                       m_slot_id,
                                                       RfxVsimOpIndicationData((void*)&event,
                                                       sizeof(event)));

    responseToTelCore(unsol);
    delete(pLine);
}

void RmcVsimRequestHandler::handleReleaseAkaSim() {
    sp<RfxAtResponse> p_response;
    int err;
    String8 cmd("");
    char akasim_prop[RFX_PROPERTY_VALUE_MAX] = {0};

    rfx_property_get("vendor.gsm.prefered.aka.sim.slot", akasim_prop, "-1");

    if (atoi(akasim_prop) != -1) {
        rfx_property_set("vendor.gsm.prefered.aka.sim.slot", "-1");
        cmd.append("AT+ERSIMAKA=0");

        p_response = atSendCommand(cmd);
        cmd.clear();
        //err = p_response->getError();
    }
}

void RmcVsimRequestHandler::handleReleaseRf() {
    int aka_slot = getAkaSimSlot();
    if (aka_slot == m_slot_id && RfxRilUtils::getRsimAuthOngoing(m_slot_id) == 1) {
        atSendCommand("AT+ERSIMAUTH=0");
        RfxRilUtils::setRsimAuthOngoing(m_slot_id, 0);
    } else {
        logI(mTag, "[VSIM]handleReleaseRf when RF is already released, aka:%d", aka_slot);
    }
}

int RmcVsimRequestHandler::checkIsTestVsimComponent(unsigned char *data, int len) {
    MD5_CTX ctx;
    unsigned char digest[MD5_DIGEST_LENGTH];
    unsigned char *byte_array;
    int rc = 0;
    unsigned char buf[16];
    RSA *pubkey = NULL;
    unsigned char tempBuf[8] = {115,107,121,114,111,97,109,0};
    const char *modulus = "C796C8EBEA5E2D177BD66725A2B980BD45C94B0EDC61A3C4A75719B50571B941356F230C252D76342F247126873E158F6A9573394C2B01B416AADAADAD4060925BCAA1BBD19BDBA417AFB448B877AC6B5C3D8381CCEE9174CB449522FFB639D737E6F75552A186CAF4590CD5179C591371D8ED7E8D35ABC634A23977BE83BD11";

    hexStringToByteArray(data, &byte_array);

    if (len < 256) {
        free(byte_array);
        return 0;
    }
    memcpy(buf, tempBuf, 8);
    memcpy(buf+8, &byte_array[152], 8);
    if ((rc = MD5_Init(&ctx)) != 1) {
        free(byte_array);
        return 0;
    }
    if ((rc = MD5_Update(&ctx, buf, sizeof(buf))) != 1) {
        free(byte_array);
        return 0;
    }
    if ((rc = MD5_Final(digest, &ctx)) != 1) {
        free(byte_array);
        return 0;
    }
    pubkey = RSA_new();
    BN_hex2bn(&pubkey->n, modulus);
    BN_hex2bn(&pubkey->e, "010001");

    if (!RSA_verify(NID_md5, digest, sizeof(digest), byte_array, 128, pubkey)) {
        free (byte_array);
        RSA_free(pubkey);
        return 0;
    }

    free (byte_array);
    RSA_free(pubkey);
    return 1;
}

void RmcVsimRequestHandler::setVerifiedVsimClient(int verified) {
    sVerifiedVsimClient = verified;
}

int RmcVsimRequestHandler::isInternalTestVsimComponent() {
#ifdef __PRODUCTION_RELEASE__
    return sVerifiedVsimClient;
#else
    char vsim_ut_internal[RFX_PROPERTY_VALUE_MAX] = {0};
    rfx_property_get("vendor.gsm.external.sim.internal", vsim_ut_internal, "1");

    RFX_LOG_D("RmcVsimRequest", "isInternalTestVsimComponent: %d, %d", atoi(vsim_ut_internal),
         sVerifiedVsimClient);
    return (atoi(vsim_ut_internal) || sVerifiedVsimClient);
#endif
}

int RmcVsimRequestHandler::getAkaSimSlot() {
    char akasim_prop[RFX_PROPERTY_VALUE_MAX] = {0};

    rfx_property_get("vendor.gsm.prefered.aka.sim.slot", akasim_prop, "-1");
    return atoi(akasim_prop);
}

int RmcVsimRequestHandler::isBeingPlugOut(int slot_id) {
    return sBeingPlugOut[slot_id];
}


// External SIM [End]
