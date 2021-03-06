#ifndef __DUAL_ISP_CONFIG_H__
#define __DUAL_ISP_CONFIG_H__

typedef cam_uni_reg_t DUAL_REG_UNI_STRUCT;
typedef cam_a_reg_t DUAL_REG_A_STRUCT;
typedef cam_b_reg_t DUAL_REG_B_STRUCT;

#define DUAL_ISP_BASE_UNI     (0x1A003000)
#define DUAL_ISP_BASE_HW     (0x1A004000)
#define DUAL_ISP_BASE_HW_D     (0x1A005000)

/* following define can be changed with rebuilding dual_isp_driver.cpp */
#define DUAL_IN_DUMP_HEADER "[ISP][DUAL_IN]"
#define DUAL_OUT_DUMP_HEADER "[ISP][DUAL_OUT]"
#define DUAL_ENG_DUMP_HEADER "[ISP][DUAL_ENG]"
#define DUAL_REG_DUMP_HEADER "[ISP][DUAL_REG]"
#define DUAL_DUMP_VERSION "V.0.0.0.1"
#define DUAL_DUMP_START "start MT6593"
#define DUAL_DUMP_END "end MT6593"
#define DUAL_HW_DIFF_STR " <dump diff> " /* can be changed */
#define DUAL_NO_HW_STR " <no dump> " /* can be changed */
#define DUAL_CAL_DIFF_STR " <cal diff> " /* can be changed */

#define DUAL_REG_DUMP_HEADER "[ISP][DUAL_REG]"
#define DUAL_CMP_DUMP_HEADER "[ISP][DUAL_CMP]"

#define DUAL_CTRL_LIST_SW(CMD, a, b, c, d, e, f) \
    DUAL_CTRL_LIST_SW_R(CMD, a, b, c, d, e, f) \

#define DUAL_CTRL_LIST_SW_R(CMD, a, b, c, d, e, f) \
    /* Driver */\
    CMD(a, b, c, d, e, f, DUAL_DEBUG_STRUCT, DEBUG)\
    /* SW */\
    CMD(a, b, c, d, e, f, DUAL_SW_STRUCT, SW)\

#define DUAL_SW_STRUCT_LIST(CMD, a, b, c, d, e, f) \
    /* CONFIG */\
    CMD(a, b, c, d, e, f, int, DUAL_SEL, R)\
    CMD(a, b, c, d, e, f, int, TWIN_MODE_SDBLK_XNUM_ALL, R)\
    CMD(a, b, c, d, e, f, int, TWIN_MODE_SDBLK_lWIDTH_ALL, R)\
    CMD(a, b, c, d, e, f, int, TWIN_RRZ_IN_CROP_HT, R)\
    CMD(a, b, c, d, e, f, int, TWIN_RRZ_HORI_INT_OFST, R)\
    CMD(a, b, c, d, e, f, int, TWIN_RRZ_HORI_INT_OFST_LAST, R)\
    CMD(a, b, c, d, e, f, int, TWIN_RRZ_HORI_SUB_OFST, R)\
    CMD(a, b, c, d, e, f, int, TWIN_RRZ_OUT_WD, R)\
    CMD(a, b, c, d, e, f, int, TWIN_AF_OFFSET, R)\
    CMD(a, b, c, d, e, f, int, TWIN_AF_BLOCK_XNUM, R)\
    CMD(a, b, c, d, e, f, int, TWIN_RAWI_XSIZE, R)\
    CMD(a, b, c, d, e, f, int, TWIN_SCENARIO, R)\

#define DUAL_CTRL_LIST_HW(CMD, a, b, c, d, e, f) \
    DUAL_CTRL_LIST_HW_R(CMD, a, b, c, d, e, f)\

#define DUAL_CTRL_LIST_HW_R(CMD, a, b, c, d, e, f) \
    /* RAWI */\
    CMD(a, b, c, d, e, f, CAM_UNI_REG_RAWI_YSIZE, CAM_UNI_RAWI_YSIZE)\
    CMD(a, b, c, d, e, f, CAM_UNI_REG_TOP_FMT_SEL, CAM_UNI_TOP_FMT_SEL)\
    CMD(a, b, c, d, e, f, CAM_UNI_REG_TOP_MOD_EN, CAM_UNI_TOP_MOD_EN)\

