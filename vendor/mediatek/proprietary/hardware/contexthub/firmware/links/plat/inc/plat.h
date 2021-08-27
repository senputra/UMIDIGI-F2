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

#ifndef _MT6XXX_PLAT_H_
#define _MT6XXX_PLAT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <seos.h>


struct MtPlatEeDataGeneric {
    uint32_t eeDataType : 20;
    uint32_t eeDataLen  : 12; // not incl header
} __attribute__((packed));

struct MtPlatEeDataEncrKey {
    struct MtPlatEeDataGeneric hdr;
    uint64_t keyID;
    uint8_t key[32];
} __attribute__((packed));



static inline const struct AppHdr* platGetInternalAppList(uint32_t *numAppsP)
{
    extern const struct AppHdr __internal_app_start, __internal_app_end;

    *numAppsP = &__internal_app_end - &__internal_app_start;
    return &__internal_app_start;
}

static inline uint8_t* platGetSharedAreaInfo(uint32_t *areaSzP)
{
    extern uint8_t __shared_start[];
    extern uint8_t __shared_end[];

    *areaSzP = __shared_end - __shared_start;
    return __shared_start;
}

static inline void platWake(void)
{
}

// GCC aligns 64-bit types on an 8-byte boundary, but Cortex-M4 only requires
// 4-byte alignment for these types. So limit the return value, as we're
// interested in the minimum alignment requirement.
#if defined(__GNUC__) && !defined(alignof)
#define alignof(type) ((__alignof__(type) > 4) ? 4 : __alignof__(type))
#endif
#ifdef __cplusplus
}
#endif

#endif //_MT6XXX_PLAT_H_
