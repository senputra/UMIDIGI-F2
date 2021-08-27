LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES := $(call all-subdir-java-files)

LOCAL_RENDERSCRIPT_TARGET_API := 18
LOCAL_RENDERSCRIPT_COMPATIBILITY := 18

aidl_files:= $(call all-Iaidl-files-under, aidl)

LOCAL_SRC_FILES := $(call all-java-files-under, src)
LOCAL_SRC_FILES += $(call all-java-files-under, ../../../common/src)
LOCAL_SRC_FILES += $(aidl_files)
LOCAL_SRC_FILES += ../visualsearch/aidl/com/visualsearch/DataInterface.aidl
LOCAL_SRC_FILES += ../visualsearch/aidl/com/visualsearch/DataInfo.aidl

LOCAL_AIDL_INCLUDES := $(LOCAL_PATH)/../visualsearch/aidl \

LOCAL_ASSET_DIR += $(LOCAL_PATH)/assets

LOCAL_JNI_SHARED_LIBRARIES := libnn_sample

LOCAL_MODULE_TAGS := optional
LOCAL_CERTIFICATE := platform

LOCAL_PROGUARD_ENABLED := disabled
LOCAL_STATIC_JAVA_LIBRARIES := android-support-v4
LOCAL_STATIC_JAVA_LIBRARIES += android-support-v7-appcompat
LOCAL_STATIC_JAVA_LIBRARIES += android-support-v7-gridlayout
LOCAL_STATIC_JAVA_LIBRARIES += android-support-v13

LOCAL_RESOURCE_DIR := $(LOCAL_PATH)/res \

LOCAL_RESOURCE_DIR += prebuilts/sdk/current/support/v7/appcompat/res
LOCAL_RESOURCE_DIR += prebuilts/sdk/current/support/v7/gridlayout/res

LOCAL_AAPT_FLAGS += --extra-packages android.support.v7.appcompat:android.support.v7.gridlayout

LOCAL_MIN_SDK_VERSION := 21

LOCAL_PACKAGE_NAME := VisualSearch
LOCAL_PRIVATE_PLATFORM_APIS := true
LOCAL_PRODUCT_MODULE := true
LOCAL_USE_AAPT2 := true

LOCAL_PROGUARD_ENABLED := full obfuscation
LOCAL_PROGUARD_FLAG_FILES := proguard.flags
LOCAL_DEX_PREOPT := false

include $(BUILD_PACKAGE)

include $(call all-makefiles-under,$(LOCAL_PATH))
