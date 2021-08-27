/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2019. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#pragma once

#include <cstdio>
#include <memory>
#include <vector>

#include "NeuroPilotTFLiteShim.h"
#include "Recognition.h"

#define DETECT_INPUT_MEAN (127.5f)
#define DETECT_INPUT_STD (127.5f)
#define DETECT_THRESHOLD (0.5f)
#define DETECT_NUMBER_OF_DETECTIONS 10

#define OUTPUT_TENSOR_DETECT_BOXES 0
#define OUTPUT_TENSOR_DETECT_CLASSES 1
#define OUTPUT_TENSOR_DETECT_SCORES 2
#define OUTPUT_TENSOR_NUM_DETECTIONS 3

#define OUTPUT_TENSOR_MAX_NUM 5

namespace detection {

    enum class ModelDataType {
        TYPE_UNKNOWN = 0,
        TYPE_FLOAT_32,
        TYPE_UINT8,
    };

    class DetectionEngine {
    public:
        explicit DetectionEngine(const std::string &model_path, const std::string &label_path, int detectCount,
                                 bool allow_fp16 = true);

        DetectionEngine(const char *model_buffer, size_t buffer_size,
                        std::vector<std::string> &labels, int detectCount,
                        bool allow_fp16 = true);

        bool Inference(const void *buffer, const std::size_t buffer_size,
                       std::vector<recognition::Recognition> &results);

        ~DetectionEngine();

        void uninit();

        void SetThreshold(float threshold) { mThreshold = threshold; }

        void SetDetectCount(int detectCount) { mDetectCount = detectCount; }

        float GetThreshold() const { return mThreshold; }

        ModelDataType GetModelInputDataType();

        ModelDataType GetModelOutputDataType(int index);

        void SetVerboseLog(bool enable) { mVerboseLog = enable; }

        void SetLoopCount(int count) { mLoopCount = count; }

    private:
        bool ReadLabels(const std::string &label_path);

        void InitBuffers();

        template<class T>
        void GetRecognitions(T *boxes, T *classes, T *scores, T *detections,
                             std::vector<recognition::Recognition> *recognitions);

    private:
        ANeuralNetworksTFLite *mTFLite = nullptr;
        ANeuralNetworksTFLiteOptions *mOptions = nullptr;
        const char *mCacheDir = nullptr;
        std::vector<std::string> mLabels;
        std::vector<recognition::Recognition> mRecognitions;
        size_t mInputTensorByteSize = 0;
        void *mOutputBoxesBuffer = nullptr;
        size_t mOutputBoxesByteSize = 0;
        void *mOutputClassesBuffer = nullptr;
        size_t mOutputClassesByteSize = 0;
        void *mOutputScoresBuffer = nullptr;
        size_t mOutputScoresByteSize = 0;
        void *mOutputDetectionsBuffer = nullptr;
        size_t mOutputDetectionsByteSize = 0;
        float mThreshold = DETECT_THRESHOLD;
        size_t mNumberOfResults = DETECT_NUMBER_OF_DETECTIONS;
        bool mVerboseLog = false;
        int mLoopCount = 1;
        int mInputHeight = 0;
        int mDetectCount = OUTPUT_TENSOR_MAX_NUM;
    };

}  // namespace detection
