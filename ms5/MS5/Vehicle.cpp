

//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           25/07/2020


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <string.h>

#include "Vehicle.h"
using namespace std;
namespace sdds {

	void Vehicle::setEmpty() {

		license_Plate[0] = '\0';

		make_model = nullptr;

		ParkingSpotNumber = 0;

	}


	bool Vehicle::isEmpty() const {

		return license_Plate[0] == '\0' || make_model == nullptr;

	}




	const char* Vehicle::getLicensePlate() {

		return license_Plate;

	}



	const char* Vehicle::getMakeModel() {

		return make_model;

	}




	void Vehicle::setMakeModel(const char* m_Model) {

		if (m_Model != nullptr && m_Model[0] != '\0' && strlen(m_Model) >= 2) {

			int size = strlen(m_Model) + 1;

			delete[] make_model;

			make_model = new char[size];

			strcpy(make_model, m_Model);

		}

		else {

			delete[] make_model;

			setEmpty();

		}

	}






	int Vehicle::getParkingSpot() const {

		return ParkingSpotNumber;

	}





	void Vehicle::setParkingSpot(int parkNum) {

		if (parkNum >= 0) {

			ParkingSpotNumber = parkNum;

		}

		else {

			delete[] make_model;

			setEmpty();

		}

	}




	bool operator==(const Vehicle& vh, const char* plate) {

		bool match = false;

		if (!vh.isEmpty()) {

			if (plate != nullptr && plate[0] != '\0'

				&& strlen(plate) <= MAXSIZE) {

				if (strcmp(vh.license_Plate, plate)) {

					match = true;

				}

			}

		}



		return match;

	}









	bool operator==(const Vehicle& vh1, const Vehicle& vh2) {

		bool match = false;

		if (!vh1.isEmpty() && !vh2.isEmpty()) {

			if (strcmp(vh1.license_Plate, vh2.license_Plate)) {

				match = true;

			}

		}



		return match;

	}







	std::istream& Vehicle::read(std::istream& st) {

		if (isCsv()) {

			st >> ParkingSpotNumber;

			st.ignore();

			st.getline(license_Plate, MAXSIZE + 1, ',');

			toupper(license_Plate[0]);

			char temp[60 + 1] = { '\0' };

			st.getline(temp, 60 + 1, ',');

			setMakeModel(temp);

		}

		else {

			std::cout << "Enter Licence Plate Number: ";

			char tp_Plate[MAXSIZE + 2];

			int invalid;

			do {

				invalid = 0;

				st.getline(tp_Plate, MAXSIZE + 2);

				if (strlen(tp_Plate) == 0 || strlen(tp_Plate) > MAXSIZE) {

					invalid = 1;

					std::cout << "Invalid Licence Plate, try again: ";

				}

				st.clear();

			} while (invalid);

			strncpy(license_Plate, tp_Plate, MAXSIZE);

			license_Plate[MAXSIZE] = '\0';

			toupper(license_Plate[0]);



			std::cout << "Enter Make and Model: ";

			char temp[60 + 2] = { '\0' };

			do {

				invalid = 0;

				st.getline(temp, 60 + 2);

				if (strlen(temp) < 2 || strlen(temp) > 60) {

					invalid = 1;

					std::cout << "Invalid Make and model, try again: ";

					st.clear();

				}

			} while (invalid);

			setMakeModel(temp);



			ParkingSpotNumber = 0;

		}



		if (st.fail()) {

			st.clear();

			setEmpty();

		}



		return st;

	}







	std::ostream& Vehicle::write(std::ostream& os) const {

		if (isEmpty()) {

			os << "Invalid Vehicle Object" << std::endl;

		}

		else {

			if (isCsv()) {

				os << ParkingSpotNumber << "," << license_Plate << "," << make_model << ",";

			}

			else {

				os << "Parking Spot Number: ";

				if (ParkingSpotNumber > 0) {

					os << ParkingSpotNumber << std::endl;

				}

				else {

					os << "N/A" << std::endl;

				}

				os << "Licence Plate: " << license_Plate << std::endl;

				os << "Make and Model: " << make_model << std::endl;

			}

		}



		return os;

	}








	Vehicle::~Vehicle() {

		delete[] make_model;

		make_model = nullptr;

	}




	Vehicle::Vehicle() : ReadWritable() {

		setEmpty();

	}



	Vehicle::Vehicle(const char* plt, const char* m_model, int spotnum) : ReadWritable() {

		setEmpty();

		if (plt != nullptr && plt[0] != '\0' && strlen(plt) <= MAXSIZE) {

			strncpy(license_Plate, plt, MAXSIZE);

			license_Plate[MAXSIZE] = '\0';

			toupper(license_Plate[0]);

		}

		else {

			license_Plate[0] = '\0';

		}

		setMakeModel(m_model);

		setParkingSpot(spotnum);

	}


















}