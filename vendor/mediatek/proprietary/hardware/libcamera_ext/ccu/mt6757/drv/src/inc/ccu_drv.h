/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/

#ifndef __CCU_DRV_H__
#define __CCU_DRV_H__

#include <linux/types.h>
#include <linux/ioctl.h>
#include "ccu_ext_interface/ccu_mailbox_extif.h"

#ifdef CONFIG_COMPAT
/*64 bit*/
#include <linux/fs.h>
#include <linux/compat.h>
#endif

struct ccu_platform_info {
	uint32_t ccu_hw_base;
	uint32_t ccu_hw_offset;
	uint32_t ccu_pmem_base;
	uint32_t ccu_pmem_size;
	uint32_t ccu_dmem_base;
	uint32_t ccu_dmem_size;
	uint32_t ccu_dmem_offset;
	uint32_t ccu_log_base;
	uint32_t ccu_log_size;
	uint32_t ccu_hw_dump_size;
	uint32_t ccu_camsys_base;
	uint32_t ccu_camsys_size;
	uint32_t ccu_n3d_a_base;
	uint32_t ccu_n3d_a_size;
	uint32_t ccu_sensor_pm_size;
	uint32_t ccu_sensor_dm_size;
};

/*---------------------------------------------------------------------------*/
/*  CCU IRQ                                                                */
/*---------------------------------------------------------------------------*/
#define IRQ_USER_NUM_MAX        32
#define SUPPORT_MAX_IRQ         32


typedef enum {
	CCU_IRQ_CLEAR_NONE, /* non-clear wait, clear after wait */
	CCU_IRQ_CLEAR_WAIT, /* clear wait, clear before and after wait */
	CCU_IRQ_CLEAR_STATUS, /* clear specific status only */
	CCU_IRQ_CLEAR_ALL /* clear all status */
} CCU_IRQ_CLEAR_ENUM;

typedef enum {
	CCU_IRQ_TYPE_INT_CCU_ST,
	CCU_IRQ_TYPE_INT_CCU_A_ST,
	CCU_IRQ_TYPE_INT_CCU_B_ST,
	CCU_IRQ_TYPE_AMOUNT
} CCU_IRQ_TYPE_ENUM;

typedef enum {
	CCU_SIGNAL_INT = 0, CCU_DMA_INT, CCU_IRQ_ST_AMOUNT
} CCU_ST_ENUM;

typedef struct {
	unsigned int tLastSig_sec; /* time stamp of the latest occurring signal*/
	unsigned int tLastSig_usec; /* time stamp of the latest occurring signal*/
	unsigned int tMark2WaitSig_sec; /* time period from marking a signal to user try to wait and get the signal*/
	unsigned int tMark2WaitSig_usec; /* time period from marking a signal to user try to wait and get the signal*/
	unsigned int tLastSig2GetSig_sec; /* time period from latest signal to user try to wait and get the signal*/
	unsigned int tLastSig2GetSig_usec; /* time period from latest signal to user try to wait and get the signal*/
	int passedbySigcnt; /* the count for the signal passed by  */
} CCU_IRQ_TIME_STRUCT;

typedef struct {
	CCU_IRQ_CLEAR_ENUM Clear;
	CCU_ST_ENUM St_type;
	unsigned int Status;
	int UserKey; /* user key for doing interrupt operation */
	unsigned int Timeout;
	CCU_IRQ_TIME_STRUCT TimeInfo;
} CCU_WAIT_IRQ_ST;

typedef struct {
	int userKey;
	char userName[32];
} CCU_REGISTER_USERKEY_STRUCT;

typedef struct {
	CCU_IRQ_TYPE_ENUM Type;
	unsigned int bDumpReg;
	CCU_WAIT_IRQ_ST EventInfo;
} CCU_WAIT_IRQ_STRUCT;

typedef struct {
	int UserKey; /* user key for doing interrupt operation */
	CCU_ST_ENUM St_type;
	unsigned int Status;
} CCU_CLEAR_IRQ_ST;

typedef struct {
	CCU_IRQ_TYPE_ENUM Type;
	CCU_CLEAR_IRQ_ST EventInfo;
} CCU_CLEAR_IRQ_STRUCT;

