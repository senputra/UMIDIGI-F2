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

package com.mediatek.camera.feature.setting.visualsearch;


import com.mediatek.camera.common.ICameraContext;
import com.mediatek.camera.common.app.IApp;
import com.mediatek.camera.common.debug.LogHelper;
import com.mediatek.camera.common.debug.LogUtil;

import com.mediatek.camera.common.mode.ICameraMode;
import com.mediatek.camera.common.relation.Relation;
import com.mediatek.camera.common.setting.ISettingManager;
import com.mediatek.camera.common.setting.SettingBase;
import com.mediatek.camera.common.setting.SettingManagerFactory;
import com.mediatek.camera.common.device.CameraDeviceManagerFactory.CameraApi;
import com.mediatek.camera.common.utils.CameraUtil;

import java.util.List;

import javax.annotation.Nonnull;

/**
 * This class use to handle HDR feature flow.
 */
public class VisualSearchSetting extends SettingBase {
    private static final LogUtil.Tag TAG = new LogUtil.Tag(VisualSearchSetting.class.getSimpleName());

    public static final String AI_OFF_VALUE = "off";
    public static final String AI_ON_VALUE = "on";
    public static final String AI_AUTO_VALUE = "auto";
    private static final String AI_KEY = "key_visualsearchsetting";
    private static final String KEY_CSHOT = "key_continuous_shot";
    private static final String VALUE_CSHOT_START = "start";
    private static final String VALUE_CSHOT_STOP = "stop";

    public static final String AI_MODE = "com.mediatek.camera.feature.mode.visualsearch.VisualSearchMode";
    public static final String PHOTO_MODE = "com.mediatek.camera.common.mode.photo.PhotoMode";

    private String mCurrentMode = "";

    private ICameraMode.ModeType mModeType;
    private VisualSearchSettingParameterConfigure mVisualSearchSettingParameterConfigure;
    private VisualSearchSettingRequestConfigure mVisualSearchSettingRequestConfigure;
    private VisualSearchSettingViewController mVisualSearchSettingViewController;

    private ISettingChangeRequester mSettingChangeRequester;
    // [Add for CCT tool] Receive keycode and set  on/set off @{
    //private IApp.KeyEventListener mKeyEventListener;
    // @}

    private ISettingManager mISettingManager;
    private ICameraContext mICameraContext;
    private String mCameraId;
    private IApp mIApp;

    @Override
    public void init(IApp app,
                     ICameraContext cameraContext,
                     ISettingManager.SettingController settingController) {
        super.init(app, cameraContext, settingController);
        LogHelper.d(TAG, "init");
        mICameraContext = cameraContext;
        mIApp = app;
        mCameraId = settingController.getCameraId();
        String value = mDataStore.getValue(AI_KEY, AI_OFF_VALUE, getStoreScope());
        setValue(value);
        if (mVisualSearchSettingViewController == null) {
            mVisualSearchSettingViewController = new VisualSearchSettingViewController(app);
        }
    }

    @Override
    public void unInit() {
        LogHelper.d(TAG, "unInit");
        if (mVisualSearchSettingViewController != null) {
            mVisualSearchSettingViewController = null;
        }
    }

    @Override
    public void addViewEntry() {
        if (mCurrentMode.equals(AI_MODE)||mCurrentMode.equals(PHOTO_MODE)) {
            CameraUtil.setShowViewIcon(true);
        } else {
            CameraUtil.setShowViewIcon(false);
        }
        if (mCurrentMode.equals(AI_MODE)) {
            CameraUtil.setChangeIconState(true);
        } else {
            CameraUtil.setChangeIconState(false);
        }
        mVisualSearchSettingViewController.addQuickSwitchIcon();
        mVisualSearchSettingViewController.showQuickSwitchIcon(getEntryValues().size() > 1);
    }

    @Override
    public void removeViewEntry() {
        mVisualSearchSettingViewController.removeQuickSwitchIcon();
    }

    @Override
    public void refreshViewEntry() {
        int num = getEntryValues().size();
        LogHelper.d(TAG, "refreshViewEntry, entry num = " + num +",isShowViewIcon = "+ CameraUtil.isShowViewIcon());
        if (num <= 1 || !CameraUtil.isShowViewIcon()) {
            mVisualSearchSettingViewController.showQuickSwitchIcon(false);
        } else {
            mVisualSearchSettingViewController.showQuickSwitchIcon(true);
        }
    }

