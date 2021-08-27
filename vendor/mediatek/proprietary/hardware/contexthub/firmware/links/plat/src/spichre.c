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

#include <errno.h>
#include <string.h>
#include <interrupt.h>
#include <spi.h>
#include <heap.h>
#include <spi_priv.h>
#include <util.h>

#include <timer.h>
#include <plat/inc/rtc.h>

#include <platform.h>
#include <plat/inc/spichre.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <driver_api.h>
#include <FreeRTOS.h>
#include <spichre-plat.h>
#ifdef CFG_MT6785_SPIISR_DEBUG
#include <spichre-plat-debug.h>
#endif

#define IDLE 0
#define INPROGRESS 1
#define PAUSED 2
#define SPI_FIFO_SIZE 32

#define PACKET_SIZE 0x400
#ifdef SPI_TEST_DEBUG
/*use this flag to sync every data transfer*/
#define SPI_ID     (1)
#define TEST_SIZE (1024)
#define PACKET_CNT (2) //fix value to 2 to avoid coverity issue
//static struct spi_transfer xfer_test;

char send_data[TEST_SIZE] = "\0"; //96780234123422343234423452345678";
char recv_data[TEST_SIZE] = "\0";
char send_data1[TEST_SIZE] = "\0"; //96780234123422343234423452345678";
char recv_data1[TEST_SIZE] = "\0";

struct SensorTask {
    // spi and interrupt
    spi_cs_t cs; //not used
    struct SpiMode mode; //not used
    struct SpiPacket packets[PACKET_CNT];
    struct SpiDevice *spiDev;
    int  pad_select;
};
struct SensorTask abc = {}; //Init as zero
#endif

static __attribute__((aligned(4))) char recv_fifo_data[SPI_FIFO_SIZE] = { 0 };

static struct mt_chip_conf mt_chip_conf_dma_test = {
    .setuptime = 10,
    .holdtime = 10,
    .high_time = 5,
    .low_time = 5,
    .cs_idletime = 10,
    .ulthgh_thrsh = 0,
    .cpol = 0,
    .cpha = 0,
    .rx_mlsb = 1,
    .tx_mlsb = 1,
    .tx_endian = 0,
    .rx_endian = 0,
    .com_mod = DMA_TRANSFER,
    .pause = 0,
    .finish_intr = 1,
    .deassert = 0,
    .ulthigh = 0,
    .tckdly = 0
};
static struct mt_chip_conf mt_chip_conf_fifo_test = {
    .setuptime = 10,
    .holdtime = 10,
    .high_time = 5,
    .low_time = 5,
    .cs_idletime = 10,
    .ulthgh_thrsh = 0,
    .cpol = 0,
    .cpha = 0,
    .rx_mlsb = 1,
    .tx_mlsb = 1,
    .tx_endian = 0,
    .rx_endian = 0,
    .com_mod = FIFO_TRANSFER,
    .pause = 0,
    .finish_intr = 1,
    .deassert = 0,
    .ulthigh = 0,
    .tckdly = 0
};


void dump_chip_config(struct mt_chip_conf *chip_config)
{
    if (chip_config != NULL) {
        SPI_MSG("setuptime=%d\n", (int)chip_config->setuptime);
        SPI_MSG("holdtime=%d\n", (int)chip_config->holdtime);
        SPI_MSG("high_time=%d\n", (int)chip_config->high_time);
        SPI_MSG("low_time=%d\n", (int)chip_config->low_time);
        SPI_MSG("cs_idletime=%d\n", (int)chip_config->cs_idletime);
        SPI_MSG("ulthgh_thrsh=%d\n", (int)chip_config->ulthgh_thrsh);
        SPI_MSG("cpol=%d\n", chip_config->cpol);
        SPI_MSG("cpha=%d\n", chip_config->cpha);
        SPI_MSG("tx_mlsb=%d\n", chip_config->tx_mlsb);
        SPI_MSG("rx_mlsb=%d\n", chip_config->rx_mlsb);
        SPI_MSG("tx_endian=%d\n", chip_config->tx_endian);
        SPI_MSG("rx_endian=%d\n", chip_config->rx_endian);
        SPI_MSG("com_mod=%d\n", chip_config->com_mod);
        SPI_MSG("pause=%d\n", chip_config->pause);
        SPI_MSG("finish_intr=%d\n", chip_config->finish_intr);
        SPI_MSG("deassert=%d\n", chip_config->deassert);
        SPI_MSG("ulthigh=%d\n", chip_config->ulthigh);
        SPI_MSG("tckdly=%d\n", chip_config->tckdly);
    } else {
        SPI_ERR("NULL chip_config!\n");
    }
}

void dump_reg_config(uint32_t base)
{
    SPI_MSG("SPI_REG_CFG0=0x%x\n", (unsigned int)SPI_CHRE_READ(base, SPI_REG_CFG0));
    SPI_MSG("SPI_REG_CFG1=0x%x\n", (unsigned int)SPI_CHRE_READ(base, SPI_REG_CFG1));
    SPI_MSG("SPI_REG_CFG2=0x%x\n", (unsigned int)SPI_CHRE_READ(base, SPI_REG_CFG2));
    SPI_MSG("SPI_REG_TX_SRC=0x%x\n", (unsigned int)SPI_CHRE_READ(base, SPI_REG_TX_SRC));
    SPI_MSG("SPI_REG_RX_DST=0x%x\n", (unsigned int)SPI_CHRE_READ(base, SPI_REG_RX_DST));
    SPI_MSG("SPI_REG_CMD=0x%x\n", (unsigned int)SPI_CHRE_READ(base, SPI_REG_CMD));
    SPI_MSG("SPI_REG_PAD_SEL=0x%x\n", (unsigned int)SPI_CHRE_READ(base, SPI_REG_PAD_SEL));
}

