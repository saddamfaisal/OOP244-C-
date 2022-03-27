#include<iostream>
#include <iomanip>
#include "MotorVehicle.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds {

   MotorVehicle::MotorVehicle(char licNum[], int year)
   {
      strcpy(this->license, licNum);
      this->year = year;
      strcpy(this->address, "Factory");
   }

   void MotorVehicle::moveTo(const char* address)
   {
      if (strcmp(this->address, address) != 0)
      {
         cout << " | " << license << " | " << " | " << setw(20) << this->address << "--->---" << address << " | " << endl;
         strcpy(this->address, address);
      }
   }




   std::ostream& MotorVehicle::write(std::ostream& ost)
   {
      ost << "| " << this->year << " | " << license << " | " << address;
      return ost;
   }


   std::istream& MotorVehicle::read(std::istream& st)
   {
      cout << "Built year: ";
      st >> this->year;
      cout << "License plate: ";
      st >> this->license;
      cout << "Current location: ";
      st >> this->address;
      return st;
   }


   ostream& operator<<(ostream& os, MotorVehicle mv) { 
      mv.write(os);
      return os;
   }
   istream& operator>>(istream& is, MotorVehicle& ml) {
      ml.read(is);
      return is;
   }

   MotorVehicle::~MotorVehicle() {}


}