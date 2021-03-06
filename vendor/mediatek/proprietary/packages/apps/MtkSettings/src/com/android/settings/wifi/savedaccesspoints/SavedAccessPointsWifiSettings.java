/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.settings.wifi.savedaccesspoints;

import android.annotation.Nullable;
import android.app.Dialog;
import android.app.settings.SettingsEnums;
import android.content.Context;
import android.content.DialogInterface;
import android.net.wifi.WifiManager;
import android.os.Bundle;
import android.util.FeatureFlagUtils;
import android.util.Log;

import com.android.settings.R;
import com.android.settings.core.FeatureFlags;
import com.android.settings.core.SubSettingLauncher;
import com.android.settings.dashboard.DashboardFragment;
import com.android.settings.development.featureflags.FeatureFlagPersistent;
import com.android.settings.wifi.WifiConfigUiBase;
import com.android.settings.wifi.WifiDialog;
import com.android.settings.wifi.WifiSettings;
import com.android.settings.wifi.details.WifiNetworkDetailsFragment;
import com.android.mtksettingslib.wifi.AccessPoint;
import com.android.mtksettingslib.wifi.AccessPointPreference;

/**
 * UI to manage saved networks/access points.
 */
public class SavedAccessPointsWifiSettings extends DashboardFragment {

    private static final String TAG = "SavedAccessPoints";

    private Bundle mAccessPointSavedState;
    private AccessPoint mSelectedAccessPoint;

    // Instance state key
    private static final String SAVE_DIALOG_ACCESS_POINT_STATE = "wifi_ap_state";

    @Override
    public int getMetricsCategory() {
        return SettingsEnums.WIFI_SAVED_ACCESS_POINTS;
    }

    @Override
    protected int getPreferenceScreenResId() {
        return R.xml.wifi_display_saved_access_points;
    }

    @Override
    protected String getLogTag() {
        return TAG;
    }

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);
        use(SavedAccessPointsPreferenceController.class)
                .setHost(this);
        use(SubscribedAccessPointsPreferenceController.class)
                .setHost(this);
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (savedInstanceState != null) {
            if (savedInstanceState.containsKey(SAVE_DIALOG_ACCESS_POINT_STATE)) {
                mAccessPointSavedState =
                        savedInstanceState.getBundle(SAVE_DIALOG_ACCESS_POINT_STATE);
            }
        }
    }

    public void showWifiPage(@Nullable AccessPointPreference accessPoint) {
        removeDialog(WifiSettings.WIFI_DIALOG_ID);

        if (accessPoint != null) {
            // Save the access point and edit mode
            mSelectedAccessPoint = accessPoint.getAccessPoint();
        } else {
            // No access point is selected. Clear saved state.
            mSelectedAccessPoint = null;
            mAccessPointSavedState = null;
        }

        if (mSelectedAccessPoint == null) {
            mSelectedAccessPoint = new AccessPoint(getActivity(), mAccessPointSavedState);
        }
        final Bundle savedState = new Bundle();
        mSelectedAccessPoint.saveWifiState(savedState);

        new SubSettingLauncher(getContext())
                .setTitleText(mSelectedAccessPoint.getTitle())
                .setDestination(WifiNetworkDetailsFragment.class.getName())
                .setArguments(savedState)
                .setSourceMetricsCategory(getMetricsCategory())
                .launch();
    }

    @Override
    public void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        // If the dialog is showing (indicated by the existence of mSelectedAccessPoint), then we
        // save its state.
        if (mSelectedAccessPoint != null) {
            mAccessPointSavedState = new Bundle();
            mSelectedAccessPoint.saveWifiState(mAccessPointSavedState);
            outState.putBundle(SAVE_DIALOG_ACCESS_POINT_STATE, mAccessPointSavedState);
        }
    }

    boolean isSubscriptionsFeatureEnabled() {
        return FeatureFlagUtils.isEnabled(getContext(), FeatureFlags.MOBILE_NETWORK_V2)
                && FeatureFlagPersistent.isEnabled(getContext(), FeatureFlags.NETWORK_INTERNET_V2);
    }
}
