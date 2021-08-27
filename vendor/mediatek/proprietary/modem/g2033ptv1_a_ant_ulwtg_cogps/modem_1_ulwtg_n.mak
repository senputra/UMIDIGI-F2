#
#  Copyright Statement:
#  ---------------------------
#  This software/firmware and related documentation ("MediaTek Software") are
#  protected under relevant copyright laws. The information contained herein 
#  is confidential and proprietary to MediaTek Inc. and/or its licensors.  
#  Without the prior written permission of MediaTek inc. and/or its licensors,
#  any reproduction,modification, use or disclosure of MediaTek Software, and
#  information contained herein, in whole or in part, shall be strictly prohibited.
#
#  MediaTek Inc.(C)2016.All rights reserved.
#
#  BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND
#  AGREES THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK 
#  SOFTWARE") RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED 
#  TO RECEIVER ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL 
#  WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED 
#  WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR 
#  NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER 
#  WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, 
#  INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER 
#  AGREES TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING 
#  THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE 
#  RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES 
#  CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR 
#  ANY MEDIATEK SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO 
#  CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND 
#  EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT 
#  TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,AT MEDIATEK'S OPTION, 
#  TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,OR REFUND ANY SOFTWARE 
#  LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK 
#  SOFTWARE AT ISSUE. 
#
# *************************************************************************

# Generated at 2020-01-17 17:36:33

AT_SLA_ENHANCEMENT = TRUE
  # Description:
  #   Add SLA to enhance AT command protection
  # Option Values:
  #   BIND_TO_AP_SBC_EN: Enable AT SLA according to AP SBC setting
  #   FALSE: AT SLA is disabled
  #   TRUE: AT SLA is enabled
  # Switch-ability:
  #   Switchable

CHK_ENV_FLAG = TRUE
  # Description:
  #   to check build environment and tool chain version
  # Option Values:
  #   FALSE: need to check build environment and tool chain version;
  #          show WARNING if the environment is not recommended.
  #   TRUE: need to check build environment and tool chain version;
  #         show error if the environment is not recommended.
  # Switch-ability:
  #   Switchable

DEFAULT_WORLD_MODE_ID = 57
  # Description:
  #   Default World Mode ID for projects which support Universal Bin
  # Option Values:
  #   19: LtTG
  #   51: LTG
  #   57: LWG
  #   59: LWTG
  #   61: LWCG
  #   63: LWCTG
  # Switch-ability:
  #   Switchable

DUAL_SIM_HOT_SWAP_CO_DECK = TRUE
  # Description:
  #   support SIM hot swap in the SAME deck
  # Option Values:
  #   FALSE: support dual SIM card hot plug in different deck
  #   TRUE: Support dual SIM card hot plug in the same deck
  # Switch-ability:
  #   Switchable

EVS_MAX_BW = WB
  # Description:
  #   EVS maximum bandwidth configuration
  # Option Values:
  #   FB: Fullband
  #   SWB: Super-wideband
  #   WB: Wideband
  # Switch-ability:
  #   Switchable

GEN93_MDMCU_SYSTEM_IMPROVEMENT_FOR_LOW_POWER = DISABLE
  # Description:
  #   Gen93 System Low Power Improvement
  # Option Values:
  #   DISABLE: DISABLE MDMCU Low Power Improvement
  #   ENABLE: ENABLE MDMCU Low Power Improvement
  # Switch-ability:
  #   Switchable

LAYOUT_SHRINK = FALSE
  # Description:
  #   To shrink modem layout, please set LAYOUT_SHRINK as true.
  # Option Values:
  #   FALSE: Not to shrink MD memory layout.
  #   TRUE: To shrink MD memory layout.
  # Switch-ability:
  #   Switchable

LTE_CA_TBL_V2_SUPPORT = TRUE
  # Description:
  #   This feature is used to decide the version of LTE CA table. V2: separate two tables for capability size reduction table and LTE CA selection table.
  # Option Values:
  #   no: auto created - value no
  #   yes: auto created - value yes
  # Switch-ability:
  #   Switchable

META_SLA_ENHANCEMENT = SLA_OFF
  # Description:
  #   Add SLA to enhance META protection
  # Option Values:
  #   SLA_BIND_TO_AP_SBC: SLA is enabled according to AP SBC setting
  #   SLA_BIND_TO_SBC: SLA is enabled according to MD SBC setting
  #   SLA_OFF: SLA is disabled
  #   SLA_ON: SLA is enabled
  # Switch-ability:
  #   Switchable

MODEM_COMMON_PACKAGE_LOW_POWER_FEATURE = DISABLE
  # Description:
  #   Modem Common Package Low Power Feature
  # Option Values:
  #   DISABLE: Disable Modem Common Package Low Power Feature
  #   ENABLE: ENABLE Modem Common Package Low Power Feature
  # Switch-ability:
  #   Switchable

MT6177M_RFCCA_SUPPORT = FALSE
  # Description:
  #   This is for MT6177M RF related project. DL/UL CCA below to BW Class C will be supported
  #   
  #   MT6761_SP(LWCTG1_MODEM_6177M)
  #   MT6761_SP(LWCTG2_MODEM_6177M)
  #   MT6761_SP(LWCTG3_MODEM_6177M)
  #   MT6761_SP(LWCTG_6177M)
  #   MT6761_SP(LWCTG_6177M_USER)
  # Option Values:
  #   FALSE: not support MT6177M RF CCA capability
  #   TRUE: support MT6177M RF CCA capability
  # Switch-ability:
  #   Switchable

NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION = FALSE
  # Description:
  #   FALSE: UE benefits from battery consumption optimisation mechanism from network, e.g. mobile phone   # TRUE: UE doesn't benefit from battery consumption optimisation mechanism from network, e.g. data card
  # Option Values:
  #   FALSE: UE benefits from battery consumption optimisation mechanism from network, e.g. mobile phone
  #   TRUE: UE doesn't benefit from battery consumption optimisation mechanism from network, e.g. data card
  # Switch-ability:
  #   Switchable

NVRAM_LID_CHECK = FALSE
  # Description:
  #   Check the nvram LID with previous version
  # Option Values:
  #   FALSE: Do NOT check the LID with previous version
  #   TRUE: Check the LID with previous version
  # Switch-ability:
  #   Switchable

NVRAM_OTA_SMART_RESET = TRUE
  # Description:
  #   Auto reset LID to default if LID structure change or default value change.
  # Option Values:
  #   FALSE: Disable this feature.
  #   TRUE: Enable this feature.
  # Switch-ability:
  #   Switchable

OTP_SUPPORT = FALSE
  # Description:
  #   Support One-Time-Programming area for the flash device
  #   
  #   Notify:
  #   If  OTP_SUPPORT = TRUE
  #   
  #   Please also modify AP part : 
  #   <EMMC>
  #   Please set /mediatek/config/[project]/ProjectConfig.mk
  #   MTK_EMMC_SUPPORT_OTP = YES
  #   
  #   <NAND>
  #   Please set /mediatek/config/[project]/ProjectConfig.mk
  #   NAND_OTP_SUPPORT = YES
  #   
  #   Relative doc could be download from
  #   http://dms.mediatek.inc:80/webtop/drl/objectId/0900006f8056690f
  # Option Values:
  #   FALSE: Disable One-Time Program Support
  #   TRUE: Enable One-Time Program Support
  # Switch-ability:
  #   Switchable

SECURE_CUSTOM_NAME = MTK
  # Description:
  #   Support security system
  # Option Values:
  #   JRD: .
  #   MTK: Customer name for MTK
  #   NONE: No customer name specified, non secure load only
  # Switch-ability:
  #   Switchable


# =========================================================================
# Non-Switchable Feature Option
# =========================================================================
BOARD_VER = MT6771_SP
  # Description:
  #   Name of the PCB or EVB.
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

CCCI_DEV_SUPPORT = TRUE
  # Description:
  #   Used to enable CCCI device related components, CCCITTY, CCCI_CCMNI, CCCI_FS.
  # Option Values:
  #   FALSE: CCCI device related components will not be built.
  #   TRUE: CCCI device related components will be built.
  # Switch-ability:
  #   Non-switchable

CCCI_FS_SUPPORT = TRUE
  # Description:
  #   Use to enable CCCI FS related component
  # Option Values:
  #   FALSE: CCCI FS related components will not be built.
  #   TRUE: CCCI FS related components will be built.
  # Switch-ability:
  #   Non-switchable

CNAP_SUPPORT = FALSE
  # Description:
  #   Enable/Disable Name identification supplementary services feature (TS22.096) support
  # Option Values:
  #   FALSE: Turn off CNAP
  #   TRUE: Turn on CNAP
  # Switch-ability:
  #   Non-switchable

COMPILER = GCC
  # Description:
  #   RVCT or ADS
  # Option Values:
  #   ADS: Use ARM ADS tool chain.
  #   GCC: Use GNU GCC tool chain (Mentor Sourcery 2010.09 , 4.5.1)
  #   RVCT: Use ARM RVCT tool chain
  # Switch-ability:
  #   Non-switchable

COMPILER_ARCH = MIPS
  # Description:
  #   distinguish between ARM and MIPS
  # Option Values:
  #   ARM: use arm instruction
  #   MIPS: use mips instruction
  # Switch-ability:
  #   Non-switchable

COMPILER_ISA = MIPS16
  # Description:
  #   Option to choose between MIPS32 and MIPS16 compiler ISA.
  # Option Values:
  #   MIPS16: Use MIPS16 ISA
  #   MIPS32: Use MIPS32 ISA (default)
  # Switch-ability:
  #   Non-switchable

CUSTOM_FLAVOR = LWCTG
  # Description:
  #   custom folder flavor setting
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

DHL_SUPPORT = TRUE
  # Description:
  #   debug and high performance logging
  # Option Values:
  #   FALSE: Disable DHL support
  #   TRUE: Enable DHL support
  # Switch-ability:
  #   Non-switchable

DSP_FLAVOR = DEFAULT_ASIC
  # Description:
  #   DSP_FLAVOR is DSP flavor name.
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

DSP_PROJECT = MT6771
  # Description:
  #   DSP_PROJECT is DSP project name.
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

DVFS_ENABLE = TRUE
  # Description:
  #   DVFS mode enable or not
  # Option Values:
  #   FALSE: DVFS mode disable
  #   TRUE: DVFS mode enable
  # Switch-ability:
  #   Non-switchable

