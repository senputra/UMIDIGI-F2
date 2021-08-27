/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2015. All rights reserved.
*
* BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
* THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
* CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
* SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
* STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
* CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
* applicable license agreements with MediaTek Inc.
*/

#ifdef BUILD_LK
#include <string.h>
#include <platform/mt_gpio.h>
#include <platform/mt_pmic.h>
#include <platform/upmu_common.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#endif

#include "lcm_drv.h"

/* --------------------------------------------------------------------------- */
/* Local Constants */
/* --------------------------------------------------------------------------- */
#define FRAME_WIDTH                                     (1280)
#define FRAME_HEIGHT                                    (1920)

#define REGFLAG_DELAY             						0xFFE
#define REGFLAG_END_OF_TABLE      						0xFFF

static LCM_UTIL_FUNCS lcm_util = {
    .set_gpio_out = NULL,
};

#define SET_RESET_PIN(v) (lcm_util.set_reset_pin((v)))

#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))

/* --------------------------------------------------------------------------- */
/* Local Functions */
/* --------------------------------------------------------------------------- */
#define dsi_set_cmdq_V2(cmd, count, ppara, force_update) lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update) lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)                          lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)      lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)                           lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)   lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)
/* --------------------------------------------------------------------------- */
/* Local Constants */
/* --------------------------------------------------------------------------- */
struct LCM_setting_table {
    unsigned int cmd;
    unsigned char count;
    unsigned char para_list[64];
};

struct IC2848_setting_table {
    unsigned int cmd;
    unsigned char count;
    unsigned int para_list[64];
};

#define ITE_I2C_BUSNUM  I2C0
#define IT6112_SLAVE_ADDR_WRITE  0xAC
#define MIPITX_ADDR 0x56
#define MIPIRX_ADDR 0x5e
static struct mt_i2c_t it6112_i2c;

static int it6112_write_byte(u8 dev_addr,char addr, char value)
{
	int ret_code = I2C_OK;
	char write_data[2];
	char len;

	write_data[0] = addr;
	write_data[1] = value;

	it6112_i2c.id = ITE_I2C_BUSNUM;
	it6112_i2c.addr = dev_addr;
	it6112_i2c.mode = ST_MODE;
	it6112_i2c.speed = 100;
	len = 2;

	ret_code = i2c_write(&it6112_i2c, write_data, len);
	if(ret_code)
	printf("%s: i2c_write: ret_code: %d\n", __func__, ret_code);

	return ret_code;
}

static int it6112_read_byte(u8 dev_addr,char addr)
{
    int ret_code = I2C_OK;
	char len;
    u8 buffer[1], reg_value[1];
	it6112_i2c.id = ITE_I2C_BUSNUM;
	it6112_i2c.addr = dev_addr;
	it6112_i2c.mode = ST_MODE;
	it6112_i2c.speed = 100;
	len = 1;

	buffer[0] = addr;
	ret_code = i2c_write(&it6112_i2c, buffer, len);
	ret_code = i2c_read(&it6112_i2c, reg_value, len);
	//printf("%s: i2c_read: ret_code: %d\n", __func__, ret_code);
    return reg_value[0];
}

int it6112_mipi_tx_write(char offset, char data)
{
#ifdef IGNORE_I2C
	pr_err("[it6112_mipi_tx_write] dev_addr = mipiTx offset[0x%x] = 0x%x \n", offset, data);

	return 0;
#endif

	return it6112_write_byte(MIPITX_ADDR,offset,data);
}

int it6112_mipi_tx_read(char offset)
{
#ifdef IGNORE_I2C
	pr_err("[it6112_mipi_tx_read] dev_addr = mipiTx offset[0x%x]  \n", offset);

	return 0;
#endif
	//it6112_i2c_read_byte(MIPITX_ADDR, offset, &dataBuffer);
	return it6112_read_byte(MIPITX_ADDR,offset);
}

int it6112_mipi_tx_set_bits(char offset, char mask, char data)
{
	char temp;
	temp = it6112_mipi_tx_read(offset);
	temp = (temp & ((~mask) & 0xFF)) + (mask & data);

	return it6112_mipi_tx_write(offset, temp);
}

int it6112_mipi_rx_write(char offset, char data)
{
#ifdef IGNORE_I2C
	pr_err("[it6112_mipi_rx_write] dev_addr = mipiRx offset[0x%x] = 0x%x \n", offset, data);

return 0;
#endif
	return it6112_write_byte(MIPIRX_ADDR,offset,data);
}

char it6112_mipi_rx_read(char offset)
{

#ifdef IGNORE_I2C

	pr_err("[it6112_mipi_rx_read] dev_addr = mipiRx offset[0x%x] \n", offset);

	return 0;
#endif

	return it6112_read_byte(MIPIRX_ADDR,offset);
}

int it6112_mipi_rx_set_bits(char offset, char mask, char data)
{
	char temp;

	temp = it6112_mipi_rx_read(offset);

	temp = (temp & ((~mask) & 0xFF)) + (mask & data);
	return it6112_mipi_rx_write(offset, temp);
}

enum MIPI_VIDEO_TYPE {
	RGB_24b = 0x3E,
	RGB_30b = 0x0D,
	RGB_36b = 0x1D,
	RGB_18b = 0x1E,
	RGB_18b_L = 0x2E,
	YCbCr_16b = 0x2C,
	YCbCr_20b = 0x0C,
	YCbCr_24b = 0x1C,
};

#define EnMBPM 1
#define MPVidType RGB_24b
#define MPLaneSwap 0
#define MPPNSwap 0
#define SkipStg 4
#define HSSetNum 3
#define Reg4laneMode 0
#define InvRxMCLK 1
#define InvTxMCLK 0

struct it6112_device {
	char enable_mipi_rx_bypass_mode;
	char enable_mipi_rx_lane_swap;
	char enable_mipi_rx_pn_swap;
	char enable_mipi_4_lane_mode;
	char mipi_rx_video_type;
	char enable_mipi_rx_mclk_inverse;
	char enable_mipi_tx_mclk_inverse;
	char mipi_rx_skip_stg;
	char mipi_rx_hs_set_number;
	char revision;
	int rclk;
} ;

static LCM_UTIL_FUNCS lcm_util;

#define MDELAY(n)       (lcm_util.mdelay(n))
#define UDELAY(n)       (lcm_util.udelay(n))

void it6112_calc_rclk(struct it6112_device *it6112)
{
     int rddata, i, sum;
     //int t10usint;

     sum = 0;
     for(i = 0; i < 5; i++) {
         it6112_mipi_rx_set_bits(0x94, 0x80, 0x80); // Enable RCLK 100ms count
         MDELAY(100);
         it6112_mipi_rx_set_bits(0x94, 0x80, 0x00); // Disable RCLK 100ms count

         rddata = it6112_mipi_rx_read(0x95);
         rddata += (it6112_mipi_rx_read(0x96)<<8);
         rddata += (it6112_mipi_rx_read(0x97)<<16);

         sum += rddata;
     }
     sum /= 5;

     it6112->rclk = sum/100;
     //t10usint = RCLK/100;

     printf("RCLK=%dMHz\n", it6112->rclk/1000);
}

