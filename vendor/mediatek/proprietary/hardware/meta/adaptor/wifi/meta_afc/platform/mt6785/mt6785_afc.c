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

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "../../meta_afc.h"
#include "../../../meta_utils/meta_cal_utils.h"
#include "mt6785_afc.h"

#define AFC_MAX_ROUND 2

// For cap id
#define MT6359_XO_CDAC_FPM_ADDR         0x794
#define MT6359_XO_CDAC_FPM_MASK         0xFF
#define MT6359_XO_CDAC_FPM_SHIFT        0

// For AAC
#define MT6359_XO_AAC_FPM_SWEN_ADDR     0x79c
#define MT6359_XO_AAC_FPM_SWEN_MASK     0x1
#define MT6359_XO_AAC_FPM_SWEN_SHIFT    15

PLT_CORE_AFC plt_core_afc = core_afc;

unsigned int get_rxv(unsigned char cycle)
{
    int retry = 30;
    unsigned int val = 0;
    char cmd[MAX_CMD_SIZE];
    memset(cmd, 0, sizeof(cmd));

    if (cycle == 1) { // RXV1
        strcpy(cmd, "get_mcr 0x820704DC");
    } else if (cycle == 5) { // RXV5
        strcpy(cmd, "get_mcr 0x820704EC");
    } else {
        return 0;
    }

    while (--retry >= 0) {
        val = get_wifi_reg_val(cmd);

        if (val == 0) {
            continue;
        }

        break;
    }

    return val;
}

int get_foe(double *avg_foe)
{
    const unsigned char VALID_CNT_MAX = 3;
    int ret = 0;
    int ifoe = 0;
    unsigned int rxv1 = 0;
    unsigned int rxv5 = 0;
    unsigned int rxv_foe = 0;
    unsigned int foe_const = 0;
    unsigned int dbw = 0;
    unsigned int tx_mode = 0;
    unsigned int sign_bit = 0;
    double accum_foe = 0;

    // Need to avoid zero foe but also minimize total calibration time
    // We get average foe from three valid rxv_foe
    for (int count = 0; count < VALID_CNT_MAX; count++) {
        rxv5 = get_rxv(5);

        if (rxv5 == 0) {
            ERR("Cannot get valid rxv5 for foe\n");
            return -ERXV;
        }

        rxv1 = get_rxv(1);

        if (rxv1 == 0) {
            ERR("Cannot get valid rxv1 for dbw and tx mode\n");
            return -ERXV;
        }

        // Get tx mode
        tx_mode = (rxv1 & BITS(12, 14)) >> 12; // RXV1: phy2mac_rxvector[14:12]

        // Calculate rxv_foe according to tx mode
        if (tx_mode == 0) {
            // CCK format: s-5.15; bit 0~10, msb is sign bit, and then 2^-6 ~ 2^-15
            // Only support dbw = 20; thus, no need to get dbw
            rxv_foe = (((rxv5 & BITS(7, 31)) >> 7) & 0x7ff); // CCK FOE = [10:0]
            sign_bit = ((rxv_foe & BIT(10)) >> 10);

            if (sign_bit) {
                ifoe = rxv_foe - 2048; // 2^11
            } else {
                ifoe = (int)rxv_foe;
            }

            foe_const = 20000000 >> 15; // 20M >> 15
            ifoe *= foe_const;
        } else {
            // OFDM format: s-4.15; bit 0~11, msb is sign bit, and then 2^-5 ~ 2^-15
            dbw = (rxv1 & BITS(15, 16)) >> 15; // RXV1: phy2mac_rxvector[16:15]; (dbw=frmode)
            foe_const = ((1 << (dbw + 1)) & 0xf) * 10000000;
            rxv_foe = (((rxv5 & BITS(7, 31)) >> 7) & 0xfff); // OFDM FOE = [11:0]
            sign_bit = ((rxv_foe & BIT(11)) >> 11);

            if (sign_bit) {
                ifoe = rxv_foe - 4096; // 2^12
            } else {
                ifoe = (int)rxv_foe;
            }

            foe_const >>= 15;
            ifoe *= foe_const;
        }

        // RXV regards RX side as its baseline
        // Change baseline to TX side, i.e. consider instrument as baseline
        ifoe *= -1;

        accum_foe += (double)ifoe;
        DBG("tx_mode[%u], dbw[%u], rxv1[0x%08x], rxv5[0x%08x], rxv_foe[0x%08x], foe[#%d]=[%d]\n", tx_mode, dbw, rxv1, rxv5, rxv_foe, count, ifoe);
    }

    // Get average foe
    *avg_foe = accum_foe / (double)VALID_CNT_MAX;
    DBG("Get avg foe[%lf]\n", *avg_foe);

    return ret;
}

