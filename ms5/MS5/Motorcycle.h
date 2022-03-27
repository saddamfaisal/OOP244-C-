
#ifndef SDDS_MOTORCYCLE_H__

#define SDDS_MOTORCYCLE_H__



#include "Vehicle.h"



namespace sdds {

	class Motorcycle : public Vehicle {

		bool 	c_side;

	public:

		Motorcycle(); 

		Motorcycle(const char* plt , const char* make_model);

		bool getSideCar() const;
		istream& read(istream&);
		ostream& write(ostream&)const;

		

	};

}

#endif