DYNAMIC_ANTENNA_TUNING = FALSE
  # Description:
  #   Dynamic Antenna Tuning (DAT)
  #   Control antenna tuner and antenna switch component dynamically according to AP events
  # Option Values:
  #   FALSE: Not support DAT
  #   TRUE: Support DAT
  # Switch-ability:
  #   Non-switchable

EDGE_CLASS_10 = FALSE
  # Description:
  #   This is for AT&T requirement that Handset can only have multislot class 10. However our default setting is multielost class 12. So we need this feature option to let customer open this feature if they want to pass AT&T cases
  # Option Values:
  #   FALSE: GPRS Multislot Class 12
  #   TRUE: GPRS Multislot Class 10
  # Switch-ability:
  #   Non-switchable

FDD_EDCH_PHYSICAL_CATEGORY = 7
  # Description:
  #   Define the HSUPA category in makefile. However, the actual category UE uses is the minimum of this one and the one queried from HW
  # Option Values:
  #   1: EDCH category = 1
  #   2: EDCH category = 2
  #   3: EDCH category = 3
  #   4: EDCH category = 4
  #   5: EDCH category = 5
  #   6: EDCH category = 6
  # Switch-ability:
  #   Non-switchable

FDD_HSDSCH_PHYSICAL_CATEGORY = 24
  # Description:
  #   Define the HSDPA category in makefile. However, the actual category UE uses is the minimum of this one and the one queried from HW
  # Option Values:
  #   1: HSDSCH category = 1
  #   10: HSDSCH category = 10
  #   11: HSDSCH category = 11
  #   12: HSDSCH category = 12
  #   2: HSDSCH category = 2
  #   3: HSDSCH category = 3
  #   4: HSDSCH category = 4
  #   5: HSDSCH category = 5
  #   6: HSDSCH category = 6
  #   7: HSDSCH category = 7
  #   8: HSDSCH category = 8
  #   9: HSDSCH category = 9
  # Switch-ability:
  #   Non-switchable

GEMINI_L = 2
  # Description:
  #   Description:
  #   Description:
  #   To identify if this project uses a "Single chip-dual SIM" solution.
  #   indicate the L count
  #   Option Values:
  #   4: Enable 4 SIMs, single talk.
  #   3: Enable 3 SIMs, single talk.
  #   FALSE: Disable this feature
  #   2: Enable 2 SIMs, single talk.
  #   Switch-ability:
  #   Non-switchable
  #   Option Values:
  #   FALSE: Disable this feature
  #   2: Enable 2 SIMs, single talk.
  #   3: Enable 3 SIMs, single talk.
  #   4: Enable 4 SIMs, single talk.
  #   Switch-ability:
  #   Non-switchable
  # Option Values:
  #   2: Enable 2 SIMs, single talk
  #   3: Enable 3 SIMs, single talk
  #   4: Enable 4 SIMs, single talk
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

GEMINI_VERSION = V2
  # Description:
  #   This option is for Gemini version control.
  #   V1: Gemini1.0
  #   V2: Gemini2.0 (Only for dual SIM)
  # Option Values:
  #   V1: Gemini 1.0
  #   V2: Gemini 2.0
  # Switch-ability:
  #   Non-switchable

GPRS_CLASS_10 = FALSE
  # Description:
  #   This is for AT&T requirement that Handset can only have multislot class 10. However our default setting is multielost class 12. So we need this feature option to let customer open this feature if they want to pass AT&T cases
  # Option Values:
  #   FALSE: GPRS Multislot Class 12
  #   TRUE: EDGE Multislot Class 10
  # Switch-ability:
  #   Non-switchable

GSM_EM_TX_POWER_CONTROL_SUPPORT = FALSE
  # Description:
  #   Depend on this option to distinguish whether EM TX POWER CONTROL is support or not
  # Option Values:
  #   FALSE: #EM TX POWER CONTROL IS NOT supported
  #   TRUE: #EM TX POWER CONTROL IS supported
  # Switch-ability:
  #   Non-switchable

HIF_CCCI_SUPPORT = TRUE
  # Description:
  #   Used to enable CCCI Core related components.
  # Option Values:
  #   FALSE: CCCI core related components wiil not be built
  #   TRUE: CCCI core related components will be built.
  # Switch-ability:
  #   Non-switchable

HIF_CCISM_SUPPORT = TRUE
  # Description:
  #   For support hardware interface CCISM
  # Option Values:
  #   FALSE: Not support CCISM interface
  #   TRUE: Support CCISM interface
  # Switch-ability:
  #   Non-switchable

HIF_PCCIF_ARM7_SUPPORT = FALSE
  # Description:
  #   For support hardware interface PCCIF_ARM7
  # Option Values:
  #   FALSE: Not support PCCIF_ARM7 interface
  #   TRUE: Support PCCIF_ARM7 interface
  # Switch-ability:
  #   Non-switchable

HIF_SECPCCIF_SUPPORT = TRUE
  # Description:
  #   For support hardware interface security PCCIF
  # Option Values:
  #   FALSE: Not support security PCCIF interface
  #   TRUE: Support security PCCIF interface
  # Switch-ability:
  #   Non-switchable

HIF_UART_SUPPORT = FALSE
  # Description:
  #   description:
  #   
  #   used to enable UART Core related components, UARTCORE.
  #   
  #   Option Values:
  #   
  #   TRUE: UART core related components will be built.
  #   
  #   FALSE: UARTcore related components will not be built.
  # Option Values:
  #   no: auto created - value no
  #   yes: auto created - value yes
  # Switch-ability:
  #   Non-switchable

HIF_USB30_SUPPORT = FALSE
  # Description:
  #   Enable HIF USB 3.0 feature
  # Option Values:
  #   FALSE: Disable USB 3.0 -> run in USB 2.0
  #   TRUE: Enable USB 3.0
  # Switch-ability:
  #   Non-switchable

HIF_USB_SUPPORT = FALSE
  # Description:
  #   Enable HIF USB feature
  # Option Values:
  #   FALSE: Disable HIF USB
  #   TRUE: Enable HIF USB
  # Switch-ability:
  #   Non-switchable

HIF_WCCIF_SUPPORT = FALSE
  # Description:
  #   For support hardware interface WCCIF (CCIF of WR8)
  # Option Values:
  #   FALSE: Not support WCCIF interface
  #   TRUE: Support WCCIF interface
  # Switch-ability:
  #   Non-switchable

ICD_SUPPORT = FALSE
  # Description:
  #   An Interface Control Document (ICD) provides a unified information generated from modem platform
  # Option Values:
  #   FALSE: Disable Modem ICD feature
  #   TRUE: Enable Modem ICD feature
  # Switch-ability:
  #   Non-switchable

IMS_GEN_CFG = GEN93_USER
  # Description:
  #   IMS_GEN_CFG is IMS gen config.
  # Option Values:
  #   GEN90_ENG: 90 generation eng
  #   GEN90_USER: 90 generation user
  #   GEN91_ENG: 91 generation eng
  #   GEN91_USER: 91 generation user
  #   GEN92_ENG: 92 generation eng
  #   GEN92_USER: 92 generation user
  #   GEN93_ENG: 93 generation eng
  #   GEN93_USER: 93 generation user
  #   NONE: no ims
  # Switch-ability:
  #   Non-switchable

IMS_SUPPORT = TRUE
  # Description:
  #   Description: 
  #   This is for VoLTE project
  #   Option Values:
  #   NONE: Not support for IMS feature
  #   TRUE: support for IMS feature
  #   Switch-ability:
  #   Non-switchable
  # Option Values:
  #   FALSE: Disable IMS capability
  #   TRUE: Enable IMS capability
  # Switch-ability:
  #   Non-switchable

IS_MT6177M_CODE_DOMAIN_POWER_IMPROVE = FALSE
  # Description:
  #   Value:TRUE
  #   Description:Improve WCDMA Code Domain Power
  #   Value:FALSE
  #   Description:Do not improve WCDMA Code Domain Power
  # Option Values:
  #   no: auto created - value no
  #   yes: auto created - value yes
  # Switch-ability:
  #   Non-switchable

L1D_LOOPBACK = 0
  # Description:
  #   enable WCDMA phase 3 co-sim load
  # Option Values:
  #   0: internal use
  #   2: internal use
  # Switch-ability:
  #   Non-switchable

L1_CATCHER = TRUE
  # Description:
  #   to enable L1 logging.
  # Option Values:
  #   FALSE: Disable
  #   TRUE: Enable
  # Switch-ability:
  #   Non-switchable

L1_GPS_REF_TIME_SUPPORT = TRUE
  # Description:
  #   To enable GPS-L1 reference fine time measurement
  # Option Values:
  #   FALSE: LI GPS timing synch feature is not supported
  #   TRUE: LI GPS timing synch feature is supported
  # Switch-ability:
  #   Non-switchable

LTE_GTT_SUPPORT = FALSE
  # Description:
  #   To turn on/off 4G GTT feature
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   Non-switchable

LTE_MAX_EPSB_SUPPORT = 8
  # Description:
  #   LTE bearer number, MAX_EXT_PDP_CONTEXT = max(GPRS_MAX_PDP_SUPPORT, LTE_MAX_EPSB_SUPPORT)
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

LTE_REPORT_CAP_AS_RELEASE = DEFAULT
  # Description:
  #   Set the release version of UECapabilityInformation.
  # Option Values:
  #   AS_REL_10: Report UE Capability to Release 10
  #   AS_REL_11: Report UE Capability to Release 11
  #   DEFAULT: Report Default Version of UE Capability
  # Switch-ability:
  #   Non-switchable

LTE_RF_MODULE = MT6771_LTE_MT6177
  # Description:
  #   Describe the LTE RF module used in this project
  #   For example:
  #   LTE_RF_MODULE = MT6169_LTE
  # Option Values:
  #   MT6169_LTE: The RF module name for LTE
  #   NONE: Default settings if there is no need to define the LTE RF module
  # Switch-ability:
  #   Non-switchable

MCD_CODESET_SHIFT_SUPPORT = 440000
  # Description:
  #   NONE: if Codeset Shift not support
  #   440000: if Codeset shift support by Docomo (Plmn ID: 440000)                                      You can enumerate all suitable support plmn
  # Option Values:
  #   440000: not support codec shift
  #   NONE: support codec shift for DOCOMO LAB test
  # Switch-ability:
  #   Non-switchable