static uint32_t IsInterruptEnable(uint32_t base)
{
    uint32_t cmd;
    cmd = SPI_CHRE_READ(base, SPI_REG_CMD);
    return (cmd >> SPI_CMD_FINISH_IE_OFFSET) & 1;
}

static void inline clear_pause_bit(uint32_t base)
{
    uint32_t reg_val;

    reg_val = SPI_CHRE_READ(base, SPI_REG_CMD);
    reg_val &= ~SPI_CMD_PAUSE_EN_MASK;
    SPI_CHRE_WRITE(base, SPI_REG_CMD, reg_val);
}

static void inline SetPauseBit(uint32_t base)
{
    uint32_t reg_val;

    reg_val = SPI_CHRE_READ(base, SPI_REG_CMD);
    reg_val |= 1 << SPI_CMD_PAUSE_EN_OFFSET;
    SPI_CHRE_WRITE(base, SPI_REG_CMD, reg_val);
}

static void inline ClearResumeBit(uint32_t base)
{
    uint32_t reg_val;

    reg_val = SPI_CHRE_READ(base, SPI_REG_CMD);
    reg_val &= ~SPI_CMD_RESUME_MASK;
    SPI_CHRE_WRITE(base, SPI_REG_CMD, reg_val);
}

/*
*  SpiSetupPacket: used to define per data length and loop count
* @ ptr : data structure from User
*/
static int inline SpiSetupPacket(struct spi_transfer *xfer)
{
    uint32_t packet_size = 0;
    uint32_t packet_loop = 0;
    uint32_t cfg1 = 0;
    uint32_t base = xfer->base;

    /*set transfer packet and loop*/
    if (xfer->len < PACKET_SIZE)
        packet_size = xfer->len;
    else
        packet_size = PACKET_SIZE;

    if (xfer->len % packet_size) {
        ///packet_loop = xfer->len/packet_size + 1;
        /*parameter not correct, there will be more data transfer,notice user to change*/
        SPI_MSG("Lens(%u) not multiple of %d\n", (unsigned int)xfer->len, PACKET_SIZE);
    }
    packet_loop = (xfer->len) / packet_size;

    cfg1 = SPI_CHRE_READ(base, SPI_REG_CFG1);
    cfg1 &= ~(SPI_CFG1_PACKET_LENGTH_MASK + SPI_CFG1_PACKET_LOOP_MASK);
    cfg1 |= (packet_size - 1) << SPI_CFG1_PACKET_LENGTH_OFFSET;
    cfg1 |= (packet_loop - 1) << SPI_CFG1_PACKET_LOOP_OFFSET;
    SPI_CHRE_WRITE(base, SPI_REG_CFG1, cfg1);

    return 0;
}

static void inline SpiStartTransfer(uint32_t base)
{
    uint32_t reg_val;
    reg_val = SPI_CHRE_READ(base, SPI_REG_CMD);
    reg_val |= 1 << SPI_CMD_ACT_OFFSET;

    /*All register must be prepared before setting the start bit [SMP]*/
    SPI_CHRE_WRITE(base, SPI_REG_CMD, reg_val);

    return;
}

/*
*  SpiChipConfig: used to define per data length and loop count
* @ ptr : HW config setting from User
*/
int SpiChipConfig(uint32_t id, struct mt_chip_conf *ptr)
{
    struct mt_chip_conf *ChipConfig = SpiGetDefaultChipConfig(id);

    if (NULL == ptr) { //default
        ChipConfig->setuptime = 50;
        ChipConfig->holdtime = 50;
        ChipConfig->high_time = 5;
        ChipConfig->low_time = 5;
        ChipConfig->cs_idletime = 10;
        ChipConfig->ulthgh_thrsh = 0;

        ChipConfig->cpol = 0;
        ChipConfig->cpha = 0;
        ChipConfig->cs_pol = 0;
        ChipConfig->sample_sel = 0;

        ChipConfig->rx_mlsb = 1;
        ChipConfig->tx_mlsb = 1;

        ChipConfig->tx_endian = 0;
        ChipConfig->rx_endian = 0;

        ChipConfig->com_mod = DMA_TRANSFER;
        ChipConfig->pause = 0;
        ChipConfig->finish_intr = 1;
        ChipConfig->deassert = 0;
        ChipConfig->ulthigh = 0;
        ChipConfig->tckdly = 0;
        //dump_chip_config(ChipConfig);
        SetChipConfig(id, ChipConfig);
    } else {
        SetChipConfig(id, ptr);

    }
    return 0;
}

static void inline SpiDisableDma(uint32_t base)
{
    uint32_t  cmd;

    cmd = SPI_CHRE_READ(base, SPI_REG_CMD);
    cmd &= ~SPI_CMD_TX_DMA_MASK;
    cmd &= ~SPI_CMD_RX_DMA_MASK;
    SPI_CHRE_WRITE(base, SPI_REG_CMD, cmd);
}

#define INVALID_DMA_ADDRESS 0xffffffff