void it6112_calc_mclk(struct it6112_device *it6112)
{
 int i, rddata, sum, mclk;

     sum = 0;
     for(i=0; i<5; i++) {
         it6112_mipi_rx_set_bits(0x9B, 0x80, 0x80);
         MDELAY(1);
         it6112_mipi_rx_set_bits(0x9B, 0x80, 0x00);

         rddata = it6112_mipi_rx_read(0x9A);
         rddata = ((it6112_mipi_rx_read(0x9B)&0x0F)<<8)+rddata;

         sum += rddata;
     }

     sum /= 5;

     //MCLK = 13500*2048/sum;
      //MCLK = 27000*2048/sum;
      mclk = it6112->rclk*2048/sum;
     printf("MCLK = %dMHz\n", mclk/1000);
}

void it6112_mipi_show_mrec()
{
     int MHSW, MHFP, MHBP, MHDEW, MHBlank;
     int MVSW, MVFP, MVBP, MVDEW, MVTotal, MHVR2nd, MVFP2nd;

     MHSW  = it6112_mipi_rx_read(0x52);
     MHSW += (it6112_mipi_rx_read(0x53) & 0x3F) << 8;

     MHFP  = it6112_mipi_rx_read(0x50);
     MHFP += (it6112_mipi_rx_read(0x51) & 0x3F) << 8;


     MHBP  = it6112_mipi_rx_read(0x54);
     MHBP += (it6112_mipi_rx_read(0x55) & 0x3F) << 8;

     MHDEW  = it6112_mipi_rx_read(0x56);
     MHDEW += (it6112_mipi_rx_read(0x57) & 0x3F) << 8;

     MHVR2nd  = it6112_mipi_rx_read(0x58);
     MHVR2nd += (it6112_mipi_rx_read(0x59)&0x3F)<<8;

     MHBlank = MHFP + MHSW + MHBP;

     MVSW  = it6112_mipi_rx_read(0x5A);
     MVSW += (it6112_mipi_rx_read(0x5B) & 0x1F) << 8;

     MVFP  = it6112_mipi_rx_read(0x58);
     MVFP += (it6112_mipi_rx_read(0x59) & 0x1F) << 8;


     MVBP  = it6112_mipi_rx_read(0x5C);
     MVBP += (it6112_mipi_rx_read(0x5D) & 0x1F) << 8;

     MVDEW  = it6112_mipi_rx_read(0x5E);
     MVDEW += (it6112_mipi_rx_read(0x5F) & 0x1F) << 8;

     MVFP2nd  = it6112_mipi_rx_read(0x62);
     MVFP2nd += (it6112_mipi_rx_read(0x63)&0x3F)<<8;

     MVTotal = MVFP + MVSW + MVBP + MVDEW ;

     printf("\n\rMHFP    = %d", MHFP);
     printf("\n\rMHSW    = %d", MHSW);
     printf("\n\rMHBP    = %d", MHBP);
     printf("\n\rMHDEW   = %d", MHDEW);
     printf("\n\rMHVR2nd = %d", MHVR2nd);
     printf("\n\rMHBlank  = %d", MHBlank);

     printf("\n\rMVFP    = %d", MVFP);
     printf("\n\rMVSW    = %d", MVSW);
     printf("\n\rMVBP   = %d", MVBP);
     printf("\n\rMVDEW   = %d", MVDEW);
     printf("\n\rMVFP2nd   = %d", MVFP2nd);
     printf("\n\rMVTotal = %d", MVTotal);
}

void it6112_init_config(struct it6112_device *it6112)
{
	it6112->enable_mipi_rx_bypass_mode = EnMBPM;
	it6112->enable_mipi_rx_lane_swap = MPLaneSwap;
	it6112->enable_mipi_rx_pn_swap = MPPNSwap;
	it6112->enable_mipi_4_lane_mode = Reg4laneMode;
	it6112->mipi_rx_video_type = MPVidType;
	it6112->enable_mipi_rx_mclk_inverse = InvRxMCLK;
	it6112->enable_mipi_tx_mclk_inverse = InvTxMCLK;
	it6112->mipi_rx_skip_stg = SkipStg;
	it6112->mipi_rx_hs_set_number = HSSetNum;
    printf("it6112_init_config end\n");
}

void it6112_mipi_rx_init(struct it6112_device *it6112)
{
	//Enable MPRX interrupt
	it6112_mipi_rx_write(0x09, 0xFF);
	it6112_mipi_rx_write(0x0A, 0xFF);
	it6112_mipi_rx_write(0x0B, 0x3F);
	it6112_mipi_rx_write(0x05, 0x03);
	it6112_mipi_rx_write(0x05, 0x00);

	// Setup INT Pin: Active Low
	it6112_mipi_rx_set_bits(0x0C, 0x0F, (it6112->enable_mipi_rx_lane_swap << 3)|(it6112->enable_mipi_rx_pn_swap << 2)| 0x03);
	it6112_mipi_rx_set_bits(0x11, 0x01, it6112->enable_mipi_rx_mclk_inverse);
	it6112_mipi_rx_set_bits(0x18, 0xff, 0x43);
	it6112_mipi_rx_set_bits(0x19, 0xf3, 0x03);
	it6112_mipi_rx_set_bits(0x20, 0xf7, 0x03);
	it6112_mipi_rx_set_bits(0x21, 0x08, 0x08);
	it6112_mipi_rx_set_bits( 0x44, 0x22, 0x22);
	it6112_mipi_rx_write(0x27, it6112->mipi_rx_video_type);
	it6112_mipi_rx_write(0x72, 0x07);
	it6112_mipi_rx_set_bits(0x8A, 0x07, 0x02);//0x03
	it6112_mipi_rx_set_bits(0xA0, 0x01, 0x01);
	if (it6112->enable_mipi_4_lane_mode)
		it6112_mipi_rx_set_bits(0x80, 0x3F, 0x03);
	else
		it6112_mipi_rx_set_bits(0x80, 0x3F, 0x07);

	printf("\n\rit6112 MPRX initial done!");
}

void it6112_mipi_tx_init(struct it6112_device *it6112)
{
	// MPTX Software Reset
	it6112_mipi_tx_set_bits(0x05, 0x01, 0x01); /*software reset all, include RX!! */
	it6112_mipi_tx_set_bits(0x05, 0x20, 0x20); //hold tx first

	MDELAY(1);

	it6112_mipi_tx_set_bits(0x10, 0x02, (it6112->enable_mipi_tx_mclk_inverse << 1));
	it6112_mipi_tx_set_bits(0x11, 0x08, (it6112->enable_mipi_4_lane_mode << 3));
	it6112_mipi_tx_set_bits(0x24, 0x0f, 0x01);
	//it6112_mipi_tx_set_bits(0x22, 0xff, 0x28);
	it6112_mipi_tx_set_bits(0x3C, 0x20, 0x20);
	it6112_mipi_tx_set_bits(0x44, 0x04, 0x04);
	it6112_mipi_tx_set_bits(0x45, 0x0f, 0x03);/* adjust tx low power state's command time interval */
	it6112_mipi_tx_set_bits(0x47, 0xf0, 0x10);
	it6112_mipi_tx_set_bits(0xB0, 0xFF, 0x27);
	MDELAY(1);

	printf("\n\rit6112 MPTX initial done!");
}

