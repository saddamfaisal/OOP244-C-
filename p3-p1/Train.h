////I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
 //Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           10/6/2020

#pragma once
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

#include <iostream>
#include <cstring> 
#include "Cargo.h"


 namespace sdds 

{
   const  int MAX_NAME = 30;
   class Train {


      char name[MAX_NAME + 1];
      int id = 0;
      Cargo* cargo;

   public:
         
      void initialize(const char* name, int id);
      bool isValid() const;
      void loadCargo(Cargo car);
      void unloadCargo();
      void display() const;
   };
}
#endif