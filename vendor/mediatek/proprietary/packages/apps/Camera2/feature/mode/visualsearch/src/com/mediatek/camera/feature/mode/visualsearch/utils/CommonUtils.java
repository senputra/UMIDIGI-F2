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

package com.mediatek.camera.feature.mode.visualsearch.utils;

import android.content.ActivityNotFoundException;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.Matrix;
import android.net.Uri;
import android.os.Build;
import android.util.DisplayMetrics;
import android.util.Size;
import android.view.OrientationEventListener;
import android.widget.RelativeLayout;
import android.widget.ImageView;
import android.widget.Toast;

import com.visualsearch.RectDataInfo;
import com.mediatek.camera.feature.mode.visualsearch.bean.DataHolder;
import com.mediatek.camera.feature.mode.visualsearch.bean.ImageTag;

import java.io.ByteArrayOutputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;

public class CommonUtils {

    public static void toLauncherApp(Context context, Bitmap bitmap, ArrayList<RectDataInfo> rectList) {
        if (bitmap != null && rectList.size() > 0) {
            try {
                DataHolder.getInstance().setSelectedImageBytes(CommonUtils.bitmapToByte(bitmap));
                DataHolder.getInstance().setRectList(rectList);
                Intent intent = new Intent();
                intent.setData(Uri.parse("wakeup://com.visualsearch/objectinfo"));
                context.startActivity(intent);
            } catch (ActivityNotFoundException e) {
                Toast.makeText(context, "ActivityNotFound", Toast.LENGTH_SHORT).show();
                e.printStackTrace();
            } catch (Exception e) {
                Toast.makeText(context, "cannot find products", Toast.LENGTH_SHORT).show();
            }
        } else {
            Toast.makeText(context, "bitmap is null rectList size = " + rectList.size(), Toast.LENGTH_SHORT).show();
        }
    }

    /**
     * click confirmView v get imageTags cropView
     */
    public static ArrayList<RectDataInfo> getRectList(ArrayList<ImageTag> imageTags, RectDataInfo info, float ivPreViewWidth, float ivPreViewHeight) {
        ArrayList<RectDataInfo> rectList = new ArrayList<>();
        float[] mRect = info.getCropRect();
        float left = mRect[0] / ivPreViewWidth;
        float top = mRect[1] / ivPreViewHeight;
        float right = mRect[2] / ivPreViewWidth;
        float bottom = mRect[3] / ivPreViewHeight;
        mRect[0] = left;
        mRect[1] = top;
        mRect[2] = right;
        mRect[3] = bottom;
        if (mRect[0] == mRect[2] || mRect[1] == mRect[3]) {
            mRect[0] = 0;
            mRect[1] = 0;
            mRect[2] = 1;
            mRect[3] = 1;
        }
        info.setCropRect(mRect);
        rectList.add(info);
        if (imageTags != null && imageTags.size() > 0) {
            for (int i = 0; i < imageTags.size(); i++) {
                ImageTag imageTag = imageTags.get(i);
                float[] rect = new float[4];
                rect[0] = (float) imageTag.getLeft();
                rect[1] = (float) imageTag.getTop();
                rect[2] = (float) imageTag.getRight();
                rect[3] = (float) imageTag.getBottom();
                if (rect[0] == rect[2] || rect[1] == rect[3]) {
                    rect[0] = 0;
                    rect[1] = 0;
                    rect[2] = 1;
                    rect[3] = 1;
                }
                if (rect[0] < 0) {
                    rect[0] = 0;
                }
                if (rect[1] < 0) {
                    rect[1] = 0;
                }
                if (rect[2] > 1) {
                    rect[2] = 1;
                }
                if (rect[3] > 1) {
                    rect[3] = 1;
                }
                RectDataInfo rectDataInfo = new RectDataInfo();
                rectDataInfo.setCropRect(rect);
                rectList.add(rectDataInfo);
            }
        }
        return rectList;
    }

