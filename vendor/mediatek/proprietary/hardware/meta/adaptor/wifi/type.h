/*******************************************************************************
** Copyright (c) 2005 MediaTek Inc.
**
** All rights reserved. Copying, compilation, modification, distribution
** or any other use whatsoever of this material is strictly prohibited
** except in accordance with a Software License Agreement with
** MediaTek Inc.
********************************************************************************
*/
#ifndef _TYPE_H
#define _TYPE_H

#define ULONG unsigned long
#define UINT  unsigned int
#define USHORT unsigned short
#define UCHAR unsigned char

#define LONG long
#define INT  int
#define SHORT short
#define CHAR char

#define UINT32 unsigned int
#define UINT16 unsigned short
#define UINT8 unsigned char

#define PUINT32 unsigned int*
#define PUINT16 unsigned short*
#define PUINT8 unsigned char*

#define UINT_64 unsigned long long
#define UINT_32 unsigned int
#define UINT_16 unsigned short
#define UINT_8 unsigned char

#define INT32  int
#define INT16  short
#define INT8  char

#define PINT32  int*
#define PINT16  short*
#define PINT8  char*
#define PVOID  void*

#define INT_32  int
#define INT_16  short
#define INT_8  char

#define PULONG ULONG*
#define PUCHAR UCHAR*

#define DWORD ULONG

/* Type definition for WLAN STATUS */
#define WLAN_STATUS                 unsigned int

#ifndef NULL
#define NULL  0
#endif

#define BOOL  bool
#define BOOLEAN bool


#if !defined(TRUE)
    #define TRUE true
#endif

#if !defined(FALSE)
    #define FALSE false
#endif

#define IN
#define OUT

#define TCHAR char

#define CString char*

#define LPSTR   char*
#define LPCTSTR char*

#define DLL_FUNC

#define TEXT

#define BIT(n)                          ((UINT_32) 1 << (n))
#define BITS(m,n)                       (~(BIT(m)-1) & ((BIT(n) - 1) | BIT(n)))


#ifndef RX_ANT_
#define RX_ANT_
typedef enum {
    AGC_RX_ANT_SEL,
    MPDU_RX_ANT_SEL,
    FIXED_0,
    FIXED_1
} RX_ANT_SEL;
#endif

#endif
