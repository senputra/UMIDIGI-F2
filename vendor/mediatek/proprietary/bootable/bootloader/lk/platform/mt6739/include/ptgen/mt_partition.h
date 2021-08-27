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
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#ifndef __MT_PARTITION_H__
#define __MT_PARTITION_H__


#include <part.h>
#include "partition_define.h"
#include <platform/mt_typedefs.h>
#include <part_dev.h>

#define NAND_WRITE_SIZE  2048

#define BIMG_HEADER_SZ              (0x800)
#define MKIMG_HEADER_SZ             (0x200)

#define BLK_BITS         (9)
#define BLK_SIZE         (1 << BLK_BITS)
#ifdef MTK_EMMC_SUPPORT
#define BLK_NUM(size)    ((unsigned long long)(size) / BLK_SIZE)
#else
#define BLK_NUM(size)    ((unsigned long long)(size) / BLK_SIZE)
#endif
#define PART_KERNEL     "KERNEL"
#define PART_ROOTFS     "ROOTFS"
enum partition_type {
	TYPE_LOW,
	TYPE_FULL,
	TYPE_SLC,
	TYPE_TLC,
};

#ifndef RAND_START_ADDR
#define RAND_START_ADDR   0
#endif

#define PMT_END_NAME "FAT"

/* partition name used by fastboot, which is always lower case */
/* although it may be upper case in partition table, security read/write wrapper will translate it automatically */
#define FRP_NAME        "frp"

struct NAND_CMD {
	u32 u4ColAddr;
	u32 u4RowAddr;
	u32 u4OOBRowAddr;
	u8  au1OOB[64];
	u8* pDataBuf;
};

typedef struct {
	unsigned char *name;        /* partition name */
	unsigned long long  blknum;      /* partition blks */
	unsigned long long  flags;       /* partition flags */
	unsigned long long  startblk;    /* partition start blk */
	unsigned int part_id;
	enum partition_type type;
} part_t;

struct part_name_map {
	char fb_name[32];   /*partition name used by fastboot*/
	char r_name[32];    /*real partition name*/
	char *partition_type;   /*partition_type*/
	int partition_idx;  /*partition index*/
	int is_support_erase;   /*partition support erase in fastboot*/
	int is_support_dl;  /*partition support download in fastboot*/
};

enum {
	RAW_DATA_IMG,
	YFFS2_IMG,
	UBIFS_IMG,
	EXT4_IMG,
	FAT_IMG,
	UNKOWN_IMG,
};
extern struct part_name_map g_part_name_map[PART_MAX_COUNT];
extern int mt_part_register_device(part_dev_t *dev);
extern part_t* mt_part_get_partition(char *name);
extern part_dev_t* mt_part_get_device(void);
extern void mt_part_init(unsigned long totalblks);
extern void mt_part_dump(void);
extern int partition_get_index(const char * name);
extern u32 partition_get_region(int index);
extern u64 partition_get_offset(int index);
extern u64 partition_get_size(int index);
extern int partition_get_type(int index, char **p_type);
extern int partition_get_name(int index, char **p_name);
extern int is_support_erase(int index);
extern int is_support_flash(int index);
extern u64 emmc_write(u64 offset, void *data, u64 size);
extern u64 emmc_read(u64 offset, void *data, u64 size);
extern int emmc_erase(u64 offset, u64 size);
extern unsigned long partition_reserve_size(void);
extern part_t *get_part(char *name);
extern unsigned long mt_part_get_part_active_bit(part_t *part);
#endif /* __MT_PARTITION_H__ */

