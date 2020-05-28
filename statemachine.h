#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include<string>
#include"vehicle.h"

enum  Zustand {OFF,NEUTRAL,ACCEL,DECEL,BREMS};

class statemachine {
 public:
    fahrzeug *my_ptr;
void help (void);
std::string getStateString(void);
void processEvent(char driverInput);
Zustand state=OFF ;
};

extern statemachine sm1 ;
#endif // STATEMACHINE_H
