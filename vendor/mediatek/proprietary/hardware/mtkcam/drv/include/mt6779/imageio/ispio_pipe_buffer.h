/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#ifndef _ISPIO_PIPE_BUFFER_H_
#define _ISPIO_PIPE_BUFFER_H_
//
#include "ispio_stddef.h"
#include <sys/time.h>
#include <vector>
using namespace std;
/*******************************************************************************
*
********************************************************************************/
namespace NSImageio {
namespace NSIspio   {
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
* Pipe Buffer Info
********************************************************************************/
struct QBufInfo
{
public: ////    fields.
    /*
     * user-specific data. Cannot be modified by pipes.
     */
    MUINT32             u4User;
    /*
     * reserved data. Cannot be modified by pipes.
     */
    MUINT32             u4Reserved;
    //
    MUINT32             u4BufIndex;
    //
    MUINT32             u4SensorId;
    /*
     * vector of buffer information.
     * Note:
     *      The vector size depends on the image format. For example, the vector
     *      must contain 3 buffer information for yuv420 3-plane.
     */
    vector<BufInfo>     vBufInfo;
    //
public:     //// constructors.
    QBufInfo(MUINT32 const _u4User = 0)
        : u4User(_u4User)
        , u4Reserved(0)
        , u4BufIndex(0)
        , u4SensorId(5)  // default: use max sensor number, sensor id must be less than 5
        , vBufInfo()
    {
    }
    //
};


/*******************************************************************************
* Pipe Buffer Info with Timestamp
********************************************************************************/
struct QTimeStampBufInfo : public QBufInfo
{
public: ////    fields.
    //
    MUINT32             u4BufIndex; //buffer index
    //
public:     //// constructors.
    QTimeStampBufInfo(MUINT32 const _u4User = 0)
        : QBufInfo(_u4User)
        , u4BufIndex(0)
    {
    }
};

//
//
struct MemInfo {
    MUINTPTR virtAddr;
    MUINTPTR phyAddr;
    MUINT32 bufCnt;
    MUINT32 bufSize;
    //
    MemInfo(MUINTPTR const _virtAddr = 0,
              MUINTPTR const _phyAddr = 0,
              MUINT32 const _bufCnt = 0,
              MUINT32 const _bufSize = 0
             )
              : virtAddr(_virtAddr), phyAddr(_phyAddr),
                bufCnt(_bufCnt), bufSize(_bufSize)
    {}
};


////////////////////////////////////////////////////////////////////////////////
};  //namespace NSIspio
};  //namespace NSImageio
#endif  //  _ISPIO_PIPE_BUFFER_H_