    @Override
    public void onModeOpened(String modeKey, ICameraMode.ModeType modeType) {
        LogHelper.d(TAG, "mCurrentMode = " + mCurrentMode + ", modeKey = " + modeKey);
        if (modeKey.equals(AI_MODE) || modeKey.equals(PHOTO_MODE)) {
            CameraUtil.setShowViewIcon(true);
        } else {
            CameraUtil.setShowViewIcon(false);
        }
        if (modeKey.equals(AI_MODE)) {
            CameraUtil.setChangeIconState(true);
        } else {
            CameraUtil.setChangeIconState(false);
        }
        mCurrentMode = modeKey;
        mModeType = modeType;

    }

    @Override
    public void onModeClosed(String modeKey) {
        super.onModeClosed(modeKey);
    }

    @Override
    public SettingType getSettingType() {
        return SettingType.PHOTO;
    }

    @Override
    public String getKey() {
        return AI_KEY;
    }

    @Override
    public IParametersConfigure getParametersConfigure() {
        if (mVisualSearchSettingParameterConfigure == null) {
            mVisualSearchSettingParameterConfigure = new VisualSearchSettingParameterConfigure(this, mSettingDeviceRequester);
        }
        mSettingChangeRequester = mVisualSearchSettingParameterConfigure;
        return mVisualSearchSettingParameterConfigure;
    }

    @Override
    public ICaptureRequestConfigure getCaptureRequestConfigure() {
        if (mVisualSearchSettingRequestConfigure == null) {
            mVisualSearchSettingRequestConfigure = new VisualSearchSettingRequestConfigure(this, mSettingDevice2Requester);
        }
        mSettingChangeRequester = mVisualSearchSettingRequestConfigure;
        return mVisualSearchSettingRequestConfigure;
    }

    @Override
    public void overrideValues(@Nonnull String headerKey, String currentValue,
                               List<String> supportValues) {
        String lastValue = getValue();
        LogHelper.i(TAG, "[overrideValues] headerKey = " + headerKey
                + ", currentValue = " + currentValue + ",supportValues = " + supportValues);
        if (headerKey.equals("key_scene_mode") && mSettingController.queryValue("key_scene_mode")
                .equals("hdr")) {
            return;
        }
        if (headerKey.equals("key_visualsearchsetting")) {
            super.overrideValues(headerKey, currentValue, supportValues);
            if (!lastValue.equals(getValue())) {
                Relation relation = VisualSearchSettingRestriction.getVisualSearchSettingRestriction()
                        .getRelation(getValue(), true);
                mSettingController.postRestriction(relation);
            }
            mActivity.runOnUiThread(new Runnable() {
                public void run() {
                    if (supportValues != null) {
                        mVisualSearchSettingViewController.showQuickSwitchIcon(supportValues.size() > 1);
                    } else {
                        if (isSupportedInCurrentMode()) {
                            mVisualSearchSettingViewController.showQuickSwitchIcon(getEntryValues().size() > 1);
                        }
                    }
                }
            });
        }
    }


    @Override
    public void postRestrictionAfterInitialized() {
        //called in setOriginalParameters
        Relation relation = VisualSearchSettingRestriction.getVisualSearchSettingRestriction().getRelation(getValue(), false);
        if (relation != null) {
            mSettingController.postRestriction(relation);
        }
    }

    @Override
    public String getStoreScope() {
        return mDataStore.getGlobalScope();
    }

    /**
     * Get current mode key.
     *
     * @return mModeType current mode key.
     */
    public ICameraMode.ModeType getCurrentModeType() {
        return mModeType;
    }

    /**
     * Used to update view for auto detection.
     *
     * @param isAutoVisiable true, means show.
     */
    public void onAutoDetectionResult(boolean isAutoVisiable) {
        mVisualSearchSettingViewController.showVisualSearchSettingIndicator(isAutoVisiable);
    }


    /**
     * Used to update hdr current value and post restriction.
     *
     * @param value current hdr value.
     */
    public void onVisualSearchSettingValueChanged(String value) {
        mHandler.post(new Runnable() {
            @Override
            public void run() {
                if (!value.equals(getValue())) {

                    setValue(value);
                    mSettingController.postRestriction(
                            VisualSearchSettingRestriction.getVisualSearchSettingRestriction().getRelation(value, true));
                    mSettingController.refreshViewEntry();
                    mSettingChangeRequester.sendSettingChangeRequest();
                    mDataStore.setValue(AI_KEY, value, getStoreScope(), false, true);

                }
            }
        });
    }

    private boolean isSupportedInCurrentMode() {
        return true;
    }

}
