/*
 * Copyright (C) 2012 The Android Open Source Project
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

package com.android.phone;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.SystemProperties;
import android.util.Log;

import com.android.internal.telephony.DebugService;

import java.io.FileDescriptor;
import java.io.PrintWriter;

//FuzzyTest
import com.android.phone.FuzzyDelayTest;

/**
 * A debug service for telephony.
 */
public class TelephonyDebugService extends Service {
    private static String TAG = "TelephonyDebugService";
    private static final boolean DBG = true;
    private DebugService mDebugService = new DebugService();

    /** Constructor */
    public TelephonyDebugService() {
        if (DBG) Log.d(TAG, "TelephonyDebugService()");
        if (SystemProperties.getInt("persist.vendor.radio.phonefuzzy", 0) == 1) {
            //Init FuzzyTest
            FuzzyDelayTest.init();
        }
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    protected void dump(FileDescriptor fd, PrintWriter pw, String[] args) {
        mDebugService.dump(fd, pw, args);
    }
}