#define DUAL_ENGINE_LIST_HW(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_R_RW(CMD, a, b, c, d, e, f)\
    DUAL_ENGINE_LIST_HW_R_R(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_R_X(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_RW_W(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_W_W(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_R_W(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_RW_RW(CMD, a, b, c, d, e, f) \

#define DUAL_ENGINE_LIST_HW_D(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_R_RW(CMD, a, b, c, d, e, f)\
    DUAL_ENGINE_LIST_HW_R_R(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_RW_W(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_W_W(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_R_W(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_RW_RW(CMD, a, b, c, d, e, f) \

#define DUAL_ENGINE_LIST_HW_T(CMD, a, b, c, d, e, f)  DUAL_ENGINE_LIST_HW_D(CMD, a, b, c, d, e, f)

#define DUAL_ENGINE_LIST_HW_IN(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_R_RW(CMD, a, b, c, d, e, f)\
    DUAL_ENGINE_LIST_HW_R_R(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_R_X(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_RW_W(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_R_W(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_RW_RW(CMD, a, b, c, d, e, f) \

#define DUAL_ENGINE_LIST_HW_IN_D(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_R_RW(CMD, a, b, c, d, e, f)\
    DUAL_ENGINE_LIST_HW_R_R(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_RW_RW(CMD, a, b, c, d, e, f) \

#define DUAL_ENGINE_LIST_HW_OUT(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_RW_W(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_W_W(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_RW_RW(CMD, a, b, c, d, e, f) \

#define DUAL_ENGINE_LIST_HW_OUT_D(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_R_RW(CMD, a, b, c, d, e, f)\
    DUAL_ENGINE_LIST_HW_RW_W(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_W_W(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_R_W(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_LIST_HW_RW_RW(CMD, a, b, c, d, e, f) \

#define DUAL_ENGINE_ARRAY_HW(CMD, a, b, c, d, e, f) \
    DUAL_ENGINE_ARRAY_HW_R_W(CMD, a, b, c, d, e, f) \

#define DUAL_ENGINE_ARRAY_HW_R_W(CMD, a, b, c, d, e, f) \
    /* SGM */\
    /*CMD(a, b, c, d, e, f, CAM_A_REG_SGM_LUT_R, CAM_A_SGM_LUT_R, CAM_B_SGM_LUT_R,,, 64)*/\
    /*CMD(a, b, c, d, e, f, CAM_A_REG_SGM_LUT_G, CAM_A_SGM_LUT_G, CAM_B_SGM_LUT_G,,, 64)*/\
    /*CMD(a, b, c, d, e, f, CAM_A_REG_SGM_LUT_B, CAM_A_SGM_LUT_B, CAM_B_SGM_LUT_B,,, 64)*/\

#define DUAL_ENGINE_LIST_HW_R_RW(CMD, a, b, c, d, e, f) \
    /* CTRL */\
    CMD(a, b, c, d, e, f, CAM_A_REG_CTL_FMT_SEL, CAM_A_CTL_FMT_SEL, CAM_B_CTL_FMT_SEL,,)\
    /* SEL */\
    CMD(a, b, c, d, e, f, CAM_A_REG_CTL_SEL, CAM_A_CTL_SEL, CAM_B_CTL_SEL,,)\
    /* SGG1 */\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGG1_PGN, CAM_A_SGG1_PGN, CAM_B_SGG1_PGN,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGG1_GMRC_1, CAM_A_SGG1_GMRC_1, CAM_B_SGG1_GMRC_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGG1_GMRC_2, CAM_A_SGG1_GMRC_2, CAM_B_SGG1_GMRC_2,,)\
    /* SGG5 */\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGG5_PGN, CAM_A_SGG5_PGN, CAM_B_SGG5_PGN,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGG5_GMRC_1, CAM_A_SGG5_GMRC_1, CAM_B_SGG5_GMRC_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGG5_GMRC_2, CAM_A_SGG5_GMRC_2, CAM_B_SGG5_GMRC_2,,)\
    /* AF */\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_BLK_0, CAM_A_AF_BLK_0, CAM_B_AF_BLK_0,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_CON, CAM_A_AF_CON, CAM_B_AF_CON,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_TH_0, CAM_A_AF_TH_0, CAM_B_AF_TH_0,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_TH_1, CAM_A_AF_TH_1, CAM_B_AF_TH_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_FLT_1, CAM_A_AF_FLT_1, CAM_B_AF_FLT_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_FLT_2, CAM_A_AF_FLT_2, CAM_B_AF_FLT_2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_FLT_3, CAM_A_AF_FLT_3, CAM_B_AF_FLT_3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_FLT_4, CAM_A_AF_FLT_4, CAM_B_AF_FLT_4,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_FLT_5, CAM_A_AF_FLT_5, CAM_B_AF_FLT_5,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_FLT_6, CAM_A_AF_FLT_6, CAM_B_AF_FLT_6,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_FLT_7, CAM_A_AF_FLT_7, CAM_B_AF_FLT_7,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_FLT_8, CAM_A_AF_FLT_8, CAM_B_AF_FLT_8,,)\
	CMD(a, b, c, d, e, f, CAM_A_REG_AF_TH_2, CAM_A_AF_TH_2, CAM_B_AF_TH_2,,)\
    /* IMGO */\
    CMD(a, b, c, d, e, f, CAM_A_REG_IMGO_CON, CAM_A_IMGO_CON, CAM_B_IMGO_CON,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_IMGO_CON2, CAM_A_IMGO_CON2, CAM_B_IMGO_CON2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_IMGO_CON3, CAM_A_IMGO_CON3, CAM_B_IMGO_CON3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_IMGO_CON4, CAM_A_IMGO_CON4, CAM_B_IMGO_CON4,,)\
    /* PDO */\
    CMD(a, b, c, d, e, f, CAM_A_REG_PDO_CON, CAM_A_PDO_CON, CAM_B_PDO_CON,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_PDO_CON2, CAM_A_PDO_CON2, CAM_B_PDO_CON2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_PDO_CON3, CAM_A_PDO_CON3, CAM_B_PDO_CON3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_PDO_CON4, CAM_A_PDO_CON4, CAM_B_PDO_CON4,,)\
    /* RRZO */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZO_CON, CAM_A_RRZO_CON, CAM_B_RRZO_CON,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZO_CON2, CAM_A_RRZO_CON2, CAM_B_RRZO_CON2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZO_CON3, CAM_A_RRZO_CON3, CAM_B_RRZO_CON3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZO_CON4, CAM_A_RRZO_CON4, CAM_B_RRZO_CON4,,)\
    /* UFEO */\
    CMD(a, b, c, d, e, f, CAM_A_REG_UFEO_CON, CAM_A_UFEO_CON, CAM_B_UFEO_CON,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_UFEO_CON2, CAM_A_UFEO_CON2, CAM_B_UFEO_CON2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_UFEO_CON3, CAM_A_UFEO_CON3, CAM_B_UFEO_CON3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_UFEO_CON4, CAM_A_UFEO_CON4, CAM_B_UFEO_CON4,,)\

#define DUAL_ENGINE_LIST_HW_R_R(CMD, a, b, c, d, e, f) \
    /* IMGO */\
    CMD(a, b, c, d, e, f, CAM_A_REG_IMGO_BASE_ADDR, CAM_A_IMGO_BASE_ADDR, CAM_B_IMGO_BASE_ADDR,,)\
    /* AFO */\
    CMD(a, b, c, d, e, f, CAM_A_REG_AFO_BASE_ADDR, CAM_A_AFO_BASE_ADDR, CAM_B_AFO_BASE_ADDR,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AFO_STRIDE, CAM_A_AFO_STRIDE, CAM_B_AFO_STRIDE,,)\
    /* PDO */\
    CMD(a, b, c, d, e, f, CAM_A_REG_PDO_BASE_ADDR, CAM_A_PDO_BASE_ADDR, CAM_B_PDO_BASE_ADDR,,)\
    /* RRZO */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZO_BASE_ADDR, CAM_A_RRZO_BASE_ADDR, CAM_B_RRZO_BASE_ADDR,,)\
    /* UFEO */\
    CMD(a, b, c, d, e, f, CAM_A_REG_UFEO_BASE_ADDR, CAM_A_UFEO_BASE_ADDR, CAM_B_UFEO_BASE_ADDR,,)\

#define DUAL_ENGINE_LIST_HW_R_X(CMD, a, b, c, d, e, f) \
    /* TG */\
    CMD(a, b, c, d, e, f, CAM_A_REG_TG_SEN_GRAB_PXL, CAM_A_TG_SEN_GRAB_PXL, CAM_B_TG_SEN_GRAB_PXL,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_TG_SEN_GRAB_LIN, CAM_A_TG_SEN_GRAB_LIN, CAM_B_TG_SEN_GRAB_LIN,,)\

#define DUAL_ENGINE_LIST_HW_RW_RW(CMD, a, b, c, d, e, f) /* partial W */\
    /* ENABLE */\
    CMD(a, b, c, d, e, f, CAM_A_REG_CTL_EN, CAM_A_CTL_EN, CAM_B_CTL_EN,,)\
    /* AF */\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_SIZE, CAM_A_AF_SIZE, CAM_B_AF_SIZE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_BLK_1, CAM_A_AF_BLK_1, CAM_B_AF_BLK_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AF_VLD, CAM_A_AF_VLD, CAM_B_AF_VLD,,)\
    /* AFO */\
    CMD(a, b, c, d, e, f, CAM_A_REG_AFO_OFST_ADDR, CAM_A_AFO_OFST_ADDR, CAM_B_AFO_OFST_ADDR,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AFO_XSIZE, CAM_A_AFO_XSIZE, CAM_B_AFO_XSIZE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AFO_YSIZE, CAM_A_AFO_YSIZE, CAM_B_AFO_YSIZE,,)\
    /* IMGO */\
    CMD(a, b, c, d, e, f, CAM_A_REG_CTL_DMA_EN, CAM_A_CTL_DMA_EN, CAM_B_CTL_DMA_EN,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_IMGO_STRIDE, CAM_A_IMGO_STRIDE, CAM_B_IMGO_STRIDE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_IMGO_OFST_ADDR, CAM_A_IMGO_OFST_ADDR, CAM_B_IMGO_OFST_ADDR,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_IMGO_XSIZE, CAM_A_IMGO_XSIZE, CAM_B_IMGO_XSIZE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_IMGO_YSIZE, CAM_A_IMGO_YSIZE, CAM_B_IMGO_YSIZE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_IMGO_CROP, CAM_A_IMGO_CROP, CAM_B_IMGO_CROP,,)\
    /* PDO */\
    CMD(a, b, c, d, e, f, CAM_A_REG_PDO_STRIDE, CAM_A_PDO_STRIDE, CAM_B_PDO_STRIDE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_PDO_OFST_ADDR, CAM_A_PDO_OFST_ADDR, CAM_B_PDO_OFST_ADDR,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_PDO_XSIZE, CAM_A_PDO_XSIZE, CAM_B_PDO_XSIZE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_PDO_YSIZE, CAM_A_PDO_YSIZE, CAM_B_PDO_YSIZE,,)\
    /* RRZ */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZ_RLB_AOFST, CAM_A_RRZ_RLB_AOFST, CAM_B_RRZ_RLB_AOFST,,)\
    /* RRZO */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZO_STRIDE, CAM_A_RRZO_STRIDE, CAM_B_RRZO_STRIDE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZO_OFST_ADDR, CAM_A_RRZO_OFST_ADDR, CAM_B_RRZO_OFST_ADDR,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZO_XSIZE, CAM_A_RRZO_XSIZE, CAM_B_RRZO_XSIZE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZO_YSIZE, CAM_A_RRZO_YSIZE, CAM_B_RRZO_YSIZE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZO_CROP, CAM_A_RRZO_CROP, CAM_B_RRZO_CROP,,)\
    /* UFE */\
    CMD(a, b, c, d, e, f, CAM_A_REG_UFE_CON, CAM_A_UFE_CON, CAM_B_UFE_CON,,)\
    /* UFEO */\
    CMD(a, b, c, d, e, f, CAM_A_REG_UFEO_STRIDE, CAM_A_UFEO_STRIDE, CAM_B_UFEO_STRIDE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_UFEO_OFST_ADDR, CAM_A_UFEO_OFST_ADDR, CAM_B_UFEO_OFST_ADDR,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_UFEO_XSIZE, CAM_A_UFEO_XSIZE, CAM_B_UFEO_XSIZE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_UFEO_YSIZE, CAM_A_UFEO_YSIZE, CAM_B_UFEO_YSIZE,,)\
    /* PCROP */\
    CMD(a, b, c, d, e, f, CAM_A_REG_PCP_CROP_CON1, CAM_A_PCP_CROP_CON1, CAM_B_PCP_CROP_CON1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_PCP_CROP_CON2, CAM_A_PCP_CROP_CON2, CAM_B_PCP_CROP_CON2,,)\
    /* PSB */\
    CMD(a, b, c, d, e, f, CAM_A_REG_PSB_SIZE, CAM_A_PSB_SIZE, CAM_B_PSB_SIZE,,)\

#define DUAL_ENGINE_LIST_HW_RW_W(CMD, a, b, c, d, e, f) /* partial W */\
    /* DMX */\
    CMD(a, b, c, d, e, f, CAM_A_REG_DMX_CTL, CAM_A_DMX_CTL, CAM_B_DMX_CTL,,)\
    /* BPC */\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_BPC_TBLI1, CAM_A_BNR_BPC_TBLI1, CAM_B_BNR_BPC_TBLI1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_BPC_TBLI2, CAM_A_BNR_BPC_TBLI2, CAM_B_BNR_BPC_TBLI2,,)\
    /* CAC */\
    CMD(a, b, c, d, e, f, CAM_A_REG_CAC_TILE_OFFSET, CAM_A_CAC_TILE_OFFSET, CAM_B_CAC_TILE_OFFSET,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_CAC_TILE_SIZE, CAM_A_CAC_TILE_SIZE, CAM_B_CAC_TILE_SIZE,,)\
    /* LSC */\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSC_CTL2, CAM_A_LSC_CTL2, CAM_B_LSC_CTL2,,)/* partial W */\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSC_LBLOCK, CAM_A_LSC_LBLOCK, CAM_B_LSC_LBLOCK,,)/* partial W */\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSC_TPIPE_OFST, CAM_A_LSC_TPIPE_OFST, CAM_B_LSC_TPIPE_OFST,,)/* partial W */\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSC_TPIPE_SIZE, CAM_A_LSC_TPIPE_SIZE, CAM_B_LSC_TPIPE_SIZE,,)/* partial W */\
    /* PMX */\
    CMD(a, b, c, d, e, f, CAM_A_REG_PMX_CTL, CAM_A_PMX_CTL, CAM_B_PMX_CTL,,)\
    /* BMX */\
    CMD(a, b, c, d, e, f, CAM_A_REG_BMX_CTL, CAM_A_BMX_CTL, CAM_B_BMX_CTL,,)\
    /* AMX */\
    CMD(a, b, c, d, e, f, CAM_A_REG_AMX_CTL, CAM_A_AMX_CTL, CAM_B_AMX_CTL,,)\
    /* RRZ */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZ_OUT_IMG, CAM_A_RRZ_OUT_IMG, CAM_B_RRZ_OUT_IMG,,)/* partial W */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZ_HORI_STEP, CAM_A_RRZ_HORI_STEP, CAM_B_RRZ_HORI_STEP,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZ_VERT_STEP, CAM_A_RRZ_VERT_STEP, CAM_B_RRZ_VERT_STEP,,)/* 0 will be re-cal */\
    /* RMX */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMX_CTL, CAM_A_RMX_CTL, CAM_B_RMX_CTL,,)\

#define DUAL_ENGINE_LIST_HW_W_W(CMD, a, b, c, d, e, f) \
    /* DMX */\
    CMD(a, b, c, d, e, f, CAM_A_REG_DMX_CROP, CAM_A_DMX_CROP, CAM_B_DMX_CROP,,)\
    /* PBN */\
    CMD(a, b, c, d, e, f, CAM_A_REG_PBN_VSIZE, CAM_A_PBN_VSIZE, CAM_B_PBN_VSIZE,,)\
    /* SL2F */\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2F_XOFF, CAM_A_SL2F_XOFF, CAM_B_SL2F_XOFF,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2F_YOFF, CAM_A_SL2F_YOFF, CAM_B_SL2F_YOFF,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2F_SIZE, CAM_A_SL2F_SIZE, CAM_B_SL2F_SIZE,,)\
    /* SL2J */\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2J_XOFF, CAM_A_SL2J_XOFF, CAM_B_SL2J_XOFF,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2J_YOFF, CAM_A_SL2J_YOFF, CAM_B_SL2J_YOFF,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2J_SIZE, CAM_A_SL2J_SIZE, CAM_B_SL2J_SIZE,,)\
    /* CACI */\
    CMD(a, b, c, d, e, f, CAM_A_REG_CACI_OFST_ADDR, CAM_A_CACI_OFST_ADDR, CAM_B_CACI_OFST_ADDR,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_CACI_XSIZE, CAM_A_CACI_XSIZE, CAM_B_CACI_XSIZE,,)\
    /* LSCI */\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSCI_OFST_ADDR, CAM_A_LSCI_OFST_ADDR, CAM_B_LSCI_OFST_ADDR,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSCI_XSIZE, CAM_A_LSCI_XSIZE, CAM_B_LSCI_XSIZE,,)\
    /* RCROP */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RCP_CROP_CON1, CAM_A_RCP_CROP_CON1, CAM_B_RCP_CROP_CON1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RCP_CROP_CON2, CAM_A_RCP_CROP_CON2, CAM_B_RCP_CROP_CON2,,)\
    /* BNR */\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_POS, CAM_A_BNR_PDC_POS, CAM_B_BNR_PDC_POS,,)\
    /* PMX */\
    CMD(a, b, c, d, e, f, CAM_A_REG_PMX_CROP, CAM_A_PMX_CROP, CAM_B_PMX_CROP,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_PMX_VSIZE, CAM_A_PMX_VSIZE, CAM_B_PMX_VSIZE,,)\
    /* BMX */\
    CMD(a, b, c, d, e, f, CAM_A_REG_BMX_CROP, CAM_A_BMX_CROP, CAM_B_BMX_CROP,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BMX_VSIZE, CAM_A_BMX_VSIZE, CAM_B_BMX_VSIZE,,)\
    /* AMX */\
    CMD(a, b, c, d, e, f, CAM_A_REG_AMX_CROP, CAM_A_AMX_CROP, CAM_B_AMX_CROP,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_AMX_VSIZE, CAM_A_AMX_VSIZE, CAM_B_AMX_VSIZE,,)\
    /* RRZ */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZ_IN_IMG, CAM_A_RRZ_IN_IMG, CAM_B_RRZ_IN_IMG,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZ_HORI_INT_OFST, CAM_A_RRZ_HORI_INT_OFST, CAM_B_RRZ_HORI_INT_OFST,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZ_HORI_SUB_OFST, CAM_A_RRZ_HORI_SUB_OFST, CAM_B_RRZ_HORI_SUB_OFST,,)\
    /* RMX */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMX_CROP, CAM_A_RMX_CROP, CAM_B_RMX_CROP,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMX_VSIZE, CAM_A_RMX_VSIZE, CAM_B_RMX_VSIZE,,)\
    /* RCROP3 */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RCP3_CROP_CON1, CAM_A_RCP3_CROP_CON1, CAM_B_RCP3_CROP_CON1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RCP3_CROP_CON2, CAM_A_RCP3_CROP_CON2, CAM_B_RCP3_CROP_CON2,,)\