static inline void SpiEnableDma(struct spi_transfer *xfer, uint32_t mode)
{
    uint32_t cmd;
    uint32_t base = xfer->base;

    cmd = SPI_CHRE_READ(base, SPI_REG_CMD);
    SPI_MSG("SpiEnableDma tx_dma=0x%x,rx_dma=0x%x\n", (unsigned int)xfer->tx_dma , (unsigned int)xfer->rx_dma);


#define SPI_4B_ALIGN 0x4
    /* set up the DMA bus address */
    if ((mode == DMA_TRANSFER) || (mode == OTHER1)) {
        if ((xfer->tx_buf != NULL) || ((xfer->tx_dma != INVALID_DMA_ADDRESS) && (xfer->tx_dma != 0))) {
            if (xfer->tx_dma & (SPI_4B_ALIGN - 1)) {
                SPI_ERR("Tx_DMA addr not 4B align,buf:%p,dma:%x\n",
                        xfer->tx_buf, (unsigned int)xfer->tx_dma);
            }
            SPI_CHRE_WRITE(base, SPI_REG_TX_SRC, xfer->tx_dma);
            cmd |= 1 << SPI_CMD_TX_DMA_OFFSET;
        }
    }
    if ((mode == DMA_TRANSFER) || (mode == OTHER2)) {
        if ((xfer->rx_buf != NULL) || ((xfer->rx_dma != INVALID_DMA_ADDRESS) && (xfer->rx_dma != 0))) {
            if (xfer->rx_dma & (SPI_4B_ALIGN - 1)) {
                SPI_ERR("Rx_DMA addr not 4B align,buf:%p,dma:%x\n",
                        xfer->rx_buf, (unsigned int)xfer->rx_dma);
            }
            SPI_CHRE_WRITE(base, SPI_REG_RX_DST, xfer->rx_dma);
            cmd |= 1 << SPI_CMD_RX_DMA_OFFSET;
        }
    }

    SPI_MSG("SPI_REG_TX_SRC=0x%x\n", (unsigned int)SPI_CHRE_READ(base, SPI_REG_TX_SRC));
    SPI_MSG("SPI_REG_RX_DST=0x%x\n", (unsigned int)SPI_CHRE_READ(base, SPI_REG_RX_DST));

    SPI_CHRE_WRITE(base, SPI_REG_CMD, cmd);
}

static void  inline SpiResumeTransfer(uint32_t base)
{
    uint32_t reg_val;

    reg_val = SPI_CHRE_READ(base, SPI_REG_CMD);
    reg_val &= ~SPI_CMD_RESUME_MASK;
    reg_val |= 1 << SPI_CMD_RESUME_OFFSET;
    /*All register must be prepared before setting the start bit [SMP]*/
    SPI_CHRE_WRITE(base, SPI_REG_CMD, reg_val);

    return;
}

void ResetSpi(uint32_t base)
{
    uint32_t reg_val;

    /*set the software reset bit in SPI_REG_CMD.*/
    reg_val = SPI_CHRE_READ(base, SPI_REG_CMD);
    reg_val &= ~SPI_CMD_RST_MASK;
    reg_val |= 1 << SPI_CMD_RST_OFFSET;
    SPI_CHRE_WRITE(base, SPI_REG_CMD, reg_val);

    reg_val = SPI_CHRE_READ(base, SPI_REG_CMD);
    reg_val &= ~SPI_CMD_RST_MASK;
    SPI_CHRE_WRITE(base, SPI_REG_CMD, reg_val);

    SPI_MSG("ResetSpi!\n");

    return;
}

