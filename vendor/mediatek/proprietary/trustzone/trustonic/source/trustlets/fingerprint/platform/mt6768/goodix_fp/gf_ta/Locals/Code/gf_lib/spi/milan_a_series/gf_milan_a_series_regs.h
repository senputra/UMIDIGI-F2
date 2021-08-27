/*
* Copyright (C) 2013-2018, Shenzhen Huiding Technology Co., Ltd.
* All Rights Reserved.
*/

#ifndef __GF_MILAN_A_SERIES_REGS_H__
#define __GF_MILAN_A_SERIES_REGS_H__


#define GF_MILAN_A_SERIES_FW_VERSION_ADDR          (0x0800)
#define GF_MILAN_A_SERIES_ESD_ADDR                 (0x0830)
#define GF_MILAN_A_SERIES_MODE_ADDR                (0x0834)
#define GF_MILAN_A_SERIES_SAMPLING_PAUSE_ADDR      (0x0840)
#define GF_MILAN_A_SERIES_IRQ_STATUS_ADDR     (0x0837)
#define GF_MILAN_A_SERIES_IRQ_CLEAR_ADDR     (0x0836)
#define GF_MILAN_A_SERIES_IRQ_RW_ADDR     (0x0836)
#define GF_MILAN_A_SERIES_FINGERON_STATUS_ADDR     (0x083E)

#define GF_MILAN_A_SERIES_DUMMY_ADDR               (0x0838)
#define GF_MILAN_A_SERIES_CFG_ADDR     (0x0842)
#define GF_MILAN_A_SERIES_FW_ADDR     (0x2000)
#define GF_MILAN_A_SERIES_CFG_FRESH_ADDR     (0x08D8)

#define GF_MILAN_A_SERIES_HOLD_RELEASE_MCU_ADDR     (0x014E)
#define GF_MILAN_A_SERIES_ENABLE_SPI_RAM_ADDR     (0x0146)
#define GF_MILAN_A_SERIES_HOLD_CHIP_ID_ADDR     (0x0142)
#define GF_MILAN_A_SERIES_FIFO_STATUS_ADDR     (0x5204)
#define GF_MILAN_A_SERIES_FIFO_DATA_ADDR     (0x5202)
#define GF_MILAN_A_SERIES_DATA_READY_STATUS_ADDR     (0x5018)
#define GF_MILAN_A_SERIES_KEY_STATUS_ADDR     (0x083B)
#define GF_MILAN_A_SERIES_TEMP_STATUS_ADDR     (0x083C)
#define GF_MILAN_A_SERIES_GSC_BASE_ADDR     (0x08B2)

#define GF_MILAN_A_SERIES_TEMPRATURE_DAC_BASE_ADDR     (0x0972)

#define GF_MILAN_A_SERIES_TOUCH_KEY_RAWDATA     (0x0A60)
#define GF_MILAN_A_SERIES_TOUCH_KEY_BASE        (0x09D4)
#define GF_MILAN_A_SERIES_TOUCH_KEY_STATUS      (0x099C)

#define GF_MILAN_A_SERIES_REISSUE_KEY_DOWN_WHEN_ENTRY_FF_MODE_ADDR     (0x0832)
#define GF_MILAN_A_SERIES_REISSUE_KEY_DOWN_WHEN_ENTRY_IMAGE_MODE_ADDR     (0x0833)
// milan c only
#define GF_MILAN_C_READY_STATUS_ADDR     (0x5018)

/* otp info register */
#define GF_MILAN_A_SERIES_OTP_INFO_CONTROL    (0x4300)
#define GF_MILAN_A_SERIES_OTP_INFO_OTP0_ADDR    (0x4302)
#define GF_MILAN_A_SERIES_OTP_INFO_OTP1_ADDR    (0x4308)
#define GF_MILAN_A_SERIES_OTP_INFO_DATA    (0x4304)
#define GF_MILAN_A_SERIES_OTP_INFO_LENGTH    (64)

