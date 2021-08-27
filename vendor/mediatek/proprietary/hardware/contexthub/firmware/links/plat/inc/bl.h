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

#ifndef _BOOTLOADER_H_
#define _BOOTLOADER_H_

#ifdef __cplusplus
}
#endif
#include <stdbool.h>
//#include <stdarg.h>
//#include <stdint.h>
//typedef int bool;
//enum { false, true };

#if 0
#undef bool
#define bool uint32_t
#define false 0
#define true 1
#endif

#define BL_VERSION_1        1
#define BL_VERSION_CUR      BL_VERSION_1

#define BL_FLASH_KERNEL_ID  0x1
#define BL_FLASH_EEDATA_ID  0x2
#define BL_FLASH_APP_ID     0x4

#define BL_FLASH_KEY1       0x45670123
#define BL_FLASH_KEY2       0xCDEF89AB

struct BlVecTable {
    /* cortex requirements */
    uint32_t    blStackTop;
    void        (*blEntry)(void);
    void        (*blNmiHandler)(void);
    void        (*blHardFaultHandler)(void);
    void        (*blMmuFaultHandler)(void);
    void        (*blBusFaultHandler)(void);
    void        (*blUsageFaultHandler)(void);

    /* bl api */
    //ver 1 bl supports:
        //basics
    uint32_t        (*blGetVersion)(void);
    void            (*blReboot)(void);
    void            (*blGetSnum)(uint32_t *snum, uint8_t length);

    //flash
    bool            (*blProgramShared)(uint8_t *dst, const uint8_t *src, uint32_t length, uint32_t key1, uint32_t key2);
    bool            (*blEraseShared)(uint32_t key1, uint32_t key2);
    bool            (*blProgramEe)(uint8_t *dst, const uint8_t *src, uint32_t length, uint32_t key1, uint32_t key2);
    //security data
    const uint32_t* (*blGetPubKeysInfo)(uint32_t *numKeys);
};

//for using outside of bootloader
extern struct BlVecTable BL;

#ifdef __cplusplus
}
#endif

#endif
