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

package com.mediatek.camera.feature.mode.visualsearch.activity;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Rect;
import android.graphics.drawable.BitmapDrawable;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Size;
import android.view.KeyEvent;
import android.view.TouchDelegate;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.mediatek.camera.R;
import com.mediatek.camera.common.utils.CameraUtil;
import com.mediatek.camera.feature.mode.visualsearch.bean.DataHolder;
import com.mediatek.camera.feature.mode.visualsearch.bean.ImageTag;
import com.mediatek.camera.feature.mode.visualsearch.utils.CommonUtils;
import com.mediatek.camera.feature.mode.visualsearch.utils.Const;
import com.mediatek.camera.feature.mode.visualsearch.utils.FileUtil;
import com.mediatek.camera.feature.mode.visualsearch.manager.VisualSearchManager;
import com.mediatek.camera.feature.mode.visualsearch.view.ImagePointsCropView;
import com.visualsearch.RectDataInfo;

import com.mediatek.camera.common.debug.LogHelper;
import com.mediatek.camera.common.debug.LogUtil;

import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ImageParseActivity extends WithLoadingActivity {

    private static final LogUtil.Tag TAG = new LogUtil.Tag(ImageParseActivity.class.getSimpleName());
    //region variable view
    private ImagePointsCropView ivPreview = null;
    private ImageView img_back_top = null;
    private TextView tv_tip = null;
    private ImageView confirmView = null;
    private ImageView showCropImageView = null;
    private Bitmap mRotatedBmp;

    private ArrayList<ImageTag> imageTags = new ArrayList<>();
    private Uri mUri;
    private int mFlag;
    private Activity mActivity;

    public static final int STATE_REQUEST_CODE = 10000;
    public static final int STATE_CAMERA_TAKE = 2;
    public static final int STATE_CAMERA_REQUEST_IMAGES_COMPLETED = 3;
    private static final String FRONT_CAMERA_ID = "1";
    private static final String BACK_CAMERA_ID = "0";
    //false: click imagetag to third party app    true:click imagetag to show current cropview
    public static boolean SHOW_CROP_VIEW = false;
    //Click the event interval
    private long startClickTime = System.currentTimeMillis();
    private boolean isDetectImageFinished = false;
    private ExecutorService singleThreadExecutor  = Executors.newSingleThreadScheduledExecutor();

    //region activity life
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_image_parse);
        isDetectImageFinished = false;
        mActivity = this;
        initView();
        initData();
        initListener();
    }

    private void initData() {
        SHOW_CROP_VIEW = false;
        mUri = DataHolder.getInstance().getUri();
        mFlag = DataHolder.getInstance().getFlag();
        switchUIState(STATE_CAMERA_TAKE);
        new ByteDataToBitmapAsyncTask().execute();

    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        LogHelper.d(TAG, "onDestroy");
        try {
            singleThreadExecutor.shutdownNow();
        } catch (Exception e) {
            singleThreadExecutor.shutdownNow();
            e.printStackTrace();
        }
    }

    public static void startActivity(Context context) {
        Intent intent = new Intent(context, ImageParseActivity.class);
        intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        context.startActivity(intent);
    }

    private void initView() {
        ivPreview = findViewById(R.id.ivPreview);
        img_back_top = findViewById(R.id.img_back_top);
        expandViewTouchDelegate(img_back_top);
        tv_tip = findViewById(R.id.tv_tip);
        confirmView = findViewById(R.id.confirm_iv);
        showCropImageView = findViewById(R.id.crop_show_iv);
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        Rect frame = new Rect();
        getWindow().getDecorView().getWindowVisibleDisplayFrame(frame);
    }

    private void expandViewTouchDelegate(final View view) {

        ((View) view.getParent()).post(new Runnable() {
            @Override
            public void run() {
                Rect bounds = new Rect();
                view.setEnabled(true);
                view.getHitRect(bounds);
                int rect = 400;
                bounds.top -= rect;
                bounds.bottom += rect;
                bounds.left -= rect;
                bounds.right += rect;

                TouchDelegate touchDelegate = new TouchDelegate(bounds, view);

                if (view.getParent() instanceof View) {
                    ((View) view.getParent()).setTouchDelegate(touchDelegate);
                }
            }
        });
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if ((keyCode == KeyEvent.KEYCODE_BACK)) {
            if (DataHolder.getInstance().isComputeFinished()) {
                finish();
                return super.onKeyDown(keyCode, event);
            }
            return false;
        } else {
            return super.onKeyDown(keyCode, event);
        }
    }

    private void initListener() {

        img_back_top.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (DataHolder.getInstance().isComputeFinished()) {
                    img_back_top.setVisibility(View.GONE);
                    imageTags = null;
                    finish();
                }
            }
        });

        //show crop view
        showCropImageView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                SHOW_CROP_VIEW = true;
                if (ivPreview != null) {
                    ivPreview.isCropView = true;
                    confirmView.setVisibility(View.VISIBLE);
                    showCropImageView.setVisibility(View.GONE);
                    ivPreview.setDrawable(null, 0);
                    Bitmap bitmap = ivPreview.convertViewToBitmap(ivPreview);
                    if (bitmap != null) {
                        ivPreview.setDrawable(new BitmapDrawable(getResources(), bitmap), 0);
                        ivPreview.invalidate();
                    } else {
                        LogHelper.e(TAG, "showCropImageViewOnClick bitmap is null");
                    }
                } else {
                    LogHelper.e(TAG, "showCropImageViewOnClick ivPreview is null");
                }
            }
        });
        //confirm
        confirmView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                long clickInterval = System.currentTimeMillis() - startClickTime;
                if (imageTags != null && imageTags.size() > 0
                        && mRotatedBmp != null && clickInterval > 1000) {
                    startClickTime = System.currentTimeMillis();
                    ArrayList<RectDataInfo> rectList = CommonUtils.getRectList(imageTags, ivPreview.getCropImageRect(),
                        ivPreview.getWidth(), ivPreview.getHeight());
                    CommonUtils.toLauncherApp(mActivity, mRotatedBmp, rectList);
                }
            }
        });

        ivPreview.setOnClickTagListener(new ImagePointsCropView.OnClickTagListener() {
            @Override
            public void clickTag(final int position) {
                if (SHOW_CROP_VIEW) {
                    if (ivPreview != null) {
                        ivPreview.isCropView = false;
                        ivPreview.setDrawable(null, position);
                        Bitmap bitmap = ivPreview.convertViewToBitmap(ivPreview);
                        if (bitmap != null) {
                            ivPreview.setDrawable(new BitmapDrawable(getResources(), bitmap), position);
                            ivPreview.invalidate();
                        } else {
                            LogHelper.e(TAG, "ivPreviewOnClick bitmap is null");
                        }
                    } else {
                        LogHelper.e(TAG, "ivPreviewOnClick ivPreview is null");
                    }
                } else {
                    long clickInterval = System.currentTimeMillis() - startClickTime;
                    if (imageTags != null && imageTags.size() > 0
                            && mRotatedBmp != null && clickInterval > 1000) {
                        startClickTime = System.currentTimeMillis();
                        ArrayList<RectDataInfo> rectList = CommonUtils.getRectListByClickTag(imageTags, position);
                        CommonUtils.toLauncherApp(mActivity, mRotatedBmp, rectList);
                    }
                }
            }
        });
    }

    @SuppressLint("StaticFieldLeak")
    class ByteDataToBitmapAsyncTask extends AsyncTask<byte[], Integer, Bitmap> {

        @Override
        protected Bitmap doInBackground(byte[]... bytes) {
            try {
                return parseBitmap();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return null;
        }

        @Override
        protected void onPostExecute(Bitmap bitmap) {
            super.onPostExecute(bitmap);
            if (bitmap != null && bitmap.getWidth() > 0 && bitmap.getHeight() > 0) {
                mRotatedBmp = bitmap;
                initImage(bitmap);
            } else {
                switchUIState(STATE_CAMERA_REQUEST_IMAGES_COMPLETED);
                LogHelper.d(TAG, "onPostExecute bitmap is null");
                Toast.makeText(mActivity, "image loading failed,return preview", Toast.LENGTH_SHORT).show();
                finish();
            }
        }
    }

    private Bitmap parseBitmap() {
        Bitmap rotatedBmp;
        int jpeg_orientation;
        int orientation = 0;
        String cameraId = DataHolder.getInstance().getCameraId();
        if (mFlag == 0) {
            try {
                if (mUri != null) {
                    rotatedBmp = FileUtil.getBitmapFromUri(mActivity, mUri);
                    jpeg_orientation = FileUtil.getExifOrientation(FileUtil.getFilePathFromUri(mActivity, mUri));
                    LogHelper.d(TAG, "jpeg_orientation = " + jpeg_orientation);
                    rotatedBmp =  CommonUtils.rotatePreviewBitmap(rotatedBmp, jpeg_orientation);
                    int screenWidth = CommonUtils.getScreenWidth(mActivity);
                    int screenHeight = CommonUtils.getScreenHeight(mActivity);
                    int rotBmpWidth = rotatedBmp.getWidth();
                    int rotBmpHeight = rotatedBmp.getHeight();
                    float rotBmpScale = (float) rotBmpWidth / rotBmpHeight;
                    float screenScale = (float) screenWidth / screenHeight;

                    if (rotBmpScale != screenScale && rotBmpWidth > screenWidth) {
                        int newBitmapWidth = Math.min(rotBmpWidth, screenWidth);
                        rotatedBmp = scaleBitmap(rotatedBmp, newBitmapWidth, rotBmpScale);
                    } else {
                        int newBitmapWidth = Math.max(rotBmpWidth, screenWidth);
                        rotatedBmp = scaleBitmap(rotatedBmp, newBitmapWidth, rotBmpScale);
                    }
                    if (rotatedBmp != null) {
                        DataHolder.getInstance().setImageData(CommonUtils.bitmapToByte(rotatedBmp));
                        LogHelper.d(TAG, "parseBitmap rotatedBmp = " + rotatedBmp.getWidth() + " x " + rotatedBmp.getHeight());
                        return rotatedBmp;
                    } else {
                        LogHelper.e(TAG, "rotatedBmp is null");
                        return null;
                    }
                } else {
                    LogHelper.e(TAG, "mUri is null");
                    return null;
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        } else {
            byte[] bitmapByte = DataHolder.getInstance().getImageData();
            if (bitmapByte != null) {
                jpeg_orientation = CameraUtil.getOrientationFromSdkExif(bitmapByte);
                LogHelper.d(TAG, "[parseBitmap] jpeg_orientation " + jpeg_orientation);
                if (jpeg_orientation != 0) {
                    orientation = 90;
                    if (cameraId.equals(FRONT_CAMERA_ID)) {
                        orientation = jpeg_orientation;
                    }
                }
                LogHelper.d(TAG, "[parseBitmap] orientation " + orientation);
                rotatedBmp = CommonUtils.rotatePreviewBitmap(
                    BitmapFactory.decodeByteArray(bitmapByte, 0, bitmapByte.length),
                    orientation);
                LogHelper.d(TAG, "parseBitmap rotatedBmp = " + rotatedBmp.getWidth() + " x " + rotatedBmp.getHeight());
                return rotatedBmp;
            } else {
                LogHelper.e(TAG, "bitmapByte is null");
                return null;
            }
        }
        return null;
    }

    private void initImage(Bitmap bitmap) {
        if (bitmap == null) {
            LogHelper.e(TAG, "bitmapByte is null");
            switchUIState(STATE_CAMERA_REQUEST_IMAGES_COMPLETED);
            return;
        }
        if (ivPreview == null) {
            LogHelper.e(TAG, "ivPreview is null");
            switchUIState(STATE_CAMERA_REQUEST_IMAGES_COMPLETED);
            return;
        }
        if (!DataHolder.getInstance().isInitFinished()) {
            switchUIState(STATE_CAMERA_REQUEST_IMAGES_COMPLETED);
            return;
        }
        ivPreview.setBackground(new BitmapDrawable(getResources(), bitmap));
        ivPreview.setScaleType(ImageView.ScaleType.FIT_XY);
        ivPreview.setAdjustViewBounds(true);
        Size size = new Size(bitmap.getWidth(), bitmap.getHeight());
        ivPreview.setSize(size);
        CommonUtils.setImageWH(mActivity, mFlag, ivPreview, bitmap.getWidth(), bitmap.getHeight());
        Size modelInputSize = new Size(Const.IMAGE_SIZE_WIDTH, Const.IMAGE_SIZE_HEIGHT);
        //FileUtil.saveBitmap(bitmap, "capture_" + SystemClock.uptimeMillis() + ".jpg");
        LogHelper.d(TAG, "ImageParseActivity detectImage");
        isDetectImageFinished = false;
        DataHolder.getInstance().setComputeFinished(isDetectImageFinished);
        singleThreadExecutor.execute(new Runnable() {
            @Override
            public void run() {
                VisualSearchManager.getInstance().detectImage(bitmap, modelInputSize, new VisualSearchManager.ImageTagListener() {
                    @Override
                    public void updateImageTags(ArrayList<ImageTag> tags) {
                        isDetectImageFinished = true;
                        DataHolder.getInstance().setComputeFinished(isDetectImageFinished);
                        if (tags != null && tags.size() > 0) {
                            LogHelper.d(TAG, "Visual Search Succeed: = " + tags.size());
                            if (imageTags == null) {
                                imageTags = new ArrayList<>();
                            }
                            imageTags.clear();
                            imageTags.addAll(tags);
                            runOnUiThread(new Runnable() {
                                @Override
                                public void run() {
                                    switchUIState(STATE_CAMERA_REQUEST_IMAGES_COMPLETED);
                                    tv_tip.setVisibility(View.VISIBLE);
                                    ivPreview.drawImageTagRegion = true;
                                    ivPreview.setImageTags(imageTags);
                                }
                            });
                        } else {
                            LogHelper.d(TAG, "Visual Search Failed");
                            runOnUiThread(new Runnable() {
                                @Override
                                public void run() {
                                    switchUIState(STATE_CAMERA_REQUEST_IMAGES_COMPLETED);
                                    Toast.makeText(mActivity, "Visual Search Failed", Toast.LENGTH_SHORT).show();
                                }
                            });
                        }
                    }
                });
            }
        });
    }

    /**
     * Scale according to the width and height of the screen
     *
     * @param originBitmap origin bitmap
     * @param newWidth     new width
     * @param scale        origin bitmap scale
     * @return new Bitmap
     */
    private Bitmap scaleBitmap(Bitmap originBitmap, int newWidth, float scale) {

        if (originBitmap == null) {
            LogHelper.e(TAG, "originBitmap is null");
            return null;
        }
        int newHeight = (int) (newWidth / scale);
        Bitmap newBitmap = Bitmap.createScaledBitmap(originBitmap, newWidth, newHeight, true);
        if (!originBitmap.isRecycled()) {
            originBitmap.recycle();
        }
        return newBitmap;
    }

    //region update UI
    private void switchUIState(int stateCameraTaken) {
        switch (stateCameraTaken) {
            case STATE_CAMERA_TAKE:
                showLoadingDialog();
                break;
            case STATE_CAMERA_REQUEST_IMAGES_COMPLETED:
                dismissLoadingDialog();
                break;
        }
    }

}