/*
* Write chip configuration to HW register
*/
int SpiSetup(struct spi_transfer *xfer)
{
    uint32_t reg_val, base;
    struct mt_chip_conf *chip_config = xfer->chip_config;
    int ret = 0;

    base = xfer->base;

    if (chip_config == NULL) {
        SPI_MSG("SpiSetup chip_config is NULL !!\n");
        return -EINVAL;
    } else {
        /*set the timing*/
        reg_val = SPI_CHRE_READ(base, SPI_REG_CFG2);
        reg_val &= ~(SPI_CFG2_SCK_HIGH_MASK | SPI_CFG2_SCK_LOW_MASK);
        reg_val |= ((chip_config->high_time - 1) << SPI_CFG2_SCK_HIGH_OFFSET);
        reg_val |= ((chip_config->low_time - 1) << SPI_CFG2_SCK_LOW_OFFSET);
        SPI_CHRE_WRITE(base, SPI_REG_CFG2, reg_val);

        reg_val = SPI_CHRE_READ(base, SPI_REG_CFG0);
        reg_val &= ~(SPI_CFG0_CS_HOLD_MASK | SPI_CFG0_CS_SETUP_MASK);
        reg_val |= ((chip_config->holdtime - 1) << SPI_CFG0_CS_HOLD_OFFSET);
        reg_val |= ((chip_config->setuptime - 1) << SPI_CFG0_CS_SETUP_OFFSET);
        SPI_CHRE_WRITE(base, SPI_REG_CFG0, reg_val);

        reg_val = SPI_CHRE_READ(base, SPI_REG_CFG1);
        reg_val &= ~(SPI_CFG1_CS_IDLE_MASK);
        reg_val |= ((chip_config->cs_idletime - 1) << SPI_CFG1_CS_IDLE_OFFSET);

        reg_val &= ~(SPI_CFG1_GET_TICK_DLY_MASK);
        reg_val |= ((chip_config->tckdly) << SPI_CFG1_GET_TICK_DLY_OFFSET);
        SPI_CHRE_WRITE(base, SPI_REG_CFG1, reg_val);

        /*config CFG1 bit[28:26] is 0*/
        reg_val = SPI_CHRE_READ(base, SPI_REG_CFG1);
        reg_val &= ~(0x7 << 26);
        SPI_CHRE_WRITE(base, SPI_REG_CFG1, reg_val);
#ifndef SPI_TEST_DEBUG
        SPI_CHRE_WRITE(base, SPI_REG_PAD_SEL, 0x0);
#else
        SPI_CHRE_WRITE(base, SPI_REG_PAD_SEL, abc.pad_select);
#endif
        /*set the mlsbx and mlsbtx*/
        reg_val = SPI_CHRE_READ(base, SPI_REG_CMD);
        reg_val &= ~(SPI_CMD_TX_ENDIAN_MASK | SPI_CMD_RX_ENDIAN_MASK);
        reg_val &= ~(SPI_CMD_TXMSBF_MASK | SPI_CMD_RXMSBF_MASK);
        reg_val &= ~(SPI_CMD_CPHA_MASK | SPI_CMD_CPOL_MASK);
        reg_val &= ~(SPI_CMD_SAMPLE_SEL_MASK | SPI_CMD_CS_POL_MASK);
        reg_val |= (chip_config->tx_mlsb << SPI_CMD_TXMSBF_OFFSET);
        reg_val |= (chip_config->rx_mlsb << SPI_CMD_RXMSBF_OFFSET);
        reg_val |= (chip_config->tx_endian << SPI_CMD_TX_ENDIAN_OFFSET);
        reg_val |= (chip_config->rx_endian << SPI_CMD_RX_ENDIAN_OFFSET);
        reg_val |= (chip_config->cpha << SPI_CMD_CPHA_OFFSET);
        reg_val |= (chip_config->cpol << SPI_CMD_CPOL_OFFSET);
        reg_val |= (chip_config->sample_sel << SPI_CMD_SAMPLE_SEL_OFFSET);
        reg_val |= (chip_config->cs_pol << SPI_CMD_CS_POL_OFFSET);
        SPI_CHRE_WRITE(base, SPI_REG_CMD, reg_val);

        /*set pause mode*/
        if (xfer->is_last_xfer == 0) { //if not last xfer use polling
            reg_val = SPI_CHRE_READ(base, SPI_REG_CMD);
            reg_val &= ~SPI_CMD_PAUSE_EN_MASK;
            reg_val &= ~ SPI_CMD_PAUSE_IE_MASK; /*disable pause IE in polling mode*/
        } else {
            reg_val |= (chip_config->pause << SPI_CMD_PAUSE_EN_OFFSET);
            SPI_CHRE_WRITE(base, SPI_REG_CMD, reg_val);

            reg_val = SPI_CHRE_READ(base, SPI_REG_CMD);
            reg_val &= ~SPI_CMD_PAUSE_EN_MASK;
            reg_val &= ~ SPI_CMD_PAUSE_IE_MASK;
            reg_val |= (chip_config->pause << SPI_CMD_PAUSE_EN_OFFSET);
            reg_val |= (chip_config->pause << SPI_CMD_PAUSE_IE_OFFSET);
            SPI_CHRE_WRITE(base, SPI_REG_CMD, reg_val);
        }


        if (xfer->is_last_xfer == 0) { //if not last xfer us polling

            reg_val = SPI_CHRE_READ(base, SPI_REG_CMD);
            reg_val &= ~ SPI_CMD_FINISH_IE_MASK;/*disable finish IE in polling mode*/
            SPI_CHRE_WRITE(base, SPI_REG_CMD, reg_val);
        } else {
            if(chip_config->com_mod == DMA_TRANSFER) {
                /*set finish interrupt always enable*/
                reg_val = SPI_CHRE_READ(base, SPI_REG_CMD);
                reg_val &= ~ SPI_CMD_FINISH_IE_MASK;
                reg_val |= (1 << SPI_CMD_FINISH_IE_OFFSET);
                SPI_CHRE_WRITE(base, SPI_REG_CMD, reg_val);
            }
        }

        /*set the communication of mode*/
        reg_val = SPI_CHRE_READ(base, SPI_REG_CMD);
        reg_val &= ~ SPI_CMD_TX_DMA_MASK;
        reg_val &= ~ SPI_CMD_RX_DMA_MASK;
        SPI_CHRE_WRITE(base, SPI_REG_CMD, reg_val);

        /*set deassert mode*/
        reg_val = SPI_CHRE_READ(base, SPI_REG_CMD);
        reg_val &= ~SPI_CMD_DEASSERT_MASK;
        reg_val |= (chip_config->deassert << SPI_CMD_DEASSERT_OFFSET);
        SPI_CHRE_WRITE(base, SPI_REG_CMD, reg_val);
    }
    return ret;
}


static void SpiRecvCheck(struct spi_transfer *xfer)
{
#ifdef SPI_TEST_DEBUG
    uint32_t cnt, i;

    SPI_MSG_ISR("SpiRecvCheck\n");

    cnt = (xfer->len % 4) ? (xfer->len / 4 + 1) : (xfer->len / 4);
    for (i = 0; i < cnt; i++) {
        if (*((uint32_t *) xfer->rx_dma + i) != *((uint32_t *) xfer->tx_dma + i)) {
            SPI_ERR_ISR("Error!! tx dma %d is:%x\n", (int)i, (unsigned int)(*((uint32_t *) xfer->tx_dma + i)));
            SPI_ERR_ISR("Error!! rx dma %d is:%x\n", (int)i, (unsigned int)(*((uint32_t *) xfer->rx_dma + i)));
       }
    }
#endif
}
void SCPSpiTimeoutHandler(uint32_t spi_id, uint32_t spi_base)
{
    SetPauseStatus(spi_id, IDLE);
    ResetSpi(spi_base);
    SetIrqFlag(spi_id, IRQ_IDLE);
    dump_reg_config(spi_base);
}

