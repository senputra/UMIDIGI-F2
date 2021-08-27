/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2020. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

#ifndef __META_CAL_UTILS_H__
#define __META_CAL_UTILS_H__

#include <log/log.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG         "META_CAL"

#define META_CAL_DEBUG  1
#define ERR(f, ...)     ALOGE("%s: " f, __FUNCTION__, ##__VA_ARGS__)
#define WAN(f, ...)     ALOGW("%s: " f, __FUNCTION__, ##__VA_ARGS__)

#if META_CAL_DEBUG
#define DBG(f, ...)     ALOGD("%s: " f, __FUNCTION__, ##__VA_ARGS__)
#define TRC(f)          ALOGW("%s #%d", __FUNCTION__, __LINE__)
#else
#define DBG(...)        ((void)0)
#define TRC(f)          ((void)0)
#endif

// General
#define PMIC_DEV "/sys/bus/platform/devices/mt-pmic/pmic_access"
#define BIT(n) ((unsigned int) 1 << (n))
#define BITS(m,n) (~(BIT(m)-1) & ((BIT(n)-1) | BIT(n)))
#define MAX_BUF_SIZE    1024
#define MAX_CMD_SIZE    100
#define MAX_FD_COUNT    10
#define INV_TEMPERATURE -9999

// WiFi related
#define PRIV_CMD_SIZE 512
#define IOCTL_GET_DRIVER (SIOCIWFIRSTPRIV + 15)

struct priv_driver_cmd_t {
    char buf[PRIV_CMD_SIZE];
    int used_len;
    int total_len;
};

typedef enum {
    ENONE = 0,
    EFD,
    EFOE,
    EFUNC_NULL,
    EINIT,
    ELIB,
    EMALLOC,
    EPMIC_PRE,
    EPMIC_R,
    EPMIC_W,
    ERXV,
    ESNPRINTF,
    ETX_MODE,
    EUNSUPPORTED,
    EMAX
} CAL_ERR;

unsigned int get_wifi_reg_val(char* cmd);
int read_pmic_reg(unsigned int addr, unsigned int *val);
int update_pmic_reg(unsigned int addr, unsigned int mask, unsigned int shift, unsigned int val);
float convert_auxadc_to_temperature(unsigned int auxadc);

#endif // __META_CAL_UTILS_H__