enum dcs_cmd_name {
	EXIT_SLEEP_MODE_SET_DISPLAY_ON,
	ENTER_SLEEP_MODE,
	SET_DISPLAY_OFF,
	EXIT_SLEEP_MODE,
	SET_DISPLAY_ON,
	LONG_WRITE_CMD,
	LONG_WRITE_CMD1,
};

struct dcs_setting_entry {
	enum dcs_cmd_name cmd_name;
	u8 cmd;
	u8 count;
	u8 para_list[30]; // count maximum to 30.
};

struct dcs_setting_entry_v2 {
	u8 cmd;
	u8 count;
	u8 para_list[30]; // count maximum to 30.
};

static struct dcs_setting_entry dcs_setting_table[] = {
	{EXIT_SLEEP_MODE_SET_DISPLAY_ON, 0x87, 8, {0x05, 0x11, 0x00, 0x36, 0x05, 0x29, 0x00, 0x1C}}, // panel enabled
	{ENTER_SLEEP_MODE, 0x87, 4, {0x05, 0x10, 0x00, 0x2C}},//ENTER SLEEP MODE
	{SET_DISPLAY_OFF, 0x87, 4, {0x05, 0x28, 0x00, 0x06}},//SET DISPLAY OFF
	{EXIT_SLEEP_MODE, 0x87, 4, {0x05, 0x11, 0x00, 0x36}},//EXIT SLEEP MODE
	{SET_DISPLAY_ON, 0x87, 4, {0x05, 0x29, 0x00, 0x1C}},//SET DISPLAY ON
	{LONG_WRITE_CMD, 0x87, 3, {0x50, 0x5A, 0x09}},//LONG_WRITE_CMD
	{LONG_WRITE_CMD1, 0x87, 17, {0x80, 0x5A, 0x51, 0xB5, 0x2A, 0x6C, 0x35, 0x4B, 0x01, 0x40, 0xE1, 0x0D, 0x82, 0x20, 0x08, 0x30, 0x03}}//LONG_WRITE_CMD1
	// to add other commands here.
};

static struct dcs_setting_entry_v2  init_code[] = {
#if 1
     //{0x87, 4, {0x05, 0xFF, 0x01, 0x1c}},
     {0x87, 4, {0x05, 0xB0, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xB2, 0x02, 0x1c}},
     {0x87, 4, {0x05, 0xB3, 0x03, 0x1c}},
     {0x87, 4, {0x05, 0xB4, 0xF0, 0x1c}},
     {0x87, 4, {0x05, 0xB6, 0x03, 0x1c}},
     {0x87, 4, {0x05, 0xB7, 0x02, 0x1c}},
     {0x87, 4, {0x05, 0xBA, 0x43, 0x1c}},
     {0x87, 4, {0x05, 0xCB, 0x1C, 0x1c}},
     {0x87, 4, {0x05, 0xCD, 0x1C, 0x1c}},
     {0x87, 4, {0x05, 0xCF, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xD0, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xF0, 0x92, 0x1c}},
     {0x87, 4, {0x05, 0xB0, 0x01, 0x1c}},
     {0x87, 4, {0x05, 0xC0, 0x25, 0x1c}},
     {0x87, 4, {0x05, 0xC1, 0x25, 0x1c}},
     {0x87, 4, {0x05, 0xC2, 0x02, 0x1c}},
     {0x87, 4, {0x05, 0xC3, 0x02, 0x1c}},
     {0x87, 4, {0x05, 0xC4, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xC5, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xC6, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xC7, 0x25, 0x1c}},
     {0x87, 4, {0x05, 0xC8, 0x08, 0x1c}},
     {0x87, 4, {0x05, 0xC9, 0x08, 0x1c}},
     {0x87, 4, {0x05, 0xCA, 0x06, 0x1c}},
     {0x87, 4, {0x05, 0xCB, 0x06, 0x1c}},
     {0x87, 4, {0x05, 0xCC, 0x0C, 0x1c}},
     {0x87, 4, {0x05, 0xCD, 0x0C, 0x1c}},
     {0x87, 4, {0x05, 0xCE, 0x0A, 0x1c}},
     {0x87, 4, {0x05, 0xCF, 0x0A, 0x1c}},
     {0x87, 4, {0x05, 0xD0, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xD1, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xD6, 0x25, 0x1c}},
     {0x87, 4, {0x05, 0xD7, 0x25, 0x1c}},
     {0x87, 4, {0x05, 0xD8, 0x01, 0x1c}},
     {0x87, 4, {0x05, 0xD9, 0x01, 0x1c}},
     {0x87, 4, {0x05, 0xDA, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xDB, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xDC, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xDD, 0x25, 0x1c}},
     {0x87, 4, {0x05, 0xDE, 0x07, 0x1c}},
     {0x87, 4, {0x05, 0xDF, 0x07, 0x1c}},
     {0x87, 4, {0x05, 0xE0, 0x05, 0x1c}},
     {0x87, 4, {0x05, 0xE1, 0x05, 0x1c}},
     {0x87, 4, {0x05, 0xE2, 0x0B, 0x1c}},
     {0x87, 4, {0x05, 0xE3, 0x0B, 0x1c}},
     {0x87, 4, {0x05, 0xE4, 0x09, 0x1c}},
     {0x87, 4, {0x05, 0xE5, 0x09, 0x1c}},
     {0x87, 4, {0x05, 0xE6, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xE7, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xEC, 0xC0, 0x1c}},

