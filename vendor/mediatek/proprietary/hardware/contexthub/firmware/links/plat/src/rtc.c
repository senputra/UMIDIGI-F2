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

#include <cpu/inc/barrier.h>
//#include <cpu/inc/cpuMath.h>
#include <plat/inc/rtc.h>
//#include <plat/inc/pwr.h>
#include <inc/timer.h>
#include <inc/platform.h>
//#include <plat/inc/exti.h>
//#include <plat/inc/cmsis.h>
//#include <variant/inc/variant.h>
#ifdef CFG_XGPT_SUPPORT
#include <mt_gpt.h>
#endif
uint64_t rtcGetTime(void)
{
#ifdef CFG_XGPT_SUPPORT
	return (uint64_t)read_xgpt_stamp_ns();
#else
    return 0;
#endif
}



