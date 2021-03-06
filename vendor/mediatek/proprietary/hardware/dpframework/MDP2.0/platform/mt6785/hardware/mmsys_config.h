#ifndef __MMSYS_CONFIG_H__
#define __MMSYS_CONFIG_H__

#include "mmsys_reg_base.h"

#define MMSYS_INTEN                   (MMSYS_CONFIG_BASE + 0x000)
#define MMSYS_INTSTA                  (MMSYS_CONFIG_BASE + 0x004)
#define MJC_APB_TX_CON                (MMSYS_CONFIG_BASE + 0x00c)

#define IPU_MOUT_EN                   (MMSYS_CONFIG_BASE + 0xf14)
#define ISP_MOUT_EN                   (MMSYS_CONFIG_BASE + 0xf18)
#define MDP_AAL_MOUT_EN               (MMSYS_CONFIG_BASE + 0xf1c)
#define MDP_COLOR_MOUT_EN             (MMSYS_CONFIG_BASE + 0xf20)
#define MDP_RDMA0_MOUT_EN             (MMSYS_CONFIG_BASE + 0xf24)
#define MDP_RDMA1_MOUT_EN             (MMSYS_CONFIG_BASE + 0xf28)
#define MDP_PRZ0_MOUT_EN              (MMSYS_CONFIG_BASE + 0xf2c)
#define MDP_PRZ1_MOUT_EN              (MMSYS_CONFIG_BASE + 0xf30)
#define DISP_TO_WROT_SOUT_SEL         (MMSYS_CONFIG_BASE + 0xf4c)
#define MDP_CCORR_SOUT_SEL            (MMSYS_CONFIG_BASE + 0xf50)
#define MDP_COLOR_IN_SOUT_SEL         (MMSYS_CONFIG_BASE + 0xf54)
#define MDP_PATH0_SOUT_SEL            (MMSYS_CONFIG_BASE + 0xf58)
#define MDP_PATH1_SOUT_SEL            (MMSYS_CONFIG_BASE + 0xf5c)

#define DISP_DITHER0_MOUT_EN          (MMSYS_CONFIG_BASE + 0xf00)
#define DISP_OVL0_2L_MOUT_EN          (MMSYS_CONFIG_BASE + 0xf04)
#define DISP_OVL0_MOUT_EN             (MMSYS_CONFIG_BASE + 0xf08)
#define DISP_OVL1_2L_MOUT_EN          (MMSYS_CONFIG_BASE + 0xf0c)
#define DISP_RSZ_MOUT_EN              (MMSYS_CONFIG_BASE + 0xf10)

#define MMSYS_MOUT_RST                (MMSYS_CONFIG_BASE + 0x050)
#define DISP_WDMA0_SEL_IN             (MMSYS_CONFIG_BASE + 0xf84)
#define MDP_AAL_SEL_IN                (MMSYS_CONFIG_BASE + 0xf90)
#define MDP_CCORR_SEL_IN              (MMSYS_CONFIG_BASE + 0xf94)
#define MDP_COLOR_OUT_SEL_IN          (MMSYS_CONFIG_BASE + 0xf98)
#define MDP_COLOR_SEL_IN              (MMSYS_CONFIG_BASE + 0xf9c)
#define MDP_PATH0_SEL_IN              (MMSYS_CONFIG_BASE + 0xfa0)
#define MDP_PATH1_SEL_IN              (MMSYS_CONFIG_BASE + 0xfa4)
#define MDP_PRZ0_SEL_IN               (MMSYS_CONFIG_BASE + 0xfa8)
#define MDP_PRZ1_SEL_IN               (MMSYS_CONFIG_BASE + 0xfac)
#define MDP_TDSHP_SEL_IN              (MMSYS_CONFIG_BASE + 0xfb0)
#define MDP_WROT0_SEL_IN              (MMSYS_CONFIG_BASE + 0xfb4)
#define MDP_WROT1_SEL_IN              (MMSYS_CONFIG_BASE + 0xfb8)

