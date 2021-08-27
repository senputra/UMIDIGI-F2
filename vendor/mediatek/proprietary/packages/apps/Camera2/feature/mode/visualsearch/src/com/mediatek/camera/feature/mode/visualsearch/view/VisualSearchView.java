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

package com.mediatek.camera.feature.mode.visualsearch.view;

import android.os.Build;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.support.annotation.NonNull;
import android.support.v4.content.ContextCompat;
import android.view.View;
import android.view.ViewGroup;
import android.graphics.Bitmap;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.BitmapFactory;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.RelativeLayout;
import android.widget.LinearLayout;
import android.provider.Settings;
import android.content.ActivityNotFoundException;
import android.net.Uri;

import com.mediatek.camera.R;
import com.mediatek.camera.common.IAppUi;
import com.mediatek.camera.common.ICameraContext;
import com.mediatek.camera.common.app.IApp;
import com.mediatek.camera.common.debug.LogHelper;
import com.mediatek.camera.common.relation.DataStore;
import com.mediatek.camera.common.widget.RotateImageView;
import com.mediatek.camera.common.widget.PreviewFrameLayout;

import com.mediatek.camera.feature.mode.visualsearch.activity.ImageParseActivity;
import com.mediatek.camera.feature.mode.visualsearch.bean.ImageTag;
import com.mediatek.camera.feature.mode.visualsearch.view.ImagePointsView;
import com.mediatek.camera.feature.mode.visualsearch.view.LoadingAnimationView;
import com.mediatek.camera.feature.mode.visualsearch.bean.DataHolder;
import com.mediatek.camera.feature.mode.visualsearch.utils.Const;
import com.mediatek.camera.feature.mode.visualsearch.utils.FileUtil;
import com.mediatek.camera.feature.mode.visualsearch.utils.CommonUtils;
import com.visualsearch.RectDataInfo;
import android.content.Intent;
import android.provider.MediaStore;

import java.util.ArrayList;


public class VisualSearchView implements View.OnClickListener {
    private static final String TAG = VisualSearchView.class.getSimpleName();
    private View mRootView;
    private PreviewFrameLayout mPreviewFrameLayout;
    private View mThumbnailIndicator;
    private ImagePointsView mIvPreview;
    private TextView tv_tip;
    private ViewGroup mParentViewGroup;
    private ArrayList<ImageTag> mImageTags;
    private Bitmap mBitmap;
    private ICameraContext mICameraContext;
    private RelativeLayout layoutPreviewPoint = null;
    private LoadingAnimationView loadingAnimationView1 = null;
    private LoadingAnimationView loadingAnimationView2 = null;
    private LoadingAnimationView loadingAnimationView3 = null;
    private LoadingAnimationView loadingAnimationView4 = null;

    // circlePaint radius
    private static final int CIRCLE_PAINT_RADIUS_FOUR = 4;
    private static final int CIRCLE_PAINT_RADIUS_SIX = 6;
    private static final int CIRCLE_PAINT_RADIUS_SEVEN = 7;
    private static final int CIRCLE_PAINT_RADIUS_EIGHT = 8;
    // circlePaint animation refresh time
    private static final int CIRCLE_PAINT_DELAYED_ANIMATION_TIME = 50;
    // Display the location of the circlePaint according to orientation
    private static final int CIRCLE_PAINT_SHOW_LOCAL_TOP = 0;
    private static final int CIRCLE_PAINT_SHOW_ORIENTATION_BOTTOM = 1;

    private IApp mApp;

    private RotateImageView mIvThumbnailBnt = null;
    //Click the event interval
    private long startClickTime = System.currentTimeMillis();

    /**
     * The constructor of panorama view.
     *
     * @param app      the instance of IApp.
     * @param cameraId the camera id.
     */
    public VisualSearchView(@NonNull IApp app, ICameraContext cameraContext) {
        mApp = app;
        mParentViewGroup = app.getAppUi().getModeRootView();
        mPreviewFrameLayout = app.getAppUi().getPreviewFrameLayout();
        mICameraContext = cameraContext;
        mApp.getAppUi().setUIVisibility(IAppUi.THUMBNAIL, View.GONE);
        mApp.getAppUi().setUIVisibility(IAppUi.SHUTTER_BUTTON, View.VISIBLE);
    }

