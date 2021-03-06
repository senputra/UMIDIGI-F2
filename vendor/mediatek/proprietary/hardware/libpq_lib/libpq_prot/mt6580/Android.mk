LOCAL_PATH := $(call my-dir)

ifeq (,$(wildcard vendor/mediatek/proprietary/hardware/libpq))
include $(CLEAR_VARS)
LOCAL_MODULE := libpq_prot
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_OWNER := mtk
LOCAL_MODULE_SUFFIX := .so
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR)/lib
LOCAL_SHARED_LIBRARIES := liblog libc++ libc libm libdl
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)/include
LOCAL_MULTILIB := 32
LOCAL_SRC_FILES_32 := arm/libpq_prot.so
include $(BUILD_PREBUILT)
endif
