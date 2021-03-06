/*
 * Copyright (C) 2011 The Android Open Source Project
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

package com.mediatek.cellbroadcastreceiver;

import android.app.Application;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.res.Configuration;
import android.telephony.CellBroadcastMessage;
import android.text.TextUtils;
//Taiwan PWS
import com.android.internal.telephony.TelephonyIntents;
import android.util.Log;
import android.preference.PreferenceManager;

import java.util.ArrayList;


/**
 * The application class loads the default preferences at first start,
 * and remembers the time of the most recently received broadcast.
 */
public class CellBroadcastReceiverApp extends Application {
    private static final String TAG = "[CMAS][CellBroadcastReceiverApp]";

    private static boolean sInitPlugin = false;

    @Override
    public void onCreate() {
        super.onCreate();
        Log.d(TAG, "onCreate ++");

        if (!sInitPlugin) {
            CellBroadcastPluginManager.initPlugins(this);
            sInitPlugin = true;
        }
        CmasConfigManager.updateConfigInfos(getApplicationContext());
        // For Taiwan PWS
        IntentFilter plmnFliter = new IntentFilter();
        plmnFliter.addAction(TelephonyIntents.ACTION_LOCATED_PLMN_CHANGED);
        registerReceiver(mPLMNChangedBroadcastReceiver, plmnFliter);

        IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction(Intent.ACTION_AIRPLANE_MODE_CHANGED);
        registerReceiver(new CellBroadcastReceiver(), intentFilter);
    }

    // For Taiwan PWS-START
    private final BroadcastReceiver mPLMNChangedBroadcastReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals(TelephonyIntents.ACTION_LOCATED_PLMN_CHANGED)) {
                String plmn = intent.getStringExtra(TelephonyIntents.EXTRA_PLMN);
                if (!TextUtils.isEmpty(plmn)) {
                    String iso = intent.getStringExtra(TelephonyIntents.EXTRA_ISO);
                    String mcc = plmn.substring(0, 3);
                    Log.d(TAG, "receive Plmn Changed " + plmn + ", mcc " + mcc + ", iso " + iso);
                    Configuration config =
                            getApplicationContext().getResources().getConfiguration();
                    config.mcc = Integer.parseInt(mcc);
                    config.mnc = Integer.parseInt(plmn.substring(3));
                    getApplicationContext().getResources().updateConfiguration(config,
                            getApplicationContext().getResources().getDisplayMetrics());
                    Log.d(TAG, "set mcc to " + config.mcc);
                    CmasConfigManager.updateConfigInfos(getApplicationContext());
                }
            }
        }
    };

    /** List of unread non-emergency alerts to show when user selects the notification. */
    private static final ArrayList<CellBroadcastMessage> sNewMessageList =
            new ArrayList<CellBroadcastMessage>(4);

    /** Adds a new unread non-emergency message and returns the current list. */
    static ArrayList<CellBroadcastMessage> addNewMessageToList(CellBroadcastMessage message) {
        sNewMessageList.add(message);
        return sNewMessageList;
    }

    /** Clears the list of unread non-emergency messages. */
    static void clearNewMessageList() {
        sNewMessageList.clear();
    }
}
