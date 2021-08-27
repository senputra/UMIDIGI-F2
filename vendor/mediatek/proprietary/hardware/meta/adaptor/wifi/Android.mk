ifeq ($(MTK_WLAN_SUPPORT), yes)

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES := meta_wifi.c iwlibstub.c

$(info "TARGET_BOARD_PLATFORM is $(TARGET_BOARD_PLATFORM)")

ifeq ($(MTK_TB_WIFI_3G_MODE), WIFI_ONLY)
ifneq ($(filter mt6765 mt6771 mt6761, $(TARGET_BOARD_PLATFORM)),)
ifneq ($(wildcard $(LOCAL_PATH)/meta_afc/platform/$(TARGET_BOARD_PLATFORM)),)
	LOCAL_CFLAGS += -DSUPPORT_AFC_C0C1
	LOCAL_SRC_FILES += meta_afc/meta_afc.c
	LOCAL_SRC_FILES += meta_c0c1/meta_c0c1.c
	LOCAL_SRC_FILES += meta_utils/meta_cal_utils.c
	LOCAL_SRC_FILES += meta_afc/platform/$(TARGET_BOARD_PLATFORM)/$(TARGET_BOARD_PLATFORM)_afc.c
	LOCAL_SRC_FILES += meta_c0c1/platform/$(TARGET_BOARD_PLATFORM)/$(TARGET_BOARD_PLATFORM)_c0c1.c
$(info "Included WiFi only Co-TMS files")
endif
endif
endif

LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)
LOCAL_C_INCLUDES := $(MTK_PATH_SOURCE)/hardware/meta/common/inc \
	$(MTK_PATH_SOURCE)/external/nvram/libnvram \

LOCAL_MODULE := libmeta_wifi
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk
LOCAL_SHARED_LIBRARIES := libcutils libnetutils libc liblog
LOCAL_STATIC_LIBRARIES := libft
LOCAL_PRELINK_MODULE := false


include $(MTK_STATIC_LIBRARY)

###############################################################################
# SELF TEST
###############################################################################
BUILD_SELF_TEST := false
ifeq ($(BUILD_SELF_TEST), true)
include $(CLEAR_VARS)
LOCAL_SRC_FILES := meta_wifi_test.c
LOCAL_C_INCLUDES := $(MTK_PATH_SOURCE)/hardware/meta/common/inc
LOCAL_MODULE := meta_wifi_test
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk
LOCAL_ALLOW_UNDEFINED_SYMBOLS := true
LOCAL_SHARED_LIBRARIES := libc libnetutils libcutils liblog libnvram
LOCAL_STATIC_LIBRARIES := libft libmeta_wifi
LOCAL_UNSTRIPPED_PATH := $(TARGET_ROOT_OUT_SBIN_UNSTRIPPED)
include $(MTK_EXECUTABLE)
endif

endif
