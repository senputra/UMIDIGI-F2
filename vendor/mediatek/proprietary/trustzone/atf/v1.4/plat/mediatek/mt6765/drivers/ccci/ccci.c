#include <debug.h>
#include <mmio.h>
#include <mtk_plat_common.h>
#include <platform.h>
#include <platform_def.h>
#include <console.h>
#include <stdint.h>
#include "ccci.h"
#include "modem_secure_base.h"

unsigned int ccci_md_dbgsys_config(uint64_t reg_id, uint64_t value)
{
	switch (reg_id) {
	case MD_REG_EN_APB_CLK:
		if (value != 0x1)
			break;
		mdsecure_write32(DBGSYS_OPEN_APB_CLK, value);
		break;
	case MD_REG_PC_MONITOR:
		if (value != 0x11 || value != 0x22)
			break;
		mdsecure_write32(DBGSYS_PCMONITOR_BASE + 0x800, value);
		break;
	case MD_REG_MDMCU_BUSMON:
		if (value != 0x0 || value != 0x1)
			break;
		mdsecure_write32(DBGSYS_MDMCU_BUSMON_BASE + 0x10, value);
		break;
	case MD_REG_MDINFRA_BUSMON:
		if (value != 0x0 || value != 0x1)
			break;
		mdsecure_write32(DBGSYS_MDINFRA_BUSMON_BASE + 0x10, value);
		break;
	default:
		break;
	}

	return 0;
}
