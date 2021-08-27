#  Copyright (C) 2015 The Android Open Source Project
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := libimage_detect
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := jniLibs/arm64-v8a/$(LOCAL_MODULE).so
LOCAL_MODULE_STEM := $(LOCAL_MODULE)
LOCAL_MODULE_SUFFIX := $(suffix $(LOCAL_SRC_FILES))
LOCAL_SHARED_LIBRARIES := libandroid liblog libneuralnetworks
LOCAL_MULTILIB := 64
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_PRIVATE_PLATFORM_APIS := true
LOCAL_PRODUCT_MODULE := true

include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE := libimage_detect
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := jniLibs/armeabi-v7a/$(LOCAL_MODULE).so
LOCAL_MODULE_STEM := $(LOCAL_MODULE)
LOCAL_MODULE_SUFFIX := $(suffix $(LOCAL_SRC_FILES))
LOCAL_SHARED_LIBRARIES := libandroid liblog libneuralnetworks
LOCAL_MULTILIB := 32
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_PRIVATE_PLATFORM_APIS := true
LOCAL_PRODUCT_MODULE := true

include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE := libcipher_utils
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := jniLibs/arm64-v8a/$(LOCAL_MODULE).so
LOCAL_MODULE_STEM := $(LOCAL_MODULE)
LOCAL_MODULE_SUFFIX := $(suffix $(LOCAL_SRC_FILES))
LOCAL_SHARED_LIBRARIES := libcrypto libssl liblog
LOCAL_MULTILIB := 64
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_PRIVATE_PLATFORM_APIS := true
LOCAL_PRODUCT_MODULE := true

include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE := libcipher_utils
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := jniLibs/armeabi-v7a/$(LOCAL_MODULE).so
LOCAL_MODULE_STEM := $(LOCAL_MODULE)
LOCAL_MODULE_SUFFIX := $(suffix $(LOCAL_SRC_FILES))
LOCAL_SHARED_LIBRARIES := libcrypto libssl liblog
LOCAL_MULTILIB := 32
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_PRIVATE_PLATFORM_APIS := true
LOCAL_PRODUCT_MODULE := true

include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE := libtensorflow-lite
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := jniLibs/arm64-v8a/$(LOCAL_MODULE).so
LOCAL_MODULE_STEM := $(LOCAL_MODULE)
LOCAL_MODULE_SUFFIX := $(suffix $(LOCAL_SRC_FILES))
LOCAL_SHARED_LIBRARIES := libcrypto libssl liblog
LOCAL_MULTILIB := 64
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_PRIVATE_PLATFORM_APIS := true
LOCAL_PRODUCT_MODULE := true

include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE := libtensorflow-lite
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := jniLibs/armeabi-v7a/$(LOCAL_MODULE).so
LOCAL_MODULE_STEM := $(LOCAL_MODULE)
LOCAL_MODULE_SUFFIX := $(suffix $(LOCAL_SRC_FILES))
LOCAL_MULTILIB := 32
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_PRIVATE_PLATFORM_APIS := true
LOCAL_PRODUCT_MODULE := true

include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE:= libvisual_search_headers
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)/include
include $(BUILD_HEADER_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libnn_sample
LOCAL_MODULE_TAGS := optional
LOCAL_HEADER_LIBRARIES := libvisual_search_headers

LOCAL_SHARED_LIBRARIES := libimage_detect libcipher_utils libtensorflow-lite

LOCAL_LDLIBS :=-llog -landroid -lneuralnetworks

LOCAL_SRC_FILES := \
    NativeImageDetect.cpp

LOCAL_PROPRIETARY_MODULE := false
LOCAL_MODULE_OWNER := mtk
LOCAL_NDK_STL_VARIANT := c++_static
LOCAL_MULTILIB := 64

LOCAL_CFLAGS := -Wall
LOCAL_CFLAGS += -Wno-return-type-c-linkage
LOCAL_CFLAGS += -Wno-unused-const-variable -Wno-unused-variable -Wno-unused-parameter -Wignored-qualifiers
LOCAL_CFLAGS += -fPIE -fPIC -mfloat-abi=softfp -mfpu=neon


LOCAL_PRIVATE_PLATFORM_APIS := true
LOCAL_PRODUCT_MODULE := true
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := libnn_sample
LOCAL_MODULE_TAGS := optional
LOCAL_HEADER_LIBRARIES := libvisual_search_headers

LOCAL_SHARED_LIBRARIES := libimage_detect libcipher_utils libtensorflow-lite

LOCAL_LDLIBS :=-llog -landroid -lneuralnetworks

LOCAL_SRC_FILES := \
    NativeImageDetect.cpp

LOCAL_PROPRIETARY_MODULE := false
LOCAL_MODULE_OWNER := mtk
LOCAL_NDK_STL_VARIANT := c++_static stlport_static
LOCAL_MULTILIB := 32

LOCAL_CFLAGS += -Wno-unused-const-variable -Wno-unused-variable -Wno-unused-parameter -Wignored-qualifiers
LOCAL_CFLAGS += -fPIE -fPIC -mfloat-abi=softfp -mfpu=neon

LOCAL_PRIVATE_PLATFORM_APIS := true
LOCAL_PRODUCT_MODULE := true
include $(BUILD_SHARED_LIBRARY)
