LOCAL_PATH := $(call my-dir)

ifeq (,$(wildcard vendor/mediatek/proprietary/trustzone/common/hal/secure))
include $(CLEAR_VARS)
LOCAL_MODULE := VP9SecureVdecDriver_API
LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_MODULE_SUFFIX := .lib
LOCAL_UNINSTALLABLE_MODULE := true
LOCAL_MULTILIB := 32
LOCAL_SRC_FILES_32 := arm/VP9SecureVdecDriver_API.lib
include $(BUILD_PREBUILT)
endif
