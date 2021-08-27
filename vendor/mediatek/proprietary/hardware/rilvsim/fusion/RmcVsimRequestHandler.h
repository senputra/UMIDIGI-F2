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
#ifndef __RMC_VSIM_REQUEST_HANDLER_H__
#define __RMC_VSIM_REQUEST_HANDLER_H__
/*****************************************************************************
 * Include
 *****************************************************************************/

/*****************************************************************************
 * Class RpSimController
 *****************************************************************************/

class RmcVsimRequestHandler : public RmcSimBaseHandler {
    RFX_DECLARE_HANDLER_CLASS(RmcVsimRequestHandler);

public:
    RmcVsimRequestHandler(int slot_id, int channel_id);
    virtual ~RmcVsimRequestHandler();

    // Check if the handler have to process the Request or not
    virtual RmcSimBaseHandler::SIM_HANDLE_RESULT needHandle(
            const sp<RfxMclMessage>& msg);

    // Process Request here
    virtual void handleRequest(const sp<RfxMclMessage>& msg);
    virtual void handleEvent(const sp<RfxMclMessage>& msg);

    // Return the list which you want to reqister
    virtual const int* queryTable(int channel_id, int *record_num);
    virtual const int* queryEventTable(int channel_id, int *record_num);

    int isSingeleRfRemoteSimSupport();

    static void setVerifiedVsimClient(int verified);
    static int isInternalTestVsimComponent();
    static int getAkaSimSlot();
    static int isBeingPlugOut(int slot_id);

private:
    void handleVsimNotification(const sp<RfxMclMessage>& msg);
    void handleVsimOperation(const sp<RfxMclMessage>& msg);
    // Handle vsim disconnected event, send necessary responses to modem
    void handleVsimDisconnected();
    void sendVsimErrorResponse();
    void handleVsimAuthRequestEvent(const sp<RfxMclMessage>& msg);
    void handleReleaseAkaSim();
    void handleReleaseRf();
    void setVsimAuthTimeoutDuration();
    int checkIsTestVsimComponent(unsigned char *data, int len);

private:
    static int sVerifiedVsimClient;
    static int sBeingPlugOut[MAX_SIM_COUNT];
};
#endif /* __RMC_VSIM_REQUEST_HANDLER_H__ */
// External SIM [End]