    /**
     * init AIVisualSearch view.
     */
    public void init() {
        getView();
    }

    public void updateThumbnail(final Bitmap bitmap) {
        if (mIvThumbnailBnt != null && bitmap != null) {
            mApp.getActivity().runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    mIvThumbnailBnt.setImageBitmap(bitmap);
                }
            });
        }

    }

    /**
     * show AIVisualSearch view.
     */
    public void show() {
        if (mRootView == null) {
            mRootView = getView();
        }
        mRootView.setVisibility(View.VISIBLE);
        mApp.getAppUi().setUIVisibility(IAppUi.THUMBNAIL, View.GONE);
        //mApp.getAppUi().applyAllUIVisibility(View.VISIBLE);
        mApp.getAppUi().setUIVisibility(IAppUi.SHUTTER_BUTTON, View.VISIBLE);
        mApp.getAppUi().setUIVisibility(IAppUi.SCREEN_HINT, View.VISIBLE);
    }

    /**
     * hide AIVisualSearch view.
     */
    public void hide() {
        if (mRootView == null) {
            return;
        }
        mRootView.setVisibility(View.GONE);
        mApp.getAppUi().applyAllUIVisibility(View.VISIBLE);
        clearPoints();
    }

    /**
     * will be called when app call release() to unload views from view
     * hierarchy.
     *
     */
    public void unInit() {
        if (mParentViewGroup != null) {
            mParentViewGroup.removeView(mRootView);
            mRootView = null;
            mParentViewGroup = null;
        }
        clearPoints();
    }

    /**
     * reset AIVisualSearch view.
     */
    public void reset() {
        if (mRootView == null) {
            return;
        }
    }

    /**
     * update RecognitionList Local
     */
    public void updatePoints(ArrayList<ImageTag> imageTags, Bitmap bitmap, int previewHeight, int previewWidth) {
        layoutPreviewPoint.setVisibility(View.GONE);
        mBitmap = bitmap;
        mImageTags = imageTags;
        mIvPreview.setScaleType(ImageView.ScaleType.FIT_XY);
        mIvPreview.setAdjustViewBounds(true);
        android.util.Size sizeU = new android.util.Size(previewWidth, previewHeight);
        mIvPreview.setSize(sizeU);
        CommonUtils.setImageWH(mApp.getActivity(), 1, mIvPreview, bitmap.getWidth(), bitmap.getHeight());
        // mIvPreview.setBackground(new BitmapDrawable(mApp.getActivity().getResources(), bitmap));
        mIvPreview.drawImageTagRegion = true;
        if (imageTags.size() > 0) {
            mIvPreview.mImageTagCount = imageTags.size();
            mIvPreview.setImageTags(imageTags);
        }
        tv_tip.setText(mApp.getActivity().getString(R.string.please_select_your_target_product));
    }

    /**
     * clear goods points
     */
    public void clearPoints() {
        mApp.getActivity().runOnUiThread(new Runnable(){
            @Override
            public void run(){
                layoutPreviewPoint.setVisibility(View.VISIBLE);
            }
        });

        if (mIvPreview != null && mImageTags != null && mImageTags.size() > 0) {
            mImageTags.clear();
            mIvPreview.mImageTagCount = mImageTags.size();
            mIvPreview.setImageTags(mImageTags);
            mApp.getActivity().runOnUiThread(new Runnable(){
                @Override
                public void run(){
                    tv_tip.setText(mApp.getActivity().getString(R.string.please_aim_at_your_target_product));
                }
            });
        }
    }

    /**
     * will be called if app want to show current view which hasn't been
     * created.
     *
     * @return
     */
    private View getView() {

        // View pointsLayout = mApp.getActivity().getLayoutInflater().inflate(R.layout.points_layout,
        //         mPreviewFrameLayout, true);

        View viewLayout = mApp.getActivity().getLayoutInflater()
            .inflate(R.layout.aithumbnail_indicator, mParentViewGroup, true);
        mRootView = viewLayout.findViewById(R.id.ai_root_view);
        mIvPreview = viewLayout.findViewById(R.id.ivPreview);

        mIvPreview.setOnClickTagListener(new ImagePointsView.OnClickTagListener() {
            @Override
            public void clickTag(int position) {
                long clickInterval = System.currentTimeMillis() - startClickTime;
                if (mImageTags != null && mImageTags.size() > 0
                        && mBitmap != null && clickInterval > 1000) {
                    startClickTime = System.currentTimeMillis();
                    ArrayList<RectDataInfo> rectListList = CommonUtils.getRectListByClickTag(mImageTags, position);
                    CommonUtils.toLauncherApp(mApp.getActivity(), mBitmap, rectListList);
                }
            }
        });
        tv_tip = viewLayout.findViewById(R.id.tv_tip);
        mThumbnailIndicator = viewLayout.findViewById(R.id.thumbnail_indicator);
        mIvThumbnailBnt = viewLayout.findViewById(R.id.iv_aiThumbnail);
        mIvThumbnailBnt.setOnClickListener(this);
        layoutPreviewPoint = viewLayout.findViewById(R.id.layoutPreviewPoint);
        // loadingAnimationView1 = viewLayout.findViewById(R.id.loadingAnimationView1);
        // loadingAnimationView2 = viewLayout.findViewById(R.id.loadingAnimationView2);
        // loadingAnimationView3 = viewLayout.findViewById(R.id.loadingAnimationView3);
        // loadingAnimationView4 = viewLayout.findViewById(R.id.loadingAnimationView4);
        // loadingAnimationView1.init(CIRCLE_PAINT_RADIUS_FOUR, CIRCLE_PAINT_DELAYED_ANIMATION_TIME, CIRCLE_PAINT_SHOW_LOCAL_TOP);
        // loadingAnimationView2.init(CIRCLE_PAINT_RADIUS_SIX, CIRCLE_PAINT_DELAYED_ANIMATION_TIME, CIRCLE_PAINT_SHOW_ORIENTATION_BOTTOM);
        // loadingAnimationView3.init(CIRCLE_PAINT_RADIUS_EIGHT, CIRCLE_PAINT_DELAYED_ANIMATION_TIME, CIRCLE_PAINT_SHOW_LOCAL_TOP);
        // loadingAnimationView4.init(CIRCLE_PAINT_RADIUS_SEVEN, CIRCLE_PAINT_DELAYED_ANIMATION_TIME, CIRCLE_PAINT_SHOW_ORIENTATION_BOTTOM);
        return mRootView;
    }

    public void startLoadingPoints() {
        if (loadingAnimationView1 != null ) {
            loadingAnimationView1.start();
        }

        if (loadingAnimationView2 != null ) {
            loadingAnimationView2.start();
        }

        if (loadingAnimationView3 != null ) {
            loadingAnimationView3.start();
        }

        if (loadingAnimationView4 != null ) {
            loadingAnimationView4.start();
        }
    }

    public void stopLoadingPoints() {
        if (loadingAnimationView1 != null ) {
            loadingAnimationView1.stop();
        }

        if (loadingAnimationView2 != null ) {
            loadingAnimationView2.stop();
        }

        if (loadingAnimationView3 != null ) {
            loadingAnimationView3.stop();
        }

        if (loadingAnimationView4 != null ) {
            loadingAnimationView4.stop();
        }
    }

    @Override
    public void onClick(View view) {
        clearPoints();
        toGallery();
    }

    //to system album
    private void toGallery() {
        DataHolder.getInstance().setRequesting(false);
        DataHolder.getInstance().setIsResumed(false);
        Intent intent = new Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
        intent.setDataAndType(MediaStore.Images.Media.EXTERNAL_CONTENT_URI, "image/*");
        mApp.getActivity().startActivityForResult(intent, ImageParseActivity.STATE_REQUEST_CODE);
    }

}