#define DUAL_ENGINE_LIST_HW_R_W(CMD, a, b, c, d, e, f) \
    /* DMX */\
    CMD(a, b, c, d, e, f, CAM_A_REG_DMX_VSIZE, CAM_A_DMX_VSIZE, CAM_B_DMX_VSIZE,,)\
    /* VBN */\
    CMD(a, b, c, d, e, f, CAM_A_REG_VBN_GAIN, CAM_A_VBN_GAIN, CAM_B_VBN_GAIN,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_VBN_OFST, CAM_A_VBN_OFST, CAM_B_VBN_OFST,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_VBN_TYPE, CAM_A_VBN_TYPE, CAM_B_VBN_TYPE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_VBN_SPARE, CAM_A_VBN_SPARE, CAM_B_VBN_SPARE,,)\
    /* SCM */\
    CMD(a, b, c, d, e, f, CAM_A_REG_SCM_CFG0, CAM_A_SCM_CFG0, CAM_B_SCM_CFG0,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SCM_CFG1, CAM_A_SCM_CFG1, CAM_B_SCM_CFG1,,)\
    /* DBN */\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBN_GAIN, CAM_A_DBN_GAIN, CAM_B_DBN_GAIN,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBN_OFST, CAM_A_DBN_OFST, CAM_B_DBN_OFST,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBN_SPARE, CAM_A_DBN_SPARE, CAM_B_DBN_SPARE,,)\
    /* PBN */\
    CMD(a, b, c, d, e, f, CAM_A_REG_PBN_TYPE, CAM_A_PBN_TYPE, CAM_B_PBN_TYPE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_PBN_LST, CAM_A_PBN_LST, CAM_B_PBN_LST,,)\
    /* BIN */\
    CMD(a, b, c, d, e, f, CAM_A_REG_BIN_CTL, CAM_A_BIN_CTL, CAM_B_BIN_CTL,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BIN_FTH, CAM_A_BIN_FTH, CAM_B_BIN_FTH,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BIN_SPARE, CAM_A_BIN_SPARE, CAM_B_BIN_SPARE,,)\
    /* SGM */\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGM_R_OFST_TABLE0_3, CAM_A_SGM_R_OFST_TABLE0_3, CAM_B_SGM_R_OFST_TABLE0_3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGM_R_OFST_TABLE4_7, CAM_A_SGM_R_OFST_TABLE4_7, CAM_B_SGM_R_OFST_TABLE4_7,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGM_R_OFST_TABLE8_11, CAM_A_SGM_R_OFST_TABLE8_11, CAM_B_SGM_R_OFST_TABLE8_11,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGM_R_OFST_TABLE12_15, CAM_A_SGM_R_OFST_TABLE12_15, CAM_B_SGM_R_OFST_TABLE12_15,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGM_G_OFST_TABLE0_3, CAM_A_SGM_G_OFST_TABLE0_3, CAM_B_SGM_G_OFST_TABLE0_3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGM_G_OFST_TABLE4_7, CAM_A_SGM_G_OFST_TABLE4_7, CAM_B_SGM_G_OFST_TABLE4_7,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGM_G_OFST_TABLE8_11, CAM_A_SGM_G_OFST_TABLE8_11, CAM_B_SGM_G_OFST_TABLE8_11,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGM_G_OFST_TABLE12_15, CAM_A_SGM_G_OFST_TABLE12_15, CAM_B_SGM_G_OFST_TABLE12_15,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGM_B_OFST_TABLE0_3, CAM_A_SGM_B_OFST_TABLE0_3, CAM_B_SGM_B_OFST_TABLE0_3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGM_B_OFST_TABLE4_7, CAM_A_SGM_B_OFST_TABLE4_7, CAM_B_SGM_B_OFST_TABLE4_7,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGM_B_OFST_TABLE8_11, CAM_A_SGM_B_OFST_TABLE8_11, CAM_B_SGM_B_OFST_TABLE8_11,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGM_B_OFST_TABLE12_15, CAM_A_SGM_B_OFST_TABLE12_15, CAM_B_SGM_B_OFST_TABLE12_15,,)\
    /* SL2F */\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2F_CEN, CAM_A_SL2F_CEN, CAM_B_SL2F_CEN,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2F_RR_CON0, CAM_A_SL2F_RR_CON0, CAM_B_SL2F_RR_CON0,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2F_RR_CON1, CAM_A_SL2F_RR_CON1, CAM_B_SL2F_RR_CON1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2F_GAIN, CAM_A_SL2F_GAIN, CAM_B_SL2F_GAIN,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2F_RZ, CAM_A_SL2F_RZ, CAM_B_SL2F_RZ,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2F_SLP_CON0, CAM_A_SL2F_SLP_CON0, CAM_B_SL2F_SLP_CON0,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2F_SLP_CON1, CAM_A_SL2F_SLP_CON1, CAM_B_SL2F_SLP_CON1,,)\
    /* SL2J */\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2J_CEN, CAM_A_SL2J_CEN, CAM_B_SL2J_CEN,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2J_RR_CON0, CAM_A_SL2J_RR_CON0, CAM_B_SL2J_RR_CON0,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2J_RR_CON1, CAM_A_SL2J_RR_CON1, CAM_B_SL2J_RR_CON1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2J_GAIN, CAM_A_SL2J_GAIN, CAM_B_SL2J_GAIN,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2J_RZ, CAM_A_SL2J_RZ, CAM_B_SL2J_RZ,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2J_SLP_CON0, CAM_A_SL2J_SLP_CON0, CAM_B_SL2J_SLP_CON0,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SL2J_SLP_CON1, CAM_A_SL2J_SLP_CON1, CAM_B_SL2J_SLP_CON1,,)\
    /* DBS */\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBS_SIGMA, CAM_A_DBS_SIGMA, CAM_B_DBS_SIGMA,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBS_BSTBL_0, CAM_A_DBS_BSTBL_0, CAM_B_DBS_BSTBL_0,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBS_BSTBL_1, CAM_A_DBS_BSTBL_1, CAM_B_DBS_BSTBL_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBS_BSTBL_2, CAM_A_DBS_BSTBL_2, CAM_B_DBS_BSTBL_2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBS_BSTBL_3, CAM_A_DBS_BSTBL_3, CAM_B_DBS_BSTBL_3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBS_CTL, CAM_A_DBS_CTL, CAM_B_DBS_CTL,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBS_CTL_2, CAM_A_DBS_CTL_2, CAM_B_DBS_CTL_2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBS_SIGMA_2, CAM_A_DBS_SIGMA_2, CAM_B_DBS_SIGMA_2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBS_YGN, CAM_A_DBS_YGN, CAM_B_DBS_YGN,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBS_SL_Y12, CAM_A_DBS_SL_Y12, CAM_B_DBS_SL_Y12,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBS_SL_Y34, CAM_A_DBS_SL_Y34, CAM_B_DBS_SL_Y34,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBS_SL_G12, CAM_A_DBS_SL_G12, CAM_B_DBS_SL_G12,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_DBS_SL_G34, CAM_A_DBS_SL_G34, CAM_B_DBS_SL_G34,,)\
    /* OB */\
    CMD(a, b, c, d, e, f, CAM_A_REG_OBC_OFFST0, CAM_A_OBC_OFFST0, CAM_B_OBC_OFFST0,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_OBC_OFFST1, CAM_A_OBC_OFFST1, CAM_B_OBC_OFFST1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_OBC_OFFST2, CAM_A_OBC_OFFST2, CAM_B_OBC_OFFST2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_OBC_OFFST3, CAM_A_OBC_OFFST3, CAM_B_OBC_OFFST3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_OBC_GAIN0, CAM_A_OBC_GAIN0, CAM_B_OBC_GAIN0,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_OBC_GAIN1, CAM_A_OBC_GAIN1, CAM_B_OBC_GAIN1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_OBC_GAIN2, CAM_A_OBC_GAIN2, CAM_B_OBC_GAIN2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_OBC_GAIN3, CAM_A_OBC_GAIN3, CAM_B_OBC_GAIN3,,)\
    /* BPCI */\
    CMD(a, b, c, d, e, f, CAM_A_REG_BPCI_XSIZE, CAM_A_BPCI_XSIZE, CAM_B_BPCI_XSIZE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BPCI_YSIZE, CAM_A_BPCI_YSIZE, CAM_B_BPCI_YSIZE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BPCI_STRIDE, CAM_A_BPCI_STRIDE, CAM_B_BPCI_STRIDE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BPCI_CON, CAM_A_BPCI_CON, CAM_B_BPCI_CON,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BPCI_CON2, CAM_A_BPCI_CON2, CAM_B_BPCI_CON2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BPCI_CON3, CAM_A_BPCI_CON3, CAM_B_BPCI_CON3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BPCI_CON4, CAM_A_BPCI_CON4, CAM_B_BPCI_CON4,,)\
    /* BPC */\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_BPC_CON, CAM_A_BNR_BPC_CON, CAM_B_BNR_BPC_CON,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_BPC_TH1, CAM_A_BNR_BPC_TH1, CAM_B_BNR_BPC_TH1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_BPC_TH2, CAM_A_BNR_BPC_TH2, CAM_B_BNR_BPC_TH2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_BPC_TH3, CAM_A_BNR_BPC_TH3, CAM_B_BNR_BPC_TH3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_BPC_TH4, CAM_A_BNR_BPC_TH4, CAM_B_BNR_BPC_TH4,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_BPC_DTC, CAM_A_BNR_BPC_DTC, CAM_B_BNR_BPC_DTC,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_BPC_COR, CAM_A_BNR_BPC_COR, CAM_B_BNR_BPC_COR,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_BPC_TH1_C, CAM_A_BNR_BPC_TH1_C, CAM_B_BNR_BPC_TH1_C,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_BPC_TH2_C, CAM_A_BNR_BPC_TH2_C, CAM_B_BNR_BPC_TH2_C,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_BPC_TH3_C, CAM_A_BNR_BPC_TH3_C, CAM_B_BNR_BPC_TH3_C,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_NR1_CON, CAM_A_BNR_NR1_CON, CAM_B_BNR_NR1_CON,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_NR1_CT_CON, CAM_A_BNR_NR1_CT_CON, CAM_B_BNR_NR1_CT_CON,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_RSV1, CAM_A_BNR_RSV1, CAM_B_BNR_RSV1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_RSV2, CAM_A_BNR_RSV2, CAM_B_BNR_RSV2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_CON, CAM_A_BNR_PDC_CON, CAM_B_BNR_PDC_CON,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_GAIN_L0, CAM_A_BNR_PDC_GAIN_L0, CAM_B_BNR_PDC_GAIN_L0,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_GAIN_L1, CAM_A_BNR_PDC_GAIN_L1, CAM_B_BNR_PDC_GAIN_L1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_GAIN_L2, CAM_A_BNR_PDC_GAIN_L2, CAM_B_BNR_PDC_GAIN_L2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_GAIN_L3, CAM_A_BNR_PDC_GAIN_L3, CAM_B_BNR_PDC_GAIN_L3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_GAIN_L4, CAM_A_BNR_PDC_GAIN_L4, CAM_B_BNR_PDC_GAIN_L4,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_GAIN_R0, CAM_A_BNR_PDC_GAIN_R0, CAM_B_BNR_PDC_GAIN_R0,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_GAIN_R1, CAM_A_BNR_PDC_GAIN_R1, CAM_B_BNR_PDC_GAIN_R1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_GAIN_R2, CAM_A_BNR_PDC_GAIN_R2, CAM_B_BNR_PDC_GAIN_R2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_GAIN_R3, CAM_A_BNR_PDC_GAIN_R3, CAM_B_BNR_PDC_GAIN_R3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_GAIN_R4, CAM_A_BNR_PDC_GAIN_R4, CAM_B_BNR_PDC_GAIN_R4,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_TH_GB, CAM_A_BNR_PDC_TH_GB, CAM_B_BNR_PDC_TH_GB,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_TH_IA, CAM_A_BNR_PDC_TH_IA, CAM_B_BNR_PDC_TH_IA,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_TH_HD, CAM_A_BNR_PDC_TH_HD, CAM_B_BNR_PDC_TH_HD,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_BNR_PDC_SL, CAM_A_BNR_PDC_SL, CAM_B_BNR_PDC_SL,,)\
    /* RMG */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMG_HDR_CFG, CAM_A_RMG_HDR_CFG, CAM_B_RMG_HDR_CFG,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMG_HDR_GAIN, CAM_A_RMG_HDR_GAIN, CAM_B_RMG_HDR_GAIN,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMG_HDR_CFG2, CAM_A_RMG_HDR_CFG2, CAM_B_RMG_HDR_CFG2,,)\
    /* RMM */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMM_OSC, CAM_A_RMM_OSC, CAM_B_RMM_OSC,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMM_MC, CAM_A_RMM_MC, CAM_B_RMM_MC,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMM_REVG_1, CAM_A_RMM_REVG_1, CAM_B_RMM_REVG_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMM_REVG_2, CAM_A_RMM_REVG_2, CAM_B_RMM_REVG_2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMM_LEOS, CAM_A_RMM_LEOS, CAM_B_RMM_LEOS,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMM_MC2, CAM_A_RMM_MC2, CAM_B_RMM_MC2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMM_DIFF_LB, CAM_A_RMM_DIFF_LB, CAM_B_RMM_DIFF_LB,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMM_MA, CAM_A_RMM_MA, CAM_B_RMM_MA,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RMM_TUNE, CAM_A_RMM_TUNE, CAM_B_RMM_TUNE,,)\
    /* CACI */\
    CMD(a, b, c, d, e, f, CAM_A_REG_CACI_YSIZE, CAM_A_CACI_YSIZE, CAM_B_CACI_YSIZE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_CACI_STRIDE, CAM_A_CACI_STRIDE, CAM_B_CACI_STRIDE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_CACI_CON, CAM_A_CACI_CON, CAM_B_CACI_CON,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_CACI_CON2, CAM_A_CACI_CON2, CAM_B_CACI_CON2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_CACI_CON3, CAM_A_CACI_CON3, CAM_B_CACI_CON3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_CACI_CON4, CAM_A_CACI_CON4, CAM_B_CACI_CON4,,)\
    /* LSC */\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSC_CTL1, CAM_A_LSC_CTL1, CAM_B_LSC_CTL1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSC_CTL3, CAM_A_LSC_CTL3, CAM_B_LSC_CTL3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSC_RATIO_0, CAM_A_LSC_RATIO_0, CAM_B_LSC_RATIO_0,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSC_RATIO_1, CAM_A_LSC_RATIO_1, CAM_B_LSC_RATIO_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSC_GAIN_TH, CAM_A_LSC_GAIN_TH, CAM_B_LSC_GAIN_TH,,)\
    /* LSCI */\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSCI_YSIZE, CAM_A_LSCI_YSIZE, CAM_B_LSCI_YSIZE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSCI_STRIDE, CAM_A_LSCI_STRIDE, CAM_B_LSCI_STRIDE,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSCI_CON, CAM_A_LSCI_CON, CAM_B_LSCI_CON,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSCI_CON2, CAM_A_LSCI_CON2, CAM_B_LSCI_CON2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSCI_CON3, CAM_A_LSCI_CON3, CAM_B_LSCI_CON3,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_LSCI_CON4, CAM_A_LSCI_CON4, CAM_B_LSCI_CON4,,)\
    /* HLR */\
    CMD(a, b, c, d, e, f, CAM_A_REG_HLR_CFG, CAM_A_HLR_CFG, CAM_B_HLR_CFG,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_HLR_GAIN, CAM_A_HLR_GAIN, CAM_B_HLR_GAIN,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_HLR_GAIN_1, CAM_A_HLR_GAIN_1, CAM_B_HLR_GAIN_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_HLR_OFST, CAM_A_HLR_OFST, CAM_B_HLR_OFST,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_HLR_OFST_1, CAM_A_HLR_OFST_1, CAM_B_HLR_OFST_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_HLR_IVGN, CAM_A_HLR_IVGN, CAM_B_HLR_IVGN,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_HLR_IVGN_1, CAM_A_HLR_IVGN_1, CAM_B_HLR_IVGN_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_HLR_KC, CAM_A_HLR_KC, CAM_B_HLR_KC,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_HLR_CFG_1, CAM_A_HLR_CFG_1, CAM_B_HLR_CFG_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_HLR_SL_PARA, CAM_A_HLR_SL_PARA, CAM_B_HLR_SL_PARA,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_HLR_SL_PARA_1, CAM_A_HLR_SL_PARA_1, CAM_B_HLR_SL_PARA_1,,)\
    /* CPG */\
    CMD(a, b, c, d, e, f, CAM_A_REG_CPG_SATU_1, CAM_A_CPG_SATU_1, CAM_B_CPG_SATU_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_CPG_SATU_2, CAM_A_CPG_SATU_2, CAM_B_CPG_SATU_2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_CPG_GAIN_1, CAM_A_CPG_GAIN_1, CAM_B_CPG_GAIN_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_CPG_GAIN_2, CAM_A_CPG_GAIN_2, CAM_B_CPG_GAIN_2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_CPG_OFST_1, CAM_A_CPG_OFST_1, CAM_B_CPG_OFST_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_CPG_OFST_2, CAM_A_CPG_OFST_2, CAM_B_CPG_OFST_2,,)\
    /* RPG */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RPG_SATU_1, CAM_A_RPG_SATU_1, CAM_B_RPG_SATU_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RPG_SATU_2, CAM_A_RPG_SATU_2, CAM_B_RPG_SATU_2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RPG_GAIN_1, CAM_A_RPG_GAIN_1, CAM_B_RPG_GAIN_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RPG_GAIN_2, CAM_A_RPG_GAIN_2, CAM_B_RPG_GAIN_2,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RPG_OFST_1, CAM_A_RPG_OFST_1, CAM_B_RPG_OFST_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RPG_OFST_2, CAM_A_RPG_OFST_2, CAM_B_RPG_OFST_2,,)\
    /* RRZ */\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZ_CTL, CAM_A_RRZ_CTL, CAM_B_RRZ_CTL,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZ_VERT_INT_OFST, CAM_A_RRZ_VERT_INT_OFST, CAM_B_RRZ_VERT_INT_OFST,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZ_VERT_SUB_OFST, CAM_A_RRZ_VERT_SUB_OFST, CAM_B_RRZ_VERT_SUB_OFST,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZ_MODE_TH, CAM_A_RRZ_MODE_TH, CAM_B_RRZ_MODE_TH,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_RRZ_MODE_CTL, CAM_A_RRZ_MODE_CTL, CAM_B_RRZ_MODE_CTL,,)\
    /* QBIN1 */\
    CMD(a, b, c, d, e, f, CAM_A_REG_QBN1_MODE, CAM_A_QBN1_MODE, CAM_B_QBN1_MODE,,)\
    /* QBIN4 */\
    CMD(a, b, c, d, e, f, CAM_A_REG_QBN4_MODE, CAM_A_QBN4_MODE, CAM_B_QBN4_MODE,,)\
    /* SGG2 */\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGG2_PGN, CAM_A_SGG2_PGN, CAM_B_SGG2_PGN,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGG2_GMRC_1, CAM_A_SGG2_GMRC_1, CAM_B_SGG2_GMRC_1,,)\
    CMD(a, b, c, d, e, f, CAM_A_REG_SGG2_GMRC_2, CAM_A_SGG2_GMRC_2, CAM_B_SGG2_GMRC_2,,)\
    /* PSB */\
    CMD(a, b, c, d, e, f, CAM_A_REG_PSB_CON, CAM_A_PSB_CON, CAM_B_PSB_CON,,)\

