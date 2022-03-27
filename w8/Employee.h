

#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include<iostream>




namespace sdds {
	class Employee
	{
	
		

	    private:
			 const int  MIN_Work_Hours{ 0 };
			 double m_hourlyRte{ 0.0 };
	   protected:
		double getHourRate()const;
		int getMinWorkHours()const;
	 public:
		Employee(double rate, int hours);
		virtual double getSalary(int workedHours) const = 0;
		virtual std::ostream& display(std::ostream& os = std:: cout) const = 0;
		virtual ~Employee();
	};
	  std::ostream& operator<<(std::ostream& out, const Employee& emp);
}
#endif // !_EMPLOYEE_H_

