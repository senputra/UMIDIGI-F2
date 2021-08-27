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

#include "WpfaDriverULIpPkt.h"
#include "WpfaDriverMessage.h"
#include "FilterStructure.h"

#include <mtk_log.h>

#define WPFA_D_LOG_TAG "WpfaDriverULIpPkt"

WPFA_IMPLEMENT_DATA_CLASS(WpfaDriverULIpPkt);

WpfaDriverULIpPkt::WpfaDriverULIpPkt(void *_data, int _length) :
        WpfaDriverBaseData(_data, _length) {
    int ret=0;
    if (_data != NULL) {
        wifiproxy_m2a_ul_ip_pkt_t *pSendMsg = (wifiproxy_m2a_ul_ip_pkt_t*)_data;
        wifiproxy_m2a_ul_ip_pkt_t *pData = (wifiproxy_m2a_ul_ip_pkt_t *)calloc(1,
                    sizeof(wifiproxy_m2a_ul_ip_pkt_t));
        if (pData == NULL) {
            mtkLogD(WPFA_D_LOG_TAG,"pData is null, return.");
            return;
        }

        for(int i = 0; i < MAX_UL_IP_PKT_SIZE; i++){
            pData->pkt[i] = pSendMsg->pkt[i];
            //mtkLogD("WpfaDriverULIpPkt", "pData->pkt[%d]=%c",i, pData->pkt[i]);
        }
        mData = (void* )pData;
        mLength = _length;
    }
}

WpfaDriverULIpPkt::~WpfaDriverULIpPkt() {
    // free memory
    if (mData != NULL) {
        free(mData);
        mData = NULL;
    }
}