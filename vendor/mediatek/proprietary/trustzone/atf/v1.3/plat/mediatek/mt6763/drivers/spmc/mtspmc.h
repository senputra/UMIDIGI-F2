/*
 * Copyright (c) 2015, ARM Limited and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __MTSPMC_H__
#define __MTSPMC_H__

/* #define FPGA_SMP	1 */
#define SPMC_SW_MODE	1
#define SPMC_DEBUG	1
#define SPMC_DVT	0
/* #define SPMC_DVT_UDELAY	0 */
#define SPMC_SPARK2	1
#define CONFIG_SPMC_MODE 1 /* 0:Legacy  1:HW  2:SW */

#define CPUTOP_MP0 0
#define CPUTOP_MP1 1
#define CPUTOP_MP2 2

#define STA_POWER_DOWN		0
#define STA_POWER_ON		1

#define MODE_SPMC_HW		0
#define MODE_AUTO_SHUT_OFF	1
#define MODE_DORMANT		2

#if SPMC_DEBUG
#define PRINTF_SPMC	INFO
#else
void __null_error(const char *fmt, ...) { }
#define PRINTF_SPMC	__null_error
#endif

int spmc_init(void);
int spmc_cputop_mpx_onoff(int cputop_mpx, int state, int mode);
int spmc_cpu_corex_onoff(int linear_id, int state, int mode);
#if SPMC_SW_MODE
int little_spmc_sw_pwr_on(int select);
int little_spmc_sw_pwr_off(int select);
int setup_sw_cluster_default_state(int select, int state);
int setup_sw_core_default_state(int select, int state);
#endif
unsigned long read_cpuectlr(void);
void write_cpuectlr(unsigned long);
int little_spark2_core_enable(unsigned int linear_id,  unsigned int sw);
int little_spark2_setldo(unsigned int linear_id);
void set_cpu_retention_control(int retention_value);
void SPARK2_reinit(void);
#endif /* __MTCMOS_H__ */
