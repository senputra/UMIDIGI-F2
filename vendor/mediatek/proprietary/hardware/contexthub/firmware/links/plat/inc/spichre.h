/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __PLAT_SPI_CHRE_H
#define __PLAT_SPI_CHRE_H

#include <gpio.h>
#include <platform.h>

#include <stdint.h>
#include <stdbool.h>
#include <mt_reg_base.h>


//#define EINVAL      201 /* Invalid argument */
#define ELEN        202 /* LEN more than 32byte */
#define EMODE       203 /* SPI more ERROR */
#define ESTATUS     204 /* Pause Status ERROR */

enum spi_sample_sel {
    POSEDGE,
    NEGEDGE
};
enum spi_cs_pol {
    ACTIVE_LOW,
    ACTIVE_HIGH
};

enum spi_cpol {
    SPI_CPOL_0,
    SPI_CPOL_1
};

enum spi_cpha {
    SPI_CPHA_0,
    SPI_CPHA_1
};

enum spi_mlsb {
    SPI_LSB,
    SPI_MSB
};

enum spi_endian {
    SPI_LENDIAN,
    SPI_BENDIAN
};

enum spi_transfer_mode {
    FIFO_TRANSFER,
    DMA_TRANSFER,
    OTHER1,
    OTHER2,
};

enum spi_pause_mode {
    PAUSE_MODE_DISABLE,
    PAUSE_MODE_ENABLE
};
enum spi_finish_intr {
    FINISH_INTR_DIS,
    FINISH_INTR_EN,
};

enum spi_deassert_mode {
    DEASSERT_DISABLE,
    DEASSERT_ENABLE
};

enum spi_ulthigh {
    ULTRA_HIGH_DISABLE,
    ULTRA_HIGH_ENABLE
};

enum spi_tckdly {
    TICK_DLY0,
    TICK_DLY1,
    TICK_DLY2,
    TICK_DLY3
};
enum spi_irq_flag {
    IRQ_IDLE,
    IRQ_BUSY
};

struct mt_chip_conf {
    uint32_t setuptime;
    uint32_t holdtime;
    uint32_t high_time;
    uint32_t low_time;
    uint32_t cs_idletime;
    uint32_t ulthgh_thrsh;
    enum spi_sample_sel sample_sel;
    enum spi_cs_pol cs_pol;
    enum spi_cpol cpol;
    enum spi_cpha cpha;
    enum spi_mlsb tx_mlsb;
    enum spi_mlsb rx_mlsb;
    enum spi_endian tx_endian;
    enum spi_endian rx_endian;
    enum spi_transfer_mode com_mod;
    enum spi_pause_mode pause;
    enum spi_finish_intr finish_intr;
    enum spi_deassert_mode deassert;
    enum spi_ulthigh ulthigh;
    enum spi_tckdly tckdly;
};

/*
 * secure dirver map region (via drApiMapPhys)
 * 1. t-driver will own virtual address
 * 2. SPI used virtual address range is 0x80000 - 0xFEFFF
 */


#define SPI_REG_CFG0        (0x00)
#define SPI_REG_CFG1        (0x04)
#define SPI_REG_TX_SRC      (0x08)
#define SPI_REG_RX_DST      (0x0C)
#define SPI_REG_TX_DATA     (0x10)
#define SPI_REG_RX_DATA     (0x14)
#define SPI_REG_CMD         (0x18)
#define SPI_REG_STATUS0     (0x1C)
#define SPI_REG_STATUS1     (0x20)
#define SPI_REG_PAD_SEL     (0x24)
#define SPI_REG_CFG2        (0x28)

/************************************************************************/

#define SPI_CFG0_CS_HOLD_OFFSET             0
#define SPI_CFG0_CS_SETUP_OFFSET            16

#define SPI_CFG0_CS_HOLD_MASK               0xffff
#define SPI_CFG0_CS_SETUP_MASK              0xffff0000

#define SPI_CFG1_CS_IDLE_OFFSET             0
#define SPI_CFG1_PACKET_LOOP_OFFSET         8
#define SPI_CFG1_PACKET_LENGTH_OFFSET       16
#define SPI_CFG1_GET_TICK_DLY_OFFSET        29

#define SPI_CFG1_CS_IDLE_MASK               0xff
#define SPI_CFG1_PACKET_LOOP_MASK           0xff00
#define SPI_CFG1_PACKET_LENGTH_MASK         0x3ff0000
#define SPI_CFG1_GET_TICK_DLY_MASK          0xe0000000

#define SPI_CFG2_SCK_HIGH_OFFSET            0
#define SPI_CFG2_SCK_LOW_OFFSET             16

#define SPI_CFG2_SCK_HIGH_MASK              0xffff
#define SPI_CFG2_SCK_LOW_MASK               0xffff0000


#define SPI_CMD_ACT_OFFSET                  0
#define SPI_CMD_RESUME_OFFSET               1
#define SPI_CMD_RST_OFFSET                  2
#define SPI_CMD_PAUSE_EN_OFFSET             4
#define SPI_CMD_DEASSERT_OFFSET             5
#define SPI_CMD_SAMPLE_SEL_OFFSET           6
#define SPI_CMD_CS_POL_OFFSET               7
#define SPI_CMD_CPHA_OFFSET                 8
#define SPI_CMD_CPOL_OFFSET                 9
#define SPI_CMD_RX_DMA_OFFSET               10
#define SPI_CMD_TX_DMA_OFFSET               11
#define SPI_CMD_TXMSBF_OFFSET               12
#define SPI_CMD_RXMSBF_OFFSET               13
#define SPI_CMD_RX_ENDIAN_OFFSET            14
#define SPI_CMD_TX_ENDIAN_OFFSET            15
#define SPI_CMD_FINISH_IE_OFFSET            16
#define SPI_CMD_PAUSE_IE_OFFSET             17

