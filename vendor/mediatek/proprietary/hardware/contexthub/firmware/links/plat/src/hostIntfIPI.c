/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __CHRE_IPI_C_INCLUDED__
#define __CHRE_IPI_C_INCLUDED__

#include "string.h"
#include <stdint.h>
#include <seos.h>
#include "timers.h"
#include <interrupt.h>
#include <scp_ipi.h>
#include <nanohubPacket.h>
#include <hostIntf_priv.h>

#define CHRE_IPI_DEBUG	0
#define IPI_WAIT  0
typedef void (*HostIntfCommCallbackF)(size_t bytesTransferred, int err);
static int hostIntfIPITxPacket(const void *txBuf, size_t txSize,
                               HostIntfCommCallbackF callback);
static int hostIntfIPIRxPacket(void *rxBuf, size_t rxSize,
                               HostIntfCommCallbackF callback);
static int hostIntfIPIRequest();
static int hostIntfIPIRelease();


HostIntfCommCallbackF IPI_Rx_callback;

static void *gRxBuf;
static size_t gRxSize;


typedef struct {
    const void *txBuf;
    size_t txSize;
    HostIntfCommCallbackF callback;
} ipi_tx_st;
ipi_tx_st ipi_tx;


static const struct HostIntfComm gIPIComm = {
    .request = hostIntfIPIRequest,
    .rxPacket = hostIntfIPIRxPacket,
    .txPacket = hostIntfIPITxPacket,
    .release = hostIntfIPIRelease,
};

const struct HostIntfComm *hostIntfIPIInit(void)
{
    return &gIPIComm;
}

static int hostIntfIPIRequest()
{
    return 0;
}

static int hostIntfIPIRelease()
{
    return 0;
}

static void defer_scp_ipi_send(void *cookie)
{
    ipi_tx_st* ipi_tx = cookie;
    int ret = 1;
#if CHRE_IPI_DEBUG
    const unsigned char* data_p = ipi_tx->txBuf;
    osLog(LOG_INFO, "SCP->(%d),%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n", ipi_tx->txSize,
        data_p[0], data_p[1], data_p[2], data_p[3], data_p[4],data_p[5], data_p[6], data_p[7], data_p[8], data_p[9]);
#endif
    while(ret!=0) // retry until ipi is free
        ret = scp_ipi_send(IPI_CHRE, (void *)ipi_tx->txBuf, ipi_tx->txSize, IPI_WAIT, IPI_SCP2AP); //no wait, let it retry when ipi busy
}

/*
 * We don't protect the ipi_tx from multi-call hostIntfIPITxPacket,
 * because it shouldn't happened.
 */
static int hostIntfIPITxPacket(const void *txBuf, size_t txSize,
                               HostIntfCommCallbackF callback)
{
    ipi_tx.txBuf = (char *)txBuf + 1; //skip prePreamble
    ipi_tx.txSize = txSize - 1; //skip prePreamble
    ipi_tx.callback = callback;
    //scp_ipi_send(IPI_CHREW, (void *)txBuf, txSize, IPI_NOWAIT, IPI_SCP2AP);
    //osDefer(defer_scp_ipi_send, &ipi_tx, true);   /* can't use ipi in ISR*/
    if (is_in_isr()) {
        xTimerPendFunctionCallFromISR((PendedFunction_t) defer_scp_ipi_send,
            &ipi_tx,
            0,
            NULL);
    } else {
        xTimerPendFunctionCall((PendedFunction_t) defer_scp_ipi_send,
            &ipi_tx,
            0,
            0);
    }
    return 0;   // todo, error handle
}

static int hostIntfIPIRxPacket(void *rxBuf, size_t rxSize,
                               HostIntfCommCallbackF callback)
{
    gRxBuf = rxBuf;
    gRxSize = rxSize;
    IPI_Rx_callback = callback;
#if CHRE_IPI_DEBUG
    osLog(LOG_INFO, "Register IPI_Rx_callback %p,rxBuf:%p,RxSize %d,\n", callback, rxBuf, rxSize);
#endif
    return 0;   //todo: error handle
}


void chre_ipi_rxhandler(int id, void * data, unsigned int len)
{
#if CHRE_IPI_DEBUG
    unsigned char* data_p = data;
    osLog(LOG_INFO, "->SCP(%d),%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",len,
        data_p[0], data_p[1], data_p[2], data_p[3], data_p[4],data_p[5], data_p[6], data_p[7], data_p[8], data_p[9]);
#endif
    if (len <= NANOHUB_PACKET_SIZE_MAX && gRxBuf) {
        gRxSize = len;
        memcpy(gRxBuf, data, gRxSize);
        IPI_Rx_callback(gRxSize, 0);    //todo: return error code
    } else
        osLog(LOG_ERROR, "len %d > %d, gRxBuf %p\n", len, NANOHUB_PACKET_SIZE_MAX, gRxBuf);
}

/*
 * AP should send back data when recevie TX
 * +1 (prePreamble size)
 */
void chre_ipi_ack_handler(int id, void * data, unsigned int len)
{
    int err = 0;
    unsigned char *token = data;	//fix me when ipi > 255 byte
#if CHRE_IPI_DEBUG
    osLog(LOG_INFO, "%s(%d), token %x\n", __func__, len, *token);
#endif
    if((ipi_tx.txSize & 0xff) != *token) {
        err = 1;
        osLog(LOG_INFO, "ipi_tx.txSize(%x)!= \n",ipi_tx.txSize);
    }
    if (ipi_tx.callback != NULL)
        ipi_tx.callback(ipi_tx.txSize + 1, err);
    if (xTaskResumeFromISR(CHRE_TaskHandle) == pdTRUE) {
        portYIELD_WITHIN_API();
    }
}
void chre_ipi_init(void)
{
    ipi_status status;
    status = scp_ipi_registration(IPI_CHRE, chre_ipi_rxhandler, "chre_scp_rx");
    scp_ipi_wakeup_ap_registration(IPI_CHRE);
    osLog(LOG_INFO, "%s:  %d\n", __func__, status);
    status = scp_ipi_registration(IPI_CHREX, chre_ipi_ack_handler, "chre_x");
    osLog(LOG_INFO, "%s:  %d\n", __func__, status);
    return;
}

#endif //__CHRE_IPI_C_INCLUDED__

