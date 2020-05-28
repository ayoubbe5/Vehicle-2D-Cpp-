#ifndef VEHICLE_H
#define VEHICLE_H
#include<string>
#include<complex>

class fahrzeug{
public:
    double s,v,a;
    double mass;
    double F_max, F_akt;
    double dt;
    void engineAccel();
    void engineNeutral();
    void simulatePhysics();
    void engineDeccel(void);
    void initVehicle( double s_in=0, double mass_in = 1000, double F_max_in = 500, double dt =1);
    std::string getVehicleString();
};
extern fahrzeug fahrzeug1;
#endif // VEHICLE_H
