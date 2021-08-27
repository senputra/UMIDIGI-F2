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

#include <time.h>
#include <unistd.h>
#include "../../../meta_utils/meta_cal_utils.h"
#include "../../../meta_afc/platform/mt6785/mt6785_afc.h"
#include "mt6785_c0c1.h"

// PMIC heater bit[6:7]
#define MT6359_RG_XO_HEATER_SEL_ADDR        0x7a6
#define MT6359_RG_XO_HEATER_SEL_MASK        0x3
#define MT6359_RG_XO_HEATER_SEL_SHIFT       6

// AUXADC (for temperature)
#define MT6359_AUXADC_ADC_OUT_CH7_ADDR          0x1096
// MT6357_AUXADC_ADC_OUT_CH7_MASK is 0x7FFF but we also need RDY (15th) bit
#define MT6359_AUXADC_ADC_OUT_AND_RDY_CH7_MASK  0xFFFF
#define MT6359_AUXADC_ADC_RDY_CH7_MASK          0x1
#define MT6359_AUXADC_ADC_RDY_CH7_SHIFT         15

PLT_CORE_C0C1 plt_core_c0c1 = core_c0c1;

static float query_temperature()
{
    int ret = 0;
    int retry = 10;
    float temp = 0;
    unsigned int orig = 0;
    unsigned int auxadc = 0;
    unsigned char ready_bit = 0;

    while (--retry >= 0) {
        ret = read_pmic_reg(MT6359_AUXADC_ADC_OUT_CH7_ADDR, &orig);
        ready_bit = (orig >> MT6359_AUXADC_ADC_RDY_CH7_SHIFT) & MT6359_AUXADC_ADC_RDY_CH7_MASK;

        if (ready_bit != 1) {
            continue;
        }

        break;
    }

    if (ready_bit == 0) {
        DBG("Retry fail: cannot get valid auxadc\n");
        return -EPMIC_R;
    }

    auxadc = orig & MT6359_AUXADC_ADC_OUT_AND_RDY_CH7_MASK;
    DBG("Auxadc[%d]\n", auxadc);

    temp = convert_auxadc_to_temperature(auxadc);
    DBG("Temperature[%f]\n", temp);

    return temp;
}

int core_c0c1(C0C1_INIT *init, float *c0c1)
{
    const int COUNT_MAX = 12;
    float tmp[MAX_DATA_SIZE] = {0};
    float foe_ppm[MAX_DATA_SIZE] = {0};
    double foe_in_hz[MAX_DATA_SIZE] = {0};
    int ret = 0;
    int count = 0;
    double foe_hz = 0;
    int lib_ret = 0;

    if (init->centerFreq == 0) {
        ERR("Invalid center frequency\n");
        return -EINIT;
    }

    DBG("Center frequency[%f]\n", init->centerFreq);
    clock_t t = clock();

    // Step 1: set pmic heater on
    ret = update_pmic_reg(MT6359_RG_XO_HEATER_SEL_ADDR, MT6359_RG_XO_HEATER_SEL_MASK, MT6359_RG_XO_HEATER_SEL_SHIFT, 3);

    if (ret != 0) {
        return -EPMIC_W;
    }

    // Step 2: heating 4 sec
    sleep(4);

    while (count < COUNT_MAX) {
        // Step 3: get temperature
        tmp[count] = query_temperature();

        // Step 4: get foe in Hz
        ret = get_foe(&foe_hz);

        if (ret != 0) {
            return ret;
        }

        foe_in_hz[count] = foe_hz;

        // Convert Hz to ppm unit; foe_arr[x] Hz; init->centerFreq: centerFreq in MHz
        // ppm = (foe * 10^6) / centerFreq
        foe_ppm[count] = (float)(foe_hz / (double)init->centerFreq);

        // Step 5: heating 1 sec
        sleep(1);
        count++;
    }

    // Step 6: set pmic heater off
    ret = update_pmic_reg(MT6359_RG_XO_HEATER_SEL_ADDR, MT6359_RG_XO_HEATER_SEL_MASK, MT6359_RG_XO_HEATER_SEL_SHIFT, 0);

    if (ret != 0) {
        return -EPMIC_W;
    }

    // Step 5: get best c0 and c1
    lib_ret = least_squares(tmp, foe_ppm, count, c0c1);

    if (lib_ret != 0) {
        return -ELIB;
    }

    DBG("Best c0[%f], c1[%f]\n", c0c1[0], c0c1[1]);

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    DBG("C0C1 calibration takes %lf seconds\n", time_taken);

    return ret;
}
