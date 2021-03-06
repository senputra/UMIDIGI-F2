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

package com.android.fmradio;

import java.util.ArrayList;
import java.util.List;

import android.Manifest;
import android.app.ActionBar;
import android.app.Activity;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.graphics.Color;
import android.graphics.PorterDuff;
import android.media.AudioManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.IBinder;
import android.os.Looper;
import android.os.Message;
import android.text.SpannableString;
import android.text.style.ForegroundColorSpan;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;

import com.android.fmradio.FmService.OnExitListener;
import com.android.fmradio.FmStation.Station;

/**
 * This class interact with user, provider edit station information, such as add
 * to favorite, edit favorite, delete from favorite
 */
public class FmFavoriteActivity extends Activity {
    // Logging
    private static final String TAG = "FmFavoriteActivity";

    public static final String ACTIVITY_RESULT = "ACTIVITY_RESULT";

    private static final int PERMISSION_REQUEST_CODE_LOCATION = 100;

    private ListView mLvFavorites = null; // list view

    LinearLayout mSearchTips = null;

    private Context mContext = null; // application context

    private OnExitListener mExitListener = null;

    private MyFavoriteAdapter mMyAdapter;

    private ProgressBar mSearchProgress = null;

    private MenuItem mMenuRefresh = null;

    private boolean mIsActivityForeground = true;

    private Toast mToast = null;

    private boolean mIsBackPressed = false;

