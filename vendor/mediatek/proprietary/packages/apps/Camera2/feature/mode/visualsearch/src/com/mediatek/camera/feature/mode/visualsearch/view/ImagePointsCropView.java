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
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffXfermode;
import android.graphics.Rect;
import android.graphics.RectF;
import android.graphics.Region;
import android.graphics.drawable.Drawable;
import android.text.TextUtils;
import android.util.AttributeSet;
import android.util.Size;
import android.view.MotionEvent;
import android.view.View;
import android.widget.ImageView;

import com.mediatek.camera.feature.mode.visualsearch.activity.ImageParseActivity;
import com.mediatek.camera.feature.mode.visualsearch.bean.ImageTag;
import com.mediatek.camera.feature.mode.visualsearch.utils.CommonUtils;
import com.visualsearch.RectDataInfo;

import java.util.ArrayList;


@SuppressLint("AppCompatCustomView")
public class ImagePointsCropView extends ImageView {
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
    public boolean drawImageTagRegion = true;
    public boolean isCropView = false;

    private int selectedImageTagIndex = -1;
    private String tagText = "";
    private Float outlineStrokeWidth;
    private OnClickTagListener onClickTagListener;
    private Size size;

    ArrayList<ImageTag> mImageTags = null;
    private int mImageTagCount = 0;

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


    private static float mX_1 = 0;
    private static float mY_1 = 0;
    private static final int STATUS_SINGLE = 1;
    private static final int STATUS_MULTI_START = 2;
    private static final int STATUS_MULTI_TOUCHING = 3;
    private int mStatus = STATUS_SINGLE;
    private static final int EDGE_LT = 1;
    private static final int EDGE_RT = 2;
    private static final int EDGE_LB = 3;
    private static final int EDGE_RB = 4;
    private static final int EDGE_MOVE_IN = 5;
    private static final int EDGE_MOVE_OUT = 6;
    private static final int EDGE_NONE = 7;

    public int currentEdge = EDGE_NONE;

    protected float oriRationWH = 0;

    protected Drawable mDrawable;
    protected CropBoxDrawable mCropBoxDrawable;

    protected Rect mDrawableSrc = new Rect();
    protected Rect mDrawableDst = new Rect();
    protected Rect mDrawableFloat = new Rect();
    protected boolean isFirst = true;
    private boolean isTouchInSquare = true;

    protected Context mContext;

    private int position = -1;

    private int offset = 50;
    private int minWidth;
    private int minHeight;
    int marginEdge = 7;

    @SuppressLint("NewApi")
    private void init(Context context) {
        this.mContext = context;
        try {
            this.setLayerType(LAYER_TYPE_SOFTWARE, null);
        } catch (Exception e) {
            e.printStackTrace();
        }
        mCropBoxDrawable = new CropBoxDrawable(context);
        minWidth = (int) ((CommonUtils.dpToPx(offset, mContext) / 2 - 4.5f) * 2 + 20);
        minHeight = (int) ((CommonUtils.dpToPx(offset, mContext) / 2 - 4.5f) * 2 + 20);
    }

    public void setDrawable(Drawable mDrawable, int position) {
        this.mDrawable = mDrawable;
        this.position = position;
        this.isFirst = true;
    }

    public void setSize(Size size) {
        this.size = size;
    }

    public Size getSize() {
        return size;
    }

    public void setOnClickTagListener(OnClickTagListener onClickTagListener) {
        this.onClickTagListener = onClickTagListener;
    }

    public void setImageTags(ArrayList<ImageTag> imageTags) {
        selectedImageTagIndex = -1;
        drawImageTagRegion = true;
        mImageTags = imageTags;
        mImageTagCount = imageTags.size();
        invalidate();
    }