void SCPSpiPollingHandle(uint32_t spi_id, uint32_t spi_base)
{

    struct spi_transfer xfer_intr00;
    struct spi_transfer *xfer_intr = &xfer_intr00;
    struct mt_chip_conf *chip_config_intr = NULL;
    uint32_t reg_val, cnt;
    uint32_t i;
    uint32_t base = spi_base;
    uint32_t id = spi_id;

    SPI_MSG("SpiHandleIRQ%x\n", (unsigned int)id);

    xfer_intr = GetSpiTransfer(id);
    chip_config_intr = GetChipConfig(id);

    if (NULL == chip_config_intr) {
        SPI_MSG_ISR("NULL chip_config!\n");
        return;
    }

    /*pause mode*/
    if (chip_config_intr->pause) {
        if (GetPauseStatus(id) == INPROGRESS) {
            SetPauseStatus(id, PAUSED);
            SPI_MSG_ISR("IRQ set PAUSED state\n");
        } else {
            SPI_ERR_ISR("Invalid status.\n");
        }
    } else {
        SetPauseStatus(id, IDLE);
        SPI_MSG_ISR("IRQ set IDLE state\n");
    }

    SPI_MSG_ISR("start to read data !!\n");
    /*FIFO*/
    if ((chip_config_intr->com_mod == FIFO_TRANSFER) && xfer_intr->rx_buf) {
        SPI_MSG_ISR("xfer->len:%d\n", (int)xfer_intr->len);
        cnt = (xfer_intr->len % 4) ? (xfer_intr->len / 4 + 1) : (xfer_intr->len / 4);
        for (i = 0; i < cnt; i++) {
            reg_val = SPI_CHRE_READ(base, SPI_REG_RX_DATA); /*get the data from rx*/
            SPI_MSG_ISR("SPI_RX_DATA_REG:0x%x\n", (unsigned int)reg_val);
            *((uint32_t *)xfer_intr->rx_buf + i) = reg_val;
        }
    }
#ifdef CFG_MT6785_SPIISR_DEBUG
    spiISRDurDebug(3);
#endif

    if (chip_config_intr->com_mod == DMA_TRANSFER)
        SpiRecvCheck(xfer_intr);

    if (xfer_intr->is_last_xfer == 1 && xfer_intr->is_transfer_end == 1) {
        SetPauseStatus(id, IDLE);
        ResetSpi(base);
        SPI_MSG_ISR("Pause set IDLE state & disable clk\n");

#ifdef CFG_MT6785_SPIISR_DEBUG
        spiISRDurDebug(4);
#endif
    }
    else {
#ifdef CFG_MT6785_SPIISR_DEBUG
        spiISRDurDebug(4);
#endif
    }

    /*set irq flag to ask SpiNextMessage continue to run*/

    SetIrqFlag(id, IRQ_IDLE);

    SPI_MSG_ISR("SCPSpiHandle-----------xfer end-------\n");
    return;
}

void startspiIrqTimer(struct spi_transfer *xfer)
{
    if(((xfer->id) >= 0) && ((xfer->id) < SPI_HOST_NUM))
    {
        if(irqTimer[xfer->id].timerHandle == 0)
        {
            irqTimer[xfer->id].timerHandle = timTimerSet(irqTimer[xfer->id].timeOut, 0, 50, spiTimerCallback, xfer, true);
            if(irqTimer[xfer->id].timerHandle == 0)
            {
                SPI_ERR("timTimerSet failed!\n");
                configASSERT(0);
            }
        }
        else
        {
            SPI_ERR("SPI%lu timerHandler!=0 default\n", xfer->id);
            configASSERT(0);
        }
    }
    else
        SPI_ERR("start Irq Timer invalid id:%lu\n", xfer->id);
}

