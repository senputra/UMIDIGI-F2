#include "meta_wifi.h"

#include <cutils/properties.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <net/if_arp.h>		    /* For ARPHRD_ETHER */
#include <sys/socket.h>		    /* For AF_INET & struct sockaddr */
#include <netinet/in.h>         /* For struct sockaddr_in */
#include <netinet/if_ether.h>
#include <linux/wireless.h>

#include "cutils/misc.h"
#include "iwlibstub.h"


#include "libnvram.h"
#include <Custom_NvRam_LID.h>

#include "type.h"

#include "meta_afc/meta_afc.h"
#include "meta_c0c1/meta_c0c1.h"
#include "meta_utils/meta_cal_para.h"

#ifndef WIFI_DRV_MOD_PATH
#define WIFI_DRV_MOD_PATH         "/system/lib/modules/wlan.ko"
#endif
#ifndef WIFI_DRV_MOD_NAME
#define WIFI_DRV_MOD_NAME         "wlan"
#endif
#ifndef WIFI_DRV_MOD_ARG
#define WIFI_DRV_MOD_ARG          ""
#endif
#ifndef WIFI_TYPE_NAME
#define WIFI_TYPE_NAME            "wlan"
#endif

#define WIFI_POWER_PATH     "/dev/wmtWifi"

#define FREEIF(p)   do { if(p) free(p); p = NULL; } while(0)

//static const char DRIVER_MODULE_NAME[]  = WIFI_DRV_MOD_NAME;
//static const char DRIVER_MODULE_TAG[]   = WIFI_DRV_MOD_NAME " ";
//static const char DRIVER_MODULE_ARG[]   = WIFI_DRV_MOD_ARG;
//static const char DRIVER_MODULE_PATH[]  = WIFI_DRV_MOD_PATH;
//static const char MODULE_FILE[]         = "/proc/modules";

static int   wifi_init = 0;
static int   wifi_skfd = -1;
//static int   wifi_rfkill_id = -1;
//static char *wifi_rfkill_state_path = NULL;
static WIFI_CNF_CB cnf_cb = NULL;

//extern int init_module(void *, unsigned long, const char *);
//extern int delete_module(const char *, unsigned int);
extern int sched_yield(void);
extern int ifc_init();
extern int ifc_up(const char *name);
extern int ifc_down(const char *name);
extern void ifc_close();

static F_INFO  gNvInfo;

#if defined(SUPPORT_AFC_C0C1)
static F_INFO gGpsNv;
#endif
static void wifi_send_resp(FT_WM_WIFI_CNF *cnf, void *buf, unsigned int size)
{
    if (cnf_cb)
        cnf_cb(cnf, buf, size);
    else
        WriteDataToPC(cnf, sizeof(FT_WM_WIFI_CNF), buf, size);
}

