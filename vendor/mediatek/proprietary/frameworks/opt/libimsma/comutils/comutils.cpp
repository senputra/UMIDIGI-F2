
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   Rotate.cpp
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *   do video buffer rotation
 *
 * Author:
 * -------
 *   Qian Dong
 *
 ****************************************************************************/
#include <utils/Log.h>
#undef LOG_TAG
#define LOG_TAG "[VT][comutils]"
#include "comutils.h"
#include <OMX_IVCommon.h>
#include <cutils/properties.h>
#include <media/stagefright/foundation/ADebug.h>
#include <media/stagefright/foundation/AString.h>
#include <media/stagefright/foundation/base64.h>
#include "media/stagefright/foundation/avc_utils.h"
#include <utils/Vector.h>
#include <utils/Trace.h>
#include <OMX_Video.h>
#include <OMX_VideoExt.h>
#include <media/stagefright/MediaDefs.h>
#include <ctype.h>
#include <media/stagefright/foundation/ABitReader.h>
#include <system/graphics.h>
#include <utils/Timers.h>


#if USING_MDP_PRE_PREOCESS

#ifdef USING_MDP_BY_HIDL
#include <ion/ion.h>
#include <ion_copy.h>
//#include <linux/ion_drv.h>
//#include <linux/mtk_ion.h>
#include <vendor/mediatek/hardware/mms/1.1/IMms.h>
#include "DpColorFormat.h"

using ::vendor::mediatek::hardware::mms::V1_1::IMms;
using ::vendor::mediatek::hardware::mms::V1_1::HwMDPParam;
using ::vendor::mediatek::hardware::mms::V1_1::DpRect;

#else
#include "DpBlitStream.h"
#endif
#else
#include "DpColorFormat.h" //for compile
#endif



#define MEM_ALIGN_32 32
#define ROUND_2(X)     ((X + 0x1) & (~0x1))
#define ROUND_8(X)     ((X + 0x7) & (~0x7))
#define ROUND_16(X)     ((X + 0xF) & (~0xF))
#define ROUND_32(X)     ((X + 0x1F) & (~0x1F))
#define YUV_SIZE(W,H)   (W * H * 3 >> 1)
#define RGB888_SIZE(W,H)   (W * H * 3)
#define ARGB888_SIZE(W,H)   (W * H * 4)
enum {
    UV_STRIDE_16_8_8,
    UV_STRIDE_16_16_16,
    UV_STRIDE_other,
};