     {0x87, 4, {0x05, 0xB0, 0x02, 0x1c}},
     {0x87, 4, {0x05, 0xC0, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xC1, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xC2, 0x0F, 0x1c}},
     {0x87, 4, {0x05, 0xC3, 0x17, 0x1c}},
     {0x87, 4, {0x05, 0xC4, 0x29, 0x1c}},
     {0x87, 4, {0x05, 0xC5, 0x27, 0x1c}},
     {0x87, 4, {0x05, 0xC6, 0x28, 0x1c}},
     {0x87, 4, {0x05, 0xC7, 0x28, 0x1c}},
     {0x87, 4, {0x05, 0xC8, 0x26, 0x1c}},
     {0x87, 4, {0x05, 0xC9, 0x23, 0x1c}},
     {0x87, 4, {0x05, 0xCA, 0x28, 0x1c}},
     {0x87, 4, {0x05, 0xCB, 0x27, 0x1c}},
     {0x87, 4, {0x05, 0xCC, 0x28, 0x1c}},
     {0x87, 4, {0x05, 0xCD, 0x25, 0x1c}},
     {0x87, 4, {0x05, 0xCE, 0x2F, 0x1c}},
     {0x87, 4, {0x05, 0xCF, 0x2D, 0x1c}},
     {0x87, 4, {0x05, 0xD0, 0x32, 0x1c}},
     {0x87, 4, {0x05, 0xD1, 0x32, 0x1c}},
     {0x87, 4, {0x05, 0xD2, 0x34, 0x1c}},
     {0x87, 4, {0x05, 0xD3, 0x32, 0x1c}},
     {0x87, 4, {0x05, 0xD4, 0x3A, 0x1c}},
     {0x87, 4, {0x05, 0xD5, 0x1F, 0x1c}},
     {0x87, 4, {0x05, 0xD6, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xD7, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xD8, 0x0F, 0x1c}},
     {0x87, 4, {0x05, 0xD9, 0x17, 0x1c}},
     {0x87, 4, {0x05, 0xDA, 0x29, 0x1c}},
     {0x87, 4, {0x05, 0xDB, 0x23, 0x1c}},
     {0x87, 4, {0x05, 0xDC, 0x2B, 0x1c}},
     {0x87, 4, {0x05, 0xDD, 0x2C, 0x1c}},
     {0x87, 4, {0x05, 0xDE, 0x2A, 0x1c}},
     {0x87, 4, {0x05, 0xDF, 0x25, 0x1c}},
     {0x87, 4, {0x05, 0xE0, 0x28, 0x1c}},
     {0x87, 4, {0x05, 0xE1, 0x27, 0x1c}},
     {0x87, 4, {0x05, 0xE2, 0x34, 0x1c}},
     {0x87, 4, {0x05, 0xE3, 0x33, 0x1c}},
     {0x87, 4, {0x05, 0xE4, 0x3D, 0x1c}},
     {0x87, 4, {0x05, 0xE5, 0x39, 0x1c}},
     {0x87, 4, {0x05, 0xE6, 0x3E, 0x1c}},
     {0x87, 4, {0x05, 0xE7, 0x36, 0x1c}},
     {0x87, 4, {0x05, 0xE8, 0x34, 0x1c}},
     {0x87, 4, {0x05, 0xE9, 0x32, 0x1c}},
     {0x87, 4, {0x05, 0xEA, 0x3A, 0x1c}},
     {0x87, 4, {0x05, 0xEB, 0x1F, 0x1c}},