typedef struct {
	unsigned int module;
	unsigned int Addr; /* register's addr */
	unsigned int Val; /* register's value */
} CCU_REG_STRUCT;

typedef struct {
	CCU_REG_STRUCT *pData; /* pointer to CCU_REG_STRUCT */
	unsigned int Count; /* count */
} CCU_REG_IO_STRUCT;

typedef struct {
	/* Add an extra index for status type in Everest -> signal or dma */
	volatile unsigned int    Status[CCU_IRQ_TYPE_AMOUNT][CCU_IRQ_ST_AMOUNT][IRQ_USER_NUM_MAX];
	unsigned int             Mask[CCU_IRQ_TYPE_AMOUNT][CCU_IRQ_ST_AMOUNT];
	unsigned int             ErrMask[CCU_IRQ_TYPE_AMOUNT][CCU_IRQ_ST_AMOUNT];
	signed int              WarnMask[CCU_IRQ_TYPE_AMOUNT][CCU_IRQ_ST_AMOUNT];
	/* flag for indicating that user do mark for a interrupt or not */
	volatile unsigned int    MarkedFlag[CCU_IRQ_TYPE_AMOUNT][CCU_IRQ_ST_AMOUNT][IRQ_USER_NUM_MAX];
	/* time for marking a specific interrupt */
	volatile unsigned int    MarkedTime_sec[CCU_IRQ_TYPE_AMOUNT][32][IRQ_USER_NUM_MAX];
	/* time for marking a specific interrupt */
	volatile unsigned int    MarkedTime_usec[CCU_IRQ_TYPE_AMOUNT][32][IRQ_USER_NUM_MAX];
	/* number of a specific signal that passed by */
	volatile signed int     PassedBySigCnt[CCU_IRQ_TYPE_AMOUNT][32][IRQ_USER_NUM_MAX];
	/* */
	volatile unsigned int    LastestSigTime_sec[CCU_IRQ_TYPE_AMOUNT][32];
	/* latest time for each interrupt */
	volatile unsigned int    LastestSigTime_usec[CCU_IRQ_TYPE_AMOUNT][32];
	/* latest time for each interrupt */
} CCU_IRQ_INFO_STRUCT;

#define CCU_ISR_MAX_NUM 32
#define INT_ERR_WARN_TIMER_THREAS 1000
#define INT_ERR_WARN_MAX_TIME 3
typedef struct {
	unsigned int m_err_int_cnt[CCU_IRQ_TYPE_AMOUNT][CCU_ISR_MAX_NUM]; /* cnt for each err int # */
	unsigned int m_warn_int_cnt[CCU_IRQ_TYPE_AMOUNT][CCU_ISR_MAX_NUM]; /* cnt for each warning int # */
	unsigned int m_err_int_mark[CCU_IRQ_TYPE_AMOUNT]; /* mark for err int, where its cnt > threshold */
	unsigned int m_warn_int_mark[CCU_IRQ_TYPE_AMOUNT]; /* mark for warn int, where its cnt > threshold */
	unsigned long m_int_usec[CCU_IRQ_TYPE_AMOUNT];
} CCU_IRQ_ERR_WAN_CNT_STRUCT;

#define CCU_BUF_SIZE            (4096)
#define CCU_BUF_SIZE_WRITE      1024
#define CCU_BUF_WRITE_AMOUNT    6
typedef enum {
	CCU_BUF_STATUS_EMPTY,
	CCU_BUF_STATUS_HOLD,
	CCU_BUF_STATUS_READY
} CCU_BUF_STATUS_ENUM;

typedef struct {
	volatile CCU_BUF_STATUS_ENUM Status;
	volatile unsigned int                Size;
	unsigned char *pData;
} CCU_BUF_STRUCT;

typedef struct {
	CCU_BUF_STRUCT      Read;
	CCU_BUF_STRUCT      Write[CCU_BUF_WRITE_AMOUNT];
} CCU_BUF_INFO_STRUCT;

