#include <vector3.h>
#include <quat.h>
#include <math.h>
#include <arduino.h>


#define Rad(deg) (deg*M_PI/180.0)

class MechaLib{
    public:
    Quat getQuat(int16_t k);//knee = 0, hip = 1
    private:
    void EtoQ(double ze,double ye,double xe, double* x, double* y, double* z, double* w);
};


class HVec{
  private:
    float floatmap(float x, float in_min, float in_max, float out_min, float out_max);
  public:
    void HipVec(double L1,double L2,double A,double B, double L, double M, double K, double* vx, double* vy, double* vz);
    void PTMRead(double P1,double* A1,double map);
};

class Nerot{
    public:
    double ABV(double x, double y, double z, double w);
    double QuadXY(double x, double y);
    double ABVS(double x,double y,double z,double w);
    double AngleXY(double x, double y);
};

