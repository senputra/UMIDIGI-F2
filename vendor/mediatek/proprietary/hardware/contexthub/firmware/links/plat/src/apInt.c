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

#include <apInt.h>
#include <gpio.h>
#include <variant/inc/variant.h>
//#include <plat/inc/gpio.h>
#include <seos.h>
#include <platform.h>
#include <plat/inc/plat.h>
#include <interrupt.h>

#if 0
static struct Gpio *apIntWkup;
#ifdef AP_INT_NONWAKEUP
static struct Gpio *apIntNonWkup;
#endif
#endif
void apIntInit()
{
#if 0
    apIntWkup = gpioRequest(AP_INT_WAKEUP);
    gpioConfigOutput(apIntWkup, GPIO_SPEED_LOW, GPIO_PULL_NONE, GPIO_OUT_PUSH_PULL, 1);

#ifdef AP_INT_NONWAKEUP
    apIntNonWkup = gpioRequest(AP_INT_NONWAKEUP);
    gpioConfigOutput(apIntNonWkup, GPIO_SPEED_LOW, GPIO_PULL_NONE, GPIO_OUT_PUSH_PULL, 1);
#endif
#endif
}
#ifdef CFG_CONTEXTHUB_FW_SUPPORT
#include <contexthub_fw.h>
#endif
#ifdef CFG_CHRE_SET_INTERRUPT
extern int m_mtkQ_data;
#define NANOHUB_QUEUE_HAVE_DATA (1 << 0)
#define SENSOR_QUEUE_HAVE_DATA  (1 << 1)
#define GPS_QUEUE_HAVE_DATA     (1 << 2)
#endif

void apIntSet(bool wakeup)
{
#ifdef CFG_CHRE_SET_INTERRUPT
    if (!is_in_isr()) {
        if (m_mtkQ_data & NANOHUB_QUEUE_HAVE_DATA) {
            m_mtkQ_data &= ~NANOHUB_QUEUE_HAVE_DATA;
#ifdef CFG_CONTEXTHUB_FW_SUPPORT
            hostIntfWakeUp();
#endif
        }
        if (m_mtkQ_data & SENSOR_QUEUE_HAVE_DATA) {
            m_mtkQ_data &= ~SENSOR_QUEUE_HAVE_DATA;
#ifdef CFG_CONTEXTHUB_FW_SUPPORT
            hostIntfWakeUp();
#endif
        }
        if (m_mtkQ_data & GPS_QUEUE_HAVE_DATA) {
            m_mtkQ_data &= ~GPS_QUEUE_HAVE_DATA;
        }
    } else {

        /* todo: delay notify */
    }
#endif
}

void apIntClear(bool wakeup)
{
#if 0
    if (wakeup) {
        platReleaseDevInSleepMode(Stm32sleepWakeup);
        gpioSet(apIntWkup, 1);
    }
#ifdef AP_INT_NONWAKEUP
    else
        gpioSet(apIntNonWkup, 1);
#endif
#endif
}