static int do_aac()
{
    int ret = 0;

    // Initialize AAC: set XO_AAC_FPM_SWEN = 1’b0 and wait 0.1ms
    ret = update_pmic_reg(MT6359_XO_AAC_FPM_SWEN_ADDR, MT6359_XO_AAC_FPM_SWEN_MASK, MT6359_XO_AAC_FPM_SWEN_SHIFT, 0);

    if (ret != 0) {
        return -EPMIC_W;
    }

    usleep(100);

    // Execute AAC and wait 30ms
    ret = update_pmic_reg(MT6359_XO_AAC_FPM_SWEN_ADDR, MT6359_XO_AAC_FPM_SWEN_MASK, MT6359_XO_AAC_FPM_SWEN_SHIFT, 1);

    if (ret != 0) {
        return -EPMIC_W;
    }

    usleep(30000);

    return ret;
}

static int do_afc()
{
    int ret = 0;
    int best_cap_id = 0;
    double cap_id_arr[10] = {0.0, 29.0, 58.0, 87.0, 116.0, 145.0, 174.0, 203.0, 232.0, 255.0};
    unsigned int cap_id_num = 10;

    // Get foe based on different cap id
    double *foe_arr = malloc(cap_id_num * sizeof(double));

    if (foe_arr == NULL) {
        DBG("Frequency error table is null\n");
        return -EMALLOC;
    }

    for (unsigned int i = 0; i < cap_id_num; i++) {
        // Set cap id
        ret = update_pmic_reg(MT6359_XO_CDAC_FPM_ADDR, MT6359_XO_CDAC_FPM_MASK, MT6359_XO_CDAC_FPM_SHIFT, cap_id_arr[i]);

        if (ret != 0) {
            return -EPMIC_W;
        }

        // Get foe
        ret = get_foe(&foe_arr[i]);

        if (ret != 0) {
            return ret;
        }
    }

    best_cap_id = evaluate_cap_id(cap_id_num, cap_id_arr, foe_arr);
    free(foe_arr);

    return best_cap_id;
}

int core_afc(float *temperature)
{
    int ret = 0;
    int best_cap_id = 0;

    clock_t t = clock();

    for (int i = 0; i < AFC_MAX_ROUND; i++) {
        DBG("AFC round #%d\n", i);

        ret = do_aac();

        if (ret != 0) {
            DBG("AAC failed\n");
            return ret;
        }

        best_cap_id = do_afc();

        if (best_cap_id < 0) {
            return best_cap_id; // do not continue, just return error cap id
        }

        ret = update_pmic_reg(MT6359_XO_CDAC_FPM_ADDR, MT6359_XO_CDAC_FPM_MASK, MT6359_XO_CDAC_FPM_SHIFT, best_cap_id);

        if (ret != 0) {
            return -EPMIC_W;
        }
    }

    // For MT6785, no need to provide temperature information
    *temperature = INV_TEMPERATURE;

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    DBG("AFC calibration takes %lf seconds\n", time_taken);

    return best_cap_id;
}
