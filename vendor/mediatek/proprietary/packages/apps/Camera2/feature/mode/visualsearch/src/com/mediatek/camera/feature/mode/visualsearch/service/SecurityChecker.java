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

package com.mediatek.camera.feature.mode.visualsearch.service;

import android.Manifest;
import android.annotation.SuppressLint;
import android.content.Context;
import android.content.pm.PackageManager;
import android.content.pm.Signature;
import android.os.Binder;
import android.os.Bundle;
import android.util.Base64;

import com.mediatek.camera.feature.mode.visualsearch.utils.NativeImageDetect;

import java.security.MessageDigest;
import java.util.concurrent.ConcurrentHashMap;

import static android.content.pm.PackageManager.GET_SIGNATURES;

public class SecurityChecker {
    private static SecurityChecker sInstance = null;
    private ConcurrentHashMap<Integer, Boolean> mSignCheckResultCache;

    private SecurityChecker() {
        mSignCheckResultCache = new ConcurrentHashMap<>();
    }

    public synchronized static SecurityChecker getInstance() {
        if (sInstance == null) {
            sInstance = new SecurityChecker();
        }
        return sInstance;
    }

    public boolean checkPermission(Context context, int callingUid) {
        String packageName = null;
        String[] packages = context.getPackageManager().getPackagesForUid(callingUid);
        if (packages != null && packages.length > 0) {
            packageName = packages[0];
        }
        if (packageName == null) {
            return true;
        }

        return checkPermission(context, Manifest.permission.CAMERA, packageName);
    }

    private boolean checkPermission(Context context, String permName, String pkgName) {
        PackageManager pm = context.getPackageManager();
        return PackageManager.PERMISSION_GRANTED == pm.checkPermission(permName, pkgName);
    }

    void clearCache() {
        mSignCheckResultCache.clear();
    }

    boolean checkKey(Context context, Bundle licenseParam) {
        int callingUid = Binder.getCallingUid();
        Boolean result;
        result = mSignCheckResultCache.get(callingUid);
        if (result != null && result) {
            return true;
        }
        if (context == null) {
            return false;
        }
        String sha256Key = licenseParam.getString("SHA256_KEY");
        String pkgNameKey = licenseParam.getString("PKG_NAME_KEY");
        byte[] encodeByRSAPrivateKey = Base64.decode(sha256Key, Base64.NO_WRAP);

        byte[] decodeByRSAPubKey = NativeImageDetect.decodeRSAPubKey(encodeByRSAPrivateKey);
        String keyByDecrypt_sha256 = new String(decodeByRSAPubKey);
        byte[] encodeByRSAPkgName = Base64.decode(pkgNameKey, Base64.NO_WRAP);

        byte[] decodeByRSAPkgName = NativeImageDetect.decodeRSAPubKey(encodeByRSAPkgName);
        String keyByDecrypt_pkgName = new String(decodeByRSAPkgName);
        PackageManager pm = context.getPackageManager();
        String pkgName = pm.getNameForUid(callingUid);
        if (pkgName != null) {
            try {
                @SuppressLint("PackageManagerGetSignatures")
                Signature signature = pm.getPackageInfo(pkgName, GET_SIGNATURES).signatures[0];
                MessageDigest messageDigestSHA256 = MessageDigest.getInstance("SHA-256");
                messageDigestSHA256.update(signature.toByteArray());
                String sha256 = hexToString(messageDigestSHA256.digest());
                if (keyByDecrypt_sha256.equals(sha256) && keyByDecrypt_pkgName.equals(pkgName)) {
                    mSignCheckResultCache.put(callingUid, true);
                    return true;
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        mSignCheckResultCache.put(callingUid, false);
        return false;
    }

    private String hexToString(byte[] block) {

        StringBuffer buf = new StringBuffer();

        for (byte aBlock : block) {
            byte2Hex(aBlock, buf);
        }
        return buf.toString();
    }

    private void byte2Hex(byte b, StringBuffer buf) {
        char[] hexChars = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

        int high = ((b & 0xf0) >> 4);
        int low = (b & 0x0f);

        buf.append(hexChars[high]);
        buf.append(hexChars[low]);

    }

}
