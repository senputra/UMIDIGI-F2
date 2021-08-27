
LOCAL_PATH := $(call my-dir)
MTK_MODEM_LOCAL_PATH := $(LOCAL_PATH)
MTK_MODEM_MDDB_FILES :=
MTK_MODEM_FIRMWARE_FILES :=
MTK_MODEM_FILTER_FILES :=
MTK_MODEM_MAP_X_1_TO_YY := 2g wg tg lwg ltg sglte ultg ulwg ulwtg ulwcg ulwctg unlwtg unlwctg
MTK_MODEM_MAP_X_3_TO_YY := 2g 3g ulwcg ulwctg

##### INSTALL MODEM FIRMWARE #####
$(foreach x,1 3,\
  $(if $(filter-out 0,$(strip $(MTK_MD$(x)_SUPPORT))),\
    $(foreach yy,$(MTK_MODEM_MAP_X_$(x)_TO_YY),\
      $(foreach z,n,\
        $(if $(wildcard $(MTK_MODEM_LOCAL_PATH)/catcher_filter_$(x)_$(yy)_$(z).bin),\
          $(eval MTK_MODEM_FIRMWARE_FILES += catcher_filter_$(x)_$(yy)_$(z).bin)\
        )\
        $(if $(wildcard $(MTK_MODEM_LOCAL_PATH)/em_filter_$(x)_$(yy)_$(z).bin),\
          $(eval MTK_MODEM_FIRMWARE_FILES += em_filter_$(x)_$(yy)_$(z).bin)\
        )\
        $(eval MTK_MD$(x)_FILTER_FILES += $(wildcard $(MTK_MODEM_LOCAL_PATH)/catcher_filter_$(x)_$(yy)_$(z).bin))\
        $(eval MTK_MD$(x)_EM_FILTER_FILES += $(wildcard $(MTK_MODEM_LOCAL_PATH)/em_filter_$(x)_$(yy)_$(z).bin))\
      )\
    )\
  )\
)
########INSTALL MODEM DATABASE########
$(foreach x,1 3,\
  $(if $(filter-out 0,$(strip $(MTK_MD$(x)_SUPPORT))),\
    $(foreach yy,$(MTK_MODEM_MAP_X_$(x)_TO_YY),\
      $(eval MTK_MODEM_MDDB_FILES += $(notdir $(wildcard $(MTK_MODEM_LOCAL_PATH)/DbgInfo_*_$(x)_$(yy)_*)))\
      $(eval MTK_MODEM_MDDB_FILES += $(notdir $(wildcard $(MTK_MODEM_LOCAL_PATH)/MDDB*_$(x)_$(yy)_*)))\
      $(eval MTK_MODEM_MDDB_FILES += $(notdir $(wildcard $(MTK_MODEM_LOCAL_PATH)/BPMdMetaDatabase_*_$(x)_$(yy)_*)))\
      $(eval MTK_MODEM_MDDB_FILES += $(notdir $(wildcard $(MTK_MODEM_LOCAL_PATH)/mdm_layout_desc_$(x)_$(yy)_*)))\
      $(eval MTK_MD$(x)_MDDB_FILES += $(wildcard $(MTK_MODEM_LOCAL_PATH)/MDDB_*_$(x)_$(yy)_*.EDB))\
      $(eval MTK_MD$(x)_MDDBMETAODB_FILES += $(wildcard $(MTK_MODEM_LOCAL_PATH)/MDDB.META*_$(x)_$(yy)_*.XML))\
      $(eval MTK_MD$(x)_MDDBMETAODB_FILES += $(wildcard $(MTK_MODEM_LOCAL_PATH)/MDDB.META*_$(x)_$(yy)_*.XML.GZ))\
      $(eval MTK_MD$(x)_DBGINFO_DSP_FILES += $(wildcard $(MTK_MODEM_LOCAL_PATH)/DbgInfo_DSP_*_$(x)_$(yy)_*))\
      $(eval MTK_MD$(x)_DBGINFO_FILES += $(filter-out $(MTK_MODEM_LOCAL_PATH)/DbgInfo_DSP_%,$(wildcard $(MTK_MODEM_LOCAL_PATH)/DbgInfo_*_$(x)_$(yy)_*)))\
      $(eval MTK_MD$(x)_META_FILES += $(wildcard $(MTK_MODEM_LOCAL_PATH)/MDDB.META_*_$(x)_$(yy)_*.EDB))\
      $(eval MTK_MD$(x)_META_FILES += $(wildcard $(MTK_MODEM_LOCAL_PATH)/BPMdMetaDatabase_*_$(x)_$(yy)_*))\
      $(eval MTK_MD$(x)_M_LAYOUT_FILES += $(wildcard $(MTK_MODEM_LOCAL_PATH)/mdm_layout_desc_$(x)_$(yy)_*.dat))\
      $(eval mddb_check_wildcard := $(wildcard $(MTK_MODEM_LOCAL_PATH)/MDDB_*_$(x)_$(yy)_* $(MTK_MODEM_LOCAL_PATH)/MDDB.C2K.META_*_$(x)_$(yy)_*))\
      $(if $(filter 0 1,$(words $(mddb_check_wildcard))),,\
        $(info More than one MDDB files are found: $(mddb_check_wildcard))\
        $(info Please only keep the latest one)\
        $(error check-modem)\
      )\
    )\
  )\
)
########INSTALL MODEM FILTER########
$(foreach x,1,\
  $(if $(filter-out 0,$(strip $(MTK_MD$(x)_SUPPORT))),\
    $(foreach yy,$(MTK_MODEM_MAP_X_$(x)_TO_YY),\
      $(foreach z,n,\
        $(eval custom_filter_wildcard := $(wildcard $(MTK_MODEM_LOCAL_PATH)/catcher_filter_$(x)_$(yy)_$(z)_*.bin))\
        $(eval MTK_MODEM_FILTER_FILES += $(notdir $(custom_filter_wildcard)))\
        $(foreach f,$(custom_filter_wildcard),\
            $(eval k := md$(x)_filter_$(patsubst $(MTK_MODEM_LOCAL_PATH)/catcher_filter_$(x)_$(yy)_$(z)_%.bin,%,$(f)))\
            $(eval MTK_MD1_CUSTOM_FILTER_RULES += $(f):$(k))\
        )\
      )\
    )\
  )\
)
########INSTALL MODEM PARTITION########
ifeq ($(strip $(MTK_SINGLE_BIN_MODEM_SUPPORT)),yes)
MTK_MD1_SINGLEBIN_FILES += $(wildcard $(MTK_MODEM_LOCAL_PATH)/single_bin_modem.bin)
MTK_MD1_IMG_FILES += $(wildcard $(MTK_MODEM_LOCAL_PATH)/md1bin.img)
MTK_MD1_DSP_FILES += $(wildcard $(MTK_MODEM_LOCAL_PATH)/md1dsp.img)
MTK_MD3_IMG_FILES += $(wildcard $(MTK_MODEM_LOCAL_PATH)/md3img.img)
MTK_MODEM_MDDB_FILES :=
MTK_MODEM_FIRMWARE_FILES :=
MTK_MODEM_FILTER_FILES :=
else
ifneq ($(wildcard $(MTK_MODEM_LOCAL_PATH)/md1bin.img),)
$(eval $(call mtk-install-mdimg,md1bin.img,$(PRODUCT_OUT),md1img.img))
endif
ifneq ($(wildcard $(MTK_MODEM_LOCAL_PATH)/md1dsp.img),)
$(eval $(call mtk-install-mdimg,md1dsp.img,$(PRODUCT_OUT),md1dsp.img))
endif
ifneq ($(wildcard $(MTK_MODEM_LOCAL_PATH)/md3img.img),)
$(eval $(call mtk-install-mdimg,md3img.img,$(PRODUCT_OUT),md3img.img))
endif
endif#MTK_SINGLE_BIN_MODEM_SUPPORT
MTK_MODEM_MCF_OTA_FILES += $(wildcard $(MTK_MODEM_LOCAL_PATH)/MCF_OTA_FILES.tar.gz)
########DEFINE MODEM MODULE########
$(foreach item,$(MTK_MODEM_FIRMWARE_FILES),$(eval $(call mtk-install-modem,$(item),$(TARGET_OUT_VENDOR_ETC)/firmware)))
$(foreach item,$(MTK_MODEM_MDDB_FILES),$(eval $(call mtk-install-modem,$(item),$(TARGET_OUT_VENDOR_ETC)/mddb)))
$(foreach item,$(MTK_MODEM_FILTER_FILES),$(eval $(call mtk-install-modem,$(item),$(TARGET_OUT_VENDOR_ETC)/firmware/customfilter)))
########DEFINE APPS MODULE########
ifneq ($(strip $(MTK_MODEM_APPS_INCLUDE_FIRST)),yes)
include $(sort $(wildcard $(LOCAL_PATH)/makefile/inst_*.mk))
MTK_MODEM_APPS_INCLUDE_FIRST := yes
endif
MTK_MODEM_DATABASE_FILES := $(MTK_MODEM_INSTALLED_MODULES)