    /**
     * click imageView's tag,sort tagList
     */
    public static ArrayList<RectDataInfo> getRectListByClickTag(ArrayList<ImageTag> tagList, int position) {
        if (tagList != null && tagList.size() > 1) {
            LinkedList linkedList = new LinkedList(tagList);
            Collections.swap(linkedList, 0, position);
            tagList = new ArrayList(linkedList);
        }
        ArrayList<RectDataInfo> rectList = new ArrayList<>();
        if (tagList != null && tagList.size() > 0) {
            for (int i = 0; i < tagList.size(); i++) {
                ImageTag imageTag = tagList.get(i);

                float[] rect = new float[4];
                rect[0] = (float) imageTag.getLeft();
                rect[1] = (float) imageTag.getTop();
                rect[2] = (float) imageTag.getRight();
                rect[3] = (float) imageTag.getBottom();
                if (rect[0] == rect[2] || rect[1] == rect[3]) {
                    rect[0] = 0;
                    rect[1] = 0;
                    rect[2] = 1;
                    rect[3] = 1;
                }
                if (rect[0] < 0) {
                    rect[0] = 0;
                }
                if (rect[1] < 0) {
                    rect[1] = 0;
                }
                if (rect[2] > 1) {
                    rect[2] = 1;
                }
                if (rect[3] > 1) {
                    rect[3] = 1;
                }
                RectDataInfo rectDataInfo = new RectDataInfo();
                rectDataInfo.setCropRect(rect);
                rectList.add(rectDataInfo);
            }
        }
        return rectList;
    }

    public static int dpToPx(int dp, Context ctx) {
        DisplayMetrics metrics = ctx.getResources().getDisplayMetrics();
        return (dp * metrics.densityDpi / DisplayMetrics.DENSITY_DEFAULT);
    }

    public static Bitmap rotateCaptureBitmap(Bitmap bitmap, int degree) {
        int w = bitmap.getWidth();
        int h = bitmap.getHeight();
        Matrix mtx = new Matrix();
        if (degree == 270) {
            degree = 180;
        } else {
            degree = 0;
        }
        mtx.postRotate(degree);
        return Bitmap.createBitmap(bitmap, 0, 0, w, h, mtx, true);
    }

    public static Bitmap rotatePreviewBitmap(Bitmap bitmap, int degree) {
        int w = bitmap.getWidth();
        int h = bitmap.getHeight();
        Matrix mtx = new Matrix();
        mtx.postRotate(degree);
        return Bitmap.createBitmap(bitmap, 0, 0, w, h, mtx, true);
    }

    public static int getScreenHeight(Context context) {
        return context.getResources().getDisplayMetrics().heightPixels;
    }

    public static int getScreenWidth(Context context) {
        return context.getResources().getDisplayMetrics().widthPixels;
    }

    public static byte[] bitmapToByte(Bitmap bitmap) {
        ByteArrayOutputStream bao = new ByteArrayOutputStream();
        bitmap.compress(Bitmap.CompressFormat.JPEG, 100, bao);
        return bao.toByteArray();
    }

    public static void setImageWH(Context context, int flag, ImageView imageView, int w, int h) {
        if (context != null && imageView != null && w > 0 && h > 0) {
            Size size = getImageScale(context, flag, w, h);
            if (size != null) {
                RelativeLayout.LayoutParams lp = new RelativeLayout.LayoutParams(size.getWidth(), size.getHeight());
                lp.addRule(RelativeLayout.CENTER_HORIZONTAL, RelativeLayout.TRUE);
                lp.addRule(RelativeLayout.CENTER_VERTICAL, RelativeLayout.TRUE);
                //ViewGroup.LayoutParams lp = imageView.getLayoutParams();
                lp.width = size.getWidth();
                lp.height = size.getHeight();
                imageView.setLayoutParams(lp);
            }
        }
    }

    private static Size getImageScale(Context context, int flag, int bmpWidth, int bmpHeight) {
        if (context == null || bmpWidth <= 0 || bmpHeight <= 0) {
            Toast.makeText(context, "The picture scale does not match", Toast.LENGTH_SHORT).show();
            return null;
        }
        int screenWidth = CommonUtils.getScreenWidth(context);
        int screenHeight = CommonUtils.getScreenHeight(context);
        int targetWidth;
        int targetHeight;
        float rotBmpScale = (float) bmpWidth / bmpHeight;
        float screenScale = (float) screenWidth / screenHeight;

        if (rotBmpScale != screenScale) {
            targetWidth = Math.min(screenWidth, bmpWidth);
            targetHeight = (int) (targetWidth / rotBmpScale);
        } else {
            targetWidth = screenWidth;
            targetHeight = screenHeight;
        }
        if (bmpWidth >= bmpHeight) {
            return new Size(targetWidth, bmpHeight * targetWidth / bmpWidth);
        } else {
            return new Size(bmpWidth * targetHeight / bmpHeight, targetHeight);
        }
    }

}