     {0x87, 4, {0x05, 0xB0, 0x03, 0x1c}},
     {0x87, 4, {0x05, 0xC8, 0x09, 0x1c}},
     {0x87, 4, {0x05, 0xC9, 0x07, 0x1c}},
     {0x87, 4, {0x05, 0xC5, 0x23, 0x1c}},
     {0x87, 4, {0x05, 0xDE, 0x23, 0x1c}},
     {0x87, 4, {0x05, 0xCA, 0x41, 0x1c}},
     {0x87, 4, {0x05, 0xCB, 0x34, 0x1c}},
     {0x87, 4, {0x05, 0xB0, 0x06, 0x1c}},
     {0x87, 4, {0x05, 0xB8, 0xA5, 0x1c}},
     {0x87, 4, {0x05, 0xC0, 0xA5, 0x1c}},
     {0x87, 4, {0x05, 0xC2, 0xA3, 0x1c}},
     {0x87, 4, {0x05, 0xC6, 0x6B, 0x1c}},
     {0x87, 4, {0x05, 0xD5, 0x32, 0x1c}},
     {0x87, 4, {0x05, 0xB0, 0x07, 0x1c}},
     {0x87, 4, {0x05, 0xB1, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xB2, 0x04, 0x1c}},
     {0x87, 4, {0x05, 0xB3, 0x0B, 0x1c}},
     {0x87, 4, {0x05, 0xB4, 0x19, 0x1c}},
     {0x87, 4, {0x05, 0xB5, 0x28, 0x1c}},
     {0x87, 4, {0x05, 0xB6, 0x37, 0x1c}},
     {0x87, 4, {0x05, 0xB7, 0x55, 0x1c}},
     {0x87, 4, {0x05, 0xB8, 0x71, 0x1c}},
     {0x87, 4, {0x05, 0xB9, 0xAE, 0x1c}},
     {0x87, 4, {0x05, 0xBA, 0xF1, 0x1c}},
     {0x87, 4, {0x05, 0xBB, 0x7A, 0x1c}},
     {0x87, 4, {0x05, 0xBC, 0xF9, 0x1c}},
     {0x87, 4, {0x05, 0xBD, 0xFD, 0x1c}},
     {0x87, 4, {0x05, 0xBE, 0x7A, 0x1c}},
     {0x87, 4, {0x05, 0xBF, 0xFB, 0x1c}},
     {0x87, 4, {0x05, 0xC0, 0x3B, 0x1c}},
     {0x87, 4, {0x05, 0xC1, 0x7E, 0x1c}},
     {0x87, 4, {0x05, 0xC2, 0x9F, 0x1c}},
     {0x87, 4, {0x05, 0xC3, 0xC0, 0x1c}},
     {0x87, 4, {0x05, 0xC4, 0xD1, 0x1c}},
     {0x87, 4, {0x05, 0xC5, 0xE0, 0x1c}},
     {0x87, 4, {0x05, 0xC6, 0xF1, 0x1c}},
     {0x87, 4, {0x05, 0xC7, 0xF8, 0x1c}},
     {0x87, 4, {0x05, 0xC8, 0xFC, 0x1c}},
     {0x87, 4, {0x05, 0xC9, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xCA, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xCB, 0x05, 0x1c}},
     {0x87, 4, {0x05, 0xCC, 0x6B, 0x1c}},
     {0x87, 4, {0x05, 0xCD, 0xFF, 0x1c}},
     {0x87, 4, {0x05, 0xCE, 0xFF, 0x1c}},
     {0x87, 4, {0x05, 0xB0, 0x08, 0x1c}},
     {0x87, 4, {0x05, 0xB1, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xB2, 0x04, 0x1c}},
     {0x87, 4, {0x05, 0xB3, 0x0B, 0x1c}},
     {0x87, 4, {0x05, 0xB4, 0x19, 0x1c}},
     {0x87, 4, {0x05, 0xB5, 0x27, 0x1c}},
     {0x87, 4, {0x05, 0xB6, 0x35, 0x1c}},
     {0x87, 4, {0x05, 0xB7, 0x51, 0x1c}},
     {0x87, 4, {0x05, 0xB8, 0x6A, 0x1c}},
     {0x87, 4, {0x05, 0xB9, 0xA4, 0x1c}},
     {0x87, 4, {0x05, 0xBA, 0xE5, 0x1c}},
     {0x87, 4, {0x05, 0xBB, 0x66, 0x1c}},
     {0x87, 4, {0x05, 0xBC, 0xE0, 0x1c}},
     {0x87, 4, {0x05, 0xBD, 0xE4, 0x1c}},
     {0x87, 4, {0x05, 0xBE, 0x5B, 0x1c}},
     {0x87, 4, {0x05, 0xBF, 0xD7, 0x1c}},
     {0x87, 4, {0x05, 0xC0, 0x14, 0x1c}},
     {0x87, 4, {0x05, 0xC1, 0x52, 0x1c}},
     {0x87, 4, {0x05, 0xC2, 0x71, 0x1c}},
     {0x87, 4, {0x05, 0xC3, 0x90, 0x1c}},
     {0x87, 4, {0x05, 0xC4, 0xA0, 0x1c}},
     {0x87, 4, {0x05, 0xC5, 0xAF, 0x1c}},
     {0x87, 4, {0x05, 0xC6, 0xC0, 0x1c}},
     {0x87, 4, {0x05, 0xC7, 0xC7, 0x1c}},
     {0x87, 4, {0x05, 0xC8, 0xCC, 0x1c}},
     {0x87, 4, {0x05, 0xC9, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xCA, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xCB, 0x05, 0x1c}},
     {0x87, 4, {0x05, 0xCC, 0x6B, 0x1c}},
     {0x87, 4, {0x05, 0xCD, 0xFF, 0x1c}},
     {0x87, 4, {0x05, 0xCE, 0xFF, 0x1c}},
     {0x87, 4, {0x05, 0xB0, 0x09, 0x1c}},
     {0x87, 4, {0x05, 0xB1, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xB2, 0x03, 0x1c}},
     {0x87, 4, {0x05, 0xB3, 0x09, 0x1c}},
     {0x87, 4, {0x05, 0xB4, 0x16, 0x1c}},
     {0x87, 4, {0x05, 0xB5, 0x23, 0x1c}},
     {0x87, 4, {0x05, 0xB6, 0x2F, 0x1c}},
     {0x87, 4, {0x05, 0xB7, 0x48, 0x1c}},
     {0x87, 4, {0x05, 0xB8, 0x67, 0x1c}},
     {0x87, 4, {0x05, 0xB9, 0xA6, 0x1c}},
     {0x87, 4, {0x05, 0xBA, 0xE9, 0x1c}},
     {0x87, 4, {0x05, 0xBB, 0x74, 0x1c}},
     {0x87, 4, {0x05, 0xBC, 0xF0, 0x1c}},
     {0x87, 4, {0x05, 0xBD, 0xF4, 0x1c}},
     {0x87, 4, {0x05, 0xBE, 0x70, 0x1c}},
     {0x87, 4, {0x05, 0xBF, 0xEC, 0x1c}},
     {0x87, 4, {0x05, 0xC0, 0x29, 0x1c}},
     {0x87, 4, {0x05, 0xC1, 0x67, 0x1c}},
     {0x87, 4, {0x05, 0xC2, 0x84, 0x1c}},
     {0x87, 4, {0x05, 0xC3, 0xA1, 0x1c}},
     {0x87, 4, {0x05, 0xC4, 0xB1, 0x1c}},
     {0x87, 4, {0x05, 0xC5, 0xC0, 0x1c}},
     {0x87, 4, {0x05, 0xC6, 0xCC, 0x1c}},
     {0x87, 4, {0x05, 0xC7, 0xD4, 0x1c}},
     {0x87, 4, {0x05, 0xC8, 0xD8, 0x1c}},
     {0x87, 4, {0x05, 0xC9, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xCA, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xCB, 0x05, 0x1c}},
     {0x87, 4, {0x05, 0xCC, 0x6B, 0x1c}},
     {0x87, 4, {0x05, 0xCD, 0xFF, 0x1c}},
     {0x87, 4, {0x05, 0xCE, 0xFF, 0x1c}},
     {0x87, 4, {0x05, 0xB0, 0x0A, 0x1c}},
     {0x87, 4, {0x05, 0xB1, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xB2, 0x04, 0x1c}},
     {0x87, 4, {0x05, 0xB3, 0x0B, 0x1c}},
     {0x87, 4, {0x05, 0xB4, 0x19, 0x1c}},
     {0x87, 4, {0x05, 0xB5, 0x28, 0x1c}},
     {0x87, 4, {0x05, 0xB6, 0x37, 0x1c}},
     {0x87, 4, {0x05, 0xB7, 0x55, 0x1c}},
     {0x87, 4, {0x05, 0xB8, 0x71, 0x1c}},
     {0x87, 4, {0x05, 0xB9, 0xAE, 0x1c}},
     {0x87, 4, {0x05, 0xBA, 0xF1, 0x1c}},
     {0x87, 4, {0x05, 0xBB, 0x7A, 0x1c}},
     {0x87, 4, {0x05, 0xBC, 0xF9, 0x1c}},
     {0x87, 4, {0x05, 0xBD, 0xFD, 0x1c}},
     {0x87, 4, {0x05, 0xBE, 0x7A, 0x1c}},
     {0x87, 4, {0x05, 0xBF, 0xFB, 0x1c}},
     {0x87, 4, {0x05, 0xC0, 0x3B, 0x1c}},
     {0x87, 4, {0x05, 0xC1, 0x7E, 0x1c}},
     {0x87, 4, {0x05, 0xC2, 0x9F, 0x1c}},
     {0x87, 4, {0x05, 0xC3, 0xC0, 0x1c}},
     {0x87, 4, {0x05, 0xC4, 0xD1, 0x1c}},
     {0x87, 4, {0x05, 0xC5, 0xE0, 0x1c}},
     {0x87, 4, {0x05, 0xC6, 0xF1, 0x1c}},
     {0x87, 4, {0x05, 0xC7, 0xF8, 0x1c}},
     {0x87, 4, {0x05, 0xC8, 0xFC, 0x1c}},
     {0x87, 4, {0x05, 0xC9, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xCA, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xCB, 0x05, 0x1c}},
     {0x87, 4, {0x05, 0xCC, 0x6B, 0x1c}},
     {0x87, 4, {0x05, 0xCD, 0xFF, 0x1c}},
     {0x87, 4, {0x05, 0xCE, 0xFF, 0x1c}},
     {0x87, 4, {0x05, 0xB0, 0x0B, 0x1c}},
     {0x87, 4, {0x05, 0xB1, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xB2, 0x04, 0x1c}},
     {0x87, 4, {0x05, 0xB3, 0x0B, 0x1c}},
     {0x87, 4, {0x05, 0xB4, 0x19, 0x1c}},
     {0x87, 4, {0x05, 0xB5, 0x27, 0x1c}},
     {0x87, 4, {0x05, 0xB6, 0x35, 0x1c}},
     {0x87, 4, {0x05, 0xB7, 0x51, 0x1c}},
     {0x87, 4, {0x05, 0xB8, 0x6A, 0x1c}},
     {0x87, 4, {0x05, 0xB9, 0xA4, 0x1c}},
     {0x87, 4, {0x05, 0xBA, 0xE5, 0x1c}},
     {0x87, 4, {0x05, 0xBB, 0x66, 0x1c}},
     {0x87, 4, {0x05, 0xBC, 0xE0, 0x1c}},
     {0x87, 4, {0x05, 0xBD, 0xE4, 0x1c}},
     {0x87, 4, {0x05, 0xBE, 0x5B, 0x1c}},
     {0x87, 4, {0x05, 0xBF, 0xD7, 0x1c}},
     {0x87, 4, {0x05, 0xC0, 0x14, 0x1c}},
     {0x87, 4, {0x05, 0xC1, 0x52, 0x1c}},
     {0x87, 4, {0x05, 0xC2, 0x71, 0x1c}},
     {0x87, 4, {0x05, 0xC3, 0x90, 0x1c}},
     {0x87, 4, {0x05, 0xC4, 0xA0, 0x1c}},
     {0x87, 4, {0x05, 0xC5, 0xAF, 0x1c}},
     {0x87, 4, {0x05, 0xC6, 0xC0, 0x1c}},
     {0x87, 4, {0x05, 0xC7, 0xC7, 0x1c}},
     {0x87, 4, {0x05, 0xC8, 0xCC, 0x1c}},
     {0x87, 4, {0x05, 0xC9, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xCA, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xCB, 0x05, 0x1c}},
     {0x87, 4, {0x05, 0xCC, 0x6B, 0x1c}},
     {0x87, 4, {0x05, 0xCD, 0xFF, 0x1c}},
     {0x87, 4, {0x05, 0xCE, 0xFF, 0x1c}},
     {0x87, 4, {0x05, 0xB0, 0x0C, 0x1c}},
     {0x87, 4, {0x05, 0xB1, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xB2, 0x03, 0x1c}},
     {0x87, 4, {0x05, 0xB3, 0x09, 0x1c}},
     {0x87, 4, {0x05, 0xB4, 0x16, 0x1c}},
     {0x87, 4, {0x05, 0xB5, 0x23, 0x1c}},
     {0x87, 4, {0x05, 0xB6, 0x2F, 0x1c}},
     {0x87, 4, {0x05, 0xB7, 0x48, 0x1c}},
     {0x87, 4, {0x05, 0xB8, 0x67, 0x1c}},
     {0x87, 4, {0x05, 0xB9, 0xA6, 0x1c}},
     {0x87, 4, {0x05, 0xBA, 0xE9, 0x1c}},
     {0x87, 4, {0x05, 0xBB, 0x74, 0x1c}},
     {0x87, 4, {0x05, 0xBC, 0xF0, 0x1c}},
     {0x87, 4, {0x05, 0xBD, 0xF4, 0x1c}},
     {0x87, 4, {0x05, 0xBE, 0x70, 0x1c}},
     {0x87, 4, {0x05, 0xBF, 0xEC, 0x1c}},
     {0x87, 4, {0x05, 0xC0, 0x29, 0x1c}},
     {0x87, 4, {0x05, 0xC1, 0x67, 0x1c}},
     {0x87, 4, {0x05, 0xC2, 0x84, 0x1c}},
     {0x87, 4, {0x05, 0xC3, 0xA1, 0x1c}},
     {0x87, 4, {0x05, 0xC4, 0xB1, 0x1c}},
     {0x87, 4, {0x05, 0xC5, 0xC0, 0x1c}},
     {0x87, 4, {0x05, 0xC6, 0xCC, 0x1c}},
     {0x87, 4, {0x05, 0xC7, 0xD4, 0x1c}},
     {0x87, 4, {0x05, 0xC8, 0xD8, 0x1c}},
     {0x87, 4, {0x05, 0xC9, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xCA, 0x00, 0x1c}},
     {0x87, 4, {0x05, 0xCB, 0x05, 0x1c}},
     {0x87, 4, {0x05, 0xCC, 0x6B, 0x1c}},
     {0x87, 4, {0x05, 0xCD, 0xFF, 0x1c}},
     {0x87, 4, {0x05, 0xCE, 0xFF, 0x1c}},
#endif
};

