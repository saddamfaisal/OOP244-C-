#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>

#include "Car.h"

using namespace std;

namespace sdds
{
	Car::Car()
	{
		c_wash = false;
	}

	Car::Car(const char* plt, const char* make_model) :Vehicle(plt, make_model)
	{
		c_wash = false;
	}

	bool Car::getCarWash() const
	{
		return c_wash;
	}

	istream& Car::read(std::istream& ist)
	{
		if (isCsv() == false)
		{
			char btx[4];
			bool opt = false;
			cout << endl << "Car information entry" << endl;
			Vehicle::read(ist);
			ist.ignore(1000, '\n');
			cout << "Carwash while parked? (Y)es/(N)o: ";

			while (!opt)
			{
				ist >> btx;



				if (strcmp(btx, "N") == 0 || strcmp(btx, "n") == 0)
				{
					c_wash = false;
					opt = true;
				}
				else if (strcmp(btx, "Y") == 0 || strcmp(btx, "y") == 0)
				{
					c_wash = true;
					opt = true;
				}

				else
				{
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					ist.ignore(1000, '\n');
				}
			}


		}

		else
		{
			char chk;
			Vehicle::read(ist);
			ist.ignore();
			ist.get(chk);
			if (chk != '0')
				c_wash = true;
			else if (chk == '0')
				c_wash = false;
		}

		return ist;
	}

	ostream& Car::write(std::ostream& os) const
	{
		if (!isEmpty()) {
			if (isCsv() == false)
				os << "Vehicle type: Car" << endl;
			else
				os << "C,";
			Vehicle::write(os);
			if (isCsv() == false) {
				if (getCarWash())
					os << "With Carwash" << endl;
				else

					os << "Without Carwash" << endl;

			}
			else

				os << (int)getCarWash() << endl;

		}


		else
			os << "Invalid Car Object" << endl;



		return os;
	}
}