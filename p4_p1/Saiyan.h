//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
// Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           17/6/2020

#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

 #include <iostream>
 #include <cstring> 
#include <string>
const int MAX_LENGTH = 31;
namespace sdds {
   
   class Saiyan
   {
      char m_name[MAX_LENGTH + 1];
      int m_dob;  //<=2020
      int m_power; //  strength(>=0)
      bool m_super;
   public:
      Saiyan() ;
      Saiyan(const char* name, int dob, int power);

      bool super() const;
      void set(const char* name, int dob, int power, bool super = false);
      bool isValid() const;
      void display() const;
      void setEmpty();
      bool fight(const Saiyan& other) const;
   };
}

#endif