    public ImagePointsCropView(Context ctx, AttributeSet attrs) {
        super(ctx, attrs);
        outlineStrokeWidth = (float) CommonUtils.dpToPx(3, ctx);
        init(ctx);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {

        if (event.getPointerCount() > 1) {
            if (mStatus == STATUS_SINGLE) {
                mStatus = STATUS_MULTI_START;
            } else if (mStatus == STATUS_MULTI_START) {
                mStatus = STATUS_MULTI_TOUCHING;
            }
        } else {
            if (mStatus == STATUS_MULTI_START
                    || mStatus == STATUS_MULTI_TOUCHING) {
                mX_1 = event.getX();
                mY_1 = event.getY();
            }

            mStatus = STATUS_SINGLE;
        }

        switch (event.getAction()) {
            case MotionEvent.ACTION_DOWN:
                mX_1 = event.getX();
                mY_1 = event.getY();
                currentEdge = getTouch((int) mX_1, (int) mY_1);
                isTouchInSquare = mDrawableFloat.contains((int) event.getX(),
                        (int) event.getY());

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
                break;

            case MotionEvent.ACTION_UP:
                checkBounds();
                break;

            case MotionEvent.ACTION_POINTER_UP:
                currentEdge = EDGE_NONE;
                break;

            case MotionEvent.ACTION_MOVE:
                if (mStatus == STATUS_SINGLE) {
                    int dx = (int) (event.getX() - mX_1);
                    int dy = (int) (event.getY() - mY_1);

                    mX_1 = event.getX();
                    mY_1 = event.getY();

                    Rect rect = new Rect();
                    if (!(dx == 0 && dy == 0)) {
                        switch (currentEdge) {
                            case EDGE_LT:
                                rect.left = mDrawableFloat.left + dx;
                                rect.top = mDrawableFloat.top + dy;
                                rect.right = mDrawableFloat.right;
                                rect.bottom = mDrawableFloat.bottom;
                                if (checkWidthContinueDraw(rect) && checkHeightContinueDraw(rect)) {
                                    rect.left = mDrawableFloat.left + dx;
                                    rect.top = mDrawableFloat.top + dy;
                                    rect.right = mDrawableFloat.right;
                                    rect.bottom = mDrawableFloat.bottom;
                                } else {
                                    if (!checkWidthContinueDraw(rect) && checkHeightContinueDraw(rect)) {
                                        rect.left = mDrawableFloat.left;
                                        rect.top = mDrawableFloat.top + dy;
                                        rect.right = mDrawableFloat.right;
                                        rect.bottom = mDrawableFloat.bottom;
                                    } else if (checkWidthContinueDraw(rect) && !checkHeightContinueDraw(rect)) {
                                        rect.left = mDrawableFloat.left + dx;
                                        rect.top = mDrawableFloat.top;
                                        rect.right = mDrawableFloat.right;
                                        rect.bottom = mDrawableFloat.bottom;
                                    } else {
                                        rect.left = mDrawableFloat.left;
                                        rect.top = mDrawableFloat.top;
                                        rect.right = mDrawableFloat.right;
                                        rect.bottom = mDrawableFloat.bottom;
                                    }
                                }
                                mDrawableFloat.set(rect);
                                break;
                            case EDGE_RT:
                                rect.left = mDrawableFloat.left;
                                rect.top = mDrawableFloat.top + dy;
                                rect.right = mDrawableFloat.right + dx;
                                rect.bottom = mDrawableFloat.bottom;
                                if (checkWidthContinueDraw(rect) && checkHeightContinueDraw(rect)) {
                                    rect.left = mDrawableFloat.left;
                                    rect.top = mDrawableFloat.top + dy;
                                    rect.right = mDrawableFloat.right + dx;
                                    rect.bottom = mDrawableFloat.bottom;
                                } else {
                                    if (!checkWidthContinueDraw(rect) && checkHeightContinueDraw(rect)) {
                                        rect.left = mDrawableFloat.left;
                                        rect.top = mDrawableFloat.top + dy;
                                        rect.right = mDrawableFloat.right;
                                        rect.bottom = mDrawableFloat.bottom;
                                    } else if (checkWidthContinueDraw(rect) && !checkHeightContinueDraw(rect)) {
                                        rect.left = mDrawableFloat.left;
                                        rect.top = mDrawableFloat.top;
                                        rect.right = mDrawableFloat.right + dx;
                                        rect.bottom = mDrawableFloat.bottom;
                                    } else {
                                        rect.left = mDrawableFloat.left;
                                        rect.top = mDrawableFloat.top;
                                        rect.right = mDrawableFloat.right;
                                        rect.bottom = mDrawableFloat.bottom;
                                    }
                                }
                                mDrawableFloat.set(rect);
                                break;
                            case EDGE_LB:
                                rect.left = mDrawableFloat.left + dx;
                                rect.top = mDrawableFloat.top;
                                rect.right = mDrawableFloat.right;
                                rect.bottom = mDrawableFloat.bottom + dy;
                                if (checkWidthContinueDraw(rect) && checkHeightContinueDraw(rect)) {
                                    rect.left = mDrawableFloat.left + dx;
                                    rect.top = mDrawableFloat.top;
                                    rect.right = mDrawableFloat.right;
                                    rect.bottom = mDrawableFloat.bottom + dy;
                                } else {
                                    if (!checkWidthContinueDraw(rect) && checkHeightContinueDraw(rect)) {
                                        rect.left = mDrawableFloat.left;
                                        rect.top = mDrawableFloat.top;
                                        rect.right = mDrawableFloat.right;
                                        rect.bottom = mDrawableFloat.bottom + dy;
                                    } else if (checkWidthContinueDraw(rect) && !checkHeightContinueDraw(rect)) {
                                        rect.left = mDrawableFloat.left + dx;
                                        rect.top = mDrawableFloat.top;
                                        rect.right = mDrawableFloat.right;
                                        rect.bottom = mDrawableFloat.bottom;
                                    } else {
                                        rect.left = mDrawableFloat.left;
                                        rect.top = mDrawableFloat.top;
                                        rect.right = mDrawableFloat.right;
                                        rect.bottom = mDrawableFloat.bottom;
                                    }
                                }
                                mDrawableFloat.set(rect);
                                break;
                            case EDGE_RB:
                                rect.left = mDrawableFloat.left;
                                rect.top = mDrawableFloat.top;
                                rect.right = mDrawableFloat.right + dx;
                                rect.bottom = mDrawableFloat.bottom + dy;
                                if (checkWidthContinueDraw(rect) && checkHeightContinueDraw(rect)) {
                                    rect.left = mDrawableFloat.left;
                                    rect.top = mDrawableFloat.top;
                                    rect.right = mDrawableFloat.right + dx;
                                    rect.bottom = mDrawableFloat.bottom + dy;
                                } else {
                                    if (!checkWidthContinueDraw(rect) && checkHeightContinueDraw(rect)) {
                                        rect.left = mDrawableFloat.left;
                                        rect.top = mDrawableFloat.top;
                                        rect.right = mDrawableFloat.right;
                                        rect.bottom = mDrawableFloat.bottom + dy;
                                    } else if (checkWidthContinueDraw(rect) && !checkHeightContinueDraw(rect)) {
                                        rect.left = mDrawableFloat.left;
                                        rect.top = mDrawableFloat.top;
                                        rect.right = mDrawableFloat.right + dx;
                                        rect.bottom = mDrawableFloat.bottom;
                                    } else {
                                        rect.left = mDrawableFloat.left;
                                        rect.top = mDrawableFloat.top;
                                        rect.right = mDrawableFloat.right;
                                        rect.bottom = mDrawableFloat.bottom;
                                    }
                                }
                                mDrawableFloat.set(rect);
                                break;
                            case EDGE_MOVE_IN:
                                if (isTouchInSquare) {
                                    mDrawableFloat.offset(dx, dy);
                                }
                                break;
                            case EDGE_MOVE_OUT:
                                break;
                        }
                        mDrawableFloat.sort();
                        invalidate();
                    }
                }
                break;
        }
        return true;
    }

    public boolean checkWidthContinueDraw(Rect mRect) {
        int left = mRect.left;
        int right = mRect.right;
        return right - left >= minWidth;
    }

    public boolean checkHeightContinueDraw(Rect mRect) {
        int top = mRect.top;
        int bottom = mRect.bottom;
        return bottom - top >= minHeight;
    }

    public int getTouch(int eventX, int eventY) {
        if (mCropBoxDrawable.getBounds().left <= eventX
                && eventX < (mCropBoxDrawable.getBounds().left + mCropBoxDrawable
                .getBorderWidth())
                && mCropBoxDrawable.getBounds().top <= eventY
                && eventY < (mCropBoxDrawable.getBounds().top + mCropBoxDrawable
                .getBorderHeight())) {
            return EDGE_LT;
        } else if ((mCropBoxDrawable.getBounds().right - mCropBoxDrawable
                .getBorderWidth()) <= eventX
                && eventX < mCropBoxDrawable.getBounds().right
                && mCropBoxDrawable.getBounds().top <= eventY
                && eventY < (mCropBoxDrawable.getBounds().top + mCropBoxDrawable
                .getBorderHeight())) {
            return EDGE_RT;
        } else if (mCropBoxDrawable.getBounds().left <= eventX
                && eventX < (mCropBoxDrawable.getBounds().left + mCropBoxDrawable
                .getBorderWidth())
                && (mCropBoxDrawable.getBounds().bottom - mCropBoxDrawable
                .getBorderHeight()) <= eventY
                && eventY < mCropBoxDrawable.getBounds().bottom) {
            return EDGE_LB;
        } else if ((mCropBoxDrawable.getBounds().right - mCropBoxDrawable
                .getBorderWidth()) <= eventX
                && eventX < mCropBoxDrawable.getBounds().right
                && (mCropBoxDrawable.getBounds().bottom - mCropBoxDrawable
                .getBorderHeight()) <= eventY
                && eventY < mCropBoxDrawable.getBounds().bottom) {
            return EDGE_RB;
        } else if (mCropBoxDrawable.getBounds().contains(eventX, eventY)) {
            return EDGE_MOVE_IN;
        }
        return EDGE_MOVE_OUT;
    }

    public interface OnClickTagListener {
        void clickTag(int position);
    }

    private void drawImageTagRegion(Canvas canvas, int offset, boolean flag) {
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
            if (drawImageTagRegion) {
                // clear ImageTag region
                paint = new Paint();
                paint.setColor(Color.RED);
                paint.setXfermode(new PorterDuffXfermode(PorterDuff.Mode.CLEAR));

                Paint outlinePaint = new Paint();
                outlinePaint.setStyle(Paint.Style.STROKE);
                outlinePaint.setStrokeWidth(outlineStrokeWidth);
                outlinePaint.setStrokeCap(Paint.Cap.ROUND);
                if (!flag && mImageTagCount > 0 && mImageTags != null && mImageTags.size() > 0) {
                    for (int i = 0; i < mImageTagCount; i++) {
                        ImageTag obj = mImageTags.get(i);
                        RectF rect1 = getRegionRect(obj, getWidth(), getHeight());
                        float x = (rect1.left + rect1.right) / 2;
                        float y = (rect1.top + rect1.bottom) / 2;
                        drawOutCircle(canvas, x, y);
                        if (selectedImageTagIndex == i && !isCropView) {
                            drawInSelectCircle(canvas, x, y);
                            drawSelectText(canvas, x, y);
                        } else {
                            drawInCircle(canvas, x, y);
                        }
                    }
                } else {
                    for (int i = 0; i < mImageTagCount; i++) {
                        if (i != position && mImageTags != null && mImageTags.size() > 0) {
                            ImageTag obj = mImageTags.get(i);
                            RectF rect1 = getRegionRect(obj, getWidth(), getHeight());
                            float x = (rect1.left + rect1.right) / 2;
                            float y = (rect1.top + rect1.bottom) / 2;
                            drawOutCircle(canvas, x, y);
                            if (selectedImageTagIndex == i && !isCropView) {
                                drawInSelectCircle(canvas, x, y);
                                drawSelectText(canvas, x, y);
                            } else {
                                drawInCircle(canvas, x, y);
                            }
                        }
                    }
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
            drawImageTagRegion(canvas, actualOffset, ImageParseActivity.SHOW_CROP_VIEW);

        }

        if (mDrawable == null) {
            return;
        }

        if (mDrawable.getIntrinsicWidth() == 0
                || mDrawable.getIntrinsicHeight() == 0) {
            return;
        }

        configureBounds();
        mDrawable.draw(canvas);

        if (ImageParseActivity.SHOW_CROP_VIEW) {
            canvas.save();
            canvas.clipRect(mDrawableFloat, Region.Op.DIFFERENCE);
            canvas.drawColor(Color.parseColor("#40000000"));
            canvas.restore();
            mCropBoxDrawable.draw(canvas);
        }
    }

    protected void configureBounds() {
        if (isFirst && mImageTags != null && mImageTags.size() > 0) {
            oriRationWH = ((float) mDrawable.getIntrinsicWidth())
                    / ((float) mDrawable.getIntrinsicHeight());

            final float scale = mContext.getResources().getDisplayMetrics().density;
            int w = Math.min(getWidth(), (int) (mDrawable.getIntrinsicWidth()
                    * scale + 0.5f));
            int h = (int) (w / oriRationWH);

            int left = (getWidth() - w) / 2;
            int top = (getHeight() - h) / 2;
            int right = left + w;
            int bottom = top + h;

            mDrawableSrc.set(left, top, right, bottom);
            mDrawableDst.set(mDrawableSrc);

            int floatLeft = (int) (getWidth() * (mImageTags.get(position).getLeft()));
            int floatTop = (int) (getHeight() * mImageTags.get(position).getTop());
            int floatRight = (int) (getWidth() * (mImageTags.get(position).getRight()));
            int floatBottom = (int) (getHeight() * (mImageTags.get(position).getBottom()));
            if (floatLeft < 0) {
                floatLeft = 0;
            }
            if (floatTop < 0) {
                floatTop = 0;
            }
            if (floatRight > getWidth()) {
                floatRight = getWidth();
            }
            if (floatBottom > getHeight()) {
                floatBottom = getHeight();
            }

            if (floatRight == floatLeft || floatBottom == floatTop) {
                floatLeft = getWidth() / 6;
                floatTop = getHeight() / 3;
                floatRight = getWidth() / 6 * 5;
                floatBottom = getHeight() / 3 * 2;
            }

            if (floatRight - floatLeft < minWidth) {
                floatRight = floatLeft + minWidth;
            }
            if (floatBottom - floatTop < minHeight) {
                floatBottom = floatTop + minHeight;
            }

            mDrawableFloat.set(floatLeft, floatTop, floatRight, floatBottom);

            isFirst = false;
        }

        mDrawable.setBounds(mDrawableDst);
        mCropBoxDrawable.setBounds(mDrawableFloat);
    }


    //Get the labeled rectangle
    public RectF getRegionRect(ImageTag tag, int width, int height) {
        RectF rect = new RectF();
        rect.left = (float) (width * tag.getLeft());
        rect.right = (float) (width * tag.getRight());
        rect.top = (float) (height * tag.getTop());
        rect.bottom = (float) (height * tag.getBottom());
        if (rect.right - rect.left < minWidth) {
            rect.right =  rect.left + minWidth;
        }
        if (rect.bottom - rect.top < minHeight) {
            rect.bottom = rect.top + minHeight;
        }
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
        if (rectSmall.right - rectSmall.left < minWidth) {
            rectSmall.right =  rectSmall.left + minWidth;
        }
        if (rectSmall.bottom - rectSmall.top < minHeight) {
            rectSmall.bottom = rectSmall.top + minHeight;
        }
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


    // check crop's rect is out of screen
    protected void checkBounds() {
        int newLeft = mDrawableFloat.left;
        int newTop = mDrawableFloat.top;
        boolean isChange = false;
        if (mDrawableFloat.left < mDrawableDst.left) {
            newLeft = marginEdge + mDrawableDst.left;
            isChange = true;
        }
        if (mDrawableFloat.top < mDrawableDst.top) {
            newTop = mDrawableDst.top + marginEdge;
            isChange = true;
        }
        if (mDrawableFloat.right > mDrawableDst.right) {
            newLeft = mDrawableDst.right - mDrawableFloat.width() - marginEdge;
            isChange = true;
        }
        if (mDrawableFloat.bottom > mDrawableDst.bottom) {
            newTop = mDrawableDst.bottom - mDrawableFloat.height() - marginEdge;
            isChange = true;
        }
        mDrawableFloat.offsetTo(newLeft, newTop);
        if (isChange) {
            if (mDrawableFloat.right - mDrawableFloat.left >= mDrawableDst.right - mDrawableDst.left) {
                if (mDrawableFloat.left <= marginEdge) {
                    mDrawableFloat.left = marginEdge;
                    mDrawableFloat.right = mDrawableDst.right - marginEdge;
                }
            }
            if (mDrawableFloat.bottom - mDrawableFloat.top >= mDrawableDst.bottom - mDrawableDst.top) {
                if (mDrawableFloat.top <= marginEdge) {
                    mDrawableFloat.top = marginEdge;
                    mDrawableFloat.bottom = mDrawableDst.bottom - marginEdge;
                }
            }
            mDrawableFloat.set(mDrawableFloat);
            invalidate();
        }
    }

    /**
     * get crop's rect
     */
    public RectDataInfo getCropImageRect() {
        RectDataInfo mRectDataInfo = new RectDataInfo();
        float[] cropImageRect = new float[4];
        int left = mDrawableFloat.left;
        int top = mDrawableFloat.top;
        int right = mDrawableFloat.right;
        int bottom = mDrawableFloat.bottom;
        if (left < 0) {
            left = 0;
        }
        if (top < 0) {
            top = 0;
        }
        int width = mDrawableDst.width();
        int height = mDrawableDst.height();
        if (right > width) {
            right = width;
        }
        if (bottom > height) {
            bottom = height;
        }
        if (right - left < minWidth) {
            right =  left + minWidth;
        }
        if (bottom - top < minHeight) {
            bottom = top + minHeight;
        }
        cropImageRect[0] = left;
        cropImageRect[1] = top;
        cropImageRect[2] = right;
        cropImageRect[3] = bottom;
        mRectDataInfo.setCropRect(cropImageRect);
        return mRectDataInfo;
    }

    public Bitmap convertViewToBitmap(View view) {
        if (view == null || view.getWidth() <= 0 || view.getHeight() <= 0) {
            return null;
        }
        Bitmap bitmap = Bitmap.createBitmap(view.getWidth(), view.getHeight(),
                Bitmap.Config.ARGB_8888);
        Paint paint = new Paint();
        paint.setColor(Color.WHITE);
        Canvas canvas = new Canvas(bitmap);
        canvas.drawRect(0, 0, bitmap.getWidth(), bitmap.getHeight(), paint);
        canvas.drawBitmap(bitmap, 0, 0, paint);
        view.draw(canvas);
        return bitmap;
    }

}