int write_data_to_driver(char *data, size_t length)
{
    int sz;
    int fd = -1;
    int ret = -1;
    int retry_cont;

    if (!data || !length)
        return ret;

    for (retry_cont = 0; retry_cont < 5; retry_cont++)
    {
        DBG("open retry_cont = (%d)", retry_cont);
        fd = open(WIFI_POWER_PATH, O_WRONLY);

        if (fd < 0)
        {
            usleep(1000000);
        }
        else
            break;
    }

    if (fd < 0)
    {
        DBG("open(%s) for write failed: %s (%d)", WIFI_POWER_PATH,
            strerror(errno), errno);
        goto out;
    }

    for (retry_cont = 0; retry_cont < 5; retry_cont++)
    {
        DBG("write retry_cont = (%d)", retry_cont);
        sz = write(fd, data, length);

        if (sz < 0)
        {
#if 0
            DBG("write(%s) failed: %s (%d)", WIFI_POWER_PATH, strerror(errno),
                errno);
            goto out;
#endif

            usleep(1000000);
        }
        else
            break;
    }

    if (sz > 0)
        ret = 0;
    else
    {
        DBG("write(%s) failed: %s (%d)", WIFI_POWER_PATH, strerror(errno),
            errno);
    }

out:

    if (fd >= 0)
        close(fd);

    return ret;
}
#if defined(SUPPORT_AFC_C0C1)
WLAN_STATUS CO_TMS_NVRAMCtrl(F_INFO *gNv, int file_lid, unsigned int offset, unsigned char value)
{
    int ret = -1;
    int iFD = -1;
    PNVRAM_ACCESS_STRUCT pnvram = NULL;
    pnvram = (PNVRAM_ACCESS_STRUCT)malloc(sizeof(NVRAM_ACCESS_STRUCT) + sizeof(unsigned char));

    if (!pnvram)
    {
        DBG("[META_CAL] Out of memory in allocating pnvram\n");
        return META_WIFI_STATUS_FAIL;
    }

    pnvram->dataLen = sizeof(unsigned char);
    pnvram->dataOffset = offset;
    memcpy(&pnvram->data[0], &value, sizeof(value));

    DBG("[META_CAL] Write offset:%d (0x%04X)\n", pnvram->dataOffset, pnvram->dataOffset);
    iFD = open(gNv->cFileName, O_WRONLY | O_CREAT, S_IRUSR | S_IRGRP);

    if (iFD >= 0)
    {
        if (lseek(iFD, pnvram->dataOffset, SEEK_SET) < 0)
        {
            ERR("[META_CAL] Fail to read nvram");
            close(iFD);
            return META_WIFI_STATUS_FAIL;
        }

        write(iFD, pnvram->data, pnvram->dataLen);
        close(iFD);

        // Invoke protect data file mechanism
        if (NVM_ProtectDataFile(file_lid, 1) != 1)
        {
            ERR("[META_CAL] Fail to set NVM_ProtectDataFile()\n");
            ret = META_WIFI_STATUS_FAIL;
        }
        else
        {
            // Invoke auto backup mechanism
            NVM_AddBackupFileNum(file_lid);
            ret = META_WIFI_STATUS_SUCCESS;
        }
    }
    else
    {
        ERR("[META_CAL] Fail to open file[%s], iFD[%d]\n", gNv->cFileName, iFD);
        return META_WIFI_STATUS_FAIL;
    }

    FREEIF(pnvram);

    return ret;
}
#endif

/*
* Control Wi-Fi power by RFKILL interface is deprecated.
* Use character device to control instead.
*/
#if 0
static int wifi_init_rfkill(void)
{
    char path[128];
    char buf[32];
    int fd, id;
    ssize_t sz;

    for (id = 0; id < 10 ; id++) {
        snprintf(path, sizeof(path), "/sys/class/rfkill/rfkill%d/type", id);
        fd = open(path, O_RDONLY);
        if (fd < 0) {
            printf("open(%s) failed: %s (%d)\n", path, strerror(errno), errno);
            return -1;
        }
        sz = read(fd, &buf, sizeof(buf));
        close(fd);
        if (sz >= (ssize_t)strlen(WIFI_TYPE_NAME) &&
            memcmp(buf, WIFI_TYPE_NAME, strlen(WIFI_TYPE_NAME)) == 0) {
            wifi_rfkill_id = id;
            break;
        }
    }

    if (id == 10)
        return -1;

    asprintf(&wifi_rfkill_state_path, "/sys/class/rfkill/rfkill%d/state",
        wifi_rfkill_id);

    return 0;
}

static int wifi_check_power(void) {
    int sz;
    int fd = -1;
    int ret = -1;
    char buf;
    char *path = wifi_rfkill_state_path;

    if ((wifi_rfkill_id == -1) && wifi_init_rfkill())
        goto out;

    fd = open(path, O_RDONLY);
    if (fd < 0) {
        printf("open(%s) failed: %s (%d)", path, strerror(errno),
            errno);
        goto out;
    }
    sz = read(fd, &buf, 1);
    if (sz != 1) {
        printf("read(%s) failed: %s (%d)", path, strerror(errno),
            errno);
        goto out;
    }

    switch (buf) {
    case '1':
        ret = 1;
        break;
    case '0':
        ret = 0;
        break;
    }

out:
    if (fd >= 0)
        close(fd);
    return ret;
}

