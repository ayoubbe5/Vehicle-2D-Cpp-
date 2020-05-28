#include <iostream>
#include <string>
#include"vehicle.h"
#include"statemachine.h"




using namespace std;
int countercpp;

statemachine sm1 ;

void statemachine::processEvent(char driverInput) {
    switch (state)
    {
    case OFF:
        if (driverInput == 'b') {
            state = NEUTRAL;
        }
        break;
    case NEUTRAL:
        if (driverInput == 'e') {
            state = OFF;
            my_ptr->engineNeutral();
        }
        if (driverInput == 'a') {
            state = ACCEL;
            my_ptr->engineAccel();
        }
        if (driverInput == 'd') {
            state = DECEL;
            my_ptr->engineDeccel();
        }
        break;
    case ACCEL:
            my_ptr->engineAccel();
        if (driverInput == 'e') {
            state = OFF;
        }
        if (driverInput == 'n') {
            state = NEUTRAL;
            my_ptr->engineNeutral();
        }
        if (driverInput == 'd') {
            cout << "Verboten";
        }

        break
        ;
    case BREMS :
     if (driverInput =='z'){
         state=BREMS;
         countercpp=countercpp+1;
            if (countercpp==2)
                state=DECEL;
     }
     /*else if (driverInput=='x') {
         for(int i = 0; i<=4;i++){
             countercpp++;
             if (countercpp==4){
                 state=ACCEL;
                 break;
             }
         }
      }*/



    case DECEL:
        if (driverInput == 'e') {
            state = OFF;
        }
        if (driverInput == 'n') {
            state = NEUTRAL;
            my_ptr->engineNeutral();
        }
        if (driverInput=='z'){
           state= BREMS;
        }
        if (driverInput == 'a') {
            cout << "Verboten" << endl;
        }

        break;

    }

}

string  statemachine:: getStateString(void) {
    switch (state)
    {
    case OFF:
        return  " OFF_State" ;
        break;
    case NEUTRAL:
        return " NEUTRAL_State" ;
        break;
    case ACCEL:
        return " ACCEL_State";
        break;
    case DECEL:
        return " DECEL_State" ;
        break;
    case BREMS:
        return "Brems_State";
    }
    return 0;
}

void statemachine:: help (void){
    cout << "Das Fahrzeug befindet sich im Zustand OFF;"<< endl<< endl ;
    cout << "drucken sie bitte 'b' um Neutral_Mode zu beginnen"<< endl;
    cout << "drucken sie bitte 'a'um Accel_Mode zu beginnen "<< endl;
    cout << "drucken sie bitte 'd' um Decel_Mode zu Beginnen "<< endl;
    cout << "\nUm Off(ende) zu bringen 'e' drucken (Immer gultig)"<< endl;
    cout << "\nDas wechsel zwischen Accel und Decel ist verboten"  << endl;

}


/*int main()
{
    help();
    while (true){


        char driverIN;
        cout << "\nIhre Eingabe: ";
        cin >> driverIN;
        processEvent(driverIN);
        cout << getStateString()<< endl;

    }
    return 0;
}*/
