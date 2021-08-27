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
#include <plat/inc/app.h>
#include <alloca.h>
#include <string.h>
//#include <plat/inc/cmsis.h>
//#include <plat/inc/pwr.h>
#include <plat/inc/bl.h>
#include <nanohub/sha2.h>
#include <nanohub/aes.h>
#include <nanohub/rsa.h>
#include <nanohub/nanohub.h>

#if 0 //todo: linker flash map
#define BOOTLOADER    __attribute__ ((section (".bltext")))
#define BOOTLOADER_RO __attribute__ ((section (".blrodata")))
#else
#define BOOTLOADER
#define BOOTLOADER_RO
#endif

//linker provides these
extern char __stack_top[];
extern char __ram_start[];
extern char __ram_end[];
extern char __eedata_start[];
extern char __eedata_end[];
extern char __code_start[];
extern char __code_end[];
extern char __shared_start[];
extern char __shared_end[];
extern void __VECTORS();

void BOOTLOADER __blEntry(void);
//static void BOOTLOADER __blCopyShared(void);
//static int BOOTLOADER __blProgramFlash(uint8_t *, uint8_t *, uint32_t, uint32_t, uint32_t);
//static uint32_t BOOTLOADER __blCrcCont(uint8_t *, unsigned int);
//static uint32_t BOOTLOADER __blCrc(uint8_t *, unsigned int);
//static void BOOTLOADER __blEraseSectors(uint32_t, uint8_t *);
//static void BOOTLOADER __blWriteBytes(uint8_t *, uint8_t *, uint32_t);
//static int BOOTLOADER __blCompareBytes(uint8_t *, uint8_t *, uint32_t);

void BOOTLOADER __blEntry(void)
{
#if 0 //todo:
    uint32_t appBase = ((uint32_t)&__VECTORS) & ~1;

    //make sure we're the vector table and no ints happen (BL does not use them)
    __blDisableInts();
    SCB->VTOR = (uint32_t)&BL;

    __blCopyShared();

    //call main app with ints off
    __blDisableInts();
    SCB->VTOR = appBase;
    asm volatile(
        "LDR SP, [%0, #0]    \n"
        "LDR PC, [%0, #4]    \n"
        :
        :"r"(appBase)
        :"memory", "cc"
    );

    //we should never return here
    while(1);
#endif
}

static uint32_t BOOTLOADER __blVersion(void)
{
    return BL_VERSION_CUR;
}

static void BOOTLOADER __blReboot(void)
{
#if 0 //todo:
    SCB->AIRCR = 0x05FA0004;
#endif
    //we never get here
    while(1);
}
#if 0
static void BOOTLOADER __blGetSnum(uint32_t *snum, uint8_t length)
{
    struct StmUdid *reg = (struct StmUdid *)UDID_BASE;
    int i;

    if (length > 3)
        length = 3;

    for (i=0; i<length; i++)
        snum[i] = reg->U_ID[i];
}
#endif

#if 0 //unknow bug?
void hexdump(uint8_t *start, uint32_t size, const char* name)
{
    int i;
    char buf[128];
    sprintf(buf, "%s start:%p +%d\n", name, start, (int)size);
    osLog(LOG_INFO, "%s", buf);
    for(i=0; i<size;i++){
        if(i%16 == 0){
            sprintf(buf, "\nGG_%08lx: ", (uint32_t)start+i);
            osLog(LOG_INFO, "%s", buf);
        }
        sprintf(buf, "%02x ", start[i]);
        osLog(LOG_INFO, "%s", buf);
    }
    osLog(LOG_INFO, "\n");
}
#endif

static bool __blProgramShared(uint8_t *dst, const uint8_t *src,
        uint32_t length, uint32_t key1, uint32_t key2)
{

    osLog(LOG_INFO, "%s dst:%p src:%p (%d)\n", __func__, dst, src, (int)length);
    memcpy(dst, src, length);
    //hexdump(dst, length, __func__);
    return true;
}

static bool __blEraseShared(uint32_t key1, uint32_t key2)
{
    osLog(LOG_INFO, "%s dst:%p (%d)\n", __func__, __shared_start, (int)&__shared_end - (int)&__shared_start);
    memset((uint8_t *)&__shared_start, 0xff, (int)&__shared_end - (int)&__shared_start);
    return true;
}

static void __blSpurious(void)
{
    //BAD!
#if 0
    __blReboot();
#endif
}
#if 0 //todo
static const uint32_t *__blGetPubKeysInfo(uint32_t *numKeys)
{
    extern uint32_t __pubkeys_start[];
    extern uint32_t __pubkeys_end[];
    uint32_t numWords = __pubkeys_end - __pubkeys_start;

    if (numWords % RSA_LIMBS) // something is wrong
        return NULL;

    *numKeys = numWords / RSA_LIMBS;
    return __pubkeys_start;
}
#endif
const struct BlVecTable __attribute__((section(".blvec"))) __BL_VECTORS =
{
    /* cortex */
    .blStackTop = (uint32_t)&__stack_top,
//    .blEntry = &__blEntry,
    .blNmiHandler = &__blSpurious,
    .blMmuFaultHandler = &__blSpurious,
    .blBusFaultHandler = &__blSpurious,
    .blUsageFaultHandler = &__blSpurious,

    /* api */
    .blGetVersion = &__blVersion,
    .blReboot = &__blReboot,
//    .blGetSnum = &__blGetSnum,
    .blProgramShared = &__blProgramShared,
    .blEraseShared = &__blEraseShared,
//    .blGetPubKeysInfo = &__blGetPubKeysInfo,
};