int SpiNextXfer(struct spi_transfer *xfer, SCPDmaCallbackF callback)
{
    uint32_t  mode, cnt, i;
    int ret = 0;

    SCPDMACallBack[xfer->id].callback = callback;
    SCPDMACallBack[xfer->id].cookie = xfer;
    struct mt_chip_conf *chip_config = GetChipConfig(xfer->id);

    if (chip_config == NULL) {
        SPI_MSG("SpiNextXfer NULL chip_config\n");
        return -EINVAL;
    }

    if ((!IsInterruptEnable(xfer->base))) {
        SPI_MSG("interrupt is disable\n");
    }

    mode = chip_config->com_mod;

    if ((mode == FIFO_TRANSFER)) {
        if (xfer->len > SPI_FIFO_SIZE) {
            ret = -ELEN;
            SPI_ERR("invalid xfer len\n");
            goto fail;
        }
    }

    /*
       * cannot 1K align & FIFO->DMA need used pause mode
       * this is to clear pause bit (CS turn to idle after data transfer done)
    */
    if (mode == DMA_TRANSFER) {
        if ((xfer->is_last_xfer == 1) && (xfer->is_transfer_end == 1))
            clear_pause_bit(xfer->base);
    } else if (mode == FIFO_TRANSFER) {
        if (xfer->is_transfer_end == 1)
            clear_pause_bit(xfer->base);
    } else {
        SPI_MSG("invalid xfer mode\n");
        ret = -EMODE;
        goto fail;
    }

    //SetPauseStatus(IDLE); //runing status, nothing about pause mode
    //disable DMA
    SpiDisableDma(xfer->base);

    /*need setting transfer data length & loop count*/
    SpiSetupPacket(xfer);

    /*Using FIFO to send data*/
    if ((mode == FIFO_TRANSFER)) {
        cnt = (xfer->len % 4) ? (xfer->len / 4 + 1) : (xfer->len / 4);
        for (i = 0; i < cnt; i++) {
            SPI_CHRE_WRITE(xfer->base, SPI_REG_TX_DATA, *((uint32_t *) xfer->tx_buf + i));
            SPI_MSG("tx_buf data is:%x\n", (unsigned int)(*((uint32_t *) xfer->tx_buf + i)));
            SPI_MSG("tx_buf addr is:%p\n", (uint32_t *)xfer->tx_buf + i);
        }
    }
    /*Using DMA to send data*/
    if ((mode == DMA_TRANSFER)) {
        SpiEnableDma(xfer, mode);
    }

    //SpiRecvCheck(xfer);
    SetSpiTransfer(xfer);

    SPI_MSG("xfer->id = %d, running=%d.\n", (int)xfer->id, (int)GetPauseStatus(xfer->id));

    if (GetPauseStatus(xfer->id) == PAUSED) { //running
        SPI_MSG("pause status to resume.\n");
        SetPauseStatus(xfer->id, INPROGRESS);   //set running status

        if (xfer->is_last_xfer == 1)
           startspiIrqTimer(xfer);

        SpiResumeTransfer(xfer->base);
    } else if (GetPauseStatus(xfer->id) == IDLE) {
        SPI_MSG("The xfer start\n");
        /*if there is only one transfer, pause bit should not be set.*/
        if ((chip_config->pause)) { // need to think whether is last  msg <&& !is_last_xfer(msg,xfer)>
            SPI_MSG("set pause mode.\n");
            SetPauseBit(xfer->base);
        }
        /*All register must be prepared before setting the start bit [SMP]*/

        SetPauseStatus(xfer->id, INPROGRESS);   //set running status

        if (xfer->is_last_xfer == 1)
            startspiIrqTimer(xfer);

        SpiStartTransfer(xfer->base);
        SPI_MSG("SpiStartTransfer\n");
    } else {
        SPI_MSG("Invalid pause status\n");
        ret = -ESTATUS;
        goto fail;
    }
    dump_reg_config(xfer->base);

    if (xfer->is_last_xfer ==
            0) //If pause mode is used, first transfer use polling, second transfer use interrupt -> spix_tz_irq_handler
        SpiPollingHandler(xfer); //ex: transfer 1048 byte data, first 1024 use polling, second 24 byte transfer use interrupt
    //Spi_disable_clk is disabled in second interrupt spix_tz_irq_handler -> SCPSpiDone -> Spi_disable_clk()
    /*exit pause mode*/
    if (GetPauseStatus(xfer->id) == PAUSED && xfer->is_last_xfer == 1) {
        ClearResumeBit(xfer->base);
    }
    return 0;
fail:
    SetPauseStatus(xfer->id, IDLE); //set running status
    ResetSpi(xfer->base);
    SetIrqFlag(xfer->id, IRQ_IDLE);
    return ret;
}

static void SCPSpiDone(struct spi_transfer *pdev, int err)
{
    SPI_MSG("Call SCPSpiDone\n");

    Spi_disable_clk(pdev->id);

    Spi_release_lock(pdev->id); /* This is interrup context, can only use isr version */

    spiMasterRxTxDone(pdev->spi_dev, err);
}

static int SpiNextMessage(struct spi_transfer *xfer)
{
    struct mt_chip_conf *chip_config;
    int ret = 0;

    chip_config = GetChipConfig(xfer->id);
    if (chip_config == NULL) {
        SPI_MSG("SpiNextMessage NULL chip_config\n");
        return -EINVAL;
    }

    ret = SpiSetup(xfer);
    if (ret < 0)
        return ret;
    ret = SpiNextXfer(xfer, SCPSpiDone);
    if (ret < 0)
        return ret;

    return ret;
}

int SpiTransfer(struct spi_transfer *xfer)
{
    int ret = 0;

    if ((!xfer)) {
        SPI_ERR("Transfer:NULL xfer.\n");
        goto out;
    }

    /*wait intrrupt had been clear*/
    while (IRQ_BUSY == GetIrqFlag(xfer->id)) {
        /*need a pause instruction to avoid unknow exception*/
        SPI_MSG("wait IRQ handle finish\n");
    }

    /*set flag to block next transfer*/
    SetIrqFlag(xfer->id, IRQ_BUSY);

    if (xfer) {
        ret = SpiNextMessage(xfer);
    }
    return ret;
out:
    return -EINVAL;

}

