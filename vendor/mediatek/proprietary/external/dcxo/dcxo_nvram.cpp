#include <fcntl.h>
#include <unistd.h>
#include <utils/Log.h>
#include <utils/String8.h>
#include <cutils/properties.h>

/* read NVRAM */
#include "libnvram.h"
#include "CFG_Wifi_File.h"
#include "Custom_NvRam_LID.h"

#define LOG_TAG		"DcxoNvramDrv"

#define NVRAM_DRV_LOG(fmt, arg...)	ALOGD(LOG_TAG " " fmt, ##arg)
#define NVRAM_DRV_ERR(fmt, arg...)	\
	ALOGE(LOG_TAG "MError: %5d: " fmt, __LINE__, ##arg)

static char* CAP_ID_PATH[] = {
	"/sys/kernel/clk_buf/clk_buf_capid",
	"/sys/power/clk_buf/clk_buf_capid",
};
#define CAP_ID_OFFSET 0xF8

int load_nvram_to_dcxo_cap_id(void)
{
	F_ID dcxo_nvram_fd;
	WIFI_CFG_PARAM_STRUCT wifi_nvram;
	int file_lid = AP_CFG_RDEB_FILE_WIFI_LID;
	int rec_size, rec_num;
	int ret, fd_dcxo, i;
	bool IsRead = true, IsOpened = false;
	char buf[5];
	char cap_id;

	NVRAM_DRV_ERR("%s: Set cap id from nvram to clk_buf_capid\n", __func__);

	dcxo_nvram_fd.iFileDesc = 0;
	dcxo_nvram_fd.ifile_lid = 0;
	dcxo_nvram_fd.bIsRead = 0;

	memset(&wifi_nvram, 0, sizeof(wifi_nvram));
	dcxo_nvram_fd = NVM_GetFileDesc(file_lid, &rec_size, &rec_num, IsRead);
	if (dcxo_nvram_fd.iFileDesc == -1) {
		NVRAM_DRV_ERR("Open nvram DcxoCap failed!\n");
		return -1;
	}

	if (rec_num != 1) {
		NVRAM_DRV_ERR("Unexpected record num %d\n", rec_num);
		NVM_CloseFileDesc(dcxo_nvram_fd);
		return -1;
	}

	NVRAM_DRV_LOG("DcxoCap rec_num %d, rec_size %d\n", rec_num, rec_size);

	ret = read(dcxo_nvram_fd.iFileDesc, &wifi_nvram, sizeof(wifi_nvram));
	if (ret < 0) {
		NVRAM_DRV_ERR("Read DcxoCapOffset from nvram failed. ret=%d\n", ret);
		NVM_CloseFileDesc(dcxo_nvram_fd);
		return -1;
	}

	cap_id = *((char *)&wifi_nvram + CAP_ID_OFFSET);
	NVRAM_DRV_LOG("Read nvram success (%d)\n", cap_id);

	if (!cap_id) {
		NVRAM_DRV_ERR("No calibration data\n");
		NVM_CloseFileDesc(dcxo_nvram_fd);
		return -1;
	}

	ret = sprintf(buf, "%d", cap_id);
	if (ret < 0) {
		NVRAM_DRV_ERR("sprintf failed. ret=%d\n", ret);
		NVM_CloseFileDesc(dcxo_nvram_fd);
		return ret;
	}

	for (i = 0; i < sizeof(CAP_ID_PATH)/sizeof(CAP_ID_PATH[0]); i++) {
		fd_dcxo = open(CAP_ID_PATH[i], O_RDWR);
		if (fd_dcxo > 0) {
			IsOpened = true;
			break;
		} else {
			NVRAM_DRV_ERR("Open cap id failed. errno=%d\n", fd_dcxo);
		}
	}

	if (!IsOpened) {
		NVM_CloseFileDesc(dcxo_nvram_fd);
		return fd_dcxo;
	}

	ret = write(fd_dcxo, buf, strlen(buf));
	close(fd_dcxo);
	if (ret < 0) {
		NVRAM_DRV_ERR("Write cap id failed. errno=%d\n", ret);
		NVM_CloseFileDesc(dcxo_nvram_fd);
		return ret;
	}

	if (!NVM_CloseFileDesc(dcxo_nvram_fd)) {
		NVRAM_DRV_ERR("Close nvram DcxoCap error!\n");
		return -1;
	}

	NVRAM_DRV_ERR("DCXO SET CAP EXIT\n");
	return 0;
}

int main(int argc, char** argv)
{
	load_nvram_to_dcxo_cap_id();
	return 0;
}

