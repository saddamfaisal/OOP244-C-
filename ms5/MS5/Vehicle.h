

//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           25/07/2020

#ifndef SDDS_Vehicle_H
#define SDDS_Vehicle_H

#define _CRT_SECURE_NO_WARNINGS

#include "ReadWritable.h"
#include <iostream>
#include <string>


using namespace std;

namespace sdds {

	const int MAXSIZE = 8;



	class Vehicle : public ReadWritable {

		char license_Plate[8 + 1];
		char* make_model;
		int ParkingSpotNumber;
	protected:
		void setEmpty();
		bool isEmpty() const;

		const char* getLicensePlate();
		const char* getMakeModel();
		void setMakeModel(const char*);
	public:

		int getParkingSpot() const;
		void setParkingSpot(int);
		friend bool operator==(const Vehicle&, const char*);
		friend bool operator==(const Vehicle&, const Vehicle&);
		virtual std::istream& read(std::istream& st = std::cin);

		virtual std::ostream& write(std::ostream& os = std::cout) const;
		virtual ~Vehicle();
		Vehicle();

		Vehicle(const char*, const char* m_model, int spotnum = 0);

		Vehicle(const Vehicle&) = delete;
		Vehicle& operator=(const Vehicle&) = delete;















	};
}


#endif