#define DISP_RDMA0_RSZ_IN_SOUT_SEL_IN (MMSYS_CONFIG_BASE + 0xf40)
#define DISP_RDMA0_SOUT_SEL_IN        (MMSYS_CONFIG_BASE + 0xf44)
#define DISP_RDMA1_SOUT_SEL_IN        (MMSYS_CONFIG_BASE + 0xf48)
#define MDP_TO_DISP0_SOUT_SEL_IN      (MMSYS_CONFIG_BASE + 0xf60)
#define MDP_TO_DISP1_SOUT_SEL_IN      (MMSYS_CONFIG_BASE + 0xf64)
#define DISP_COLOR_OUT_SEL_IN         (MMSYS_CONFIG_BASE + 0xf68)
#define DISP_OVL0_2L_SEL_IN           (MMSYS_CONFIG_BASE + 0xf6c)
#define DISP_OVL0_SEL_IN              (MMSYS_CONFIG_BASE + 0xf70)
#define DISP_PATH0_SEL_IN             (MMSYS_CONFIG_BASE + 0xf74)
#define DISP_RDMA0_RSZ_OUT_SEL_IN     (MMSYS_CONFIG_BASE + 0xf78)
#define DISP_RSZ_SEL_IN               (MMSYS_CONFIG_BASE + 0xf7c)
#define DISP_WDMA0_PRE_SEL_IN         (MMSYS_CONFIG_BASE + 0xf80)
#define DSI0_SEL_IN                   (MMSYS_CONFIG_BASE + 0xf8c)
#define OVL_TO_RSZ_SEL_IN             (MMSYS_CONFIG_BASE + 0xfbc)
#define OVL_TO_WDMA_SEL_IN            (MMSYS_CONFIG_BASE + 0xfc0)
#define OVL_TO_WROT_SEL_IN            (MMSYS_CONFIG_BASE + 0xfc4)

