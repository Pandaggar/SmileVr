#ifndef SENSORS_MECHATSENSOR_H
#define SENSORS_MECHATSENSOR_H

#include "sensor.h"
#include "MechaT_Lib.h"


class MechaTknee : public Sensor
{
public:
    MechaTknee(uint8_t id, uint8_t address, float rotation) : Sensor("MechaTknee", IMU_MechaTknee, id, address, rotation){};
    ~MechaTknee()override = default;
    void motionSetup() override final;
    void motionLoop() override final;
    void sendData() override final;
    void startCalibration(int calibrationType) override final;
private:
    MechaLib imu{};
};

#endif