#ifndef TRUCK_H_
#define TRUCK_H_
#include "MotorVehicle.h"
#include <iostream>
#include <string.h>
using namespace std;

namespace sdds
{
   class Truck : public MotorVehicle
   {
   private:
      double maxWeight;
      double currentWeight;

   public:
      Truck(char licPlateNo[], int year, double capacity, const char* currAddress);
      bool addCargo(double cargo);
      bool unloadCargo();
      using MotorVehicle::write; // super class function
      using MotorVehicle::read; // super class function
      ostream& write(ostream& os);
      istream& read(istream& in);
      friend ostream& operator<<(ostream& os, Truck tr);
      friend istream& operator>>(istream& is, Truck& tr);
      virtual ~Truck();

   };

}

#endif