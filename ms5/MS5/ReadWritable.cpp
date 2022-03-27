

//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           25/07/2020
#include <iostream>

#include "ReadWritable.h"





namespace sdds {

	ReadWritable::ReadWritable() {

		commaSepFlag = false;

	}



	bool ReadWritable::isCsv()const {

		return commaSepFlag;

	}



	void ReadWritable::setCsv(bool value) {

		commaSepFlag = value;

	}



	ReadWritable::~ReadWritable() {



	}


	std::ostream& operator<<(std::ostream& ost, const ReadWritable& rt)
	{

		rt.write(ost);

		return ost;
	}


	std::istream& operator>>(std::istream& ost, ReadWritable& rt) {

		rt.read(ost);

		return ost;

	}

}