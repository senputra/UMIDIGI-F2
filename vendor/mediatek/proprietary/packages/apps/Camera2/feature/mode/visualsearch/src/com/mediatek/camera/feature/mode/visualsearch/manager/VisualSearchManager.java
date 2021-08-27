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

package com.mediatek.camera.feature.mode.visualsearch.manager;

import android.annotation.SuppressLint;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.os.AsyncTask;
import android.os.SystemClock;
import android.util.Size;

import com.mediatek.camera.feature.mode.visualsearch.bean.ImageTag;
import com.mediatek.camera.feature.mode.visualsearch.bean.Recognition;
import com.mediatek.camera.feature.mode.visualsearch.bean.DataHolder;
import com.mediatek.camera.feature.mode.visualsearch.utils.NativeImageDetect;
import com.mediatek.camera.feature.mode.visualsearch.utils.Const;

import com.mediatek.camera.common.debug.LogHelper;
import com.mediatek.camera.common.debug.LogUtil;

import org.json.JSONArray;
import org.json.JSONObject;

import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.List;

public class VisualSearchManager {

    private static final LogUtil.Tag TAG = new LogUtil.Tag(VisualSearchManager.class.getSimpleName());
    private static VisualSearchManager sInstance = null;
    private static final int DIM_BATCH_SIZE = 1;
    private static final int DIM_PIXEL_SIZE = 3;
    private static int IMAGE_SIZE_X = Const.IMAGE_SIZE_WIDTH;
    private static int IMAGE_SIZE_Y = Const.IMAGE_SIZE_HEIGHT;
    private ImageTagListener mImageTagListener = null;
    /**
     * A ByteBuffer to hold image data, to be feed into Tensorflow Lite as inputs.
     */
    private ByteBuffer imgData = null;
    /* Preallocated buffers for storing image data in. */
    private int[] intValues;

    private ArrayList<Recognition> recognitionList;

    public synchronized static VisualSearchManager getInstance() {

        if (sInstance == null) {
            synchronized (VisualSearchManager.class) {
                if (sInstance == null) {
                    sInstance = new VisualSearchManager();
                }
            }
        }
        return sInstance;
    }

    public void init() {
        NativeImageDetect.init();
    }

    public void initModel(int modelType, String modelPath, String labelPath) {
        NativeImageDetect.initModel(modelType, modelPath, labelPath, 5);
    }

    // public void initModels(int modelType, List<String> labelList) {
    //     NativeImageDetect.initModelList(modelType, labelList, 5);
    // }

    public int initModels(int modelType, String modelPath, List<String> labelList) {
        return NativeImageDetect.initModelsByPath(modelType, modelPath, labelList, 5);
    }

    public int initModels(int modelType, AssetManager assetManager, String modelName, List<String> labelList) {
        return NativeImageDetect.initModels(modelType, assetManager, modelName, labelList, 5);
    }

    /**
     * @param bitmap           image
     * @param modelInputSize   model input size
     * @param imageTagListener result
     */
    public void detectImage(Bitmap bitmap, Size modelInputSize, ImageTagListener imageTagListener) {
        IMAGE_SIZE_X = modelInputSize.getWidth();
        IMAGE_SIZE_Y = modelInputSize.getHeight();
        if (imageTagListener != null) {
            mImageTagListener = imageTagListener;
        }
        if (bitmap != null) {
            new ComputeTask().execute(bitmap);
        }
    }

    @SuppressLint("StaticFieldLeak")
    private class ComputeTask extends AsyncTask<Bitmap, Void, String> {
        @Override
        protected String doInBackground(Bitmap... inputs) {
            // Reusing the same prepared model with different inputs.
            return classifyFrame(inputs[0]);
        }

        @Override
        protected void onPostExecute(String result) {
            DataHolder.getInstance().setRequesting(false);
            recognitionList = new ArrayList<>();
            if (result != null && result.length() > 0) {
                try {
                    JSONArray productArr = new JSONArray(result);
                    for (int i = 0; i < productArr.length(); i++) {
                        JSONObject productObj = new JSONObject(String.valueOf(productArr.getJSONObject(i)));
                        String objectName = (String) productObj.get("productName");
                        String rectStr = (String) productObj.get("rect");
                        String[] rectList = rectStr.split(",");
                        Recognition recognition = new Recognition();
                        Recognition.Rect rect = new Recognition.Rect(Double.parseDouble(rectList[0]) / IMAGE_SIZE_X, Double.parseDouble(rectList[1]) / IMAGE_SIZE_Y,
                                Double.parseDouble(rectList[2]) / IMAGE_SIZE_X, Double.parseDouble(rectList[3]) / IMAGE_SIZE_Y);
                        recognition.setObjectName(objectName);
                        recognition.setRect(rect);
                        recognitionList.add(recognition);
                    }
                    DataHolder.getInstance().setRecognitionList(recognitionList);
                } catch (Exception e) {
                    e.printStackTrace();
                }
                showTags();
            } else {
                Recognition recognition = new Recognition();
                Recognition.Rect rect = new Recognition.Rect(0.5, 0.5, 0.5, 0.5);
                recognition.setObjectName(null);
                recognition.setRect(rect);
                recognitionList.add(recognition);
                DataHolder.getInstance().setRecognitionList(recognitionList);
                showTags();
                LogHelper.i(TAG,"Query for similar images");
            }
        }
    }

