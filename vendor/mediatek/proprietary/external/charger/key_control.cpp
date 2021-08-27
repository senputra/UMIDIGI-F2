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
 * MediaTek Inc. (C) 2010. All rights reserved.
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

#include <suspend/autosuspend.h>
#include <sys/epoll.h>
#include "main.h"

#define LONG_PRESS_DEFAULT_DURATION 500
#define INPUT_DEVICE_PATH "/dev/input"
#define EPOLL_MAX_EVENTS 16

static int inotify_fd;
static int epoll_fd;
static char **dev_names;
static int num_fds, wd;
static pthread_mutex_t mutex;
pthread_cond_t keycond;
static int keyDownPressed = false;
static int keyUpPressed = false;
static int powerKeyPressed = false;
static int longPressDuration = LONG_PRESS_DEFAULT_DURATION;

static int request_suspend(bool enable)
{
    if (enable)
        return autosuspend_enable();
    else
        return autosuspend_disable();
}

static void* key_thread_routine(__attribute__((unused))void *arg)
{
    static bool bootingUp = false;
    static bool long_press = false;
    struct timeval start;

    while (!bootingUp) {
        pthread_mutex_lock(&mutex);
        request_suspend(true);
        pthread_cond_wait(&keycond, &mutex);

        request_suspend(false);
        /* longPressDetecting = true; */

        gettimeofday(&start, NULL);
        KPOC_LOGI("pwr key long press check start\n");

        pthread_mutex_unlock(&mutex);

        while(powerKeyPressed)
        {
            usleep(1000*100); //200ms
            long_press = time_exceed(start, longPressDuration);
            if(long_press)
            {
                KPOC_LOGI("pwr key reaches boot condition\n");
                if(get_voltage() > VBAT_POWER_ON)
                {
                	showLowBattLogo = 0;
                    // ready to boot up.
                    inotify_rm_watch(inotify_fd, wd);
                    if (keyDownPressed || keyUpPressed)
                        exit_charger(EXIT_REBOOT_UBOOT);
                    else
                        exit_charger(EXIT_POWER_UP);
                    bootingUp = true;
                }
                else {
                	showLowBattLogo = 1;
                    KPOC_LOGI("VBAT <= %d\n", VBAT_POWER_ON);
                    break;
                }
            }
        }

        if (!long_press)
            showLowBattLogo = 0;
        if(!bootingUp)
            start_charging_anim(TRIGGER_ANIM_KEY);
        KPOC_LOGI("pwr key long press check end\n");
    }
    return NULL;
}

void long_press_control()
{
    int ret = 0;
    pthread_attr_t attr;
    pthread_t pwrkey_thread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&keycond, NULL);
    pthread_attr_init(&attr);

    ret = pthread_create(&pwrkey_thread, &attr, key_thread_routine, NULL);
    if (ret != 0)
    {
        KPOC_LOGI("create key pthread failed.\n");
        exit_charger(EXIT_ERROR_SHUTDOWN);
    }
}

static int is_keypad_device(const char *filename)
{
    int i;
    char * strpos = NULL;

    for (i = 0; i < (int) ARRAY_SIZE(keypad_device_name); i++){
        KPOC_LOGI("check device name: %s v.s. %s \n", filename, keypad_device_name[i]);
        strpos = (char *) strcasestr(filename, keypad_device_name[i]);
        if (strpos != NULL)
            return true;
    }
    return false;
}


