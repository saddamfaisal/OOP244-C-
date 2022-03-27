//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           7/6/2020




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
	const int MAX_WRAP = 20;

	struct Wrapping {
		char* m_pattern;

	};

	struct Gift {
		char m_description[MAX_DESC + 1];
		double m_price;
		int m_units;
		Wrapping* m_wrap;
		int m_wrapLayers;
	};
	void gifting(Gift& gift);
	void gifting(char* desciption);
	void gifting(double& price);
	void gifting(int& units);

	void display(const Gift&);

	bool wrap(Gift&);
	bool unwrap(Gift&);
}


#endif // !GIFT_H