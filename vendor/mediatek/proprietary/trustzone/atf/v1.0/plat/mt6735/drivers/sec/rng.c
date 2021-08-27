#include <arch_helpers.h>
#include <assert.h>
#include <bl_common.h>
#include <console.h>
#include <debug.h>
#include <interrupt_mgmt.h>
#include <mmio.h>
#include <sip_error.h>
#include <plat_private.h>
#include <plat_def.h>
#include <platform.h>
#include <stdint.h>
#include <string.h>
#include <xlat_tables.h>
#include <rng.h>

#define MTK_SEC_RNG_MAGIC	(0x74726e67)

uint32_t plat_get_true_rnd(uint32_t *val)
{
	uint32_t ret = 0;
	uint32_t value = 0;

	if (val == NULL)
		return SIP_SVC_E_INVALID_PARAMS;

	/* ungate */
	mmio_write_32(TRNG_PDN_CLR, TRNG_PDN_VALUE);

	/* read random data once and drop it */
	((uint32_t *)val)[0] = mmio_read_32(TRNG_DATA);

	/* start */
	value = mmio_read_32(TRNG_CTRL);
	value |= TRNG_CTRL_START;
	mmio_write_32(TRNG_CTRL, value);

	/* get random data from trng */
	while (1) {
		value = mmio_read_32(TRNG_CTRL);
		if (value & TRNG_CTRL_RDY)
			break;
	}

	((uint32_t *)val)[0] = mmio_read_32(TRNG_DATA);

	/* stop */
	value = mmio_read_32(TRNG_CTRL);
	value &= ~TRNG_CTRL_START;
	mmio_write_32(TRNG_CTRL, value);

	/* gate */
	mmio_write_32(TRNG_PDN_SET, TRNG_PDN_VALUE);

	return ret;
}

uint32_t plat_get_rnd(uint32_t *val)
{
	uint32_t ret = 0;

	if (val == NULL)
		return SIP_SVC_E_INVALID_PARAMS;
	/* we call trng directly in current implementation */
	/* if we need a lot of random numbers, we should avoid
	 * using trng direclty. Instead, we should use trng only to
	 * get seed to prng, and use prng to get random number and
	 * do re-seeding when a specified amount of samples are collected,
	 * say 1000.
	 */
	ret = plat_get_true_rnd(val);

	return ret;
}

/**
 * plat_get_rnd_4 - get 4 32-bit random number data which is used from linux
 * input - x1: trng magic number
 * output - val0, val1, val2, val3: output buffer contains 32-bit rnd
 *
 */
uint32_t plat_get_rnd_4(uint32_t x1, uint32_t *val0, uint32_t *val1,
		uint32_t *val2, uint32_t *val3)
{
	uint32_t value[4] = {0};
	uint32_t ret = 0;

	if (val0 == NULL || val1 == NULL || val2 == NULL || val3 == NULL)
		return SIP_SVC_E_INVALID_PARAMS;

	if (x1 == MTK_SEC_RNG_MAGIC) {
		ret += plat_get_true_rnd(value);
		ret += plat_get_true_rnd(value + 1);
		ret += plat_get_true_rnd(value + 2);
		ret += plat_get_true_rnd(value + 3);
		*val0 = value[0];
		*val1 = value[1];
		*val2 = value[2];
		*val3 = value[3];

		if (ret)
			ERROR("%s failed, ret:0x%x\n", __func__, ret);

		return ret;
	}

	ERROR("%s: Wrong magic number:0x%x\n", __func__, x1);

	return SIP_SVC_E_INVALID_PARAMS;
}
