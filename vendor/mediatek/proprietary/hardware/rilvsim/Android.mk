# Copyright Statement:
#
# This software/firmware and related documentation ("MediaTek Software") are
# protected under relevant copyright laws. The information contained herein
# is confidential and proprietary to MediaTek Inc. and/or its licensors.
# Without the prior written permission of MediaTek inc. and/or its licensors,
# any reproduction, modification, use or disclosure of MediaTek Software,
# and information contained herein, in whole or in part, shall be strictly prohibited.

# MediaTek Inc. (C) 2010. All rights reserved.
#
# BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
# THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
# CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
# SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
# STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
# CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
# The following software/firmware and/or related documentation ("MediaTek Software")
# have been modified by MediaTek Inc. All revisions are subject to any receiver's
# applicable license agreements with MediaTek Inc.


LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

ifneq ($(MTK_RIL_MODE), c6m_1rild)
LOCAL_SRC_FILES:= \
        mtk_ril_vsim.c \

LOCAL_SHARED_LIBRARIES := libmtkrilutils librilutils libssl libcrypto liblog libcutils

LOCAL_CFLAGS := -D_GNU_SOURCE -DRIL_SHLIB -DMTK_RIL -D__CCMNI_SUPPORT__
ifeq ($(MTK_MUX_CHANNEL), 64)
    LOCAL_CFLAGS += -DMTK_MUX_CHANNEL_64
endif

else

LOCAL_SRC_FILES:= \
        fusion/RmcVsimRequestHandler.cpp \
        fusion/RmcVsimUrcHandler.cpp

LOCAL_SHARED_LIBRARIES := libutils librilfusion libmtkrilutils librilutils libmtkrillog libssl \
        libcrypto liblog
LOCAL_CFLAGS := -D_GNU_SOURCE -DRIL_SHLIB -DMTK_RIL -D__CCMNI_SUPPORT__
LOCAL_CFLAGS += -DMTK_IMS_CHANNEL_SUPPORT
LOCAL_CFLAGS += -DMTK_USE_HIDL
LOCAL_CFLAGS += -DMTK_MUX_CHANNEL_64
endif



ifneq ($(MTK_NUM_MODEM_PROTOCOL),1)
    LOCAL_CFLAGS += -DANDROID_MULTI_SIM
endif

ifeq ($(MTK_NUM_MODEM_PROTOCOL), 2)
    LOCAL_CFLAGS += -DANDROID_SIM_COUNT_2
endif

ifeq ($(MTK_NUM_MODEM_PROTOCOL), 3)
    LOCAL_CFLAGS += -DANDROID_SIM_COUNT_3
endif

ifeq ($(MTK_NUM_MODEM_PROTOCOL), 4)
    LOCAL_CFLAGS += -DANDROID_SIM_COUNT_4
endif

LOCAL_MODULE_TAGS := optional

LOCAL_C_INCLUDES := $(MTK_PATH_SOURCE)/hardware/ril/gsm/mtk-ril/   \
     $(MTK_PATH_SOURCE)/hardware/ril/include \
     $(MTK_PATH_SOURCE)/hardware/ril/platformlib/include/mtkrilutils \
     $(MTK_PATH_SOURCE)/hardware/ril/libratconfig/include \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ril/fusion/mtk-ril/mdcomm/sim/ \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ril/fusion/mtk-ril/framework/include \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ril/fusion/mtk-ril/framework/include/base \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ril/fusion/mtk-ril/framework/include/core \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ril/fusion/mtk-ril/mdcomm/ \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ril/fusion/mtk-ril/framework/port/android/include \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ril/fusion/mtk-ril/telcore \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ril/fusion/mtk-ril/ \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ril/platformlib/include \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ril/platformlib/include/utils \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ril/platformlib/include/property \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ril/platformlib/include/log \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ril/platformlib/include/config \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ril/platformlib/include/tinyxml \
     $(TOP)/$(MTK_PATH_SOURCE)/hardware/ccci/include \

ifneq ($(MTK_RIL_MODE), c6m_1rild)
LOCAL_MODULE:= mtk-ril-prop-vsim
else
LOCAL_MODULE:= libmtk-fusion-ril-prop-vsim
endif

LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk

include $(MTK_STATIC_LIBRARY)

#$(info including $(LOCAL_PATH)/fusion/Android.mk...)
#include $(LOCAL_PATH)/fusion/Android.mk

