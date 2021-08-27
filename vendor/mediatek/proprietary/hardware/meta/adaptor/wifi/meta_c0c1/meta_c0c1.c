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
#include "meta_c0c1.h"
#include "../meta_utils/meta_cal_utils.h"

/****** C0C1 Lib START (lib provided by GPS team) ******/
#define LS_STATE_NUME 2

typedef float        R4;
typedef double       R8;
typedef unsigned int U4;

#define R8_ESL_EPS 0.6e-37
#define R4_ESL_EPS 0.6e-37f

#ifndef R4abs
    #define R4abs(x) ((x) >= 0 ? (x) : -(x))
#endif

#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define U_Diag(i) ((i + 1) * (i + 2) / 2 - 1)
#define MIN_TSX_TEMP -40
#define MAX_TSX_TEMP +85

// umeas - Bierman one measuremenmt at a time update to a U-D-U vector
// triangular stored covariance matrix and state vector.  This routine
// may be used without a residual and state vector for covariance
// analysis by settings TST<0.  It may also be used to edit a previously
// added measurement by re-running umeas but with a negative measurement
// variance R
// The equation numbers refer to Rierman's 1975 cdc paper, pp. 337-346.
static void umeas(
    R4 U[],        // io - Vector stored UD factors of covariance P,
                   //      U[N*(N+1)/2].   D is stored on the Diagonal of U,
                   //      which is implicit unity.  (The last [N+1]th column
                   //      contains the state vector corrections.)
    U4 N,          // i  - State vector dimension (N>0)
    R4 R,          // i  - Scaler measurement variance (R>=0)
                   //      (if R<0.0, then the measurement is edited)
#ifdef __arm
    const R4 A[],  // i  - Observation equation & residual, A[N+1].
#else
    R4 A[],        // i  - Observation equation & residual, A[N+1].
#endif
                   //      (Only used if TST>=0.0)
    R4 F[],        // o  - Work vector, F[N+1], containing (A*U)^T,
                   //      F[N+1]=dz/alpha.   (If desired, F can overwrite
                   //      A to save storage).
    R4 G[],        // o  - Normalised Kalman gain vector, G[N], gain=G/alpha
    R4 *alpha,     // o  - Innovations variance
                   //      (Set negative if the acceptance test failed.)
    R4 TST)        // i  - Acceptence test multiplier (4.0=2 sigma, 9.0=3 sigma
                   //      etc) (if TST<0.0, only a covariance update is done)
{
    // Local Variable Declerations
    R8 sum, beta, gamma;    // intermediate values
    R4 temp, P, S;          // intermediate values
    U4 nz_in_A;             // index of 1st non-zero element in A
    U4 max_2_in_A;          // max of 2, or 1st non zero element in A
    U4 N_p1;                // State vector dimension + 1
    U4 N_tot;               // Size of UDU factorized covariance matrix
    U4 i, j, k;             // loop / array indicies
    U4 jjN, jj;             // diagonals of U matrix
    U4 kj;                  // kth element of row j in U
    U4 jm1;                 // j - 1

    // Adjust pointers of U, A, G & F so that the arrays start at 1 & not 0.
    U--;
    A--;
    G--;
    F--;

    // Compute size of obs equation (H) and covarinace matrices (U).
    N_p1  = N + 1;
    N_tot = ( N * N_p1 ) / 2;

    // Find first non-zero element of A.
    nz_in_A = 0;
    for (j = 1; j <= N; j++) {
        if (A[j] != 0.0f) {
            nz_in_A = j;
            break;
        }
    }

    // Trap the error of no non-zero elements in A (this should never happen!), and exit.
    if (nz_in_A == 0) {
        for (k = 1; k <= N; k++) {
            G[k] = 0.0f;
            F[k] = 0.0f;
        }

        if (TST >= 0.0f && R4abs(R) > R4_ESL_EPS) U[N_tot + N_p1] = A[N_p1] / R;
        alpha[0] = R;
        return;
    }

    max_2_in_A = 0; // Supress N/A "used before set" compiler warning.
    // Continue with a valid observation equation, taking into account special
    // case of dimension one, where U is always unity and D is the only value
    // of concern.  Compute   F = U^T.A    and   G = D.(U^T.A)
    if (N > 1) {
        jjN = N_tot;
        max_2_in_A = MAX( 2, nz_in_A );
        for ( j=N ; j>=max_2_in_A ; j-- )
        {
            jj = jjN - j;
            sum = A[j]; // because U[jj]=1.0 implicitly
            jm1 = j - 1;
            for ( k=1 ; k<=jm1 ; k++ )
            {
                sum = sum + U[jj+k] * A[k];
            }
            F[j] = (R4)sum;
            G[j] = (R4)sum * U[jjN];
            jjN = jj;
        }
    }

    // If the first non-zero element is at location 1, the treated specially
    // because U[1] is implicitly 1.0 but in fact stores D[1].
    if (nz_in_A == 1) {
        F[1] = A[1];
        G[1] = U[1] * F[1];
    } else {
        for (k = 1; k < nz_in_A; k++) {
            F[k] = 0.0f;
            G[k] = 0.0f;
        }
    }

    // If doing a full measurement update (ie TST>=0 ) then compute the
    // Innovations variance  = ( R + A.P.A^T ) , stored as beta for now and
    // compute  the pre-adjustment residual  Z = Z - A^T.X  remembering that
    // F=U^T.A  and  G = D.(U^T.A).   Trap the case of measurement residuals
    // too large to pass the acceptence test, returning a negative innovations
    // variance (alpha) for bad measurements.
    if (TST >= 0.0f) {
        beta = R;
        sum = 0.0;

        for (j = nz_in_A; j <= N; j++) {
            beta = beta + F[j] * G[j];
            sum = sum + A[j] * U[N_tot + j];
        }

        sum = A[N_p1] - sum;
        U[N_tot + N_p1] = (R4)sum;
        if (R >= 0.0 && (sum * sum) > (TST * beta)) {
            alpha[0] = (R4) - beta;
            return;
        }
    }

    // Compute the inovation term = (A.P.A^T + R), where gamma = 1.0/alpha.
    // Test 'sum' against machine epsilon value to avoid problems when R=0.
    gamma = 0.0;
    if (nz_in_A == 1) { // ie case when U[1] = D[1]
        sum = R  +  G[1] * F[1];
        if (fabs(sum) > R8_ESL_EPS) gamma = 1.0 / sum;
        {
            U[1]  = U[1] * (R4)(R * (R4)gamma); // D[1] update
            if (N == 1)  goto  Neq1_contine;
            kj = 2;
        }
    }
    else {
        kj = (nz_in_A * (nz_in_A - 1) / 2) + 1;
        sum = R;
        if (fabs(sum) > R8_ESL_EPS) gamma = 1.0 / sum;
    }

    for (j = max_2_in_A; j <= N; j++) {
        beta = sum;
        temp = G[j];
        P = -F[j] * (R4)gamma; // Equation (21)

        for (k = 1; k < j; k++) {
            S = U[kj]; // Equation (22)
            U[kj] = S + P * G[k]; // Equation (23)
            G[k] = G[k] + temp * S;
            kj++;
        }

        sum = sum + temp * F[j];
        if (fabs(sum) > R8_ESL_EPS) {
            gamma = 1.0 / sum;
            U[kj] = U[kj] * (R4)(beta * gamma); // D[j] Equation (19)
        }

        // Zero out off-diag column in U for singularity case, U[jj] remains =1.0
        if (U[kj] == 0.0f) {
            i = kj;
            for (k = 1; k <= j; k++) {
                U[i] = 0.0f;
                i = kj - k;
            }
        }

        // Next row j
        kj++;
    }

// Jumped directly to here for case when N=1
Neq1_contine:
    // If required, update the state vector and then exit with the inovations
    // variance, alpha = 1.0/gamma.
    alpha[0] = (R4) sum; // = (A.P.A^T + R) = 1.0/gamma
    if (TST > 0.0f) {
        sum = U[N_tot + N_p1] * gamma;
        F[N_p1] = (R4)sum;
        for (j = 1; j <= N; j++) {
            U[N_tot + j] = U[N_tot + j] + G[j] * (R4)sum;
        }
    }

    return;
}

