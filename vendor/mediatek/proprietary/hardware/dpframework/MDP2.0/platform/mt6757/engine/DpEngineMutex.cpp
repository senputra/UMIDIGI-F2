#include "DpEngineMutex.h"
#include "DpEngineType.h"
#include "DpPathBase.h"
#include "DpCommand.h"
#include "mmsys_mutex.h"

DpEngineMutex::DpEngineMutex(DpPathBase *path)
    : m_pPath(path),
      m_mutexID(-1),
      m_mutexMod(0)
{
    int32_t index;
    for (index = 0; index < ISP_MAX_OUTPUT_PORT_NUM; index++)
    {
        m_engineSOF[index] = -1;
    }
}


DpEngineMutex::~DpEngineMutex()
{
}


bool DpEngineMutex::require(DpCommand &command)
{
    DpPathBase::iterator iterator;
    DpEngineType         curType;
    uint32_t             mutexSOF;
    uint32_t             countSOF = 0;
    int32_t              index;

    // Default value
    m_mutexID = -1;
    m_mutexMod = 0;
    mutexSOF  = 0;
    for (index = 0; index < ISP_MAX_OUTPUT_PORT_NUM; index++)
    {
        m_engineSOF[index] = -1;
    }

    for (iterator = m_pPath->begin(); iterator != m_pPath->end(); iterator++)
    {
        if (true == iterator->isOutputDisable())
        {
            continue;
        }

        curType = iterator->getEngineType();
        switch(curType)
        {
        /**********************************************
         * Name            MSB LSB
         * DISP_MUTEX_MOD   23   0
         *
         * Specifies which modules are in this mutex.
         * Every bit denotes a module. Bit definition:
         *  3 mdp_rdma0
         *  4 mdp_rdma1
         *  - mdp_rsz0
         *  6 mdp_rsz1
         *  7 mdp_rsz2
         *  8 mdp_tdshp
         *  9 mdp_color
         *  - mdp_wdma
         *  11 mdp_wrot0
         *  12 mdp_wrot1
         **********************************************/
        case tWROT1:
            m_engineSOF[countSOF] = tWROT1;
            m_mutexMod |= 1 << 12;
            countSOF++;
            break;
        case tWROT0:
            m_engineSOF[countSOF] = tWROT0;
            m_mutexMod |= 1 << 11;
            countSOF++;
            break;
        case tCOLOR0:
            m_mutexMod |= 1 << 9;
            break;
        case tTDSHP0:
            m_mutexMod |= 1 << 8;
            break;
        case tSCL2:
            m_mutexMod |= 1 << 7;
            break;
        case tSCL1:
            m_mutexMod |= 1 << 6;
            break;
        case tRDMA1:
            m_mutexMod |= 1 << 4;
            m_mutexID = DISP_MUTEX_MDP_FIRST + 2;
            break;
        case tRDMA0:
            m_mutexMod |= 1 << 3;
            m_mutexID = DISP_MUTEX_MDP_FIRST + 1;
            break;
        case tIMGI:
            m_mutexID = DISP_MUTEX_MDP_FIRST;
            break;
        case tVENC:
            DPLOGI("tVENC trying to get mutex\n");
            break;
        default:
            break;
        }
    }

    if (m_mutexID == -1)
    {
        DPLOGE("no mutex assigned...\n");
        return false;
    }

    if (m_mutexMod != 0)
    {
        // Set mutex modules
        DPLOGI("DpEngineMutex: MM_MUTEX_GET %p\n", MM_MUTEX_GET);

        MM_REG_WRITE(command, MM_MUTEX_GET, 0x01, 0x00000001);
        MM_REG_POLL( command, MM_MUTEX_GET, 0x02, 0x00000002);

        DPLOGI("DpEngineMutex: MM_MUTEX_MOD 0x%08x = 0x%08x\n", MM_MUTEX_MOD, m_mutexMod);
        DPLOGI("DpEngineMutex: MM_MUTEX_SOF 0x%08x = 0x%08x\n", MM_MUTEX_SOF, mutexSOF);

        MM_REG_WRITE(command, MM_MUTEX_MOD, m_mutexMod, 0x07FFFFFF);
        MM_REG_WRITE(command, MM_MUTEX_SOF, mutexSOF, 0x00000007);

        MM_REG_WRITE(command, MM_MUTEX_GET, 0x00, 0x00000001);
        MM_REG_POLL( command, MM_MUTEX_GET, 0x00, 0x00000002);
    }

    return true;
}


bool DpEngineMutex::release(DpCommand &command)
{
    if (-1 == m_mutexID)
    {
        DPLOGE("DpEngineMutex: incorrect mutex id\n");
        assert(0);
        return false;
    }

    if (0 != m_mutexMod)
    {
        int32_t index;
        DPLOGI("DpEngineMutex: release mutex token %d\n", m_mutexID);

        // Wait WROT SRAM shared to DISP RDMA
        for (index = 0; index < ISP_MAX_OUTPUT_PORT_NUM; index++)
        {
            switch(m_engineSOF[index])
            {
                case tWROT0:
                    MM_REG_WAIT_NO_CLEAR(command, DpCommand::SYNC_WROT0_SRAM_READY);
                    break;
                case tWROT1:
                    MM_REG_WAIT_NO_CLEAR(command, DpCommand::SYNC_WROT1_SRAM_READY);
                    break;
                default:
                    break;
            }
        }


        MM_REG_WRITE(command, MM_MUTEX_GET, 0x01, 0x00000001);
        MM_REG_POLL( command, MM_MUTEX_GET, 0x02, 0x00000002);

        // Enable the mutex
        MM_REG_WRITE(command, MM_MUTEX_EN, 0x1, 0x00000001);

        MM_REG_WRITE(command, MM_MUTEX_GET, 0x00, 0x00000001);
        MM_REG_POLL( command, MM_MUTEX_GET, 0x00, 0x00000002);

        // Wait mutex done and clear the module list
        if (m_engineSOF[0] != -1)
        {
            if (m_engineSOF[0] == tWROT0)
            {
                MM_REG_WAIT(command, DpCommand::WROT0_FRAME_START);
            }
            else if (m_engineSOF[0] == tWROT1)
            {
                MM_REG_WAIT(command, DpCommand::WROT1_FRAME_START);
            }
            else
            {
                MM_REG_WAIT(command, DpCommand::WDMA_FRAME_START);
            }
        }
        else
        {
            MM_REG_POLL(command, MM_MUTEX_EN, 0x0, 0x00000001);
        }


        MM_REG_WRITE(command, MM_MUTEX_GET, 0x01, 0x00000001);
        MM_REG_POLL( command, MM_MUTEX_GET, 0x02, 0x00000002);

        MM_REG_WRITE(command, MM_MUTEX_MOD, 0x0, 0x07FFFFFF);

        MM_REG_WRITE(command, MM_MUTEX_GET, 0x00, 0x00000001);
        MM_REG_POLL( command, MM_MUTEX_GET, 0x00, 0x00000002);

        DPLOGI("DpEngineMutex: disable mutex %d begin\n", m_mutexID);
    }

    return true;
}
