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
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.ColorFilter;
import android.graphics.Paint;
import android.graphics.PixelFormat;
import android.graphics.Rect;
import android.graphics.drawable.Drawable;

public class CropBoxDrawable extends Drawable {

    private static final int LINE_COLOR_A = 255;
    private static final int LINE_COLOR_R = 50;
    private static final int LINE_COLOR_G = 50;
    private static final int LINE_COLOR_B = 50;
    private static final float LINE_LENGTH = 50f;
    private static final float FINE_LINE_WIDTH = 1f;
    private static final float THICK_LINE_WIDTH = 7f;

    private static final float STD_SLASH_LENGTH = 3.5f;
    private static final float SLASH_LENGTH = 30f;

    private static final Paint mFineLinePaint = new Paint();
    private static final Paint mThickLinePaint = new Paint();
    private int lineLength;
    private Context mContext;

    static {
        mFineLinePaint.setARGB(LINE_COLOR_A, LINE_COLOR_R, LINE_COLOR_G, LINE_COLOR_B);
        mFineLinePaint.setStrokeWidth(FINE_LINE_WIDTH);
        mFineLinePaint.setStyle(Paint.Style.STROKE);
        mFineLinePaint.setAntiAlias(true);
        mFineLinePaint.setColor(Color.WHITE);

        mThickLinePaint.setARGB(LINE_COLOR_A, LINE_COLOR_R, LINE_COLOR_G, LINE_COLOR_B);
        mThickLinePaint.setStrokeWidth(THICK_LINE_WIDTH);
        mThickLinePaint.setStyle(Paint.Style.STROKE);
        mThickLinePaint.setAntiAlias(true);
        mThickLinePaint.setColor(Color.WHITE);
    }


    public CropBoxDrawable(Context context) {
        super();
        mContext = context;
        lineLength = dpToPx(context, LINE_LENGTH) / 2;
    }

    @Override
    public void draw(Canvas canvas) {
        int left = getBounds().left;
        int top = getBounds().top;
        int right = getBounds().right;
        int bottom = getBounds().bottom;
        Rect mRect = new Rect(left + lineLength, top + lineLength,
                right - lineLength, bottom - lineLength);
        canvas.drawRect(mRect, mFineLinePaint);

        canvas.drawLine(left + lineLength - STD_SLASH_LENGTH, top + lineLength,
                left + lineLength + SLASH_LENGTH, top + lineLength, mThickLinePaint);

        canvas.drawLine(left + lineLength, top + lineLength,
                left + lineLength, top + lineLength + SLASH_LENGTH, mThickLinePaint);

        canvas.drawLine(right - lineLength + STD_SLASH_LENGTH, top + lineLength,
                right - lineLength - SLASH_LENGTH, top + lineLength, mThickLinePaint);

        canvas.drawLine(right - lineLength, top + lineLength - STD_SLASH_LENGTH,
                right - lineLength, top + lineLength + SLASH_LENGTH, mThickLinePaint);

        canvas.drawLine(left + lineLength - STD_SLASH_LENGTH, bottom - lineLength,
                left + lineLength + SLASH_LENGTH, bottom - lineLength, mThickLinePaint);

        canvas.drawLine((left + lineLength), bottom - lineLength,
                (left + lineLength), bottom - lineLength - SLASH_LENGTH, mThickLinePaint);

        canvas.drawLine(right - lineLength + STD_SLASH_LENGTH, bottom - lineLength,
                right - lineLength - SLASH_LENGTH, bottom - lineLength, mThickLinePaint);

        canvas.drawLine((right - lineLength), bottom - lineLength - SLASH_LENGTH,
                right - lineLength, bottom - lineLength + STD_SLASH_LENGTH, mThickLinePaint);

    }

    @Override
    public void setBounds(Rect bounds) {
        super.setBounds(new Rect(bounds.left - lineLength,
                bounds.top - lineLength, bounds.right
                + lineLength, bounds.bottom
                + lineLength));
    }

    @Override
    public void setAlpha(int alpha) {

    }

    @Override
    public void setColorFilter(ColorFilter cf) {

    }

    @Override
    public int getOpacity() {
        return PixelFormat.UNKNOWN;
    }

    private int dpToPx(Context context, float dpValue) {
        final float scale = context.getResources().getDisplayMetrics().density;
        return (int) (dpValue * scale + 0.5f);
    }

    public int getBorderWidth() {
        return dpToPx(mContext, LINE_LENGTH);
    }

    public int getBorderHeight() {
        return dpToPx(mContext, LINE_LENGTH);
    }
}