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

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffXfermode;
import android.graphics.Rect;
import android.graphics.RectF;
import android.text.TextUtils;
import android.util.AttributeSet;
import android.util.Size;
import android.view.MotionEvent;
import android.widget.ImageView;

import com.mediatek.camera.feature.mode.visualsearch.bean.ImageTag;
import com.mediatek.camera.feature.mode.visualsearch.utils.CommonUtils;
import java.util.ArrayList;


@SuppressLint("AppCompatCustomView")
public class ImagePointsView extends ImageView {

    private static final int RADIUS_IN = 10;
    private static final int RADIUS_OUT = 25;
    private static final Paint outCirclePaint = new Paint();
    private static final Paint inCirclePaint = new Paint();
    private static final Paint selectCirclePaint = new Paint();
    private static final Paint selectTextPaint = new Paint();
    private static final Paint linePaint = new Paint();
    private static final int IN_CIRCLE_COLOR = Color.WHITE;
    private static final int SHADOW_ALPHA = (int) (255 * 0.5);
    private static final float LINE_STROKE_WIDTH = 5f;
    public int scrollOffset;
    public boolean drawImageTagRegion = false;

    private int selectedImageTagIndex = -1;
    private String tagText = "";
    private Float outlineStrokeWidth;
    private OnClickTagListener onClickTagListener;
    private Size size;

    private ArrayList<ImageTag> mImageTags = null;
    public int mImageTagCount = 0;

    static {

        inCirclePaint.setColor(IN_CIRCLE_COLOR);
        inCirclePaint.setStrokeWidth(LINE_STROKE_WIDTH);
        inCirclePaint.setAntiAlias(true);

        outCirclePaint.setColor(Color.BLACK);
        outCirclePaint.setAlpha(SHADOW_ALPHA);
        outCirclePaint.setAntiAlias(true);

        selectCirclePaint.setColor(Color.GREEN);
        selectCirclePaint.setAlpha(SHADOW_ALPHA);
        selectCirclePaint.setAntiAlias(true);

        selectTextPaint.setColor(Color.GREEN);
        selectTextPaint.setTextSize(3 * 10);
        selectTextPaint.setAntiAlias(true);

        linePaint.setColor(Color.GREEN);
        selectCirclePaint.setAlpha(SHADOW_ALPHA);
        linePaint.setStyle(Paint.Style.STROKE);
        linePaint.setStrokeWidth(1f);

    }

    public void setSize(Size size) {
        this.size = size;
    }

    public void setOnClickTagListener(OnClickTagListener onClickTagListener) {
        this.onClickTagListener = onClickTagListener;
    }

    public void setImageTags(ArrayList<ImageTag> imageTags) {
        selectedImageTagIndex = -1;
        mImageTags = imageTags;
        if (mImageTagCount != imageTags.size()) {
            mImageTagCount = imageTags.size();
        }
        drawImageTagRegion = true;
        invalidate();
    }

    public ImagePointsView(Context ctx, AttributeSet attrs) {
        super(ctx, attrs);
        outlineStrokeWidth = (float) CommonUtils.dpToPx(3, ctx);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        if (event.getAction() == MotionEvent.ACTION_DOWN) {
            if (size != null && mImageTags != null && mImageTags.size() > 0 && mImageTagCount > 0) {
                float x = event.getX();
                float y = event.getY();
                for (int i = 0; i < mImageTagCount; i++) {
                    ImageTag obj = mImageTags.get(i);
                    if (isHit(obj, x, y)) {
                        selectedImageTagIndex = i;
                        tagText = "";
                        onClickTagListener.clickTag(i);
                        break;
                    }
                }
                invalidate();
            }
        }
        return super.onTouchEvent(event);
    }

    public interface OnClickTagListener {
        void clickTag(int position);
    }

