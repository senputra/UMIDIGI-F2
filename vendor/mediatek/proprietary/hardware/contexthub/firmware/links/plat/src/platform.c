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

#include <cpu/inc/cpuMath.h>
#include <plat/inc/rtc.h>
#include <plat/inc/plat.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <platform.h>
#include <seos.h>
#include <timer.h>
#include <usart.h>
#include <mpu.h>
#include <cpu.h>
#include <hostIntf.h>
#include <atomic.h>
#include <nanohubPacket.h>
#include <sensType.h>
#include <semphr.h>
#include <interrupt.h>
#include <performance.h>
#ifdef CFG_XGPT_SUPPORT
#include <mt_gpt.h>
#endif

bool heapInit(void)
{
    /* nothing to do for mt6xxx */
    return 1;
}

void* heapAlloc(uint32_t sz)
{
    return pvPortMalloc(sz);
}

void heapFree(void* ptr)
{
    vPortFree(ptr);
}

int heapFreeAll(uint32_t tid)
{
    /* nothing to do for mt6xxx */
    return 1;
}

void platInitialize(void)
{
    /* nothing to do for mt6xxx */
}

void cpuInit(void)
{
    /* nothing to do for mt6xxx */
}

uint64_t platGetTicks(void)
{
#ifdef CFG_XGPT_SUPPORT
    return (uint64_t)read_xgpt_stamp_ns();
#else
    return 0;
#endif
}

void platSleep(void)
{
    mark_timestamp(0, 0, SENSOR_SLEEP, rtcGetTime());
    vTaskSuspend(CHRE_TaskHandle);
    portYIELD_WITHIN_API();
}

uint32_t platFreeResources(uint32_t tid)
{
    return 0;
}

#ifndef CFG_XGPT_SUPPORT
bool platSleepClockRequest(uint64_t wakeupTime, uint32_t maxJitterPpm, uint32_t maxDriftPpm, uint32_t maxErrTotalPpm) {
	return false;
}
#endif