int get_dcs_ecc(int dcshead)

{
  int Q0, Q1, Q2, Q3, Q4, Q5;

    Q0 = ((dcshead>> 0)&(0x01)) ^  ((dcshead>> 1)&(0x01)) ^ ((dcshead>> 2)&(0x01)) ^ ((dcshead>> 4)&(0x01)) ^ ((dcshead>> 5)&(0x01)) ^

        ((dcshead>> 7)&(0x01)) ^  ((dcshead>>10)&(0x01)) ^ ((dcshead>>11)&(0x01)) ^ ((dcshead>>13)&(0x01)) ^ ((dcshead>>16)&(0x01)) ^

                                ((dcshead>>20)&(0x01)) ^  ((dcshead>>21)&(0x01)) ^ ((dcshead>>22)&(0x01)) ^ ((dcshead>>23)&(0x01)) ;

   Q1 = ((dcshead>> 0)&(0x01)) ^  ((dcshead>> 1)&(0x01)) ^ ((dcshead>> 3)&(0x01)) ^ ((dcshead>> 4)&(0x01)) ^ ((dcshead>> 6)&(0x01)) ^

        ((dcshead>>8)&(0x01))  ^  ((dcshead>>10)&(0x01)) ^ ((dcshead>>12)&(0x01)) ^ ((dcshead>>14)&(0x01)) ^ ((dcshead>>17)&(0x01)) ^

                                ((dcshead>>20)&(0x01)) ^  ((dcshead>>21)&(0x01)) ^ ((dcshead>>22)&(0x01)) ^ ((dcshead>>23)&(0x01)) ;

   Q2 = ((dcshead>> 0)&(0x01)) ^  ((dcshead>> 2)&(0x01)) ^ ((dcshead>> 3)&(0x01)) ^ ((dcshead>> 5)&(0x01)) ^ ((dcshead>> 6)&(0x01)) ^

        ((dcshead>>9)&(0x01))  ^  ((dcshead>>11)&(0x01)) ^ ((dcshead>>12)&(0x01)) ^ ((dcshead>>15)&(0x01)) ^ ((dcshead>>18)&(0x01)) ^

                                ((dcshead>>20)&(0x01)) ^  ((dcshead>>21)&(0x01)) ^ ((dcshead>>22)&(0x01))  ;

   Q3 = ((dcshead>> 1)&(0x01)) ^  ((dcshead>> 2)&(0x01)) ^ ((dcshead>> 3)&(0x01)) ^ ((dcshead>> 7)&(0x01)) ^ ((dcshead>>8)&(0x01)) ^

        ((dcshead>>9)&(0x01))  ^  ((dcshead>>13)&(0x01)) ^ ((dcshead>>14)&(0x01)) ^ ((dcshead>>15)&(0x01)) ^ ((dcshead>>19)&(0x01)) ^

                                ((dcshead>>20)&(0x01)) ^  ((dcshead>>21)&(0x01)) ^ ((dcshead>>23)&(0x01))  ;

   Q4 = ((dcshead>> 4)&(0x01)) ^  ((dcshead>> 5)&(0x01)) ^ ((dcshead>> 6)&(0x01)) ^ ((dcshead>> 7)&(0x01)) ^ ((dcshead>>8)&(0x01)) ^

        ((dcshead>>9)&(0x01))  ^  ((dcshead>>16)&(0x01)) ^ ((dcshead>>17)&(0x01)) ^ ((dcshead>>18)&(0x01)) ^ ((dcshead>>19)&(0x01)) ^

                                ((dcshead>>20)&(0x01)) ^  ((dcshead>>22)&(0x01)) ^ ((dcshead>>23)&(0x01))  ;

   Q5 = ((dcshead>>10)&(0x01)) ^  ((dcshead>>11)&(0x01)) ^ ((dcshead>>12)&(0x01)) ^ ((dcshead>>13)&(0x01)) ^ ((dcshead>>14)&(0x01)) ^

        ((dcshead>>15)&(0x01)) ^  ((dcshead>>16)&(0x01)) ^ ((dcshead>>17)&(0x01)) ^ ((dcshead>>18)&(0x01)) ^ ((dcshead>>19)&(0x01)) ^

                                ((dcshead>>21)&(0x01)) ^  ((dcshead>>22)&(0x01)) ^ ((dcshead>>23)&(0x01))  ;

//   printf("Q0= %X Q1=%X\n", Q0, Q1);

   return (Q0 + (Q1<<1) + (Q2<<2) + (Q3<<3) + (Q4<<4) + (Q5<<5)) ;

}

