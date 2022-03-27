#ifndef GIFT_H
#define GIFT_H

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.
// Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           3/6/2020

#include <iostream>

namespace sdds {
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.999;


	struct Gift {
		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;
	};

	void gifting(char* desciption);
	void gifting(double& price);
	void gifting(int& units);

	void display(const Gift&);

}


#endif // !GIFT_H