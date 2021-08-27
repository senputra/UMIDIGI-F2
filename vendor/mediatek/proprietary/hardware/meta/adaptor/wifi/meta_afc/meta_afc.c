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

#include <stdlib.h>
#include "meta_afc.h"
#include "../meta_utils/meta_cal_utils.h"

static double** allocate_2d_array(unsigned int row, unsigned int col)
{
    double **arr = (double **)malloc(row * sizeof(double *));

    if (arr == NULL)
        return NULL;

    for (unsigned int i = 0; i < row; i++) {
        arr[i] = (double *)malloc(col * sizeof(double));
    }

    return arr;
}

static void free_2d_array(double **arr, unsigned int row)
{
    for (unsigned i = 0; i < row; i++) {
        free(arr[i]);
    }

    free(arr);
}

static void multiply_matrix(double **a, double **b, double **ret, unsigned int out_row, unsigned int out_col, unsigned int middle)
{
    for(unsigned int row = 0; row < out_row; row++) {
        for(unsigned int col = 0; col < out_col; col++) {
            ret[row][col] = 0.0;

            for(unsigned int i = 0; i < middle; i++) {
                ret[row][col] += a[row][i] * b[i][col];
            }
        }
    }
}

static bool inverse_matrix(const double m[16], double invOut[16])
{
    double inv[16], det;
    int i;

    inv[0] = m[5]  * m[10] * m[15] -
             m[5]  * m[11] * m[14] -
             m[9]  * m[6]  * m[15] +
             m[9]  * m[7]  * m[14] +
             m[13] * m[6]  * m[11] -
             m[13] * m[7]  * m[10];

    inv[4] = -m[4]  * m[10] * m[15] +
              m[4]  * m[11] * m[14] +
              m[8]  * m[6]  * m[15] -
              m[8]  * m[7]  * m[14] -
              m[12] * m[6]  * m[11] +
              m[12] * m[7]  * m[10];

    inv[8] = m[4]  * m[9] * m[15] -
             m[4]  * m[11] * m[13] -
             m[8]  * m[5] * m[15] +
             m[8]  * m[7] * m[13] +
             m[12] * m[5] * m[11] -
             m[12] * m[7] * m[9];

    inv[12] = -m[4]  * m[9] * m[14] +
               m[4]  * m[10] * m[13] +
               m[8]  * m[5] * m[14] -
               m[8]  * m[6] * m[13] -
               m[12] * m[5] * m[10] +
               m[12] * m[6] * m[9];

    inv[1] = -m[1]  * m[10] * m[15] +
              m[1]  * m[11] * m[14] +
              m[9]  * m[2] * m[15] -
              m[9]  * m[3] * m[14] -
              m[13] * m[2] * m[11] +
              m[13] * m[3] * m[10];

    inv[5] = m[0]  * m[10] * m[15] -
             m[0]  * m[11] * m[14] -
             m[8]  * m[2] * m[15] +
             m[8]  * m[3] * m[14] +
             m[12] * m[2] * m[11] -
             m[12] * m[3] * m[10];

    inv[9] = -m[0]  * m[9] * m[15] +
              m[0]  * m[11] * m[13] +
              m[8]  * m[1] * m[15] -
              m[8]  * m[3] * m[13] -
              m[12] * m[1] * m[11] +
              m[12] * m[3] * m[9];

    inv[13] = m[0]  * m[9] * m[14] -
              m[0]  * m[10] * m[13] -
              m[8]  * m[1] * m[14] +
              m[8]  * m[2] * m[13] +
              m[12] * m[1] * m[10] -
              m[12] * m[2] * m[9];

    inv[2] = m[1]  * m[6] * m[15] -
             m[1]  * m[7] * m[14] -
             m[5]  * m[2] * m[15] +
             m[5]  * m[3] * m[14] +
             m[13] * m[2] * m[7] -
             m[13] * m[3] * m[6];

    inv[6] = -m[0]  * m[6] * m[15] +
              m[0]  * m[7] * m[14] +
              m[4]  * m[2] * m[15] -
              m[4]  * m[3] * m[14] -
              m[12] * m[2] * m[7] +
              m[12] * m[3] * m[6];

    inv[10] = m[0]  * m[5] * m[15] -
              m[0]  * m[7] * m[13] -
              m[4]  * m[1] * m[15] +
              m[4]  * m[3] * m[13] +
              m[12] * m[1] * m[7] -
              m[12] * m[3] * m[5];

    inv[14] = -m[0]  * m[5] * m[14] +
               m[0]  * m[6] * m[13] +
               m[4]  * m[1] * m[14] -
               m[4]  * m[2] * m[13] -
               m[12] * m[1] * m[6] +
               m[12] * m[2] * m[5];

    inv[3] = -m[1] * m[6] * m[11] +
              m[1] * m[7] * m[10] +
              m[5] * m[2] * m[11] -
              m[5] * m[3] * m[10] -
              m[9] * m[2] * m[7] +
              m[9] * m[3] * m[6];

    inv[7] = m[0] * m[6] * m[11] -
             m[0] * m[7] * m[10] -
             m[4] * m[2] * m[11] +
             m[4] * m[3] * m[10] +
             m[8] * m[2] * m[7] -
             m[8] * m[3] * m[6];

    inv[11] = -m[0] * m[5] * m[11] +
               m[0] * m[7] * m[9] +
               m[4] * m[1] * m[11] -
               m[4] * m[3] * m[9] -
               m[8] * m[1] * m[7] +
               m[8] * m[3] * m[5];

    inv[15] = m[0] * m[5] * m[10] -
              m[0] * m[6] * m[9] -
              m[4] * m[1] * m[10] +
              m[4] * m[2] * m[9] +
              m[8] * m[1] * m[6] -
              m[8] * m[2] * m[5];

    det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

    if (det == 0)
        return false;

    det = 1.0 / det;

    for (i = 0; i < 16; i++)
        invOut[i] = inv[i] * det;

    return true;
}

