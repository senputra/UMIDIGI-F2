/*
 * Copyright (c) 2014 TRUSTONIC LIMITED
 * All rights reserved
 *
 * The present software is the confidential and proprietary information of
 * TRUSTONIC LIMITED. You shall not disclose the present software and shall
 * use it only in accordance with the terms of the license agreement you
 * entered into with TRUSTONIC LIMITED. This software may be subject to
 * export or import laws in certain countries.
 */

#include <arch_helpers.h>
#include <assert.h>
#include <debug.h>
#include <gic_v2.h>
#include <gic_v3.h>
#include <interrupt_mgmt.h>
#include <mmio.h>
#include "plat_private.h"
#include <platform.h>
#include <platform_def.h>
#include <string.h>
#include <tbase_private.h>
#include <tzc400.h>
#include <rng.h>

/* Defines */
#define PLAT_TBASE_INPUT_HWIDENTITY	(0x1)
#define PLAT_TBASE_INPUT_HWKEY		(0x2)
#define PLAT_TBASE_INPUT_RNG		(0x3)

#define PLAT_TBASE_INPUT_OK		((uint32_t)0)
#define PLAT_TBASE_INPUT_ERROR		((uint32_t)-1)

/* for AEE WDT/HWT dump */
/*extern void aee_wdt_dump(void);*/

/* Forward declarations */
static void coreDump(uint32_t coreId);
static void platformDump(void);

/*void irq_raise_softirq(unsigned int map, unsigned int irq);*/

/* Code */
/* <t-base handler for SWd fastcall INPUT */
uint32_t plat_tbase_input(uint64_t DataId, uint64_t *Length, void *out)
{
	uint32_t Status = PLAT_TBASE_INPUT_OK;
	uint32_t length = 0, idx = 0;

	/* Implement associated actions */
	switch (DataId) {
	case PLAT_TBASE_INPUT_HWIDENTITY: {
		atf_arg_t_ptr teearg = &gteearg;

		/* Maybe we can move this to a memcpy instead */
		for (idx = 0; idx < (*Length / sizeof(uint32_t)) &&
			idx < (sizeof(teearg->hwuid) / sizeof(uint32_t)); idx++) {
			((uint32_t *)out)[idx] = teearg->hwuid[idx];
			length += sizeof(uint32_t);
		}

		break;
	}
	case PLAT_TBASE_INPUT_HWKEY: {
		atf_arg_t_ptr teearg = &gteearg;

		/* Maybe we can move this to a memcpy instead */
		for (idx = 0; idx < (*Length / sizeof(uint32_t)) &&
			idx < (sizeof(teearg->HRID) / sizeof(uint32_t)) ; idx++) {
			((uint32_t *)out)[idx] = teearg->HRID[idx];
			length += sizeof(uint32_t);
		}
		*Length = length;
		break;
	}
	case PLAT_TBASE_INPUT_RNG: {
		Status = plat_get_rnd((uint32_t *)out);
		*Length = 4;
		break;
	}
	default:
		/* Unsupported request */
		Status = PLAT_TBASE_INPUT_ERROR;
		break;
	}

	return Status;
}

/* <t-base handler for SWd fastcall DUMP */
uint32_t plat_tbase_dump(void)
{
	uint32_t linear_id = platform_get_core_pos(read_mpidr());

	NOTICE("core %d is dumped !\n", (int)linear_id);

	aee_wdt_dump(NULL);

	return 0;
}

void plat_tbase_fiqforward_init(void)
{
	NOTICE("Configuring t-base forwarded FIQs...\n");

	/* Watchdog FIQ configuration */
	tbase_fiqforward_configure(WDT_IRQ_BIT_ID,    /* interrupt id */
								TBASE_FLAG_SET);  /* enable forward */

#if FIQFORWARD_TEST
	/* Another forwarded FIQ, just for testing purpose */
	tbase_fiqforward_configure(161,              /* interrupt id */
								TBASE_FLAG_SET); /* enable forward */
#endif
}

/* <t-base handler for EL1->EL3 forwarded FIQs */
uint32_t plat_tbase_forward_fiq(uint32_t fiqId)
{
	uint32_t Status = PLAT_TBASE_INPUT_OK;
	uint32_t linear_id = platform_get_core_pos(read_mpidr());

	/* Verbosity */
	NOTICE("core %d EL3 received forwarded FIQ %d from <t-base !\n", (int)linear_id, (int) fiqId);

	/* Handle forwarded FIQ */
	switch (fiqId) {
	case WDT_IRQ_BIT_ID:
		/* FIQ dump */
		platformDump();
		break;
	case 161:
		/* just a simple test */
		NOTICE("%s: That's a test !\n", __func__);
		break;
	default:
		/* Unknown FIQ */

		NOTICE("%s: FIQ %d was forwarded but no processing was associated to it.\n", __func__, fiqId);
		Status = PLAT_TBASE_INPUT_ERROR;
		break;
	}


	return Status;
}

/* Private code */
static void coreDump(uint32_t coreId)
{
	uint64_t mpidr = read_mpidr();
	uint32_t linear_id = platform_get_core_pos(mpidr);

	uint32_t SGITarget;

	assert(coreId < PLATFORM_CORE_COUNT);

	/* Check if target core is the one we're currently running on */
	if (coreId == linear_id) {
		/* Current core : let's call the handler directly */
		plat_tbase_dump();
	} else {
		/* Other cores : let's do the same using SGIs */

		/* Configure SGI */
		gicd_clr_igroupr(MT_GIC_BASE, FIQ_SMP_CALL_SGI);
		gicd_set_ipriorityr(MT_GIC_BASE, FIQ_SMP_CALL_SGI, GIC_HIGHEST_SEC_PRIORITY);

		/* Enable SGI */
		gicd_set_isenabler(MT_GIC_BASE, FIQ_SMP_CALL_SGI);

		/* Send SGI to this specific core */
		SGITarget = 1 << coreId;

		/* Trigger SGI */
		irq_raise_softirq(SGITarget, FIQ_SMP_CALL_SGI);
	}
}

static void platformDump(void)
{
	uint64_t mpidr = read_mpidr();
	uint32_t linear_id = platform_get_core_pos(mpidr);
	uint32_t i;

	/* Dump all cores, one by one */
	for (i = 0 ; i < PLATFORM_CORE_COUNT ; i++) {
		/* Do not dump current (primary) core, we'll do it after at last */
		if (i != linear_id) {
			/* Dump core 'i' */
			coreDump(i);
		}
	}

	/* All secondary cores have been dumped, let's dump primary core */
	coreDump(linear_id);
}