#define DUAL_SW_DECLARE(a, b, c, d, e, f, g, h, i,...) DUAL_SW_DECLARE_##i(a, b, c, d, e, f, g, h, i,...)
#define DUAL_SW_DECLARE_RW(a, b, c, d, e, f, g, h, i,...) DUAL_SW_DECLARE_W(a, b, c, d, e, f, g, h, i,...)
#define DUAL_SW_DECLARE_R(a, b, c, d, e, f, g, h, i,...) g h;
#define DUAL_SW_DECLARE_W(a, b, c, d, e, f, g, h, i,...) \
{\
    CHECK_ERROR_DUAL_CFG_##g##_##h##_##i = 0;\
}\

#define DUAL_IN_STRUCT_DECLARE(a, b, c, d, e, f, g, h,...) g h;

#define DUAL_ENGINE_DECLARE(a, b, c, d, e, f, g, h, i, j, k,...) g h;
#define DUAL_ENGINE_D_DECLARE(a, b, c, d, e, f, g, h, i, j, k,...) g i;

#define DUAL_IN_ARRAY_DECLARE(a, b, c, d, e, f, g, h, i, j, k, l,...) g h[l];
#define DUAL_IN_ARRAY_D_DECLARE(a, b, c, d, e, f, g, h, i, j, k, l,...) g i[l];

