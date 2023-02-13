#ifndef SENSORS_MECHATSENSOR_H
#define SENSORS_MECHATSENSOR_H

#include "sensor.h"
#include "MechaT_Lib.h"


class MechaTankle : public Sensor
{
public:
    MechaTankle(uint8_t id, uint8_t address, float rotation) : Sensor("MechaTankle", IMU_MechaTankle, id, address, rotation){};
    ~MechaTankle(){};
    void motionSetup() override final;
    void motionLoop() override final;
    void startCalibration(int calibrationType) override final;

private:
    MechaLib imu{};
};

#endif