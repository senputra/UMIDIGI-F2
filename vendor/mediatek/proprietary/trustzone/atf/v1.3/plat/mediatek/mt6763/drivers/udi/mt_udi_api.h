#ifndef _MT_UDI_API_H
#define _MT_UDI_API_H

/**
 * @file    mt_udi_api.h
 * @brief   Driver header for UDI controller
 *
 */

#define __ATF_MODE_UDI__

#ifdef __ATF_MODE_UDI__
#include <mmio.h>
#endif

/*******************************************************************************
 * Defines for UDI Service queries
 ******************************************************************************/

 /* REG ACCESS */
#ifdef __ATF_MODE_UDI__
#define ptp3_reg_read(addr)			mmio_read_32(addr)
#define ptp3_reg_write(addr, val)	mmio_write_32(addr, val)
#else
#define ptp3_reg_read(addr)			(*(volatile unsigned int *)(addr))
#define ptp3_reg_write(addr, val)	(*(volatile unsigned int *)(addr) = (unsigned int)(val))
#endif

/* #define ptp3_reg_write_mask(addr, mask, val)
	ptp3_reg_write(addr, (ptp3_reg_read(addr) & ~(_BITMASK_(mask))) | _BITS_(mask, val)) */
#define ptp3_shift(val, bits, shift) \
	((val & (((unsigned int)0x1 << bits) - 1)) << shift)
#define ptp3_reg_write_bits(addr, val, bits, shift) \
	ptp3_reg_write(addr, ((ptp3_reg_read(addr) & ~(ptp3_shift((unsigned int)0xffffffff, \
	bits, shift))) | ptp3_shift(val, bits, shift)))
#define ptp3_reg_read_bits(addr, bits, shift) \
	((ptp3_reg_read(addr) >> shift) & (((unsigned int)0x1 << bits) - 1))

/* ptp3 Register Definition */
#define UDI_PTP3_UDI_REG                                    (0x0C530750)
/*
Bit(s)	Mnemonic	Name	Description
11:8	sw_tdo	Software JTAG control for top-level GatewayTAP
6		sw_trst	Software JTAG control for top-level GatewayTAP
5		sw_tms	Software JTAG control for top-level GatewayTAP
4	    sw_tdi	Software JTAG control for top-level GatewayTAP
3:0	sw_tck	Software JTAG control for top-level GatewayTAP, 1, 2 ,4 ,8 for sub_chains 0/1/2/3
*/

#define rg_sw_tck_w(val)                                ptp3_reg_write_bits(UDI_PTP3_UDI_REG, val, 4, 0)
#define rg_sw_tck_r()                                   ptp3_reg_read_bits(UDI_PTP3_UDI_REG, 4, 0)
#define rg_sw_tdi_w(val)                                ptp3_reg_write_bits(UDI_PTP3_UDI_REG, val, 1, 4)
#define rg_sw_tdi_r()                                   ptp3_reg_read_bits(UDI_PTP3_UDI_REG, 1, 4)
#define rg_sw_tms_w(val)                                ptp3_reg_write_bits(UDI_PTP3_UDI_REG, val, 1, 5)
#define rg_sw_tms_r()                                   ptp3_reg_read_bits(UDI_PTP3_UDI_REG, 1, 5)
#define rg_sw_trst_w(val)                               ptp3_reg_write_bits(UDI_PTP3_UDI_REG, val, 1, 6)
#define rg_sw_trst_r()                                  ptp3_reg_read_bits(UDI_PTP3_UDI_REG, 1, 6)
#define rg_sw_tdo_w(val)                                ptp3_reg_write_bits(UDI_PTP3_UDI_REG, val, 4, 8)
#define rg_sw_tdo_r()                                   ptp3_reg_read_bits(UDI_PTP3_UDI_REG, 4, 8)


/*******************************/
/* UDI function */
extern int UDIRead(unsigned int reg_value, unsigned int t_count);
extern int UDIBitCtrl(unsigned int reg_value);
/* ********************************** */


#endif
