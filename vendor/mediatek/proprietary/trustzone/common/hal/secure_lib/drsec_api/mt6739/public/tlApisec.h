/*
 * Copyright (c) 2013 TRUSTONIC LIMITED
 * All rights reserved
 *
 * The present software is the confidential and proprietary information of
 * TRUSTONIC LIMITED. You shall not disclose the present software and shall
 * use it only in accordance with the terms of the license agreement you
 * entered into with TRUSTONIC LIMITED. This software may be subject to
 * export or import laws in certain countries.
 */

#ifndef __TL_M_SECDRV_API_H__
#define __TL_M_SECDRV_API_H__


/* Marshaled function parameters.
 * structs and union of marshaling parameters via TlApi.
 *
 * @note The structs can NEVER be packed !
 * @note The structs can NOT used via sizeof(..) !
 */

 /*
  * Command id definitions
  */
#define FID_DR_DAPC_OPEN_SESSION            6   /* this will not be used */
#define FID_DR_DAPC_CLOSE_SESSION           7   /* this will not be used */
#define FID_DR_DAPC_INIT_DATA               8   /* this will not be used */
#define FID_DR_DAPC_EXECUTE                 9
#define FID_DRV_DEVAPC_SET                  11
#define FID_DRV_DEVAPC_SET_MASTER           12
#define FID_DRV_DEVAPC_SET_MM               13
#define FID_DRV_UT_TEST_DEVAPC              30  /* this will not be used */


typedef enum {
    MEM_TA_VIRTUAL = 1,
    MEM_PHYSICAL = 2,
    MEM_NULL = 3,
    MEM_TPLAY_MAPPING = 4,
    MEM_HANDLE_PHY_MAPPING = 5,
    MEM_RESERVED = 0x7FFFFFFF  /* force enum to use 32 bits */
} EX_MEM_t;


enum DEVAPC_MODULE_REQ_TYPE {
	DEVAPC_MODULE_REQ_CAMERA_ISP = 0,
	DEVAPC_MODULE_REQ_IMGSENSOR,
	DEVAPC_MODULE_REQ_VDEC,
	DEVAPC_MODULE_REQ_VENC,
	DEVAPC_MODULE_REQ_M4U,
	DEVAPC_MODULE_REQ_I2C,
	DEVAPC_MODULE_REQ_SPI,
	DEVAPC_MODULE_REQ_DISP,
	DEVAPC_MODULE_REQ_NUM,
};

enum DEVAPC_MASTER_REQ_TYPE {
	DEVAPC_MASTER_REQ_SPI,
	DEVAPC_MASTER_REQ_NUM,
};

enum DEVAPC_PROTECT_ON_OFF {
	DEVAPC_PROTECT_DISABLE = 0,
	DEVAPC_PROTECT_ENABLE,
};

enum CAMERA_ISP_PROTECT_TYPE {
	NONE = 0,
	CAM_A,
	CAM_B,
	CAM_C,
};

enum I2C_PROTECT_INDEX {
	I2C0 = 0,
	I2C1,
	I2C2,
	I2C3,
	I2C4,
	I2C5,
	I2C6,
	I2C7,
	I2C8,
	I2C_NUM,
};

enum SPI_PROTECT_INDEX {
	SPI0 = 0,
	SPI1,
	SPI2,
	SPI3,
	SPI4,
	SPI5,
	SPI6,
	SPI7,
	SPI_NUM,
};

/* .. add more when needed */

/* Marshaled function parameters.
 * structs and union of marshaling parameters via TlApi.
 *
 * @note The structs can NEVER be packed !
 * @note The structs can NOT used via sizeof(..) !
 */

typedef struct {
    uint32_t    commandId;
    uint32_t    index;
    uint32_t    result;
    uint32_t    module_index;
    uint32_t    domain_num;
    uint32_t    permission_control;

    // for MTK_DEVAPC_HAL_SUPPORT
    enum DEVAPC_MODULE_REQ_TYPE module_type;
    enum DEVAPC_PROTECT_ON_OFF onoff;
    uint32_t param;

} tlApiDapc_t, *tlApiDapc_ptr;


/** Union of marshaling parameters. */
typedef struct
{
    tlApiDapc_ptr   DapcData;
    uint32_t        commandId;
    uint8_t         *pKey;
    uint32_t        key_len;
    uint8_t         *pSrc;
    uint32_t        pSrc_offset; //for decryption API
    uint8_t         *pDst;
    uint32_t        dataSize;
    uint8_t         *pIV;
    uint32_t        ivSize;
    EX_MEM_t        dstMemType;
    EX_MEM_t        srcMemType;
    uint32_t        phyAddr;
    uint32_t        nwd_user;
    uint32_t        nwd_req_dir;
    uint32_t        reserve_1[2];
    uint32_t        pBuf_offset;//for decryption API, encryption API and copy API
    uint32_t        reserve[19]; //This is reserve for new API to use if required to change
    /* untyped parameter list (expends union to 8 entries) */
} secDriverParam_t, *secDriverParam_ptr;


#endif // __TL_M_SECDRV_API_H__