static int wifi_set_power(int on)
{
    int sz;
    int fd = -1;
    int ret = -1;
    const char buf = (on ? '1' : '0');

    if (wifi_rfkill_id == -1) {
        if (wifi_init_rfkill()) goto out;
    }

    fd = open(wifi_rfkill_state_path, O_WRONLY);
    if (fd < 0) {
        printf("open(%s) for write failed: %s (%d)", wifi_rfkill_state_path,
             strerror(errno), errno);
        goto out;
    }
    sz = write(fd, &buf, 1);
    if (sz < 0) {
        printf("write(%s) failed: %s (%d)", wifi_rfkill_state_path, strerror(errno),
             errno);
        goto out;
    }
    ret = 0;

out:
    if (fd >= 0) close(fd);
    return ret;
}
#else

static int wifi_set_power(int on)
{
    int sz;
    int fd = -1;
    int ret = -1;
    const char buf = (on ? '1' : '0');
    char value[128];
    int nvramReady = 0;

    if (on) {
        DBG("Busy waiting for nvram ready...");
        while(1) {
            property_get("vendor.mtk.nvram.ready", value, "0");
            nvramReady = atoi(value);
            if (nvramReady == 1) {
                break;
            }
        }
        DBG("NVRAM is sent to wifi driver.");
    }

    fd = open(WIFI_POWER_PATH, O_WRONLY);
    if (fd < 0) {
        DBG("open(%s) for write failed: %s (%d)", WIFI_POWER_PATH,
             strerror(errno), errno);
        goto out;
    }
    sz = write(fd, &buf, 1);
    if (sz < 0) {
        DBG("write(%s) failed: %s (%d)", WIFI_POWER_PATH, strerror(errno),
             errno);
        goto out;
    }
    ret = 0;

out:
    if (fd >= 0) close(fd);
    return ret;
}
#endif

#if 0
static int wifi_insmod(const char *filename, const char *args)
{
    void *module;
    unsigned int size;
    int ret;

    module = load_file(filename, &size);
    if (!module)
        return -1;

    ret = init_module(module, size, args);

    free(module);

    return ret;
}

static int wifi_rmmod(const char *modname)
{
    int ret = -1;
    int maxtry = 10;

    while (maxtry-- > 0) {
        ret = delete_module(modname, O_NONBLOCK | O_EXCL);
        if (ret < 0 && errno == EAGAIN)
            usleep(500000);
        else
            break;
    }

    if (ret != 0)
        ERR("Unable to unload driver \"%s\": %s\n", modname, strerror(errno));

    return ret;
}

static int wifi_is_loaded(void)
{
    FILE *proc;
    char line[sizeof(DRIVER_MODULE_TAG)+10];

    if ((proc = fopen(MODULE_FILE, "r")) == NULL) {
        ERR("Could not open %s: %s", MODULE_FILE, strerror(errno));
        return 0;
    }
    while ((fgets(line, sizeof(line), proc)) != NULL) {
        if (strncmp(line, DRIVER_MODULE_TAG, strlen(DRIVER_MODULE_TAG)) == 0) {
            fclose(proc);
            return 1;
        }
    }
    fclose(proc);
    return 0;
}
#endif

void removeSubstring(char *s,const char *toremove)
{
    while((s=strstr(s,toremove)) != NULL)
        memmove(s,s+strlen(toremove),1+strlen(s+strlen(toremove)));

}
/*----------------------------------------------------------------------------*/
/**
* @brief remove Script's head command, inclue: adb, shell, iwpriv,wlan0,driver
*
* @param[in] pStr, input string
*
* @return new command size
*/
/*----------------------------------------------------------------------------*/