namespace android
{
static void printBinary(uint8_t *ptrBS, int iLen)
{
    int i;
    char tmp[1024];
    char *ptr = tmp;

    for(i = 0; i < iLen; ++i) {
        sprintf(ptr, "%02x", ptrBS[i]);
        ptr += 2;
    }

    *ptr = '\0';
    ALOGI("[genParameterSets] bssize(%d), bs(%s)", iLen, tmp);
}


int32_t  RemovePreventionByte(uint8_t *profile_tier_level, uint8_t size)
{
    int32_t pos = 0;
    int32_t leftSize = size ;

    for(; pos < size - 2;) {
        if(profile_tier_level[pos] == 0x00 &&
                profile_tier_level[pos + 1] == 0x00 &&
                profile_tier_level[pos + 2] == 0x03) {
            memmove(profile_tier_level + pos + 2, profile_tier_level + pos + 3, size - (pos + 3));
            pos += 2;
            leftSize--;//remove 1 0x03
        } else {
            pos++;
        }
    }

    VT_LOGD("Size %d --> leftSize %d",size,leftSize);
    return leftSize;
}

DpColorFormat OmxColorToDpColor(int32_t omx_color_format)
{
    DpColorFormat colorFormat;

    switch(omx_color_format) {
    case OMX_COLOR_FormatVendorMTKYUV:
        colorFormat = eNV12_BLK;
        break;
    case OMX_COLOR_FormatVendorMTKYUV_FCM:
        colorFormat = eNV12_BLK_FCM;
        break;
    case OMX_COLOR_FormatYUV420Planar:
        colorFormat = eYUV_420_3P;
        break;
    case OMX_MTK_COLOR_FormatYV12://HAL3
        colorFormat = eYV12;
        break;
    case OMX_COLOR_Format24bitRGB888:
        colorFormat = eRGB888 ;
        break;
    case OMX_COLOR_Format32bitARGB8888:
        colorFormat = eARGB8888  ;
        break;
    case OMX_COLOR_Format32BitRGBA8888://hAL1
        colorFormat = eRGBA8888 ;
        break;
    case OMX_COLOR_FormatYUV420SemiPlanar://NV21
        colorFormat = eNV21 ;
        break;	
    default:
        colorFormat = eYUV_420_3P;
        VT_LOGE("[Warning] Cannot find color mapping !!");
        break;
    }

    return colorFormat;
}

const char *PixelFormatToString(int32_t pixelFormat)
{
    switch(pixelFormat) {
    case HAL_PIXEL_FORMAT_RGBA_8888:
        return "HAL_PIXEL_FORMAT_RGBA_8888";
    case HAL_PIXEL_FORMAT_RGBX_8888:
        return "HAL_PIXEL_FORMAT_RGBX_8888";
    case HAL_PIXEL_FORMAT_RGB_888:
        return "HAL_PIXEL_FORMAT_RGB_888";
    case HAL_PIXEL_FORMAT_RGB_565:
        return "HAL_PIXEL_FORMAT_RGB_565";
    case HAL_PIXEL_FORMAT_BGRA_8888:
        return "HAL_PIXEL_FORMAT_BGRA_8888";
    case HAL_PIXEL_FORMAT_YV12:
        return "HAL_PIXEL_FORMAT_YV12";
    case HAL_PIXEL_FORMAT_YCrCb_420_SP://NV21
        return "HAL_PIXEL_FORMAT_YCrCb_420_SP ";
    case HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED:
        return "HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED";
    default:
        return "Unknown Pixel Format";
    }
}
const char *OmxFormatToString(int32_t omxFormat)
{
    switch((OMX_COLOR_FORMATTYPE) omxFormat) {
    case OMX_MTK_COLOR_FormatYV12:
        return "OMX_MTK_COLOR_FormatYV12";
    case OMX_COLOR_FormatYUV420SemiPlanar:
        return "OMX_COLOR_FormatYUV420SemiPlanar";
    case OMX_COLOR_Format24bitRGB888:
        return "OMX_COLOR_Format24bitRGB888";
    case OMX_COLOR_FormatAndroidOpaque:
        return "OMX_COLOR_FormatAndroidOpaque";
    case OMX_COLOR_Format32bitARGB8888:
        return "OMX_COLOR_Format32bitARGB8888";
    case OMX_COLOR_Format32BitRGBA8888:
        return "OMX_COLOR_Format32BitRGBA8888";
    case OMX_COLOR_Format32bitBGRA8888:
        return "OMX_COLOR_Format32bitBGRA8888";
    default:
        return "Unknown OMX Format";
    }
}

int32_t PixelForamt2ColorFomat(int32_t pixelFormat)
{
    int32_t  colorFormat;

    switch(pixelFormat) {
    case HAL_PIXEL_FORMAT_YV12://0x32315659
        colorFormat =  OMX_MTK_COLOR_FormatYV12;//0x7F000200,
        break;

    case HAL_PIXEL_FORMAT_YCrCb_420_SP://17
        colorFormat =  OMX_COLOR_FormatYUV420SemiPlanar;//  NV21 17  
        break;

    case HAL_PIXEL_FORMAT_RGB_888:
        colorFormat =  OMX_COLOR_Format24bitRGB888;
        break;

    case HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED:// = 0x22,TODO qian
        colorFormat =  OMX_COLOR_FormatAndroidOpaque;
        break;

    case HAL_PIXEL_FORMAT_RGBA_8888://0x1
        colorFormat =  OMX_COLOR_Format32BitRGBA8888;//TODO 0x7F00A000
        break;

    default :
        colorFormat = OMX_COLOR_FormatAndroidOpaque;
        break;
    }

    //CHECK(colorFormat == OMX_MTK_COLOR_FormatYV12);
    return colorFormat;
}
int32_t getEncoderInPutFormat()
{
    /*
    OMX_COLOR_FormatYUV420SemiPlanar = 11
    OMX_MTK_COLOR_FormatYV12 = 0x7F000200
    char value[PROPERTY_VALUE_MAX];
    if (property_get("persist.vendor.radio.vilte.enc.format", value, NULL)) {//resolution change interval
    format = atoi(value);
    VT_LOGI("[ID=%d]format %s",mMultiInstanceID,OmxFormatToString(format));
    }
    */
    return OMX_MTK_COLOR_FormatYV12;//OMX_COLOR_FormatYUV420SemiPlanar
}

void mtk_scaling_list(int32_t sizeOfScalingList, ABitReader *br)
{
    int lastScale = 8;
    int nextScale = 8;

    for(int j = 0; j < sizeOfScalingList; j++) {
        if(nextScale != 0) {
            int32_t delta_scale = parseSE(br);
            nextScale = (lastScale + delta_scale + 256) % 256;
        }

        lastScale = (nextScale == 0) ? lastScale : nextScale;
    }
}

void mtk_parse_seq_scaling_matrix_present(ABitReader *br)
{
    for(int i = 0; i < 8; i++) {
        uint32_t seq_scaling_list_present_flag =  br->getBits(1);
        ALOGV("seq_scaling_list_presetn_flag :%d", seq_scaling_list_present_flag);

        if(seq_scaling_list_present_flag) {
            if(i < 6)
                mtk_scaling_list(16, br);
            else
                mtk_scaling_list(64, br);
        }
    }
}


void MTKFindAVCSPSInfo(
    uint8_t *seqParamSet, size_t size, struct MtkSPSInfo *pSPSInfo)
{
    if(pSPSInfo == NULL) {
        ALOGE("pSPSInfo == NULL");
        return ;
    }

    ABitReader br(seqParamSet + 1, size - 1);

    unsigned profile_idc = br.getBits(8);
    pSPSInfo->profile = profile_idc;
    br.skipBits(8);

    pSPSInfo->level = br.getBits(8);
    parseUE(&br);    // seq_parameter_set_id

    unsigned chroma_format_idc = 1;  // 4:2:0 chroma format

    if(profile_idc == 100 || profile_idc == 110
            || profile_idc == 122 || profile_idc == 244
            || profile_idc == 44 || profile_idc == 83 || profile_idc == 86) {
        chroma_format_idc = parseUE(&br);

        if(chroma_format_idc == 3) {
            br.skipBits(1);    // residual_colour_transform_flag
        }

        parseUE(&br);    // bit_depth_luma_minus8
        parseUE(&br);    // bit_depth_chroma_minus8
        br.skipBits(1);    // qpprime_y_zero_transform_bypass_flag

        // CHECK_EQ(br.getBits(1), 0u);  // seq_scaling_matrix_present_flag
        if(br.getBits(1) != 0) {
            ALOGW("seq_scaling_matrix_present_flag != 0");
            mtk_parse_seq_scaling_matrix_present(&br);
        }
    }

    parseUE(&br);    // log2_max_frame_num_minus4
    unsigned pic_order_cnt_type = parseUE(&br);

    if(pic_order_cnt_type == 0) {
        parseUE(&br);    // log2_max_pic_order_cnt_lsb_minus4
    } else if(pic_order_cnt_type == 1) {
        // offset_for_non_ref_pic, offset_for_top_to_bottom_field and
        // offset_for_ref_frame are technically se(v), but since we are
        // just skipping over them the midpoint does not matter.

        br.getBits(1);    // delta_pic_order_always_zero_flag
        parseUE(&br);    // offset_for_non_ref_pic
        parseUE(&br);    // offset_for_top_to_bottom_field

        unsigned num_ref_frames_in_pic_order_cnt_cycle = parseUE(&br);

        for(unsigned i = 0; i < num_ref_frames_in_pic_order_cnt_cycle; ++i) {
            parseUE(&br);    // offset_for_ref_frame
        }
    }

    parseUE(&br);    // num_ref_frames
    br.getBits(1);    // gaps_in_frame_num_value_allowed_flag

    unsigned pic_width_in_mbs_minus1 = parseUE(&br);
    unsigned pic_height_in_map_units_minus1 = parseUE(&br);
    unsigned frame_mbs_only_flag = br.getBits(1);

    pSPSInfo->width = pic_width_in_mbs_minus1 * 16 + 16;

    pSPSInfo->height = (2 - frame_mbs_only_flag)
                       * (pic_height_in_map_units_minus1 * 16 + 16);

    if(!frame_mbs_only_flag) {
        br.getBits(1);    // mb_adaptive_frame_field_flag
    }

    br.getBits(1);    // direct_8x8_inference_flag

    if(br.getBits(1)) {       // frame_cropping_flag
        unsigned frame_crop_left_offset = parseUE(&br);
        unsigned frame_crop_right_offset = parseUE(&br);
        unsigned frame_crop_top_offset = parseUE(&br);
        unsigned frame_crop_bottom_offset = parseUE(&br);

        unsigned cropUnitX, cropUnitY;

        if(chroma_format_idc == 0  /* monochrome */) {
            cropUnitX = 1;
            cropUnitY = 2 - frame_mbs_only_flag;
        } else {
            unsigned subWidthC = (chroma_format_idc == 3) ? 1 : 2;
            unsigned subHeightC = (chroma_format_idc == 1) ? 2 : 1;

            cropUnitX = subWidthC;
            cropUnitY = subHeightC * (2 - frame_mbs_only_flag);
        }

        ALOGV("frame_crop = (%u, %u, %u, %u), cropUnitX = %u, cropUnitY = %u",
              frame_crop_left_offset, frame_crop_right_offset,
              frame_crop_top_offset, frame_crop_bottom_offset,
              cropUnitX, cropUnitY);

        pSPSInfo->width -=
            (frame_crop_left_offset + frame_crop_right_offset) * cropUnitX;
        pSPSInfo->height -=
            (frame_crop_top_offset + frame_crop_bottom_offset) * cropUnitY;
    }

    return ;
}


sp<ABuffer> MakeAVCCodecSpecificData(
    const char *params,
    int32_t *profile,int32_t *level,
    int32_t *width, int32_t *height, int32_t *sarWidth, int32_t *sarHeight)
{

    AString val(params);
    Vector<sp<ABuffer> > paramSets;

    size_t numSeqParameterSets = 0;
    size_t totalSeqParameterSetSize = 0;
    size_t numPicParameterSets = 0;
    size_t totalPicParameterSetSize = 0;
    *profile = 0;
    *level = 0;

    VT_LOGD("params : %s width=%d height=%d sarWidth=%d sarHeight=%d",
            val.c_str(), *width, *height, *sarWidth, *sarHeight);

    //VT_LOGD("params : %s",val.c_str());

    size_t start = 0;
    int loopCount = 0;

    for(;;) {
        bool parseErr = false;
        ssize_t commaPos = val.find(",", start);
        size_t end = (commaPos < 0) ? val.size() : commaPos;

        AString nalString(val, start, end - start);
        VT_LOGD("nalString : %s,start %zu",nalString.c_str(),start);

        sp<ABuffer> nal = decodeBase64(nalString);

        if(nal == NULL) {
            VT_LOGI("params error 1 @ start %zu",start);
            return NULL;
        }

        //maybe have some tuncate SPS in CMCC...
        if(loopCount++ == 0 && nal->size() < 10) {
            VT_LOGE("find SPS nal_size too little %zu",nal->size());
            return NULL;
        }

        int32_t leftSize = RemovePreventionByte(nal->data(), nal->size());
        nal->setRange(0, leftSize);


        if(nal->size() <= 0) {
            VT_LOGE("params error 2 @ start %zu",start);
            parseErr = true;
        }

        if(nal->size() >=65535u) {
            VT_LOGE("params error 3 @ start %zu",start);
            parseErr = true;
        }

        if(parseErr) {
            if(numSeqParameterSets == 0) {
                VT_LOGE("can not find right sps, return NULL");
                return NULL;
            } else {
                VT_LOGE("find %zu sps, %zu pps,",numSeqParameterSets,numPicParameterSets);
                break;
            }
        }

        uint8_t nalType = nal->data() [0] & 0x1f;

        if(numSeqParameterSets == 0) {
            CHECK_EQ((unsigned) nalType, 7u);      //sps
        } else if(numPicParameterSets > 0) {
            CHECK_EQ((unsigned) nalType, 8u);      //pps
        }

        if(nalType == 7) {
            ++numSeqParameterSets;
            totalSeqParameterSetSize += nal->size();
        } else  {
            CHECK_EQ((unsigned) nalType, 8u);
            ++numPicParameterSets;
            totalPicParameterSetSize += nal->size();
        }

        paramSets.push(nal);

        if(commaPos < 0) {
            break;
        }

        start = commaPos + 1;
    }

    CHECK_LT(numSeqParameterSets, 32u);
    CHECK_LE(numPicParameterSets, 255u);

    size_t csdSize =
        1 + 3 + 1 + 1 /*configurationVersion +profilelevel +lengthSizes */
        + 2 * numSeqParameterSets/*size field*/ + totalSeqParameterSetSize
        + 1 + 2 * numPicParameterSets/*size field*/ + totalPicParameterSetSize;

    sp<ABuffer> csd = new ABuffer(csdSize);
    uint8_t *out = csd->data();

    *out++ = 0x01;  // configurationVersion

    sp<ABuffer> nal = paramSets.editItemAt(0);
    memcpy(out, nal->data() + 1, 3);    // profile/level... memcpy(out, profilelevel, 3);
    VT_LOGD("P L %p", (nal->data() + 1));
    out += 3;

    *out++ = (0x3f << 2) | 1;   // lengthSize == 2 bytes
    *out++ = 0xe0 | numSeqParameterSets;


    for(size_t i = 0; i < numSeqParameterSets; ++i) {
        sp<ABuffer> nal = paramSets.editItemAt(i);


        *out++ = nal->size() >> 8;
        *out++ = nal->size() & 0xff;

        memcpy(out, nal->data(), nal->size());

        out += nal->size();

        if(i == 0) {
            FindAVCDimensions(nal, width, height);
            MtkSPSInfo  spsInf;
            MTKFindAVCSPSInfo(nal->data(),nal->size(),&spsInf);
            VT_LOGD("W %d H %d P %d L %d",spsInf.width,spsInf.height,spsInf.profile,spsInf.level);
            *profile = spsInf.profile;
            *level = spsInf.level;
        }
    }

    *out++ = numPicParameterSets;

    for(size_t i = 0; i < numPicParameterSets; ++i) {
        sp<ABuffer> nal = paramSets.editItemAt(i + numSeqParameterSets);

        *out++ = nal->size() >> 8;
        *out++ = nal->size() & 0xff;

        memcpy(out, nal->data(), nal->size());

        out += nal->size();
    }

    // hexdump(csd->data(), csd->size());

    return csd;
}
uint16_t U16_AT(const uint8_t *ptr)
{
    return ptr[0] << 8 | ptr[1];
}
sp<ABuffer> parseAVCCodecSpecificData(const uint8_t *data, size_t size)
{
    const uint8_t *ptr =  data;
    sp<ABuffer> csd = new ABuffer(1024);
    static const uint8_t kNALStartCode[4] = { 0x00, 0x00, 0x00, 0x01 };

    // verify minimum size and configurationVersion == 1.
    if(size < 7 || ptr[0] != 1) {
        CHECK(0);
    }


    // There is decodable content out there that fails the following
    // assertion, let's be lenient for now...
    // CHECK((ptr[4] >> 2) == 0x3f);  // reserved

    //size_t lengthSize = 1 + (ptr[4] & 3);

    // commented out check below as H264_QVGA_500_NO_AUDIO.3gp
    // violates it...
    // CHECK((ptr[5] >> 5) == 7);  // reserved

    size_t numSeqParameterSets = ptr[5] & 31;

    ptr += 6;
    size -= 6;

    uint32_t totalSize = 0;

    for(size_t i = 0; i < numSeqParameterSets; ++i) {
        if(size < 2) {
            CHECK(0);
        }

        size_t length = U16_AT(ptr);

        ptr += 2;
        size -= 2;

        if(size < length) {
            CHECK(0);
        }


        memcpy(csd->data() +totalSize, kNALStartCode, 4);
        memcpy(csd->data() + 4 + totalSize, ptr,length);
        totalSize += length + 4;

        csd->setRange(0, totalSize);

        ptr += length;
        size -= length;
    }

    if(size < 1) {
        CHECK(0);
    }

    size_t numPictureParameterSets = *ptr;
    ++ptr;
    --size;

    for(size_t i = 0; i < numPictureParameterSets; ++i) {
        if(size < 2) {
            CHECK(0);
        }

        size_t length = U16_AT(ptr);

        ptr += 2;
        size -= 2;

        if(size < length) {
            CHECK(0);
        }

        memcpy(csd->data() +totalSize, kNALStartCode, 4);
        memcpy(csd->data() + 4 + totalSize, ptr,length);
        totalSize += length + 4;
        csd->setRange(0, totalSize);


        ptr += length;
        size -= length;
    }

    return csd;
}
void dumpFileToPath(const char* path,const sp<ABuffer> &buffer,bool appendStartCode)
{
    FILE *fp = fopen(path, "ab");
    uint8_t startCodec[4] = {0,0,0,1};

    if(fp) {
        if(appendStartCode) {
            fwrite((void *) startCodec, 1, 4, fp);
        }

        fwrite((void *) buffer->data(), 1, buffer->size(), fp);
        fclose(fp);
    }

}
void dumpRawYUVToPath(const char* path,void * data,int32_t size)
{
    FILE *fp = fopen(path, "ab");

    if(fp) {
        fwrite(data, 1,  size , fp);
        fclose(fp);
    }

}
/*
00 00 00
Profile 00 Level

Profile valid value
Profile Value
Baseline    66
Main    77
High    100

Level
10  1       (supports only QCIF format and below with 380160 samples/sec)
11  1.1    (CIF and below. 768000 samples/sec)
12  1.2    (CIF and below. 1536000 samples/sec)
13  1.3    (CIF and below. 3041280 samples/sec)
20  2       (CIF and below. 3041280 samples/sec)
21  2.1    (Supports HHR formats. Enables Interlace support. 5068800 samples/sec)
22  2.2    (Supports SD/4CIF formats. Enables Interlace support. 5184000 samples/sec)
30  3       (Supports SD/4CIF formats. Enables Interlace support. 10368000 samples/sec)
31  3.1    (Supports 720p HD format. Enables Interlace support. 27648000 samples/sec)

typedef enum OMX_VIDEO_HEVCPROFILETYPE {
    OMX_VIDEO_HEVCProfileUnknown = 0x0,
    OMX_VIDEO_HEVCProfileMain    = 0x1,
    OMX_VIDEO_HEVCProfileMain10  = 0x2,
    OMX_VIDEO_HEVCProfileMax     = 0x7FFFFFFF
} OMX_VIDEO_HEVCPROFILETYPE;


typedef enum OMX_VIDEO_HEVCLEVELTYPE {
    OMX_VIDEO_HEVCLevelUnknown    = 0x0,
    OMX_VIDEO_HEVCMainTierLevel1  = 0x1,
    OMX_VIDEO_HEVCHighTierLevel1  = 0x2,
    OMX_VIDEO_HEVCMainTierLevel2  = 0x4,
    OMX_VIDEO_HEVCHighTierLevel2  = 0x8,
    OMX_VIDEO_HEVCMainTierLevel21 = 0x10,
    OMX_VIDEO_HEVCHighTierLevel21 = 0x20,
    OMX_VIDEO_HEVCMainTierLevel3  = 0x40,
    OMX_VIDEO_HEVCHighTierLevel3  = 0x80,
    OMX_VIDEO_HEVCMainTierLevel31 = 0x100,
    OMX_VIDEO_HEVCHighTierLevel31 = 0x200,
    OMX_VIDEO_HEVCMainTierLevel4  = 0x400,
    OMX_VIDEO_HEVCHighTierLevel4  = 0x800,
    OMX_VIDEO_HEVCMainTierLevel41 = 0x1000,
    OMX_VIDEO_HEVCHighTierLevel41 = 0x2000,
    OMX_VIDEO_HEVCMainTierLevel5  = 0x4000,
    OMX_VIDEO_HEVCHighTierLevel5  = 0x8000,
    OMX_VIDEO_HEVCMainTierLevel51 = 0x10000,
    OMX_VIDEO_HEVCHighTierLevel51 = 0x20000,
    OMX_VIDEO_HEVCMainTierLevel52 = 0x40000,
    OMX_VIDEO_HEVCHighTierLevel52 = 0x80000,
    OMX_VIDEO_HEVCMainTierLevel6  = 0x100000,
    OMX_VIDEO_HEVCHighTierLevel6  = 0x200000,
    OMX_VIDEO_HEVCMainTierLevel61 = 0x400000,
    OMX_VIDEO_HEVCHighTierLevel61 = 0x800000,
    OMX_VIDEO_HEVCMainTierLevel62 = 0x1000000,
    OMX_VIDEO_HEVCHighTierLevel62 = 0x2000000,
    OMX_VIDEO_HEVCHighTiermax     = 0x7FFFFFFF
} OMX_VIDEO_HEVCLEVELTYPE;


Level   level_id    OMX_VIDEO_HEVCLEVELTYPE
1.0 30  OMX_VIDEO_HEVCMainTierLevel1
2.0 60  OMX_VIDEO_HEVCMainTierLevel2
2.1 63  OMX_VIDEO_HEVCMainTierLevel21
3   90  OMX_VIDEO_HEVCMainTierLevel3
3.1 93  OMX_VIDEO_HEVCMainTierLevel31
4.0 120 OMX_VIDEO_HEVCMainTierLevel4
4.1 123 OMX_VIDEO_HEVCMainTierLevel41
5.0 150 OMX_VIDEO_HEVCMainTierLevel5
5.1 153 OMX_VIDEO_HEVCMainTierLevel51
5.2 156 OMX_VIDEO_HEVCMainTierLevel52
6.0 180 OMX_VIDEO_HEVCMainTierLevel6
6.1 183 OMX_VIDEO_HEVCMainTierLevel61
6.2 186 OMX_VIDEO_HEVCMainTierLevel62
level_id = Level * 30
0 < level_id < 255



*/
//TODO, add HEVC related value
int32_t convertToOMXProfile(const char* mimetype,int32_t profile)
{
    bool isH264 = (!strcasecmp(mimetype, MEDIA_MIMETYPE_VIDEO_AVC));
    bool isHEVC= (!strcasecmp(mimetype, MEDIA_MIMETYPE_VIDEO_HEVC));

    if(isH264) {
        if(profile ==  66) {
            return  OMX_VIDEO_AVCProfileBaseline;
        } else if(profile == 77) {
            return  OMX_VIDEO_AVCProfileMain;
        } else if(profile == 100) {
            return  OMX_VIDEO_AVCProfileHigh;
        }
    }

    if(isHEVC) {
        if(profile ==  1) {
            return  OMX_VIDEO_HEVCProfileMain;
        } else if(profile == 2) {
            return  OMX_VIDEO_HEVCProfileMain10;
        } else if(profile == 0x7FFFFFFF) {
            return  OMX_VIDEO_HEVCProfileMax;
        }
    }

    VT_LOGE("not support profile");
    return -1;
}
int32_t convertToOMXLevel(const char* mimetype,int32_t profile,int32_t level)
{
    bool isH264 = (!strcasecmp(mimetype, MEDIA_MIMETYPE_VIDEO_AVC));
    bool isHEVC= (!strcasecmp(mimetype, MEDIA_MIMETYPE_VIDEO_HEVC));

    if(isH264) {
        if(level == 10) {
            return  OMX_VIDEO_AVCLevel1;
        } else if(level == 11) {
            return  OMX_VIDEO_AVCLevel11;
        } else if(level == 12) {
            return  OMX_VIDEO_AVCLevel12;
        } else if(level == 13) {
            return  OMX_VIDEO_AVCLevel13;
        } else if(level == 20) {
            return  OMX_VIDEO_AVCLevel2;
        } else if(level == 21) {
            return  OMX_VIDEO_AVCLevel21;
        } else if(level == 22) {
            return  OMX_VIDEO_AVCLevel22;
        } else if(level == 30) {
            return  OMX_VIDEO_AVCLevel3;
        } else if(level == 31) {
            return  OMX_VIDEO_AVCLevel31;
        } else if(level == 32) {
            return  OMX_VIDEO_AVCLevel32;
        } else if(level == 40) {
            return  OMX_VIDEO_AVCLevel4;
        } else if(level == 41) {
            return  OMX_VIDEO_AVCLevel41;
        } else if(level == 42) {
            return  OMX_VIDEO_AVCLevel42;
        } else if(level == 50) {
            return  OMX_VIDEO_AVCLevel5;
        } else if(level == 51) {
            return  OMX_VIDEO_AVCLevel51;
        } else if(level == 52) {
            return  OMX_VIDEO_AVCLevel52;
        }
    }

    int32_t OMXProfile = convertToOMXProfile(mimetype,profile);

    if(isHEVC && OMXProfile == OMX_VIDEO_HEVCProfileMain) {
        if(level == 30) {
            return  OMX_VIDEO_HEVCMainTierLevel1;
        } else if(level == 60) {
            return  OMX_VIDEO_HEVCMainTierLevel2;
        } else if(level == 63) {
            return  OMX_VIDEO_HEVCMainTierLevel21;
        } else if(level == 90) {
            return  OMX_VIDEO_HEVCMainTierLevel3;
        } else if(level == 93) {
            return  OMX_VIDEO_HEVCMainTierLevel31;
        } else if(level == 120) {
            return  OMX_VIDEO_HEVCMainTierLevel4;
        } else if(level == 123) {
            return  OMX_VIDEO_HEVCMainTierLevel41;
        } else if(level == 150) {
            return  OMX_VIDEO_HEVCMainTierLevel5;
        } else if(level == 153) {
            return  OMX_VIDEO_HEVCMainTierLevel51;
        } else if(level == 156) {
            return  OMX_VIDEO_HEVCMainTierLevel52;
        } else if(level == 180) {
            return  OMX_VIDEO_HEVCMainTierLevel6;
        } else if(level == 183) {
            return  OMX_VIDEO_HEVCMainTierLevel61;
        } else if(level == 186) {
            return  OMX_VIDEO_HEVCMainTierLevel62;
        }
    }

    VT_LOGE("not support level");
    return -1;
}
//CCW:counter-clockwise
int32_t convertToCCWRotationDegree(bool isCcw, int32_t degree)
{
    if(isCcw) return degree;

    return 360-degree;
}
//CCW:clockwise
int32_t convertToCWRotationDegree(bool isCw, int32_t degree)
{
    if(isCw) return degree;

    return 360-degree;
}

sp<ABuffer> MakeHEVCCodecSpecificData(
    const char *params, int32_t *width, int32_t *height)
{
    VT_LOGD("params: %s",params);


    AString val(params);
    Vector<sp<ABuffer> > paramSets;
    size_t numVPS = 0;
    size_t numSPS = 0;
    size_t numPPS = 0;
    size_t totalparamSetsSize = 0;

    const uint8_t VPS_NAL_TYPE = 32;
    const uint8_t SPS_NAL_TYPE = 33;
    const uint8_t PPS_NAL_TYPE = 34;
    static const uint8_t kNALStartCode[4] = { 0x00, 0x00, 0x00, 0x01 };

    VT_LOGD("val : %s",val.c_str());

    size_t start = 0;
    int loopCount = 0;

    for(;;) {
        bool parseErr = false;
        ssize_t commaPos = val.find(",", start);
        size_t end = (commaPos < 0) ? val.size() : commaPos;

        AString nalString(val, start, end - start);
        VT_LOGD("nalString : %s,start %zu",nalString.c_str(),start);

        sp<ABuffer> nal = decodeBase64(nalString);

        if(nal == NULL) {
            VT_LOGI("params error 1 @ start %zu",start);
            return NULL;
        }

        //maybe have some tuncate SPS in CMCC...
        if(loopCount++ == 0 && nal->size() < 10) {
            VT_LOGE("find SPS nal_size too little %zu",nal->size());
            return NULL;
        }

        printBinary(nal->data(), nal->size());

        sp<ABuffer> nalWoPreventionByte = ABuffer::CreateAsCopy(nal->data(),nal->size());
        RemovePreventionByte(nalWoPreventionByte->data(), nalWoPreventionByte->size());

        if(nalWoPreventionByte == NULL) {
            VT_LOGI("params error 1 @ start %zu",start);
            parseErr = true;
        }

        if(nalWoPreventionByte->size() <= 0) {
            VT_LOGE("params error 2 @ start %zu",start);
            parseErr = true;
        }

        if(nalWoPreventionByte->size() >=65535u) {
            VT_LOGE("params error 3 @ start %zu",start);
            parseErr = true;
        }

        if(parseErr) {
            if(numVPS == 0 &&  numSPS == 0 &&  numVPS == 0) {
                VT_LOGE("can not find any valid vps/sps/pps, return NULL");
                return NULL;
            } else if(numSPS == 0 &&  numVPS == 0) {
                VT_LOGE("can not find any valid /sps/pps, return NULL");
                return NULL;
            } else {
                VT_LOGE("find %zu numVPS, %zu numSPS,, %zu numVPS",numVPS,numSPS,numVPS);
                break;
            }
        }

        printBinary(nalWoPreventionByte->data(), nalWoPreventionByte->size());
        uint8_t nalType = (nalWoPreventionByte->data() [0] >> 1) & 0x3f;
        VT_LOGD("nalType= %d",nalType);

        if(nalType == VPS_NAL_TYPE) {
            numVPS++;
        } else if(nalType == SPS_NAL_TYPE) {
            numSPS++;
        } else if(nalType == PPS_NAL_TYPE) {
            numPPS++;
        }

        paramSets.push(nal);
        totalparamSetsSize += nal->size();

        if(nalType == SPS_NAL_TYPE) {
            FindHEVCWH(nalWoPreventionByte, width, height);
        }

        if(commaPos < 0) {
            break;
        }

        start = commaPos + 1;
    }

    sp<ABuffer> accessUnit = new ABuffer(totalparamSetsSize + paramSets.size() *4);
    uint32_t shiftSize = 0;

    for(size_t i = 0; i < paramSets.size(); i++) {
        sp<ABuffer> tmpNal = paramSets.editItemAt(i);

        memcpy(accessUnit->data() +shiftSize , kNALStartCode,4);
        memcpy(accessUnit->data() +shiftSize+4 , tmpNal->data(),tmpNal->size());
        shiftSize += tmpNal->size() +4;
    }

    CHECK(shiftSize == (totalparamSetsSize + 4*paramSets.size()));

    //now we can direct return the accessUnit
    ALOGI("found HEVC codec config W %d H%d",*width, *height);
    printBinary(accessUnit->data(), accessUnit->size());
    return accessUnit;




    //extract all NAL info
    /*
    const uint8_t *data = accessUnit->data();
    size_t size = accessUnit->size();
    size_t numOfParamSets = 0;

    // find vps,only choose the first vps,
    // need check whether need sent all the vps to decoder
    sp<ABuffer> videoParamSet = FindHEVCNAL(data, size, VPS_NAL_TYPE, NULL);
    if (videoParamSet == NULL) {
        ALOGW("no vps found !!!");
        // return NULL;
    } else {
        numOfParamSets++;
        ALOGI("find vps, size =%zu", videoParamSet->size());
    }

    // find sps,only choose the first sps,
    // need check whether need sent all the sps to decoder
    sp<ABuffer> seqParamSet = FindHEVCNAL(data, size, SPS_NAL_TYPE, NULL);
    if (seqParamSet == NULL) {
        ALOGW("no sps found !!!");
        return NULL;
    } else {
        numOfParamSets++;
        ALOGI("find sps, size =%zu", seqParamSet->size());
    }


    //int32_t width, height;
    FindHEVCDimensions(seqParamSet, &width, &height);

    // find pps,only choose the first pps,
    // need check whether need sent all the pps to decoder
    size_t stopOffset;
    sp<ABuffer> picParamSet = FindHEVCNAL(data, size, PPS_NAL_TYPE, &stopOffset);
    if (picParamSet == NULL) {
        ALOGW("no sps found !!!");
        return NULL;
    } else {
        numOfParamSets++;
        ALOGI("find pps, size =%zu", picParamSet->size());
    }

    int32_t numbOfArrays = numOfParamSets;
    int32_t paramSetSize = 0;

    // only save one vps,sps,pps in codecConfig data
    if (videoParamSet != NULL) {
        paramSetSize += 1 + 2 + 2 + videoParamSet->size();
    }
    if (seqParamSet != NULL) {
        paramSetSize += 1 + 2 + 2 + seqParamSet->size();
    }
    if (picParamSet != NULL) {
        paramSetSize += 1 + 2 + 2 + picParamSet->size();
    }
    size_t csdSize =
        1 + 1 + 4 + 6 + 1 + 2 + 1 + 1 + 1 + 1 + 2 + 1
        + 1 + paramSetSize;
    ALOGI("MakeHEVCCodecSpecificData codec config data size =%zu", csdSize);
    sp<ABuffer> csd = new ABuffer(csdSize);
    uint8_t *out = csd->data();

    *out++ = 0x01;  // configurationVersion

    //opy profile_tier_leve info in sps, containing
     // 1 byte:general_profile_space(2),general_tier_flag(1),general_profile_idc(5)
    //  4 bytes: general_profile_compatibility_flags, 6 bytes: general_constraint_indicator_flags
    //  1 byte:general_level_idc

    memcpy(out, seqParamSet->data() + 3, 1 + 4 + 6 + 1);

    uint8_t profile = out[0] & 0x1f;
    uint8_t level = out[11];


    out += 1 + 4 + 6 + 1;

    *out++ = 0xf0;  // reserved(1111b) + min_spatial_segmentation_idc(4)
    *out++ = 0x00;  // min_spatial_segmentation_idc(8)
    *out++ = 0xfc;  // reserved(6bits,111111b) + parallelismType(2)(0=unknow,1=slices,2=tiles,3=WPP)
    *out++ = 0xfd;  // reserved(6bits,111111b)+chromaFormat(2)(0=monochrome, 1=4:2:0, 2=4:2:2, 3=4:4:4)

    *out++ = 0xf8;  // reserved(5bits,11111b) + bitDepthLumaMinus8(3)
    *out++ = 0xf8;  // reserved(5bits,11111b) + bitDepthChromaMinus8(3)

    uint16_t avgFrameRate = 0;
    // avgFrameRate (16bits,in units of frames/256 seconds,0 indicates an unspecified average frame rate)
    *out++ = avgFrameRate >> 8;
    *out++ = avgFrameRate & 0xff;

    // constantFrameRate(2bits,0=not be of constant frame rate),numTemporalLayers(3bits),temporalIdNested(1bits),
    *out++ = 0x03;
    // lengthSizeMinusOne(2bits)

    *out++ = numbOfArrays;  // numOfArrays

    if (videoParamSet != NULL) {
        *out++ = 0x3f & VPS_NAL_TYPE;  // array_completeness(1bit)+reserved(1bit,0)+NAL_unit_type(6bits)

        // num of vps
        uint16_t numNalus = 1;
        *out++ = numNalus >> 8;
        *out++ =  numNalus & 0xff;

        // vps nal length
        *out++ = videoParamSet->size() >> 8;
        *out++ = videoParamSet->size() & 0xff;

        memcpy(out, videoParamSet->data(), videoParamSet->size());
        out += videoParamSet->size();
    }

    if (seqParamSet != NULL) {
        *out++ = 0x3f & SPS_NAL_TYPE;  // array_completeness(1bit)+reserved(1bit,0)+NAL_unit_type(6bits)

        // num of sps
        uint16_t numNalus = 1;
        *out++ = numNalus >> 8;
        *out++ = numNalus & 0xff;

        // sps nal length
        *out++ = seqParamSet->size() >> 8;
        *out++ = seqParamSet->size() & 0xff;

            memcpy(out, seqParamSet->data(), seqParamSet->size());
            out += seqParamSet->size();
        }
        if (picParamSet != NULL) {
            *out++ = 0x3f & PPS_NAL_TYPE;  // array_completeness(1bit)+reserved(1bit,0)+NAL_unit_type(6bits)

            // num of pps
            uint16_t numNalus = 1;
            *out++ = numNalus >> 8;
            *out++ = numNalus & 0xff;

            // pps nal length
            *out++ = picParamSet->size() >> 8;
            *out++ = picParamSet->size() & 0xff;

            memcpy(out, picParamSet->data(), picParamSet->size());
            // no need add out offset
        }


        ALOGI("found HEVC codec config W %d H%d,  profile%d  level %d",
                width, height, profile, level);

        return csd; */
}

void FindHEVCWH(const sp<ABuffer> &seqParamSet, int32_t *width, int32_t *height)
{
    ALOGI("FindHEVCWH ++");
    ABitReader br(seqParamSet->data() + 2, seqParamSet->size() - 1);

    br.skipBits(4);    // sps_video_parameter_set_id;
    unsigned sps_max_sub_layers_minus1 = br.getBits(3);
    ALOGI("sps_max_sub_layers_minus1 =%d", sps_max_sub_layers_minus1);
    br.skipBits(1);    // sps_temporal_id_nesting_flag;

    /*-----------profile_tier_level start-----------------------*/

    br.skipBits(3);    // general_profile_spac, general_tier_flag

    unsigned general_profile_idc = br.getBits(5);
    ALOGI("general_profile_idc =%d", general_profile_idc);
    br.skipBits(32);    // general_profile_compatibility_flag

    br.skipBits(48);    // general_constraint_indicator_flags

    unsigned general_level_idc = br.getBits(8);
    ALOGI("general_level_idc =%d", general_level_idc);

    uint8_t sub_layer_profile_present_flag[sps_max_sub_layers_minus1];
    uint8_t sub_layer_level_present_flag[sps_max_sub_layers_minus1];

    for(int i = 0; (unsigned) i < sps_max_sub_layers_minus1; i++) {
        sub_layer_profile_present_flag[i] = br.getBits(1);
        sub_layer_level_present_flag[i] = br.getBits(1);
    }

    if(sps_max_sub_layers_minus1 > 0) {
        for(int j = sps_max_sub_layers_minus1; j < 8; j++) {
            br.skipBits(2);
        }
    }

    for(int i = 0; (unsigned) i < sps_max_sub_layers_minus1; i++) {
        if(sub_layer_profile_present_flag[i]) {
            br.skipBits(2);    // sub_layer_profile_space
            br.skipBits(1);    // sub_layer_tier_flag
            br.skipBits(5);    // sub_layer_profile_idc
            br.skipBits(32);    // sub_layer_profile_compatibility_flag
            br.skipBits(48);    // sub_layer_constraint_indicator_flags
        }

        if(sub_layer_level_present_flag[i]) {
            br.skipBits(8);    // sub_layer_level_idc
        }
    }

    /*-----------profile_tier_level done-----------------------*/

    parseUE(&br);    // sps_seq_parameter_set_id
    unsigned chroma_format_idc, separate_colour_plane_flag;
    chroma_format_idc = parseUE(&br);
    ALOGI("chroma_format_idc=%d", chroma_format_idc);

    if(chroma_format_idc == 3) {
        separate_colour_plane_flag = br.getBits(1);
    }

    int32_t pic_width_in_luma_samples = parseUE(&br);
    int32_t pic_height_in_luma_samples = parseUE(&br);
    ALOGI("pic_width_in_luma_samples =%d", pic_width_in_luma_samples);
    ALOGI("pic_height_in_luma_samples =%d", pic_height_in_luma_samples);

    *width = pic_width_in_luma_samples;
    *height = pic_height_in_luma_samples;
    uint8_t conformance_window_flag = br.getBits(1);
    ALOGI("conformance_window_flag =%d", conformance_window_flag);

    if(conformance_window_flag) {
        unsigned conf_win_left_offset = parseUE(&br);
        unsigned conf_win_right_offset = parseUE(&br);
        unsigned conf_win_top_offset = parseUE(&br);
        unsigned conf_win_bottom_offset = parseUE(&br);

        *width -= conf_win_left_offset + conf_win_right_offset* 2;
        *height -= conf_win_top_offset + conf_win_bottom_offset* 2;

        ALOGI("frame_crop = (%u, %u, %u, %u)",
              conf_win_left_offset, conf_win_right_offset,
              conf_win_top_offset, conf_win_bottom_offset);
    }

    unsigned bit_depth_luma_minus8 = parseUE(&br);
    unsigned bit_depth_chroma_minus8 = parseUE(&br);
    ALOGI("bit_depth_luma_minus8 =%u, bit_depth_chroma_minus8 =%u", bit_depth_luma_minus8, bit_depth_chroma_minus8);
    ALOGI("FindHEVCWH --");
}

}
