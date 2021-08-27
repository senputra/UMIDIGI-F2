/*
 * Copyright Statement:
 *
 *   This software/firmware and related documentation ("MediaTek Software") are
 *   protected under relevant copyright laws. The information contained herein is
 *   confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 *   the prior written permission of MediaTek inc. and/or its licensors, any
 *   reproduction, modification, use or disclosure of MediaTek Software, and
 *   information contained herein, in whole or in part, shall be strictly
 *   prohibited.
 *
 *   MediaTek Inc. (C) 2016. All rights reserved.
 *
 *   BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *   THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 *   RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 *   ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 *   WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 *   WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 *   NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 *   RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *   INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 *   TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 *   RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 *   OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 *   SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 *   RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 *   STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 *   ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 *   RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 *   MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 *   CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *   The following software/firmware and/or related documentation ("MediaTek
 *   Software") have been modified by MediaTek Inc. All revisions are subject to
 *   any receiver's applicable license agreements with MediaTek Inc.
 */

package com.mediatek.camera.feature.setting.visualsearch;

import android.app.Activity;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.content.res.Resources;

import com.mediatek.camera.R;
import com.mediatek.camera.common.IAppUiListener;
import com.mediatek.camera.common.app.IApp;
import com.mediatek.camera.common.debug.LogHelper;
import com.mediatek.camera.common.debug.LogUtil;
import com.mediatek.camera.common.utils.CameraUtil;
import com.mediatek.camera.common.widget.RotateImageView;

import javax.annotation.Nonnull;


/**
 * HdrViewController used to control hdr ui and send view click item
 * to hdr.
 */

public class VisualSearchSettingViewController {

    /**
     * Mode change listener, when a mode is selected, notify the new mode.
     */
    public interface OnAIModeChangedListener {
        /**
         * Notify the new mode info.
         *
         * @param modeName The selected mode item.
         */
        void onModeChanged(String modeName);
    }

    private static final LogUtil.Tag TAG =
            new LogUtil.Tag(VisualSearchSettingViewController.class.getSimpleName());

    private static final int AI_PRIORITY = 60;
    private static final int AI_SHUTTER_PRIORITY = 80;
    private static final String AI_OFF_VALUE = "off";
    private static final String AI_ON_VALUE = "on";

    private static final int AI_VIEW_INIT = 0;
    private static final int AI_VIEW_ADD_QUICK_SWITCH = 1;
    private static final int AI_VIEW_REMOVE_QUICK_SWITCH = 2;
    private static final int AI_VIEW_UPDATE_INDICATOR = 3;
    private static final int AI_VIEW_UPDATE_QUICK_SWITCH_ICON = 4;


    private ImageView mAiEntryView;
    private MainHandler mMainHandler;
    private final IApp mApp;

    private int mFlag = 0;
    private String modeName = "AI";
    private Resources mResources = null;
    private String mViewState = AI_OFF_VALUE;

    /**
     * The constructor.
     *
     * @param app IApp.
     *
     */
    public VisualSearchSettingViewController(IApp app) {
        mApp = app;
        mResources = mApp.getActivity().getResources();
        mMainHandler = new MainHandler(app.getActivity().getMainLooper());
        mMainHandler.sendEmptyMessage(AI_VIEW_INIT);
        mViewState = AI_OFF_VALUE;
    }

    /**
     * add flash switch to quick switch.
     */
    public void addQuickSwitchIcon() {
        if (CameraUtil.isChangeIconState()) {
            mViewState = AI_ON_VALUE;
        } else {
            mViewState = AI_OFF_VALUE;
        }
        mMainHandler.sendEmptyMessage(AI_VIEW_ADD_QUICK_SWITCH);
    }

    /**
     * remove quick switch icon.
     */
    public void removeQuickSwitchIcon() {
        mMainHandler.sendEmptyMessage(AI_VIEW_REMOVE_QUICK_SWITCH);
    }

    /**
     * for overrides value, for set visibility.
     *
     * @param isShow true means show.
     */
    public void showQuickSwitchIcon(boolean isShow) {
        mMainHandler.obtainMessage(AI_VIEW_UPDATE_QUICK_SWITCH_ICON, isShow).sendToTarget();
    }


