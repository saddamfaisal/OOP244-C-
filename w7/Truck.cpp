#include "MotorVehicle.h"
#include "Truck.h"
#include<iostream>
#include <iomanip>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

namespace sdds
{


   Truck::Truck(char licNum[], int year, double capacity, const char* currAddress) : MotorVehicle(licNum, year)
   {
      this->maxWeight = capacity;
      this->currentWeight = 0;
      MotorVehicle::moveTo(currAddress);

   }



   bool Truck::addCargo(double cargo)
   {
      if (this->currentWeight != this->maxWeight)
      {
         this->currentWeight =
            this->currentWeight + cargo <= this->maxWeight ?
            this->currentWeight + cargo : this->maxWeight;
         return true;
      }
      return false;
   }



   bool Truck::unloadCargo()
   {
      if (this->currentWeight != 0)
      {
         this->currentWeight = 0;
         return true;
      }

      return false; 
   }

   ostream& Truck::write(ostream& os)
   {
      MotorVehicle::write(os);
      cout << " | " << currentWeight << "/" << this->maxWeight;
      return os;
   }


   istream& Truck::read(istream& in)
   {
      MotorVehicle::read(in);//calling base class
      cout << "Capacity: ";
      in >> this->maxWeight;
      cout << "Cargo: ";
      in >> this->currentWeight;
      return in;
   }


   ostream& operator<<(ostream& os, Truck tr)
   {
      tr.write(os);
      return os;
   }


   istream& operator>>(istream& is, Truck& tr)
   {
      tr.read(is);
      return is;
   }

   Truck::~Truck() {}



}