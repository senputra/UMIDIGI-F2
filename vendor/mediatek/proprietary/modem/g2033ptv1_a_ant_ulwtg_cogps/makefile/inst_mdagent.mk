#################################################
# Install Binary and related RC files           #
#################################################

$(eval $(call mtk-install-ims,\
        volte_imsm_93,\
        ,\
        EXECUTABLES,\
        ,\
        libs/arm/,\
        init_rc/init.volte_imsm_93.rc,\
        ,\
))