static int open_device(const char *device)
{
    int version;
    int fd;
    struct epoll_event event_item;
    char **tmp_device_names;
    char name[80];
    char location[80];
    char idstr[80];
    struct input_id id;

    fd = open(device, O_RDWR);
    if(fd < 0) {
        KPOC_LOGI("could not open %s, %s\n", device, strerror(errno));
        return -1;
    }
    if(ioctl(fd, EVIOCGVERSION, &version)) {
        KPOC_LOGI("could not get driver version for %s, %s\n", device, strerror(errno));
        return -1;
    }
    if(ioctl(fd, EVIOCGID, &id)) {
        KPOC_LOGI("could not get driver id for %s, %s\n", device, strerror(errno));
        return -1;
    }

    name[sizeof(name) - 1] = '\0';
    location[sizeof(location) - 1] = '\0';
    idstr[sizeof(idstr) - 1] = '\0';

    if(ioctl(fd, EVIOCGNAME(sizeof(name) - 1), &name) < 1)
        name[0] = '\0';

    if(!is_keypad_device(name))
        return -1;

    if(ioctl(fd, EVIOCGPHYS(sizeof(location) - 1), &location) < 1)
        location[0] = '\0';

    if(ioctl(fd, EVIOCGUNIQ(sizeof(idstr) - 1), &idstr) < 1)
        idstr[0] = '\0';

    event_item.events = EPOLLIN | EPOLLWAKEUP;
    event_item.data.u32 = fd;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event_item)) {
        KPOC_LOGI("Could not add fd to epoll, %s\n", strerror(errno));
        return -1;
    }

    tmp_device_names = (char**)realloc(dev_names, sizeof(dev_names[0]) * (num_fds + 1));
    if(tmp_device_names == NULL) {
        KPOC_LOGI("out of memory\n");
        return -1;
    }

    dev_names = tmp_device_names;
    dev_names[num_fds] = strdup(device);
    num_fds++;

    return 0;
}

int close_device(const char *device)
{
    int i, count;

    for(i = 1; i < num_fds; i++)
    {
        if(strcmp(dev_names[i], device) == 0)
        {
            count = num_fds - i - 1;
            KPOC_LOGI("remove device %d: %s\n", i, device);

            free(dev_names[i]);
            memmove(dev_names + i, dev_names + i + 1, count * sizeof(dev_names[0]));

            num_fds--;
            return 0;
        }
    }
    KPOC_LOGI("remote device: %s not found\n", device);
    return -1;
}

static int read_notify(const char *dirname, int nfd)
{
    int res;
    char devname[PATH_MAX];
    char *filename;
    char event_buf[512];
    int event_size;
    int event_pos = 0;
    struct inotify_event *event;

    res = read(nfd, event_buf, sizeof(event_buf));
    if(res < (int)sizeof(*event)) {
        if(errno == EINTR)
            return 0;
        KPOC_LOGI("could not get event, %s\n", strerror(errno));
        return 1;
    }

    strncpy(devname, dirname, sizeof(devname) - 1);
    devname[sizeof(devname) - 1] = '\0';
    filename = devname + strlen(devname);
    *filename++ = '/';

    while(res >= (int)sizeof(*event)) {
        event = (struct inotify_event *)(event_buf + event_pos);
        if(event->len) {
            strncpy(filename, event->name, sizeof(devname) - (strlen(devname) + 1));
            if(event->mask & IN_CREATE) {
                open_device(devname);
            }
            else {
                close_device(devname);
            }
        }
        event_size = sizeof(*event) + event->len;
        res -= event_size;
        event_pos += event_size;
    }
    return 0;
}

static int scan_dir(const char *dirname)
{
    char devname[PATH_MAX];
    char *filename;
    DIR *dir;
    struct dirent *de;
    dir = opendir(dirname);
    if(dir == NULL)
        return -1;
    strncpy(devname, dirname, sizeof(devname) - 1);
    devname[sizeof(devname) - 1] = '\0';
    filename = devname + strlen(devname);
    *filename++ = '/';
    while((de = readdir(dir))) {
        if(de->d_name[0] == '.' &&
           (de->d_name[1] == '\0' ||
            (de->d_name[1] == '.' && de->d_name[2] == '\0')))
            continue;
        strncpy(filename, de->d_name, sizeof(devname) - (strlen(devname) + 1));
        KPOC_LOGI("%s(), open_device %s\n", __FUNCTION__, devname);
        open_device(devname);
    }
    closedir(dir);
    return 0;
}