MM_RF_MODULE = MT6771_MMRF_MT6177
  # Description:
  #   Describe the Multi-Mode RF module used in this project for Customization
  # Option Values:
  #   NONE: Default settings if there is no need to define
  # Switch-ability:
  #   Non-switchable

MODEM_SPEC = MTK_MODEM_LWTG
  # Description:
  #   MTK modem spec type
  # Option Values:
  #   MTK_MODEM_2G_EDGE: MTK 2G EDGE modem
  #   MTK_MODEM_3G_TDD: MTK 3G TD modem
  #   MTK_MODEM_3G_WCDMA: MTK 3G WCDMA modem
  #   MTK_MODEM_4G_LTE_MM_TDD: MTK 4G LTE-TD-EDGE multi-mode modem
  #   MTK_MODEM_4G_LTE_MM_WCDMA: MTK 4G LTE-WCDMA-EDGE multi-mode modem
  #   MTK_MODEM_4G_LTE_SM: MTK 4G LTE single mode modem
  #   MTK_MODEM_G: MTK 2G EDGE modem
  #   MTK_MODEM_LTG: MTK 4G LTE / 3G TDSCDMA modem
  #   MTK_MODEM_LWCTG: FDD-LTE/TDD-LTE/WCDMA/CDMA2000/TDSCDMA/GSM
  #   MTK_MODEM_LWG: MTK 4G LTE / 3G WCDMA modem
  #   MTK_MODEM_LWTG: FDD-LTE/TDD-LTE/WCDMA/TDSCDMA/GSM
  #   MTK_MODEM_LfTG: MTK 4G FDD-LTE / 3G TDSCDMA modem
  #   MTK_MODEM_LfWG: MTK 4G FDD-LTE / 3G WCDMA modem
  #   MTK_MODEM_LtTG: MTK 4G TDD-LTE / 3G TDSCDMA modem
  #   MTK_MODEM_LtWG: MTK 4G TDD-LTE / 3G WCDMA modem
  #   MTK_MODEM_TG: MTK 3G TDSCDMA modem
  #   MTK_MODEM_WG: MTK 3G WCDMA modem
  # Switch-ability:
  #   Non-switchable
#
#  Copyright Statement:
#  ---------------------------
#  This software/firmware and related documentation ("MediaTek Software") are
#  protected under relevant copyright laws. The information contained herein 
#  is confidential and proprietary to MediaTek Inc. and/or its licensors.  
#  Without the prior written permission of MediaTek inc. and/or its licensors,
#  any reproduction,modification, use or disclosure of MediaTek Software, and
#  information contained herein, in whole or in part, shall be strictly prohibited.
#   
#  MediaTek Inc.(C)2015.All rights reserved.
#
#  BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND
#  AGREES THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK 
#  SOFTWARE") RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED 
#  TO RECEIVER ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL 
#  WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED 
#  WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR 
#  NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER 
#  WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, 
#  INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER 
#  AGREES TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING 
#  THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE 
#  RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES 
#  CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR 
#  ANY MEDIATEK SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO 
#  CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND 
#  EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT 
#  TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,AT MEDIATEK'S OPTION, 
#  TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,OR REFUND ANY SOFTWARE 
#  LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK 
#  SOFTWARE AT ISSUE. 
#
# *************************************************************************

# Generated at 2015-09-18 12:14:48
C2K_MODE_SUPPORT = NONE
  # Description:
  #   Specify if CDMA2000 RAT is supported
  # Option Values:
  #   C2K_SRLTE: CDMA2000 RAT is supported, LTE SRLTE is enabled
  #   C2K_ONLY:  CDMA2000 RAT is supported, LTE SRLTE is disabled
  #   NONE:      CDMA2000 RAT is not supported, LTE SRLTE is disabled
  # Switch-ability:
  #   Non-switchable

EUTRAN_MODE_SUPPORT = EUTRAN_MODE
  # Description:
  #   4G modem capability
  # Option Values:
  #   EUTRAN_MODE: Support EUTRAN mode
  #   NONE: NONE
  # Switch-ability:
  #   Non-switchable

FDD_LTE_SUPPORT = TRUE
  # Description:
  #   FDD_LTE support capability
  # Option Values:
  #   TRUE: Support FDD-LTE
  #   FALSE: Do NOT support FDD-LTE
  # Switch-ability:
  #   Non-switchable

GERAN_MODE_SUPPORT = GERAN_EGPRS_MODE
  # Description:
  #   2G modem capability
  # Option Values:
  #   GERAN_GSM_MODE: Support GSM only
  #   GERAN_GPRS_MODE: Support GPRS
  #   GERAN_EGPRS_MODE: Support EGPRS
  #   NONE: NONE
  # Switch-ability:
  #   Non-switchable

L1_EGPRS = TRUE
  # Description:
  #   this compile option is only used for L1 Stand alone to turn on/off EDGE function
  # Option Values:
  #   TRUE: EGPRS enable
  #   FALSE: EGPRS disable
  # Switch-ability:
  #   Non-switchable

L1_GPRS = TRUE
  # Description:
  #   Turn on the GPRS support of Layer 1
  #   This is used for internal test
  # Option Values:
  #   TRUE: GPRS enable
  #   FALSE: GPRS disable
  # Switch-ability:
  #   Non-switchable

L1_TDD128 = TRUE
  # Description:
  #   Modem Capability
  # Option Values:
  #   TRUE: L1 support TDD modem
  #   FALSE: L1 not support TDD modem
  # Switch-ability:
  #   Non-switchable

L1_WCDMA = TRUE
  # Description:
  #   Add an option to enable WCDMA L1 support
  # Option Values:
  #   TRUE: Support UMTS L1
  #   FALSE: Not support UMTS L1
  # Switch-ability:
  #   Non-switchable

LTE_RELEASE_SUPPORT = LTE_RD10_RELEASE
  # Description:
  #   The option is to switch different asn1 version of release for TS36.331
  # Option Values:
  #   LTE_R9_RELEASE: TS 36.331 9.8.0
  #   LTE_R9C0_RELEASE: TS 36.331 9.12.0
  #   LTE_RB70_RELEASE: TS 36.331 11.7.0
  #   LTE_RB90_RELEASE: TS 36.331 11.9.0
  #   LTE_RC50_RELEASE: TS 36.331 12.5.0
  #   NONE: NONE
  # Switch-ability:
  #   Non-switchable

TDD_LTE_SUPPORT = TRUE
  # Description:
  #   TDD_LTE support capability
  # Option Values:
  #   TRUE: Support TDD-LTE
  #   Support TDD-LTE: Support TDD-LTE
  # Switch-ability:
  #   Non-switchable

UMTS_FDD_SUPPORT = UMTS_FDD_MODE_SUPPORT
  # Description:
  #   Feature option for 3G FDD Modem Mode 
  # Option Values:
  #   UMTS_FDD_MODE_SUPPORT: 3G Modem in FDD Mode
  # Switch-ability:
  #   Non-switchable

UMTS_MODE_SUPPORT = UMTS_FDD_TDD_SUPPORT
  # Description:
  #   The option is to switch the FDD or TDD mode for 3G modem
  # Option Values:
  #   UMTS_FDD_MODE_SUPPORT: 3G modem in FDD mode
  #   UMTS_TDD128_MODE_SUPPORT: 3G modem in TDD mode
  #   NONE: None of 3G modem mode is supported.
  # Switch-ability:
  #   Non-switchable

UMTS_RELEASE_SUPPORT = UMTS_R11_SUPPORT
  # Description:
  #   The option is to switch different version of release for 3G modem
  # Option Values:
  #   UMTS_R6_SUPPORT: 3G modem supports Rel6
  #   UMTS_R4_SUPPORT: 3G modem supports Rel4
  #   UMTS_R5_SUPPORT: 3G modem supports Rel5
  # Switch-ability:
  #   Non-switchable

UMTS_TDD_SUPPORT = UMTS_TDD128_MODE_SUPPORT
  # Description:
  #   3G modem in TDD mode
  # Option Values:
  #   UMTS_TDD128_MODE_SUPPORT: 3g modem in TDD mode
  # Switch-ability:
  #   Non-switchable

UTRAN_MODE_SUPPORT = UTRAN_FDD_TDD_SUPPORT
  # Description:
  #   3G modem capability
  # Option Values:
  #   UTRAN_FDD_MODE: Support 3G FDD
  #   UTRAN_TDD128_MODE: Support 3G TDD128
  #   NONE: NONE
  # Switch-ability:
  #   Non-switchable


MTK_AUDIO_HIERARCHICAL_PARAM_SUPPORT = TRUE
  # Description:
  #   NEW SPE architecture
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

MTK_MODEM_ARCH = MT6293
  # Description:
  #   MTK MODEM ARCHITECTURE
  # Option Values:
  #   MT6291: MT6291
  #   MT6291M: MT6291M
  #   MT6291P: MT6291P
  # Switch-ability:
  #   Non-switchable

MULTIPLE_PS = TRUE
  # Description:
  #   Turn on/off multiple PS attach feature
  # Option Values:
  #   FALSE: Turn off Muliple PS attach feature
  #   TRUE: Turn on Muliple PS attach feature
  # Switch-ability:
  #   Non-switchable

NVRAM_OTP_ENCRYPT = FALSE
  # Description:
  #   To turn on/off encryption for NVRAM OTP LID.
  # Option Values:
  #   FALSE: To disable encryption for NVRAM OTP LID
  #   TRUE: To enable encryption for NVRAM OTP LID
  # Switch-ability:
  #   Non-switchable

ORIGINAL_FLAVOR = LWTG_R3_6771
  # Description:
  #   Project original flavor setting (for customer project reference only)
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

ORIGINAL_PROJECT_NAME = TK_MD_BASIC
  # Description:
  #   Project original name setting (for customer project reference only)
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

PLMN_LIST_PREF_SUPPORT = DEFAULT
  # Description:
  #   PLMN List EM mode setting
  # Option Values:
  #   DEFAULT: PLMN list mode can be selected except low cost, L1S project.
  #   OFF: PLMN List mode can not be selected by EM mode
  #   ON: Let PLMN List mode, accuracy or speed, can be selected by EM mode
  # Switch-ability:
  #   Non-switchable

