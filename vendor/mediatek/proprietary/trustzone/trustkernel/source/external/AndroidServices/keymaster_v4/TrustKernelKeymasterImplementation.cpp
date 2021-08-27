/*
 * Copyright (C) 2014 MediaTek Inc.
 * Modification based on code covered by the mentioned copyright
 * and/or permission notice(s).
 */
/*
 * Copyright (C) 2012 The Android Open Source Project
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
#include <android/log.h>

#define LOG_TAG "KeymasterHAL"

#undef ALOGE
#define ALOGE(fmt, ...) \
    __android_log_print(ANDROID_LOG_ERROR, \
            LOG_TAG, "%s:%d: " fmt, basename(__FILE__), __LINE__, ##__VA_ARGS__)

#undef ALOGD
#define ALOGD(fmt, ...) \
    __android_log_print(ANDROID_LOG_DEBUG, \
            LOG_TAG, "%s:%d: " fmt, basename(__FILE__), __LINE__, ##__VA_ARGS__)

#undef ALOGI
#define ALOGI(fmt, ...) \
    __android_log_print(ANDROID_LOG_INFO, \
            LOG_TAG, "%s:%d: " fmt, basename(__FILE__), __LINE__, ##__VA_ARGS__)

#undef ALOGW
#define ALOGW(fmt, ...) \
    __android_log_print(ANDROID_LOG_WARN, \
            LOG_TAG, "%s:%d: " fmt, basename(__FILE__), __LINE__, ##__VA_ARGS__)

#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <type_traits>
#include <stdlib.h>
#include <unistd.h>
#include <algorithm>

#include <openssl/x509.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/err.h>
#include <openssl/bio.h>

#include <tee_client_api.h>

#include <extract.h>
#include <my_util.h>

#include <include/TrustKernelKeymasterImplementation.h>


#define FORWARD0(name) \
    keymaster_error_t trustkernel::TrustKernelKeymasterImplementation::name()

#define FORWARD1(name, T1, n1) \
    keymaster_error_t trustkernel::TrustKernelKeymasterImplementation::name(T1 n1)

#define FORWARD2(name, T1, n1, T2, n2) \
    keymaster_error_t trustkernel::TrustKernelKeymasterImplementation::name(T1 n1, T2 n2)

#define FORWARD3(name, T1, n1, T2, n2, T3, n3) \
    keymaster_error_t trustkernel::TrustKernelKeymasterImplementation::name(T1 n1, T2 n2, T3 n3)

#define FORWARD4(name, T1, n1, T2, n2, T3, n3, T4, n4) \
    keymaster_error_t trustkernel::TrustKernelKeymasterImplementation::name(T1 n1, T2 n2, T3 n3, T4 n4)

#define FORWARD5(name, T1, n1, T2, n2, T3, n3, T4, n4, T5, n5) \
    keymaster_error_t trustkernel::TrustKernelKeymasterImplementation::name(T1 n1, T2 n2, T3 n3, T4 n4, T5 n5)

#define FORWARD6(name, T1, n1, T2, n2, T3, n3, T4, n4, T5, n5, T6, n6) \
    keymaster_error_t trustkernel::TrustKernelKeymasterImplementation::name(T1 n1, T2 n2, T3 n3, T4 n4, T5 n5, T6 n6)

#define FORWARD7(name, T1, n1, T2, n2, T3, n3, T4, n4, T5, n5, T6, n6, T7, n7) \
    keymaster_error_t trustkernel::TrustKernelKeymasterImplementation::name(T1 n1, T2 n2, T3 n3, T4 n4, T5 n5, T6 n6, T7 n7)

static const TEEC_UUID UUID_TrustKernelKeymasterV2 =
{ 0x9ef77781, 0x7bd5, 0x4e39, { 0x96, 0x5f, 0x20, 0xf6, 0xf2, 0x11, 0xf4, 0x6b } };

#define TEE_KEY_BLOB_SIZE 4096

#define CMD_GENERATE_KEY 13
#define CMD_GET_KEY_CHARACTER_SIZE 14
#define CMD_GET_KEY_CHARACTER 15
#define CMD_BEGIN 16
#define CMD_UPDATE 17
#define CMD_FINISH 18
#define CMD_IMPORT_KEY 19
#define CMD_EXPORT_KEY 20
#define CMD_DELETE_KEY 21
#define CMD_DELETE_ALL_KEY 22
#define CMD_ABORT 23
#define CMD_ATTEST_KEY 24
#define CMD_CONFIGURE 25
#define CMD_UPGRADE_KEY 26
#define CMD_GET_HMAC_SHARING_PARAM 27
#define CMD_COMPUTE_SHARED_HMAC 28
#define CMD_VERIFY_AUTHORIZATION 29

#define CMD_IMPORT_WRAPPED_KEY  30

#define CMD_soter_handle_generate_attk_key_pair    0xff00
#define CMD_soter_handle_verify_attk_key_pair      0xff01
#define CMD_soter_handle_export_attk_public_key    0xff02
#define CMD_soter_handle_get_device_id             0xff03
#define CMD_soter_handle_setFid                    0xff04

typedef struct {
    uint64_t reserved;
    uint64_t data_length;
} _keymaster_blob_t;

typedef struct {
    keymaster_tag_t tag;
    union {
        uint32_t enumerated;   /* KM_ENUM and KM_ENUM_REP */
        bool boolean;          /* KM_BOOL */
        uint32_t integer;      /* KM_INT and KM_INT_REP */
        uint64_t long_integer; /* KM_LONG */
        uint64_t date_time;    /* KM_DATE */
        _keymaster_blob_t blob; /* KM_BIGNUM and KM_BYTES*/
    };
} _keymaster_key_param_t;

bool trustkernel::TrustKernelKeymasterImplementation::invoke(const char *file, uint32_t lineno,
        uint32_t cmdId, uint32_t va, uint32_t vb,
        const void *inMem, uint32_t inMemSize,
        void *outMem, uint32_t outMemSize,
        uint32_t *outA, uint32_t *outB)
{
    uint32_t outMemSizeBak = outMemSize;

    bool ret = invoke(file, lineno, cmdId, va, vb,
            inMem, inMemSize,
            outMem, &outMemSize,
            outA, outB);

    if (outMemSize != outMemSizeBak)
        ALOGW("Output buffer size changed during InvokeCommand");

    return ret;
}

#define INVOKE(...) invoke(__FILE__, __LINE__, __VA_ARGS__)

TEEC_Result trustkernel::TrustKernelKeymasterImplementation::reconfigure() {
    uint32_t res;
    if (configureData.get() == NULL)
        return TEEC_ERROR_BAD_STATE;

    if (!INVOKE(CMD_CONFIGURE, 0, 0, configureData.get(), configureDataSize, NULL, (uint32_t) 0, &res))
        return TEEC_ERROR_GENERIC;

    if (res != KM_ERROR_OK) {
        ALOGE("TEE return %d", res);
        return TEEC_ERROR_GENERIC;
    }

    configured = true;

    if (computeHmacData.get() != NULL && computeHmacDataSize != 0) {
        uint8_t buf[32];

        if (!INVOKE(CMD_COMPUTE_SHARED_HMAC, 0, 0, computeHmacData.get(), computeHmacDataSize, buf, sizeof(buf), &res))
            return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
        if (res != KM_ERROR_OK) {
            ALOGE("TEE return %d", res);
            return (keymaster_error_t) res;
        }
    }

    return TEEC_SUCCESS;
}

bool trustkernel::TrustKernelKeymasterImplementation::invoke(const char *file, uint32_t lineno,
        uint32_t cmdId, uint32_t va, uint32_t vb,
        const void *inMem, uint32_t inMemSize,
        void *outMem, uint32_t *outMemSize,
        uint32_t *outA, uint32_t *outB)
{
    (void) file; // To eliminate the warning when these two parameters are not used to print debug info
    (void) lineno;

    if (error_)
        error_ = OpenTEESession();

    if (error_)
        return false;

    if (!configured && cmdId != CMD_CONFIGURE && configureData.get() != NULL)
        reconfigure(); // We just try to reconfigure, if there is any failure, the actual command will return error code

    if (inMemSize == 0)
        inMem = NULL;
    if (outMemSize == NULL)
        outMem = NULL;

    ALOGD("Invoke cmdId %d at %s:%d", cmdId, file, lineno);
    TEEC_Operation op;
    uint32_t orig;

    TEEC_Result result;
    op.params[0].value.a = va;
    op.params[0].value.b = vb;
    op.params[1].tmpref.buffer = (void *) inMem;
    op.params[1].tmpref.size = inMemSize;
    op.params[2].tmpref.buffer = outMem;
    op.params[2].tmpref.size = outMemSize ? *outMemSize: 0;

    op.paramTypes = TEEC_PARAM_TYPES(TEEC_VALUE_INOUT,
            inMem != NULL ? TEEC_MEMREF_TEMP_INPUT : TEEC_NONE,
            outMem != NULL ? TEEC_MEMREF_TEMP_OUTPUT : TEEC_NONE,
            TEEC_NONE);

    result = TEEC_InvokeCommand(&session, cmdId, &op, &orig);

    if (result != TEEC_SUCCESS) {
        ALOGE("Invoke command failed with 0x%08x, orig 0x%08x\n", result, orig);
        if (orig != TEEC_ORIGIN_TRUSTED_APP) {
            CloseTEESession();
            error_ = OpenTEESession();
        }
        return false;
    }

    if (outMemSize)
        *outMemSize = op.params[2].tmpref.size;

    if (outA)
        *outA = op.params[0].value.a;
    if (outB)
        *outB = op.params[0].value.b;
    return true;
}