#define WIFI_REMOVE_HEAD_SIZE 5
int wifiScriptRemoveHead(char *pStr)
{
    int strIndex = 0;
    char *removeStrArray[WIFI_REMOVE_HEAD_SIZE] = {
        "adb ",
        "shell ",
        "iwpriv ",
        "wlan0 ",
        "driver ",
    };

    if(!pStr)
        return FALSE;

    for (strIndex = 0 ; strIndex < WIFI_REMOVE_HEAD_SIZE ; strIndex++)
    {
        if(strncmp(pStr,removeStrArray[strIndex],strlen(removeStrArray[strIndex])) == 0)
            removeSubstring(pStr,removeStrArray[strIndex]);
    }

    return strlen(pStr);
}

void META_WIFI_Register(WIFI_CNF_CB callback)
{
    cnf_cb = callback;
}

int META_WIFI_init(void)
{
    int count = 100;

    if(1 == wifi_init){
    	ERR("wifi is already initilized.\n");
    	return true;
    }
#if 0
    if (!wifi_is_loaded()){
        ERR("[META_WIFI] loading wifi driver ... ...\n");
        if (wifi_insmod(DRIVER_MODULE_PATH, DRIVER_MODULE_ARG) < 0) {
            ERR("[META_WIFI] failed to load wifi driver!!!\n");
            goto error;
        }
    }
#endif
    usleep(200000);

	/*get wifi nvram profile before wifi on */
	gNvInfo = NVM_ReadFileVerInfo(AP_CFG_RDEB_FILE_WIFI_LID);
	DBG("[META_WIFI] NVRAM FileVer:%s\n", gNvInfo.cFileVer);
	DBG("[META_WIFI] NVRAM FileName:%s\n", gNvInfo.cFileName);
	DBG("[META_WIFI] NVRAM RecSize:%d\n", gNvInfo.i4RecSize);
	DBG("[META_WIFI] NVRAM RecNum:%d\n", gNvInfo.i4RecNum);
	DBG("[META_WIFI] NVRAM MaxFileLid:%d\n", gNvInfo.i4MaxFileLid);


#if defined(SUPPORT_AFC_C0C1)
	gGpsNv = NVM_ReadFileVerInfo(AP_CFG_CUSTOM_FILE_GPS_LID);
	DBG("[META_WIFI] GPS NVRAM FileVer:%s\n", gGpsNv.cFileVer);
	DBG("[META_WIFI] GPS NVRAM FileName:%s\n", gGpsNv.cFileName);
	DBG("[META_WIFI] GPS NVRAM RecSize:%d\n", gGpsNv.i4RecSize);
	DBG("[META_WIFI] GPS NVRAM RecNum:%d\n", gGpsNv.i4RecNum);
	DBG("[META_WIFI] GPS NVRAM MaxFileLid:%d\n", gGpsNv.i4MaxFileLid);
#endif

    wifi_set_power(1);


    sched_yield();

    while (count-- > 0) {
        if (ifc_init() == 0) {
            if (ifc_up("wlan0") == 0) {
                ifc_close();
                break;
            }
            ERR("[META_WIFI] ifc_up(wlan0) failed\n");
            ifc_close();
        } else {
            ERR("[META_WIFI] ifc_init() failed\n");
        }
        usleep(100000);
    }
    if (count == 0)
        goto error;

    if (wifi_skfd == -1)
        wifi_skfd = openNetHandle();

    if (wifi_skfd < 0) {
        META_WIFI_deinit();
        goto error;
    }

    wifi_init = 1;

    return true;

error:
    wifi_set_power(0);
    return false;
}

void META_WIFI_deinit(void)
{
    //int count = 20; /* wait at most 10 seconds for completion */

    if(0 == wifi_init){
    	ERR("wifi is already deinitilized.\n");
    	return;
    }

    if (wifi_skfd > 0) {
        closeNetHandle(wifi_skfd);
        wifi_skfd = -1;
    }

/*    if (wifi_rmmod(DRIVER_MODULE_NAME) == 0) {
        while (count-- > 0) {
            if (!wifi_is_loaded())
                break;
            usleep(500000);
        }
        sched_yield();*/
        wifi_set_power(0);
/*    }*/
    wifi_init = 0;
    return;
}