PRODUCTION_RELEASE = TRUE
  # Description:
  #   Specify if production released is turned on. 
  #   If it is enabled, some system code will be effected, like
  #   1. Watchdog enabled, and must be restared each time context switch;
  #   2. Handset silent reboot if system comes across with exception;
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Disable this feature
  # Switch-ability:
  #   Non-switchable

RF_DRDI_SPECIAL_MEMORY_SUPPORT = FALSE
  # Description:
  #   this feature option is for extend DRDI to support HTC request
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   Non-switchable

RTOS = NUCLEUS_V3
  # Description:
  #   The RTOS used in the load
  # Option Values:
  #   MERTOS: Use MERTOS as OS
  #   NUCLEUS_V2: Use Nucleus 2.x as the OX
  #   NUCLEUS_V3: Use Nucleus 3 as the OS
  # Switch-ability:
  #   Non-switchable

SAR_TX_POWER_BACKOFF_SUPPORT = FALSE
  # Description:
  #   SAR_TX_POWER_BACKOFF_SUPPORT = FALSE  
  #   Description: 
  #   Option Values: 
  #   TRUE:Set to TRUE if support SAR_TX_POWER_BACKOFF_SUPPORT. 
  #   FALSE:Set to FALSE if not support SAR_TX_POWER_BACKOFF_SUPPORT.
  # Option Values:
  #   FALSE: sar tx power backoff support is NOT supported
  #   TRUE: sar tx power backoff support is supported
  # Switch-ability:
  #   Non-switchable

SIM_HOT_SWAP = SIM_SLOT_2
  # Description:
  #   support SIM hot swap, only MT6253D enable now
  # Option Values:
  #   NONE: not support SIM hot swap
  #   SIM_SLOT_1: single SIM project, support sim hot swap from SLOT 1
  #   SIM_SLOT_2: Dual SIM  project, support sim hot swap from SLOT 2
  #   SIM_SLOT_3: 3 SIM  project, support sim hot swap from SLOT 3
  #   SIM_SLOT_4: 4 SIM  project, support sim hot swap from SLOT 4
  # Switch-ability:
  #   Non-switchable

SP_VIDEO_CALL_SUPPORT = FALSE
  # Description:
  #   Enable Video Call Modem Capability for Smartphone project
  # Option Values:
  #   FALSE: Turn off Video Call Support for Smartphone
  #   TRUE: Turn on Video Call Support for Smartphone
  #         (conflict w/ 3G_VIDEO_CALL)
  # Switch-ability:
  #   Non-switchable

TDD_EDCH_PHYSICAL_CATEGORY = 6
  # Description:
  #   Define the HSUPA category in makefile.
  # Option Values:
  #   1: EDCH Physical category = 1
  #   2: EDCH Physical category = 2
  #   3: EDCH Physical category 3
  #   4: EDCH Physical category = 4
  #   5: EDCH Physical category = 5
  #   6: EDCH Physical category = 6
  # Switch-ability:
  #   Non-switchable

TDD_HSDSCH_PHYSICAL_CATEGORY = 14
  # Description:
  #   Define the HSDPA category in makefile.
  # Option Values:
  #   1: HSDSCH category = 1
  #   10: HSDSCH category = 10
  #   11: HSDSCH category = 11
  #   12: HSDSCH category = 12
  #   13: HSDSCH category = 13
  #   14: HSDSCH category = 14
  #   15: HSDSCH category = 15
  #   2: HSDSCH category = 2
  #   3: HSDSCH category = 3
  #   4: HSDSCH category = 4
  #   5: HSDSCH category = 5
  #   6: HSDSCH category = 6
  #   7: HSDSCH category = 7
  #   8: HSDSCH category = 8
  #   9: HSDSCH category = 9
  # Switch-ability:
  #   Non-switchable

TST_DNT_LOGGING = FALSE
  # Description:
  #   Enable SIB logging (High speed logging interface)
  # Option Values:
  #   FALSE: Disable
  #   TRUE: Enable
  # Switch-ability:
  #   Non-switchable

TST_LOGACC_SUPPORT = FALSE
  # Description:
  #   to enable the LogAcc HW Support for TST.
  # Option Values:
  #   FALSE: Disable
  #   TRUE: Enable
  # Switch-ability:
  #   Non-switchable

TST_MALMO_SUPPORT = FALSE
  # Description:
  #   Support advanced logging acceleration system, Maimo.
  #   It's HW dependent and only supported on certain platforms.
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   Non-switchable

TST_SUPPORT = FALSE
  # Description:
  #   to enable message logging and debug information tracing mechanism.
  # Option Values:
  #   FALSE: Disable
  #   TRUE: Enable
  # Switch-ability:
  #   Non-switchable

USB_ACM_SUPPORT = FALSE
  # Description:
  #   Used to enable USB CDC/ACM device
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

USB_ECM_SUPPORT = FALSE
  # Description:
  #   Used to enable USB CDC/ECM device
  # Option Values:
  #   FALSE: Disable USB CDC/ECM device
  #   TRUE: Enable USB CDC/ECM device
  # Switch-ability:
  #   Non-switchable

USE_EVS_IO_REPLACE_AWB = TRUE
  # Description:
  #   Use EVS AWB-IO mode codec to replace AWB codec.
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

UT_FLUSH_LOG_ON_ASSERT = FALSE
  # Description:
  #   Enable log flush on assert in MoDIS-like environment
  # Option Values:
  #   FALSE: Disable
  #   TRUE: Enable
  # Switch-ability:
  #   Non-switchable

VOLTE_SUPPORT = TRUE
  # Description:
  #   Enable or disable Voice over LTE
  # Option Values:
  #   FALSE: Note support VoLTE
  #   TRUE: Support the VoLTE
  # Switch-ability:
  #   Non-switchable

WCDMA_RFEQ_COEF_SUBBAND_SUPPORT = FALSE
  # Description:
  #   Value:TRUE
  #   Description:Turn on WCDMA RFEQ tuning by sub-band feature
  #   Value:FALSE
  #   Description:Turn off WCDMA RFEQ tuning by sub-band feature
  # Option Values:
  #   no: auto created - value no
  #   yes: auto created - value yes
  # Switch-ability:
  #   Non-switchable

WFC_SUPPORT = TRUE
  # Description:
  #   Description: 
  #   This is for WFC project. WFC is part of IMS. So WFC_SUPPORT can only effective when IMS_SUPPORT is set to TRUE also.
  #   Option Values: 
  #   NONE: Not support for IMS-WFC feature 
  #   TRUE: support for IMS-WFC feature 
  #   Switch-ability: 
  #   Non-switchable
  # Option Values:
  #   FALSE: Disable WFC capability
  #   TRUE: Enable WFC capability
  # Switch-ability:
  #   Non-switchable

WIFI_LTE_DPP_SUPPORT = FALSE
  # Description:
  #   WIFI/LTE Duplicate Packet Prediction support
  # Option Values:
  #   no: auto created - value no
  #   yes: auto created - value yes
  # Switch-ability:
  #   Non-switchable


# =========================================================================
# Feature Options which customer can NOT modify
# =========================================================================
2G_BPI_PT3A_SUPPORT = TRUE
  # Description:
  #   TRUE: Support the PT3A event
  #   FALSE: NOT support the PT3A event
  # Option Values:
  #   FALSE: NOT support the PT3A event
  #   TRUE: Support the PT3A event
  # Switch-ability:
  #   Non-switchable

2G_RX_DIVERSITY_PATH_SUPPORT = FALSE
  # Description:
  #   TRUE: Support 2G RX diversity path
  #   FALSE: NOT support  2G RX diversity path
  # Option Values:
  #   FALSE: NOT support  2G RX diversity path
  #   TRUE: Support 2G RX diversity path
  # Switch-ability:
  #   Non-switchable

2G_TX_VOLTAGE_COMPENSATION_SUPPORT = TRUE
  # Description:
  #   This feature option is to turn on/off the voltage compensation on 2G TX power
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

32K_XOSC_REMOVE = TRUE
  # Description:
  #   support 32k crystal removal
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

AFC_VCXO_TYPE = VCXO
  # Description:
  #   the oscillator type used in this project
  # Option Values:
  #   VCTCXO: VCTCXO clk
  #   VCXO: VCXO clk
  # Switch-ability:
  #   Switchable

AGPS_SUPPORT = CP_AGPS_AGLONASS_ABDS
  # Description:
  #   Description:
  #   It decides control plane is used.
  #   Option Values:
  #   NONE: Disable AGPS feature.
  #   CP_AGPS: Enable AGPS control-plane on 2/3/4G. (only used for the modem load on smart phone project not support GLONASS)
  #   CP_AGPS_AGLONASS: Enable AGPS and AGLONASS control-plane on 2/3/4G. (only used for the modem load on smart phone project supported GLONASS)
  #   CP_AGPS_AGLONASS_ABDS: Enable AGPS , AGLONASS and ABDS control-plane on 2/3/4G. (only used for the modem load on smart phone project supported GLONASS and BDS)
  #   Switch-ability:
  #   Non-switchable
  # Option Values:
  #   CONTROL_PLANE: Enable AGPS control-plane. (only used for the modem load on smart phone project)
  #   CP_AGPS: Enable AGPS control-plane on 2/3G.
  #   CP_AGPS_AGLONASS: Enable AGPS and AGLONASS control-plane on 2/3G.
  #   CP_AGPS_AGLONASS_ABDS: it can support A-BDS
  #   CP_AGPS_AGLONASS_ABDS_AGALILEO: It can support A-Galileo
  #   NONE: Disable AGPS feature.
  # Switch-ability:
  #   Non-switchable

AMMS_DRDI_SUPPORT = FALSE
  # Description:
  #   If the option is TRUE, MD will return unused DRDI data memory to AP.
  #   Note(LR13 R2 ONLY): customers cannot turn on &quot;modem secure boot check&quot; and &quot;AMMS-DRDI&quot; simultaneously
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   Non-switchable

AMMS_POS_SUPPORT = FALSE
  # Description:
  #   Some network but not all network needs Positioning info. It is a waste if memory source from Global variable since the memory will be used only during emergency phone call. Hence we aim to source memory from AP side in runtime, and return memory to AP if usage completed.
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this featuree
  # Switch-ability:
  #   Non-switchable

AMRWB_LINK_SUPPORT = TRUE
  # Description:
  #   If the compile option is true, our BB chip will support AMRWB voice call. If false, we won't support this function.
  # Option Values:
  #   FALSE: Not Support WB-AMR link
  #   TRUE: Support WB-AMR link
  # Switch-ability:
  #   Switchable

