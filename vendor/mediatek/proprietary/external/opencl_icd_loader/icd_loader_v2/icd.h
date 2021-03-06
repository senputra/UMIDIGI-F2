/*
 * Copyright (c) 2016 The Khronos Group Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software source and associated documentation files (the "Materials"),
 * to deal in the Materials without restriction, including without limitation
 * the rights to use, copy, modify, compile, merge, publish, distribute,
 * sublicense, and/or sell copies of the Materials, and to permit persons to
 * whom the Materials are furnished to do so, subject the following terms and
 * conditions:
 *
 * All modifications to the Materials used to create a binary that is
 * distributed to third parties shall be provided to Khronos with an
 * unrestricted license to use for the purposes of implementing bug fixes and
 * enhancements to the Materials;
 *
 * If the binary is used as part of an OpenCL(TM) implementation, whether binary
 * is distributed together with or separately to that implementation, then
 * recipient must become an OpenCL Adopter and follow the published OpenCL
 * conformance process for that implementation, details at:
 * http://www.khronos.org/conformance/;
 *
 * The above copyright notice, the OpenCL trademark license, and this permission
 * notice shall be included in all copies or substantial portions of the
 * Materials.
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE MATERIALS OR THE USE OR OTHER DEALINGS IN
 * THE MATERIALS.
 *
 * OpenCL is a trademark of Apple Inc. used under license by Khronos.
 */

#ifndef _ICD_H_
#define _ICD_H_

#ifndef CL_USE_DEPRECATED_OPENCL_1_0_APIS
#define CL_USE_DEPRECATED_OPENCL_1_0_APIS
#endif

#ifndef CL_USE_DEPRECATED_OPENCL_1_1_APIS
#define CL_USE_DEPRECATED_OPENCL_1_1_APIS
#endif

#ifndef CL_USE_DEPRECATED_OPENCL_1_2_APIS
#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#endif

#include <CL/cl.h>
#include <CL/cl_ext.h>

#ifdef _WIN32
#include <tchar.h>
#endif

/*
 * type definitions
 */

typedef CL_API_ENTRY cl_int (CL_API_CALL *pfn_clIcdGetPlatformIDs)(
    cl_uint num_entries, 
    cl_platform_id *platforms, 
    cl_uint *num_platforms) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *pfn_clGetPlatformInfo)(
    cl_platform_id   platform, 
    cl_platform_info param_name,
    size_t           param_value_size, 
    void *           param_value,
    size_t *         param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY void *(CL_API_CALL *pfn_clGetExtensionFunctionAddress)(
    const char *function_name)  CL_API_SUFFIX__VERSION_1_0;

typedef struct KHRicdVendorRec KHRicdVendor;

/* 
 * KHRicdVendor
 *
 * Data for a single ICD vendor platform.
 */
struct KHRicdVendorRec
{
    // the loaded library object (true type varies on Linux versus Windows)
    void *library;

    // the extension suffix for this platform
    char *suffix;

    // function pointer to the ICD platform IDs extracted from the library
    pfn_clGetExtensionFunctionAddress clGetExtensionFunctionAddress;

    // the platform retrieved from clGetIcdPlatformIDsKHR
    cl_platform_id platform;

    // next vendor in the list vendors
    KHRicdVendor *next;
};

// the global state
extern KHRicdVendor * khrIcdVendors;

/* 
 * khrIcd interface
 */

// read vendors from system configuration and store the data
// loaded into khrIcdState.  this will call the OS-specific
// function khrIcdEnumerateVendors.  this is called at every
// dispatch function which may be a valid first call into the
// API (e.g, getPlatformIDs, etc).
void khrIcdInitialize(void);

// go through the list of vendors (in /etc/OpenCL.conf or through 
// the registry) and call khrIcdVendorAdd for each vendor encountered
// n.b, this call is OS-specific
void khrIcdOsVendorsEnumerateOnce(void);

// add a vendor's implementation to the list of libraries
void khrIcdVendorAdd(const char *libraryName);

// dynamically load a library.  returns NULL on failure
// n.b, this call is OS-specific
void *khrIcdOsLibraryLoad(const char *libraryName);

// get a function pointer from a loaded library.  returns NULL on failure.
// n.b, this call is OS-specific
void *khrIcdOsLibraryGetFunctionAddress(void *library, const char *functionName);

// unload a library.
// n.b, this call is OS-specific
void khrIcdOsLibraryUnload(void *library);

// parse properties and determine the platform to use from them
void khrIcdContextPropertiesGetPlatform(
    const cl_context_properties *properties, 
    cl_platform_id *outPlatform);

// internal tracing macros
#if 0
    #include <stdio.h>
    #define KHR_ICD_TRACE(...) \
    do \
    { \
        fprintf(stderr, "KHR ICD trace at %s:%d: ", __FILE__, __LINE__); \
        fprintf(stderr, __VA_ARGS__); \
    } while (0)
#ifdef _WIN32
#define KHR_ICD_WIDE_TRACE(...) \
    do \
    { \
        fwprintf(stderr, L"KHR ICD trace at %hs:%d: ", __FILE__, __LINE__); \
        fwprintf(stderr, __VA_ARGS__); \
    } while (0)
#else
#define KHR_ICD_WIDE_TRACE(...)
#endif
    #define KHR_ICD_ASSERT(x) \
    do \
    { \
        if (!(x)) \
        { \
            fprintf(stderr, "KHR ICD assert at %s:%d: %s failed", __FILE__, __LINE__, #x); \
        } \
    } while (0)
#else
    #define KHR_ICD_TRACE(...)
    #define KHR_ICD_WIDE_TRACE(...)
    #define KHR_ICD_ASSERT(x)
#endif

// if handle is NULL then return invalid_handle_error_code
#define KHR_ICD_VALIDATE_HANDLE_RETURN_ERROR(handle,invalid_handle_error_code) \
    do \
    { \
        if (!handle) \
        { \
            return invalid_handle_error_code; \
        } \
    } while (0)

// if handle is NULL then set errcode_ret to invalid_handle_error and return NULL 
// (NULL being an invalid handle)
#define KHR_ICD_VALIDATE_HANDLE_RETURN_HANDLE(handle,invalid_handle_error) \
    do \
    { \
        if (!handle) \
        { \
            if (errcode_ret) \
            { \
                *errcode_ret = invalid_handle_error; \
            } \
            return NULL; \
        } \
    } while (0)

#ifdef CL_TRACE
// OpenCL API Trace
void initCLTraceLevel();
extern cl_bool sCLSystraceEnabled;
extern cl_bool sCLTraceLevel;
#endif

#endif