#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

#include "Engineer.h"

using namespace std;

namespace sdds

{

   Engineer::Engineer(double rate, int level) : Employee(rate, 30)

   {

      

      if (level > 0)

      {

         m_level = level;

      }

   }

   double Engineer::getSalary(int workedHours) const

   {

      //you will need to call getHourlyRate() and getMinWorkHours() from base class

      Employee::getHourRate();

      Employee::getMinWorkHours();

      //multiply workedHours by rate

      (workedHours * getHourRate());

      //add to salary $40.00 times level

      (getHourRate() + m_level * 40);

      //if he worked less than minimum deduct from salary 20%

      if (workedHours < getMinWorkHours())

      {

         (getHourRate() - getHourRate() * 20 / 100);

      }

   }

    std::ostream& Engineer::display(std::ostream& os) const

   {

      // display info according to workshop documentation

      //and output sample file (you may need setw(20) manipulator)

      os << "Engineer" << endl;

      os << "Level: " << m_level << endl;

      os << "Pay rate: " << getHourRate() << endl;

      os << "Min Hours: " << getMinWorkHours() << endl;

      return os;

   }

}