AMR_LINK_SUPPORT = TRUE
  # Description:
  #   Support AMR link, channel codec and RATSCCH procedure, with base station.
  # Option Values:
  #   FALSE: AMR disable
  #   TRUE: AMR enable
  # Switch-ability:
  #   Non-switchable

BAND_SUPPORT = QUAD
  # Description:
  #   Described the support band of RF
  # Option Values:
  #   DCS1800: Support 1800
  #   DUAL850: Support 850/1900
  #   DUAL900: Support 900/1800
  #   EGSM900: Support 900
  #   GSM450: Support 450
  #   GSM850: Support 850
  #   PCS1900: Support 1900
  #   PGSM900: Support 900
  #   QUAD: Support 850/900/1800/1900
  #   RGSM900: Support 900
  #   TRIPLE: Support 900/1800/1900
  #   TRIPLE850: Support 850/1800/1900
  # Switch-ability:
  #   Switchable

BIP_SUPPORT = TRUE
  # Description:
  #   support Bearer Independent Protocol
  # Option Values:
  #   FALSE: disable BIP in MD
  #   TRUE: enable BIP in MD
  # Switch-ability:
  #   Non-switchable

C2K_RFD_STUB_ENABLE = FALSE
  # Description:
  #   This flag is added for CL1 to use C2K RFD stub interface or formal interface;
  #   FALSE by default. (Modis:TRUE,Default:FALSE)
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Switchable

CARRIER_RESTRICTION = FALSE
  # Description:
  #   Android SIMME lock Carrier Restriction Feature
  # Option Values:
  #   no: auto created - value no
  #   yes: auto created - value yes
  # Switch-ability:
  #   Non-switchable

CHIP_VER = S00
  # Description:
  #   Chip version, changed according to ECO.
  # Option Values:
  #   S00: .
  #   S01: .
  #   S02: .
  # Switch-ability:
  #   Non-switchable

CLIB_TIME_SUPPORT = TRUE
  # Description:
  #   Enable clib time function e.g. time(), gmtime_r(), localtime_r()...
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   Non-switchable

CMUX_SUPPORT = TRUE
  # Description:
  #   Support 07.10 multiplexer feature: TRUE or FALSE
  # Option Values:
  #   FALSE: Disable 27.010 multiplexer
  #   TRUE: Enable 27.010 multiplexer
  # Switch-ability:
  #   Non-switchable

COMBO_MEMORY_SUPPORT = FALSE
  # Description:
  #   To support different memory part in the same load.
  # Option Values:
  #   FALSE: Disable combo memory support.
  #          Default setting is FALSE.
  #   TRUE: Enable combo memory support
  # Switch-ability:
  #   Non-switchable

CONFIG_UI = NONE
  # Description:
  #   Compare with feature phone, the UI is not a part of modem since smart phone. Default is NONE
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

CUSTOM_DEBUG_MODULES = NVRAM SYS_SVC SYS_DRV CONFIG DEVDRV
  # Description:
  #   CUSTOM_DEBUG_MODULES means these modules will be built with debug information.
  # Option Values:
  #   ALL: all
  #   NONE: Disable this feature
  #   module_names: The modules' name that you want to turn on debug information, seperated by space
  # Switch-ability:
  #   Non-switchable

CUSTOM_NON_DEBUG_MODULES = NONE
  # Description:
  #   CUSTOM_NON_DEBUG_MODULES means it will be built without debug information after custom release
  # Option Values:
  #   ALL: .
  #   NONE: .
  #   module_names: Module name list using space seperated
  # Switch-ability:
  #   Switchable

DATA_CARD_SPEECH = FALSE
  # Description:
  #   Enable speech capablility via data card tool  through PC speaker and microphone
  # Option Values:
  #   FALSE: Disable Datacrad speech
  #   TRUE: Enable data card speech
  # Switch-ability:
  #   Non-switchable

DEMO_PROJECT = FALSE
  # Description:
  #   To define projects that are experimental or for demo purposes only. It should NEVER be enabled on MP projects, and it is used by MTK internally. Customer does not need to change it
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   Non-switchable

DHL_CCB_LOGGING_SUPPORT = TRUE
  # Description:
  #   Logging with cross-core buffer management feature by CCCI.
  #   Direct share memory access both for MD and AP logging service.
  # Option Values:
  #   FALSE: Use other CCCI channel.
  #   TRUE: Use CCB as logging channel.
  # Switch-ability:
  #   Non-switchable

DHL_MONITOR_MODE_SUPPORT = TRUE
  # Description:
  #   Collect customer subscribe info to monitor channel
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

DHL_ULSP_SUPPORT = TRUE
  # Description:
  #   DHL_ULSP_SUPPORT = FALSE
  #   Description:
  #   enable hardware ULS+ logging 
  #   Option Values:
  #   TRUE: Support
  #   FALSE: Non Support
  #   Switch-ability:
  #   True -> False
  # Option Values:
  #   FALSE: Not support ULS+ logging
  #   TRUE: Support DHL ULS+ logging
  # Switch-ability:
  #   Switchable

DISABLE_CRRST_LOCK = FALSE
  # Description:
  #   This feature is to disable Carrier Restriction Lock check facility
  # Option Values:
  #   no: auto created - value no
  #   yes: auto created - value yes
  # Switch-ability:
  #   Non-switchable

DISABLE_SLEEP = TRUE
  # Description:
  #   control the C2K sleep mode
  # Option Values:
  #   FALSE: Enable C2K sleep
  #   TRUE: Disable C2K sleep
  # Switch-ability:
  #   Non-switchable

DRV_CUSTOM_TOOL_SUPPORT = FALSE
  # Description:
  #   To enable using driver customization tool for GPIO/EINT/ADC/UEM/Keypad/PMU setting.
  # Option Values:
  #   FALSE: Disable
  #   TRUE: Enable
  # Switch-ability:
  #   Switchable

DSPIRDBG = FALSE
  # Description:
  #   To enable IRDBG interface for dsp debugging
  # Option Values:
  #   FALSE: .
  #   TRUE: .
  # Switch-ability:
  #   Non-switchable

EDGE_SUPPORT = TRUE
  # Description:
  #   Enable EDGE support Only applicable to 6229 latter version
  # Option Values:
  #   FALSE: EGPRS enable
  #   TRUE: EGPRS enable
  # Switch-ability:
  #   Non-switchable

EVS_SUPPORT = TRUE
  # Description:
  #   speech new codec feature EVS
  # Option Values:
  #   FALSE: EVS no support
  #   TRUE: EVS support
  # Switch-ability:
  #   Non-switchable

FAST_DORMANCY_SUPPORT = TRUE
  # Description:
  #   This feature option is used to enable/disable 3G R8 Fast Dormancy feature.
  # Option Values:
  #   FALSE: Support Legacy FD
  #   TRUE: Support both R8 & Legacy FD
  #   not define the feature option: modem will not support R8 nor Legacy FD
  # Switch-ability:
  #   Switchable

FOTA_UPDATE_PACKAGE_ON_NAND = FALSE
  # Description:
  #   Use NAND to place update package for NOR project
  # Option Values:
  #   FALSE: Place diff package on NOR
  #   TRUE: Enable FOTA update package in NAND for NOR project
  # Switch-ability:
  #   Non-switchable

FS_DEDICATED_BUFFER = TRUE
  # Description:
  #   If this feature is enabled, FS will allocate a dedicated buffer to enhance file system performance. The improved operations are file copy, file move (to differenct drive), disk mount, disk format and memory card hot-plug-in.
  # Option Values:
  #   FALSE: Disable FS Dedicated Buffer
  #   TRUE: Enable FS Dedicated Buffer
  # Switch-ability:
  #   Switchable

FS_OPEN_HINT_SUPPORT = TRUE
  # Description:
  #   FS will try to preserve several recently found locations of files or folders internally. If FS user wants to open those files or folders again later, the opening time could be minimized.
  # Option Values:
  #   FALSE: Disable FS Internal Open Hint
  #   TRUE: Enable FS Internal Open Hint
  # Switch-ability:
  #   Switchable

FS_RAMDISK = FALSE
  # Description:
  #   Enable RAM disk to replace NOR flash disk.
  #   NOTE. To enable FS_RAMDISK, please configure this project as file system on NOR flash.
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: RAM Disk will replace flash disk (e.g., NOR, NAND, eMMC...etc) on file system. This feature is used for SP modem-only project only.
  # Switch-ability:
  #   Non-switchable

FS_TRACE_SUPPORT = FALSE
  # Description:
  #   File System will provide run-time trace information with proper configure. The trace information is very helpful to identify problem source.
  # Option Values:
  #   FALSE: To disable FS debug messange
  #   TRUE: To enable FS debug messange
  # Switch-ability:
  #   Switchable

GCC_WARN_AS_ERROR = FALSE
  # Description:
  #   This option will regard build warnings as errors for GCC.
  # Option Values:
  #   FALSE: Not support warnings as errors
  #   TRUE: Support warnings as errors
  # Switch-ability:
  #   Non-switchable

GEMINI = 2
  # Description:
  #   To identify if this project uses a &quot;Single chip-dual SIM&quot; solution.
  # Option Values:
  #   2: Enable 2 SIMs, single talk.
  #   3: Enable 3 SIMs, single talk.
  #   4: Enable 4 SIMs, single talk.
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

GEMINI_W = 2
  # Description:
  #   Description:
  #   To identify if this project uses a "Single chip-dual SIM" solution.
  #   indicate the W count
  #   Option Values:
  #   4: Enable 4 SIMs, single talk.
  #   3: Enable 3 SIMs, single talk.
  #   FALSE: Disable this feature
  #   2: Enable 2 SIMs, single talk.
  #   Switch-ability:
  #   Non-switchable
  # Option Values:
  #   2: Enable 2 SIMs, single talk.
  #   3: Enable 3 SIMs, single talk.
  #   4: Enable 4 SIMs, single talk.
  #   FALSE: Disable this feature
  # Switch-ability:
  #   Non-switchable

GERAN_RELEASE_SUPPORT = GERAN_R11_SUPPORT
  # Description:
  #   The option is to switch different version of release for 2G modem
  # Option Values:
  #   GERAN_R4_SUPPORT: set the 2G MODEM to 3GPP R4 baseline
  #   GERAN_R5_SUPPORT: set the 2G MODEM to 3GPP R5 baseline
  #   GERAN_R6_SUPPORT: set the 2G MODEM to 3GPP R6 baseline
  #   GERAN_R99_SUPPORT: set the 2G MODEM to 3GPP R99 baseline
  # Switch-ability:
  #   Non-switchable

GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND = TRUE
  # Description:
  #   This feature makes PPP process UART data even if there is no FLC buffer available (ex: In 2G CS Call suspend PS Transfer, so FLC buffer run out)
  #   In this situation, PPP start to decode the UART data into a temp buffer, and if the decoded packet is a IP pac
  # Option Values:
  #   no: auto created - value no
  #   yes: auto created - value yes
  # Switch-ability:
  #   Non-switchable

GPRS_MAX_PDP_SUPPORT = 8
  # Description:
  #   Maximum simultaneous PDP contexts (2~7)
  # Option Values:
  #   1: Maximum simultaneous PDP contexts is one
  #   2: Maximum simultaneous PDP contexts is two
  #   3: Maximum simultaneous PDP contexts is three
  #   4: Maximum simultaneous PDP contexts is four
  #   5: Maximum simultaneous PDP contexts is five
  #   6: Maximum simultaneous PDP contexts is six
  #   7: Maximum simultaneous PDP contexts is seven
  # Switch-ability:
  #   Non-switchable

GPS_SUPPORT = SMART_PHONE_MODEM
  # Description:
  #   Mapping with SMART PHONE MODEM      # NONE, SMART_PHONE_MODEM
  # Option Values:
  #   NONE: disable release GPS for smart phone modem
  #   SMART_PHONE_MODEM: enable release GPS for smart phone modem
  # Switch-ability:
  #   Non-switchable

HIF_CCISM_SCP_SUPPORT = TRUE
  # Description:
  #   Description:
  #   For support hardware interface SCP CCISM
  #   Option Values:
  #   TRUE: Support SCP CCISM interface
  #   FALSE: Not support SCP CCISM interface
  #   Switch-ability:
  #   Non-switchable
  #   ----------------------------------------------------------------
  #   For Support SCP chip full load MD, need to set to TRUE. (MT6771 full load MD set to TRUE)
  # Option Values:
  #   FALSE: Not support SCP CCISM interface
  #   TRUE: Support SCP CCISM interface
  # Switch-ability:
  #   Non-switchable

HIF_CLDMA_SUPPORT = TRUE
  # Description:
  #   Used to enable CLDMA Core related components, CLDMACORE.
  # Option Values:
  #   FALSE: CLDMA core related components wiil not be built.
  #   TRUE: CLDMA core related components will be built.
  # Switch-ability:
  #   Non-switchable

ICUSB_SUPPORT = FALSE
  # Description:
  #   ICUSB feature is to support SIM+ card with CCID/MSDC/EEM class ability.
  #   ICUSB_SUPPORT = TRUE; enable ICUSB feature support
  #   ICUSB_SUPPORT = FALSE; disable ICUSB feature support
  # Option Values:
  #   FALSE: disable ICUSB feature support
  #   TRUE: enable ICUSB feature support
  # Switch-ability:
  #   Non-switchable

IDC_PTA_VERSION = IDC_PTA_DEFAULT
  # Description:
  #   each project will have different PTA version for IDC feature.
  #   IDC_PTA_DEFAULT: PTA version before 3.0
  #   IDC_PTA_3.0: PTA version 3.0
  #   IDC_PTA_5.0: PTA version 5.0
  # Option Values:
  #   IDC_PTA_3.0: PTA 3.0
  #   IDC_PTA_5.0: PTA 5.0
  #   IDC_PTA_DEFAULT: default PTA version
  # Switch-ability:
  #   Switchable

KAL_ASSERT_LEVEL = KAL_ASSERT_LEVEL3
  # Description:
  #   Setup KAL assert level
  #   3: for full debugging facility support
  #   0: for minimal debugging facility support
  # Option Values:
  #   KAL_ASSERT_LEVEL0: .
  #   KAL_ASSERT_LEVEL1: .
  #   KAL_ASSERT_LEVEL2: .
  #   KAL_ASSERT_LEVEL3: .
  #   KAL_ASSERT_LEVEL4: save entire CPU registers
  # Switch-ability:
  #   Non-switchable

KAL_DEBUG_LEVEL = NORMAL_DEBUG_KAL
  # Description:
  #   Control the major KAL debugging facility availability and behavior. More debugging facility consume more extra RAM footprint.
  #   
  #   Less debugging facility may suffer extra effort to locate root cause of issue.
  #   
  #   RICH_DEBUG_KAL > NORMAL_DEBUG_KAL > SLIM_DEBUG_KAL > RELEASE_KAL.
  #   
  #   Default Setting :  NORMAL_DEBUG_KAL
  # Option Values:
  #   NORMAL_DEBUG_KAL: .
  #   RELEASE_KAL: .
  #   RICH_DEBUG_KAL: .
  #   SLIM_DEBUG_KAL: .
  # Switch-ability:
  #   Non-switchable

KAL_HW_ITC_CUSTOM_LOG_SUPPORT = TRUE
  # Description:
  #   Turn on/off SWLA custom_logging in KAL_HW_ITC APIs
  # Option Values:
  #   FALSE: Disable custom_logging in KAL HW_ITC APIs
  #   TRUE: Enable custom_logging in KAL HW_ITC APIs
  # Switch-ability:
  #   Non-switchable

KAL_TRACE_OUTPUT = FULL
  # Description:
  #   This option is used to enable or disable the trace output for the concern of saving ROM size
  # Option Values:
  #   CUST_PARTIAL: Enable partial traces
  #   FULL: Enable all trace
  #   NONE: Disable all trace
  # Switch-ability:
  #   Switchable

KPALV_SUPPORT = TRUE
  # Description:
  #   keep-alive mechanism in MD
  # Option Values:
  #   FALSE: Disable Keep-alive in MD
  #   TRUE: Enable Keep-alive in MD
  # Switch-ability:
  #   Non-switchable

L1_EPSK_TX = TRUE
  # Description:
  #   Turn on/off this compile option may switch the function of EPSK modulation transmitter
  # Option Values:
  #   FALSE: EPSK TX disable
  #   TRUE: EPSK TX enable
  # Switch-ability:
  #   Non-switchable

LPP_EXT_SUPPORT = TRUE
  # Description:
  #   Determine if LTE LPP Extension supported.
  #   Note: LPP_EXT_SUPPORT can be turned on only if EUTRAN_MODE_SUPPORT and LPP_SUPPORT is defined.
  #   
  #   Option Values:
  #   TRUE: Enable LTE LPP Extension feature
  #   FALSE: Disable LTE LPP Extension feature
  #   
  #   The Smartphone Feature ID is  SPOID00000170
  # Option Values:
  #   no: auto created - value no
  #   yes: auto created - value yes
  # Switch-ability:
  #   Non-switchable

LPP_SUPPORT = CONTROL_PLANE
  # Description:
  #   Determine if LPP protocol is supported.
  #   Note: LPP_SUPPORT can be turned on only if EUTRAN_MODE_SUPPORT and at least one of AGPS_SUPPORT/LTE_OTDOA_SUPPORT/LTE_ECID_SUPPORT is defined.
  # Option Values:
  #   CONTROL_PLANE: Enable LPP protocol control plane
  #   NONE: Disable LPP feature
  # Switch-ability:
  #   Non-switchable

LTEA_FEATURE_SET = FULL
  # Description:
  #   to enable the capability of LTE-A features by NVRAM default value
  #   Option Values:
  #   STAGE1: Support LTE-A Stage1 features
  #   STAGE2: Support LTE-A Stage2 features (CA, EDDA)
  #   FULL: Support LTE-A full features (CA, EDDA, eMBMS, eICIC, feICIC, UL CoMP)(CA, EDDA)
  #   Switch-ability:
  #   Non-switchable
  # Option Values:
  #   FULL: Support LTE-A full features (CA, EDDA, eMBMS, eICIC, feICIC, UL CoMP)(CA, EDDA)
  #   STAGE1: Support LTE-A Stage1 features
  #   STAGE2: Support LTE-A Stage2 features (CA, EDDA)
  # Switch-ability:
  #   Non-switchable

LTE_ECID_SUPPORT = TRUE
  # Description:
  #   Determine if LTE ECID positioning is supported.
  #   Note: LTE_ECID_SUPPORT can be turned on only if EUTRAN_MODE_SUPPORT and LPP_SUPPORT is defined.
  # Option Values:
  #   FALSE: Disable LTE ECID positioning feature
  #   TRUE: Enable LTE ECID positioning feature
  # Switch-ability:
  #   Non-switchable

LTE_OTDOA_SUPPORT = TRUE
  # Description:
  #   Determine if LTE OTDOA positioning is supported.
  #   Note: LTE_OTDOA_SUPPORT can be turned on only if EUTRAN_MODE_SUPPORT and LPP_SUPPORT is defined.
  # Option Values:
  #   FALSE: Disable LTE OTDOA positioning feature
  #   TRUE: Enable LTE OTDOA positioning feature
  # Switch-ability:
  #   Non-switchable

LWA_SUPPORT = FALSE
  # Description:
  #   LTE Wifi Aggregation Support
  # Option Values:
  #   FALSE: Not Support LWA
  #   TRUE: Support LWA
  # Switch-ability:
  #   Non-switchable

MCU_PMU_DEFAUT_USER = 0
  # Description:
  #   Add a new option MCU_PMU_DEFAUT_USER for pmu to select default parking user.
  # Option Values:
  #   0: SYS
  #   1: SWLA
  #   2: EL1BD
  # Switch-ability:
  #   Non-switchable

MD_TCPIP_SUPPORT = TRUE
  # Description:
  #   Support TCPIP stack, it will create corresponding tasks and HISR, and enable related features.
  # Option Values:
  #   FALSE: Disable MD TCP/IP stack
  #   TRUE: Enable MD TCP/IP stack
  # Switch-ability:
  #   Non-switchable

MD_TCPIP_VERSION = NUCLEUS_V3
  # Description:
  #   TCPIP stack version.
  # Option Values:
  #   NUCLEUS_V3: Use 3.x as the version
  # Switch-ability:
  #   Non-switchable

MODEMRESERVEDSIZE_AUTOCONFIG = TRUE
  # Description:
  #   To define if image layout is able to be auto-adjusted
  # Option Values:
  #   FALSE: image layout is not able to be adjusted
  #   TRUE: image layout is able to be adjusted
  # Switch-ability:
  #   Non-switchable