#define GF_MILAN_A_SERIES_OTP_CHIP_TYPE_LOW    (0x10)
#define GF_MILAN_A_SERIES_OTP_CHIP_TYPE_HIGH    (0x11)
#define GF_MILAN_A_SERIES_OTP_CHIP_TYPE_LENGTH    (2)

#define GF_MILAN_A_SERIES_OTP_CLOCK    (0x12)
#define GF_MILAN_A_SERIES_OTP_CLOCK_LENGTH    (2)
#define GF_MILAN_A_SERIES_OTP_CLOCK_CHECKSUM    (0x1D)
#define GF_MILAN_A_SERIES_OTP_CP    (0x00)
#define GF_MILAN_A_SERIES_OTP_CP_LENGTH    (0x08)

#define GF_MILAN_A_SERIES_OTP_CLOCK_CALIBRATION_REG   (0x4226)
#define GF_MILAN_A_SERIES_OTP_WDT_CALIBRATION_REG    (0x4228)
#define GF_MILAN_A_SERIES_OTP_RETRY   (10)

/* temperature register */
#define GF_MILAN_A_SERIES_TEMPERATURE_CONTROL    (0x0812)
#define GF_MILAN_A_SERIES_TEMPERATURE_DA_TM_CODE    (0x0184)

/* DAC&R and HBD info */
#define GF_MILAN_A_SERIES_OTP_HBD_START   (0x14)
#define GF_MILAN_A_SERIES_OTP_HBD_LENGTH   (9)
#define GF_MILAN_A_SERIES_OTP_DACR_START   (0x20)
#define GF_MILAN_A_SERIES_OTP_DACR_LENGTH   (21)
#define GF_MILAN_A_SERIES_OTP_DACR_HBD_CHECKSUM   (0x1F)

#define GF_MILAN_A_SERIES_OTP_HBD_GSC_LED0_DRV    (0x18)
#define GF_MILAN_A_SERIES_OTP_HBD_GSC_BASE_L    (0x19)
#define GF_MILAN_A_SERIES_OTP_HBD_GSC_BASE_H    (0x1A)
#define GF_MILAN_A_SERIES_OTP_HBD_PIXEL_CANCEL    (0x1B)
#define GF_MILAN_A_SERIES_OTP_HBD_LED0_DRV    (0x1C)

#define GF_MILAN_A_SERIES_HBD_SWITCH_ADDR    (0x08B0)
#define GF_MILAN_A_SERIES_HBD_CONFIG_ADDR    (0x08C4)
#define GF_MILAN_A_SERIES_HBD_STEP_ADDR    (0x08CE)
#define GF_MILAN_A_SERIES_HBD_LED0_DRV_ADDR    (0x08D0)
#define GF_MILAN_A_SERIES_HBD_CONFIG_RESET_ADDR    (0x08B4)
#define GF_MILAN_A_SERIES_HBD_STEP_RESET_ADDR    (0x08C2)
#define GF_MILAN_A_SERIES_HBD_LED0_DRV_RESET_ADDR    (0x08BE)
//define for pixel test

#define GF_MILAN_A_SERIES_TCODE_ADDR     (0x088E)
#define GF_MILAN_A_SERIES_DAC1_START_ADDR      (0x0898)  //DAC1_1 -- DAC1_4
#define GF_MILAN_A_SERIES_DAC12_BIT9_ADDR      (0x089D)
#define GF_MILAN_A_SERIES_DAC2_START_ADDR      (0x089E)  //DAC2_1 -- DAC2_4
#define GF_MILAN_A_SERIES_DAC3_START_ADDR      (0x08A2)  //DAC3_1 -- DAC3_4
#define GF_MILAN_A_SERIES_DAC3_BIT9_ADDR      (0x08A6)

#define GF_MILAN_A_SERIES_CHECKSUM_ADDR      (0x093E)

#define GF_MILAN_A_VENDOR_OPT1         (0x423C)
#define GF_MILAN_A_VENDOR_OPT2         (0x4234)

#define GF_MILAN_A_GPIO_IN         (0x12A)

#endif /*__GF_MILAN_A_SERIES_REGS_H__ */
