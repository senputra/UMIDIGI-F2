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

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.IBinder;
import android.os.MemoryFile;
import android.os.Parcel;
import android.os.ParcelFileDescriptor;
import android.os.RemoteException;

import com.mediatek.camera.feature.mode.visualsearch.bean.DataHolder;
import com.visualsearch.DataInfo;
import com.visualsearch.DataInterface;
import com.visualsearch.RectDataInfo;

import com.mediatek.camera.common.debug.LogHelper;
import com.mediatek.camera.common.debug.LogUtil;

import java.io.FileDescriptor;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class DataProviderStub extends DataInterface.Stub {

    private static final LogUtil.Tag TAG = new LogUtil.Tag(DataProviderStub.class
            .getSimpleName());
    private Context mContext;
    private boolean checkPermission;
    private boolean checkLicense;

    private static int sVersionMajor = 0;
    private static int sVersionMinor = 0;
    private static int sVersionRevision = 0;

    public DataProviderStub(Context mContext, String pkgName) {
        this.mContext = mContext;
        try {
            PackageManager pm = mContext.getPackageManager();
            if (pm == null) {
                LogHelper.e(TAG, "PackageManager is null");
            } else {
                PackageInfo pi;
                pi = pm.getPackageInfo(pkgName, 0);
                if (pi == null) {
                    LogHelper.e(TAG, "getPackageInfo is null");
                } else {
                    String versionName = pi.versionName;
                    String reg = "^\\D*(\\d+)\\.(\\d+)\\.(\\d+).*$";
                    Pattern p = Pattern.compile(reg);
                    Matcher m = p.matcher(versionName);
                    if (m.find()) {
                        setVersionMajor(Integer.parseInt(m.group(1)));
                        setVersionMinor(Integer.parseInt(m.group(2)));
                        setVersionRevision(Integer.parseInt(m.group(3)));
                    }
                }
            }
        } catch (PackageManager.NameNotFoundException | NumberFormatException e) {
            e.printStackTrace();
            LogHelper.e(TAG, e.getMessage());
        }
    }

    @Override
    public boolean onTransact(int code, Parcel data, Parcel reply, int flags) throws RemoteException {
        checkPermission = true;// SecurityChecker.getInstance().checkPermission(mContext, getCallingUid());
        return checkPermission && super.onTransact(code, data, reply, flags);
    }

    @Override
    public IBinder asBinder() {
        return this;
    }

    @Override
    public Bundle getVersionInfo() {
        if (checkLicense && checkPermission) {
            Bundle bundle = new Bundle();
            bundle.putInt("ver_major", getVersionMajor());
            bundle.putInt("ver_minor", getVersionMinor());
            bundle.putInt("ver_revision", getVersionRevision());
            return bundle;
        }
        return null;
    }

    @Override
    public DataInfo getResultList() {
        if (checkLicense && checkPermission) {
            ArrayList<RectDataInfo> rectList = DataHolder.getInstance().getRectList();
            ArrayList<String> categoryList = DataHolder.getInstance().getCategoryList();
            DataInfo dataInfo = new DataInfo();
            dataInfo.setCategoryList(categoryList);
            dataInfo.setRectList(rectList);
            return dataInfo;
        }
        return null;
    }

    @Override
    public Bundle getImageBytes(String bundleKey) {
        byte[] bytes = DataHolder.getInstance().getSelectedImageBytes();
        MemoryFile memoryFile = null;
        try {
            memoryFile = new MemoryFile("shareMemory", bytes.length);
            memoryFile.getOutputStream().write(bytes);
            Method method = MemoryFile.class.getDeclaredMethod("getFileDescriptor");
            FileDescriptor fd = (FileDescriptor) method.invoke(memoryFile);
            ParcelFileDescriptor descriptor = ParcelFileDescriptor.dup(fd);
            Bundle mBundle = new Bundle();
            mBundle.putParcelable(bundleKey, descriptor);
            memoryFile.close();
            return mBundle;
        } catch (IOException | NoSuchMethodException | IllegalAccessException | InvocationTargetException e) {
            if (memoryFile != null) {
                memoryFile.close();
            }
            e.printStackTrace();
        }
        return null;
    }


    private static synchronized int getVersionMajor() {
        return sVersionMajor;
    }

    private static synchronized int getVersionMinor() {
        return sVersionMinor;
    }

    private static synchronized int getVersionRevision() {
        return sVersionRevision;
    }

    private static synchronized void setVersionMajor(int versionMajor) {
        DataProviderStub.sVersionMajor = versionMajor;
    }

    private static synchronized void setVersionMinor(int versionMinor) {
        DataProviderStub.sVersionMinor = versionMinor;
    }

    private static synchronized void setVersionRevision(int versionRevision) {
        DataProviderStub.sVersionRevision = versionRevision;
    }

    @Override
    public boolean verifyLicense(Bundle param) {
        checkLicense = SecurityChecker.getInstance().checkKey(mContext, param);
        LogHelper.v(TAG, "DataProviderStub verifyLicense: " + checkLicense);
        return checkLicense;
    }
}
