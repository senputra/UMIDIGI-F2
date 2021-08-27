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
 *     MediaTek Inc. (C) 2019. All rights reserved.
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

package com.mediatek.camera.feature.mode.visualsearch;

import android.app.Activity;
import android.app.FragmentManager;
import android.app.FragmentTransaction;

import android.content.ContentValues;
import android.content.BroadcastReceiver;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.Matrix;
import android.graphics.ImageFormat;
import android.net.Uri;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;
import android.text.TextUtils;
import android.content.IntentFilter;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Environment;
import android.os.Looper;
import android.os.Message;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.net.ConnectivityManager;
import android.content.Context;
import android.os.SystemClock;
import android.os.AsyncTask;
import android.annotation.SuppressLint;
import android.content.res.AssetManager;

import com.mediatek.camera.common.IAppUi;
import com.mediatek.camera.common.IAppUi.AnimationData;
import com.mediatek.camera.common.IAppUiListener;
import com.mediatek.camera.common.ICameraContext;
import com.mediatek.camera.common.app.IApp;
import com.mediatek.camera.common.debug.CameraSysTrace;
import com.mediatek.camera.common.debug.LogHelper;
import com.mediatek.camera.common.debug.LogUtil;
import com.mediatek.camera.common.memory.IMemoryManager;
import com.mediatek.camera.common.memory.MemoryManagerImpl;
import com.mediatek.camera.common.mode.CameraModeBase;
import com.mediatek.camera.common.mode.DeviceUsage;
import com.mediatek.camera.common.mode.photo.ThumbnailHelper;
import com.mediatek.camera.common.relation.DataStore;
import com.mediatek.camera.common.relation.StatusMonitor;
import com.mediatek.camera.common.setting.ISettingManager;
import com.mediatek.camera.common.setting.SettingManagerFactory;
import com.mediatek.camera.common.storage.MediaSaver;
import com.mediatek.camera.common.utils.BitmapCreator;
import com.mediatek.camera.common.utils.CameraUtil;
import com.mediatek.camera.common.utils.Size;
import com.mediatek.camera.feature.mode.visualsearch.utils.CommonUtils;
import com.mediatek.camera.common.widget.PreviewFrameLayout;

import com.mediatek.camera.feature.mode.visualsearch.activity.ImageParseActivity;
import com.mediatek.camera.feature.mode.visualsearch.bean.DataHolder;
import com.mediatek.camera.feature.mode.visualsearch.view.VisualSearchView;
import com.mediatek.camera.feature.mode.visualsearch.utils.FileUtil;
import com.mediatek.camera.R;
import com.mediatek.camera.feature.mode.visualsearch.bean.ImageTag;
import com.mediatek.camera.feature.mode.visualsearch.utils.Const;
import com.mediatek.camera.feature.mode.visualsearch.manager.VisualSearchManager;

import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import java.lang.Exception;
import javax.annotation.Nonnull;
import java.io.File;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.nio.ByteBuffer;


import org.json.JSONArray;
import org.json.JSONObject;

/**
 * Demo mode that is used to take normal picture.
 */