    private void drawImageTagRegion(Canvas canvas, int offset) {
        if (mImageTags != null && mImageTagCount > 0) {
            canvas.translate(0f, (float) -offset);
            RectF rect = new RectF();
            rect.left = 0f;
            rect.top = 0f;
            rect.bottom = getHeight();
            rect.right = getWidth();
            Paint paint = new Paint();

            // darken whole image
            paint.setColor(Color.TRANSPARENT);
            paint.setAntiAlias(true);
            paint.setStyle(Paint.Style.FILL);
            if (drawImageTagRegion && mImageTags != null && mImageTags.size() > 0 && mImageTagCount > 0) {
                // clear ImageTag region
                try{
                    paint = new Paint();
                    paint.setColor(Color.RED);
                    paint.setXfermode(new PorterDuffXfermode(PorterDuff.Mode.CLEAR));

                    Paint outlinePaint = new Paint();
                    outlinePaint.setStyle(Paint.Style.STROKE);
                    outlinePaint.setStrokeWidth(outlineStrokeWidth);
                    outlinePaint.setStrokeCap(Paint.Cap.ROUND);
                    mImageTagCount = mImageTags.size();
                    for (int i = 0; i < mImageTagCount; i++) {
                        ImageTag obj = mImageTags.get(i);
                        RectF rect1 = getRegionRect(obj, getWidth(), getHeight());
                        float x = (rect1.left + rect1.right) / 2;
                        float y = (rect1.top + rect1.bottom) / 2;

                        drawOutCircle(canvas, x, y);
                        if (selectedImageTagIndex == i) {
                            drawInSelectCircle(canvas, x, y);
                            if (tagText != null && tagText.equals("")) {
                                drawSelectText(canvas, x, y);
                            }
                        } else {
                            drawInCircle(canvas, x, y);
                        }
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private void drawInCircle(Canvas canvas, float x, float y) {
        canvas.drawCircle(x, y, RADIUS_IN, inCirclePaint);
    }

    private void drawInSelectCircle(Canvas canvas, float x, float y) {
        canvas.drawCircle(x, y, RADIUS_IN, selectCirclePaint);
    }

    private void drawOutCircle(Canvas canvas, float x, float y) {
        canvas.drawCircle(x, y, RADIUS_OUT, outCirclePaint);
    }

    private void drawSelectText(Canvas canvas, float x, float y) {
        if (!TextUtils.isEmpty(tagText) && selectedImageTagIndex != -1) {
            Rect rect = new Rect();
            selectTextPaint.getTextBounds(tagText, 0, tagText.length(), rect);
            Path mPath = new Path();
            mPath.moveTo(x, y);
            int width = rect.width();
            if (x < getWidth() >> 1 && y < getHeight() >> 1) {
                canvas.drawText(tagText, x, y + 3 * RADIUS_OUT, selectTextPaint);
                mPath.lineTo(x + width / 5, y + 2 * RADIUS_OUT);
            } else if (x > getWidth() >> 1 && y < getHeight() >> 1) {
                canvas.drawText(tagText, x - width / 5 * 3, y + 3 * RADIUS_OUT, selectTextPaint);
                mPath.lineTo(x, y + 2 * RADIUS_OUT);
            } else if (x < getWidth() >> 1 && y > getHeight() >> 1) {
                canvas.drawText(tagText, x, y - 3 * RADIUS_OUT, selectTextPaint);
                mPath.lineTo(x + width / 5, y - 2 * RADIUS_OUT);
            } else if (x > getWidth() >> 1 && y > getHeight() >> 1) {
                canvas.drawText(tagText, x - width / 5 * 3, y - 3 * RADIUS_OUT, selectTextPaint);
                mPath.lineTo(x, y - 2 * RADIUS_OUT);
            }
            canvas.drawPath(mPath, linePaint);
        }
    }

    @Override
    protected void onDraw(Canvas canvas) {
        if (size != null) {
            Rect rectSrc = new Rect();
            rectSrc.left = 0;
            rectSrc.right = size.getWidth();
            rectSrc.top = scrollOffset;
            rectSrc.bottom = size.getHeight();
            Rect rectDst = new Rect();
            rectDst.left = 0;
            rectDst.right = getWidth();
            rectDst.top = 0;
            int actualOffset = (scrollOffset * (getHeight() / size.getHeight()));
            rectDst.bottom = getHeight() - actualOffset;
            // canvas.drawBitmap(bmp, rectSrc, rectDst, new Paint());
            drawImageTagRegion(canvas, actualOffset);
        }
    }

    //Get the labeled rectangle
    public RectF getRegionRect(ImageTag tag, int width, int height) {
        RectF rect = new RectF();
        rect.left = (float) (width * tag.getLeft());
        rect.right = (float) (width * tag.getRight());
        rect.top = (float) (height * tag.getTop());
        rect.bottom = (float) (height * tag.getBottom());
        return rect;
    }

    //The center square
    public RectF getCenterRegionRect(RectF rectF) {
        RectF rectSmall = new RectF();
        float x = (rectF.left + rectF.right) * 0.5f;
        float y = (rectF.top + rectF.bottom) * 0.5f;
        rectSmall.left = x - RADIUS_OUT * 2;
        rectSmall.right = x + RADIUS_OUT * 2;
        rectSmall.top = y - RADIUS_OUT * 2;
        rectSmall.bottom = y + RADIUS_OUT * 2;
        return rectSmall;
    }

    public boolean isHit(ImageTag tag, float x, float y) {
        RectF rect1 = getRegionRect(tag, getWidth(), getHeight());
        RectF rectSmall = getCenterRegionRect(rect1);
        return contains(rectSmall, x, y);
    }

    public boolean contains(RectF rect, float x, float y) {
        return rect.left < rect.right && rect.top < rect.bottom && x >= rect.left && x < rect.right && y >= rect.top && y < rect.bottom;
    }

}