#define SPI_CMD_ACT_MASK                    0x1
#define SPI_CMD_RESUME_MASK                 0x2
#define SPI_CMD_RST_MASK                    0x4
#define SPI_CMD_PAUSE_EN_MASK               0x10
#define SPI_CMD_DEASSERT_MASK               0x20
#define SPI_CMD_SAMPLE_SEL_MASK             0x40
#define SPI_CMD_CS_POL_MASK                 0x80
#define SPI_CMD_CPHA_MASK                   0x100
#define SPI_CMD_CPOL_MASK                   0x200
#define SPI_CMD_RX_DMA_MASK                 0x400
#define SPI_CMD_TX_DMA_MASK                 0x800
#define SPI_CMD_TXMSBF_MASK                 0x1000
#define SPI_CMD_RXMSBF_MASK                 0x2000
#define SPI_CMD_RX_ENDIAN_MASK              0x4000
#define SPI_CMD_TX_ENDIAN_MASK              0x8000
#define SPI_CMD_FINISH_IE_MASK              0x10000
#define SPI_CMD_PAUSE_IE_MASK               0x20000

#define SPI_ULTRA_HIGH_EN_OFFSET            0
#define SPI_ULTRA_HIGH_THRESH_OFFSET        16

#define SPI_ULTRA_HIGH_EN_MASK              0x1
#define SPI_ULTRA_HIGH_THRESH_MASK          0xffff0000


struct spi_transfer {
    uint32_t    id;
    uint32_t    base;
    uint32_t    running;

    void        *tx_buf;
    void        *rx_buf;
    uint32_t    len;
    uint32_t    is_dma_used;
    uint32_t    is_transfer_end; /*for clear pause bit*/

    uint8_t     is_last_xfer;

    uint32_t    tx_dma; //dma_addr_t
    uint32_t    rx_dma; //dma_addr_t

    struct mt_chip_conf *chip_config;

    struct SpiDevice *spi_dev;

};



#define SPI_REG_GET32(addr)     (*(volatile uint32_t*)(addr))
#define SPI_REG_SET32(addr, val)    (*(volatile uint32_t*)(addr) = (val))

#define SPI_CHRE_READ(base, offset)      SPI_REG_GET32(base + offset)
#define SPI_CHRE_WRITE(base, offset, val)        SPI_REG_SET32(base + offset, val)

#define SPI_SET_BITS(REG, BS)       OUTREG32(REG, INREG32(REG) | (unsigned int)(BS))
#define SPI_CLR_BITS(REG, BS)       OUTREG32(REG, INREG32(REG) & (unsigned int)(~BS))

typedef void (*SCPDmaCallbackF)(struct spi_transfer *pdev, int err);
struct SCPDmaStreamState {
    SCPDmaCallbackF callback;
    void *cookie;
};

void dump_reg_config(uint32_t base);
void SCPSpiTimeoutHandler(uint32_t spi_id, uint32_t spi_base);
void startspiIrqTimer(struct spi_transfer *xfer);

#ifdef SPI_TEST_DEBUG
extern int SpiTest(int spi_id, int pad_select);
#endif
extern void mt_init_spi_irq();
extern void SCPSpiPollingHandle(uint32_t spi_id, uint32_t spi_base);
extern int spiMasterRxTxSync(struct SpiDevice *dev, void *rxBuf, void *txBuf,
                      size_t size);

//#define SPI_TEST_DEBUG
//#define SPI_PRINT_DEBUG
#define SPI_PRINT_ERR_DEBUG
#ifdef SPI_PRINT_DEBUG
#define SPITAG                  "[SPI-SCP] "
#define SPI_MSG(fmt, arg...)    PRINTF_D(SPITAG fmt, ##arg)
#define SPI_ERR(fmt, arg...)    PRINTF_E(SPITAG fmt, ##arg)
#define SPI_MSG_ISR(fmt, arg...)    PRINTF_D(SPITAG fmt, ##arg) //May need porting if print in ISR is supported
#define SPI_ERR_ISR(fmt, arg...)    PRINTF_E(SPITAG fmt, ##arg) //May need porting if print in ISR is supported

#elif defined(SPI_PRINT_ERR_DEBUG)
#define SPITAG                  "[SPI-SCP] "
#define SPI_MSG(fmt, arg...)
#define SPI_ERR(fmt, arg...)    PRINTF_E(SPITAG fmt, ##arg)
#define SPI_MSG_ISR(fmt, arg...)
#define SPI_ERR_ISR(fmt, arg...)    PRINTF_E(SPITAG fmt, ##arg) //May need porting if print in ISR is supported

#else
#define SPI_MSG(fmt, arg...)
#define SPI_ERR(fmt, arg...)
#define SPI_MSG_ISR(fmt, arg...)
#define SPI_ERR_ISR(fmt, arg...)
#endif

#endif /* __PLAT_SPI_H */
