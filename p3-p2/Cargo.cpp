

//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           10/6/2020

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Cargo.h"
#include "Train.h"

using namespace std;
namespace sdds {

   void  Cargo::initialize(const char* newdesc, double newwei)
   {

      if (strlen(newdesc) <= MAX_DESC)
         
         setDesc(newdesc);

        setWeight(newwei);

        if (newwei >= MIN_WEIGHT && newwei <= MAX_WEIGHT)
        {
           setWeight(newwei);
        }
        else
        {

           setWeight(MIN_WEIGHT);

        }






   };
   void Cargo::setDesc(const char* newdesc)
   {
    
        
      strcpy(description, newdesc);





   };
   const char* Cargo::getDesc() const
   {
      return description;

   };
   void Cargo::setWeight(double newwei)
   {
     

      weight = newwei;





   };
   double Cargo::getWeight()const
   {
      return weight;







   };

}  