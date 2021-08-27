
ifeq ($(strip $(MTK_UT_XCAP_SUPPORT)),yes)

PRODUCT_PACKAGES += libutinterface_md
PRODUCT_PACKAGES += libcurl_xcap_md
PRODUCT_PACKAGES += libutinterface_custom_md

endif
