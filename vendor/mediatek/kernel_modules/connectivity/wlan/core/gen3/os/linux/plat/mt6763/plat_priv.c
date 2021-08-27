/* SPDX-License-Identifier: GPL-2.0 */

/*
 * Copyright (c) 2020 MediaTek Inc.
 */

#include "connectivity_build_in_adapter.h"
#include "gl_typedef.h"
#include "typedef.h"
#include <cpu_ctrl.h>

#define MAX_CPU_FREQ     23400000
#define CLUSTER_NUM      2

int kalBoostCpu(unsigned int level)
{
	int i = 0;
	struct ppm_limit_data freq_to_set[CLUSTER_NUM];

	for (i = 0; i < CLUSTER_NUM; i++) {
		freq_to_set[i].max = -1; /* -1 means don't care */
		freq_to_set[i].min = level ? MAX_CPU_FREQ : -1;
	}
	update_userlimit_cpu_freq(CPU_KIR_WIFI, CLUSTER_NUM, freq_to_set);

	return 0;
}