#define DUAL_OUT_ARRAY_DECLARE(a, b, c, d, e, f, g, h, i, j, k, l,...) g h[l];
#define DUAL_OUT_ARRAY_D_DECLARE(a, b, c, d, e, f, g, h, i, j, k, l,...) g i[l];

/* all data types must be int */
typedef struct DUAL_DEBUG_STRUCT
{
    int DUAL_LOG_EN;
    int DUAL_LOG_ID;
}DUAL_DEBUG_STRUCT;

/* all data types must be int */
typedef struct DUAL_SW_STRUCT
{
    DUAL_SW_STRUCT_LIST(DUAL_SW_DECLARE,,,,,,)
}DUAL_SW_STRUCT;

typedef struct DUAL_IN_CONFIG_STRUCT
{
    DUAL_CTRL_LIST_SW(DUAL_IN_STRUCT_DECLARE,,,,,,)
    DUAL_CTRL_LIST_HW(DUAL_IN_STRUCT_DECLARE,,,,,,)
    DUAL_ENGINE_LIST_HW_IN(DUAL_ENGINE_DECLARE,,,,,,)
    DUAL_ENGINE_LIST_HW_IN_D(DUAL_ENGINE_D_DECLARE,,,,,,)
    DUAL_ENGINE_ARRAY_HW(DUAL_IN_ARRAY_DECLARE,,,,,,)
    DUAL_ENGINE_ARRAY_HW(DUAL_IN_ARRAY_D_DECLARE,,,,,,)
}DUAL_IN_CONFIG_STRUCT;

