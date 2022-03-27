#pragma once

//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           10/6/2020

#pragma once

#include <iostream>
#include <cstring> 

#ifndef SDDS_CARGO_H
#define SDDS_CARGO_H


namespace sdds {

   const int MAX_DESC = 20;
   const double MAX_WEIGHT = 777.555;
   const double MIN_WEIGHT = 44.2222;
      /// convert the struct to class
   class Cargo {          
      
   public:
      void initialize(const char* desc, double weight);
      void setDesc(const char* desc);
      const char* getDesc() const;
      void setWeight(double weight);
      double getWeight()const;
      private:
      char description[MAX_DESC + 1];
      double weight;

   };

}
#endif