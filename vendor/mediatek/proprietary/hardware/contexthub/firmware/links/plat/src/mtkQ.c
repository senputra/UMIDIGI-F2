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

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <heap.h>
#include <plat/inc/app.h>
#include <plat/inc/mtkQ.h>
#ifdef CFG_CONTEXTHUB_FW_SUPPORT
#include <contexthub_fw.h>
#endif
#include <hostIntf.h>
#include <sensType.h>

struct SimpleQueue* simpleQueueAlloc(uint32_t numEntries, uint32_t entrySz, SimpleQueueForciblyDiscardCbkF forceDiscardCbk)
{
    struct SimpleQueue *sq = NULL;
    return sq;
}
bool simpleQueueDequeue(struct SimpleQueue* sq, void *data)
{
    return true;
}

#ifndef CFG_CONTEXTHUB_FW_SUPPORT //test code, remember remove it later
bool SensorQueueEnqueue(struct SimpleQueue* sq, const void *data, int length, bool possiblyDiscardable)
{
    osLog(LOG_INFO, "SensorQueueEnqueue %p %p %d %d\n", sq, data, length, possiblyDiscardable);
	return true;
}
#endif
#ifdef CFG_CHRE_SET_INTERRUPT
unsigned int m_mtkQ_data = 0;
#define NANOHUB_QUEUE_HAVE_DATA (1 << 0)
#define SENSOR_QUEUE_HAVE_DATA  (1 << 1)
#define GPS_QUEUE_HAVE_DATA     (1 << 2)
#endif

bool simpleQueueEnqueue(struct SimpleQueue* sq, const void *data, int length, bool possiblyDiscardable)
{
#ifndef CFG_CHRE_SET_INTERRUPT
    if ((buffer->sensType >= SENS_TYPE_ACCEL && buffer->sensType <= SENS_TYPE_END) ||
        (buffer->sensType == SENS_TYPE_INVALID && buffer->dataType == HOSTINTF_DATA_TYPE_RESET_REASON))
        return SensorQueueEnqueue(sq, data, length, possiblyDiscardable);
#else
    /* simpleQ dispatch */
    /* osLog(LOG_INFO, "simpleQueueEnqueue %p %p %d %d\n", sq, data, length, possiblyDiscardable); */
    const struct HostIntfDataBuffer *buffer = data;
    //osLog(LOG_INFO, "mtkQ sensType:%d\n", buffer->sensType);
    if (buffer->sensType == SENS_TYPE_INVALID && buffer->dataType == HOSTINTF_DATA_TYPE_RESET_REASON) {
        //m_mtkQ_data |= NANOHUB_QUEUE_HAVE_DATA;
        /*for RESET_REASON, we have notify ap in SensorQueueEnqueue, we didn't put any data in
        sram data buffer, it is no need to set flag to m_mtkQ_data, or we may try to
        access dram and exception because mContextHubDramFifo.bufferBase is not ready.
        */
        SensorQueueEnqueue(sq, data, length, possiblyDiscardable);
    } else if (buffer->sensType == SENS_TYPE_INVALID && buffer->dataType == HOSTINTF_DATA_TYPE_APP_TO_HOST) {
        m_mtkQ_data |= NANOHUB_QUEUE_HAVE_DATA;
        SensorQueueEnqueue(sq, data, length, possiblyDiscardable);
    } else if (buffer->sensType >= SENS_TYPE_ACCEL && buffer->sensType <= SENS_TYPE_END) {
        m_mtkQ_data |= SENSOR_QUEUE_HAVE_DATA;
        SensorQueueEnqueue(sq, data, length, possiblyDiscardable);
    }
    return true;
#endif
}