keymaster_error_t
trustkernel::TrustKernelKeymasterImplementation::get_hmac_sharing_parameters(keymaster_hmac_sharing_parameters_t *params)
{
    uint32_t res = KM_ERROR_UNKNOWN_ERROR;

    if (params == NULL)
        return KM_ERROR_OUTPUT_PARAMETER_NULL;
    params->seed.data = NULL;
    params->seed.data_length = 0;
    memset(params->nonce, 0, sizeof(params->nonce));

    uint32_t outMemSize = 128;
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> outMem((uint8_t *) malloc(outMemSize));
    if (outMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    memset(outMem.get(), 0, outMemSize);

    if (!INVOKE(CMD_GET_HMAC_SHARING_PARAM, 0, 0, NULL, 0, outMem.get(), &outMemSize, &res))
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
    if (res != KM_ERROR_OK) {
        ALOGE("TEE return %d", res);
        return (keymaster_error_t) res;
    }

    do {
        const uint8_t *p = outMem.get(), *pend = p + outMemSize;
        EXTRACT_PRIMITIVE(uint32_t, params->seed.data_length);
        params->seed.data = (uint8_t *) malloc(params->seed.data_length);
        if (params->seed.data == NULL)
            return KM_ERROR_MEMORY_ALLOCATION_FAILED;
        EXTRACT_BYTES((void *) params->seed.data, (uint32_t) params->seed.data_length);
        uint32_t nonceSize;
        EXTRACT_PRIMITIVE(uint32_t, nonceSize);
        if (nonceSize != sizeof(params->nonce)) {
            free((void *) params->seed.data);
            params->seed.data = NULL;
            params->seed.data_length = 0;
            return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
        }
        EXTRACT_BYTES(params->nonce, (uint32_t) sizeof(params->nonce));
        break;

error:
        if (params->seed.data)
            free((void *) params->seed.data);
        return KM_ERROR_UNKNOWN_ERROR;
    } while(0);

    return KM_ERROR_OK;
}

keymaster_error_t
trustkernel::TrustKernelKeymasterImplementation::compute_shared_hmac(
                    const uint8_t *params, size_t params_size,
                    keymaster_blob_t *sharing_check)
{
    if (params == NULL || params_size == 0)
        return KM_ERROR_INVALID_ARGUMENT;
    if (sharing_check == NULL)
        return KM_ERROR_OUTPUT_PARAMETER_NULL;
    sharing_check->data = NULL;
    sharing_check->data_length = 0;

    computeHmacData.reset((uint8_t *) malloc(params_size));
    if (computeHmacData.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    memcpy(computeHmacData.get(), params, params_size);
    computeHmacDataSize = params_size;

    uint32_t outMemSize = 32;
    uint32_t res = KM_ERROR_UNKNOWN_ERROR;
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> outMem((uint8_t *) malloc(outMemSize));
    if (outMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    memset(outMem.get(), 0, outMemSize);

    if (!INVOKE(CMD_COMPUTE_SHARED_HMAC, 0, 0, params, params_size, outMem.get(), &outMemSize, &res))
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
    if (res != KM_ERROR_OK) {
        ALOGE("TEE return %d", res);
        return (keymaster_error_t) res;
    }

    sharing_check->data = (uint8_t *) realloc(outMem.release(), outMemSize);
    sharing_check->data_length = outMemSize;

    return KM_ERROR_OK;
}

keymaster_error_t
trustkernel::TrustKernelKeymasterImplementation::verify_authorization(
                    uint64_t challenge,
                    const keymaster_key_param_set_t *attest_params,
                    const keymaster_hardware_auth_token_t *auth_token,
                    keymaster_verification_token_t *verify_token)
{
    uint32_t res = KM_ERROR_UNKNOWN_ERROR;
    if (attest_params == NULL)
        return KM_ERROR_INVALID_ARGUMENT;
    if (verify_token == NULL)
        return KM_ERROR_OUTPUT_PARAMETER_NULL;
    verify_token->parameters_verified.params = NULL;
    verify_token->parameters_verified.length = 0;

    uint32_t inMemSize = sizeof(challenge) +
                         4 + marshal_size(attest_params) +
                         4 + sizeof(*auth_token);
    uint32_t outMemSize = 100 + marshal_size(attest_params);
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> inMem((uint8_t *) malloc(inMemSize));
    if (inMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> outMem((uint8_t *) malloc(outMemSize));
    if (outMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    do {
        // Prepare inMem

        uint8_t *p = inMem.get(), *pend = p + inMemSize;
        PACK_PRIMITIVE(uint64_t, challenge);
        PACK_EXP(uint32_t, marshal_size(attest_params));
        marshal_to(p, attest_params);
        p += marshal_size(attest_params);
        PACK_EXP(uint32_t, sizeof(*auth_token));
        if (auth_token == NULL)
            PACK_ZEROS(sizeof(*auth_token));
        else
            PACK_BYTES(auth_token, sizeof(*auth_token));
        break;
error:
        return KM_ERROR_UNKNOWN_ERROR;
    } while(0);

    if (!INVOKE(CMD_VERIFY_AUTHORIZATION, 0, 0, inMem.get(), inMemSize, outMem.get(), &outMemSize, &res))
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
    if (res != KM_ERROR_OK) {
        ALOGE("TEE return %d", res);
        return (keymaster_error_t) res;
    }

    do {
        const uint8_t *p = outMem.get(), *pend = p + outMemSize;
        EXTRACT_PRIMITIVE_ERR(uint64_t, verify_token->challenge, out_error);
        EXTRACT_PRIMITIVE_ERR(uint64_t, verify_token->timestamp, out_error);
        EXTRACT_PRIMITIVE_ERR(uint32_t, verify_token->security_level, out_error);
        EXTRACT_BYTES_ERR(verify_token->mac, 32, out_error);
        break;
out_error:
        keymaster_free_param_set(&verify_token->parameters_verified);
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
    } while(0);

    return KM_ERROR_OK;
}

FORWARD2(add_rng_entropy,
        const uint8_t*, data __unused,
        size_t, data_length __unused)
{
    return KM_ERROR_OK;
}

uint32_t trustkernel::TrustKernelKeymasterImplementation::marshal_size(const keymaster_key_param_set_t *params) {
    uint32_t size = sizeof(uint32_t);

    if (params != NULL) {
        for (uint32_t i = 0; i < params->length; i++) {
            size += sizeof(_keymaster_key_param_t);
            switch (keymaster_tag_get_type(params->params[i].tag)) {
                case KM_BIGNUM:
                case KM_BYTES:
                    size += params->params[i].blob.data_length;
                    break;
                default:
                    break;
            }
        }
    }

    return size;
}

void trustkernel::TrustKernelKeymasterImplementation::marshal_to(uint8_t *pMarshaled, const keymaster_key_param_set_t *params) {
    uint8_t *p = pMarshaled, *pend = p + marshal_size(params);

    if (params == NULL) {
        uint32_t zero = 0;
        PACK_PRIMITIVE(uint32_t, zero);
    } else {
        PACK_PRIMITIVE(uint32_t, params->length);
        for (uint32_t i = 0; i < params->length; i++) {
            _keymaster_key_param_t converted;
            converted.tag = params->params[i].tag;
            switch (keymaster_tag_get_type(params->params[i].tag)) {
                case KM_ENUM:
                case KM_ENUM_REP:
                    converted.enumerated = params->params[i].enumerated;
                    break;
                case KM_UINT:
                case KM_UINT_REP:
                    converted.integer = params->params[i].integer;
                    break;
                case KM_ULONG:
                case KM_ULONG_REP:
                    converted.long_integer = params->params[i].long_integer;
                    break;
                case KM_DATE:
                    converted.date_time = params->params[i].date_time;
                    break;
                case KM_BOOL:
                    converted.boolean = params->params[i].boolean;
                    break;
                case KM_BIGNUM:
                case KM_BYTES:
                    converted.blob.data_length = params->params[i].blob.data_length;
                    break;
                default:
                    break;
            }
            PACK_BYTES(&converted, sizeof(_keymaster_key_param_t));
            switch (keymaster_tag_get_type(params->params[i].tag)) {
                case KM_BIGNUM:
                case KM_BYTES:
                    PACK_BYTES(params->params[i].blob.data, params->params[i].blob.data_length);
                    break;
                default:
                    break;
            }
        }
    }

error:
    return;
}

uint8_t * trustkernel::TrustKernelKeymasterImplementation::marshal(const keymaster_key_param_set_t *params, uint32_t *pSize) {
    *pSize = marshal_size(params);

    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> pMarshaled((uint8_t *) malloc(*pSize));
    marshal_to(pMarshaled.get(), params);
    return pMarshaled.release();
}

keymaster_key_param_set_t
trustkernel::TrustKernelKeymasterImplementation::unmarshal_param_set(uint8_t *marshalled, uint32_t marshalled_size, uint8_t **next_ptr = NULL)
{
    uint32_t length, i;
    keymaster_key_param_set_t res = {
        .params = NULL,
        .length = 0
    };
    uint8_t *p = marshalled, *pend = marshalled + marshalled_size;

    EXTRACT_PRIMITIVE(uint32_t, length);
    res.params = (keymaster_key_param_t *) malloc(length * sizeof(keymaster_key_param_t));
    if (res.params == NULL) {
        ALOGE("Out of memory");
        goto error;
    }

    for (i = 0; i < length; i++) {
        _keymaster_key_param_t converted;
        EXTRACT_BYTES(&converted, (uint32_t) sizeof(_keymaster_key_param_t));
        res.params[i].tag = converted.tag;
        switch (keymaster_tag_get_type(res.params[i].tag)) {
            case KM_ENUM:
            case KM_ENUM_REP:
                res.params[i].enumerated = converted.enumerated;
                break;
            case KM_UINT:
            case KM_UINT_REP:
                res.params[i].integer = converted.integer;
                break;
            case KM_ULONG:
            case KM_ULONG_REP:
                res.params[i].long_integer = converted.long_integer;
                break;
            case KM_DATE:
                res.params[i].date_time = converted.date_time;
                break;
            case KM_BOOL:
                res.params[i].boolean = converted.boolean;
                break;
            case KM_BIGNUM:
            case KM_BYTES:
                res.params[i].blob.data_length = converted.blob.data_length;
                break;
            default:
                break;
        }
        switch (keymaster_tag_get_type(res.params[i].tag)) {
            case KM_BIGNUM:
            case KM_BYTES:
                res.params[i].blob.data = (uint8_t *) malloc(res.params[i].blob.data_length);
                if (res.params[i].blob.data == NULL) {
                    ALOGE("Out of memory");
                    goto error;
                }
                EXTRACT_BYTES((void *) res.params[i].blob.data, (uint32_t) res.params[i].blob.data_length);
                break;
            default:
                break;
        }
        res.length++;
    }

    if (next_ptr)
        *next_ptr = p;

    return res;

error:
    if (res.params)
        keymaster_free_param_set(&res);
    res.params = NULL;
    res.length = 0;
    return res;
}

keymaster_key_characteristics_t
trustkernel::TrustKernelKeymasterImplementation::unmarshal_character(uint8_t *marshalled, uint32_t marshalled_size)
{
    keymaster_key_characteristics_t res;
    uint8_t *next_marshalled;

    res.hw_enforced.params = NULL;
    res.hw_enforced.length = 0;
    res.sw_enforced.params = NULL;
    res.sw_enforced.length = 0;

    res.hw_enforced = unmarshal_param_set(marshalled, marshalled_size, &next_marshalled);
    if (res.hw_enforced.params == NULL)
        goto error;

    marshalled_size -= (next_marshalled - marshalled);
    marshalled = next_marshalled;

    res.sw_enforced = unmarshal_param_set(marshalled, marshalled_size);
    if (res.sw_enforced.params == NULL)
        goto error;

    return res;

error:
    if (res.hw_enforced.params != NULL)
        keymaster_free_param_set(&res.hw_enforced);

    if (res.sw_enforced.params != NULL)
        keymaster_free_param_set(&res.sw_enforced);

    return (keymaster_key_characteristics_t) {
        .hw_enforced = { .params = NULL, .length = 0 },
            .sw_enforced = { .params = NULL, .length = 0 }
    };
}

FORWARD3(generate_key,
        const keymaster_key_param_set_t*, params,
        keymaster_key_blob_t*, key_blob,
        keymaster_key_characteristics_t*, characteristics)
{

    if (params == NULL)
        return KM_ERROR_INVALID_ARGUMENT;
    if (key_blob == NULL)
        return KM_ERROR_OUTPUT_PARAMETER_NULL;
    key_blob->key_material = NULL;
    key_blob->key_material_size = 0;
    if (characteristics != NULL) {
        characteristics->hw_enforced.params = NULL;
        characteristics->hw_enforced.length = 0;
        characteristics->sw_enforced.params = NULL;
        characteristics->sw_enforced.length = 0;
    }

    {
        // Prepare inMem & outMem
        uint32_t inMemSize;
        uint32_t outMemSize = TEE_KEY_BLOB_SIZE;
        uint32_t res = KM_ERROR_UNKNOWN_ERROR;
        std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> inMem(marshal(params, &inMemSize));
        if (inMem.get() == NULL)
            return KM_ERROR_MEMORY_ALLOCATION_FAILED;
        std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> outMem((uint8_t *) malloc(outMemSize));
        if (outMem.get() == NULL)
            return KM_ERROR_MEMORY_ALLOCATION_FAILED;
        memset(outMem.get(), 0, outMemSize);

        if (!INVOKE(CMD_GENERATE_KEY, 0, 0, inMem.get(), inMemSize, outMem.get(), &outMemSize, &res))
            return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
        if (res != KM_ERROR_OK) {
            ALOGE("TEE return %d", res);
            return (keymaster_error_t) res;
        }

        key_blob->key_material = (uint8_t *) realloc(outMem.release(), outMemSize);
        key_blob->key_material_size = outMemSize;
    }

    // If the caller don't want the characteristics, return directly
    if (characteristics == NULL)
        return KM_ERROR_OK;

    {
        // Prepare client_id & app_data, call get_key_characteristics
        keymaster_blob_t client_id = { .data = NULL, .data_length = 0 }, app_data = { .data = NULL, .data_length = 0 };
        for (uint32_t i = 0; i < params->length; i++) {
            if (params->params[i].tag == KM_TAG_APPLICATION_ID)
                client_id = params->params[i].blob;
            else if (params->params[i].tag == KM_TAG_APPLICATION_DATA)
                app_data = params->params[i].blob;
        }
        get_key_characteristics(key_blob, &client_id, &app_data, characteristics);
    }

    return KM_ERROR_OK;
}

FORWARD4(get_key_characteristics,
        const keymaster_key_blob_t*, key_blob,
        const keymaster_blob_t*, client_id,
        const keymaster_blob_t*, app_data,
        keymaster_key_characteristics_t*, characteristics)
{
    if (key_blob == NULL || key_blob->key_material == NULL || key_blob->key_material_size == 0)
        return KM_ERROR_INVALID_ARGUMENT;
    if (characteristics == NULL)
        return KM_ERROR_OUTPUT_PARAMETER_NULL;
    characteristics->hw_enforced.params = NULL;
    characteristics->hw_enforced.length = 0;
    characteristics->sw_enforced.params = NULL;
    characteristics->sw_enforced.length = 0;

    uint32_t outMemSize = 0;
    uint32_t inMemSize = sizeof(uint32_t) + key_blob->key_material_size;
    if (client_id == NULL)
        inMemSize += sizeof(uint32_t);
    else
        inMemSize += sizeof(uint32_t) + client_id->data_length;
    if (app_data == NULL)
        inMemSize += sizeof(uint32_t);
    else
        inMemSize += sizeof(uint32_t) + app_data->data_length;
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> inMem((uint8_t *) malloc(inMemSize));
    if (inMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    do {
        // Prepare input memory

        uint8_t *p = inMem.get(), *pend = p + inMemSize;
        PACK_PRIMITIVE_ERR(uint32_t, key_blob->key_material_size, marshal_error);
        PACK_BYTES_ERR(key_blob->key_material, key_blob->key_material_size, marshal_error);

        if (client_id == NULL) {
            PACK_EXP_ERR(uint32_t, 0, marshal_error);
        } else {
            PACK_PRIMITIVE_ERR(uint32_t, client_id->data_length, marshal_error);
            PACK_BYTES_ERR(client_id->data, client_id->data_length, marshal_error);
        }

        if (app_data == NULL) {
            PACK_EXP_ERR(uint32_t, 0, marshal_error);
        } else {
            PACK_PRIMITIVE_ERR(uint32_t, app_data->data_length, marshal_error);
            PACK_BYTES_ERR(app_data->data, app_data->data_length, marshal_error);
        }
        break;

marshal_error:
        ALOGE("Marshal failed");
        return KM_ERROR_UNKNOWN_ERROR;
    } while(0);

    {
        outMemSize = 4096; // TODO: Is 4K enough?
    }

    {
        // Get output

        uint32_t res = KM_ERROR_UNKNOWN_ERROR;
        std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> outMem((uint8_t *) malloc(outMemSize));
        if (outMem.get() == NULL)
            return KM_ERROR_MEMORY_ALLOCATION_FAILED;
        memset(outMem.get(), 0, outMemSize);

        if (!INVOKE(CMD_GET_KEY_CHARACTER, 0, 0, inMem.get(), inMemSize, outMem.get(), &outMemSize, &res))
            return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
        if (res != KM_ERROR_OK) {
            ALOGE("Get key characteristics return %d", res);
            return (keymaster_error_t) res;
        }

        *characteristics = unmarshal_character(outMem.get(), outMemSize);
        if (characteristics->hw_enforced.params == NULL) {
            ALOGE("Unmarshal failed");
            return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
        }
    }

    return KM_ERROR_OK;
}

int
trustkernel::TrustKernelKeymasterImplementation::convert_to_evp(keymaster_algorithm_t algorithm) {
    switch (algorithm) {
        case KM_ALGORITHM_RSA:
            return EVP_PKEY_RSA;
        case KM_ALGORITHM_EC:
            return EVP_PKEY_EC;
        default:
            return -1;
    };
}

keymaster_error_t
trustkernel::TrustKernelKeymasterImplementation::convert_pkcs8_blob_to_evp(const uint8_t* key_data, size_t key_length,
        keymaster_algorithm_t expected_algorithm,
        std::unique_ptr<EVP_PKEY, ::trustkernel::EVP_PKEY_Delete>* pkey)
{
    if (key_data == NULL || key_length <= 0)
        return KM_ERROR_INVALID_ARGUMENT;

    std::unique_ptr<PKCS8_PRIV_KEY_INFO, ::trustkernel::PKCS8_PRIV_KEY_INFO_Delete> pkcs8(
            d2i_PKCS8_PRIV_KEY_INFO(NULL, &key_data, key_length));
    if (pkcs8.get() == NULL)
        return KM_ERROR_INVALID_ARGUMENT;

    pkey->reset(EVP_PKCS82PKEY(pkcs8.get()));
    if (!pkey->get())
        return KM_ERROR_INVALID_ARGUMENT;

    if (EVP_PKEY_type((*pkey)->type) != convert_to_evp(expected_algorithm)) {
        ALOGE("EVP key algorithm was %d, not the expected %d", EVP_PKEY_type((*pkey)->type),
                convert_to_evp(expected_algorithm));
        return KM_ERROR_INVALID_ARGUMENT;
    }

    return KM_ERROR_OK;
}

FORWARD5(import_key,
        const keymaster_key_param_set_t*, params,
        keymaster_key_format_t, key_format,
        const keymaster_blob_t*, key_data,
        keymaster_key_blob_t*, key_blob,
        keymaster_key_characteristics_t*, characteristics)
{
    if (params == NULL || key_data == NULL || key_data->data == NULL || key_data->data_length == 0)
        return KM_ERROR_INVALID_ARGUMENT;
    if (key_blob == NULL)
        return KM_ERROR_OUTPUT_PARAMETER_NULL;
    key_blob->key_material = NULL;
    key_blob->key_material_size = 0;
    if (characteristics != NULL) {
        characteristics->hw_enforced.params = NULL;
        characteristics->hw_enforced.length = 0;
        characteristics->sw_enforced.params = NULL;
        characteristics->sw_enforced.length = 0;
    }

    keymaster_error_t res;
    keymaster_key_param_t *algo_tag = keymaster_get_tag_unique(params, KM_TAG_ALGORITHM);
    if (algo_tag == NULL)
        return KM_ERROR_INVALID_ARGUMENT;

    uint32_t outMemSize = 8192; // TODO: 8K is enough?
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> outMem((uint8_t *) malloc(outMemSize));
    if (outMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    memset(outMem.get(), 0, outMemSize);

    switch (algo_tag->enumerated) {
        case KM_ALGORITHM_RSA:
            {
                if (key_format != KM_KEY_FORMAT_PKCS8)
                    return KM_ERROR_INCOMPATIBLE_KEY_FORMAT;
                std::unique_ptr<EVP_PKEY, ::trustkernel::EVP_PKEY_Delete> pkey;
                if ((res = convert_pkcs8_blob_to_evp(key_data->data, key_data->data_length, KM_ALGORITHM_RSA, &pkey)) != KM_ERROR_OK) {
                    ALOGE("Parse PKCS8 key failed");
                    return res;
                }

                std::unique_ptr<RSA, trustkernel::RSA_Delete> rsa(EVP_PKEY_get1_RSA(pkey.get()));
                if (rsa.get() == NULL) {
                    ALOGE("Get RSA key failed");
                    return KM_ERROR_INVALID_ARGUMENT;
                }

                uint32_t inMemSize = 0;
                std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> inMem;

                do {
                    uint32_t marshalled_size;
                    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> marshalled(marshal(params, &marshalled_size));

                    inMemSize += sizeof(uint32_t) + marshalled_size;
                    inMemSize += sizeof(uint32_t) + BN_num_bytes(rsa->n);
                    inMemSize += sizeof(uint32_t) + BN_num_bytes(rsa->e); // public
                    inMemSize += sizeof(uint32_t) + BN_num_bytes(rsa->d); // private
                    inMemSize += sizeof(uint32_t) + BN_num_bytes(rsa->p);
                    inMemSize += sizeof(uint32_t) + BN_num_bytes(rsa->q);
                    inMemSize += sizeof(uint32_t) + BN_num_bytes(rsa->dmp1);
                    inMemSize += sizeof(uint32_t) + BN_num_bytes(rsa->dmq1);
                    inMemSize += sizeof(uint32_t) + BN_num_bytes(rsa->iqmp);
                    inMem.reset((uint8_t *) malloc(inMemSize));
                    if (inMem.get() == NULL) {
                        ALOGE("Out of memory");
                        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
                    }

                    uint8_t *p = inMem.get(), *pend = p + inMemSize;
                    PACK_PRIMITIVE_ERR(uint32_t, marshalled_size, rsa_marshal_error);
                    PACK_BYTES_ERR(marshalled.get(), marshalled_size, rsa_marshal_error);
                    PACK_BN_ERR(rsa->n, rsa_marshal_error);
                    PACK_BN_ERR(rsa->e, rsa_marshal_error);
                    PACK_BN_ERR(rsa->d, rsa_marshal_error);
                    PACK_BN_ERR(rsa->p, rsa_marshal_error);
                    PACK_BN_ERR(rsa->q, rsa_marshal_error);
                    PACK_BN_ERR(rsa->dmp1, rsa_marshal_error);
                    PACK_BN_ERR(rsa->dmq1, rsa_marshal_error);
                    PACK_BN_ERR(rsa->iqmp, rsa_marshal_error);
                    break;

rsa_marshal_error:
                    ALOGE("Marshal failed");
                    return KM_ERROR_UNKNOWN_ERROR;
                } while(0);

                if (!INVOKE(CMD_IMPORT_KEY, 0, 0, inMem.get(), inMemSize, outMem.get(), &outMemSize, (uint32_t *) &res))
                    return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
                if (res != KM_ERROR_OK) {
                    ALOGE("TEE return %d", res);
                    return res;
                }
            }
            break;
        case KM_ALGORITHM_TRIPLE_DES:
        case KM_ALGORITHM_AES:
        case KM_ALGORITHM_HMAC:
            {
                if (key_format != KM_KEY_FORMAT_RAW)
                    return KM_ERROR_INCOMPATIBLE_KEY_FORMAT;

                uint32_t inMemSize = 0;
                std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> inMem;

                do {
                    uint32_t marshalled_size;
                    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> marshalled(marshal(params, &marshalled_size));

                    inMemSize += sizeof(uint32_t) + marshalled_size;
                    inMemSize += key_data->data_length;
                    inMem.reset((uint8_t *) malloc(inMemSize));
                    if (inMem.get() == NULL) {
                        ALOGE("Out of memory");
                        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
                    }

                    uint8_t *p = inMem.get(), *pend = p + inMemSize;
                    PACK_PRIMITIVE_ERR(uint32_t, marshalled_size, aes_marshal_error);
                    PACK_BYTES_ERR(marshalled.get(), marshalled_size, aes_marshal_error);
                    PACK_BYTES_ERR(key_data->data, key_data->data_length, aes_marshal_error);
                    break;

aes_marshal_error:
                    ALOGE("Marshal failed");
                    return KM_ERROR_UNKNOWN_ERROR;
                } while(0);

                if (!INVOKE(CMD_IMPORT_KEY, 0, 0, inMem.get(), inMemSize, outMem.get(), &outMemSize, (uint32_t *) &res))
                    return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
                if (res != KM_ERROR_OK) {
                    ALOGE("TEE return km_res %d", res);
                    return res;
                }
            }
            break;
        case KM_ALGORITHM_EC:
            {
                if (key_format != KM_KEY_FORMAT_PKCS8)
                    return KM_ERROR_INCOMPATIBLE_KEY_FORMAT;
                std::unique_ptr<EVP_PKEY, ::trustkernel::EVP_PKEY_Delete> pkey;
                if ((res = convert_pkcs8_blob_to_evp(key_data->data, key_data->data_length, KM_ALGORITHM_EC, &pkey)) != KM_ERROR_OK) {
                    ALOGE("Parse PKCS8 key failed");
                    return res;
                }

                std::unique_ptr<EC_KEY, ::trustkernel::EC_Delete> ec(EVP_PKEY_get1_EC_KEY(pkey.get()));
                if (ec.get() == NULL) {
                    ALOGE("Get EC key failed");
                    return KM_ERROR_INVALID_ARGUMENT;
                }
                const EC_POINT *pub = EC_KEY_get0_public_key(ec.get());
                if (pub == NULL) {
                    ALOGE("Get EC key failed");
                    return KM_ERROR_INVALID_ARGUMENT;
                }
                const BIGNUM *pri = EC_KEY_get0_private_key(ec.get());
                if (pri == NULL) {
                    ALOGE("Get EC key failed");
                    return KM_ERROR_INVALID_ARGUMENT;
                }
                uint32_t key_size;
                const EC_GROUP *group = EC_KEY_get0_group(ec.get());
                if (group == NULL) {
                    ALOGE("Get EC key failed");
                    return KM_ERROR_INVALID_ARGUMENT;
                }
                int nid = EC_GROUP_get_curve_name(group);
                if (nid == 0) {
                    ALOGE("Unsupported nid %d", nid);
                    return KM_ERROR_INVALID_ARGUMENT;
                }
                if (nid == NID_secp224r1)
                    key_size = 224;
                else if (nid == NID_X9_62_prime256v1)
                    key_size = 256;
                else if (nid == NID_secp384r1)
                    key_size = 384;
                else if (nid == NID_secp521r1)
                    key_size = 521;
                else {
                    ALOGE("Unsupported curve %d", nid);
                    return KM_ERROR_INVALID_ARGUMENT;
                }

                std::unique_ptr<BIGNUM, BN_Delete> pub_x(BN_new()), pub_y(BN_new());
                if (pub_x.get() == NULL || pub_y.get() == NULL) {
                    ALOGE("Out of memory");
                    return KM_ERROR_MEMORY_ALLOCATION_FAILED;
                }
                if (EC_POINT_get_affine_coordinates_GFp(group, pub, pub_x.get(), pub_y.get(), NULL) != 1) {
                    ALOGE("Error when get coordinates of public key");
                    return KM_ERROR_INVALID_ARGUMENT;
                }

                uint32_t inMemSize = 0;
                std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> inMem;

                do {
                    uint32_t marshalled_size;
                    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> marshalled(marshal(params, &marshalled_size));

                    inMemSize += sizeof(uint32_t) + marshalled_size;
                    inMemSize += sizeof(uint32_t);
                    inMemSize += sizeof(uint32_t) + BN_num_bytes(pub_x.get());
                    inMemSize += sizeof(uint32_t) + BN_num_bytes(pub_y.get()); // public
                    inMemSize += sizeof(uint32_t) + BN_num_bytes(pri); // private
                    inMem.reset((uint8_t *) malloc(inMemSize));
                    if (inMem.get() == NULL) {
                        ALOGE("Out of memory");
                        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
                    }

                    uint8_t *p = inMem.get(), *pend = p + inMemSize;
                    PACK_PRIMITIVE_ERR(uint32_t, marshalled_size, ec_marshal_error);
                    PACK_BYTES_ERR(marshalled.get(), marshalled_size, ec_marshal_error);
                    PACK_PRIMITIVE_ERR(uint32_t, key_size, ec_marshal_error);
                    PACK_BN_ERR(pub_x.get(), ec_marshal_error);
                    PACK_BN_ERR(pub_y.get(), ec_marshal_error);
                    PACK_BN_ERR(pri, ec_marshal_error);
                    break;

ec_marshal_error:
                    ALOGE("Marshal failed");
                    return KM_ERROR_UNKNOWN_ERROR;
                } while(0);

                if (!INVOKE(CMD_IMPORT_KEY, 0, 0, inMem.get(), inMemSize, outMem.get(), &outMemSize, (uint32_t *) &res))
                    return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
                if (res != KM_ERROR_OK) {
                    ALOGE("TEE return %d", res);
                    return res;
                }
            }
            break;
        default:
            return KM_ERROR_UNSUPPORTED_ALGORITHM;
    }

    do {
        uint8_t *p = outMem.get(), *pend = p + outMemSize;
        uint32_t size;

        EXTRACT_PRIMITIVE_ERR(uint32_t, size, unmarshal_error);
        key_blob->key_material = (uint8_t *) malloc(size);
        if (key_blob->key_material == NULL) {
            ALOGE("Out of memory");
            return KM_ERROR_MEMORY_ALLOCATION_FAILED;
        }
        EXTRACT_BYTES_ERR((void *) key_blob->key_material, size, unmarshal_error);
        key_blob->key_material_size = size;

        if (characteristics == NULL)
            return KM_ERROR_OK;

        EXTRACT_PRIMITIVE_ERR(uint32_t, size, unmarshal_error);
        *characteristics = unmarshal_character(p, size);
        if (characteristics->hw_enforced.params == NULL) {
            ALOGE("Unmarshal failed");
            goto unmarshal_error;
        }

        break;

unmarshal_error:
        ALOGE("Unmarshal failed");
        free((void *) key_blob->key_material);
        key_blob->key_material = NULL;
        key_blob->key_material_size = 0;
        return KM_ERROR_UNKNOWN_ERROR;
    } while (0);

    return KM_ERROR_OK;
}

keymaster_error_t
trustkernel::TrustKernelKeymasterImplementation::import_wrapped_key(const keymaster_key_blob_t *wrapped_key_data,
                                                                const keymaster_key_blob_t *wrapping_key_data,
                                                                const keymaster_key_blob_t *masking_key_data,
                                                                const keymaster_key_param_set_t *params,
                                                                uint64_t password_sid,
                                                                uint64_t biometric_sid,
                                                                keymaster_key_blob_t *key_blob,
                                                                keymaster_key_characteristics_t *characteristics)
{
    keymaster_error_t res;

    if (wrapped_key_data == NULL ||
        wrapped_key_data->key_material == NULL ||
        wrapped_key_data->key_material_size == 0 ||
        wrapping_key_data == NULL ||
        wrapping_key_data->key_material == NULL ||
        wrapping_key_data->key_material_size == 0 ||
        masking_key_data == NULL ||
        masking_key_data->key_material == NULL ||
        masking_key_data->key_material_size == 0) {
        return KM_ERROR_INVALID_ARGUMENT;
    }

    if (key_blob == NULL)
        return KM_ERROR_OUTPUT_PARAMETER_NULL;

    key_blob->key_material = NULL;
    key_blob->key_material_size = 0;

    uint32_t inMemSize = 0;
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> inMem;

    uint32_t outMemSize = 8192; // TODO: 8K is enough?
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> outMem((uint8_t *) malloc(outMemSize));
    if (outMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    memset(outMem.get(), 0, outMemSize);

    do {
        uint32_t marshalled_size;
        std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> marshalled(marshal(params, &marshalled_size));

        inMemSize += sizeof(uint32_t) + marshalled_size;
        inMemSize += sizeof(uint32_t) + wrapped_key_data->key_material_size;
        inMemSize += sizeof(uint32_t) + wrapping_key_data->key_material_size;
        inMemSize += sizeof(uint32_t) + masking_key_data->key_material_size;
        inMemSize += sizeof(uint64_t) + sizeof(uint64_t);

        inMem.reset((uint8_t *) malloc(inMemSize));
        if (inMem.get() == NULL) {
            ALOGE("Out of memory");
            return KM_ERROR_MEMORY_ALLOCATION_FAILED;
        }

        uint8_t *p = inMem.get(), *pend = p + inMemSize;

        PACK_PRIMITIVE_ERR(uint32_t, marshalled_size, marshal_error);
        PACK_BYTES_ERR(marshalled.get(), marshalled_size, marshal_error);

        PACK_PRIMITIVE_ERR(uint32_t,
            wrapped_key_data->key_material_size, marshal_error);
        PACK_BYTES_ERR(wrapped_key_data->key_material,
            wrapped_key_data->key_material_size, marshal_error);

        PACK_PRIMITIVE_ERR(uint32_t,
            wrapping_key_data->key_material_size, marshal_error);
        PACK_BYTES_ERR(wrapping_key_data->key_material,
            wrapping_key_data->key_material_size, marshal_error);

        PACK_PRIMITIVE_ERR(uint32_t,
            masking_key_data->key_material_size, marshal_error);
        PACK_BYTES_ERR(masking_key_data->key_material,
            masking_key_data->key_material_size, marshal_error);

        PACK_PRIMITIVE_ERR(uint64_t, password_sid, marshal_error);
        PACK_PRIMITIVE_ERR(uint64_t, biometric_sid, marshal_error);

        break;

marshal_error:
        ALOGE("Marshall failed");
        return KM_ERROR_UNKNOWN_ERROR;
    } while (0);

    if (!INVOKE(CMD_IMPORT_WRAPPED_KEY, 0, 0, inMem.get(), inMemSize, outMem.get(), &outMemSize, (uint32_t *) &res))
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;

    if (res != KM_ERROR_OK) {
        ALOGE("TEE return km_res %d", res);
        return res;
    }

    do {
        uint8_t *p = outMem.get(), *pend = p + outMemSize;
        uint32_t size;

        EXTRACT_PRIMITIVE_ERR(uint32_t, size, unmarshal_error);
        key_blob->key_material = (uint8_t *) malloc(size);
        if (key_blob->key_material == NULL) {
            ALOGE("Out of memory");
            return KM_ERROR_MEMORY_ALLOCATION_FAILED;
        }
        EXTRACT_BYTES_ERR((void *) key_blob->key_material, size, unmarshal_error);
        key_blob->key_material_size = size;

        if (characteristics == NULL)
            return KM_ERROR_OK;

        EXTRACT_PRIMITIVE_ERR(uint32_t, size, unmarshal_error);
        *characteristics = unmarshal_character(p, size);
        if (characteristics->hw_enforced.params == NULL) {
            ALOGE("Unmarshal failed");
            goto unmarshal_error;
        }

        break;

unmarshal_error:
        ALOGE("Unmarshal failed");
        free((void *) key_blob->key_material);
        key_blob->key_material = NULL;
        key_blob->key_material_size = 0;
        return KM_ERROR_UNKNOWN_ERROR;
    } while (0);

    return KM_ERROR_OK;
}

FORWARD5(export_key,
        keymaster_key_format_t, export_format,
        const keymaster_key_blob_t*, key_to_export,
        const keymaster_blob_t*, client_id,
        const keymaster_blob_t*, app_data,
             keymaster_blob_t*, export_data)
{
    if (key_to_export == NULL || key_to_export->key_material == NULL || key_to_export->key_material_size == 0)
        return KM_ERROR_INVALID_ARGUMENT;
    if (export_data == NULL)
        return KM_ERROR_OUTPUT_PARAMETER_NULL;
    export_data->data = NULL;
    export_data->data_length = 0;

    uint32_t res;
    std::unique_ptr<keymaster_key_characteristics_t, Characteristics_Delete> characters((keymaster_key_characteristics_t *) malloc(sizeof(keymaster_key_characteristics_t)));
    if (characters.get() == NULL) {
        ALOGE("Out of memory");
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    }
    {
        if ((res = get_key_characteristics(key_to_export, client_id, app_data, characters.get())) != KM_ERROR_OK) {
            ALOGE("Get key characteristics failed");
            return (keymaster_error_t) res;
        }
    }

    uint32_t inMemSize = sizeof(uint32_t) + key_to_export->key_material_size;
    if (client_id == NULL)
        inMemSize += sizeof(uint32_t);
    else
        inMemSize += sizeof(uint32_t) + client_id->data_length;
    if (app_data == NULL)
        inMemSize += sizeof(uint32_t);
    else
        inMemSize += sizeof(uint32_t) + app_data->data_length;
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> inMem((uint8_t *) malloc(inMemSize));
    if (inMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    do {
        // Prepare input memory

        uint8_t *p = inMem.get(), *pend = p + inMemSize;
        PACK_PRIMITIVE_ERR(uint32_t, key_to_export->key_material_size, marshal_error);
        PACK_BYTES_ERR(key_to_export->key_material, key_to_export->key_material_size, marshal_error);
        if (client_id == NULL) {
            PACK_EXP_ERR(uint32_t, 0, marshal_error);
        } else {
            PACK_PRIMITIVE_ERR(uint32_t, client_id->data_length, marshal_error);
            PACK_BYTES_ERR(client_id->data, client_id->data_length, marshal_error);
        }

        if (app_data == NULL) {
            PACK_EXP_ERR(uint32_t, 0, marshal_error);
        } else {
            PACK_PRIMITIVE_ERR(uint32_t, app_data->data_length, marshal_error);
            PACK_BYTES_ERR(app_data->data, app_data->data_length, marshal_error);
        }

        break;

marshal_error:
        ALOGE("Marshal failed");
        return KM_ERROR_UNKNOWN_ERROR;
    } while(0);

    uint32_t outMemSize = 4096; // TODO: How many memory do we need?
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> outMem((uint8_t *) malloc(outMemSize));
    if (outMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    memset(outMem.get(), 0, outMemSize);

    {
        // Get output
        uint32_t res = KM_ERROR_UNKNOWN_ERROR;

        if (!INVOKE(CMD_EXPORT_KEY, 0, 0, inMem.get(), inMemSize, outMem.get(), &outMemSize, &res))
            return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
        if (res != KM_ERROR_OK) {
            ALOGE("Export key return %d", res);
            return (keymaster_error_t) res;
        }
    }

    keymaster_key_param_t *tag = keymaster_get_tag_unique(&characters->hw_enforced, KM_TAG_ALGORITHM);
    if (tag == NULL) {
        ALOGE("No KM_TAG_ALGORITHM");
        return KM_ERROR_UNKNOWN_ERROR;
    }
    switch (tag->enumerated) {
        case KM_ALGORITHM_RSA:
            {
                if (export_format != KM_KEY_FORMAT_X509)
                    return KM_ERROR_UNSUPPORTED_KEY_FORMAT;
                export_data->data = (const uint8_t *) realloc(outMem.release(), outMemSize);
                export_data->data_length = outMemSize;
                return (keymaster_error_t) res;
            }
            break;
        case KM_ALGORITHM_EC:
            {
                if (export_format != KM_KEY_FORMAT_X509)
                    return KM_ERROR_UNSUPPORTED_KEY_FORMAT;
                std::unique_ptr<EC_KEY, ::trustkernel::EC_Delete> ec;
                std::unique_ptr<BIGNUM, ::trustkernel::BN_Delete> pub_x;
                std::unique_ptr<BIGNUM, ::trustkernel::BN_Delete> pub_y;
                uint32_t key_size;
                do {
                    uint8_t *p = outMem.get(), *pend = p + outMemSize, *tmp;
                    uint32_t size;

                    EXTRACT_PRIMITIVE_ERR(uint32_t, key_size, ec_unmarshal_error);
                    switch (key_size) {
                        case 224:
                            ec.reset(EC_KEY_new_by_curve_name(NID_secp224r1));
                            break;
                        case 256:
                            ec.reset(EC_KEY_new_by_curve_name(NID_X9_62_prime256v1));
                            break;
                        case 384:
                            ec.reset(EC_KEY_new_by_curve_name(NID_secp384r1));
                            break;
                        case 521:
                            ec.reset(EC_KEY_new_by_curve_name(NID_secp521r1));
                            break;
                        default:
                            ALOGE("Unknown key_size %d", key_size);
                            return KM_ERROR_UNKNOWN_ERROR;
                    }
                    if (ec.get() == NULL) {
                        ALOGE("Out of memory");
                        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
                    }
                    EXTRACT_PRIMITIVE_ERR(uint32_t, size, ec_unmarshal_error);
                    EXTRACT_BYTES_NOCOPY_ERR(tmp, size, ec_unmarshal_error);
                    pub_x.reset(BN_bin2bn(tmp, size, NULL));
                    if (pub_x.get() == 0) {
                        ALOGE("Out of memory");
                        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
                    }
                    EXTRACT_PRIMITIVE_ERR(uint32_t, size, ec_unmarshal_error);
                    EXTRACT_BYTES_NOCOPY_ERR(tmp, size, ec_unmarshal_error);
                    pub_y.reset(BN_bin2bn(tmp, size, NULL));
                    if (pub_y.get() == 0) {
                        ALOGE("Out of memory");
                        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
                    }
                    break;

ec_unmarshal_error:
                    ALOGE("Unmarshal failed");
                    return KM_ERROR_UNKNOWN_ERROR;
                } while(0);

                if (EC_KEY_set_public_key_affine_coordinates(ec.get(), pub_x.get(), pub_y.get()) != 1) {
                    ALOGE("EC set public key failed");
                    return KM_ERROR_UNKNOWN_ERROR;
                }

                std::unique_ptr<EVP_PKEY, ::trustkernel::EVP_PKEY_Delete> pkey(EVP_PKEY_new());
                if (pkey.get() == NULL) {
                    ALOGE("Out of memory");
                    return KM_ERROR_MEMORY_ALLOCATION_FAILED;
                }
                EVP_PKEY_set1_EC_KEY(pkey.get(), ec.get());

                int len = i2d_PUBKEY(pkey.get(), NULL);
                if (len <= 0) {
                    ALOGE("OpenSSL translate to X509 failed");
                    return KM_ERROR_UNKNOWN_ERROR;
                }

                std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> key(static_cast<uint8_t*>(malloc(len)));
                if (key.get() == NULL) {
                    ALOGE("Could not allocate memory for public key data");
                    return KM_ERROR_MEMORY_ALLOCATION_FAILED;
                }

                uint8_t *tmp = key.get();
                if (i2d_PUBKEY(pkey.get(), &tmp) != len) {
                    ALOGE("OpenSSL translate to X509 failed");
                    return KM_ERROR_UNKNOWN_ERROR;
                }

                export_data->data = key.release();
                export_data->data_length = len;
                return KM_ERROR_OK;
            }
            break;
        default:
            return KM_ERROR_INCOMPATIBLE_ALGORITHM;
    }
}

FORWARD1(delete_key, const keymaster_key_blob_t*, key)
{
    uint32_t res;
    if (key == NULL || key->key_material == NULL || key->key_material_size == 0)
        return KM_ERROR_INVALID_ARGUMENT;

    if (!INVOKE(CMD_DELETE_KEY, 0, 0, (void *) key->key_material, key->key_material_size, NULL, (uint32_t) 0, &res))
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;

    if (res != KM_ERROR_OK) {
        ALOGE("Delete key return %d", res);
        return (keymaster_error_t) res;
    }

    return KM_ERROR_OK;
}

FORWARD0(delete_all_keys) {
    uint32_t res;

    if (!INVOKE(CMD_DELETE_ALL_KEY, 0, 0, NULL, 0, NULL, (uint32_t) 0, &res))
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;

    if (res != KM_ERROR_OK) {
        ALOGE("Delete all key return %d", res);
        return (keymaster_error_t) res;
    }

    return KM_ERROR_OK;
}

FORWARD6(begin, keymaster_purpose_t, purpose,
             const keymaster_key_blob_t*, key,
             const keymaster_key_param_set_t*, in_params,
             const keymaster_blob_t*, auth_token_blob,
             keymaster_key_param_set_t*, out_params,
             keymaster_operation_handle_t*, operation_handle)
{
    uint32_t inMemSize, outMemSize;

    uint32_t res;
    uint32_t marshal_size;
    uint32_t operation;

    if (key == NULL || key->key_material == NULL || key->key_material_size == 0)
        return KM_ERROR_INVALID_ARGUMENT;
    if (out_params != NULL) {
        out_params->params = NULL;
        out_params->length = 0;
    }
    if (operation_handle == NULL)
        return KM_ERROR_OUTPUT_PARAMETER_NULL;
    *operation_handle = 0;

    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> marshalled(marshal(in_params, &marshal_size));
    if (marshalled.get() == NULL)
        return KM_ERROR_UNKNOWN_ERROR;
    inMemSize = sizeof(uint32_t) * 3 +
        key->key_material_size + marshal_size + auth_token_blob->data_length;
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> inMem((uint8_t *) malloc(inMemSize));
    if (inMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    do {
        uint8_t *p = inMem.get(), *pend = p + inMemSize;

        PACK_PRIMITIVE(uint32_t, key->key_material_size);
        PACK_BYTES(key->key_material, key->key_material_size);
        PACK_PRIMITIVE(uint32_t, marshal_size);
        PACK_BYTES(marshalled.get(), marshal_size);
        PACK_PRIMITIVE(uint32_t, auth_token_blob->data_length);
        PACK_BYTES(auth_token_blob->data, auth_token_blob->data_length);
        break;

error:
        ALOGE("Marshal failed");
        return KM_ERROR_UNKNOWN_ERROR;
    } while (0);

    outMemSize = 4096; // TODO: How much memory do we need?
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> outMem((uint8_t *) malloc(outMemSize));
    if (outMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    memset(outMem.get(), 0, outMemSize);

    if (!INVOKE(CMD_BEGIN, purpose, 0, inMem.get(), inMemSize, outMem.get(), &outMemSize, &res, &operation))
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
    if (res != KM_ERROR_OK) {
        ALOGE("TEE return %d", res);
        return (keymaster_error_t) res;
    }

    if (out_params == NULL && outMemSize != sizeof(uint32_t)) {
        ALOGE("Output parameter null");
        abort(operation);
        return KM_ERROR_OUTPUT_PARAMETER_NULL;
    }
    if (outMemSize != sizeof(uint32_t)) {
        *out_params = unmarshal_param_set(outMem.get(), outMemSize);
        if (out_params->params == NULL) {
            ALOGE("Unmarshal failed");
            abort(operation);
            return KM_ERROR_UNKNOWN_ERROR;
        }
    }
    *operation_handle = operation;

    return KM_ERROR_OK;
}

FORWARD7(update,
             keymaster_operation_handle_t, operation_handle,
             const keymaster_key_param_set_t*, in_params,
             const keymaster_blob_t*, input,
             size_t*, input_consumed,
             const keymaster_blob_t *, auth_token_blob,
             keymaster_key_param_set_t*, out_params,
             keymaster_blob_t*, output)
{
    uint32_t inMemSize, outMemSize;
    uint32_t res;
    uint32_t marshal_size;
    uint32_t _input_consumed;

    if (output) {
        output->data = NULL;
        output->data_length = 0;
    }
    if (out_params) {
        out_params->params = NULL;
        out_params->length = 0;
    }

    if (input_consumed == NULL)
        return KM_ERROR_OUTPUT_PARAMETER_NULL;
    *input_consumed = 0;
    if (input == NULL)
        return KM_ERROR_OK;

    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> marshalled(marshal(in_params, &marshal_size));
    if (marshalled.get() == NULL)
        return KM_ERROR_UNKNOWN_ERROR;
    inMemSize = sizeof(uint32_t) * 3 +
        input->data_length + marshal_size  + auth_token_blob->data_length;
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> inMem((uint8_t *) malloc(inMemSize));
    if (inMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    do {
        uint8_t *p = inMem.get(), *pend = p + inMemSize;
        PACK_PRIMITIVE(uint32_t, input->data_length);
        PACK_BYTES(input->data, input->data_length);
        PACK_PRIMITIVE(uint32_t, marshal_size);
        PACK_BYTES(marshalled.get(), marshal_size);
        PACK_PRIMITIVE(uint32_t, auth_token_blob->data_length);
        PACK_BYTES(auth_token_blob->data, (uint32_t) auth_token_blob->data_length);
        break;

error:
        ALOGE("Marshal failed");
        return KM_ERROR_UNKNOWN_ERROR;
    } while (0);

    outMemSize = std::max(input->data_length, (size_t) 4096); // TODO: How much memory do we need?
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> outMem((uint8_t *) malloc(outMemSize));
    if (outMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    memset(outMem.get(), 0, outMemSize);

    if (!INVOKE(CMD_UPDATE, operation_handle, 0, inMem.get(), inMemSize, outMem.get(), &outMemSize, &res, &_input_consumed))
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
    if (res != KM_ERROR_OK) {
        ALOGE("TEE return %d", res);
        return (keymaster_error_t) res;
    }
    ALOGD("Update output %dB", outMemSize);
    *input_consumed = _input_consumed;

    if (output == NULL) {
        if (outMemSize != 0)
            return KM_ERROR_OUTPUT_PARAMETER_NULL;
    } else {
        if (outMemSize != 0) {
            output->data = (const uint8_t *) realloc(outMem.release(), outMemSize);
            output->data_length = outMemSize;
        } else {
            output->data = NULL;
            output->data_length = 0;
        }
    }

    return KM_ERROR_OK;
}

FORWARD7(finish,
             keymaster_operation_handle_t, operation_handle,
             const keymaster_key_param_set_t*, in_params,
             const keymaster_blob_t*, input,
             const keymaster_blob_t*, signature,
             const keymaster_blob_t *, auth_token_blob,
             keymaster_key_param_set_t*, out_params,
             keymaster_blob_t*, output)
{
    uint32_t res;
    uint32_t inMemSize, outMemSize;
    uint32_t size, marshal_size;
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> pOutput;
    uint32_t pOutputSize;
    size_t consumed_size;

    if (output) {
        output->data = NULL;
        output->data_length = 0;
    }
    if (out_params) {
        out_params->params = NULL;
        out_params->length = 0;
    }

    res = update(operation_handle, in_params, input, &consumed_size, auth_token_blob, out_params, output);
    if (res != KM_ERROR_OK) {
        ALOGE("Do update in finish failed");
        return (keymaster_error_t) res;
    }
    if (output != NULL) {
        pOutput.reset((uint8_t *) output->data);
        pOutputSize = output->data_length;
        output->data = NULL;
        output->data_length = 0;
    }
    if (input != NULL && consumed_size != input->data_length) {
        ALOGE("Update in finish didn't consume all the data");
        return KM_ERROR_INVALID_INPUT_LENGTH;
    }

    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> marshalled(marshal(in_params, &marshal_size));
    if (marshalled.get() == NULL) {
        ALOGE("Marshal failed");
        return KM_ERROR_UNKNOWN_ERROR;
    }
    if (signature == NULL)
        inMemSize = sizeof(uint32_t) * 3 + marshal_size + auth_token_blob->data_length;
    else
        inMemSize = sizeof(uint32_t) * 3 +
            signature->data_length + marshal_size + auth_token_blob->data_length;
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> inMem((uint8_t *) malloc(inMemSize));
    if (inMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    do {
        uint8_t *p = inMem.get(), *pend = p + inMemSize;
        if (signature == NULL) {
            uint32_t zero = 0;
            PACK_PRIMITIVE_ERR(uint32_t, zero, marshal_error);
        } else {
            PACK_PRIMITIVE_ERR(uint32_t, signature->data_length, marshal_error);
            PACK_BYTES_ERR(signature->data, signature->data_length, marshal_error);
        }
        PACK_PRIMITIVE_ERR(uint32_t, marshal_size, marshal_error);
        PACK_BYTES_ERR(marshalled.get(), marshal_size, marshal_error);
        PACK_PRIMITIVE_ERR(uint32_t, auth_token_blob->data_length, marshal_error);
        PACK_BYTES_ERR(auth_token_blob->data, (uint32_t) auth_token_blob->data_length, marshal_error);
        break;

marshal_error:
        ALOGE("Marshal failed");
        return KM_ERROR_UNKNOWN_ERROR;
    } while (0);

    outMemSize = 4096; // TODO: How much memory do we need?
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> outMem((uint8_t *) malloc(outMemSize));
    if (outMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    memset(outMem.get(), 0, outMemSize);

    if (!INVOKE(CMD_FINISH, operation_handle, 0, inMem.get(), inMemSize, outMem.get(), &outMemSize, &res))
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
    if (res != KM_ERROR_OK) {
        ALOGE("TEE return %d", res);
        return (keymaster_error_t) res;
    }

    do {
        uint8_t *p = outMem.get(), *pend = p + outMemSize, *tmp;
        EXTRACT_PRIMITIVE_ERR(uint32_t, size, unmarshal_error);
        if (size != 0 && output == NULL)
            return KM_ERROR_OUTPUT_PARAMETER_NULL;
        {
            uint8_t *orig_buf = pOutput.release();
            uint8_t *tmp = (uint8_t *) realloc(orig_buf, pOutputSize + size);
            if (tmp == NULL) {
                ALOGE("Out of memory");
                free(orig_buf);
                return KM_ERROR_MEMORY_ALLOCATION_FAILED;
            }
            pOutput.reset(tmp);
        }
        EXTRACT_BYTES_ERR(pOutput.get() + pOutputSize, size, unmarshal_error);
        pOutputSize += size;
        EXTRACT_PRIMITIVE_ERR(uint32_t, size, unmarshal_error);
        if (size != sizeof(uint32_t) && out_params == NULL)
            return KM_ERROR_OUTPUT_PARAMETER_NULL;
        EXTRACT_BYTES_NOCOPY_ERR(tmp, size, unmarshal_error);
        if (size != sizeof(uint32_t)) {
            *out_params = unmarshal_param_set(tmp, size);
            if (out_params->params == NULL) {
                ALOGE("Unmarshal failed");
                return KM_ERROR_UNKNOWN_ERROR;
            }
        }

        output->data = pOutput.release();
        output->data_length = pOutputSize;
        break;

unmarshal_error:
        output->data_length = 0;
        if (out_params)
            out_params->length = 0;
        return KM_ERROR_UNKNOWN_ERROR;
    } while(0);

    return KM_ERROR_OK;
}

FORWARD1(abort, keymaster_operation_handle_t, operation_handle) {
    uint32_t res;

    if (!INVOKE(CMD_ABORT, operation_handle, 0, NULL, 0, NULL, (uint32_t) 0, &res))
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;

    if (res != KM_ERROR_OK) {
        ALOGE("Abort return %d", res);
        return (keymaster_error_t) res;
    }

    return KM_ERROR_OK;
}

FORWARD3(attest_key,
             const keymaster_key_blob_t*, key_to_attest,
             const keymaster_key_param_set_t*, attest_params,
             keymaster_cert_chain_t*, cert_chain)
{
    uint32_t inMemSize, outMemSize;

    uint32_t res;
    uint32_t marshal_size;
    uint32_t certs = 0;

    if (key_to_attest == NULL || key_to_attest->key_material == NULL || key_to_attest->key_material_size == 0)
        return KM_ERROR_INVALID_ARGUMENT;
    if (cert_chain == NULL)
        return KM_ERROR_OUTPUT_PARAMETER_NULL;
    cert_chain->entries = NULL;
    cert_chain->entry_count = 0;

    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> marshalled(marshal(attest_params, &marshal_size));
    if (marshalled.get() == NULL)
        return KM_ERROR_UNKNOWN_ERROR;
    inMemSize = sizeof(uint32_t) * 2 + key_to_attest->key_material_size + marshal_size;
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> inMem((uint8_t *) malloc(inMemSize));
    if (inMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;

    do {
        uint8_t *p = inMem.get(), *pend = p + inMemSize;
        PACK_PRIMITIVE_ERR(uint32_t, key_to_attest->key_material_size, marshal_error);
        PACK_BYTES_ERR(key_to_attest->key_material, key_to_attest->key_material_size, marshal_error);
        PACK_PRIMITIVE_ERR(uint32_t, marshal_size, marshal_error);
        PACK_BYTES_ERR(marshalled.get(), marshal_size, marshal_error);
        break;

marshal_error:
        ALOGE("Marshal failed");
        return KM_ERROR_UNKNOWN_ERROR;
    } while (0);

    outMemSize = 65536; // TODO: How much memory do we need?
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> outMem((uint8_t *) malloc(outMemSize));
    if (outMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    memset(outMem.get(), 0, outMemSize);

    if (!INVOKE(CMD_ATTEST_KEY, 0, 0, inMem.get(), inMemSize, outMem.get(), &outMemSize, &res, &certs))
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
    if (res != KM_ERROR_OK) {
        ALOGE("TEE return %d", res);
        return (keymaster_error_t) res;
    }

    cert_chain->entry_count = 0;
    cert_chain->entries = (keymaster_blob_t *) malloc(sizeof(keymaster_blob_t) * certs);
    if (cert_chain->entries == NULL) {
        ALOGE("Out of memory, need %zuB", sizeof(keymaster_blob_t) * certs);
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    }
    do {
        uint8_t *p = outMem.get(), *pend = p + outMemSize;
        uint32_t size;
        uint8_t *tmp = NULL;
        while (certs--) {
            EXTRACT_PRIMITIVE_ERR(uint32_t, size, unmarshal_error);
            tmp = (uint8_t *) malloc(size);
            if (tmp == NULL) {
                ALOGE("Out of memory, need %uB", size);
                return KM_ERROR_MEMORY_ALLOCATION_FAILED;
            }
            EXTRACT_BYTES_ERR(tmp, size, unmarshal_error);
            cert_chain->entries[cert_chain->entry_count].data = tmp;
            cert_chain->entries[cert_chain->entry_count].data_length = size;
            cert_chain->entry_count++;
        }
        break;
unmarshal_error:
        ALOGE("Unmarshal failed");
        keymaster_free_cert_chain(cert_chain);
        if (tmp)
            free(tmp);
        return KM_ERROR_UNKNOWN_ERROR;
    } while (0);

    return KM_ERROR_OK;
}

FORWARD1(configure,
             const keymaster_key_param_set_t*, params)
{
    uint32_t res;
    uint32_t marshal_size;

    configureData.reset(marshal(params, &marshal_size));
    if (configureData.get() == NULL)
        return KM_ERROR_UNKNOWN_ERROR;
    configureDataSize = marshal_size;

    if (!INVOKE(CMD_CONFIGURE, 0, 0, configureData.get(), configureDataSize, NULL, (uint32_t) 0, &res))
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
    if (res != KM_ERROR_OK) {
        ALOGE("TEE return %d", res);
        return (keymaster_error_t) res;
    }

    configured = true;
    return KM_ERROR_OK;
}

FORWARD3(upgrade_key,
             const keymaster_key_blob_t*, key_to_upgrade,
             const keymaster_key_param_set_t*, upgrade_params,
             keymaster_key_blob_t*, upgraded_key) {
    uint32_t inMemSize = 0;
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> inMem;
    uint32_t res;

    if (key_to_upgrade == NULL || key_to_upgrade->key_material == NULL || key_to_upgrade->key_material_size == 0)
        return KM_ERROR_INVALID_ARGUMENT;
    if (upgraded_key == NULL)
        return KM_ERROR_OUTPUT_PARAMETER_NULL;
    upgraded_key->key_material = NULL;
    upgraded_key->key_material_size = 0;

    do {
        uint32_t marshalled_size;
        std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> marshalled(marshal(upgrade_params, &marshalled_size));
        if (marshalled.get() == NULL) {
            ALOGE("Marshal failed");
            return KM_ERROR_MEMORY_ALLOCATION_FAILED;
        }

        inMemSize += sizeof(uint32_t) + marshalled_size;
        inMemSize += sizeof(uint32_t) + key_to_upgrade->key_material_size;
        inMem.reset((uint8_t *) malloc(inMemSize));
        if (inMem.get() == NULL) {
            ALOGE("Out of memory, need %uB", inMemSize);
            return KM_ERROR_MEMORY_ALLOCATION_FAILED;
        }

        uint8_t *p = inMem.get(), *pend = p + inMemSize;
        PACK_PRIMITIVE_ERR(uint32_t, marshalled_size, marshal_error);
        PACK_BYTES_ERR(marshalled.get(), marshalled_size, marshal_error);
        PACK_EXP_ERR(uint32_t, key_to_upgrade->key_material_size, marshal_error);
        PACK_BYTES_ERR(key_to_upgrade->key_material, key_to_upgrade->key_material_size, marshal_error);
        break;

marshal_error:
        ALOGE("Marshal failed");
        return KM_ERROR_UNKNOWN_ERROR;
    } while(0);

    uint32_t outMemSize = TEE_KEY_BLOB_SIZE;
    std::unique_ptr<uint8_t, ::trustkernel::Malloc_Free> outMem((uint8_t *) malloc(outMemSize));
    if (outMem.get() == NULL)
        return KM_ERROR_MEMORY_ALLOCATION_FAILED;
    memset(outMem.get(), 0, outMemSize);

    if (!INVOKE(CMD_UPGRADE_KEY, 0, 0, inMem.get(), inMemSize, outMem.get(), &outMemSize, &res))
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
    if (res != KM_ERROR_OK) {
        ALOGE("TEE return %d", res);
        return (keymaster_error_t) res;
    }

    upgraded_key->key_material = (uint8_t *) realloc(outMem.release(), outMemSize);
    upgraded_key->key_material_size = outMemSize;

    return KM_ERROR_OK;
}

FORWARD1(generate_attk_key_pair, const uint8_t, copy_num) {
    uint32_t res = 0;
    ALOGE("start generate_attk_key_pair\n");

    if (!INVOKE(CMD_soter_handle_generate_attk_key_pair, (uint32_t) copy_num, 0, NULL, 0, NULL, (uint32_t) 0, &res)) {
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
    }

    if (res != KM_ERROR_OK) {
        ALOGE("generate_attk_key_pair return %d", res);
        return (keymaster_error_t) res;
    } else {
        return KM_ERROR_OK;
    }
}

FORWARD0(verify_attk_key_pair)
{
    ALOGE("start verify_attk_key_pair\n");
    uint32_t res = 0;

    if (!INVOKE(CMD_soter_handle_verify_attk_key_pair, 0, 0, NULL, 0, NULL, (uint32_t) 0, &res)) {
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
    }

    if (res != KM_ERROR_OK) {
        ALOGE("verify_attk_key_pair return %d", res);
        return (keymaster_error_t) res;
    } else {
        return KM_ERROR_OK;
    }
}

FORWARD2(export_attk_public_key,
             const uint8_t*, pub_key_data,
             size_t*, pub_key_data_length)
{
    uint32_t res = 0;
    uint32_t length = *pub_key_data_length;

    if (!INVOKE(CMD_soter_handle_export_attk_public_key, 0, 0,
            NULL, 0, (uint8_t *)pub_key_data, &length, &res)) {
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
    }

    if (res != KM_ERROR_OK) {
        ALOGE("export_attk_public_key return %d", res);
        return (keymaster_error_t) res;
    } else {
        *pub_key_data_length = length;
        return KM_ERROR_OK;
    }
}

FORWARD2(get_device_id, const uint8_t*, device_id,
        size_t*, device_id_length)
{
    ALOGE("enter get_device_id\n");
    uint32_t res = 0;
    uint32_t length = *device_id_length;

    if (!INVOKE(CMD_soter_handle_get_device_id, 0, 0,
        NULL, 0, (uint8_t *) device_id, &length,
        &res)) {
        return KM_ERROR_SECURE_HW_COMMUNICATION_FAILED;
    }

    if (res != KM_ERROR_OK) {
        ALOGE("get_device_id return %d", res);
        return (keymaster_error_t) res;
    } else {
        *device_id_length = length;
        return KM_ERROR_OK;
    }
}

trustkernel::TrustKernelKeymasterImplementation::~TrustKernelKeymasterImplementation() {
    CloseTEESession();
}

trustkernel::TrustKernelKeymasterImplementation::TrustKernelKeymasterImplementation() {
    error_ = OpenTEESession();
}

void trustkernel::TrustKernelKeymasterImplementation::CloseTEESession() {
    TEEC_CloseSession(&session);
    TEEC_FinalizeContext(&context);
}

TEEC_Result trustkernel::TrustKernelKeymasterImplementation::OpenTEESession() {
// retry teec_#name, and set error code into error_
#define RETRY_TEEC_FUNC(name, ...) do { \
    for (;;) { \
        error_ = TEEC_##name(__VA_ARGS__); \
        if (error_ != TEEC_SUCCESS) { \
            ALOGE(" " #name " failed with 0x%08x\n", error_); \
            sleep(1); \
        } else { \
            break; \
        } \
    } \
} while(0)

    uint32_t orig;

    RETRY_TEEC_FUNC(InitializeContext, NULL, &context);
    if (error_ != TEEC_SUCCESS) {
        ALOGE("TEEC_InitializeContext failed with return value:%x\n", error_);
        goto cleanup_1;
    }

    RETRY_TEEC_FUNC(OpenSession, &context, &session,
            &UUID_TrustKernelKeymasterV2, TEEC_LOGIN_PUBLIC,
            NULL, NULL, &orig);
    if(error_ != TEEC_SUCCESS) {
        ALOGE("TEEC_OpenSession failed with return value:%x, orig 0x%x\n", error_, orig);
        goto cleanup_2;
    }

    ALOGI("Open session successfully\n");
    configured = false;

    return 0;

cleanup_2:
    TEEC_FinalizeContext(&context);
cleanup_1:
    return error_;
#undef RETRY_TEEC_FUNC
}