int spi_handle(struct spi_transfer* spiData, const struct SpiMode *mode)
{
    int ret = 0;
    uint32_t packet_loop, rest_size;
    uint32_t tmp_speed;
    uint32_t divider, sck_time;

    ret = config_spi_base(spiData);
    if (ret < 0)
        return ret;

    spiData->is_last_xfer = 1;
    Spi_enable_clk(spiData->id);

    SPI_MSG("tx_dma=0x%x,rx_dma=0x%x\n", (unsigned int)spiData->tx_dma , (unsigned int)spiData->rx_dma);
    SPI_MSG("xfer.len=%d, xfer.is_dma_used=%d\n ", (int)spiData->len, (int)spiData->is_dma_used);
    SPI_MSG("IRQ status=%d\n ", (int)GetIrqFlag(spiData->id));
    while (IRQ_BUSY == GetIrqFlag(spiData->id)) {
        /*need a pause instruction to avoid unknow exception*/
        SPI_MSG("IPC wait IRQ handle finish\n");
    }

    ret = SpiChipConfig(spiData->id, spiData->chip_config);
    if (ret < 0)
        return ret;

    /* Initialize CPOL, CPHA, DATA MSB/LSM and SPI speed */
    spiData->chip_config->cpol = mode->cpol;
    spiData->chip_config->cpha = mode->cpha;
    if(mode->format == SPI_FORMAT_MSB_FIRST)
    {
        spiData->chip_config->tx_mlsb = 1;
        spiData->chip_config->rx_mlsb = 1;
    }
    else
    {
        spiData->chip_config->tx_mlsb = 0;
        spiData->chip_config->rx_mlsb = 0;
    }

    tmp_speed = mode->speed;
    if (tmp_speed == 0) {
        SPI_MSG("Invalid spi speed 0Hz!! Use 8M instead.\n");
        tmp_speed = 8*1000000;
    }
    if (tmp_speed > (spi_clk_rate>>1)) {
        SPI_MSG("Too high spi speed(%d)! Use max spi_clk_rate/2 instead(%d).\n",
            tmp_speed, (spi_clk_rate>>1) );
        tmp_speed = spi_clk_rate>>1;
    }

    divider = (spi_clk_rate + (tmp_speed>>1)) / tmp_speed;
    sck_time = (divider+1)>>1;

    spiData->chip_config->high_time = sck_time;
    spiData->chip_config->low_time = sck_time;

#ifndef NO_DMA_LENGTH_LIMIT
    packet_loop = spiData->len / 1024;
    rest_size = spiData->len % 1024;
    SPI_MSG("packet_loop=%d,rest_size=%d\n", (int)packet_loop, (int)rest_size);

    if (spiData->len <= 1024 || rest_size == 0) {
        ret = SpiTransfer(spiData);
    } else {
        spiData->chip_config->pause = 1;
        SetChipConfig(spiData->id, spiData->chip_config);
        spiData->is_last_xfer = 0;
        spiData->len = 1024 * packet_loop;
        ret = SpiTransfer(spiData); //Use polling here
        if (ret < 0)
            goto fail;

        spiData->chip_config->pause = 0;
        SetChipConfig(spiData->id, spiData->chip_config);
        spiData->is_last_xfer = 1;
        spiData->len = rest_size;
        //xfer.rx_buf = xfer_p->rx_buf + 1024 * packet_loop ;
        //xfer.tx_buf = xfer_p->tx_buf + 1024 * packet_loop ;
        spiData->rx_dma = spiData->rx_dma + 1024 * packet_loop;
        spiData->tx_dma = spiData->tx_dma + 1024 * packet_loop;

        ret = SpiTransfer(spiData); //Use interrupt here
        /* If Transfer success, disable spi clk in IRQ handler done ->  SCPSpiDone() */
        if (ret < 0)
            goto fail;
        //xfer.rx_buf = xfer_p->rx_buf;
    }
#else
    ret = SpiTransfer(spiData);
    if (ret < 0)
        goto fail;
#endif
    return ret;

fail:
    Spi_disable_clk(spiData->id);
    return ret;
}

static int SCPSpiRxTx(struct SpiDevice *dev, void *rxBuf, const void *txBuf,
                      size_t size, const struct SpiMode *mode)
{
    int ret = 0;
    struct spi_transfer    *xfer_p = dev->pdata;

    SPI_MSG("SCPSpiRxTx Start\n");
    ret = Spi_get_lock(xfer_p->id);
    if(ret != 0)
        return ret;
    xfer_p->tx_dma = (uint32_t)txBuf;
    xfer_p->rx_dma = (uint32_t)rxBuf;
    xfer_p->len = size;
    //xfer_p->id already assigned in spiRequest
    xfer_p->is_dma_used = 1;
    xfer_p->is_transfer_end = 1;
    xfer_p->chip_config = &mt_chip_conf_dma_test;

    ret = spi_handle(xfer_p, mode);

    /* Any error happens during spi_handle, release lock here */
    /* Normally, lock will be released in isr context SCPSpiDone() */
    if(ret != 0)
        Spi_release_lock(xfer_p->id);
    return ret;
}

static int SCPSpiRelease(struct SpiDevice *dev)
{
    struct spi_transfer *xfer_p = dev->pdata;

    dev->pdata = NULL;
    heapFree(xfer_p);
    return 0;
}

const struct SpiDevice_ops mSCPSpiOps = {
    .masterRxTx = SCPSpiRxTx,
    .release = SCPSpiRelease,
};


int spiRequest(struct SpiDevice *dev, uint8_t busId)
{
    if (busId > (SPI_HOST_NUM - 1)) /* invalid SPI id */
        return -ENODEV;

    struct spi_transfer *xfer_p = heapAlloc(sizeof(struct spi_transfer));

    memset(xfer_p, 0, sizeof(struct spi_transfer));
    xfer_p->id = busId;
    xfer_p->spi_dev = dev;

    //spi_gpio_set(busId); //move to spi_init() to save time
    mt_init_spi_irq(busId);

    dev->ops = &mSCPSpiOps;
    dev->pdata = xfer_p;
    return 0;
}

#ifdef SPI_TEST_DEBUG
static void TESTSpiCallback(void *cookie, int err)
{
    /* NOTICE:  Please call osEnqueuePrivateEvt() here to trigger sensor event */
    SPI_MSG("Call TESTSpiCallback \n");
}