void META_WIFI_OP(FT_WM_WIFI_REQ *req, char *peer_buf, unsigned short peer_len)
{
    unsigned int i;
    int ret = -1;
    FT_WM_WIFI_CNF cnf;
    OID_STRUC *poid = NULL;
    UINT_32 avail_sz = 0;
    NVRAM_ACCESS_STRUCT *pnvram = NULL;
    char *pCmd = NULL;
    int cmdLen = 0;
    F_INFO kFileInfo;
    int iFD;
    void *ret_buf = NULL, *allocated_buf = NULL;
    unsigned int ret_size = 0;
    int readByteLen = -1;

#if defined(SUPPORT_AFC_C0C1)
	// For AFC/C0C1 calibration
	WIFI_AFC_REQ *afc_req = NULL;
	WIFI_AFC_CNF afc_cnf;
	WIFI_AFC_CNF c0c1_cnf;
#endif

//modify for wifi init/deinit flow
//     if (NULL == req || NULL == peer_buf || wifi_skfd < 0 || !wifi_init) {
//         printf("[META_WIFI] Invalid arguments or operation\n");
//         goto exit;
//     }

     DBG("META_WIFI_OP OP is %d\n", req->type);

    //for the compaliance of the former meta tool
    if(!wifi_init && WIFI_CMD_INIT != req->type){
    	if(true != META_WIFI_init()){
		ERR("!wifi_init & META_WIFI_init fail\n");
		ret = -1;
		goto exit;
	}
	else
		DBG("Init for the compaliance of the former meta tool.\n");
    }


    // OID operation
    if(WIFI_CMD_SET_OID == req->type
            || WIFI_CMD_QUERY_OID == req->type) {
        if ((peer_len <= 0) || NULL == (poid = (OID_STRUC *)malloc(peer_len))) {
            ERR("[META_WIFI] No memory, %d\n", peer_len);
            goto exit;
        }

        // for later freeing
        allocated_buf = (void *)poid;
        memcpy(poid, peer_buf, peer_len);

        if (WIFI_CMD_SET_OID == req->type) {
            for (i = 0; i < poid->SetOidPara.dataLen; i++) {
                DBG("[META_WIFI] OIDReq : data[%d] = 0x%x\n",
                    i, poid->SetOidPara.data[i]);
            }
            ret = setIWreq(wifi_skfd, "wlan0", poid->SetOidPara.oid,
                poid->SetOidPara.data, poid->SetOidPara.dataLen, &avail_sz);
            DBG("[META_WIFI] SET_OID, OID: 0x%x, len: %d, ret: %d\n",
                poid->SetOidPara.oid, poid->SetOidPara.dataLen, ret);
        }
        else if (WIFI_CMD_QUERY_OID == req->type) {
            ret = getIWreq(wifi_skfd, "wlan0", poid->QueryOidPara.oid,
                 poid->QueryOidPara.data, poid->QueryOidPara.dataLen, &avail_sz);
            DBG("[META_WIFI] QUERY_OID, OID: 0x%x, len: %d, ret: %d\n",
                poid->QueryOidPara.oid, poid->QueryOidPara.dataLen, ret);
        }

        if (ret == 0 && WIFI_CMD_QUERY_OID == req->type) {
            ret_buf = (void *)poid;
            ret_size = avail_sz+8;
        }
    }
    // NVRAM access
    else if(WIFI_CMD_NVRAM_WRITE_ACCESS == req->type
            || WIFI_CMD_NVRAM_READ_ACCESS == req->type) {
        if ((peer_len <= 0) || NULL == (pnvram = (NVRAM_ACCESS_STRUCT *)malloc(peer_len))) {
            ERR("[META_WIFI] No memory, %d\n", peer_len);
            goto exit;
        }

        // for later freeing
        allocated_buf = (void *)pnvram;
        memcpy(pnvram, peer_buf, peer_len);

        if(peer_len < (offsetof(NVRAM_ACCESS_STRUCT, data) + pnvram->dataLen)) {
            ERR("[META_WIFI] Mimatched NVRAM content length: (%d / %u)\n", peer_len,
	    	(unsigned int)(offsetof(NVRAM_ACCESS_STRUCT, data) + pnvram->dataLen));
            goto exit;
        }

        kFileInfo = NVM_ReadFileVerInfo(AP_CFG_RDEB_FILE_WIFI_LID);

        if(WIFI_CMD_NVRAM_READ_ACCESS == req->type) {

            /* post-check for read access */
            if(NVM_ProtectDataFile(AP_CFG_RDEB_FILE_WIFI_LID, 0) != 1) {
                ERR("[META_WIFI] NVM_ProtectDataFile(): get failed\n");
                goto exit;
            }

            iFD = open(kFileInfo.cFileName, O_RDONLY|O_CREAT, S_IRUSR|S_IRGRP);
            if(iFD >= 0) {
                if(lseek(iFD, pnvram->dataOffset, SEEK_SET) < 0){
                    ERR("[META_WIFI] lseek fail!");
                    close(iFD);
                    goto exit;
                }
                readByteLen = read(iFD, pnvram->data, pnvram->dataLen);
                if(readByteLen <= 0) {
                    ERR("[META_WIFI] read fail! ,readByteLen :%d",readByteLen);
                    close(iFD);
                    goto exit;
                }
                close(iFD);

                ret = 0;
            }else {
				ERR("[META_WIFI] open file :%s fail!",kFileInfo.cFileName);
				goto exit;
            }
        }
        else if(WIFI_CMD_NVRAM_WRITE_ACCESS == req->type) {
            iFD = open(kFileInfo.cFileName, O_WRONLY|O_CREAT, S_IRUSR|S_IRGRP);
            if(iFD >= 0) {
                if(lseek(iFD, pnvram->dataOffset, SEEK_SET) < 0){
                    ERR("[META_WIFI] read fail!");
                    close(iFD);
                    goto exit;
                }

                write(iFD, pnvram->data, pnvram->dataLen);
                close(iFD);

                /* invoke protect data file mechanism */
            	if(NVM_ProtectDataFile(AP_CFG_RDEB_FILE_WIFI_LID, 1) != 1) {
		    ERR("[META_WIFI] NVM_ProtectDataFile(): set failed\n");
                    ret = -1;
                }
                else {
                    // invoke auto backup mechanism
                    NVM_AddBackupFileNum(AP_CFG_RDEB_FILE_WIFI_LID);

                    ret = 0;
                }
            }else {
				ERR("[META_WIFI] open file :%s fail!",kFileInfo.cFileName);
				goto exit;
            }
        }

        if (ret == 0 && WIFI_CMD_NVRAM_READ_ACCESS == req->type) {
            ret_buf = (void *)pnvram;
            ret_size = offsetof(NVRAM_ACCESS_STRUCT, data) + readByteLen;
        }
    }
    else if(WIFI_CMD_INIT == req->type){
	if(true != META_WIFI_init())
		ret = -1;
	else
		ret = 0;
    }

    else if(WIFI_CMD_DEINIT == req->type){
    	META_WIFI_deinit();
    	ret = 0;
    }

    else if(WIFI_CMD_SCRIPT == req->type) {

        /*Do sanity check*/
        if (peer_len <= 0)
            goto exit;

        /*memory allocate for saving driver's command result*/
        if (NULL == (pCmd = (char *)malloc(WIFI_SCRIPT_TOTAL_BUF_LEN))) {
            goto exit;
        }

        memcpy(pCmd, peer_buf, peer_len);
        pCmd[peer_len] ='\0';

        /*parse User command and remove iwpriv driver command head, for example : adb shell ipwriv driver*/
        cmdLen = wifiScriptRemoveHead(pCmd);

        if(cmdLen > 0)
        {
            ret = driverIWreq(wifi_skfd, "wlan0", pCmd, cmdLen, &avail_sz);
            DBG("[META_WIFI] DRIVER CMD:%s,len:%d,ret:%d,avail_sz:%d\n", peer_buf, peer_len, ret, avail_sz);

            if (ret == 0 && WIFI_CMD_SCRIPT == req->type) {
                ret_buf = (void *)pCmd;
                ret_size = avail_sz;
            }
        }

    }
#if defined(SUPPORT_AFC_C0C1)
	else if (WIFI_CMD_AFC_CALIBRATION == req->type)
	{
		int cap_id = 0;
		float afc_temperature = 0;
		int nvram_ret = 0;

		if ((peer_len <= 0) || NULL == (afc_req = (WIFI_AFC_REQ*)malloc(sizeof(WIFI_AFC_REQ))))
		{
			ERR("[META_CAL] Fail to allocate WIFI_AFC_REQ, %d\n", peer_len);
			goto exit;
		}

		// Get operation in peer buffer
		memset(afc_req, 0, sizeof(WIFI_AFC_REQ));
		memcpy(afc_req, peer_buf, peer_len);
		ret = 0;

		if (afc_req->cmd_id == WIFI_AFC_Calibration) {
			if (afc_req->cmd.afc_cmd.Action == 1) {
				// Action 0 for start; 1 for stop
				goto exit;
			}

			memset(&afc_cnf, 0, sizeof(WIFI_AFC_CNF));
			afc_cnf.cmd_id = WIFI_AFC_Calibration;
			afc_cnf.cmd.afc_cmd.Status = META_SUCCESS;

			DBG("[META_CAL] Start AFC calibration\n");
			cap_id = start_afc_calibration(&afc_temperature);

			if (cap_id >= 0) {
				nvram_ret = CO_TMS_NVRAMCtrl(&gNvInfo, AP_CFG_RDEB_FILE_WIFI_LID, 0xF8, (unsigned char)cap_id);
				DBG("[META_CAL] Write cap_id[%d]=[0x%x] into wifi nvram\n", cap_id, cap_id);

				if (nvram_ret == META_WIFI_STATUS_FAIL) {
					afc_cnf.cmd.afc_cmd.Status = META_FAILED;
					ret = -1;
					ERR("[META_CAL] Fail to write cap id %d into wifi nvram\n", cap_id);
				}
			} else {
				afc_cnf.cmd.afc_cmd.Status = META_FAILED;
				ret = -1;
				ERR("[META_CAL] Fail to get valid cap id, cal_ret[%d]\n", cap_id);
			}

			afc_cnf.cmd.afc_cmd.CAP_ID = cap_id;
			afc_cnf.cmd.afc_cmd.Temperature = afc_temperature;
			ret_buf = (void *)&afc_cnf;
			ret_size = sizeof(WIFI_AFC_CNF);
			DBG("[META_CAL] Send AFC CNF: Status[%d], CAP_ID[%d], Temperature[%f]", afc_cnf.cmd.afc_cmd.Status, afc_cnf.cmd.afc_cmd.CAP_ID, afc_cnf.cmd.afc_cmd.Temperature);

		} else if (afc_req->cmd_id == WIFI_C0C1_Calibration) {
			if (afc_req->cmd.c0c1_cmd.Action == 1) {
				// Action 0 for start; 1 for stop
				goto exit;
			}

			unsigned int ui_c0 = 0;
			unsigned int ui_c1 = 0;
			unsigned char token = 0;
			int cal_ret = 0;
			float c0c1[2] = {0};
			unsigned int nvram_c0[4] = {0x24, 0x25, 0x26, 0x27};
			unsigned int nvram_c1[4] = {0x28, 0x29, 0x2A, 0x2B};
			C0C1_INIT init;
			init.c1 = afc_req->cmd.c0c1_cmd.C1;
			init.centerFreq = afc_req->cmd.c0c1_cmd.CenterFreq;
			init.temperature = afc_req->cmd.c0c1_cmd.Temperature;

			memset(&c0c1_cnf, 0, sizeof(WIFI_AFC_CNF));
			c0c1_cnf.cmd_id = WIFI_C0C1_Calibration;
			c0c1_cnf.cmd.c0c1_cmd.Status = META_SUCCESS;

			DBG("[META_CAL] Start C0C1 calibration, init c1[%f], centerFreq[%f], temperature[%f]\n", init.c1, init.centerFreq, init.temperature);
			cal_ret = start_c0c1_calibration(&init, c0c1);

			if (cal_ret == 0) {
				ui_c0 = *(unsigned int *)&(c0c1[0]);
				ui_c1 = *(unsigned int *)&(c0c1[1]);
				DBG("[META_CAL] Convert float c0[%f], c1[%f] to unsigned int c0[0x%x], c1[0x%x]", c0c1[0], c0c1[1], ui_c0, ui_c1);

				// Since nvram only read/write unsigned char, we need to
				// break (4 bytes: unsigned int) into 4 (1 byte: unsigned char)
				for (int i = 0; i < 4; i++) {
					token = (ui_c0 >> (i * 8)) & 0xFF;
					DBG("[META_CAL] Write c0 token_%d[0x%x] into gps nvram addr[0x%x]", i, token, nvram_c0[i]);

					nvram_ret = CO_TMS_NVRAMCtrl(&gGpsNv, AP_CFG_CUSTOM_FILE_GPS_LID, nvram_c0[i], token);

					if (nvram_ret == META_WIFI_STATUS_FAIL) {
						c0c1_cnf.cmd.c0c1_cmd.Status = META_FAILED;
						ret = -1;
						ERR("[META_CAL] Fail to write valid c0[%f] into gps nvram, token[%d]\n", c0c1[0], i);
						break;
					}
				}

				for (int i = 0; i < 4; i++) {
					token = (ui_c1 >> (i * 8)) & 0xFF;
					DBG("[META_CAL] Write c1 token_%d[0x%x] into gps nvram addr[0x%x]", i, token, nvram_c1[i]);

					nvram_ret = CO_TMS_NVRAMCtrl(&gGpsNv, AP_CFG_CUSTOM_FILE_GPS_LID, nvram_c1[i], token);

					if (nvram_ret == META_WIFI_STATUS_FAIL) {
						c0c1_cnf.cmd.c0c1_cmd.Status = META_FAILED;
						ret = -1;
						ERR("[META_CAL] Fail to write valid c1[%f] into gps nvram, token[%d]\n", c0c1[1], i);
						break;
					}
				}
			} else {
				c0c1_cnf.cmd.c0c1_cmd.Status = META_FAILED;
				ret = -1;
				ERR("[META_CAL] Fail to get valid c0c1, cal_ret[%d]\n", cal_ret);
			}

			c0c1_cnf.cmd.c0c1_cmd.C0 = c0c1[0];
			c0c1_cnf.cmd.c0c1_cmd.C1 = c0c1[1];
			ret_buf = (void *)&c0c1_cnf;
			ret_size = sizeof(WIFI_AFC_CNF);

			DBG("[META_CAL] Send C0C1 CNF: Status[%d], C0[%f], C1[%f]", c0c1_cnf.cmd.c0c1_cmd.Status, c0c1_cnf.cmd.c0c1_cmd.C0, c0c1_cnf.cmd.c0c1_cmd.C1);
		}
	}
#endif

exit:
    memset(&cnf, 0, sizeof(FT_WM_WIFI_CNF));
    cnf.header.token = req->header.token;
    cnf.header.id    = FT_WIFI_CNF_ID;
    cnf.type         = req->type;
    cnf.status       = META_SUCCESS;

    /* CHECKME!! Need to confirm the value of drv_status */
    cnf.drv_status   = (ret == 0) ? (int)true : (int)false;

    wifi_send_resp(&cnf, ret_buf, ret_size);

    FREEIF(poid);
    FREEIF(pnvram);
    FREEIF(pCmd);
#if defined(SUPPORT_AFC_C0C1)
	FREEIF(afc_req);
#endif

    return;
}