#define MMSYS_MISC                    (MMSYS_CONFIG_BASE + 0x0f0)
#define MMSYS_SMI_LARB_SEL            (MMSYS_CONFIG_BASE + 0x0f4)
#define MMSYS_SODI_REQ_MASK           (MMSYS_CONFIG_BASE + 0x0f8)
#define MMSYS_CG_CON0                 (MMSYS_CONFIG_BASE + 0x100)
#define MMSYS_CG_SET0                 (MMSYS_CONFIG_BASE + 0x104)
#define MMSYS_CG_CLR0                 (MMSYS_CONFIG_BASE + 0x108)
#define MMSYS_CG_CON1                 (MMSYS_CONFIG_BASE + 0x110)
#define MMSYS_CG_SET1                 (MMSYS_CONFIG_BASE + 0x114)
#define MMSYS_CG_CLR1                 (MMSYS_CONFIG_BASE + 0x118)
#define MMSYS_HW_DCM_DIS0             (MMSYS_CONFIG_BASE + 0x120)
#define MMSYS_HW_DCM_DIS_SET0         (MMSYS_CONFIG_BASE + 0x124)
#define MMSYS_HW_DCM_DIS_CLR0         (MMSYS_CONFIG_BASE + 0x128)
#define MMSYS_HW_DCM_DIS1             (MMSYS_CONFIG_BASE + 0x130)
#define MMSYS_HW_DCM_DIS_SET1         (MMSYS_CONFIG_BASE + 0x134)
#define MMSYS_HW_DCM_DIS_CLR1         (MMSYS_CONFIG_BASE + 0x138)
#define MMSYS_SW0_RST_B               (MMSYS_CONFIG_BASE + 0x140)
#define MMSYS_SW1_RST_B               (MMSYS_CONFIG_BASE + 0x144)
#define MMSYS_LCM_RST_B               (MMSYS_CONFIG_BASE + 0x150)
#define LARB6_AXI_ASIF_CFG_WD         (MMSYS_CONFIG_BASE + 0x180)
#define LARB6_AXI_ASIF_CFG_RD         (MMSYS_CONFIG_BASE + 0x184)
#define PROC_TRACK_EMI_BUSY_CON       (MMSYS_CONFIG_BASE + 0x190)
#define DISP_FAKE_ENG_EN              (MMSYS_CONFIG_BASE + 0x200)
#define DISP_FAKE_ENG_RST             (MMSYS_CONFIG_BASE + 0x204)
#define DISP_FAKE_ENG_CON0            (MMSYS_CONFIG_BASE + 0x208)
#define DISP_FAKE_ENG_CON1            (MMSYS_CONFIG_BASE + 0x20c)
#define DISP_FAKE_ENG_RD_ADDR         (MMSYS_CONFIG_BASE + 0x210)
#define DISP_FAKE_ENG_WR_ADDR         (MMSYS_CONFIG_BASE + 0x214)
#define DISP_FAKE_ENG_STATE           (MMSYS_CONFIG_BASE + 0x218)
#define DISP_FAKE_ENG2_EN             (MMSYS_CONFIG_BASE + 0x220)
#define DISP_FAKE_ENG2_RST            (MMSYS_CONFIG_BASE + 0x224)
#define DISP_FAKE_ENG2_CON0           (MMSYS_CONFIG_BASE + 0x228)
#define DISP_FAKE_ENG2_CON1           (MMSYS_CONFIG_BASE + 0x22c)
#define DISP_FAKE_ENG2_RD_ADDR        (MMSYS_CONFIG_BASE + 0x230)
#define DISP_FAKE_ENG2_WR_ADDR        (MMSYS_CONFIG_BASE + 0x234)
#define DISP_FAKE_ENG2_STATE          (MMSYS_CONFIG_BASE + 0x238)
#define MMSYS_MBIST_CON               (MMSYS_CONFIG_BASE + 0x800)
#define MMSYS_MBIST_DONE0             (MMSYS_CONFIG_BASE + 0x804)
#define MMSYS_MBIST_DONE1             (MMSYS_CONFIG_BASE + 0x808)
#define MMSYS_MBIST_HOLDB             (MMSYS_CONFIG_BASE + 0x80c)
#define MMSYS_MBIST_MODE0             (MMSYS_CONFIG_BASE + 0x810)
#define MMSYS_MBIST_MODE1             (MMSYS_CONFIG_BASE + 0x814)
#define MMSYS_MBIST_MODE2             (MMSYS_CONFIG_BASE + 0x818)
#define MMSYS_MBIST_MODE3             (MMSYS_CONFIG_BASE + 0x81c)
#define MMSYS_MBIST_FAIL0             (MMSYS_CONFIG_BASE + 0x820)
#define MMSYS_MBIST_FAIL1             (MMSYS_CONFIG_BASE + 0x824)
#define MMSYS_MBIST_FAIL2             (MMSYS_CONFIG_BASE + 0x828)
#define MMSYS_MBIST_FAIL3             (MMSYS_CONFIG_BASE + 0x82c)
#define MMSYS_MBIST_DEBUG             (MMSYS_CONFIG_BASE + 0x830)
#define MMSYS_MBIST_DIAG_SCANOUT      (MMSYS_CONFIG_BASE + 0x834)
#define MMSYS_MBIST_PRE_FUSE          (MMSYS_CONFIG_BASE + 0x838)
#define MMSYS_MBIST_BSEL0             (MMSYS_CONFIG_BASE + 0x83c)
#define MMSYS_MBIST_DREQ              (MMSYS_CONFIG_BASE + 0x840)
#define MMSYS_MBIST_HDEN              (MMSYS_CONFIG_BASE + 0x844)
#define MDP_RDMA0_MEM_DELSEL0         (MMSYS_CONFIG_BASE + 0x848)
#define MDP_RDMA0_MEM_DELSEL1         (MMSYS_CONFIG_BASE + 0x84c)
#define MDP_RDMA1_MEM_DELSEL          (MMSYS_CONFIG_BASE + 0x850)
#define MDP_RSZ_MEM_DELSEL_0          (MMSYS_CONFIG_BASE + 0x854)
#define MDP_RSZ_MEM_DELSEL_1          (MMSYS_CONFIG_BASE + 0x858)
#define MDP_RSZ_MEM_DELSEL_2          (MMSYS_CONFIG_BASE + 0x85c)
#define MDP_TDSHP_MEM_DELSEL          (MMSYS_CONFIG_BASE + 0x860)
#define MDP_WROT_MEM_DELSEL0          (MMSYS_CONFIG_BASE + 0x864)
#define MDP_WROT_MEM_DELSEL1          (MMSYS_CONFIG_BASE + 0x868)
#define DISP_OVL0_MEM_DELSEL_0        (MMSYS_CONFIG_BASE + 0x86c)
#define DISP_OVL0_MEM_DELSEL_1        (MMSYS_CONFIG_BASE + 0x870)
#define DISP_OVL0_2L_MEM_DELSEL       (MMSYS_CONFIG_BASE + 0x874)
#define DISP_OVL1_2L_MEM_DELSEL       (MMSYS_CONFIG_BASE + 0x878)
#define DISP_RDMA_MEM_DELSEL          (MMSYS_CONFIG_BASE + 0x87C)
#define DISP_RDMA_UFO_MEM_DELSEL      (MMSYS_CONFIG_BASE + 0x880)
#define DISP_GAMMA_MEM_DELSEL         (MMSYS_CONFIG_BASE + 0x884)
#define DSI_MEM_DELSEL                (MMSYS_CONFIG_BASE + 0x888)
#define DISP_AAL_MEM_DELSEL           (MMSYS_CONFIG_BASE + 0x88C)
#define MDP_AAL_MEM_DELSEL            (MMSYS_CONFIG_BASE + 0x890)
#define DISP_RSZ_MEM_DELSEL           (MMSYS_CONFIG_BASE + 0x894)
#define DISP_WDMA_MEM_DELSEL          (MMSYS_CONFIG_BASE + 0x898)
#define MMSYS_DEBUG_OUT_SEL           (MMSYS_CONFIG_BASE + 0x89C)
#define MMSYS_MBIST_RP_RST_B          (MMSYS_CONFIG_BASE + 0x8A0)
#define MMSYS_MBIST_RP_FAIL0          (MMSYS_CONFIG_BASE + 0x8A4)
#define MMSYS_MBIST_RP_FAIL1          (MMSYS_CONFIG_BASE + 0x8A8)
#define MMSYS_MBIST_RP_FAIL2          (MMSYS_CONFIG_BASE + 0x8AC)
#define MMSYS_MBIST_RP_OK0            (MMSYS_CONFIG_BASE + 0x8B0)
#define MMSYS_MBIST_RP_OK1            (MMSYS_CONFIG_BASE + 0x8B4)
#define MMSYS_MBIST_RP_OK2            (MMSYS_CONFIG_BASE + 0x8B8)
#define MMSYS_DUMMY0                  (MMSYS_CONFIG_BASE + 0x8BC)
#define MMSYS_DUMMY1                  (MMSYS_CONFIG_BASE + 0x8C0)
#define MMSYS_DUMMY2                  (MMSYS_CONFIG_BASE + 0x8C4)
#define MMSYS_DUMMY3                  (MMSYS_CONFIG_BASE + 0x8C8)
#define MMSYS_DL_VALID_0              (MMSYS_CONFIG_BASE + 0x8CC)
#define MMSYS_DL_VALID_1              (MMSYS_CONFIG_BASE + 0x8D0)
#define MMSYS_DL_VALID_2              (MMSYS_CONFIG_BASE + 0x8D4)
#define MMSYS_DL_VALID_3              (MMSYS_CONFIG_BASE + 0x8D8)
#define MMSYS_DL_VALID_4              (MMSYS_CONFIG_BASE + 0x8DC)
#define MMSYS_DL_READY_0              (MMSYS_CONFIG_BASE + 0x8E0)
#define MMSYS_DL_READY_1              (MMSYS_CONFIG_BASE + 0x8E4)
#define MMSYS_DL_READY_2              (MMSYS_CONFIG_BASE + 0x8E8)
#define MMSYS_DL_READY_3              (MMSYS_CONFIG_BASE + 0x8EC)
#define MMSYS_DL_READY_4              (MMSYS_CONFIG_BASE + 0x8F0)
#define SMI_LARB_GREQ                 (MMSYS_CONFIG_BASE + 0x8F4)
#define MMSYS_MOUT_MASK_0             (MMSYS_CONFIG_BASE + 0x8F8)
#define MMSYS_MOUT_MASK_1             (MMSYS_CONFIG_BASE + 0x8FC)
#define MMSYS_MOUT_MASK_2             (MMSYS_CONFIG_BASE + 0x900)
#define MMSYS_POWER_READ              (MMSYS_CONFIG_BASE + 0x904)
#define MMSYS_HRT_WEIGHT_READ         (MMSYS_CONFIG_BASE + 0x908)
#define MDP_PWR_METER_CTL             (MMSYS_CONFIG_BASE + 0x90C)
#define DISP_PWR_METER_CTL            (MMSYS_CONFIG_BASE + 0x910)
#define MMSYS_GALS0                   (MMSYS_CONFIG_BASE + 0x914)
#define MMSYS_GALS1                   (MMSYS_CONFIG_BASE + 0x918)
#define MMSYS_GALS2                   (MMSYS_CONFIG_BASE + 0x91C)
#define MMSYS_GALS_DBG0               (MMSYS_CONFIG_BASE + 0x920)
#define MMSYS_GALS_DBG1               (MMSYS_CONFIG_BASE + 0x924)
#define MMSYS_GALS_DBG2               (MMSYS_CONFIG_BASE + 0x928)
#define MMSYS_GALS_DBG3               (MMSYS_CONFIG_BASE + 0x92C)
#define MMSYS_GALS_DBG4               (MMSYS_CONFIG_BASE + 0x930)
#define MMSYS_GALS_DBG5               (MMSYS_CONFIG_BASE + 0x934)
#define MDP_ASYNC_CFG_WD              (MMSYS_CONFIG_BASE + 0x938)
#define MDP_ASYNC_CFG_RD              (MMSYS_CONFIG_BASE + 0x93C)
#define MDP_ASYNC_IPU_CFG_WD          (MMSYS_CONFIG_BASE + 0x940)
#define MDP_ASYNC_IPU_CFG_RD          (MMSYS_CONFIG_BASE + 0x944)
#define MMSYS_R2Y                     (MMSYS_CONFIG_BASE + 0x948)
#define MDP_ASYNC_ISP_CFG_OUT_RD      (MMSYS_CONFIG_BASE + 0x958)
#define MDP_ASYNC_IPU_CFG_OUT_RD      (MMSYS_CONFIG_BASE + 0x95C)
#define TOP_RELAY_FSM_RD              (MMSYS_CONFIG_BASE + 0x960)
#define MMSYS_DBPI_SEL                (MMSYS_CONFIG_BASE + 0x964)
#define DISP_RDMA_VDE_SEL             (MMSYS_CONFIG_BASE + 0x968)
#define MMSYS_GALS_DBG6               (MMSYS_CONFIG_BASE + 0x96C)
#define MMSYS_GALS_DBG7               (MMSYS_CONFIG_BASE + 0x970)
#define MMSYS_GALS_DBG8               (MMSYS_CONFIG_BASE + 0x974)
#define MMSYS_GALS_DBG9               (MMSYS_CONFIG_BASE + 0x978)
#define MMSYS_GALS_DBGA               (MMSYS_CONFIG_BASE + 0x97C)
#define MMSYS_GALS_DBGB               (MMSYS_CONFIG_BASE + 0x980)
#define MMSYS_GALS_DBGC               (MMSYS_CONFIG_BASE + 0x984)
#define MMSYS_GALS_DBGD               (MMSYS_CONFIG_BASE + 0x988)
#define MMSYS_GALS_DBGE               (MMSYS_CONFIG_BASE + 0x98C)
#define MMSYS_GALS_DBGF               (MMSYS_CONFIG_BASE + 0x990)
#define ISP_RELAY_CFG_WD              (MMSYS_CONFIG_BASE + 0x994)
#define ISP_RELAY_CNT_RD              (MMSYS_CONFIG_BASE + 0x998)
#define ISP_RELAY_CNT_LATCH_RD        (MMSYS_CONFIG_BASE + 0x99C)
#define IPU_RELAY_CFG_WD              (MMSYS_CONFIG_BASE + 0x9A0)
#define IPU_RELAY_CNT_RD              (MMSYS_CONFIG_BASE + 0x9A4)
#define IPU_RELAY_CNT_LATCH_RD        (MMSYS_CONFIG_BASE + 0x9A8)
#define MMSYS_MBIST_BSEL5             (MMSYS_CONFIG_BASE + 0x9AC)
#define MDP_ASYNC_ISP_CFG_OUT_CNT_RD  (MMSYS_CONFIG_BASE + 0x9B0)
#define MDP_ASYNC_IPU_CFG_OUT_CNT_RD  (MMSYS_CONFIG_BASE + 0x9B4)

#define MMSYS_SW0_RST_B_MASK          (0xFFFFFFFF)
#define MMSYS_SW1_RST_B_MASK          (0xFFFFFFFF)
#define MDP_COLOR_IN_SOUT_SEL_MASK    (0x0F)
#define MDP_COLOR_OUT_SEL_IN_MASK     (0x0FFFF)
#define DISP_COLOR_OUT_SEL_IN_MASK    (0xFFFFFFFF)
#define MDP_ASYNC_CFG_WD_MASK         (0xFFFFFFFF)
#define MMSYS_HW_DCM_DIS0_MASK        (0xFFFFFFFF)
#define MMSYS_HW_DCM_DIS1_MASK        (0xFFFFFFFF)
#define MDP_ASYNC_CFG_WD_MASK         (0xFFFFFFFF)
#define ISP_RELAY_CFG_WD_MASK         (0xFFFFFFFF)
#define IPU_RELAY_CFG_WD_MASK         (0xFFFFFFFF)

#endif  // __MMSYS_CONFIG_H__
