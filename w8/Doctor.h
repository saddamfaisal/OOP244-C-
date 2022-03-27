#ifndef SDDS_DOCTOR_H__

#define SDDS_DOCTOR_H__

#include <iostream>

#include "Employee.h"

namespace sdds

{

   const int MAX_CHAR = 32;//limit for doctor type

   class Doctor :public Employee

   {

      char m_type[MAX_CHAR + 1];

      bool m_specialist;

   public:

      Doctor(const char* type, double rate, int hours, bool specialist = false);

      virtual double getSalary(int workedHours) const;

      virtual std::ostream& display(std::ostream& os =std::cout) const;

   };

}

#endif