int SpiTest(int spi_id, int pad_select)
{
    int ret = 0;
    int i;

    /* Should be called in task Init */
    ret = spiMasterRequest(spi_id, &abc.spiDev);
    if (ret < 0) {
        SPI_ERR("spiMasterRequest() fail!\n");
        return ret;
    }
    spi_gpio_set(spi_id, pad_select);

    /* Initialize CPOL, CPHA, DATA MSB/LSM and SPI speed */
    abc.mode.cpol = SPI_CPOL_IDLE_LO;
    abc.mode.cpha = SPI_CPHA_LEADING_EDGE;
    abc.mode.format = SPI_FORMAT_MSB_FIRST;
    abc.mode.speed = spi_freq_2383333;
    abc.pad_select = pad_select;

    /* Initialize transfer rxBuf txBuf size and delay between two packets */
    for (i = 0; i < PACKET_CNT; i++) {
        if (i == 0) {
            abc.packets[i].rxBuf = &recv_data;

            abc.packets[i].txBuf = &send_data;
        } else {
            abc.packets[i].rxBuf = &recv_data1;

            abc.packets[i].txBuf = &send_data1;
        }
        abc.packets[i].size = TEST_SIZE;
        abc.packets[i].delay =
            0; //delay between packets, unit: nanosecnods  NOTICE: set delay as non zero have bug now due to no timer
    }
    /*Initialize tx pattern */
    for (i = 0; i < TEST_SIZE; i++) {
        send_data[i] = i % 16;
        send_data1[i] = i % 16;
    }

    SPI_MSG("Spitest Start\n");
    /* Notice: Sensor driver should Process rxBuf in TESTSpiCallback -> osEnqueuePrivateEvt  */
    ret = spiMasterRxTx(abc.spiDev, abc.cs,
                        abc.packets, PACKET_CNT, &abc.mode, TESTSpiCallback, NULL);
    if (ret < 0) {
        SPI_ERR("spiMasterRxTx() fail!\n");
        return ret;
    }

    /* Should be called in task end */
#if 0 //Mark here because we can not gurantee SPI transfer done when CPU comes here
    ret = spiMasterRelease(abc.spiDev);
    if (ret < 0) {
        SPI_ERR("spiMasterRelease() fail!\n");
        return ret;
    }
#endif

    SPI_MSG("Spitest End!! ret = %d\n", ret);
    return 0
           ;
}
#endif

static void _spi_fifo_setup(struct spi_transfer *xfer)
{
    unsigned int packet_size = xfer->len;
    unsigned int packet_loop = 1;

    unsigned int cfg1;

    SpiSetup(xfer);

    cfg1 = SPI_CHRE_READ(xfer->base, SPI_REG_CFG1) ;
    cfg1 &= 0xffff00ff;
    cfg1 |= (packet_loop - 1) << 8;
    cfg1 &= 0xfc00ffff;
    cfg1 |= (packet_size - 1) << 16;
    SPI_CHRE_WRITE(xfer->base, SPI_REG_CFG1, cfg1) ;
}

static int spi_fifo_sync(struct spi_transfer *xfer)
{
    unsigned int cnt, i;
    unsigned int cmd;

    xfer->is_last_xfer = 1;

    _spi_fifo_setup(xfer);

    cnt = (xfer->len % 4) ? (xfer->len / 4 + 1) : (xfer->len / 4);

    SPI_MSG("_spi_fifo_sync xfer->base = %p, xfer->len =%d, cnt = %d\n", xfer->base, xfer->len, cnt);
    for (i = 0; i < cnt; i++) {
        SPI_CHRE_WRITE(xfer->base, SPI_REG_TX_DATA, *((uint32_t *) xfer->tx_buf + i));
        SPI_MSG("_spi_fifo_sync tx_buf = %x\n", *((uint32_t *) xfer->tx_buf+i));
    }
    cmd = SPI_CHRE_READ(xfer->base, SPI_REG_CMD);
    cmd |= 0x01;
    cmd &= ~(SPI_CMD_FINISH_IE_MASK | SPI_CMD_PAUSE_IE_MASK);
    SPI_CHRE_WRITE(xfer->base, SPI_REG_CMD, cmd) ;

    /*wait for data transfer complete*/
    i = 0;
    do {
        i++;
        if (i > 10000000L) {
            break;
        }
    } while (((SPI_CHRE_READ(xfer->base, SPI_REG_STATUS1)) & 0x1) == 0);

    if (i > 10000000L)
        return -1;
    else
        return 0;
}

int spiMasterRxTxSync(struct SpiDevice *dev, void *rxBuf,
        void *txBuf, size_t size)
{
    unsigned int i, cnt, reg_val, ret;
    struct spi_transfer *xfer_intr = dev->pdata;

    SPI_MSG("spi_scp_sync start!\n");
    xfer_intr->tx_buf = (uint32_t *)txBuf;
    xfer_intr->rx_buf = (uint32_t *)recv_fifo_data;
    xfer_intr->len= size;

    ret = config_spi_base(xfer_intr);
    if (ret < 0)
        return ret;

    xfer_intr->chip_config = &mt_chip_conf_fifo_test;
    Spi_enable_clk(xfer_intr->id);
    SPI_MSG("spi_scp_sync start xfer_intr->id = %d\n", xfer_intr->id);

    ret = spi_fifo_sync(xfer_intr);
    if (ret < 0) {
        ResetSpi(xfer_intr->base);
        Spi_disable_clk(xfer_intr->id);
        SPI_ERR("sync func timeout!\n");
        return ret;
    }

    cnt = (xfer_intr->len % 4) ? (xfer_intr->len / 4 + 1) : (xfer_intr->len / 4);
    for (i = 0; i < cnt; i++) {
        reg_val = SPI_CHRE_READ(xfer_intr->base, SPI_REG_RX_DATA); /*get the data from rx*/
        SPI_MSG("SPI_RX_DATA_REG:0x%x\n", (unsigned int)reg_val);
        *((uint32_t *)xfer_intr->rx_buf + i) = reg_val;
    }
    memcpy(rxBuf, recv_fifo_data, size);
    ResetSpi(xfer_intr->base);
    Spi_disable_clk(xfer_intr->id);
    SPI_MSG("spi_scp_sync end!\n");
    return 0;
}


