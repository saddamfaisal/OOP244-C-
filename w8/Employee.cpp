

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Employee.h"
using namespace std;

namespace sdds {
   Employee::Employee(double rate, int hours) :MIN_Work_Hours(hours) {
      if (rate > 0) {
         m_hourlyRte = rate;
      }
      else {

      }
      m_hourlyRte = 0;
  }
 Employee::~Employee(){}

 double Employee::getHourRate()const {
    return  m_hourlyRte;
 }
 int Employee::getMinWorkHours()const {
    return MIN_Work_Hours;

 }


 std::ostream& operator<<(std::ostream& out, const Employee& emp) {
    
    return emp.display(out);
 }























}