typedef struct DUAL_OUT_CONFIG_STRUCT
{
    DUAL_ENGINE_LIST_HW_OUT(DUAL_ENGINE_DECLARE,,,,,,)
    DUAL_ENGINE_LIST_HW_OUT_D(DUAL_ENGINE_D_DECLARE,,,,,,)
    DUAL_ENGINE_ARRAY_HW(DUAL_OUT_ARRAY_DECLARE,,,,,,)
    DUAL_ENGINE_ARRAY_HW(DUAL_OUT_ARRAY_D_DECLARE,,,,,,)
}DUAL_OUT_CONFIG_STRUCT;

typedef struct ISP_REG_PTR_STRUCT
{
    DUAL_REG_UNI_STRUCT *ptr_isp_uni;
    DUAL_REG_A_STRUCT *ptr_isp_reg;
    DUAL_REG_B_STRUCT *ptr_isp_reg_d;
}ISP_REG_PTR_STRUCT;

extern int dual_cal_platform(ISP_REG_PTR_STRUCT *ptr_isp_reg_param, DUAL_IN_CONFIG_STRUCT *ptr_dual_in_config,
                      DUAL_OUT_CONFIG_STRUCT *ptr_dual_out_config);
extern int dual_printf_platform_config(const DUAL_IN_CONFIG_STRUCT *ptr_dual_in_config);
extern int dual_printf_platform_reg(const ISP_REG_PTR_STRUCT *ptr_isp_reg_param);
#endif
