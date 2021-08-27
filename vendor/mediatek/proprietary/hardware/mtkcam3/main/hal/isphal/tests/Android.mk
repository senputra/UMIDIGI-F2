LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

-include $(TOP)/$(MTK_PATH_SOURCE)/hardware/mtkcam/mtkcam.mk

# isphal_test - Unit tests of ISP HAL interface operations
LOCAL_MODULE := isphal_test
LOCAL_MODULE_TAGS := tests
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk

LOCAL_ADDITIONAL_DEPENDENCIES := $(LOCAL_PATH)/Android.mk

MTK_PATH_CAM := $(MTK_PATH_SOURCE)/hardware/mtkcam
MTK_PATH_CAM3 := $(MTK_PATH_SOURCE)/hardware/mtkcam3

LOCAL_SRC_FILES := main.cpp

LOCAL_CFLAGS := -DLOG_TAG=\"$(LOCAL_MODULE)\"
#LOCAL_CFLAGS += -DENABLE_JPEG_BUFFER_TEST

LOCAL_HEADER_LIBRARIES := libhardware_headers \
	libmtkcam_headers \
	libmtkcam3_headers

LOCAL_STATIC_LIBRARIES := \
	libjsoncpp \
	libgrallocusage

LOCAL_SHARED_LIBRARIES := \
	liblog \
	libsync \
	libutils \
	libcutils \
	libhidlbase \
	libcamera_metadata \
	libmtkcam_stdutils \
	libmtkisp_metadata \
	vendor.mediatek.hardware.camera.isphal@1.0 \
	android.hardware.graphics.allocator@2.0 \
	android.hardware.graphics.mapper@2.0 \
	android.hardware.camera.provider@2.4

include $(BUILD_NATIVE_TEST)
