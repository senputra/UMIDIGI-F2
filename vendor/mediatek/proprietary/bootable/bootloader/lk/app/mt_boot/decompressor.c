/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2017. All rights reserved.
*
* BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
* THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
* CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
* SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
* STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
* CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*/

#include <lib/zlib.h>
#include <string.h>
#include <debug.h>
#include <malloc.h>
#include <platform/mt_gpt.h>	// for get_timer()
#include <iothread.h>
#include <profiling.h>

#define RESERVED		0xe0
#define COMMENT			0x10
#define ORIG_NAME		8
#define EXTRA_FIELD		4
#define HEAD_CRC		2
#define ZALLOC_ALIGNMENT	16

static void *zlib_alloc(void *x, unsigned items, unsigned size)
{
	void *p;

	size *= items;
	size = (size + ZALLOC_ALIGNMENT - 1) & ~(ZALLOC_ALIGNMENT - 1);

	p = malloc (size);
 	return (p);
}

static void zlib_free(void *x, void *addr)
{
	free (addr);
}


int zunzip(unsigned char *src, unsigned long *lenp, void *dst, int dstlen, int offset)
{
	z_stream s;
	int r;

	memset(&s, 0, sizeof(z_stream));

	r = inflateInit2(&s, -MAX_WBITS);
	if (r != Z_OK) {
		dprintf (CRITICAL, "inflateInit2() error, returned %d\n", r);
		return -1;
	}
	s.zalloc = zlib_alloc;
	s.zfree = zlib_free;
	s.next_in = src + offset;
	s.next_out = dst;
	s.avail_in = *lenp - offset;
	s.avail_out = dstlen;
	r = inflate(&s, Z_FINISH);
	if ((r != Z_STREAM_END)) {
		dprintf(CRITICAL, "inflate() error! return %d\n", r);
		inflateEnd(&s);
		return -1;
	}
	*lenp = s.next_out - (unsigned char *) dst;
	inflateEnd(&s);

	return 0;
}

int gunzip(unsigned char *src, unsigned long *lenp, void *dst, int dstlen)
{
	unsigned long i, flags;
	int ret;

	i = 10;
	flags = src[3];

	/* Skip the header of gzip */
	if (src[2] != Z_DEFLATED || (flags & RESERVED) != 0) {
		dprintf (CRITICAL, "gzip header is not correct. Error!\n");
		return -1;
	}
	if ((flags & EXTRA_FIELD) != 0)
		i = 12 + src[10] + (src[11] << 8);
	if ((flags & ORIG_NAME) != 0)
		while (src[i++] != 0)
			;
	if ((flags & COMMENT) != 0)
		while (src[i++] != 0)
			;
	if ((flags & HEAD_CRC) != 0)
		i += 2;

	if (i >= *lenp) {
		dprintf(CRITICAL, "gunzip header is bigger than expectation! Error!\n");
		return -1;
	}

	ret = zunzip(src, lenp, dst, dstlen, i);

	return ret;
}


bool decompress_kernel(unsigned char *in, void *out, int inlen, int outlen)
{
	unsigned long lenp = inlen;
	int ret;

	wake_up_iothread();

	PROFILING_START("decompress_kernel");
	ret = gunzip(in, &lenp, out, outlen);
	PROFILING_END();

	wait_for_iothread();

	return ret;
}

