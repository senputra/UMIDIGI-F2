
ifeq ($(strip $(MTK_UT_XCAP_SUPPORT)),yes)

$(eval $(call mtk-install-ims,\
    libutinterface_md,\
    .so,\
    SHARED_LIBRARIES,\
    libs/arm64/,\
    libs/arm/,\
))

$(eval $(call mtk-install-ims,\
    libcurl_xcap_md,\
    .so,\
    SHARED_LIBRARIES,\
    libs/arm64/,\
    libs/arm/,\
))

$(eval $(call mtk-install-ims,\
    libutinterface_custom_md,\
    .so,\
    SHARED_LIBRARIES,\
    libs/arm64/,\
    libs/arm/,\
))

endif

