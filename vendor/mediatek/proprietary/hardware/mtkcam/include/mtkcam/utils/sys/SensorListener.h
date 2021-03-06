#ifndef _MTK_HARDWARE_MTKCAM_INCLUDE_MTKCAM_UTILS_SYS_SENSORLISTENER_H_
#define _MTK_HARDWARE_MTKCAM_INCLUDE_MTKCAM_UTILS_SYS_SENSORLISTENER_H_
//-----------------------------------------------------------------------------
class SensorListener
{
    protected:
        virtual ~SensorListener() {};
    //
    public:
        typedef enum
        {
            SensorType_Acc,
            SensorType_Mag,
            SensorType_Gyro,
            SensorType_Light,
            SensorType_Proxi
        }SensorTypeEnum;
        //
        typedef void (*Listener) ();
        //
//        static SensorListener*  createInstance(void);
        static SensorListener*  createInstance(const char* Caller = "unknown");
        virtual MVOID   destroyInstance(void) = 0;
        virtual MBOOL   setListener(Listener func) = 0;
        virtual MBOOL   enableSensor(
                            SensorTypeEnum  sensorType,
                            MUINT32         periodInMs) = 0;
        virtual MBOOL   disableSensor(SensorTypeEnum sensorType) = 0;
};
//-----------------------------------------------------------------------------
#endif

