
#ifndef SDDS_EMGINEER_H__

#define SDDS_ENGINEER_H__

#include "Employee.h"

namespace sdds

{

   class Engineer :public Employee

   {

      int m_level;

   public:

      Engineer(double rate, int level);

      virtual double getSalary(int workedHours) const;

      virtual std::ostream& display(std::ostream& os) const;

   };

}

#endif