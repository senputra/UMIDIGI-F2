/*
 *   Copyright Statement:
 *
 *     This software/firmware and related documentation ("MediaTek Software") are
 *     protected under relevant copyright laws. The information contained herein is
 *     confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 *     the prior written permission of MediaTek inc. and/or its licensors, any
 *     reproduction, modification, use or disclosure of MediaTek Software, and
 *     information contained herein, in whole or in part, shall be strictly
 *     prohibited.
 *
 *     MediaTek Inc. (C) 2016. All rights reserved.
 *
 *     BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *    THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 *     RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 *     ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 *     WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 *     WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 *     NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 *     RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 *     TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 *     RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 *     OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 *     SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 *     RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 *     STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 *     ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 *     RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 *     MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 *     CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     The following software/firmware and/or related documentation ("MediaTek
 *     Software") have been modified by MediaTek Inc. All revisions are subject to
 *     any receiver's applicable license agreements with MediaTek Inc.
 */

/**
* AIDL is an interface definition language for generating code for
* interprocess communication (IPC) between two processes on An Android device.
* The use of AIDL means that there is a Service in the server that provides
* Binder objects to the specific client process to which the bindService is bound.
* A client converts a Binder object into a proxy object for the AIDL interface through asInterface,
* a static method of the AIDL interface, through which a remote invocation request can be made
**/

package com.visualsearch;
import com.visualsearch.DataInfo;
import android.os.Bundle;

interface DataInterface {
    /**
     * Use to get version information .
     *
     * @return The bundle contains version information
     * @see ParamDefinition#KEY_VERSION_MAJOR
     * @see ParamDefinition#KEY_VERSION_MINOR
     * @see ParamDefinition#KEY_VERSION_REVISION
     *      Use Bundle.getInt(ParamDefinition.KEY_VERSION_MAJOR) to get major version code.
     *      Use Bundle.getInt(ParamDefinition.KEY_VERSION_MINOR) to get minor version code.
     *      Use Bundle.getInt(ParamDefinition.KEY_VERSION_REVISION) to get revision version code.
     */
    Bundle getVersionInfo();
    /**
     * Submit validation information
     *
     * @return The verification result.
     * @param The bundle contains the authentication information.
     * @see KEY
     * @see PRODUCT_NAME
     *      Use Bundle.getString(KEY) to get key.
     *      Use Bundle.getString(PRODUCT_NAME) to get product name.
     */
    boolean verifyLicense(in Bundle param);
    /**
     * Query Image information.
     *
     * @return Image information (rectList,categoryrectList)
     *
     */
    DataInfo getResultList();
    /**
        * Query Image information.
        *
        * @return Bundle bundle,through bundle get imageInformation
        *@param bundleKey put imageInformation through bundleKey
        */
    Bundle getImageBytes(String bundleKey);

}
