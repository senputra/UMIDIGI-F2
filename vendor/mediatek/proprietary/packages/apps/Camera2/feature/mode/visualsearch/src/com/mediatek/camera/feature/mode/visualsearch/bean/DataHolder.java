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

package com.mediatek.camera.feature.mode.visualsearch.bean;

import android.net.Uri;

import com.visualsearch.RectDataInfo;

import java.io.Serializable;
import java.util.ArrayList;

public class DataHolder implements Serializable {

    private static volatile DataHolder instance;
    private String mCameraId;
    private byte[] mImageData;
    private int mImgOrientation;
    private int mFlag;
    private Uri uri;
    private boolean mIsResumed;
    private long parseTime;
    private boolean isRequesting;
    private byte[] selectedImageBytes;
    private float[] rect;
    private String category;
    private ArrayList<Recognition> recognitionList;

    private ArrayList<RectDataInfo> rectList;
    private ArrayList<String> categoryList;
    private boolean isComputeFinished;
    private boolean isInitFinished;

    public static DataHolder getInstance() {
        if (instance == null) {
            synchronized (DataHolder.class) {
                if (instance == null) {
                    instance = new DataHolder();
                }
            }
        }
        return instance;
    }

    public void setCameraId(String cameraId) {
        mCameraId = cameraId;
    }

    public String getCameraId() {
        return mCameraId;
    }

    public boolean isComputeFinished() {
        return isComputeFinished;
    }

    public void setComputeFinished(boolean computeFinished) {
        isComputeFinished = computeFinished;
    }

    public boolean isInitFinished() {
        return isInitFinished;
    }

    public void setInitFinished(boolean initFinished) {
        isInitFinished = initFinished;
    }


    public ArrayList<RectDataInfo> getRectList() {
        return rectList;
    }

    public void setRectList(ArrayList<RectDataInfo> rectList) {
        this.rectList = rectList;
    }

    public ArrayList<String> getCategoryList() {
        return categoryList;
    }

    public void setCategoryList(ArrayList<String> categoryList) {
        this.categoryList = categoryList;
    }

    public byte[] getImageData() {
        return mImageData;
    }

    public void setImageData(byte[] imageData) {
        this.mImageData = imageData;
    }

    public Uri getUri() {
        return uri;
    }

    public void setUri(Uri uri) {
        this.uri = uri;
    }

    public int getImgOrientation() {
        return mImgOrientation;
    }

    public void setImgOrientation(int orientation) {
        mImgOrientation = orientation;
    }

    public int getFlag() {
        return mFlag;
    }

    public void setFlag(int flag) {
        mFlag = flag;
    }

    public boolean isIsResumed() {
        return mIsResumed;
    }

    public void setIsResumed(boolean mIsResumed) {
        this.mIsResumed = mIsResumed;
    }

    public long getParseTime() {
        return parseTime;
    }

    public void setParseTime(long parseTime) {
        this.parseTime = parseTime;
    }

    public boolean isRequesting() {
        return isRequesting;
    }

    public void setRequesting(boolean requesting) {
        isRequesting = requesting;
    }

    public byte[] getSelectedImageBytes() {
        return selectedImageBytes;
    }

    public void setSelectedImageBytes(byte[] selectedImageBytes) {
        this.selectedImageBytes = selectedImageBytes;
    }

    public float[] getRect() {
        return rect;
    }

    public void setRect(float[] rect) {
        this.rect = rect;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public ArrayList<Recognition> getRecognitionList() {
        return recognitionList;
    }

    public void setRecognitionList(ArrayList<Recognition> recognitionList) {
        this.recognitionList = recognitionList;
    }
}
