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

#include <telephony/mtk_ril.h>
#include "atchannels.h"
#include "usim_fcp_parser.h"
#include <assert.h>
#include <libmtkrilutils.h>
#include <ril_sim.h>
#include <errno.h>
#include <fcntl.h>
#include <paths.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#include "atchannels.h"
#include "at_tok.h"
#include "misc.h"
#include <sys/ioctl.h>
#include <cutils/properties.h>

#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/md5.h>
#include <openssl/x509.h>

#define LOG_TAG "RIL-SIM"
#define SIM_CHANNEL_CTX getRILChannelCtxFromToken(t)
static const struct timeval TIMEVAL_PIN_SIM = { 0, 100000 };
static const struct timeval TIMEVAL_0 = {0,0};

extern const struct RIL_Env *s_rilenv;
extern int isInitDone;

#define RIL_onRequestComplete(t, e, response, responselen) s_rilenv->OnRequestComplete(t,e, response, responselen)
#define RIL_onUnsolicitedResponse(a,b,c,d) s_rilenv->OnUnsolicitedResponse(a,b,c,d)
#define RIL_requestTimedCallback(a,b,c) s_rilenv->RequestTimedCallback(a,b,c)
#define RIL_requestProxyTimedCallback(a,b,c,d,e) \
        RLOGD("%s request timed callback %s to %s", __FUNCTION__, e, proxyIdToString((int)d)); \
        s_rilenv->RequestProxyTimedCallback(a,b,c,(int)d)

extern const char *proxyIdToString(int id);
extern SIM_Status getSIMStatus(RIL_SOCKET_ID rid);
extern int isVsimEnabledByRid(int rid);
extern int isExternalSimOnlySlot(RIL_SOCKET_ID rid);
extern int isPersistExternalSimDisabled();
extern int setVsimPlugInOutEvent();
extern void bootupGetIccid(RILChannelCtx *p_channel);
extern void flightModeBoot(RILChannelCtx *p_channel);
// Timer callback function for resetting VSIM in initializing flow
void initializeResetVsim(void *param);
// Timer callback function for flight mode boot when VSIM is enabled
void flightModeBootForVsim(void *param);
// Timer callback function for get ICCID when VSIM is enabled
void getIccidWhenVsimEnable(void *param);

int is_rsim_auth_ongoing[MAX_SIM_COUNT] = {0,0,0,0};
int is_md_waiting_rsp[MAX_SIM_COUNT] = {-1,-1,-1,-1};
static int verified_vsim_client = 0;

#define PROPERTY_MODEM_VSIM_CAPABILITYY "vendor.gsm.modem.vsim.capability"
#define MODEM_VSIM_CAPABILITYY_EANBLE 0x01
#define MODEM_VSIM_CAPABILITYY_HOTSWAP 0x02
int modem_vsim_capability[MAX_SIM_COUNT] = {0,0,0,0};

#define VSIM_TRIGGER_RESET      0
#define VSIM_TRIGGER_PLUG_IN    1
#define VSIM_TRIGGER_PLUG_OUT   2

int isNonDsdaRemoteSupport() {
    char property_value[PROPERTY_VALUE_MAX] = { 0 };
    property_get("ro.vendor.mtk_non_dsda_rsim_support", property_value, "0");
    return atoi(property_value);
}

int isSwitchVsimWithHotSwap() {
    int supported = 0;
    for (int rid = 0; rid < MAX_SIM_COUNT; rid++) {
        supported = modem_vsim_capability[rid] & MODEM_VSIM_CAPABILITYY_HOTSWAP;
        if (supported != 0) break;
    }

    return supported;
}

void setRsimAuthOngoing(int rid, int ongoing)
{
    is_rsim_auth_ongoing[rid] = ongoing;
    LOGD("[VSIM] setRsimAuthOngoing rid:%d is %d.", rid, is_rsim_auth_ongoing[rid]);
}

// -1: not waiting
// 0: waiting APDU response
// 1: waiting ATR response
void setMdWaitingResponse(int rid, int waiting)
{
    is_md_waiting_rsp[rid] = waiting;
    LOGD("[VSIM] setMdWaitingResponse rid:%d is %d.", rid, is_md_waiting_rsp[rid]);
}

