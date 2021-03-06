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
*/

#include <reg.h>
#include <latch.h>
#include <debug.h>
#include <mt_reg_base.h>
#include <aee_platform_debug.h>
#include <dfd.h>

static unsigned int timeout_infra;
static unsigned int timeout_peri;

void no_need_dump(void)
{
	return;
}

static unsigned long preisys_dump_offset[] = {
	0x508, /* PERIBUS_DBG0 */
	0x50c, /* PERIBUS_DBG1 */
	0x510, /* PERIBUS_DBG2 */
	0x514, /* PERIBUS_DBG3 */
	0x518, /* PERIBUS_DBG4 */
	0x51c, /* PERIBUS_DBG5 */
	0x520, /* PERIBUS_DBG6 */
	0x524, /* PERIBUS_DBG7 */
	0x528, /* PERIBUS_DBG8 */
	0x52c, /* PERIBUS_DBG9 */
	0x530, /* PERIBUS_DBG10 */
	0x534, /* PERIBUS_DBG11 */
	0x538, /* PERIBUS_DBG12 */
	0x53c, /* PERIBUS_DBG13 */
	0x580, /* PERIBUS_DBG14 */
	0x584, /* PERIBUS_DBG15 */
	0x588, /* PERIBUS_DBG16 */
	0x58c, /* PERIBUS_DBG17 */
	0x590, /* PERIBUS_DBG18 */
	0x594, /* PERIBUS_DBG19 */
	0x598, /* PERIBUS_DBG20 */
};

int plt_lastbus_is_timeout(const struct plt_cfg_bus_latch *self)
{
	unsigned int ctrl;
	unsigned long infra_base = INFRACFG_AO_BASE;
	unsigned long peri_base = PERICFG_BASE;

	if (!self) {
		dprintf(CRITICAL, "%s:%d: self is Null\n",
			__func__, __LINE__);
		return 0;
	}

	/* workaround for timeout bit lost */
	timeout_infra = (readl(infra_base + 0x514) & 0x00000700)? 1 : 0;
	timeout_peri = (readl(infra_base + 0x514) & 0x00070000)? 1 : 0;

	timeout_infra |= (readl(infra_base + self->infrasys_offsets.bus_infra_ctrl) & 0x1);
	timeout_peri |= (readl(peri_base + self->perisys_offsets.bus_peri_r1) & 0x1);
	ctrl = timeout_infra | timeout_peri;

	return ctrl;
}

int plt_lastbus_dump(const struct plt_cfg_bus_latch *self,
					 char *buf, int *wp)
{
	unsigned int i;
	unsigned long infra_base = INFRACFG_AO_BASE;
	unsigned long peri_base = PERICFG_BASE;

	if (timeout_infra)
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[LAST BUS] INFRASYS TIMEOUT:\n");

	if (timeout_peri)
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[LAST BUS] PERISYS TIMEOUT:\n");

	/* INFRA_AO_DBG_STA */
	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "%08x\n",
		       readl(infra_base + 0x514));

	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[LAST BUS] === \n");


	/* infrabus_dbg_in_0 */
	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "%08x\n",
		       readl(infra_base + self->infrasys_offsets.bus_infra_mask_l));

	/* infrabus_dbg_mask_2 */
	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "%08x\n",
		       readl(infra_base + self->infrasys_offsets.bus_infra_mask_h));

	/* infrabus_dbg_in_1 */
	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "%08x\n",
		       readl(infra_base + self->infrasys_offsets.bus_infra_ctrl));

	if (self->num_infrasys_mon != 0) {
		for (i = 0; i <= self->num_infrasys_mon-1; ++i)
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "%08x\n",
				       readl(infra_base + self->infrasys_offsets.bus_infra_snapshot + 4*i));
	}

	/* peribus_dbg_in_0 */
	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "%08x\n",
	               readl(peri_base + self->perisys_offsets.bus_peri_r0));

	/* peribus_dbg_in_1 */
	*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "%08x\n",
	               readl(peri_base + self->perisys_offsets.bus_peri_r1));

	if (self->num_perisys_mon != 0) {
		for (i = 0; i <= self->num_perisys_mon-1; ++i)
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "%08x\n",
			               readl(peri_base + preisys_dump_offset[i]));
	}

	return 0;
}

void plt_setup_dfd_file_name(const struct plt_cfg_dfd *cfg_dfd)
{
	struct aee_db_file_info *files;

	files = get_file_info();
	strcpy(files[AEE_PLAT_DFD20].filename, "DFD.dfd");
	files[AEE_PLAT_DFD20].filesize = (unsigned int)cfg_dfd->large_buffer_length;
}