    /**
     * show visualsearch indicator.
     *
     * @param isShow true means show.
     */
    public void showVisualSearchSettingIndicator(boolean isShow) {
        mMainHandler.obtainMessage(AI_VIEW_UPDATE_INDICATOR, isShow).sendToTarget();
    }

    /**
     * Handler let some task execute in main thread.
     */
    private class MainHandler extends Handler {
        public MainHandler(Looper looper) {
            super(looper);
        }

        @Override
        public void handleMessage(Message msg) {
            switch (msg.what) {
                case AI_VIEW_INIT:
                    mAiEntryView = initVisualSearchSettingEntryView();
                    break;

                case AI_VIEW_ADD_QUICK_SWITCH:
                    mApp.getAppUi().addToQuickSwitcher(mAiEntryView, AI_PRIORITY);
                    updateAiViewState(mViewState);
                    mApp.getAppUi().registerOnShutterButtonListener(
                            mShutterListener, AI_SHUTTER_PRIORITY);

                    break;

                case AI_VIEW_REMOVE_QUICK_SWITCH:
                    mApp.getAppUi().removeFromQuickSwitcher(mAiEntryView);
                    mApp.getAppUi().unregisterOnShutterButtonListener(mShutterListener);
                    break;

                case AI_VIEW_UPDATE_QUICK_SWITCH_ICON:
                    if ((boolean) msg.obj) {
                        mAiEntryView.setVisibility(View.VISIBLE);
                    } else {
                        mAiEntryView.setVisibility(View.GONE);
                    }
                    break;

                case AI_VIEW_UPDATE_INDICATOR:
                    break;

                default:
                    break;
            }
        }
    }

    /**
     * Initialize the hdr view which will add to quick switcher.
     *
     * @return the view add to quick switcher
     */
    private ImageView initVisualSearchSettingEntryView() {
        Activity activity = mApp.getActivity();
        RotateImageView view = (RotateImageView) activity.getLayoutInflater().inflate(
                R.layout.ai_icon, null);
        view.setOnClickListener(mAiEntryListener);
        return view;
    }


    /**
     * This listener used to monitor the hdr quick switch icon click item.
     */
    private final View.OnClickListener mAiEntryListener = new View.OnClickListener() {
        @Override
        public void onClick(View view) {
            mViewState = AI_ON_VALUE;
            mApp.getAppUi().isChangedMode(true,mFlag);
            mFlag = mFlag + 1;
        }

    };

    public void setOnModeChangedListener(OnAIModeChangedListener listener,int flag) {

        if (flag % 2 == 0) {
            CameraUtil.setChangeIconState(true);
        } else {
            CameraUtil.setChangeIconState(false);
        }
        if (CameraUtil.isChangeIconState()) {
            modeName = mResources.getString(mResources.getIdentifier("visual_search_mode_title",
            "string", mApp.getActivity().getPackageName()));
            listener.onModeChanged(modeName);
            mViewState = AI_ON_VALUE;
        } else {
            modeName = mResources.getString(mResources.getIdentifier("normal_mode_title",
            "string", mApp.getActivity().getPackageName()));
            listener.onModeChanged(modeName);
            mViewState = AI_OFF_VALUE;
        }
    }

    private void updateAiViewState(String value) {
        if (AI_ON_VALUE.equals(value)) {
            if (mAiEntryView != null) {
                mAiEntryView.setImageResource(R.drawable.ic_shopping_status_on);
                mAiEntryView.setContentDescription(mApp.getActivity().getResources().getString(
                        R.string.accessibility_ai_on));
            } else {
                LogHelper.d(TAG, "mAiEntryView is null");
            }
        } else if (AI_OFF_VALUE.equals(value)) {
            mAiEntryView.setImageResource(R.drawable.ic_shopping_status_off);
            mAiEntryView.setContentDescription(mApp.getActivity().getResources().getString(
                    R.string.accessibility_ai_off));
        } else {
            LogHelper.d(TAG, "invalid  view state");
        }
    }

    private final IAppUiListener.OnShutterButtonListener mShutterListener =
            new IAppUiListener.OnShutterButtonListener() {

                @Override
                public boolean onShutterButtonFocus(boolean pressed) {
                    return false;
                }

                @Override
                public boolean onShutterButtonClick() {
                    return false;
                }

                @Override
                public boolean onShutterButtonLongPressed() {

                    return false;
                }
            };
}
