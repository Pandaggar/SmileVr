#include "MechaTankle.h"
#include "network/network.h"
#include "utils.h"
#include "GlobalVars.h"

void MechaTankle::motionSetup(){
#ifdef DEBUG_SENSOR
    imu.initialize(addr);
#endif
    m_Logger.info("Connected to MechaT");
    working = true;
    configured = true;
}

void MechaTankle::motionLoop()
{
hadData = true;
    
    
    Quat quat = imu.getQuat(1);
    quaternion.set(quat.x, quat.y, quat.z, quat.w);
    quaternion *= sensorOffset;

            if (!OPTIMIZE_UPDATES || !lastQuatSent.equalsWithEpsilon(quaternion))
            {
                newData = true;
                lastQuatSent = quaternion;
            }
}



void MechaTankle::startCalibration(int calibrationType){

}