/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2020. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

#include <linux/wireless.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "meta_cal_utils.h"

static void execute_wifi_cmd(struct iwreq *wrq, char* cmd)
{
    struct priv_driver_cmd_t priv_cmd;
    int ioctl_sock = 0;

    if (wrq == NULL || cmd == NULL) {
        return;
    }

    memset(wrq, 0, sizeof(struct iwreq));
    memset(&priv_cmd, 0, sizeof(struct priv_driver_cmd_t));
    strcpy(priv_cmd.buf, cmd);
    priv_cmd.used_len = strlen(priv_cmd.buf);
    priv_cmd.total_len = PRIV_CMD_SIZE;
    strncpy(wrq->ifr_name, "wlan0", (IFNAMSIZ - 1));
    wrq->u.data.pointer = &priv_cmd;
    wrq->u.data.length = strlen(priv_cmd.buf);

    ioctl_sock = socket(AF_INET, SOCK_DGRAM, 0);
    ioctl(ioctl_sock, IOCTL_GET_DRIVER, wrq);
    close(ioctl_sock);
}

unsigned int get_wifi_reg_val(char* cmd)
{
    struct iwreq wrq;
    unsigned int val = 0;

    execute_wifi_cmd(&wrq, cmd);
    val = (unsigned int)strtoul(wrq.u.data.pointer, NULL, 0);
    DBG("Get cmd[%s], val[0x%08x]\n", cmd, val);

    return val;
}

static int open_pmic_fd()
{
    unsigned int count = 0;
    int fd = -1;

    do {
        fd = open(PMIC_DEV, O_RDWR | O_NOCTTY);

        if (fd < 0) {
            count++;
            ERR("Cannot open device node(%s) count(%d)\n", PMIC_DEV, count);
            usleep(300000);

            if (count > MAX_FD_COUNT) {
                break;
            }
        }
        else
            break;
    } while(1);

    return fd;
}

static int prepare_pmic_reg(unsigned int addr) {
    int ret = 0;
    int size = 0;
    unsigned char buf[MAX_BUF_SIZE];
    memset(buf, 0, sizeof(buf));

    int fd = open_pmic_fd();

    if (fd < 0) {
        return -EFD;
    }

    if (snprintf(buf, MAX_BUF_SIZE, "%x", addr) < 0) {
        close(fd);
        return -ESNPRINTF;
    }

    size = write(fd, buf, strlen(buf));
    DBG("Prepare pmic reg[0x%s], size: %d\n", buf, size);
    close(fd);

    return ret;
}

int read_pmic_reg(unsigned int addr, unsigned int *val) {
    int ret = 0;
    int size = 0;
    unsigned char buf[MAX_BUF_SIZE];
    memset(buf, 0, sizeof(buf));

    ret = prepare_pmic_reg(addr);

    if (ret != 0) {
        return -EPMIC_PRE;
    }

    int fd = open_pmic_fd();

    if (fd < 0) {
        return -EFD;
    }

    size = read(fd, buf, MAX_BUF_SIZE);

    if (size > 0 && size < MAX_BUF_SIZE) {
        sscanf(buf, "0x%x\n", val);
        DBG("Read pmic reg[0x%x]=[%x]\n", addr, *val);
    } else {
        close(fd);
        return -EPMIC_R;
    }

    close(fd);

    return ret;
}

static int write_pmic_reg(unsigned int addr, unsigned int val) {
    int ret = 0;
    int size = 0;
    unsigned char buf[MAX_BUF_SIZE];
    memset(buf, 0, sizeof(buf));

    int fd = open_pmic_fd();

    if (fd < 0) {
        return -EFD;
    }

    if (snprintf(buf, MAX_BUF_SIZE, "%x %x", addr, val) < 0) {
        close(fd);
        return -ESNPRINTF;
    }

    size = write(fd, buf, strlen(buf));
    DBG("Write pmic cmd[%s], size[%d]\n", buf, size);
    close(fd);

    return ret;
}

int update_pmic_reg(unsigned int addr, unsigned int mask, unsigned int shift, unsigned int val) {
    int ret = 0;
    unsigned int orig = 0;
    unsigned int new_val = 0;

    ret = read_pmic_reg(addr, &orig);

    if (ret != 0) {
        return -EPMIC_R;
    }

    new_val = orig & ~(mask << shift);
    new_val |= (val << shift);

    if (orig != new_val) {
        DBG("Update pmic reg[0x%x] bits val[%d]\n", addr, val);
        ret = write_pmic_reg(addr, new_val);
    } else {
        DBG("Same as original value, ignore pmic reg[0x%x] update\n", addr);
    }

    return ret;
}

float convert_auxadc_to_temperature(unsigned int auxadc)
{
    double temp = 0;
    double u = 0;

    u = (auxadc - pow(2, 15)) / 32767.0;
    temp = 4311 / (log(u/(1-u)) + 4311 / 298.15) - 273.15;

    return (float)temp;
}