int least_squares(float input_u[MAX_DATA_SIZE], float input_f[MAX_DATA_SIZE], int nData, float C0C1[2])
{

    float CovMat[(LS_STATE_NUME+1)*(LS_STATE_NUME+1+1)/2]; // Covariance Matrix U.D.U factors
    float Obs_Equ[LS_STATE_NUME+1]; // Observation equation matrix
    float esl_HTU[LS_STATE_NUME+1]; // Work vector required by ESL function "umeas"
    float esl_MGV[LS_STATE_NUME]; // Work vector required by ESL function "umeas"

    R4 dX[LS_STATE_NUME];
    R4 H[MAX_DATA_SIZE][2];
    R4 F[MAX_DATA_SIZE];
    R4 ResVar[MAX_DATA_SIZE]; // i - Residual Variances  [m^2 or m^2/s^2]
    R4 Inno_Var; // Residual innovations variance

    R4 c3 = 9.9e-5;
    R4 c2 = -0.00085;

    int i;

    if (nData > 12) {
        return -1;
    }

    for (i = 0; i < nData; i++) {
        float t;
        float k_3,k_2;
        t = input_u[i];

        H[i][0] = t-25.0;
        H[i][1] = 1.0;

        k_3 = (t - 25.0) * (t - 25.0) * (t - 25.0);
        k_2 = (t - 25.0) * (t - 25.0) ;

        F[i] = input_f[i] - (c3 * (k_3) + c2 * k_2);
        ResVar[i] = 1.0;
    }

    // Initialise the Covariance Matrix to a have large uncertainties.
    memset(CovMat, 0, sizeof(CovMat));
    memset(Obs_Equ, 0, sizeof(Obs_Equ));

    for (i = 0; i <= LS_STATE_NUME; i++) {
        CovMat[U_Diag(i)] = (R4)1.0e14;
    }

    for (i = 0; i < nData; i++) {
        Obs_Equ[0] = H[i][0];
        Obs_Equ[1] = H[i][1];

        Obs_Equ[LS_STATE_NUME] = F[i];

        umeas(CovMat, LS_STATE_NUME, 20.0/*ResVar[i]*/, Obs_Equ, // io,3i
                esl_HTU, esl_MGV, &Inno_Var, 1.0e20f);
    }

    memcpy(dX, &CovMat[LS_STATE_NUME * (LS_STATE_NUME + 1) / 2], (sizeof(R4) * LS_STATE_NUME));

    C0C1[0] = dX[1];
    C0C1[1] = dX[0];

    return 0;
}
/****** C0C1 Lib END (lib provided by GPS team) ******/

int start_c0c1_calibration(C0C1_INIT *init, float *c0c1)
{
    if (plt_core_c0c1) {
        return plt_core_c0c1(init, c0c1);
    }

    return -EFUNC_NULL;
}
