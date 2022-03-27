
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           14/07/2020
#define _CRT_SECURE_NO_WARNINGS
#ifndef MOTORVEHICLE_H_
#define MOTORVEHICLE_H_
#include <iostream>
#include <string.h>


namespace sdds

 {
   
   const int sz = 32;

   class MotorVehicle
   {
   private:
      char license[sz];
      char address[64];
      int year;
   public:
      MotorVehicle(char licNum[], int year);
      void moveTo(const char* address);
      std::ostream& write(std::ostream& ost);
      std::istream& read(std::istream& st);
      friend ostream& operator<<(ostream& os, MotorVehicle mv); // old: friend ostream&

      friend istream& operator>>(istream& os, MotorVehicle& ml);
      virtual ~MotorVehicle();

   };

}

 #endif


  

 
 
    



