#################################################
# Install Binary and related RC files           #
#################################################

$(eval $(call mtk-install-ims,\
	bip,\
	,\
	EXECUTABLES,\
	,\
	libs/arm/,\
	init_rc/init.bip.rc,\
	,\
))

