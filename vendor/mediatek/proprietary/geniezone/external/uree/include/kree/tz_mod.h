/*
 * Copyright (c) 2019, MediaTek Inc. All rights reserved.
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws.
 * The information contained herein is confidential and proprietary to
 * MediaTek Inc. and/or its licensors.
 * Except as otherwise provided in the applicable licensing terms with
 * MediaTek Inc. and/or its licensors, any reproduction, modification, use or
 * disclosure of MediaTek Software, and information contained herein, in whole
 * or in part, shall be strictly prohibited.
*/

#ifndef TZ_MOD_H
#define TZ_MOD_H

 /*****************************************************************************
 * MODULE DEFINITION
 *****************************************************************************/
#define MODULE_NAME	    "[MTEE_MOD]"
#define TZ_DEV_NAME        "trustzone"
#define MAJOR_DEV_NUM   197

 /*****************************************************************************
 * IOCTL DEFINITION
 *****************************************************************************/
#define MTEE_IOC_MAGIC       'T'
#define MTEE_CMD_OPEN_SESSION \
		_IOWR(MTEE_IOC_MAGIC,  1, struct kree_session_cmd_param)
#define MTEE_CMD_CLOSE_SESSION \
		_IOWR(MTEE_IOC_MAGIC,  2, struct kree_session_cmd_param)
#define MTEE_CMD_TEE_SERVICE \
		_IOWR(MTEE_IOC_MAGIC,  3, struct kree_tee_service_cmd_param)
#define MTEE_CMD_SHM_REG \
		_IOWR(MTEE_IOC_MAGIC,  4, struct kree_tee_service_cmd_param)
#define MTEE_CMD_SHM_UNREG \
		_IOWR(MTEE_IOC_MAGIC,  5, struct kree_tee_service_cmd_param)
#define MTEE_CMD_SC_TEST_CP_CHM2SHM \
			_IOWR(MTEE_IOC_MAGIC,  6, struct kree_user_sc_param)
#define MTEE_CMD_SC_TEST_UPT_CHMDATA \
			_IOWR(MTEE_IOC_MAGIC,  7, struct kree_user_sc_param)
#define MTEE_CMD_SC_CHMEM_HANDLE \
			_IOWR(MTEE_IOC_MAGIC,  14, struct kree_user_sc_param)
#define MTEE_CMD_FOD_TEE_SHM_ON \
			_IO(MTEE_IOC_MAGIC,  16)
#define MTEE_CMD_FOD_TEE_SHM_OFF \
			_IO(MTEE_IOC_MAGIC,  17)
#define MTEE_CMD_SCAMERA_to_MTEE \
			_IOWR(MTEE_IOC_MAGIC,  18, struct kree_scamera_param)
#define MTEE_CMD_DEEP_IDLE_MASK \
			_IO(MTEE_IOC_MAGIC, 19)
#define MTEE_CMD_DEEP_IDLE_UNMASK \
			_IO(MTEE_IOC_MAGIC, 20)

#define DEV_IOC_MAXNR       (10)

/* param for open/close session */
struct kree_session_cmd_param {
	int32_t ret;
	int32_t handle;
	uint64_t data;
};

/* param for tee service call */
struct kree_tee_service_cmd_param {
	int32_t ret;
	int32_t handle;
	uint32_t command;
	uint32_t paramTypes;
	uint64_t param;
};

/* param for shared memory */
struct kree_sharedmemory_cmd_param {
	int32_t ret;
	uint32_t session;
	uint32_t mem_handle;
	uint32_t command;
	uint64_t buffer;
	uint32_t size;
	uint32_t control;	/* 0 = write, 1 = read only */
};

struct kree_user_test_chm_param {
	uint32_t append_chm_session;
	uint32_t alloc_chm_session;
	uint32_t append_chm_handle;
};

struct kree_user_sc_param {
	uint32_t size;	/*alloc chm size*/
	uint32_t alignment;	/*alloc alignment size*/
	uint32_t ION_handle;
	uint32_t other_handle; /*shm handle*/
	struct kree_user_test_chm_param chmp;
};

struct kree_scamera_param {
	uint32_t size;
	int width;
	int height;
	uint32_t stride;
	int format;
	int cmd;
	int done;
};

#endif /* end of DEVFINO_H */
