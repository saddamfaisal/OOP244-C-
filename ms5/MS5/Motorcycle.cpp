#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Motorcycle.h"
#include<cstring>
using namespace std;

namespace sdds
{
	Motorcycle::Motorcycle() {
		c_side = false;
	}

	Motorcycle::Motorcycle(const char* plt, const char* make_model) :Vehicle(plt, make_model) {
		c_side = false;
	}

	bool Motorcycle::getSideCar() const
	{
		return c_side;
	}

	istream& Motorcycle::read(std::istream& ist)
	{
		if (isCsv() == false)
		{

			cout << endl << "Motorcycle information entry" << endl;
			Vehicle::read(ist);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			bool opt = false;
			do
			{

				char btx[4];
				ist >> btx;


				if (strcmp(btx, "N") == 0 || strcmp(btx, "n") == 0)
				{
					c_side = false;
					opt = true;
				}

				if (strcmp(btx, "Y") == 0 || strcmp(btx, "y") == 0)
				{
					c_side = true;
					opt = true;
				}

				else
				{
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					ist.ignore(1000, '\n');
				}

			} while (!opt);


		}

		else
		{

			char ch;
			Vehicle::read(ist);
			ist.ignore();
			ist.get(ch);
			if (ch != '0')
				c_side = true;
			else if (ch == '0')

				c_side = false;
		}
		return ist;
	}

	ostream& Motorcycle::write(std::ostream& os) const
	{
		if (!isEmpty()) {
			if (isCsv() == false)
				os << "Vehicle type: Motorcycle" << endl;

			else

				os << "M,";



			Vehicle::write(os);
			if (isCsv() == false) {
				if (getSideCar())
					os << "With Sidecar" << endl;
			}

			else

				os << (int)getSideCar() << endl;
		}
		else

			os << "Invalid Motorcycle Object" << endl;



		return os;
	}

}