static double x_3_order_calc(double **coef, double x)
{
    double x_2 = x * x;
    double x_3 = x_2 * x;
    return coef[0][0] * x_3 + coef[1][0] * x_2 + coef[2][0] * x + coef[3][0];
}

int evaluate_cap_id(unsigned int cap_id_num, double *cap_id, double *foe_arr)
{
    const unsigned int CAP_ID_MAX = 255;
    unsigned int equat_dimen = 4;
    unsigned int one_dimen = 1;
    int best_cap_id = 0;
    int row = 0;
    int col = 0;
    int i = 0;
    double in[16], out[16];

    // Matrix b stores foe
    double **b = NULL;
    b = allocate_2d_array(cap_id_num, one_dimen);

    if (b == NULL) {
        ERR("Malloc b failed\n");
        return -EMALLOC;
    }

    for (i = 0; i < cap_id_num; i++) {
        b[i][0] = foe_arr[i];
    }

    // Calculate X 10x4
    double **x = NULL;
    x = allocate_2d_array(cap_id_num, equat_dimen);

    if (x == NULL) {
        ERR("Malloc x failed\n");
        return -EMALLOC;
    }

    for (col = 3; col >= 0; col--) {
        for(row = 0; row < cap_id_num; row++) {
            if(col == 3) {
                x[row][col] = 1;
            }
            else if(col == 2) {
                x[row][col] = cap_id[row];
            }
            else if(col == 1) {
                x[row][col] = cap_id[row] * cap_id[row];
            }
            else if(col == 0) {
                x[row][col] = cap_id[row] * cap_id[row] * cap_id[row];
            }
        }
    }

    // Calculate XT 4x10
    double **xt = NULL;
    xt = allocate_2d_array(equat_dimen, cap_id_num);

    if (xt == NULL) {
        ERR("Malloc xt failed\n");
        return -EMALLOC;
    }

    for (row = 0; row < equat_dimen; row++) {
        for (col = 0; col < cap_id_num; col++) {
            xt[row][col] = x[col][row];
        }
    }

    // Calculate XT * X 4x10 * 10x4 = 4x4
    double **xt_x = NULL;
    xt_x = allocate_2d_array(equat_dimen, equat_dimen);

    if (xt_x == NULL) {
        ERR("Malloc xt_x failed\n");
        return -EMALLOC;
    }

    multiply_matrix(xt, x, xt_x, equat_dimen, equat_dimen, cap_id_num);

    // Inverse XT_X_I 4x4
    double **xt_x_i = NULL;
    xt_x_i = allocate_2d_array(equat_dimen, equat_dimen);

    if (xt_x_i == NULL) {
        ERR("Malloc xt_x_i failed\n");
        return -EMALLOC;
    }

    for (i = 0; i < 16; i++) {
        in[i] = xt_x[i / 4][i % 4];
    }

    inverse_matrix(in, out);

    for (i = 0; i < 16; i++) {
        xt_x_i[i / 4][i % 4] = out[i];
    }

    // Calculate XT_X_I * XT 4x4 * 4x10 = 4x10
    double **xt_x_i_xt = NULL;
    xt_x_i_xt = allocate_2d_array(equat_dimen, cap_id_num);

    if (xt_x_i_xt == NULL) {
        ERR("Malloc xt_x_i_xt failed\n");
        return -EMALLOC;
    }

    multiply_matrix(xt_x_i, xt, xt_x_i_xt, equat_dimen, cap_id_num, equat_dimen);

    // Calculate XT_X_I_XT * b 4x10 * 10x1 = 4x1
    double **coef = NULL;
    coef = allocate_2d_array(equat_dimen, one_dimen);

    if (coef == NULL) {
        ERR("Malloc coef failed\n");
        return -EMALLOC;
    }

    multiply_matrix(xt_x_i_xt, b, coef, equat_dimen, one_dimen, cap_id_num);

    DBG("AFC formula coefficient=[%lf][%lf][%lf][%lf]\n", coef[0][0], coef[1][0], coef[2][0], coef[3][0]);
    double smallest_val = x_3_order_calc(coef, 0);

    if (smallest_val < 0) {
        smallest_val = -smallest_val;
    }

    for (i = 1; i <= CAP_ID_MAX; i++) {
        double val = x_3_order_calc(coef, i);

        if (val < 0) {
            val = -val;
        }

        if (val < smallest_val) {
            smallest_val = val;
            best_cap_id = i;
        }
    }

    free_2d_array(b, cap_id_num);
    free_2d_array(x, cap_id_num);
    free_2d_array(xt, equat_dimen);
    free_2d_array(xt_x, equat_dimen);
    free_2d_array(xt_x_i, equat_dimen);
    free_2d_array(xt_x_i_xt, equat_dimen);
    free_2d_array(coef, equat_dimen);

    DBG("Best cap id=[%d]\n", best_cap_id);
    return best_cap_id;
}

int start_afc_calibration(float *temperature)
{
    if (plt_core_afc) {
        return plt_core_afc(temperature);
    }

    return -EFUNC_NULL;
}
