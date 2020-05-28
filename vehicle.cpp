#include"vehicle.h"
#include <iostream>
#include <string>
#include<complex>

using namespace std;

void engineAccel();
void engineNeutral();
void simulatePhysics();
void initVehicle(double s_in, double mass_in ,double F_max_in , double dt);
string getVehicleString();

fahrzeug fahrzeug1;


void fahrzeug::simulatePhysics(void){
    double v_mittel;
    fahrzeug1.a =fahrzeug1.F_akt / fahrzeug1.mass;
    v_mittel = fahrzeug1.v+(fahrzeug1.a/fahrzeug1.dt)/2;
    fahrzeug1.v+=fahrzeug1.a/fahrzeug1.dt;
    fahrzeug1.s+=v_mittel/fahrzeug1.dt;
    fahrzeug1.F_akt = 0;
}

void fahrzeug::engineDeccel(void){
    fahrzeug1.F_akt=-fahrzeug1.F_max;
     cout <<" Effekt:  " << fahrzeug1.F_akt<<endl;
}


void fahrzeug::engineAccel(void){
    fahrzeug1.F_akt= fahrzeug1.F_max;
    cout <<" Effekt:  " << fahrzeug1.F_akt<<endl;
                      }
void fahrzeug::engineNeutral(void){
    fahrzeug1.F_akt= 0;
    cout << "Effekt: F_akt = 0  " << endl;
                        }

string fahrzeug::getVehicleString(void){
    string str;
    str="Fahrzeugdaten sind :\n"
    "\n Die Position des Fahrzeugs ist : " + to_string(fahrzeug1.s) + "m"
     "\n Die Geschwindigkeit des Fahrzeugs ist: " + to_string(fahrzeug1.v) + "v/s"
            "\n Die Beschleunigung des Fahrzeugs ist : " + to_string(fahrzeug1.a) + "m/s1^2";
    return str;
}
void fahrzeug::initVehicle(double s_in, double mass_in ,double F_max_in , double dt){
fahrzeug1.s=s_in;
fahrzeug1.mass= mass_in;
fahrzeug1.F_max=F_max_in;
fahrzeug1.dt=dt;
}
