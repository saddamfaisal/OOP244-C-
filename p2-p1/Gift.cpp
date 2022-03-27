//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
// Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           3/6/2020


#define _CRT_SECURE_NO_WARNINGS

#include "Gift.h"

using namespace std;

namespace sdds {

	// the function accepts a character array pointer and gets the value for it that is askes the desc 
	void gifting(char* DESCRIPTION) {

		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> DESCRIPTION;
	}
	// the fucntion accepts a double  and gets its value 
	void gifting(double& PRICE) {
		cout << "Enter gift price: ";
		cin >> PRICE;
		while (PRICE < 0 || PRICE > MAX_PRICE) {
			cout << "Gift price must be between 0 and 999.999" << endl;
			cout << "Enter gift price: ";
			cin >> PRICE;

		}
	}
	// the function accepts a int and gets its valu
	void gifting(int& UNITS) {

		cout << "Enter gift units: ";
		cin >> UNITS;
		while (UNITS < 1) {
			cout << "Gift units must be at least 1" << endl;
			cout << "Enter gift units: ";
			cin >> UNITS;
		}
	}
	// the function accepts an sturcture object and dispalys its values
	void display(const Gift& gift_i) {

		cout << "Gift Details:" << endl << " Description: " << gift_i.g_description << endl << "       Price: " << gift_i.g_price << endl << "       Units: " << gift_i.g_units << endl << endl;
	}
}