MTK_ATF_SUPPORT=yes
MTK_TEE_SUPPORT=no
TRUSTONIC_TEE_SUPPORT=no
TRUSTONIC_TEE_VERSION=410
MTK_MACH_TYPE=mt6755
MTK_ATF_VERSION=v1.0
MTK_TEE_DRAM_SIZE=0x1300000
SECURE_DEINT_SUPPORT=no
MICROTRUST_TEE_SUPPORT=no
MICROTRUST_TEE_VERSION=300
MTK_INDIRECT_ACCESS_SUPPORT=no
MTK_GIC_VERSION=500
KEYMASTER_RPMB=yes
KEYMASTER_WRAPKEY=yes
ifeq ($(TARGET_BUILD_VARIANT), user)
  MTK_DEBUGSYS_LOCK = yes
endif