int checkIsTestVsimComponent(unsigned char *data, int len) {
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

int isInternalTestVsimComponent() {
#ifdef __PRODUCTION_RELEASE__
    return verified_vsim_client;
#else
    char vsim_ut_internal[PROPERTY_VALUE_MAX] = {0};
    property_get("vendor.gsm.external.sim.internal", vsim_ut_internal, "1");

    LOGD("[VSIM] isInternalTestVsimComponent: %d, %d", atoi(vsim_ut_internal), verified_vsim_client);
    return (atoi(vsim_ut_internal) || verified_vsim_client);
#endif
}

void requestSetAkaSim(RIL_SOCKET_ID rid)
{
    ATResponse *p_response = NULL;
    int err, ret;
    char *cmd = NULL;
    char vsim_enabled_prop[PROPERTY_VALUE_MAX] = {0};
    char vsim_inserted_prop[PROPERTY_VALUE_MAX] = {0};
    char persist_vsim_inserted_prop[PROPERTY_VALUE_MAX] = {0};
    char rsim_prop[PROPERTY_VALUE_MAX] = {0};
    char akasim_prop[PROPERTY_VALUE_MAX] = {0};

    property_get("vendor.gsm.prefered.rsim.slot", rsim_prop, "-1");
    property_get("vendor.gsm.prefered.aka.sim.slot", akasim_prop, "-1");

    if (atoi(rsim_prop) == -1 || atoi(akasim_prop) != rid) {
        LOGE("[VSIM] requestSetAkaSim rsim=%d, aka-sim=%d", atoi(rsim_prop), atoi(akasim_prop));
        return;
    }

    /* If rsim enabled, then should set aka sim protocol in case of it haven't be disabled. */
    if (atoi(akasim_prop) >= 0) {
        asprintf(&cmd, "AT+ERSIMAKA=1");
        err = at_send_command(cmd, &p_response, getChannelCtxbyProxy(rid));
        free(cmd);

        if (err < 0 || NULL == p_response) {
            LOGE("[VSIM] requestSetAkaSim Fail");
            ret = RIL_E_GENERIC_FAILURE;
            goto done;
        }

        if (0 == p_response->success) {
            switch (at_get_cme_error(p_response)) {
                LOGD("[VSIM] requestSetAkaSim p_response = %d /n", at_get_cme_error(p_response) );
                default:
                    ret = RIL_E_GENERIC_FAILURE;
                    goto done;
            }
        }
    }

done:
    at_response_free(p_response);
}

void requestSwitchExternalSim(RIL_SOCKET_ID rid)
{
    ATResponse *p_response = NULL;
    int err, ret;
    char *cmd = NULL;
    char vsim_enabled_prop[PROPERTY_VALUE_MAX] = {0};
    char vsim_inserted_prop[PROPERTY_VALUE_MAX] = {0};
    char persist_vsim_inserted_prop[PROPERTY_VALUE_MAX] = {0};
    char rsim_prop[PROPERTY_VALUE_MAX] = {0};

    getMSimProperty(rid, "vendor.gsm.external.sim.enabled", vsim_enabled_prop);
    getMSimProperty(rid, "vendor.gsm.external.sim.inserted", vsim_inserted_prop);
    property_get("vendor.gsm.prefered.rsim.slot", rsim_prop, "-1");

    if (isPersistExternalSimDisabled()) {
        property_set("persist.vendor.radio.external.sim", "");
    } else {
        getMSimProperty(rid, "persist.vendor.radio.external.sim", persist_vsim_inserted_prop);
    }

    if (atoi(persist_vsim_inserted_prop) > 0) {
        LOGD("[VSIM] persist.vendor.radio.external.sim is 1.");
    }

    /* When to set true and when to set false ? */
    if (atoi(vsim_enabled_prop) > 0 && atoi(vsim_inserted_prop) > 0) {
        // Mean VSIM enabled and modem reset only rild reset case,
        // should recover to previous status
        if (atoi(rsim_prop) >= 0 && atoi(rsim_prop) == rid) {
            asprintf(&cmd, "AT+ERSIM");
        } else if (isExternalSimOnlySlot(rid) > 0) {
            asprintf(&cmd, "AT+EAPVSIM=1,1");
        } else {
            asprintf(&cmd, "AT+EAPVSIM=1");
        }
    } else {
        // Might reboot or VSIM did't be enabled
        if (atoi(persist_vsim_inserted_prop) > 0 && !isNonDsdaRemoteSupport()) {
            // Case 1. Device reboot and VSIM enabled before reboot. Keep slot to VSIM only.
            asprintf(&cmd, "AT+EAPVSIM=1,0");
            LOGD("[VSIM] Case 1. Device reboot and VSIM enabled before reboot. Keep slot to VSIM only.");
        } else if (isExternalSimOnlySlot(rid) > 0 && !isNonDsdaRemoteSupport()) {
            // Case 2. Device reboot and the slot has been set to VSIM only in configuration.
            asprintf(&cmd, "AT+EAPVSIM=1,0");
            LOGD("[VSIM] Case 2. Device reboot and the slot has been set to VSIM only in configuration.");
        } else {
            // Case 3. Others. VSIM disabled and it is not VSIM only protocol.
            asprintf(&cmd, "AT+EAPVSIM=0");
        }
    }
    err = at_send_command(cmd, &p_response, getChannelCtxbyProxy(rid));
    free(cmd);

    if (err < 0 || NULL == p_response) {
        LOGE("[VSIM] requestSwitchExternalSim Fail");
        ret = RIL_E_GENERIC_FAILURE;
        goto done;
    }

    if (0 == p_response->success) {
        switch (at_get_cme_error(p_response)) {
            LOGD("[VSIM] requestSwitchExternalSim p_response = %d /n", at_get_cme_error(p_response) );
            default:
                ret = RIL_E_GENERIC_FAILURE;
                goto done;
        }
    }

done:
    at_response_free(p_response);
    LOGE("[VSIM] requestSwitchExternalSim Done");
}


typedef struct {
    int rid;
    RILChannelId cid;
    int eventId;
    char* urc;
} VsimTimedCallbackParam;


void sendVsimErrorResponse(void *param) {
    ATResponse *p_response = NULL;
    int err, ret;
    int enabled = 0;
    char *line, *cmd;

    VsimTimedCallbackParam *data = (VsimTimedCallbackParam *) param;

    if (is_md_waiting_rsp[data->rid] == -1) {
        ret = RIL_E_SUCCESS;
        LOGI("[VSIM] sendVsimErrorResponse no urc waiting.");
        goto done;
    }

    if (data->eventId == 1) {
        // ATR response need one more paramenter to told result successful or not.
        asprintf(&cmd, "AT+ERSA=%d, 0, \"0000\"", data->eventId);
    } else {
        asprintf(&cmd, "AT+ERSA=%d,\"0000\"", data->eventId);
    }

    setMdWaitingResponse(data->rid, -1);

    // VSIM use the call channel.
    err = at_send_command(cmd, &p_response, getChannelCtxbyProxy((RIL_SOCKET_ID)(data->rid)));
    free(cmd);

    if (err < 0 || NULL == p_response) {
        LOGE("[VSIM] sendVsimErrorResponse Fail");
        ret = RIL_E_GENERIC_FAILURE;
        goto done;
    }

    if (0 == p_response->success) {
        switch (at_get_cme_error(p_response)) {
            LOGD("[VSIM] sendVsimErrorResponse p_response = %d /n", at_get_cme_error(p_response) );
            default:
                ret = RIL_E_GENERIC_FAILURE;
                goto done;
        }
    }

done:
    if (data->urc != NULL) {
        free(data->urc);
    }
    free(data);

    at_response_free(p_response);
}

void sendVsimErrorResponseByToken(int eventId, RIL_Token t) {
    ATResponse *p_response = NULL;
    int err, ret;
    int enabled = 0;
    RIL_SOCKET_ID rid = getRILIdByChannelCtx(getRILChannelCtxFromToken(t));
    char *line, *cmd;

    if (is_md_waiting_rsp[rid] == -1) {
        ret = RIL_E_SUCCESS;
        LOGI("[VSIM] sendVsimErrorResponseByToken no urc waiting.");
        goto done;
    }

    if (eventId) {
        // ATR response need one more paramenter to told result successful or not.
        asprintf(&cmd, "AT+ERSA=%d, 0, \"0000\"", eventId);
    } else {
        asprintf(&cmd, "AT+ERSA=%d,\"0000\"", eventId);
    }

    setMdWaitingResponse(rid, -1);

    err = at_send_command(cmd, &p_response, SIM_CHANNEL_CTX);
    free(cmd);

    if (err < 0 || NULL == p_response) {
        LOGE("[VSIM] sendVsimErrorResponseByToken Fail");
        ret = RIL_E_GENERIC_FAILURE;
        goto done;
    }

    if (0 == p_response->success) {
        switch (at_get_cme_error(p_response)) {
            LOGD("[VSIM] sendVsimErrorResponseByToken p_response = %d /n", at_get_cme_error(p_response) );
            default:
                ret = RIL_E_GENERIC_FAILURE;
                goto done;
        }
    }

done:
    at_response_free(p_response);
}

int queryVsimRadioBearer(void *param)
{
    ATResponse *p_response = NULL;
    int err;
    int speed = 0, enabled = 0;
    char *line, *cmd;
    VsimTimedCallbackParam *data = (VsimTimedCallbackParam *) param;

    /* Query if the radio bearer has been enabled.
     * TODO: should be removed in the further
     * AT+PSBEARER?
     * success: +PSBEARER:<cell_data_speed_support>,<max_data_bearer_capability>
     * fail: ERROR
     */

    asprintf(&cmd, "AT+PSBEARER?");

    err = at_send_command_singleline(
            cmd, "+PSBEARER:", &p_response, getChannelCtxbyProxy((RIL_SOCKET_ID)(data->rid)));
    free(cmd);
    if (err < 0 || NULL == p_response) {
        LOGE("queryVsimRadioBearer fail");
         goto done;
    }

    switch (at_get_cme_error(p_response)) {
        LOGD("p_response = %d /n", at_get_cme_error(p_response) );
        case CME_SUCCESS:
            if (err < 0 || p_response->success == 0) {
                goto done;
            } else {
                line = p_response->p_intermediates->line;

                err = at_tok_start(&line);
                if(err < 0) goto done;

                err = at_tok_nextint(&line, &speed);
                if(err < 0) goto done;

                err = at_tok_nextint(&line, &enabled);
                if(err < 0) goto done;

                at_response_free(p_response);
                p_response = NULL;
            }
            break;
        case CME_UNKNOWN:
            LOGD("queryVsimRadioBearer p_response: CME_UNKNOWN");
            break;
        default:
            LOGD("queryVsimRadioBearer fail");
    }

done:
    enabled = 0;
    LOGD("queryVsimRadioBearer done, enabled: %d", enabled);
    if (NULL != p_response) {
        at_response_free(p_response);
    }

    return enabled;
}

void setVsimAuthTimeoutDuration(RIL_Token t) {
    ATResponse *p_response = NULL;
    int err, ret;
    int enabled = 0;
    char *line, *cmd;
    RIL_SOCKET_ID rid = getRILIdByChannelCtx(getRILChannelCtxFromToken(t));

    char vsim_timeout_prop[PROPERTY_VALUE_MAX] = {0};
    getMSimProperty(rid, "vendor.gsm.external.sim.timeout", vsim_timeout_prop);

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
    asprintf(&cmd, "AT+ERSIMATO=%d", timeOut);

    err = at_send_command(cmd, &p_response, SIM_CHANNEL_CTX);
    free(cmd);

    if (err < 0 || NULL == p_response) {
        LOGE("[VSIM] setVsimAuthTimeoutDuration Fail");
        ret = RIL_E_GENERIC_FAILURE;
        goto done;
    }

    if (0 == p_response->success) {
        switch (at_get_cme_error(p_response)) {
            LOGD("[VSIM] setVsimAuthTimeoutDuration p_response = %d /n", at_get_cme_error(p_response) );
            default:
                ret = RIL_E_GENERIC_FAILURE;
                goto done;
        }
    }

done:
    at_response_free(p_response);
}

void handleVsimAuthRequestEvent (void *param) {
    RIL_VsimOperationEvent event;
    int event_type;
    memset(&event, 0, sizeof(event));

    VsimTimedCallbackParam *data = (VsimTimedCallbackParam *) param;
    char* line = (char*)data->urc;

    if (queryVsimRadioBearer(data) > 0) {
        sendVsimErrorResponse(data);
        LOGD("[VSIM]handleVsimAuthRequestEvent: sendVsimErrorResponse");
        return;
    } else {
        if (strStartsWith(data->urc, "+ERSAAUTH:")) {
            /**
             * [+ERSAATUH URC Command Usage]
             * +ERSAAUTH: <type>, "APDU"
             *
             * <type>:
             * 0 (start authenication procedure)
             */

            if (at_tok_start(&line) < 0) {
                goto done;
            }

            if (at_tok_nextint(&line, &event_type) < 0) {
                RLOGE("[VSIM]handleVsimAuthRequestEvent get type fail!");
                goto done;
            }

            if (isVsimEnabledByRid(data->rid) == 0 && (event_type == 0)) {
                VsimTimedCallbackParam* errorParam = (VsimTimedCallbackParam *)calloc(1, sizeof(VsimTimedCallbackParam));
                errorParam->rid = data->rid;
                errorParam->cid = getRILChannelId(RIL_NW, data->rid);
                errorParam->eventId = event_type;
                errorParam->urc = NULL;
                RIL_requestProxyTimedCallback(sendVsimErrorResponse, (void *)errorParam, &TIMEVAL_PIN_SIM,
                        errorParam->cid, "sendVsimErrorResponse");

                free(data->urc);
                free(data);

                LOGD("[VSIM] handleVsimAuthRequestEvent received URC during vsim disabled.");
                return;
            }

            switch (event_type) {
                case 0:
                    // Authencation procedure, notify ExternalSimMgr to occupy AKA-SIM's RF
                    setRsimAuthOngoing(data->rid, 1);
                    event.eventId = MSG_ID_UICC_AUTHENTICATION_REQUEST_IND;

                    if (at_tok_hasmore(&line)) {
                        if (at_tok_nextstr(&line, &event.data) < 0) {
                            RLOGE("[VSIM]handleVsimAuthRequestEvent get string fail!");
                            goto done;
                        }

                        //event.data = (uint8_t *) calloc(1, ((sizeof(uint8_t) * event.data_length) / 2));
                        event.data_length = strlen(event.data);
                    }
                    break;

                default:
                    LOGD("[VSIM]handleVsimAuthRequestEvent: +ERSAAUTH unsupport type");
            }
        }
    }

done:
    //LOGD("[VSIM]handleVsimAuthRequestEvent: eventId = %d, temp_data = %s", event.eventId, temp_data);
    RIL_UNSOL_RESPONSE(RIL_UNSOL_VSIM_OPERATION_INDICATION, &event, sizeof(event), data->rid);

    free(data->urc);
    free(data);

}

void handleReleaseAkaSim (void *param) {
    ATResponse *p_response = NULL;
    int err;
    char *cmd = NULL;
    char akasim_prop[PROPERTY_VALUE_MAX] = {0};

    VsimTimedCallbackParam *data = (VsimTimedCallbackParam *) param;

    property_get("vendor.gsm.prefered.aka.sim.slot", akasim_prop, "-1");

    if (atoi(akasim_prop) != -1) {
        property_set("vendor.gsm.prefered.aka.sim.slot", "-1");

        asprintf(&cmd, "AT+ERSIMAKA=0");
        err = at_send_command(cmd, &p_response, getChannelCtxbyProxy((RIL_SOCKET_ID)(data->rid)));
        free(cmd);

        at_response_free(p_response);
    }
}

void onVsimEventDetected(const char *s, RIL_SOCKET_ID rid) {
    RIL_VsimOperationEvent event;
    int event_type;
    char* line = (char*)s;
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
     */

    if (at_tok_start(&line) < 0) {
        goto done;
    }

    if (at_tok_nextint(&line, &event_type) < 0) {
        RLOGE("[VSIM]onVsimEventDetected get type fail!");
        goto done;
    }

    if (isVsimEnabledByRid(rid) == 0 && (event_type == 0 || event_type == 1)) {
        setMdWaitingResponse(rid, event_type);
        VsimTimedCallbackParam* param = (VsimTimedCallbackParam *)calloc(1, sizeof(VsimTimedCallbackParam));
        param->rid = rid;
        param->cid = getRILChannelId(RIL_NW, rid);
        param->eventId = event_type;
        param->urc = NULL;
        RIL_requestProxyTimedCallback(sendVsimErrorResponse, (void *)param, &TIMEVAL_PIN_SIM,
                param->cid, "sendVsimErrorResponse");
        LOGD("[VSIM] onVsimEventDetected received URC during vsim disabled.");
        return;
    }

    switch (event_type) {
        case 0:
            event.eventId = MSG_ID_UICC_APDU_REQUEST; //REQUEST_TYPE_APDU_EVENT;

            if (at_tok_hasmore(&line)) {
                if (at_tok_nextstr(&line, &event.data) < 0) {
                    RLOGE("[VSIM]onVsimEventDetected get string fail!");
                    goto done;
                }

                event.data_length = strlen(event.data);
            }
            setMdWaitingResponse(rid, 0);
            break;
        case 1:
            LOGD("[VSIM]onVsimEventDetected: card reset request");
            event.eventId = MSG_ID_UICC_RESET_REQUEST; //REQUEST_TYPE_ATR_EVENT;
            setMdWaitingResponse(rid, 1);
            verified_vsim_client = 0;
            break;
        case 2:
            LOGD("[VSIM]onVsimEventDetected: card power down");
            return; // TODO: should sent to upper layer
            /*event.eventId = REQUEST_TYPE_CARD_POWER_DOWN;
            event.result = 0;   //Use result filed to record mode information
            if (at_tok_hasmore(&line)) {
                 if (at_tok_nextint(&line, &event.result) < 0) {
                     RLOGE("[VSIM]onVsimEventDetected get power down mode fail!");
                     goto done;
                 }
            }
            break;*/
        case 3:
            LOGD("[VSIM]onVsimEventDetected: VSIM_TRIGGER_PLUG_OUT");
            setVsimPlugInOutEvent(rid, VSIM_TRIGGER_PLUG_OUT);
            return;
        case 4:
            LOGD("[VSIM]onVsimEventDetected: VSIM_TRIGGER_PLUG_IN");
            setVsimPlugInOutEvent(rid, VSIM_TRIGGER_PLUG_IN);
            return;
        default:
            LOGD("[VSIM]onVsimEventDetected: unsupport type");
    }

done:
    RIL_UNSOL_RESPONSE(RIL_UNSOL_VSIM_OPERATION_INDICATION, &event, sizeof(event), rid);
}

void onVsimAuthEventDetected (const char *s, RIL_SOCKET_ID rid) {
    // In case of receving +ERSAAUTH event, we need to occupy RF in AKA-SIM slot. (stack 2 in modem)
    RIL_VsimOperationEvent event;
    int event_type = 0;
    char* line = (char*)s;
    memset(&event, 0, sizeof(event));
    int slotId = rid;
    char rsim_prop[PROPERTY_VALUE_MAX] = {0};
    char akasim_prop[PROPERTY_VALUE_MAX] = {0};

    if (strStartsWith(s, "+ERSAAUTH:")) {
        setMdWaitingResponse(rid, 0);
        VsimTimedCallbackParam* param = (VsimTimedCallbackParam *)calloc(1, sizeof(VsimTimedCallbackParam));
        param->rid = rid;
        param->cid = getRILChannelId(RIL_CC, rid);
        param->eventId = event_type;
        asprintf(&param->urc, "%s", s);

        RIL_requestProxyTimedCallback(handleVsimAuthRequestEvent, (void *)param, &TIMEVAL_PIN_SIM,
                param->cid, "handleVsimAuthRequestEvent");
        return ;
    } else if (strStartsWith(s, "+ERSIMAUTH:")) {

        /**
         * [+ERSIMAUTH URC Command Usage]
         * +ERSAAUTH: <type>
         *
         * <type>:
         * 0 (abort authenication procedure)
         * 1 (complete authenication procedure)
         */

        if (at_tok_start(&line) < 0) {
            goto done;
        }

        if (at_tok_nextint(&line, &event_type) < 0) {
            RLOGE("[VSIM]handleVsimAuthAckEvent get type fail!");
            goto done;
        }

        switch (event_type) {
            case 0:
                // Abort authenication, send notify to Jave layer directly
                LOGD("[VSIM]handleVsimAuthAckEvent: auth abort");
                property_get("vendor.gsm.prefered.rsim.slot", rsim_prop, "-1");

                if (atoi(rsim_prop) == -1) {
                    goto done;
                }
                slotId = atoi(rsim_prop);

                setRsimAuthOngoing(rid, 0);
                setRsimAuthOngoing(slotId, 0);
                event.eventId = MSG_ID_UICC_AUTHENTICATION_ABORT_IND;
                break;
            case 1:
                // Complete authenication, send notify to Jave layer directly
                LOGD("[VSIM]handleVsimAuthAckEvent: auth abort");
                setRsimAuthOngoing(rid, 0);
                event.eventId = MSG_ID_UICC_AUTHENTICATION_DONE_IND;
                break;
            default:
                LOGD("[VSIM]handleVsimAuthAckEvent: +ERSIMAUTH: unsupport type");
        }

        if (isInternalTestVsimComponent() == 0) {
            // Release AKA SIM stack
            VsimTimedCallbackParam* param = (VsimTimedCallbackParam *)calloc(1, sizeof(VsimTimedCallbackParam));
            property_get("vendor.gsm.prefered.aka.sim.slot", akasim_prop, "-1");

            if (atoi(akasim_prop) == -1) {
                goto done;
            }

            param->rid = atoi(akasim_prop);
            param->cid = getRILChannelId(RIL_CC, param->rid);
            param->eventId = event_type;
            param->urc = NULL;

            RIL_requestProxyTimedCallback(handleReleaseAkaSim, (void *)param, &TIMEVAL_PIN_SIM,
                    param->cid, "handleReleaseAkaSim");
        }
    }

done:
    //LOGD("[VSIM]onVsimAuthEventDetected: eventId = %d, temp_data = %s", event.eventId, temp_data);
    RIL_UNSOL_RESPONSE(RIL_UNSOL_VSIM_OPERATION_INDICATION, &event, sizeof(event), slotId);
}

int queryModemVsimCapability(RIL_SOCKET_ID rid)
{
    ATResponse *p_response = NULL;
    int err;
    int capability = 0;
    char *line, *cmd;

    /**
     * Query if the VSIM has been enabled
     * AT+EAPVSIM?
     * success: +EAPVSIM: <capability and status>
     *          APVSIM Capability or Status Query (bit mask)
     *          0x01 : APVSIM ON/OFF status
     *          0x02 : APVSIM Support enable/disable via Hot Swap Mechanism
     * fail: ERROR
     *
     */

    asprintf(&cmd, "AT+EAPVSIM?");

    err = at_send_command_singleline(cmd, "+EAPVSIM:", &p_response, getChannelCtxbyProxy(rid));
    free(cmd);
    if (err < 0 || NULL == p_response) {
        LOGE("queryModemVsimCapability fail");
         goto done;
    }

    switch (at_get_cme_error(p_response)) {
        LOGD("p_response = %d /n", at_get_cme_error(p_response) );
        case CME_SUCCESS:
            if (err < 0 || p_response->success == 0) {
                goto done;
            } else {
                line = p_response->p_intermediates->line;

                err = at_tok_start(&line);
                if(err < 0) goto done;

                err = at_tok_nextint(&line, &modem_vsim_capability[rid]);
                if(err < 0) goto done;

                at_response_free(p_response);
                p_response = NULL;
            }
            break;
        case CME_UNKNOWN:
            LOGD("queryModemVsimCapability p_response: CME_UNKNOWN");
            break;
        default:
            LOGD("queryModemVsimCapability fail");
    }

done:
    LOGD("queryModemVsimCapability done, capability: %d", modem_vsim_capability[rid]);
    if (NULL != p_response) {
        at_response_free(p_response);
    }

    asprintf(&cmd, "%d", modem_vsim_capability[rid]);
    setExternalSimProperty(rid, PROPERTY_MODEM_VSIM_CAPABILITYY, cmd);
    free(cmd);

    return modem_vsim_capability[rid];
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
 *       <parameter1>: apdu_status // failure or success, 1: success, 0: failure
 *       <parameter2>: ATR // (string)
 * 2 (event: card error)
 *       <parameter1>: error cause // Not define the error code yet, currently MD only handle driver's hot swap signal (recovery is trigger by Status Word)
 * 3 (event: card hot swap out)
 * 4 (event: card hot swap in)
 */
void requestVsimNotification(void *data, size_t datalen, RIL_Token t) {

    ATResponse *p_response = NULL;
    int err;
    char *cmd = NULL;
    RIL_Errno ret = RIL_E_SUCCESS;
    RIL_VsimEvent *event = (RIL_VsimEvent *)data;
    RIL_SOCKET_ID rid = getRILIdByChannelCtx(getRILChannelCtxFromToken(t));
    SIM_Status sim_status = SIM_ABSENT;

    RLOGD("[VSIM]requestVsimNotification, event_Id: %d, sim_type: %d", event->eventId, event->sim_type);

    // Check if any not response URC, if so send error response first.
    if (is_md_waiting_rsp[rid] != -1) {
        if (event->eventId == REQUEST_TYPE_ENABLE_EXTERNAL_SIM ||
            event->eventId == REQUEST_TYPE_PLUG_IN) {
            sendVsimErrorResponseByToken(is_md_waiting_rsp[rid], t);
        }
    }

    if (event->eventId == REQUEST_TYPE_ENABLE_EXTERNAL_SIM) {
        setExternalSimProperty(rid, "vendor.gsm.external.sim.enabled", "1");
        if (isNonDsdaRemoteSupport()) {
            if (event->sim_type == SIM_TYPE_REMOTE_SIM) {
                char property[PROPERTY_VALUE_MAX] = {0};
                sprintf(property, "%d", rid);
                property_set("vendor.gsm.prefered.rsim.slot", property);
            }
            int count = 0;
            do{
                sim_status = getSIMStatus(rid);
                if (SIM_BUSY == sim_status )
                {
                    sleepMsec(200);
                    count++;
                }
            } while((SIM_BUSY == sim_status) && count < 10);

            asprintf(&cmd, "AT+EAPVSIM=1,0,1");
        } else if (isSwitchVsimWithHotSwap()) {
            int count = 0;
            do{
                sim_status = getSIMStatus(rid);
                if (SIM_BUSY == sim_status )
                {
                    sleepMsec(200);
                    count++;
                }
            } while((SIM_BUSY == sim_status) && count < 10);

            asprintf(&cmd, "AT+EAPVSIM=1,1");
        } else {
            RIL_onRequestComplete(t, ret, event, sizeof(RIL_VsimEvent));
            return;
        }
    } else if (event->eventId == REQUEST_TYPE_DISABLE_EXTERNAL_SIM) {
        setExternalSimProperty(rid, "vendor.gsm.external.sim.enabled", "0");
        setExternalSimProperty(rid, "vendor.gsm.external.sim.inserted", "0");
        setExternalSimProperty(rid, "persist.vendor.radio.external.sim", "0");
        setExternalSimProperty(rid, "persist.vendor.radio.vsim.timeout", "");
        char property[PROPERTY_VALUE_MAX] = {0};
        property_get("vendor.gsm.prefered.aka.sim.slot", property, "-1");
        if (atoi(property) == rid) {
            property_set("vendor.gsm.prefered.aka.sim.slot", "-1");
        }
        memset(property, 0, sizeof(property));
        property_get("vendor.gsm.prefered.rsim.slot", property, "-1");
        if (atoi(property) == rid) {
            property_set("vendor.gsm.prefered.rsim.slot", "-1");
        }
        if (is_md_waiting_rsp[rid] != -1) {
            sendVsimErrorResponseByToken(is_md_waiting_rsp[rid], t);
        }

        if (isNonDsdaRemoteSupport()) {
            // Modem SIM hot plug limitation, it need to wait for get non-BUSY sim state to trigger
            // AP VSIM hot plug command.
            int count = 0;
            do{
                sim_status = getSIMStatus(rid);
                if (SIM_BUSY == sim_status )
                {
                    sleepMsec(200);
                    count++;
                }
            } while((SIM_BUSY == sim_status) && count < 10);

            if (isExternalSimOnlySlot(rid) > 0 && !isNonDsdaRemoteSupport()) {
                asprintf(&cmd, "AT+EAPVSIM=1,0,1");
            } else {
                asprintf(&cmd, "AT+EAPVSIM=0,0,1");
            }
        } else if (isSwitchVsimWithHotSwap()) {
            asprintf(&cmd, "AT+EAPVSIM=0");
        } else {
            RIL_onRequestComplete(t, ret, event, sizeof(RIL_VsimEvent));
            return;
        }
    } else if (event->eventId == REQUEST_TYPE_PLUG_IN) {
        char property[PROPERTY_VALUE_MAX] = {0};
        getMSimProperty(rid, (char*)"vendor.gsm.external.sim.enabled", property);
        if (atoi(property) != 0) {
            memset(property, 0, sizeof(property));
            sprintf(property, "%d", event->sim_type);
            setExternalSimProperty(rid, "vendor.gsm.external.sim.inserted", property);
        }
        if (isNonDsdaRemoteSupport()) {
            // Modem SIM hot plug limitation, it need to wait for get non-BUSY sim state to trigger
            // AP VSIM hot plug command.
            int count = 0;
            do{
                sim_status = getSIMStatus(rid);
                if (SIM_BUSY == sim_status )
                {
                    sleepMsec(200);
                    count++;
                }
            } while((SIM_BUSY == sim_status) && count < 10);

            // TODO: Need to radio off other protocols
            if (event->sim_type == SIM_TYPE_LOCAL_SIM) {
                asprintf(&cmd, "AT+EAPVSIM=1,1,1");
            } else if (event->sim_type == SIM_TYPE_REMOTE_SIM) {
                asprintf(&cmd, "AT+ERSIM");
            }
        } else {
            asprintf(&cmd, "AT+ERSA=4");
        }
    } else if (event->eventId == REQUEST_TYPE_PLUG_OUT) {
        setExternalSimProperty(rid, "vendor.gsm.external.sim.inserted", "0");
        if (is_md_waiting_rsp[rid] != -1) {
            sendVsimErrorResponseByToken(is_md_waiting_rsp[rid], t);
        }
        asprintf(&cmd, "AT+ERSA=3");
    } else if (event->eventId == REQUEST_TYPE_SET_PERSIST_TYPE) {
        char property[PROPERTY_VALUE_MAX] = {0};
        sprintf(property, "%d", event->sim_type);
        setExternalSimProperty(rid, "persist.vendor.radio.external.sim", property);
        goto done;
    } else if (event->eventId == REQUEST_TYPE_SET_MAPPING_INFO) {
        char property[PROPERTY_VALUE_MAX] = {0};
        sprintf(property, "%d", rid);
        if (event->sim_type == SIM_TYPE_REMOTE_SIM) {
            property_set("vendor.gsm.prefered.rsim.slot", property);
            goto done;
        } else {
            property_set("vendor.gsm.prefered.aka.sim.slot", property);
            asprintf(&cmd, "AT+ERSIMAKA=1");
        }
    } else if (event->eventId == REQUEST_TYPE_RESET_MAPPING_INFO) {
        if (event->sim_type == SIM_TYPE_REMOTE_SIM) {
            property_set("vendor.gsm.prefered.rsim.slot", "-1");
        }
        goto done;
    } else if (event->eventId == REQUEST_TYPE_SET_TIMEOUT_TIMER) {
        char property[PROPERTY_VALUE_MAX] = {0};
        sprintf(property, "%d", event->sim_type);
        setExternalSimProperty(rid, "vendor.gsm.external.sim.timeout", property);
        goto done;
    } else if (event->eventId == REQUEST_TYPE_SET_PERSIST_TIMEOUT) {
        char property[PROPERTY_VALUE_MAX] = {0};
        sprintf(property, "%d", event->sim_type);
        setExternalSimProperty(rid, "persist.vendor.radio.vsim.timeout", property);
        goto done;
    } else if (event->eventId == EVENT_TYPE_SEND_RSIM_AUTH_IND) {
        // Start to RSIM authenication procedure, we need to occupy RF for AKA-SIM
        setVsimAuthTimeoutDuration(t);
        asprintf(&cmd, "AT+ERSIMAUTH=1");
        setRsimAuthOngoing(rid, 1);
    } else if (event->eventId == EVENT_TYPE_RECEIVE_RSIM_AUTH_RSP) {
        // Complete RSIM authenication procedure, we need to release RF for AKA-SIM
        asprintf(&cmd, "AT+ERSIMAUTH=0");
        setRsimAuthOngoing(rid, 0);
    } else if (event->eventId == EVENT_TYPE_RSIM_AUTH_DONE) {
        property_set("vendor.gsm.prefered.aka.sim.slot", "-1");
        asprintf(&cmd, "AT+ERSIMAKA=0");
    } else if (event->eventId == EVENT_TYPE_EXTERNAL_SIM_CONNECTED) {
        char property[PROPERTY_VALUE_MAX] = {0};
        sprintf(property, "%d", event->sim_type); // reuse sim_type as connected flag
        property_set("vendor.gsm.external.sim.connected", property);
        goto done;
    } else {
        LOGE("[VSIM] requestVsimNotification wrong event id.");
        ret = RIL_E_GENERIC_FAILURE;
        goto done;
    }

    if (s_md_off == 0 || ((event->eventId == EVENT_TYPE_SEND_RSIM_AUTH_IND) ||
        (event->eventId == EVENT_TYPE_RECEIVE_RSIM_AUTH_RSP))) {

        err = at_send_command(cmd, &p_response, SIM_CHANNEL_CTX);
        free(cmd);

        if (err < 0 || NULL == p_response) {
            LOGE("[VSIM] requestVsimNotification Fail");
            ret = RIL_E_GENERIC_FAILURE;
            goto done;
        }

        if (0 == p_response->success) {
            switch (at_get_cme_error(p_response)) {
                default:
                    ret = RIL_E_GENERIC_FAILURE;
                    goto done;
            }
        }
    } else {
        free(cmd);
        LOGE("[VSIM] requestVsimNotification s_md_off, return error.");
        ret = RIL_E_GENERIC_FAILURE;
        goto done;
    }

done:
    RIL_onRequestComplete(t, ret, event, sizeof(RIL_VsimEvent));
    at_response_free(p_response);
}

void requestVsimOperation(void *data, size_t datalen, RIL_Token t) {
    ATResponse *p_response = NULL;
    int err;
    char *cmd = NULL;
    RIL_SOCKET_ID rid = getRILIdByChannelCtx(getRILChannelCtxFromToken(t));
    RIL_Errno ret = RIL_E_SUCCESS;

    RIL_VsimOperationEvent *response = (RIL_VsimOperationEvent *)data;

    if (is_md_waiting_rsp[rid] == -1) {
        ret = RIL_E_SUCCESS;
        LOGI("[VSIM] requestVsimOperation no urc waiting.");
        goto done;
    }

    RLOGD("[VSIM]requestVsimOperation, eventId: %d", response->eventId);

    if (response->eventId == MSG_ID_UICC_RESET_RESPONSE) {
        asprintf(&cmd, "AT+ERSA=1, %d, \"%s\"", ((response->result < 0) ? 0 : 1), response->data);
        setMdWaitingResponse(rid, -1);
    } else if (response->eventId == MSG_ID_UICC_APDU_RESPONSE) {
        asprintf(&cmd, "AT+ERSA=0, \"%s\"", response->data);
        setMdWaitingResponse(rid, -1);
    } else if (response->eventId == MSG_ID_UICC_TEST_MODE_REQUEST) {
        verified_vsim_client = checkIsTestVsimComponent(response->data, strlen(response->data));
        goto done;
    } else {
        RLOGD("[VSIM]requestVsimOperation, eventId not support: %d", response->eventId);
        goto done;
    }

    //RLOGD("[VSIM]requestVsimOperation, cmd: %s", cmd);

    err = at_send_command(cmd, &p_response, SIM_CHANNEL_CTX);
    free(cmd);

    if (err < 0 || NULL == p_response) {
        LOGE("[VSIM] requestVsimOperation Fail");
        ret = RIL_E_GENERIC_FAILURE;
        goto done;
    }

    if (0 == p_response->success) {
        switch (at_get_cme_error(p_response)) {
            default:
                ret = RIL_E_GENERIC_FAILURE;
                goto done;
        }
    }

done:
    RIL_onRequestComplete(t, ret, &response->transaction_id, sizeof(response->transaction_id));
    at_response_free(p_response);
}

#define VSIM_NO_RESPONSE_TIMEOUT_DURATION "13"
void initVsimConfiguration(RIL_SOCKET_ID rid) {
    char persist[PROPERTY_VALUE_MAX] = { 0 };
    getMSimProperty(rid, (char*)"persist.vendor.radio.external.sim", persist);

    if (strcmp("1", persist) == 0) {
        setExternalSimProperty(rid, "vendor.gsm.external.sim.enabled", "1");
    }
    setExternalSimProperty(rid, "vendor.gsm.external.sim.timeout",
                    VSIM_NO_RESPONSE_TIMEOUT_DURATION);
}

void initializeResetVsim(void *param) {
    RIL_SOCKET_ID rid = *((RIL_SOCKET_ID *)param);
    LOGI("[VSIM] initializeResetVsim rid:%d, initDone:%d.", rid, isInitDone);
    while (!isInitDone) {
        usleep(100*1000);
    }
    requestSimReset(rid);
    RIL_requestProxyTimedCallback(flightModeBootForVsim, (void *)param,
            &TIMEVAL_0, getRILChannelId(RIL_SIM, getMainProtocolRid()), "flightModeBootForVsim");
}

void flightModeBootForVsim(void *param) {
    RIL_SOCKET_ID rid = *((RIL_SOCKET_ID *)param);
    LOGI("[VSIM] flightModeBootForVsim rid:%d, initDone:%d.", rid, isInitDone);
    flightModeBoot(getChannelCtxbyProxy());
    bootupGetIccid(getChannelCtxbyProxy());
    for (int i = 0; i < getSimCount(); i++) {
        if (getMainProtocolRid() == i) continue; // skip main protocol for it has already been got
        RIL_requestProxyTimedCallback(getIccidWhenVsimEnable, (void *)&i, &TIMEVAL_0,
                getRILChannelId(RIL_SIM, i), "getIccidWhenVsimEnable");
    }
}

void getIccidWhenVsimEnable(void *param __unused) {
    bootupGetIccid(getChannelCtxbyProxy());
}