    //endregion
    private void showTags() {
        ArrayList<ImageTag> imageTags = new ArrayList<>();
        recognitionList = DataHolder.getInstance().getRecognitionList();
        if (recognitionList != null && recognitionList.size() > 0) {
            for (int i = 0; i < recognitionList.size(); i++) {
                ImageTag imageTag = new ImageTag();
                imageTag.setLeft((float) recognitionList.get(i).getRect().getLeft());
                imageTag.setTop((float) recognitionList.get(i).getRect().getTop());
                imageTag.setRight((float) recognitionList.get(i).getRect().getRight());
                imageTag.setBottom((float) recognitionList.get(i).getRect().getBottom());
                imageTag.setCategory(recognitionList.get(i).getObjectName());
                imageTags.add(imageTag);
            }
            if (mImageTagListener != null) {
                mImageTagListener.updateImageTags(imageTags);
            }
        }
    }

    @SuppressLint("UseSparseArrays")
    private String classifyFrame(Bitmap bitmap) {
        if (bitmap == null) {
            LogHelper.e(TAG,"Image recognition failure!!");
            return null;
        }
        try {
            int BYTE_NUM_PER_CHANNEL = 1;
            imgData = ByteBuffer.allocateDirect(DIM_BATCH_SIZE * IMAGE_SIZE_X
                    * IMAGE_SIZE_Y * DIM_PIXEL_SIZE
                    * BYTE_NUM_PER_CHANNEL);
            intValues = new int[IMAGE_SIZE_X * IMAGE_SIZE_Y];

            Bitmap scaledBmp = Bitmap.createScaledBitmap(bitmap, IMAGE_SIZE_X, IMAGE_SIZE_Y, false);
            imgData = convertBitmapToByteBuffer(scaledBmp);
            long startTime = SystemClock.uptimeMillis();
            String result = "";
            if (imgData != null && imgData.position() > 0) {
                result = NativeImageDetect.compute(imgData, imgData.position(), Const.MODEL_TYPE_0);
                if (result == null || result.length() <= 0) {
                    String result1 = NativeImageDetect.compute(imgData, imgData.position(), Const.MODEL_TYPE_1);
                    if (result1 == null || result1.length() <= 0) {
                        return null;//"JNI On failure";
                    } else {
                        result = result1;
                    }
                }
            }

            // Print the results.
            long endTime = SystemClock.uptimeMillis();
            LogHelper.d(TAG, "classifyFrame run time: " + (endTime - startTime) + "ms");
            LogHelper.d(TAG, "classifyFrame run result: " + result);
            LogHelper.d(TAG, "Image recognition successful!!");
            return result;
        } catch (Exception e) {
            e.printStackTrace();
            LogHelper.e(TAG, "compute failed " + e.toString());
        }
        return null;
    }

    /**
     * Writes Image data into a {@code ByteBuffer}.
     */
    private ByteBuffer convertBitmapToByteBuffer(Bitmap bitmap) {
        if (imgData == null) {
            return null;
        }
        long startTime = SystemClock.uptimeMillis();
        //FileUtil.saveBitmap(bitmap, SystemClock.uptimeMillis()+"_300.png");
        imgData.rewind();
        bitmap.getPixels(intValues, 0, bitmap.getWidth(), 0, 0, bitmap.getWidth(), bitmap.getHeight());
        // Convert the image to floating point.
        for (int i = 0; i < IMAGE_SIZE_X; ++i) {
            for (int j = 0; j < IMAGE_SIZE_Y; ++j) {
                final int val = intValues[i * IMAGE_SIZE_X + j];
                addPixelValue(val);
            }
        }
        long endTime = SystemClock.uptimeMillis();
        return imgData;
    }

    private void addPixelValue(int pixelValue) {
        imgData.put((byte) ((pixelValue >> 16) & 0xFF));
        imgData.put((byte) ((pixelValue >> 8) & 0xFF));
        imgData.put((byte) (pixelValue & 0xFF));
    }

    public void onDestroy() {
        NativeImageDetect.destroyModel();
    }

    public interface ImageTagListener {
        void updateImageTags(ArrayList<ImageTag> imageTags);
    }
}
