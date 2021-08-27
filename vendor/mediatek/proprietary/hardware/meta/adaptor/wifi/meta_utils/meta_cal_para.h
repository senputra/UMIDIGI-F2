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

#ifndef _META_CAL_PARA_H_
#define _META_CAL_PARA_H_

// AFC and C0C1 calibration related structures defined by META tool owner
typedef struct
{
    unsigned int Action;
    unsigned int InitialVale;
    float Slop;
    unsigned int AAC;
    unsigned int CAP_ID;
} WIFI_AFC_Calibration_REQ;

typedef struct
{
    unsigned int Status;
    unsigned int AAC;
    unsigned int CAP_ID;
    float Temperature;
} WIFI_AFC_Calibration_CNF;

typedef struct
{
    unsigned int Action;
    float C0;
    float C1;
    unsigned int SamplePoint;
    unsigned int SPInterval;
    unsigned int HeaterTime;
    float CenterFreq;
    float Temperature;
} WIFI_C0C1_Calibration_REQ;

typedef struct
{
    unsigned int Status;
    float C0;
    float C1;
} WIFI_C0C1_Calibration_CNF;

typedef struct
{
    unsigned int Action;        // Action 0: use for AFC  1 : use for C0/C1
    unsigned int parameter1;    // Action=0  parameter1=AAC      Action=1  parameter1=C0
    unsigned int parameter2;    // Action=0  parameter2=CAP_ID   Action=2  parameter1=C1
} WIFI_Write_NVRAM_REQ;

typedef struct
{
    unsigned int Status;
} WIFI_Write_NVRAM_CNF;

typedef struct
{
    unsigned int Action;        // Action   0 : use for AFC  1 : use for C0/C1
    unsigned int parameter1;    // Action=0   parameter1=AAC      Action=1  parameter1=C0
    unsigned int parameter2;    // Action=0   parameter2=CAP_ID   Action=2  parameter1=C1
} WIFI_Write_File_REQ;

typedef struct
{
    unsigned int Status;
} WIFI_Write_File_CNF;

typedef struct
{
    unsigned int Action;    // Action   0 : use for AFC  1 : use for C0/C1
} WIFI_Read_NVRAM_REQ;

typedef struct
{
    unsigned int Status;
    unsigned int parameter1;    // if request Action=0 parameter1=AAC  else Action=1  parameter1=C0
    unsigned int parameter2;    // if request Action=0 parameter2=AAC  else Action=1  parameter2=C1
} WIFI_Read_NVRAM_CNF;

typedef struct
{
    unsigned int Action;    // Action   0 : use for AFC  1 : use for C0/C1
} WIFI_Read_File_REQ;

typedef struct
{
    unsigned int Status;
    unsigned int parameter1;    // if request Action=0 parameter1=AAC  else Action=1  parameter1=C0
    unsigned int parameter2;    // if request Action=0 parameter2=AAC  else Action=1  parameter2=C1
} WIFI_Read_File_CNF;

typedef union
{
    WIFI_AFC_Calibration_REQ afc_cmd;
    WIFI_C0C1_Calibration_REQ c0c1_cmd;
    WIFI_Write_NVRAM_REQ write_nvram_cmd;
    WIFI_Write_File_REQ write_file_cmd;
    WIFI_Read_NVRAM_REQ read_nvram_cmd;
    WIFI_Read_File_REQ read_file_cmd;
} FT_WIFI_AFC_REQ_CMD;

typedef union
{
    WIFI_AFC_Calibration_CNF afc_cmd;
    WIFI_C0C1_Calibration_CNF c0c1_cmd;
    WIFI_Write_NVRAM_CNF write_nvram_cmd;
    WIFI_Write_File_CNF write_file_cmd;
    WIFI_Read_NVRAM_CNF read_nvram_cmd;
    WIFI_Read_File_CNF read_file_cmd;
} FT_WIFI_AFC_CNF_CMD;

typedef enum
{
    WIFI_AFC_Calibration = 0,
    WIFI_C0C1_Calibration = 1,
    WIFI_Write_NVRAM = 2,
    WIFI_Write_File = 3,
    WIFI_Read_NVRAM = 4,
    WIFI_Read_File = 5
} WIFI_CMDID;

typedef struct
{
    WIFI_CMDID cmd_id;
    FT_WIFI_AFC_REQ_CMD cmd;
} WIFI_AFC_REQ;

typedef struct
{
    WIFI_CMDID cmd_id;
    FT_WIFI_AFC_CNF_CMD cmd;
} WIFI_AFC_CNF;

#endif // _META_CAL_PARA_H_