MODEM_CARD = NONE
  # Description:
  #   Target is data card module.
  # Option Values:
  #   CS_CALL_DISABLE: Data card project, has ability to disable CS call
  #   FULL: Data card project
  #   NONE: Disable this feature
  # Switch-ability:
  #   Non-switchable

MTK_BT_CHIP = MTK_CONSYS_MT6771
  # Description:
  #   MTK_BT_CHIP
  # Option Values:
  #   MTK_CONSYS_MT6571: Need to support software BT codec (CVSD / mSBC).
  #   MTK_CONSYS_MT6572: Need to support software BT codec (CVSD / mSBC).
  #   MTK_CONSYS_MT6582: Need to support software BT codec (CVSD / mSBC).
  #   MTK_CONSYS_MT6592: Need to support software BT codec (CVSD / mSBC).
  #   MTK_CONSYS_MT6752: Need to support software BT codec (CVSD / mSBC).
  #   MTK_MT6620: Need to support BT phone call PCM interface.
  #   MTK_MT6622: Need to support BT phone call PCM interface.
  #   MTK_MT6626: Need to support BT phone call PCM interface.
  #   MTK_MT6628: Need to support BT phone call PCM interface.
  #   MTK_MT6630: Need to support BT phone call PCM interface.
  #   NONE: No BT phone call.
  # Switch-ability:
  #   Switchable

MTK_GWSD_MT_SUPPORT = FALSE
  # Description:
  #   Feature option for controlling Game With Smooth Data (GWSD)
  # Option Values:
  #   no: auto created - value no
  #   yes: auto created - value yes
  # Switch-ability:
  #   Non-switchable

MULTIPLE_IMS_SUPPORT = TRUE
  # Description:
  #   Description:
  #   Turn on/off multiple IMS feature
  #   Option Values:
  #   TRUE: Enable this feature
  #   FALSE: Disable this feature
  #   Switch-ability:
  #   Non-switchable
  # Option Values:
  #   FALSE: Turn off Muliple IMS feature
  #   TRUE: Turn on Muliple IMS feature
  # Switch-ability:
  #   Non-switchable

NAND_SUPPORT = FALSE
  # Description:
  #   To enable NAND flash support, please set NAND_SUPPORT as TRUE.
  # Option Values:
  #   no: auto created - value no
  #   yes: auto created - value yes
  # Switch-ability:
  #   Non-switchable

NVRAM_BIND_TO_CHIP_CIPHER = DISABLE
  # Description:
  #   This option enables NVRAM HW encryption/decryption on LIDs with the attribute "NVRAM_ATTR_MSP", e.g. SIM-ME-Lock.
  # Option Values:
  #   DISABLE: Disable NVRAM hardware encryption
  #   ENABLE: Enable NVRAM hardware encryption
  # Switch-ability:
  #   Switchable

OS_TICK_PERIOD_IN_US = 1000
  # Description:
  #   Set the OS tick period in micro second
  # Option Values:
  #   4615: For backward compatible, not suggested
  #   5000: Default OS Tick Period
  # Switch-ability:
  #   Non-switchable

PHB_ADDITIONAL_SUPPORT = TRUE
  # Description:
  #   USIM Phonebook Support
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   Switchable

PHB_FDN_ENTRY = 50
  # Description:
  #   Maximum fixed dial number in SIM card, its value must <=32
  # Option Values:
  #   NA: The value can be 1 to 32, must <=32
  # Switch-ability:
  #   Switchable

PHB_LN_ENTRY = 10
  # Description:
  #   Number of the call log with single log type from single SIM card, it &apos;s a range better no more than 100, suggestion to be 10, 20, 30, 40, 50, 60, 80, 100 and so on. Totol log num = PHB_LN_ENTRY * log type num * sim card num.
  # Option Values:
  #   10: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 10, total log num = 10 * log type num * sim card num.
  #   100: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 100, total log num = 100 * log type num * sim card num.
  #   20: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 20, total log num = 20 * log type num * sim card num.
  #   30: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 30, total log num = 30 * log type num * sim card num.
  #   40: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 40, total log num = 40 * log type num * sim card num.
  #   50: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 50, total log num = 50 * log type num * sim card num.
  #   60: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 60, total log num = 60 * log type num * sim card num.
  #   80: Number of call log with single log type from single SIM card, ex, The dialed call log from SIM1 is 80, total log num = 80 * log type num * sim card num.
  # Switch-ability:
  #   Non-switchable

PHB_PHONE_ENTRY = 10
  # Description:
  #   Maximum Phonebook entry in Phone,  #Switch-ability: [Any] -> [Any]
  # Option Values:
  #   NA: .
  # Switch-ability:
  #   Switchable

PHB_SIM_ENTRY = 1000
  # Description:
  #   Maximum Phonebook entry in SIM card.
  # Option Values:
  #   NA: .
  # Switch-ability:
  #   Switchable

PHB_SYNC = ON
  # Description:
  #   To enable/disable phonebook sync feature.
  # Option Values:
  #   OFF: Not support Sync from Phonebook
  #   ON: Support Sync from Phonebook
  # Switch-ability:
  #   Switchable

PLATFORM = MT6771
  # Description:
  #   Name of BB-chip.
  # Option Values:
  #   NA: N/A
  # Switch-ability:
  #   Non-switchable

PMIC = MT6358
  # Description:
  #   To specify which Power Management IC(PMIC) is used, or no PMIC.
  # Option Values:
  #   MT6223PMU: .
  #   MT6235PMU: .
  #   MT6236PMU: .
  #   MT6238PMU: .
  #   MT6253ELPMU: .
  #   MT6253PMU: .
  #   MT6255PMU: For MT6255 Usage
  #   MT6258PMU: .
  #   MT6276PMU: .
  #   MT6305: .
  #   MT6318: .
  #   MT6326: .
  #   MT6326_CCCI: .
  #   MT6573PMU: .
  #   NONE: No PMU/PMIC on PCB
  # Switch-ability:
  #   Non-switchable

PS_MCU_CLOCK = MCU_900M
  # Description:
  #   Specify PScore MCU clock rate
  # Option Values:
  #   MCU_775M: CPU normal operation frequency: 775MHz
  # Switch-ability:
  #   Non-switchable

R15_DEFLATE_UDC_SUPPORT = FALSE
  # Description:
  #   Support 3GPP R15 Deflate based UL Data Compression (UDC)
  # Option Values:
  #   FALSE: Not support R15 Deflate UDC
  #   TRUE: Support R15 Deflate UDC
  # Switch-ability:
  #   Non-switchable

R7R8_FULL_SET_SUPPORT = FALSE
  # Description:
  #   Description:
  #   This feature option is to turn ON some rare R7R8 capability indication, such as MACIIS, DRXInFACH, EnhancedCommonState, COMMON_EDCH, HSDSCH_CELL_CHNAGE_ENHANCED, CSoHS, UEA2_UIA2
  #   Option Values:
  #   ENABLE: Enable these feature's capability
  #   DISABLE: Disable this feature's capability
  #   Switch-ability:
  #   [FALSE] -> [TRUE]
  # Option Values:
  #   FALSE: Disable this feature
  #   TRUE: Enable this feature
  # Switch-ability:
  #   Non-switchable

REDUCE_HEADER_DEPTH = FALSE
  # Description:
  #   To collect used header files to one folder to reduce compiler's searching time.
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

RF_BYPASS = FALSE
  # Description:
  #   This feature is for AIQ/DIQ platform.
  #   TRUE : AIQ/DIQ platform - FPGA or EVB w/o RF
  #   FALSE : Normal platform - SP or EVB w/ RF
  # Option Values:
  #   FALSE: Disable RF_BYPASS
  #   TRUE: Enable RF_BYPASS
  # Switch-ability:
  #   Non-switchable

RF_DRDI_CAPABILITY_SUPPORT = TRUE
  # Description:
  #   RF_DRDI_CAPABILITY_SUPPORT = TRUE  
  #   Description: 
  #   Option Values: 
  #   TRUE:Set to TRUE if support DRDI. 
  #   FALSE:Set to FALSE if not support DRDI.
  # Option Values:
  #   FALSE: Set to FALSE if not support DRDI.
  #   TRUE: Set to TRUE if support DRDI.
  # Switch-ability:
  #   Non-switchable

RF_MODULE = MT6771_2G_MT6177_SP
  # Description:
  #   describe the RF module used in this project
  # Option Values:
  #   NA: the RF module used in this project
  # Switch-ability:
  #   Switchable

RX_POWER_OFFSET_SUPPORT = FALSE
  # Description:
  #   Offset compensates on 2G SACCH level, 3G RSCP, 4G RSRP are tuned by NV parameter and RSSI
  #   
  #   RX_POWER_OFFSET_SUPPORT = FALSE  
  #   Description: 
  #   Option Values: 
  #   TRUE:Set to TRUE if support RX_POWER_OFFSET_SUPPORT. 
  #   FALSE:Set to FALSE if not support RX_POWER_OFFSET_SUPPORT.
  # Option Values:
  #   FALSE: RX power offset support is NOT supported
  #   TRUE: RX power offset support is supported
  # Switch-ability:
  #   Non-switchable

SCC_FORCE_LOG_TO_SIB = FALSE
  # Description:
  #   to specify if all MCU/DSP logs are intended to be outputted via SIB, as a force option for convenience
  # Option Values:
  #   FALSE: Not forced (as is)
  #   TRUE: Forced to be outputted via SIB
  # Switch-ability:
  #   Non-switchable

SCC_SIB_SUPPORT = FALSE
  # Description:
  #   Enable SIB support (High speed logging interface) with SCC (SIB Control Channel) module included (since 6291)
  # Option Values:
  #   FALSE: Disable SIB logging
  #   TRUE: Enable SIB logging
  # Switch-ability:
  #   Non-switchable

SECURE_SUPPORT = FALSE
  # Description:
  #   Support security system
  # Option Values:
  #   FALSE: Non-secure load
  #   TRUE: Secure load
  # Switch-ability:
  #   Non-switchable

SECURE_VERSION = 1
  # Description:
  #   Support security system
  # Option Values:
  #   0: Secure version 0
  #   1: Secure version 1
  # Switch-ability:
  #   Switchable