typedef struct {
	unsigned int     Vd;
	unsigned int     Expdone;
	unsigned int     WorkQueueVd;
	unsigned int     WorkQueueExpdone;
	unsigned int     TaskletVd;
	unsigned int     TaskletExpdone;
} CCU_TIME_LOG_STRUCT;

#ifdef MTK_VPU_KERNEL
typedef struct {
	spinlock_t                      SpinLockCcuRef;
	spinlock_t                      SpinLockCcu;
	spinlock_t                      SpinLockIrq[CCU_IRQ_TYPE_AMOUNT];
	spinlock_t                      SpinLockIrqCnt[CCU_IRQ_TYPE_AMOUNT];
	spinlock_t                      SpinLockRTBC;
	spinlock_t                      SpinLockClock;

	wait_queue_head_t               WaitQueueHead;
	volatile wait_queue_head_t      WaitQHeadList[SUPPORT_MAX_IRQ];

	unsigned int                         UserCount;
	unsigned int                         DebugMask;
	signed int							IrqNum;
	CCU_IRQ_INFO_STRUCT				IrqInfo;
	CCU_IRQ_ERR_WAN_CNT_STRUCT		IrqCntInfo;
	CCU_BUF_INFO_STRUCT				BufInfo;
	CCU_TIME_LOG_STRUCT             TimeLog;
} CCU_INFO_STRUCT;
#endif

/*---------------------------------------------------------------------------*/
/*  CCU working buffer                                                       */
/*---------------------------------------------------------------------------*/
#define SIZE_32BYTE	(32)
#define SIZE_1MB	(1024*1024)
#define SIZE_1MB_PWR2PAGE   (8)
#define MAX_I2CBUF_NUM 	1
#define MAX_MAILBOX_NUM 2
#define MAX_LOG_BUF_NUM 2

#define MAILBOX_SEND 0
#define MAILBOX_GET 1

typedef struct ccu_working_buffer_s {
	uint8_t *va_pool;
	uint32_t mva_pool;
	uint32_t sz_pool;

	uint8_t *va_i2c;							/* i2c buffer mode */
	uint32_t mva_i2c;
	uint32_t sz_i2c;

	uint8_t *va_mb[MAX_MAILBOX_NUM]; 			/* mailbox  		*/
	uint32_t mva_mb[MAX_MAILBOX_NUM];
	uint32_t sz_mb[MAX_MAILBOX_NUM];

	char    *va_log[MAX_LOG_BUF_NUM];			/* log buffer		*/
	uint32_t mva_log[MAX_LOG_BUF_NUM];
	uint32_t sz_log[MAX_LOG_BUF_NUM];
    int32_t  fd_log[MAX_LOG_BUF_NUM];
} ccu_working_buffer_t;

#ifdef CONFIG_COMPAT
typedef struct compat_ccu_working_buffer_s {
	compat_uptr_t va_pool;
	uint32_t mva_pool;
	uint32_t sz_pool;

	compat_uptr_t va_i2c;							/* i2c buffer mode */
	uint32_t mva_i2c;
	uint32_t sz_i2c;

	compat_uptr_t va_mb[MAX_MAILBOX_NUM]; 			/* mailbox  		*/
	uint32_t mva_mb[MAX_MAILBOX_NUM];
	uint32_t sz_mb[MAX_MAILBOX_NUM];

	compat_uptr_t va_log[MAX_LOG_BUF_NUM];			/* log buffer		*/
	uint32_t mva_log[MAX_LOG_BUF_NUM];
	uint32_t sz_log[MAX_LOG_BUF_NUM];
    int32_t  fd_log[MAX_LOG_BUF_NUM];
} compat_ccu_working_buffer_t;
#endif
/*---------------------------------------------------------------------------*/
/*  CCU Power                                                                */
/*---------------------------------------------------------------------------*/
typedef struct ccu_power_s {
	uint32_t bON;
	uint32_t freq;
	uint32_t power;
	ccu_working_buffer_t workBuf;
} ccu_power_t;

#ifdef CONFIG_COMPAT
typedef struct compat_ccu_power_s {
	uint32_t bON;
	uint32_t freq;
	uint32_t power;
	compat_ccu_working_buffer_t workBuf;
} compat_ccu_power_t;
#endif
/*---------------------------------------------------------------------------*/
/*  CCU command                                                              */
/*---------------------------------------------------------------------------*/