public class VisualSearchMode extends CameraModeBase implements IVisualSearchDeviceController.CaptureDataCallback,
        IVisualSearchDeviceController.DeviceCallback, IVisualSearchDeviceController.PreviewSizeCallback,
        IMemoryManager.IMemoryListener{
    private static final LogUtil.Tag TAG = new LogUtil.Tag(VisualSearchMode.class.getSimpleName());
    private static final String KEY_MATRIX_DISPLAY_SHOW = "key_matrix_display_show";
    private static final String KEY_PICTURE_SIZE = "key_picture_size";
    private static final String KEY_FORMTAT = "key_format";
    private static final String KEY_DNG = "key_dng";
    private static final String JPEG_CALLBACK = "jpeg callback";
    private static final String POST_VIEW_CALLBACK = "post view callback";
    private static final long DNG_IMAGE_SIZE = 45 * 1024 * 1024;

    protected static final String PHOTO_CAPTURE_START = "start";
    protected static final String PHOTO_CAPTURE_STOP = "stop";
    protected static final String KEY_PHOTO_CAPTURE = "key_photo_capture";

    private long mPreviewUpdateTime = 0;

    private ICameraContext mICameraContext;

    protected IVisualSearchDeviceController mIDeviceController;
    protected VisualSearchModeHelper mVisualSearchModeHelper;
    protected int mCaptureWidth;
    // make sure the picture size ratio = mCaptureWidth / mCaptureHeight not to NAN.
    protected int mCaptureHeight = Integer.MAX_VALUE;
    //the reason is if surface is ready, let it to set to device controller, otherwise
    //if surface is ready but activity is not into resume ,will found the preview
    //can not start preview.
    protected volatile boolean mIsResumed = false;
    private String mCameraId;
    private int mOrientation;

    private ISettingManager mISettingManager;
    private MemoryManagerImpl mMemoryManager;
    private byte[] mPreviewData;
    private int mPreviewFormat;
    private int mPreviewWidth;
    private int mPreviewHeight;
    //make sure it is in capturing to show the saving UI.
    private int mCapturingNumber = 0;
    private boolean mIsMatrixDisplayShow = false;
    private Object mPreviewDataSync = new Object();
    private Object mCaptureNumberSync = new Object();
    private StatusMonitor.StatusChangeListener mStatusChangeListener = new MyStatusChangeListener();
    private IMemoryManager.MemoryAction mMemoryState = IMemoryManager.MemoryAction.NORMAL;
    protected StatusMonitor.StatusResponder mPhotoStatusResponder;

    private IAppUiListener.ISurfaceStatusListener mISurfaceStatusListener
            = new SurfaceChangeListener();

    private VisualSearchView mVisualSearchView;
    private ArrayList<ImageTag> imageTags = new ArrayList<>();
    private Bitmap bitmapPre = null;
    private SensorManager mSensorManager;
    private Handler mMainHandler;
    private IApp mApp;

    private static final int MSG_INIT_VIEW = 1000;
    private static final int MSG_HIDE_VIEW = 1001;
    private static final int MSG_SHOW_VIEW = 1002;
    private static final int MSG_UNINIT_VIEW = 1003;
    private static final int MSG_UPDATE_RECOGNITION = 1004;
    private static final int MSG_CLEAR_POINTS = 1005;
    private static final int MSG_SHOW_ANIMATION = 1006;
    private static final int MSG_DISMISS_ANIMATION = 1007;

    //Max offset of device X axis
    private static final float X = 5f;
    //Max offset of device Y axis
    private static final float Y = 1f;
    //Max offset of device Z axis
    private static final float Z = 5f;

    private boolean isInitFinish = false;
    private boolean isComputeFinish = true;

    @Override
    public void init(@Nonnull IApp app, @Nonnull ICameraContext cameraContext,
                     boolean isFromLaunch) {
        LogHelper.d(TAG, "[init]+");
        super.init(app, cameraContext, isFromLaunch);
        mApp = app;
        new LoadModelsAsyncTask().execute();
        mICameraContext = cameraContext;
        mCameraId = getCameraIdByFacing(mDataStore.getValue(
                KEY_CAMERA_SWITCHER, null, mDataStore.getGlobalScope()));
        LogHelper.d(TAG, "[init] mCameraId " + mCameraId);
        DataHolder.getInstance().setCameraId(mCameraId);
        // Device controller must be initialize before set preview size, because surfaceAvailable
        // may be called immediately when setPreviewSize.
        mIDeviceController = new VisualSearchDevice2Controller(app.getActivity(), cameraContext);
        initSettingManager(mCameraId);
        initStatusMonitor();
        prepareAndOpenCamera(false, mCameraId, isFromLaunch);
        ThumbnailHelper.setApp(app);
        mMemoryManager = new MemoryManagerImpl(app.getActivity());
        mVisualSearchModeHelper = new VisualSearchModeHelper(cameraContext);
        mMainHandler = new VisualSearchHandler(mIApp.getActivity().getMainLooper());
        mVisualSearchView = new VisualSearchView(app, cameraContext);
        DataHolder.getInstance().setIsResumed(true);
        DataHolder.getInstance().setRequesting(true);
        mMainHandler.sendEmptyMessage(MSG_INIT_VIEW);
        LogHelper.d(TAG, "[init]- ");
        mSensorManager = ((SensorManager) mIApp.getActivity().getSystemService(mIApp.getActivity().SENSOR_SERVICE));
        if (mSensorManager != null) {
            Sensor mRVSensor = mSensorManager.getDefaultSensor(Sensor.TYPE_ROTATION_VECTOR);
            if (mRVSensor != null) {
                mSensorManager.registerListener(mRVSensorEventListener, mRVSensor, SensorManager.SENSOR_DELAY_NORMAL);
            }
        }
    }

    @SuppressLint("StaticFieldLeak")
    class LoadModelsAsyncTask extends AsyncTask<Void, Void, Integer> {
        @Override
        protected Integer doInBackground(Void... voids) {
            return initModels();
        }

        @Override
        protected void onPreExecute() {
            super.onPreExecute();
        }

        @Override
        protected void onPostExecute(Integer result) {
            super.onPostExecute(result);
            if (result == 1) {
                isInitFinish = true;
                DataHolder.getInstance().setInitFinished(true);
            } else {
                Toast.makeText(mApp.getActivity(), "init model failed,please check!", Toast.LENGTH_SHORT).show();
                isInitFinish = false;
                DataHolder.getInstance().setInitFinished(false);
            }
        }
    }

    private int initModels() {
        int result = 0, result1 = 0;
        VisualSearchManager.getInstance().init();
        AssetManager assetManager = mApp.getActivity().getAssets();
        String[] model_labels_1 = mApp.getActivity().getResources().getStringArray(R.array.detect_one_labelList);
        String[] model_labels_2 = mApp.getActivity().getResources().getStringArray(R.array.detect_labelList);
        List<String> model_labelList_1 = loadLabelList(model_labels_1);
        List<String> model_labelList_2 = loadLabelList(model_labels_2);

        if (model_labelList_1 != null) {
            //result = VisualSearchManager.getInstance().initModels(Const.MODEL_TYPE_0, assetManager, "detect_one.tflite", model_labelList_1);
            //TODO Only for beta version test
            result = VisualSearchManager.getInstance().initModels(Const.MODEL_TYPE_0, "/data/local/tmp/visualsearch/detect_one.tflite", model_labelList_1);
        }
        if (model_labelList_2 != null) {
            //result1 = VisualSearchManager.getInstance().initModels(Const.MODEL_TYPE_1, assetManager, "detect.tflite", model_labelList_2);
            //TODO Only for beta version test
            result1 = VisualSearchManager.getInstance().initModels(Const.MODEL_TYPE_1,"/data/local/tmp/visualsearch/detect.tflite", model_labelList_2);
        }
        LogHelper.d(TAG, "result= " + result + ", result1 = " + result1);
        return result & result1;
    }

    /**
     * Reads label list from arrays.
     */
    private List<String> loadLabelList(String[] labels) {
        try {
            List<String> labelList = new ArrayList<>();
            if (labels != null) {
                labelList.addAll(Arrays.asList(labels));
            }
            return labelList;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    private long num;
    private float[] lastQuaternion = new float[4];
    private SensorEventListener mRVSensorEventListener = new SensorEventListener() {
        @Override
        public void onSensorChanged(SensorEvent event) {

            float[] quaternionZ = new float[4];
            SensorManager.getQuaternionFromVector(quaternionZ, event.values);

            if (num >= 3) {
                //Euler TO Quaternion
                float[] quaternionX = new float[4];
                quaternionX[0] = lastQuaternion[0];
                quaternionX[1] = -lastQuaternion[1];
                quaternionX[2] = -lastQuaternion[2];
                quaternionX[3] = -lastQuaternion[3];
                float[] quaternionY = new float[4];
                quaternionY[0] = quaternionZ[0]*quaternionX[0] - quaternionZ[1]*quaternionX[1] - quaternionZ[2]*quaternionX[2] -quaternionZ[3]*quaternionX[3];
                quaternionY[1] = quaternionZ[0]*quaternionX[1] + quaternionZ[1]*quaternionX[0] + quaternionZ[2]*quaternionX[3] -quaternionZ[3]*quaternionX[2];
                quaternionY[2] = quaternionZ[0]*quaternionX[2] - quaternionZ[1]*quaternionX[3] + quaternionZ[2]*quaternionX[0] +quaternionZ[3]*quaternionX[1];
                quaternionY[3] = quaternionZ[0]*quaternionX[3] + quaternionZ[1]*quaternionX[2] - quaternionZ[2]*quaternionX[1] +quaternionZ[3]*quaternionX[0];

                //Quaternion TO Euler
                //Calculate the displacement to the X Y Z axis
                double z = Math.atan2(2*quaternionY[1]*quaternionY[2] - 2*quaternionY[0]*quaternionY[3]
                        , 2*quaternionY[0]*quaternionY[0] + 2*quaternionY[1]*quaternionY[1]-1);
                double x = -Math.asin(2*quaternionY[1]*quaternionY[3] + 2*quaternionY[0]*quaternionY[2]);
                double y = Math.atan2(2*quaternionY[2]*quaternionY[3] - 2*quaternionY[0]*quaternionY[1]
                        , 2*quaternionY[0]*quaternionY[0] + 2*quaternionY[3]*quaternionY[3]-1);

                x = Math.abs(x);
                y = Math.abs(y);
                z = Math.abs(z);
                //Converts the value of X Y Z obtained to an integer
                int distanceX = (int)Math.round(x / 0.01);
                int distanceY = (int)Math.round(y / 0.01);
                int distanceZ = (int)Math.round(z / 0.01);
                //Determine whether to hide the dot animation according to the shaking degree of the device
                if (distanceX > X || distanceY > Y  || distanceZ > Z || distanceX < -X || distanceY < -Y  || distanceZ < -Z ) {
                    cancelQueryPreImage();
                    if(imageTags != null && imageTags.size() > 0) {
                        mMainHandler.sendEmptyMessage(MSG_CLEAR_POINTS);
                    }
                } else {
                    DataHolder.getInstance().setRequesting(true);
                }
                if (distanceY != 0) {
                    lastQuaternion = quaternionZ;
                }
            } else {
                num++;
                lastQuaternion = quaternionZ;
            }
        }

        @Override
        public void onAccuracyChanged(Sensor sensor, int accuracy) {

        }
    };

    @Override
    public void resume(@Nonnull DeviceUsage deviceUsage) {
        LogHelper.d(TAG, "[resume]+");
        super.resume(deviceUsage);
        mIsResumed = true;
        initSettingManager(mCameraId);
        initStatusMonitor();
        mMemoryManager.addListener(this);
        mMemoryManager.initStateForCapture(
                mICameraContext.getStorageService().getCaptureStorageSpace());
        mMemoryState = IMemoryManager.MemoryAction.NORMAL;
        updateModeDeviceState(MODE_DEVICE_STATE_PREVIEWING);
        mIDeviceController.queryCameraDeviceManager();
        prepareAndOpenCamera(false, mCameraId, false);
        DataHolder.getInstance().setIsResumed(true);
        DataHolder.getInstance().setRequesting(true);
        mMainHandler.sendEmptyMessage(MSG_SHOW_ANIMATION);
        mMainHandler.sendEmptyMessage(MSG_CLEAR_POINTS);
        LogHelper.d(TAG, "[resume]-");
    }

    @Override
    public void pause(@Nonnull DeviceUsage nextModeDeviceUsage) {
        LogHelper.d(TAG, "[pause]+");
        DataHolder.getInstance().setIsResumed(false);
        super.pause(nextModeDeviceUsage);
        mIsResumed = false;
        mMemoryManager.removeListener(this);
        //clear the surface listener
        mIApp.getAppUi().clearPreviewStatusListener(mISurfaceStatusListener);

        if (mNeedCloseCameraIds.size() > 0) {
            LogHelper.d(TAG, "[pause] mNeedCloseCameraId = " + mCameraId);
            prePareAndCloseCamera(needCloseCameraSync(), mCameraId);
            recycleSettingManager(mCameraId);
        } else if (mNeedCloseSession) {
            clearAllCallbacks(mCameraId);
            mIDeviceController.closeSession();
        } else {
            clearAllCallbacks(mCameraId);
            mIDeviceController.stopPreview();
        }
        mMainHandler.sendEmptyMessage(MSG_DISMISS_ANIMATION);
        cancelQueryPreImage();
        LogHelper.d(TAG, "[pause]-");
    }

    @Override
    public void unInit() {
        super.unInit();
        LogHelper.d(TAG, "[unInit]+");
        mIDeviceController.destroyDeviceController();
        mMainHandler.sendEmptyMessage(MSG_DISMISS_ANIMATION);
        mMainHandler.sendEmptyMessage(MSG_UNINIT_VIEW);
        if (mSensorManager != null && mRVSensorEventListener != null) {
            mSensorManager.unregisterListener(mRVSensorEventListener);
            mSensorManager = null;
        }
        cancelQueryPreImage();
        DataHolder.getInstance().setIsResumed(false);
        DataHolder.getInstance().setInitFinished(false);
        LogHelper.d(TAG, "[unInit] isComputeFinish = " + isComputeFinish);
        if (isComputeFinish && DataHolder.getInstance().isComputeFinished()) {
            VisualSearchManager.getInstance().onDestroy();
            DataHolder.getInstance().setComputeFinished(false);
        }
        if (mVisualSearchView != null) {
            mVisualSearchView.clearPoints();
            mVisualSearchView = null;
        }
        isInitFinish = false;
        LogHelper.d(TAG, "[unInit]-");
    }

    @Override
    public boolean onCameraSelected(@Nonnull String newCameraId) {
        LogHelper.i(TAG, "[onCameraSelected] ,new id:" + newCameraId + ",current id:" + mCameraId);
        super.onCameraSelected(newCameraId);
        //first need check whether can switch camera or not.
        if (canSelectCamera(newCameraId)) {
            //trigger switch camera animation in here
            //must before mCamera = newCameraId, otherwise the animation's orientation and
            // whether need mirror is error.
            synchronized (mPreviewDataSync) {
                startSwitchCameraAnimation();
            }
            doCameraSelect(mCameraId, newCameraId);
            return true;
        } else {
            return false;
        }
    }

    @Override
    public boolean onShutterButtonFocus(boolean pressed) {
        return true;
    }

    @Override
    protected boolean doShutterButtonClick() {
        //Storage case
        boolean storageReady = mICameraContext.getStorageService().getCaptureStorageSpace() > 0;
        boolean isDeviceReady = mIDeviceController.isReadyForCapture();
        LogHelper.i(TAG, "onShutterButtonClick, is storage ready : " + storageReady + "," +
                "isDeviceReady = " + isDeviceReady);
        DataHolder.getInstance().setIsResumed(false);
        cancelQueryPreImage();
        mVisualSearchView.clearPoints();
        if (storageReady && isDeviceReady && mIsResumed
                && mMemoryState != IMemoryManager.MemoryAction.STOP && isInitFinish) {
            //trigger capture animation
            startCaptureAnimation();
            mPhotoStatusResponder.statusChanged(KEY_PHOTO_CAPTURE, PHOTO_CAPTURE_START);
            updateModeDeviceState(MODE_DEVICE_STATE_CAPTURING);
            disableAllUIExceptionShutter();
            mIDeviceController.updateGSensorOrientation(mIApp.getGSensorOrientation());
            mIDeviceController.takePicture(this);
        }
        return true;
    }

    @Override
    public boolean onShutterButtonLongPressed() {
        return false;
    }

    private void startSwitchCameraAnimation() {
        // Prepare the animation data.
        AnimationData data = prepareAnimationData(mPreviewData, mPreviewWidth,
                mPreviewHeight, mPreviewFormat);
        // Trigger animation start.
        mIApp.getAppUi().animationStart(IAppUi.AnimationType.TYPE_SWITCH_CAMERA, data);
    }

    private void stopSwitchCameraAnimation() {
        mIApp.getAppUi().animationEnd(IAppUi.AnimationType.TYPE_SWITCH_CAMERA);
    }

    private void stopChangeModeAnimation() {
        mIApp.getAppUi().animationEnd(IAppUi.AnimationType.TYPE_SWITCH_MODE);
    }

    private AnimationData prepareAnimationData(byte[] data, int width, int height, int format) {
        // Prepare the animation data.
        AnimationData animationData = new AnimationData();
        animationData.mData = data;
        animationData.mWidth = width;
        animationData.mHeight = height;
        animationData.mFormat = format;
        animationData.mOrientation = mVisualSearchModeHelper.getCameraInfoOrientation(mCameraId,
                mIApp.getActivity());
        animationData.mIsMirror = mVisualSearchModeHelper.isMirror(mCameraId, mIApp.getActivity());
        return animationData;
    }


    private void prepareAndOpenCamera(boolean needOpenCameraSync, String CameraId, boolean isFromLaunch) {
        LogHelper.d(TAG, "[prepareAndOpenCamera] +: CameraId :" + CameraId + ",isFromLaunch: " +isFromLaunch);
        mPreviewUpdateTime = System.currentTimeMillis();
        mCameraId = CameraId;
        StatusMonitor statusMonitor = mICameraContext.getStatusMonitor(mCameraId);
        statusMonitor.registerValueChangedListener(KEY_PICTURE_SIZE, mStatusChangeListener);
        statusMonitor.registerValueChangedListener(KEY_FORMTAT, mStatusChangeListener);
        statusMonitor.registerValueChangedListener(KEY_MATRIX_DISPLAY_SHOW, mStatusChangeListener);


        //before open camera, prepare the device callback and size changed callback.
        mIDeviceController.setDeviceCallback(this);
        mIDeviceController.setPreviewSizeReadyCallback(this);
        //prepare device info.
        DeviceInfo info = new DeviceInfo();
        info.setCameraId(mCameraId);
        info.setSettingManager(mISettingManager);
        info.setNeedOpenCameraSync(needOpenCameraSync);
        info.setNeedFastStartPreview(isFromLaunch);
        mIDeviceController.openCamera(info);
    }

    private void initSettingManager(String mCameraId) {
        SettingManagerFactory smf = mICameraContext.getSettingManagerFactory();
        mISettingManager = smf.getInstance(
                mCameraId,
                getModeKey(),
                ModeType.PHOTO,
                mCameraApi);
    }

    @Override
    protected ISettingManager getSettingManager() {
        return mISettingManager;
    }

    @Override
    public void onDataReceived(IVisualSearchDeviceController.DataCallbackInfo dataCallbackInfo) {
        //when mode receive the data, need save it.
        byte[] data = dataCallbackInfo.data;
        int format = dataCallbackInfo.mBufferFormat;
        boolean needUpdateThumbnail = dataCallbackInfo.needUpdateThumbnail;
        boolean needRestartPreview = dataCallbackInfo.needRestartPreview;
        LogHelper.d(TAG, "onDataReceived, data = " + data + ", format = " + format + ", mIsResumed = " + mIsResumed +
                ", needUpdateThumbnail = " + needUpdateThumbnail + ", needRestartPreview = " +
                needRestartPreview);
        if (data != null) {
            CameraSysTrace.onEventSystrace(JPEG_CALLBACK, true);
        }

        if (data != null && format == ImageFormat.JPEG) {
            queryImage(data);
            new SaveDataAsyncTask().execute(data);
        }

        if (data != null) {
            CameraSysTrace.onEventSystrace(JPEG_CALLBACK, false);
        }
    }

    class SaveDataAsyncTask extends AsyncTask<byte[], Void, Void> {
        @Override
        protected Void doInBackground(byte[]... prams) {
            LogHelper.d(TAG, "SaveDataAsyncTask saveData");
            saveData(prams[0]);
            return null;
        }
    }

    private void queryImage(byte[] data) {
        LogHelper.d(TAG, "queryImage ");
        CameraUtil.setChangeIconState(true);
        mApp.getActivity().runOnUiThread(() -> {
            DataHolder.getInstance().setImageData(data);
            DataHolder.getInstance().setFlag(1);
            if (DataHolder.getInstance().getImageData() != null && DataHolder.getInstance().getFlag() == 1) {
                Intent intent = new Intent(mApp.getActivity(),ImageParseActivity.class);
                mApp.getActivity().startActivity(intent);
            } else {
                LogHelper.e(TAG,"queryImage data is null");
            }
        });
    }


    private Bitmap byteToBitmap(byte[] data) {
        if (data != null) {
            int rotation = CameraUtil.getJpegRotationFromDeviceSpec(Integer.parseInt(mCameraId),
                    mIApp.getGSensorOrientation(), mIApp.getActivity());
            Bitmap bitmap = BitmapFactory.decodeByteArray(data, 0, data.length);
            Matrix matrix = new Matrix();
            matrix.preRotate(rotation);
            return Bitmap.createBitmap(bitmap, 0, 0, bitmap.getWidth(), bitmap.getHeight(), matrix, true);
        }
        return null;
    }

    @Override
    public void onPostViewCallback(byte[] data) {
        LogHelper.d(TAG, "[onPostViewCallback] data = " + data + ",mIsResumed = " + mIsResumed);
        CameraSysTrace.onEventSystrace(POST_VIEW_CALLBACK, true, true);
        if (data != null && mIsResumed) {
            //will update the thumbnail
            int rotation = CameraUtil.getJpegRotationFromDeviceSpec(Integer.parseInt(mCameraId),
                    mIApp.getGSensorOrientation(), mIApp.getActivity());
            Bitmap bitmap = BitmapCreator.createBitmapFromYuv(data,
                    ThumbnailHelper.POST_VIEW_FORMAT,
                    ThumbnailHelper.getThumbnailWidth(),
                    ThumbnailHelper.getThumbnailHeight(),
                    mIApp.getAppUi().getThumbnailViewWidth(),
                    rotation);
            //mIApp.getAppUi().updateThumbnail(bitmap);
            //mVisualSearchView.updateThumbnail(bitmap);
        }
        CameraSysTrace.onEventSystrace(POST_VIEW_CALLBACK, false,true);
    }

    @Override
    public void onCameraOpened(String cameraId) {
        updateModeDeviceState(MODE_DEVICE_STATE_OPENED);
    }

    @Override
    public void beforeCloseCamera() {
        updateModeDeviceState(MODE_DEVICE_STATE_CLOSED);
    }

    @Override
    public void afterStopPreview() {
        updateModeDeviceState(MODE_DEVICE_STATE_OPENED);
    }

    ExecutorService singleThreadExecutor  = Executors.newSingleThreadScheduledExecutor();
    @Override
    public void onPreviewCallback(byte[] data, int format) {
        long time = System.currentTimeMillis() - mPreviewUpdateTime;
        boolean isRequesting = DataHolder.getInstance().isRequesting();
        LogHelper.d(TAG, "[onPreviewCallback] data = " + data + ", mPreviewWidth " + mPreviewWidth+", isRequesting = "+isRequesting);
        if (data != null && mPreviewWidth > 0 && isRequesting) {
            singleThreadExecutor.execute(new Runnable() {
                @Override
                public void run() {
                    DataHolder.getInstance().setRequesting(true);
                    mPreviewUpdateTime = System.currentTimeMillis();
                    int width = mPreviewWidth;
                    int height = mPreviewHeight;
                    LogHelper.d(TAG, "[onPreviewCallback] size " + width + " - " + height);
                    if (data != null) {
                        long startTime = SystemClock.uptimeMillis();
                        int rotation = CameraUtil.getJpegRotationFromDeviceSpec(
                            Integer.parseInt(mCameraId),mIApp.getGSensorOrientation(), mIApp.getActivity());
                        LogHelper.d(TAG, "[createBitmapFromYuv] " + width + " - " + height + " - " + rotation);
                        bitmapPre = BitmapCreator.createBitmapFromYuv(data, ImageFormat.NV21, width, height,
                            width, rotation);
                        //FileUtil.saveBitmap(bitmapPre, "preview_" + SystemClock.uptimeMillis() + "_" + rotation + ".png");
                        long endTime = SystemClock.uptimeMillis();
                        LogHelper.d(TAG, "yuvToBitmapPre run time: " + (endTime - startTime));
                        if (isInitFinish && isRequesting) {
                            isComputeFinish = false;
                            android.util.Size modelInputSize = new android.util.Size(Const.IMAGE_SIZE_WIDTH, Const.IMAGE_SIZE_HEIGHT);
                            VisualSearchManager.getInstance().detectImage(bitmapPre, modelInputSize, new VisualSearchManager.ImageTagListener() {
                                @Override
                                public void updateImageTags(ArrayList<ImageTag> tags) {
                                    isComputeFinish = true;
                                    updateModeDeviceState(MODE_DEVICE_STATE_CAPTURING);
                                    if(tags != null && tags.size() > 0){
                                        imageTags.clear();
                                        imageTags.addAll(tags);
                                        updateRecognitionListLocal();
                                    }
                                }
                            });
                        }
                    }
                }
            });
        }
        if (!mIsResumed) {
            return;
        }
        synchronized (mPreviewDataSync) {
            //Notify preview started.
            if (!mIsMatrixDisplayShow) {
                mIApp.getAppUi().applyAllUIEnabled(true);
            }
            mIApp.getAppUi().onPreviewStarted(mCameraId);
            if (mPreviewData == null) {
                mIApp.getActivity().runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        // so need notify switch camera animation need stop.
                        stopSwitchCameraAnimation();
                        //need notify change mode animation need stop if is doing change mode.
                        stopChangeModeAnimation();
                        //stop the capture animation if is doing capturing.
                        stopCaptureAnimation();
                    }
                });
            }
            updateModeDeviceState(MODE_DEVICE_STATE_PREVIEWING);

            mPreviewData = data;
            mPreviewFormat = format;
        }
    }

    private void cancelQueryPreImage(){
        DataHolder.getInstance().setRequesting(false);
    }


    private void updateRecognitionListLocal(){
        mMainHandler.sendEmptyMessage(MSG_UPDATE_RECOGNITION);
    }

    @Override
    public void onPreviewSizeReady(Size previewSize) {
        updatePictureSizeAndPreviewSize(previewSize);
    }

    private void initStatusMonitor() {
        StatusMonitor statusMonitor = mICameraContext.getStatusMonitor(mCameraId);
        mPhotoStatusResponder = statusMonitor.getStatusResponder(KEY_PHOTO_CAPTURE);
    }

    private void saveData(byte[] data) {
        if (data != null) {
            //check memory to decide whether it can take next picture.
            //if not, show saving
            ISettingManager.SettingController controller = mISettingManager.getSettingController();
            String dngState = controller.queryValue(KEY_DNG);
            long saveDataSize = data.length;
            if (dngState != null && "on".equalsIgnoreCase(dngState)) {
                saveDataSize = saveDataSize + DNG_IMAGE_SIZE;
            }
            synchronized (mCaptureNumberSync) {
                mCapturingNumber++;
                mMemoryManager.checkOneShotMemoryAction(saveDataSize);
            }
            // set image save path
            String fileDirectory = Environment.getExternalStoragePublicDirectory(
                    Environment.DIRECTORY_DCIM).toString() + "/VisualSearch";
            File file = new File(fileDirectory);
            if(!file.exists()){
                file.mkdir();
            }
            //String fileDirectory = mICameraContext.getStorageService().getFileDirectory();
            Size exifSize = CameraUtil.getSizeFromExif(data);

            ContentValues contentValues = mVisualSearchModeHelper.createContentValues(data,
                    fileDirectory, exifSize.getWidth(), exifSize.getHeight());
            mICameraContext.getMediaSaver().addSaveRequest(data, contentValues, null,
                    mMediaSaverListener);
            //reset the switch camera to null
            synchronized (mPreviewDataSync) {
                mPreviewData = null;
            }
        }
    }

    private void updatePictureSizeAndPreviewSize(Size previewSize) {
        ISettingManager.SettingController controller = mISettingManager.getSettingController();
        String size = controller.queryValue(KEY_PICTURE_SIZE);
        if (size != null && mIsResumed) {
            String[] pictureSizes = size.split("x");
            mCaptureWidth = Integer.parseInt(pictureSizes[0]);
            mCaptureHeight = Integer.parseInt(pictureSizes[1]);
            mIDeviceController.setPictureSize(new Size(mCaptureWidth, mCaptureHeight));
            int width = previewSize.getWidth();
            int height = previewSize.getHeight();
            LogHelper.d(TAG, "[updatePictureSizeAndPreviewSize] picture size: " + mCaptureWidth +
                    " X" + mCaptureHeight + ",current preview size:" + mPreviewWidth + " X " +
                    mPreviewHeight + ",new value :" + width + " X " + height);
            if (width != mPreviewWidth || height != mPreviewHeight) {
                onPreviewSizeChanged(width, height);
            }
        }

    }

    private void disableAllUIExceptionShutter() {
        mIApp.getAppUi().applyAllUIEnabled(false);
        mIApp.getAppUi().setUIEnabled(IAppUi.SHUTTER_BUTTON, true);
        mIApp.getAppUi().setUIEnabled(IAppUi.SHUTTER_TEXT, false);
    }

    private void updateThumbnail(byte[] data, int imageWidth) {
        Bitmap bitmap = BitmapCreator.createBitmapFromJpegWithoutExif(data, imageWidth,
                mIApp.getAppUi().getThumbnailViewWidth());
        int rotation = CameraUtil.getJpegRotationFromDeviceSpec(Integer.parseInt(mCameraId),
                mIApp.getGSensorOrientation(), mIApp.getActivity());
        Matrix matrix = new Matrix();
        matrix.preRotate(rotation);
        bitmap = Bitmap.createBitmap(bitmap, 0, 0, bitmap.getWidth(), bitmap.getHeight(), matrix, true);

        //mIApp.getAppUi().updateThumbnail(bitmap);
        //mVisualSearchView.updateThumbnail(bitmap);
    }

    @Override
    public void onMemoryStateChanged(IMemoryManager.MemoryAction state) {
        if (state == IMemoryManager.MemoryAction.STOP && mCapturingNumber != 0) {
            //show saving
            LogHelper.d(TAG, "memory low, show saving");
            mIApp.getAppUi().showSavingDialog(null, true);
            mIApp.getAppUi().applyAllUIVisibility(View.INVISIBLE);
        }
    }

    private void startCaptureAnimation() {
        mIApp.getAppUi().animationStart(IAppUi.AnimationType.TYPE_CAPTURE, null);
    }

    private void stopCaptureAnimation() {
        mIApp.getAppUi().animationEnd(IAppUi.AnimationType.TYPE_CAPTURE);
    }

    private void recycleSettingManager(String mCameraId) {
        mICameraContext.getSettingManagerFactory().recycle(mCameraId);
    }

    private void clearAllCallbacks(String mCameraId) {
        mIDeviceController.setPreviewSizeReadyCallback(null);
        StatusMonitor statusMonitor = mICameraContext.getStatusMonitor(mCameraId);
        statusMonitor.unregisterValueChangedListener(KEY_PICTURE_SIZE, mStatusChangeListener);
        statusMonitor.unregisterValueChangedListener(KEY_FORMTAT, mStatusChangeListener);
        statusMonitor.unregisterValueChangedListener(
                KEY_MATRIX_DISPLAY_SHOW, mStatusChangeListener);

    }

    private void prePareAndCloseCamera(boolean needSync, String mCameraId) {
        clearAllCallbacks(mCameraId);
        mIDeviceController.closeCamera(needSync);
        mIsMatrixDisplayShow = false;
        //reset the preview size and preview data.
        mPreviewWidth = 0;
        mPreviewHeight = 0;
    }

    /**
     * surface changed listener.
     */
    private class SurfaceChangeListener implements IAppUiListener.ISurfaceStatusListener {

        @Override
        public void surfaceAvailable(Object surfaceObject, int width, int height) {
            LogHelper.d(TAG, "surfaceAvailable,device controller = " + mIDeviceController
                    + ",w = " + width + ",h = " + height);
            if (mModeHandler != null) {
                mModeHandler.post(new Runnable() {
                    @Override
                    public void run() {
                        if (mIDeviceController != null && mIsResumed) {
                            mIDeviceController.updatePreviewSurface(surfaceObject);
                        }
                    }
                });
            }
        }

        @Override
        public void surfaceChanged(Object surfaceObject, int width, int height) {
            LogHelper.d(TAG, "surfaceChanged, device controller = " + mIDeviceController
                    + ",w = " + width + ",h = " + height);
            if (mModeHandler != null) {
                mModeHandler.post(new Runnable() {
                    @Override
                    public void run() {
                        if (mIDeviceController != null && mIsResumed) {
                            mIDeviceController.updatePreviewSurface(surfaceObject);
                        }
                    }
                });
            }
        }

        @Override
        public void surfaceDestroyed(Object surfaceObject, int width, int height) {
            LogHelper.d(TAG, "surfaceDestroyed,device controller = " + mIDeviceController);
        }
    }

    /**
     * Status change listener implement.
     */
    private class MyStatusChangeListener implements StatusMonitor.StatusChangeListener {
        @Override
        public void onStatusChanged(String key, String value) {
            LogHelper.d(TAG, "[onStatusChanged] key = " + key + ",value = " + value);
            if (KEY_PICTURE_SIZE.equalsIgnoreCase(key)) {
                String[] sizes = value.split("x");
                mCaptureWidth = Integer.parseInt(sizes[0]);
                mCaptureHeight = Integer.parseInt(sizes[1]);
                mIDeviceController.setPictureSize(new Size(mCaptureWidth, mCaptureHeight));
                Size previewSize = mIDeviceController.getPreviewSize((double) mCaptureWidth /
                        mCaptureHeight);
                int width = previewSize.getWidth();
                int height = previewSize.getHeight();
                if (width != mPreviewWidth || height != mPreviewHeight) {
                    onPreviewSizeChanged(width, height);
                }
            } else if (KEY_MATRIX_DISPLAY_SHOW.equals(key)) {
                mIsMatrixDisplayShow = "true".equals(value);
            } else if (KEY_FORMTAT.equalsIgnoreCase(key)) {
                mIDeviceController.setFormat(value);
                LogHelper.i(TAG, "[onStatusChanged] key = " + key
                        + ", set sCaptureFormat = " + value);
            }
        }
    }

    private void onPreviewSizeChanged(int width, int height) {
        //Need reset the preview data to null if the preview size is changed.
        synchronized (mPreviewDataSync) {
            mPreviewData = null;
        }
        mPreviewWidth = width;
        mPreviewHeight = height;
        mIApp.getAppUi().setPreviewSize(mPreviewWidth, mPreviewHeight, mISurfaceStatusListener);
    }

    private MediaSaver.MediaSaverListener mMediaSaverListener
            = new MediaSaver.MediaSaverListener() {

        @Override
        public void onFileSaved(Uri uri) {
            mIApp.notifyNewMedia(uri, true);
            synchronized (mCaptureNumberSync) {
                mCapturingNumber--;
                if (mCapturingNumber == 0) {
                    mMemoryState = IMemoryManager.MemoryAction.NORMAL;
                    mIApp.getAppUi().hideSavingDialog();
                    //mIApp.getAppUi().applyAllUIVisibility(View.VISIBLE);
                }
            }
            LogHelper.d(TAG, "[onFileSaved] uri = " + uri + ", mCapturingNumber = "
                    + mCapturingNumber);
        }
    };

    private class VisualSearchHandler extends Handler {
        public VisualSearchHandler(Looper looper) {
            super(looper);
        }

        @Override
        public void handleMessage(Message msg) {
            this.obtainMessage();
            switch (msg.what) {
                case MSG_INIT_VIEW:
                    if (mVisualSearchView != null) {
                        mVisualSearchView.init();
                    }
                    if (mVisualSearchView != null) {
                        mVisualSearchView.show();
                    }
                    break;
                case MSG_SHOW_VIEW:
                    if (mVisualSearchView != null) {
                        mVisualSearchView.show();
                    }
                    break;
                case MSG_HIDE_VIEW:
                    if (mVisualSearchView != null) {
                        mVisualSearchView.hide();
                    }
                    break;
                case MSG_UNINIT_VIEW:
                    if (mVisualSearchView != null) {
                        mVisualSearchView.hide();
                    }
                    if (mVisualSearchView != null) {
                        mVisualSearchView.unInit();
                    }
                    break;
                case MSG_UPDATE_RECOGNITION:
                    if (mPreviewWidth > 0 && CameraUtil.isChangeIconState() && mVisualSearchView != null) {
                        mVisualSearchView.updatePoints(imageTags,bitmapPre,mPreviewWidth,mPreviewHeight);
                    }
                    break;
                case MSG_CLEAR_POINTS:
                    if (mVisualSearchView != null) {
                        mVisualSearchView.clearPoints();
                    }
                    break;
                case MSG_SHOW_ANIMATION:
                    if (mVisualSearchView != null) {
                        mVisualSearchView.startLoadingPoints();
                    }
                    break;
                case MSG_DISMISS_ANIMATION:
                    if (mVisualSearchView != null) {
                        mVisualSearchView.stopLoadingPoints();
                    }
                    break;
                default:
                    break;
            }

        }
    }

    /**
     * Reads label list from Assets.
     */
    private List<String> loadLabelList(Activity activity, String fileName) {
        try {
            List<String> labelList = new ArrayList<>();
            BufferedReader reader =
                    new BufferedReader(new InputStreamReader(activity.getAssets().open(fileName)));
            String line;
            while ((line = reader.readLine()) != null) {
                labelList.add(line);
            }
            reader.close();
            return labelList;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    private boolean canSelectCamera(@Nonnull String newCameraId) {
        boolean value = true;

        if (newCameraId == null || mCameraId.equalsIgnoreCase(newCameraId)) {
            value = false;
        }
        LogHelper.d(TAG, "[canSelectCamera] +: " + value);
        return value;
    }

    private void doCameraSelect(String oldCamera, String newCamera) {
        LogHelper.d(TAG, "[doCameraSelect] + oldCamera: " + oldCamera +" ,newCamera :"+ newCamera);
        mIApp.getAppUi().applyAllUIEnabled(false);
        mIApp.getAppUi().onCameraSelected(newCamera);
        prePareAndCloseCamera(true, oldCamera);
        recycleSettingManager(oldCamera);
        initSettingManager(newCamera);
        prepareAndOpenCamera(false, newCamera, true);
    }

}
