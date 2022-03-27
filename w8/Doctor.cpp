

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>

#include "Doctor.h"

using namespace std;

namespace sdds

{

   Doctor::Doctor(const char* type, double rate, int hours, bool specialist) : Employee(rate, hours)

   {

      if (type != nullptr && type[0] != '\0')

      {

         strncpy(m_type, type, MAX_CHAR);

         m_specialist = specialist;

      }

   }

   double Doctor::getSalary(int  workedHours) const

   {

      //you will need to call getHourlyRate() and getMinWorkHours() from base class

      Employee::getHourRate();

      Employee::getMinWorkHours();

      //if worked hours more than or equal to minimum

      if (workedHours >= getMinWorkHours())

      {

         //multiply rate by minimum hours and add for extra hours 1.5*rate

         int extraHours = workedHours - getMinWorkHours();

         (getHourRate() * getMinWorkHours() + extraHours * 1.5 * getHourRate());

      }

      //otherwise multiply rate by workedHours

      else

      {

         (getHourRate() * workedHours);

      }

      //if he is a specialists add $2,000.00

      if (m_specialist)

      {

         (getHourRate() + 2000);

      }

   }

    std:: ostream& Doctor::display(std::ostream& os) const

   {

      // display info according to workshop documentation

      //and output sample file (you may need setw(16) manipulator)

      if (m_specialist == false) {

         os << "Doctor" << endl;

         os << "Type: " << endl;

            os << "Pay rate: " << getHourRate() << endl;

         os << "Min Hours: " << getMinWorkHours() << endl;

      }

      else

      {

         os << "Doctor" << endl;

         os << "Type: " << m_type << " (specialist)" << endl;

         os << "Pay rate: " << getHourRate() << endl;

         os << "Min Hours: " << getMinWorkHours() << endl;

      }

      return os;

   }

}
