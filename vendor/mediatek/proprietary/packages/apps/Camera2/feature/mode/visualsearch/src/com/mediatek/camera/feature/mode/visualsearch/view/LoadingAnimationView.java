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

import android.content.Context;
import android.graphics.BlurMaskFilter;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.PointF;
import android.graphics.RectF;
import android.os.Handler;
import android.os.Message;
import android.util.AttributeSet;
import android.util.TypedValue;
import android.view.View;
import android.support.annotation.Nullable;

import java.util.Timer;
import java.util.TimerTask;

/**
 * The preview screen adds animation effects to display the animation
 * position based on the time and coordinate values passed in,
 */

public class LoadingAnimationView extends View {

    private Paint circlePaint;

    private float radiusEnd;

    private int w;
    private int h;
    private int startX1;
    private int startY1;
    private int startX2;
    private int startY2;
    private int rectCenterX;
    private int rectCenterY;

    private int maxDistance;
    private float rectW;
    private float rectH;
    private PointF pointEnd1;
    private PointF pointEnd2;
    private Timer timer;

    private int radius = 6;
    private int period = 50;
    private int orientation = 0;

    private boolean isStop;

    public LoadingAnimationView(Context context) {
        this(context, null);
    }

    public LoadingAnimationView(Context context, @Nullable AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public LoadingAnimationView(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);

    }

    /**
     * @param radius      circlePaint radius
     * @param period      circlePaint animation refresh time
     * @param orientation Display the location of the circlePaint according to orientation
     */
    public void init(int radius, int period, int orientation) {
        this.radius = radius;
        this.period = period;
        this.orientation = orientation;
        initPaint();
        initPoint();
    }

    public void start() {
        isStop = false;
        if (timer != null) {
            timer.cancel();
            timer = null;
        }
        timer = new Timer();
        TimerTask timerTask = new TimerTask() {
            public void run() {
                if (w > 0) {
                    changePoint();
                }
            }
        };
        resetState(w, h);
        timer.schedule(timerTask, 0, period * dp2px(radius * 3));
    }

    public void stop() {
        isStop = true;
        if (timer != null) {
            timer.cancel();
            timer = null;
            resetState(w, h);
        }
    }

    private void initPoint() {
        pointEnd1 = new PointF(startX1, startY1);
        pointEnd2 = new PointF(startX2, startY2);
    }

    private void initPaint() {
        setLayerType(View.LAYER_TYPE_SOFTWARE, null);
        this.setWillNotDraw(false);
        circlePaint = new Paint(Paint.ANTI_ALIAS_FLAG);
        int circleColor = Color.WHITE;
        circlePaint.setColor(circleColor);
        circlePaint.setAntiAlias(true);
        circlePaint.setStyle(Paint.Style.FILL_AND_STROKE);
        circlePaint.setMaskFilter(new BlurMaskFilter(radius / 3 * 2, BlurMaskFilter.Blur.NORMAL));
    }


    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        super.onSizeChanged(w, h, oldw, oldh);
        this.w = w;
        this.h = h;
        resetState(w, h);
    }

    private void resetState(int w, int h) {
        if (orientation == 0) {
            maxDistance = dp2px(radius * 3);
            startX1 = w / 2;
            startY1 = h / 2 - maxDistance / 2;
            startX2 = w / 2;
            startY2 = h / 2 + maxDistance / 2;
            rectCenterX = w / 2;
            rectCenterY = h / 2;
            radiusEnd = dp2px(radius);
            rectH = (maxDistance >> 1) - radiusEnd;
        } else {
            maxDistance = dp2px(radius * 3);
            startX1 = w / 2 - maxDistance / 2;
            startY1 = h / 2;
            startX2 = w / 2 + maxDistance / 2;
            startY2 = h / 2;
            rectCenterX = w / 2;
            rectCenterY = h / 2;
            radiusEnd = dp2px(radius);
            rectW = (maxDistance >> 1) - radiusEnd;
        }
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        if (pointEnd1 != null && pointEnd1.x > 0) {
            drawEndBall(canvas, pointEnd1, radiusEnd);
            drawEndBall(canvas, pointEnd2, radiusEnd);
            drawRegionRect(canvas, rectW, rectH);
        }
    }

    private void drawEndBall(Canvas canvas, PointF pointF, float radius) {
        canvas.drawCircle(pointF.x, pointF.y, radius, circlePaint);
    }

    //Get the labeled rectangle
    public void drawRegionRect(Canvas canvas, float width, float height) {
        RectF rect = new RectF();
        rect.left = rectCenterX - width;
        rect.right = rectCenterX + width;
        rect.top = rectCenterY - height;
        rect.bottom = rectCenterY + height;
        canvas.drawRect(rect, circlePaint);
    }

    /**
     * changePoint Position
     */
    private void changePoint() {
        if (orientation == 0) {
            int targetY1 = startY1;
            int targetY2 = startY2;
            for (int i = 0; i < maxDistance; i++) {
                if (isStop) {
                    break;
                }
                targetY1++;
                targetY2--;
                try {
                    Message message = new Message();
                    message.arg1 = targetY1;
                    message.arg2 = targetY2;
                    handlerUpdateCircle.sendMessage(message);
                    if (i == (maxDistance - 1)) {
                        handlerEnd.sendEmptyMessage(0);
                    }
                    Thread.sleep(period);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        } else {
            int targetX1 = startX1;
            int targetX2 = startX2;
            for (int i = 0; i < maxDistance; i++) {
                if (isStop) {
                    break;
                }
                targetX1++;
                targetX2--;
                try {
                    Message message = new Message();
                    message.arg1 = targetX1;
                    message.arg2 = targetX2;
                    handlerUpdateCircle.sendMessage(message);
                    if (i == (maxDistance - 1)) {
                        handlerEnd.sendEmptyMessage(0);
                    }
                    Thread.sleep(period);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private Handler handlerUpdateCircle = new Handler(new Handler.Callback() {
        @Override
        public boolean handleMessage(Message msg) {
            if (orientation == 0) {
                int targetY1 = msg.arg1;
                int targetY2 = msg.arg2;
                updatePointPosition(startX1, targetY1, targetY2);
            } else {
                int targetX1 = msg.arg1;
                int targetX2 = msg.arg2;
                updatePointPosition(startY1, targetX1, targetX2);
            }

            return false;
        }
    });

    private Handler handlerEnd = new Handler(new Handler.Callback() {
        @Override
        public boolean handleMessage(Message msg) {
            reset();
            return false;
        }
    });

    /**
     * Updates the dot position based on the value passed in
     */
    private void updatePointPosition(float currentStatic, float current1, float current2) {
        if (orientation == 0) {
            pointEnd1.set(currentStatic, current1);
            pointEnd2.set(currentStatic, current2);
            float i = current1 - current2 - radiusEnd;
            if (i > 0) {
                rectW = radiusEnd - i / 2;
                if (rectW < 0) {
                    rectW = 0;
                }
            }
        } else {
            pointEnd1.set(current1, currentStatic);
            pointEnd2.set(current2, currentStatic);
            float i = current1 - current2 - radiusEnd;
            if (i > 0) {
                rectH = radiusEnd - i / 2;
                if (rectH < 0) {
                    rectH = 0;
                }
            }
        }
        invalidate();
    }


    public void reset() {
        pointEnd1.set(startX1, startY1);
        pointEnd2.set(startX2, startY2);
        invalidate();
    }

    /**
     * dp 2 px
     *
     * @param dpVal dp value
     */
    protected int dp2px(int dpVal) {
        return (int) TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP,
                dpVal, getResources().getDisplayMetrics());
    }
}