    /**
     * on create
     *
     * @param savedInstanceState The save instance state
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
            Log.d(TAG, "onCreate");
        super.onCreate(savedInstanceState);
        // Bind the activity to FM audio stream.
        setVolumeControlStream(AudioManager.STREAM_MUSIC);
        getWindow().requestFeature(Window.FEATURE_ACTION_BAR);
        setContentView(R.layout.favorite);
        // display action bar and navigation button
        ActionBar actionBar = getActionBar();
        actionBar.setTitle(getString(R.string.station_title));
        actionBar.setDisplayHomeAsUpEnabled(true);
        mContext = getApplicationContext();

        mMyAdapter = new MyFavoriteAdapter(mContext);
        mLvFavorites = (ListView) findViewById(R.id.station_list);
        mSearchTips = (LinearLayout) findViewById(R.id.search_tips);
        mSearchProgress = (ProgressBar) findViewById(R.id.search_progress);
        mLvFavorites.setAdapter(mMyAdapter); // set adapter
        mMyAdapter.swipResult(getData());

        mLvFavorites.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            /**
             * Click list item will finish activity and pass value to other activity
             *
             * @param parent adapter view
             * @param view item view
             * @param position current position
             * @param id current id
             */
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                // Set the selected frequency to main UI and finish the
                // favorite manager.
                TextView textView = (TextView) view.findViewById(R.id.lv_station_freq);
                float frequency = 0;
                try {
                    frequency = Float.parseFloat(textView.getText().toString());
                } catch (NumberFormatException e) {
                    e.printStackTrace();
                }
                Intent intentResult = new Intent();
                intentResult.putExtra(ACTIVITY_RESULT, FmUtils.computeStation(frequency));
                setResult(RESULT_OK, intentResult);
                finish();
            }
        });

        // Finish favorite when exit FM
        mExitListener = new FmService.OnExitListener() {
            @Override
            public void onExit() {
                Handler mainHandler = new Handler(Looper.getMainLooper());
                mainHandler.post(new Runnable() {
                    @Override
                    public void run() {
                        FmFavoriteActivity.this.finish();
                    }
                });
            }
        };
        FmService.registerExitListener(mExitListener);
        if (!mIsServiceBinded) {
            bindService();
        }
    }

    /**
     * When menu is selected
     *
     * @param item The selected menu item
     * @return true to consume it, false to can handle other
     */
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
            Log.d(TAG, "onOptionsItemSelected, item = " + item.getItemId());
        switch (item.getItemId()) {
            case android.R.id.home:
                onBackPressed();
                break;
            case R.id.fm_station_list_refresh:
                refreshList();
                break;
            default:
                break;
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onBackPressed() {
            Log.d(TAG, "onBackPressed");
        if (null == mService) {
            Log.w(TAG, "onBackPressed, mService is null");
        } else {
            boolean isScanning = mService.isScanning();
            if (isScanning) {
                mService.stopScan();
                mIsBackPressed = true;
                return;
            }
        }
        super.onBackPressed();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
            Log.d(TAG, "onCreateOptionsMenu");
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.fm_station_list_menu, menu);
        mMenuRefresh = menu.findItem(R.id.fm_station_list_refresh);
        resetMenuTitleColor(true);
        return true;
    }

    private void resetMenuTitleColor(boolean enabled) {
        SpannableString ss = new SpannableString(mMenuRefresh.getTitle());
        int titleColor = enabled ? getResources().getColor(R.color.actionbar_overflow_title_color)
                : getResources().getColor(R.color.actionbar_overflow_title_disabled_color);
        ss.setSpan(new ForegroundColorSpan(titleColor), 0, ss.length(), 0);
        mMenuRefresh.setTitle(ss);
    }

    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {
        if (null != mService) {
            boolean isScan = mService.isScanning();
            refreshMenuItem(!isScan);
        }
        return super.onPrepareOptionsMenu(menu);
    }

    static final class ViewHolder {
        ImageView mStationTypeView;
        TextView mStationFreqView;
        TextView mStationNameView;
        TextView mStationRdsView;
        RelativeLayout mImgLayout;
    }

    private Cursor getData() {
        Cursor cursor = mContext.getContentResolver().query(Station.CONTENT_URI,
                FmStation.COLUMNS, null, null, FmStation.Station.FREQUENCY);
        return cursor;
    }

    class MyFavoriteAdapter extends BaseAdapter {
        private Cursor mCursor;

        private LayoutInflater mInflater;

        public MyFavoriteAdapter(Context context) {
            mInflater = LayoutInflater.from(context);
        }

        public void swipResult(Cursor cursor) {
            if (null != mCursor) {
                mCursor.close();
            }
            mCursor = cursor;
            notifyDataSetChanged();
        }

        @Override
        public int getCount() {
            if (null != mCursor) {
                return mCursor.getCount();
            }
            return 0;
        }

        @Override
        public Object getItem(int position) {
            return null;
        }

        @Override
        public long getItemId(int position) {
            return 0;
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            ViewHolder viewHolder = null;
            if (null == convertView) {
                viewHolder = new ViewHolder();
                convertView = mInflater.inflate(R.layout.station_item, null);
                viewHolder.mStationTypeView = (ImageView) convertView
                        .findViewById(R.id.lv_station_type);
                viewHolder.mStationFreqView = (TextView) convertView
                        .findViewById(R.id.lv_station_freq);
                viewHolder.mStationNameView = (TextView) convertView
                        .findViewById(R.id.lv_station_name);
                viewHolder.mStationRdsView = (TextView) convertView
                        .findViewById(R.id.lv_station_rds);
                viewHolder.mImgLayout = (RelativeLayout) convertView
                        .findViewById(R.id.list_item_right);
                convertView.setTag(viewHolder);
            } else {
                viewHolder = (ViewHolder) convertView.getTag();
            }

            if (mCursor != null && mCursor.moveToFirst()) {
                mCursor.moveToPosition(position);
                final int stationFreq = mCursor.getInt(mCursor
                        .getColumnIndex(FmStation.Station.FREQUENCY));
                String name = mCursor.getString(mCursor
                        .getColumnIndex(FmStation.Station.STATION_NAME));
                String rds = mCursor.getString(mCursor
                        .getColumnIndex(FmStation.Station.RADIO_TEXT));
                final int isFavorite = mCursor.getInt(mCursor
                        .getColumnIndex(FmStation.Station.IS_FAVORITE));

                if (null == name || "".equals(name)) {
                    name = mCursor.getString(mCursor
                            .getColumnIndex(FmStation.Station.PROGRAM_SERVICE));
                }

                if (rds == null || rds.equals("")) {
                    viewHolder.mStationRdsView.setVisibility(View.GONE);
                } else {
                    viewHolder.mStationRdsView.setVisibility(View.VISIBLE);
                }

                viewHolder.mStationFreqView.setText(FmUtils.formatStation(stationFreq));
                viewHolder.mStationNameView.setText(name);
                viewHolder.mStationRdsView.setText(rds);
                if (0 == isFavorite) {
                    viewHolder.mStationTypeView.setImageResource(R.drawable.btn_fm_favorite_off);
                    viewHolder.mStationTypeView.setColorFilter(Color.BLACK,
                            PorterDuff.Mode.SRC_ATOP);
                    viewHolder.mStationTypeView.setAlpha(0.54f);
                } else {
                    viewHolder.mStationTypeView.setImageResource(R.drawable.btn_fm_favorite_on);
                    viewHolder.mStationTypeView.setColorFilter(null);
                    viewHolder.mStationTypeView.setAlpha(1.0f);
                }

                viewHolder.mImgLayout.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        if (0 == isFavorite) {
                            addFavorite(stationFreq);
                        } else {
                            deleteFavorite(stationFreq);
                        }
                    }
                });
            }
            return convertView;
        }
    }

    /**
     * Add searched station as favorite station
     */
    public void addFavorite(int stationFreq) {
            Log.d(TAG, "addFavorite");
        // TODO it's on UI thread, change to sub thread
        // update the station name and station type in database
        // according the frequency
        FmStation.addToFavorite(mContext, stationFreq);
        mMyAdapter.swipResult(getData());
    }

    /**
     * Delete favorite from favorite station list, make it as searched station
     */
    public void deleteFavorite(int stationFreq) {
            Log.d(TAG, "deleteFavorite");
        // TODO it's on UI thread, change to sub thread
        // update the station type from favorite to searched.
        FmStation.removeFromFavorite(mContext, stationFreq);
        mMyAdapter.swipResult(getData());
    }

    @Override
    protected void onResume() {
            Log.d(TAG, "onResume");
        super.onResume();
        mIsActivityForeground = true;
        if (null != mService) {
            mService.setFmMainActivityForeground(mIsActivityForeground);
            if (FmRecorder.STATE_RECORDING != mService.getRecorderState()) {
                mService.removeNotification();
            }
        }
    }

    @Override
    protected void onPause() {
            Log.d(TAG, "onPause");
        mIsActivityForeground = false;
        if (null != mService) {
            mService.setFmMainActivityForeground(mIsActivityForeground);
        }
        super.onPause();
    }

    @Override
    protected void onStop() {
       // FmUtils.updateFrontActivity(mContext, "");
        if (null != mService) {
            // home key pressed, show notification
            mService.setNotificationClsName(FmFavoriteActivity.class.getName());
            mService.updatePlayingNotification();
        }
        super.onStop();
    }

    @Override
    protected void onDestroy() {
            Log.d(TAG, "onDestroy");
        mMyAdapter.swipResult(null);
        FmService.unregisterExitListener(mExitListener);
        if (mService != null) {
            mService.unregisterFmRadioListener(mFmRadioListener);
        }
        unbindService();
        super.onDestroy();
    }

    private FmService mService = null;

    private boolean mIsServiceBinded = false;

    private void bindService() {
        mIsServiceBinded = bindService(new Intent(FmFavoriteActivity.this, FmService.class),
                mServiceConnection, Context.BIND_AUTO_CREATE);
        if (!mIsServiceBinded) {
            Log.e(TAG, "bindService, mIsServiceBinded is false");
            finish();
        }
    }

    private void unbindService() {
        if (mIsServiceBinded) {
            unbindService(mServiceConnection);
        }
    }

    // Service listener
    private FmListener mFmRadioListener = new FmListener() {
        @Override
        public void onCallBack(Bundle bundle) {
            int flag = bundle.getInt(FmListener.CALLBACK_FLAG);
            if (flag == FmListener.MSGID_FM_EXIT) {
                mHandler.removeCallbacksAndMessages(null);
            }

            // remove tag message first, avoid too many same messages in queue.
            Message msg = mHandler.obtainMessage(flag);
            msg.setData(bundle);
            mHandler.removeMessages(flag);
            mHandler.sendMessage(msg);
        }
    };

    /**
     * Main thread handler to update UI
     */
    private Handler mHandler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            Log.d(TAG,
                    "handleMessage, what = " + msg.what + ",hashcode:"
                            + mHandler.hashCode());
            Bundle bundle;
            switch (msg.what) {
                case FmListener.MSGID_SCAN_FINISHED:
                    bundle = msg.getData();
                    // cancel scan happen
                    boolean isScan = bundle.getBoolean(FmListener.KEY_IS_SCAN);
                    int searchedNum = bundle.getInt(FmListener.KEY_STATION_NUM);
                    refreshMenuItem(true);
                    mMyAdapter.swipResult(getData());
                    mService.updatePlayingNotification();
                    if (searchedNum == 0) {
                        Toast.makeText(mContext, getString(R.string.toast_cannot_search),
                                Toast.LENGTH_SHORT).show();
                        if (mIsBackPressed) {
                            Log.d(TAG, "back was pressed, so finishing activity");
                            mIsBackPressed = false;
                            finish();
                            return;
                        }
                        // searched station is zero, if db has station, should not use empty.
                        if (mMyAdapter.getCount() == 0) {
                            View emptyView = (View) findViewById(R.id.empty_tips);
                            emptyView.setVisibility(View.VISIBLE);
                            View searchTips = (View) findViewById(R.id.search_tips);
                            searchTips.setVisibility(View.GONE);
                        }
                        return;
                    }
                    // Show toast to tell user how many stations have been searched
                    String text = getString(R.string.toast_station_searched) + " "
                            + String.valueOf(searchedNum);
                    Toast.makeText(mContext, text, Toast.LENGTH_SHORT).show();
                    break;
                case FmListener.MSGID_SWITCH_ANTENNA:
                    bundle = msg.getData();
                    boolean isHeadset = bundle.getBoolean(FmListener.KEY_IS_SWITCH_ANTENNA);
                    // if receive headset plugout, need set headset mode on ui
                    if (!isHeadset) {
                        finish();
                    }
                    break;
                default:
                    break;
            }
        }
    };

    private void refreshMenuItem(boolean enabled) {
        // action menu
        if (mMenuRefresh != null) {
            mMenuRefresh.setEnabled(enabled);
            resetMenuTitleColor(enabled);
        }
    }

    // When call bind service, it will call service connect. register call back
    // listener and initial device
    private final ServiceConnection mServiceConnection = new ServiceConnection() {

        /**
         * called by system when bind service
         *
         * @param className component name
         * @param service service binder
         */
        @Override
        public void onServiceConnected(ComponentName className, IBinder service) {
            mService = ((FmService.ServiceBinder) service).getService();
                Log.d(TAG, "onServiceConnected, mService = " + mService);
            if (null == mService) {
                finish();
                return;
            }
            mService.registerFmRadioListener(mFmRadioListener);
            mService.setFmMainActivityForeground(mIsActivityForeground);
            if (FmRecorder.STATE_RECORDING != mService.getRecorderState()) {
                mService.removeNotification();
            }
            // FmUtils.isFirstEnterStationList() must be called at the first time.
            // After it is called, it will save status to SharedPreferences.
            // If have started scanning, don't scan again, this always happen when
            // Activity recreate with no station.
            boolean isScan = mService.isScanning();
            if ((FmUtils.isFirstEnterStationList(mContext) || (0 == mMyAdapter.getCount()))
                    && !isScan) {
                refreshMenuItem(false);
                mLvFavorites.setEmptyView(mSearchTips);
                mSearchProgress.setIndeterminate(true);
                mMyAdapter.swipResult(null);
                // should hide no station view before starting scanning
                View emptyView = (View) findViewById(R.id.empty_tips);
                emptyView.setVisibility(View.GONE);
                mService.startScanAsync();
            } else {
                if (isScan) {
                    mMyAdapter.swipResult(null);
                    mLvFavorites.setEmptyView(mSearchTips);
                    mSearchProgress.setIndeterminate(true);
                } else {
                    // TODO it's on UI thread, change to sub thread
                    mMyAdapter.swipResult(getData());
                }
                refreshMenuItem(!isScan);
            }
        }

        /**
         * When unbind service will call this method
         *
         * @param className The component name
         */
        @Override
        public void onServiceDisconnected(ComponentName className) {
        Log.d(TAG, "onServiceDisconnected");
        }
    };


    private void refreshList() {
        int recordAudioPermission = checkSelfPermission(Manifest.permission.RECORD_AUDIO);

        List<String> mPermissionStrings = new ArrayList<String>();
        boolean mRequest = false;

        if (recordAudioPermission != PackageManager.PERMISSION_GRANTED) {
            mPermissionStrings.add(Manifest.permission.RECORD_AUDIO);
            mRequest = true;
        }
        if (mRequest == true) {
            String[] mPermissionList = new String[mPermissionStrings.size()];
            mPermissionList = mPermissionStrings.toArray(mPermissionList);
            requestPermissions(mPermissionList, PERMISSION_REQUEST_CODE_LOCATION);
            return;
        }
        if (null != mService) {
            refreshMenuItem(false);

            mMyAdapter.swipResult(null);
            mLvFavorites.setEmptyView(mSearchTips);
            mSearchProgress.setIndeterminate(true);

            // should hide no station view before starting scanning
            View emptyView = (View) findViewById(R.id.empty_tips);
            emptyView.setVisibility(View.GONE);
            mService.startScanAsync();
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions,
            int[] grantResults) {
        if (requestCode == PERMISSION_REQUEST_CODE_LOCATION) {
            boolean granted = true;
            boolean mShowPermission = true;
            for (int counter = 0; counter < permissions.length; counter++) {
                boolean permissionGranted = (grantResults[counter] ==
                                             PackageManager.PERMISSION_GRANTED);
                granted = granted && permissionGranted;
                if (!permissionGranted) {
                    mShowPermission = mShowPermission && shouldShowRequestPermissionRationale(
                                      permissions[counter]);
                }
            }
            Log.i(TAG, "<onRequestPermissionsResult> Location permission granted" + granted);
            if (granted == true) {
                refreshList();
            } else if (!mShowPermission) {
                showToast(getString(R.string.missing_required_permission));
            }
        }
    }

    private void showToast(CharSequence text) {
        if (null == mToast) {
            mToast = Toast.makeText(mContext, text, Toast.LENGTH_SHORT);
        }
        mToast.setText(text);
        mToast.show();
    }

}