SECURITY_FEATURE_TEST = FALSE
  # Description:
  #   Enable/Disable security feature test case
  # Option Values:
  #   FALSE: disable this feature
  #   TRUE: enable this feature
  # Switch-ability:
  #   N/A

SIM_SWTICH_CONTROLLER_MT6306 = FALSE
  # Description:
  #   enable MT6306 4SIM feature
  # Option Values:
  #   FALSE: disable 4SIM controller for MT6306
  #   TRUE: enable 4SIM controller for MT6306
  # Switch-ability:
  #   Switchable

SMART_PHONE_CORE = ANDROID_MODEM
  # Description:
  #   To distinguish if it is a smart phone MODEM makefile or a smart phone APP makefile. NONE means it is not a smart-phone make file
  # Option Values:
  #   ANDROID_MODEM: modem processor software load for Android smart phone
  #   MODEM_ONLY: in-house testing load running on modem processor
  #   NONE: .
  # Switch-ability:
  #   Non-switchable

SML_SUPPORT = TRUE
  # Description:
  #   SIM-ME lock support
  # Option Values:
  #   FALSE: Not support SIM-ME lock
  #   TRUE: Support SIM-ME lock
  # Switch-ability:
  #   Non-switchable

SMS_OVER_PS_SUPPORT = TRUE
  # Description:
  #   Wrap the functionality - "SMS over PS" - for switchable
  # Option Values:
  #   FALSE: Disable SMS send over PS
  #   TRUE: Enable SMS send over PS
  # Switch-ability:
  #   Non-switchable

SMS_PHONE_ENTRY = 50
  # Description:
  #   SMS Entry Number in NVRAM
  # Option Values:
  #   NA: SMS entities on NVRAM
  # Switch-ability:
  #   Switchable

SMS_R8_NATION_LANGUAGE = FALSE
  # Description:
  #   The feature option is to support Turkish special character encoding method which is defined in 3GPP 23.038 Release8.
  #   New SMS UDH IEI is introduced to indicate the encoding/decoding alphabet of special Turikish character.
  #   Using the new method, SMS can avoid to use UCS2 coding scheme when the special Turkish character is present in the message.
  # Option Values:
  #   FALSE: Disable SMS R8 Nation Language (ex: Turkey)
  #   TRUE: Enable SMS R8 Nation Language (ex: Turkey)
  # Switch-ability:
  #   Non-switchable

SMS_TOTAL_ENTRY = 100
  # Description:
  #   total number of SMS stored in SIM and NVRAM can be read
  # Option Values:
  #   NA: SMS entities on NVRAM+SIM
  # Switch-ability:
  #   Switchable

SSS_SUPPORT = SSS_LIB
  # Description:
  #   Modem internal security library
  # Option Values:
  #   SSS_LIB: .
  #   SSS_SOURCE: .
  # Switch-ability:
  #   Non-switchable

SUB_BOARD_VER = PCB01
  # Description:
  #   Sub-name of the PCB or EVB.
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

TASK_BATCH_SCHEDULING = TRUE
  # Description:
  #   Task Rescheduling for low power
  # Option Values:
  #   FALSE: Disable Option
  #   TRUE: Enable Option
  # Switch-ability:
  #   Non-switchable

TEST_LOAD_TYPE = NONE
  # Description:
  #   internal test load type
  # Option Values:
  #   BASIC: BASIC
  #   L1S: L1S
  #   NONE: NONE
  #   UDVT: UDVT
  # Switch-ability:
  #   Non-switchable

TST_WRITE_TO_FILE = FALSE
  # Description:
  #   enable tst outputting traces to files
  # Option Values:
  #   FALSE: Disable
  #   TRUE: Enable
  # Switch-ability:
  #   Switchable

TX_POWER_OFFSET_SUPPORT = FALSE
  # Description:
  #   Depend on this option to distinguish whether TX POWER OFFSET is supported or not.
  # Option Values:
  #   FALSE: TX POWER OFFSET is NOT supported
  #   TRUE: TX POWER OFFSET is supported
  # Switch-ability:
  #   Non-switchable

UL1_BCH_ROUND_ROBIN_WITH_PCH = TRUE
  # Description:
  #   new FO for enabling/disabling  3G BCH Round Robin feature
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

UMTS_RF_MODULE = MT6771_UMTS_FDD_MT6177
  # Description:
  #   This option is used specify which RF module is used in UL1D RF driver
  #   &quot;UL1D&quot; means UMTS Layer 1 Driver.
  # Option Values:
  #   MT6162: the RF module used in this project
  # Switch-ability:
  #   Non-switchable

UMTS_TDD128_RF_MODULE = MT6771_UMTS_TDD_MT6177
  # Description:
  #   Modem Capability
  # Option Values:
  #   NA: the RF module used in this project
  # Switch-ability:
  #   Non-switchable

USB_COM_PORT_SUPPORT = FALSE
  # Description:
  #   Open Com Port function
  # Option Values:
  #   FALSE: Disbale USB comport
  #   TRUE: Enable USB comport
  # Switch-ability:
  #   Non-switchable

USB_HS_SUPPORT = FALSE
  # Description:
  #   Customer can use this compileoption to decide USB2.0 or USB1.1. TRUE:: work in USB2.0
  # Option Values:
  #   FALSE: Disable USB High-Soeed mode (Run in Full Speed)
  #   TRUE: Enable USB High-Speed
  # Switch-ability:
  #   Non-switchable

USB_IN_META_SUPPORT = FALSE
  # Description:
  #   This option is used to turn on Meta mode bu using USB.
  # Option Values:
  #   FALSE: can only use UART
  #   TRUE: support by using USB
  # Switch-ability:
  #   Non-switchable

USB_MASS_STORAGE_CDROM_SUPPORT = FALSE
  # Description:
  #   enable USB mass storage feature
  # Option Values:
  #   N/A
  # Switch-ability:
  #   Non-switchable

USB_MASS_STORAGE_SUPPORT = FALSE
  # Description:
  #   enable USB mass storage feature
  # Option Values:
  #   FALSE: doesn't  support Mass Storage  function
  #   TRUE: Support USB mass storage function
  # Switch-ability:
  #   Non-switchable

USB_MBIM_SUPPORT = FALSE
  # Description:
  #   Used to enable USB MBIM device
  # Option Values:
  #   FALSE: Disable USB MBIM device
  #   TRUE: Enable USB MBIM device
  # Switch-ability:
  #   Non-switchable

USB_MSD_SUPPORT = FALSE
  # Description:
  #   Used to enable USB Mass Storage device.
  # Option Values:
  #   FALSE: USB Mass Storage module will not be built.
  #   TRUE: USB Mass Storage module will be built.
  # Switch-ability:
  #   Non-switchable

USB_RNDIS_SUPPORT = TRUE
  # Description:
  #   Used to enable USB RNDIS device
  # Option Values:
  #   FALSE: Disable USB CDC/ACM device
  #   TRUE: Enable USB CDC/ACM device
  # Switch-ability:
  #   Non-switchable

USE_1X_ONLY = FALSE
  # Description:
  #   Used for C2K Only for Modem
  # Option Values:
  #   FALSE: Not C2K Only
  #   TRUE: C2K Only
  # Switch-ability:
  #   Non-switchable

USE_GPS_TYPE = GPS_TYPE_EXTERNAL_ON_AP
  # Description:
  #   option to use GPS chip internal or external. For MTK C2K modem solution, always use external GPS chip.
  # Option Values:
  #   GPS_TYPE_EXTERNAL_ON_AP: GPS chip on AP side
  # Switch-ability:
  #   Non-switchable

USE_RUIM = TRUE
  # Description:
  #   TRUE: Device with SIM card
  #   FLASE: Device without SIM card
  # Option Values:
  #   FLASE: Device without SIM card
  #   TRUE: Device with SIM card
  # Switch-ability:
  #   Non-switchable


3G_B5_AND_B19_INDICATOR_SUPPORT = FALSE

BRANCH = LR12A.R3.MP

BUILD = BUILD_NO

CCCI_CCMNI_SUPPORT = FALSE

CUSTOM_CFLAGS = #-gdwarf-2

HW_VER = TK_MD_BASIC_HW

NVRAM_SUPPORT = TRUE

ORIGINAL_VERNO = MOLY.LR12A.R3.MP.V96.9

RAM_SUPPORT_TYPE = NONE

SERIAL_FLASH_SUPPORT = FALSE

SIM_MAX_RETRY_DETECT_CARD_COUNT = NA

VERNO = MOLY.LR12A.R3.MP.V96.9


# *************************************************************************
# TK MD Custom Feature Option Configuration
# *************************************************************************
TK_MD_CUS = NONE

# *************************************************************************
# Release Setting Section
# *************************************************************************
RELEASE_PACKAGE         = REL_CR_BASIC	# REL_CR_MMI_GPRS, REL_CR_MMI_GSM, REL_CR_L4_GPRS, REL_CR_L4_GSM REL_SUB_UAS_UMTS
RELEASE_PACKAGE_SUB_PS  = REL_SUB_PROTOCOL
RELEASE_PACKAGE_SUB_C2K = REL_SUB_C2K
############################################################

COM_DEFS_FOR_MT6771_2G_MT6177_SP = MT6177L_2G_RF
COM_DEFS_FOR_MT6771_UMTS_FDD_MT6177 = MT6177L_RF MT6177L_UMTS_FDD
COM_DEFS_FOR_MT6771_UMTS_TDD_MT6177 = MT6177L_RF MT6177L_UMTS_TDD
COM_DEFS_FOR_MT6771_LTE_MT6177 = MT6177L_RF MT6177L_LTE_RF

# *************************************************************************
# Common preprocessor definitions
# *************************************************************************

# *************************************************************************
# By project preprocessor definitions
# *************************************************************************




# *************************************************************************
# Component trace definition header files for custom release only
# *************************************************************************
# Customer can add new trace headers here for new modules
NEW_CUS_REL_TRACE_DEFS_MODEM =

# *************************************************************************
# Custom Release Component Configuration
# *************************************************************************
include make/common/rel/$(strip $(RELEASE_PACKAGE)).mak

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifneq ($(findstring REL_SUB_, $(strip $(RELEASE_PACKAGE))),)
    -include make/${CORE_ROOT}/rel/sub_ps/$(strip $(RELEASE_PACKAGE_SUB_PS)).mak
  endif
endif

-include make/common/rel/sub_c2k/$(strip $(RELEASE_PACKAGE_SUB_C2K)).mak
