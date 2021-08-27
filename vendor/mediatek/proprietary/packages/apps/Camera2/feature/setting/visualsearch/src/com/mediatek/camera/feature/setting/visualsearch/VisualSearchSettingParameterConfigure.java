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

import android.hardware.Camera;
import android.view.View;

import com.mediatek.camera.common.debug.LogHelper;
import com.mediatek.camera.common.debug.LogUtil;
import com.mediatek.camera.common.device.v1.CameraProxy;
import com.mediatek.camera.common.mode.ICameraMode;
import com.mediatek.camera.common.setting.ICameraSetting;
import com.mediatek.camera.common.setting.ISettingManager;

import java.util.ArrayList;
import java.util.List;

/**
 * Class used to configure flash parameters(Used only for api1).
 * What's more,settings without ui which has restriction with flash will be restricted here.
 */
public class VisualSearchSettingParameterConfigure implements ICameraSetting.IParametersConfigure {
    private static final LogUtil.Tag TAG =
            new LogUtil.Tag(VisualSearchSettingParameterConfigure.class.getSimpleName());

    private static final String AI_TORCH_VALUE = "torch";

    private ISettingManager.SettingDeviceRequester mSettingDeviceRequester;
    private VisualSearchSetting mVisualSearchSetting;

    private boolean mIsSupportedVisualSearchSetting = false;

    /**
     * Constructor of flash parameter configuration.
     * @param flash Flash instance.
     * @param requester setting device request to send value changed request.
     */
    public VisualSearchSettingParameterConfigure(VisualSearchSetting visualSearchSetting,
                                   ISettingManager.SettingDeviceRequester requester) {
        mVisualSearchSetting = visualSearchSetting;
        mSettingDeviceRequester = requester;
    }

    @Override
    public void setOriginalParameters(Camera.Parameters originalParameters) {
        initPlatformSupportedValues(originalParameters);
        if (mIsSupportedVisualSearchSetting) {
            initAppSupportedEntryValues();
            initSettingEntryValues();
        }
    }

    @Override
    public boolean configParameters(Camera.Parameters parameters) {
        if (mIsSupportedVisualSearchSetting) {
            String value = mVisualSearchSetting.getValue();
            if (value != null) {
                if (VisualSearchSetting.AI_ON_VALUE.equals(value)) {
                    //on
                    parameters.setSceneMode("visualsearch");
                    //setExtendHdrRestriction(parameters);
                } else if (VisualSearchSetting.AI_AUTO_VALUE.equals(value)) {
                    //auto
                    parameters.setSceneMode("visualsearch");
                    //setExtendHdrRestriction(parameters);
                } else {
                    //off
                }
            }
        }
        return false;
    }

    @Override
    public void configCommand(CameraProxy cameraProxy) {

    }

    @Override
    public void sendSettingChangeRequest() {
        mSettingDeviceRequester.requestChangeSettingValue(mVisualSearchSetting.getKey());
    }

    /**
     * Initialize platform supported values.
     */
    private void initPlatformSupportedValues(Camera.Parameters originalParameters) {
        List<String> supportedList = originalParameters.getSupportedFlashModes();
        supportedList = new ArrayList<>();
        supportedList.add(VisualSearchSetting.AI_OFF_VALUE);
        mVisualSearchSetting.setSupportedPlatformValues(supportedList);
    }

    /**
     * Initialize application supported entry values. May be spec required supported values.
     */
    private void initAppSupportedEntryValues() {
        List<String> supportedList = new ArrayList<>();
        supportedList.add(VisualSearchSetting.AI_OFF_VALUE);
        supportedList.add(VisualSearchSetting.AI_ON_VALUE);
        supportedList.add(VisualSearchSetting.AI_AUTO_VALUE);
        mVisualSearchSetting.setSupportedEntryValues(supportedList);
    }

    /**
     * Initialize flash supported setting values,setting with ui will use this values to show.
     * their choices.The values is the intersection of platform supported values and application
     * supported entry values.
     */
    private void initSettingEntryValues() {
        List<String> supportedEntryList = new ArrayList<>();
        List<String> supportedList = new ArrayList<>();
        supportedEntryList.add(VisualSearchSetting.AI_OFF_VALUE);
        supportedEntryList.add(VisualSearchSetting.AI_ON_VALUE);
        supportedEntryList.add(VisualSearchSetting.AI_AUTO_VALUE);
        supportedList.addAll(supportedEntryList);
        supportedList.retainAll(mVisualSearchSetting.getSupportedPlatformValues());
        mVisualSearchSetting.setEntryValues(supportedList);
    }
}
