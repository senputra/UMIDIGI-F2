/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef _TeletexString_H_
#define _TeletexString_H_

#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef OCTET_STRING_t TeletexString_t; /* Implemented via OCTET STRING */

extern asn_TYPE_descriptor_t asn_DEF_TeletexString;

#ifdef __cplusplus
}
#endif

#endif  /* _TeletexString_H_ */
