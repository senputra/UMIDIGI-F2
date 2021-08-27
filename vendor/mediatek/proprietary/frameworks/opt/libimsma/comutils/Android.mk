############################################################

build_vilte =
ifeq ($(strip $(MSSI_MTK_VILTE_SUPPORT)),yes)
    build_vilte = yes
endif

ifeq ($(strip $(MSSI_MTK_VIWIFI_SUPPORT)),yes)
    build_vilte = yes
endif

ifdef build_vilte

############################################################


LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
MY_IMS_PATH :=  $(TOP)/$(MTK_ROOT)/frameworks/opt/libimsma
MY_OMX_PATH :=  $(TOP)/$(MTK_ROOT)/frameworks/native/include/media/openmax

LOCAL_C_INCLUDES:= \
        $(MY_OMX_PATH) \
        $(TOP)/frameworks/native/include/media/openmax \
        $(TOP)/frameworks/av/media/libstagefright \
        $(TOP)/frameworks/av/include/media/libstagefright/foundation

LOCAL_SRC_FILES := \
        comutils.cpp

ifeq ($(TARGET_ARCH),arm)
    LOCAL_CFLAGS += -Wno-psabi
endif

LOCAL_CFLAGS += -Werror -Wno-error=deprecated-declarations -Wall

LOCAL_SHARED_LIBRARIES:= \
        libcutils\
        libstagefright_foundation       \
        libutils  \
        libstagefright\
        libmedia\
        liblog \
        libhidlbase


LOCAL_MODULE:= libcomutils
#LOCAL_PROPRIETARY_MODULE := true
#LOCAL_MODULE_OWNER := mtk

LOCAL_MODULE_TAGS:= optional

include $(MTK_SHARED_LIBRARY)

endif