typedef enum ccu_eng_status_e {
	CCU_ENG_STATUS_SUCCESS,
	CCU_ENG_STATUS_BUSY,
	CCU_ENG_STATUS_TIMEOUT,
	CCU_ENG_STATUS_INVALID,
	CCU_ENG_STATUS_FLUSH,
	CCU_ENG_STATUS_FAILURE,
} ccu_eng_status_t;

/*---------------------------------------------------------------------------*/
/*  CCU Command                                                                */
/*---------------------------------------------------------------------------*/
typedef struct ccu_cmd_s {
	ccu_msg_t task;
	ccu_eng_status_t status;
} ccu_cmd_st;

/*---------------------------------------------------------------------------*/
/*  IOCTL Command                                                            */
/*---------------------------------------------------------------------------*/
#define CCU_MAGICNO             'c'
#define CCU_IOCTL_SET_POWER                 _IOW(CCU_MAGICNO,   0, int)
#define CCU_IOCTL_ENQUE_COMMAND             _IOW(CCU_MAGICNO,   1, int)
#define CCU_IOCTL_DEQUE_COMMAND             _IOWR(CCU_MAGICNO,  2, int)
#define CCU_IOCTL_FLUSH_COMMAND             _IOW(CCU_MAGICNO,   3, int)
#define CCU_IOCTL_WAIT_IRQ                  _IOW(CCU_MAGICNO,   9, int)
#define CCU_IOCTL_SEND_CMD                  _IOWR(CCU_MAGICNO, 10, int)
#define CCU_IOCTL_SET_RUN                   _IO(CCU_MAGICNO,  11)

#define CCU_CLEAR_IRQ                       _IOW(CCU_MAGICNO,  12, int)
#define CCU_REGISTER_IRQ_USER_KEY           _IOR(CCU_MAGICNO,  13, int)
#define CCU_READ_REGISTER                   _IOWR(CCU_MAGICNO, 14, int)
#define CCU_WRITE_REGISTER                  _IOWR(CCU_MAGICNO, 15, int)

#define CCU_IOCTL_SET_WORK_BUF              _IOW(CCU_MAGICNO,  18, int)
#define CCU_IOCTL_FLUSH_LOG                 _IOW(CCU_MAGICNO,  19, int)

#define CCU_IOCTL_GET_I2C_DMA_BUF_ADDR      _IOR(CCU_MAGICNO,  20, int)
#define CCU_IOCTL_SET_I2C_MODE              _IOW(CCU_MAGICNO,  21, int)
#define CCU_IOCTL_SET_I2C_CHANNEL           _IOW(CCU_MAGICNO,  22, int)

#define CCU_IOCTL_GET_CURRENT_FPS           _IOR(CCU_MAGICNO,  23, int)
#define CCU_IOCTL_GET_SENSOR_I2C_SLAVE_ADDR _IOR(CCU_MAGICNO,  24, int)
#define CCU_IOCTL_GET_SENSOR_NAME           _IOR(CCU_MAGICNO,  25, int)
#define CCU_IOCTL_GET_PLATFORM_INFO         _IOR(CCU_MAGICNO,  26, int)

/*---------------------------------------------------------------------------*/
/*	i2c interface from ccu_drv.c */
/*---------------------------------------------------------------------------*/
enum CCU_I2C_CHANNEL
{
    CCU_I2C_CHANNEL_UNDEF = 0x0,
    CCU_I2C_CHANNEL_MAINCAM =  0x1,
    CCU_I2C_CHANNEL_SUBCAM =  0x2
};

struct ccu_i2c_arg {
	unsigned int i2c_write_id;
	unsigned int transfer_len;
};

extern int i2c_get_dma_buffer_addr(void **va);
extern int ccu_i2c_buf_mode_en(int enable);
extern int ccu_init_i2c_buf_mode(unsigned short i2cId);
extern int ccu_config_i2c_buf_mode(int transfer_len);
extern int ccu_i2c_frame_reset(void);
extern int ccu_trigger_i2c(int transac_len, MBOOL do_dma_en);

#endif