void key_control(int * pwrkeys, int pwrkeys_num)
{
    int res, i, j;
    int pollres;
    int input_fd = -1;
    struct input_event event;
    struct epoll_event event_item;
    struct epoll_event pending_event_items[EPOLL_MAX_EVENTS];
    bool device_change = false;

    longPressDuration = 500;
    long_press_control();

    num_fds = 1;
    epoll_fd = epoll_create(1);
    if (epoll_fd < 0) {
        KPOC_LOGI("could not create epoll fd, %s\n", strerror(errno));
        exit_charger(EXIT_ERROR_SHUTDOWN);
    }

    inotify_fd = inotify_init();
    if (inotify_fd < 0) {
        KPOC_LOGI("could not create inotify fd, %s\n", strerror(errno));
        exit_charger(EXIT_ERROR_SHUTDOWN);
    }

    memset(&event_item, 0, sizeof(event_item));
    event_item.events = EPOLLIN | EPOLLWAKEUP;
    event_item.data.u32 = inotify_fd;

    res = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, inotify_fd, &event_item);
    if (res != 0) {
        KPOC_LOGI("could not create inotify fd, %s\n", strerror(errno));
        exit_charger(EXIT_ERROR_SHUTDOWN);
    }

    wd = inotify_add_watch(inotify_fd, INPUT_DEVICE_PATH, IN_DELETE | IN_CREATE);
    if (wd < 0) {
        KPOC_LOGI("could not add watch for %s, %s\n", INPUT_DEVICE_PATH, strerror(errno));
        exit_charger(EXIT_ERROR_SHUTDOWN);
    }
    res = scan_dir(INPUT_DEVICE_PATH);
    if (res < 0) {
        KPOC_LOGI("scan dir failed for %s\n", INPUT_DEVICE_PATH);
        exit_charger(EXIT_ERROR_SHUTDOWN);
    }

    while (1) {
        pollres = epoll_wait(epoll_fd, pending_event_items, EPOLL_MAX_EVENTS, -1);
        if (pollres == 0) {
            KPOC_LOGI("epoll_wait should not return 0 with no timeout\n");
            exit_charger(EXIT_ERROR_SHUTDOWN);
            return;
        }
        if (pollres < 0) {
            KPOC_LOGI("epoll_wait returned with errno=%d\n", errno);
            exit_charger(EXIT_ERROR_SHUTDOWN);
            return;
        }
        for (i = 0; i < pollres; ++i) {
            const struct epoll_event& temp_event = pending_event_items[i];
            int data_fd = temp_event.data.u32;
            if (data_fd == inotify_fd) {
                if (temp_event.events & EPOLLIN) {
                    device_change = true;
                } else {
                    KPOC_LOGI("Received unexpected epoll event 0x%08x for INotify\n", temp_event.events);
                }
                continue;
            }

            if (input_fd != data_fd) {
                input_fd = data_fd;
            }

            if (temp_event.events & EPOLLIN) {
                res = read(input_fd, &event, sizeof(event));
                if (res < 0) {
                    if (errno != EAGAIN && errno != EINTR) {
                        KPOC_LOGI("could not get event. errno=%d\n", errno);
                    }
                    exit_charger(EXIT_ERROR_SHUTDOWN);
                } else if (res % sizeof(input_event) != 0) {
                    KPOC_LOGI("could not get event. wrong size=%zd\n", res);
                    exit_charger(EXIT_ERROR_SHUTDOWN);
                } else {
#ifdef VERBOSE_OUTPUT
                    KPOC_LOGI("%s: event.type:%d,%d:%d\n", __FUNCTION__, event.type, event.code, event.value);
#endif

                    if (EV_KEY == event.type) {
                        for (j = 0; j < pwrkeys_num; j++) {
                            if (event.code == pwrkeys[j]) {
                                if (1 == event.value) {
                                    powerKeyPressed = true;
                                    pthread_cond_signal(&keycond);
                                } else
                                    powerKeyPressed = false;
                                break;
                            }
                        }
                    }
                }
            } else {
                KPOC_LOGI("Received unexpected epoll event 0x%08x for device fd %d\n",
                        temp_event.events, input_fd);
            }
        }

        if (device_change)
            read_notify(INPUT_DEVICE_PATH, inotify_fd);
    }
}

