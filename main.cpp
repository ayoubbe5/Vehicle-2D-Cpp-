#include <iostream>
#include <string>
#include"vehicle.h"
#include"statemachine.h"

using namespace std;


int main()
{
    fahrzeug *my_ptr = new fahrzeug;


      int tmp_m;
      int temp_kra;
      cout << "Geben sie bitte die masse "<< endl ;
      cin>>tmp_m;
      cout <<"Geben sie bitte die Motor_Kraft "<< endl;
      cin>>temp_kra;

     my_ptr->initVehicle(1,tmp_m,temp_kra,500);
      my_ptr->getVehicleString();
    my_ptr->engineAccel();
      my_ptr->simulatePhysics();
      my_ptr->getVehicleString();
     my_ptr->engineNeutral();
      my_ptr->simulatePhysics();
      my_ptr->getVehicleString();
      sm1.help();
      while (true){


          char driverIN;
          cout << "\nIhre Eingabe: ";
          cin >> driverIN;
          sm1.processEvent(driverIN);
          cout << sm1.getStateString()<< endl;
          my_ptr->simulatePhysics();
          cout <<my_ptr->getVehicleString()<< endl ;

      }
      return 0;

    return 0;
}