void it6112_mipi_write_short_dcs_para(enum dcs_cmd_name cmd_name)
{
        int short_cmd = 0, i;

        short_cmd = dcs_setting_table[cmd_name].para_list[0] | dcs_setting_table[cmd_name].para_list[1] << 8 |
                    dcs_setting_table[cmd_name].para_list[2] << 16;
        dcs_setting_table[cmd_name].para_list[3] = get_dcs_ecc(short_cmd);

        //printf(("\n\rcmd_name: %d", dcs_setting_table[cmd_name].cmd_name));

        /*for (i = 0; i < dcs_setting_table[cmd_name].count; i++) {
                printf(("  para[%d]:0x%02x", i, dcs_setting_table[cmd_name].para_list[i]));
        }
        printf(("\n"));*/

        for (i = 0; i < dcs_setting_table[cmd_name].count; i++)
                it6112_mipi_tx_write(0x73, dcs_setting_table[cmd_name].para_list[i]);

        it6112_mipi_tx_write(0x74, 0x40 | dcs_setting_table[cmd_name].count);
        it6112_mipi_tx_write(0x75, dcs_setting_table[cmd_name].cmd);
}

void it6112_mipi_write_dcs_cmds(enum dcs_cmd_name start, int count)
{
        u8 i, enable_force_lp_mode = !!(it6112_mipi_tx_read(0x05) & 0x20);

        if (enable_force_lp_mode)
                it6112_mipi_tx_set_bits(0x70, 0x04, 0x04);

        it6112_mipi_tx_write(0x3D, 0x00);
        it6112_mipi_tx_write(0x3E, enable_force_lp_mode ? 0x00 : 0x10);
        it6112_mipi_tx_write(0x3F, enable_force_lp_mode ? 0x30 : 0x90);

        for (i = start; i < start + count; i++) {
                it6112_mipi_write_short_dcs_para(i);
        }
        MDELAY(10);

        if (enable_force_lp_mode)
                it6112_mipi_tx_set_bits(0x70, 0x04, 0x00);

        MDELAY(20);
}
void it6112_mipi_write_dcs_cmds_v2(struct dcs_setting_entry_v2 *init_cmd, unsigned int cmd_index)
{
        int short_cmd = 0;
        u8 i, enable_force_lp_mode = !!(it6112_mipi_tx_read(0x05) & 0x20);

         if (enable_force_lp_mode)
                it6112_mipi_tx_set_bits(0x70, 0x04, 0x04);

        it6112_mipi_tx_write(0x3D, 0x00);
        it6112_mipi_tx_write(0x3E, enable_force_lp_mode ? 0x00 : 0x10);
        it6112_mipi_tx_write(0x3F, enable_force_lp_mode ? 0x30 : 0x90);

        short_cmd = init_cmd[cmd_index].para_list[0] | init_cmd[cmd_index].para_list[1] << 8 |
                    init_cmd[cmd_index].para_list[2] << 16;
        init_cmd[cmd_index].para_list[3] = get_dcs_ecc(short_cmd);

        /*for (i = 0; i < init_cmd[cmd_index].count; i++) {
                printf(("  para[%d]:0x%02x\n", i, init_cmd[cmd_index].para_list[i]));
        }*/

        for (i = 0; i < init_cmd[cmd_index].count; i++)
                it6112_mipi_tx_write(0x73, init_cmd[cmd_index].para_list[i]);

        it6112_mipi_tx_write(0x74, 0x40 | init_cmd[cmd_index].count);
        it6112_mipi_tx_write(0x75, init_cmd[cmd_index].cmd);
}

void it6112_mipi_write_dcs_cmds_v3()
{
        u8 enable_force_lp_mode = !!(it6112_mipi_tx_read(0x05) & 0x20);

        MDELAY(10);

        if (enable_force_lp_mode)
                it6112_mipi_tx_set_bits(0x70, 0x04, 0x00);

        MDELAY(20);
}

static void it6112_push_table(struct dcs_setting_entry_v2 *init_code, unsigned int count)
{
	unsigned int i;
    unsigned int cmd;

    for(i = 0; i < count; i++)
    {
        cmd = init_code[i].cmd;
        switch (cmd)
        {
            case REGFLAG_DELAY:
                MDELAY(init_code[i].count);
                break;
            case REGFLAG_END_OF_TABLE:
                break;
            default:
				it6112_mipi_write_dcs_cmds_v2(init_code, i);
				break;
       	}
    }
}

void it6112_mipi_set_output(struct it6112_device *it6112)
{
        it6112_calc_rclk(it6112);
        it6112_calc_mclk(it6112);
        it6112_mipi_tx_set_bits(0x11, 0x80, 0x80);
        MDELAY(1);
        //it6112_mipi_write_dcs_cmds(EXIT_SLEEP_MODE_SET_DISPLAY_ON, 1); // enable panel output
        //test
        //it6112_mipi_write_dcs_cmds(1, 4);
//default do not push lcm initial code
       if (0)
     	{
        it6112_push_table(init_code, sizeof(init_code) / sizeof(struct dcs_setting_entry_v2));
        MDELAY(10);
        it6112_mipi_write_dcs_cmds_v3();
      }
        it6112_mipi_write_dcs_cmds(EXIT_SLEEP_MODE, 1);
        MDELAY(100);
        it6112_mipi_write_dcs_cmds(SET_DISPLAY_ON, 1);
        //it6112_mipi_write_dcs_long_cmd(LONG_WRITE_CMD);//long command example
        MDELAY(1);
        it6112_mipi_tx_set_bits(0x11, 0x80, 0x00);
        MDELAY(1);
        it6112_mipi_tx_write(0x05, 0xfe);
        it6112_mipi_tx_write(0x05, 0x00);
}

