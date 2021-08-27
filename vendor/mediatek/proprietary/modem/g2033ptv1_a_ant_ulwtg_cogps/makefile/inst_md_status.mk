#################################################
# Install Binary and related RC files           #
#################################################

$(eval $(call mtk-install-ims,\
        volte_md_status,\
        ,\
        EXECUTABLES,\
        ,\
        libs/arm/,\
        init_rc/init.volte_md_status.rc,\
        ,\
))