unsigned int it6112_revision_identify(struct it6112_device *it6112)
{
	if( it6112_mipi_tx_read(0x00) != 0x54 || it6112_mipi_tx_read(0x01) != 0x49 ||
	    it6112_mipi_tx_read(0x02) != 0x12 || it6112_mipi_tx_read(0x03) != 0x61) {
		printf(("\n\rError: Can not find IT6112B0 Device !"));
		return 0;
	}
	it6112->revision = it6112_mipi_tx_read(0x04);

	return 1;
}

void it6112_mipi_power_on()
{
	it6112_mipi_tx_set_bits(0x06, 0x02, 0x00);//Video Clock Domain Reset
	MDELAY(1);
	it6112_mipi_rx_set_bits(0x05, 0x0F, 0x00);
	it6112_mipi_tx_set_bits(0x05, 0xCC, 0x00);//tx mclk still hold
	MDELAY(1);
	printf("\n\rit6112 mipi power on");
}

void it6112_mipi_power_off()
{
	it6112_mipi_write_dcs_cmds(SET_DISPLAY_OFF,1);
	MDELAY(100);
	it6112_mipi_write_dcs_cmds(ENTER_SLEEP_MODE,1);
	it6112_mipi_tx_set_bits(0x05, 0xFE, 0xFE);
	it6112_mipi_rx_set_bits(0x05, 0x03, 0x03);
	it6112_mipi_tx_set_bits(0x06, 0x02, 0x02);
	printf("\n\rit6112 mipi power off");
}

static struct it6112_device it6112_dev;
void it6112_init(void)
{
	struct it6112_device *it6112;
	//u32 i;

	it6112 = &it6112_dev;
	it6112->enable_mipi_rx_bypass_mode = EnMBPM;
	it6112->enable_mipi_rx_lane_swap = MPLaneSwap;
	it6112->enable_mipi_rx_pn_swap = MPPNSwap;
	it6112->enable_mipi_4_lane_mode = Reg4laneMode;
	it6112->mipi_rx_video_type = MPVidType;
	it6112->enable_mipi_rx_mclk_inverse = InvRxMCLK;
	it6112->enable_mipi_tx_mclk_inverse = InvTxMCLK;
	it6112->mipi_rx_skip_stg = SkipStg;
	it6112->mipi_rx_hs_set_number = HSSetNum;

  if (!it6112_revision_identify(it6112))
		return;

	it6112_init_config(it6112);
	it6112_mipi_power_on();
	it6112_mipi_rx_init(it6112);
	it6112_mipi_tx_init(it6112);
	it6112_mipi_set_output(it6112);
}

/* --------------------------------------------------------------------------- */
/* LCM Driver Implementations */
/* --------------------------------------------------------------------------- */

#ifdef GPIO_LCM_RST
#define GPIO_LCD_RST_EN      GPIO_LCM_RST
#else
#define GPIO_LCD_RST_EN      0xFFFFFFFF
#endif

#ifdef GPIO_LCD_PWR
#define GPIO_LCD_PWR_EN      GPIO_LCM_RST
#else
#define GPIO_LCD_PWR_EN      0xFFFFFFFF
#endif

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
	memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}

static void lcm_get_params(LCM_PARAMS *params)
{
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type = LCM_TYPE_DSI;

	params->width = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;

	params->dsi.mode = SYNC_PULSE_VDO_MODE;//BURST_VDO_MODE

	/* DSI */
	/* Command mode setting */
	params->dsi.LANE_NUM = LCM_FOUR_LANE;
	/* The following defined the fomat for data coming from LCD engine. */
	params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq = LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding = LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format = LCM_DSI_FORMAT_RGB888;

	params->dsi.packet_size = 256;
	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;
	/* Video mode setting */
	//params->dsi.intermediat_buffer_num 		= 0;	/* This para should be 0 at video mode */

	params->dsi.vertical_sync_active = 2;
	params->dsi.vertical_backporch = 20;
	params->dsi.vertical_frontporch = 20;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 4;
	params->dsi.horizontal_backporch = 80; //80; //chg by mtk for lcm crash anda project 20161228
	params->dsi.horizontal_frontporch = 20;  //48; //chg by mtk for lcm crash anda project 20161228
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;

	params->dsi.PLL_CLOCK = 510;
	params->dsi.cont_clock = 1;
	params->dsi.ssc_disable = 1;
	params->dsi.HS_PRPR = 0x07;

}

static void lcm_set_gpio_output(unsigned int GPIO, unsigned int output)
{
	if(GPIO == 0xFFFFFFFF)
	{
	#ifdef BUILD_LK
		printf("[LK/LCM] GPIO_LCD_RST_EN =  0x%x \n",GPIO_LCD_RST_EN);
	#elif (defined BUILD_UBOOT)
	#else
	#endif
		return;
	}

	mt_set_gpio_mode(GPIO, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO, (output>0)? GPIO_OUT_ONE: GPIO_OUT_ZERO);
}

static void lcm_init(void)
{
#ifdef BUILD_LK
    printf("%s, lk\n", __func__);
#else
    printk("%s, kernel\n", __func__);
#endif

	lcm_set_gpio_output(GPIO_LCD_RST_EN, 0);
	lcm_set_gpio_output(GPIO_LCD_PWR_EN, 0);
	MDELAY(10);
	lcm_set_gpio_output(GPIO_LCD_PWR_EN, 1);
	MDELAY(5);
	lcm_set_gpio_output(GPIO_LCD_RST_EN, 1);
	MDELAY(10);
	lcm_set_gpio_output(GPIO_LCD_RST_EN, 0);
	MDELAY(10);
	lcm_set_gpio_output(GPIO_LCD_RST_EN, 1);
	MDELAY(10);
	it6112_init();
}

static void lcm_suspend(void)
{
#ifndef BUILD_LK
	it6112_mipi_power_off();
	MDELAY(20);
	lcm_set_gpio_output(GPIO_LCD_RST_EN, 0);
	MDELAY(10);
	lcm_set_gpio_output(GPIO_LCD_PWR_EN, 0);
	MDELAY(20);
#endif
}

static void lcm_resume(void)
{
#ifndef BUILD_LK
	lcm_init();
#endif
}

LCM_DRIVER it6112_sample_dsi_vdo_lcm_drv = {
	.name = "it6112_sample_dsi_vdo_lcm_drv",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
};
