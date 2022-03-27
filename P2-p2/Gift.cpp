
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           7/6/2020





#define _CRT_SECURE_NO_WARNINGS

// Gift.cpp
#include <iostream>
#include <cstring>
#include "Gift.h"


using namespace std;

namespace sdds
{
	// This function wraps an valid unwrapped gift


	// This function utilizes the the following gifting 
	// functions retrieve a valid gift and then wraps it
	void gifting(Gift& gift)
	{
		cout << "Preparing a gift..." << endl;
		gifting(gift.m_description);
		gifting(gift.m_price);
		gifting(gift.m_units);
		wrap(gift);
	}

	// This function retrieves the description for a gift
	void gifting(char* desc)
	{
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> desc;
	}

	// This function retrieves the price of a gift
	void gifting(double& price)
	{
		bool valid;
		do
		{
			valid = true;
			cout << "Enter gift price: ";
			cin >> price;

			if (price < 0 || price > MAX_PRICE)
			{
				cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
				valid = false;
			}
		} while (!valid);
	}

	// This function retrieves the unit total of a gift
	void gifting(int& units)
	{
		bool valid;
		do
		{
			valid = true;
			cout << "Enter gift units: ";
			cin >> units;

			if (units < 1)
			{
				cout << "Gift units must be at least 1" << endl;
				valid = false;
			}
		} while (!valid);
	}

	// This function displays available gift information
	void display(const Gift& gift)
	{
		cout << "Gift Details:" << endl;
		cout << "Description: " << gift.m_description << endl;
		cout << "Price: " << gift.m_price << endl;
		cout << "Units: " << gift.m_units << endl;

		if (gift.m_wrap != nullptr)
		{
			cout << "Wrap Layers: " << gift.m_wrapLayers << endl;
			for (int i = 0; i < gift.m_wrapLayers; i++)
				cout << "Wrap #" << i + 1 << " -> " << gift.m_wrap->m_pattern << endl;
		}
		else
		{
			cout << "Unwrapped!" << endl;
		}
	}

	bool wrap(Gift& gift)
	{
		bool checkGift, True;
		if (gift.m_wrapLayers < 1)
		{
			cout << "Wrapping gifts..." << endl;
			do
			{
				True = true;
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> gift.m_wrapLayers;
				if (gift.m_wrapLayers < 1)
				{
					cout << "Layers at minimum must be 1, try again." << endl;
					True = false;
				}
			} while (!True);

			// Allocates dynamic memory from input
			gift.m_wrap = new Wrapping[gift.m_wrapLayers];

			for (int i = 0; i < gift.m_wrapLayers; i++)
			{
				// Temp character pointer to store input string
				char* temp = new char[MAX_WRAP + 1];

				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin.width(MAX_WRAP + 1);
				cin >> temp;

				// Allocates dynamic memory from strlen of temp
				gift.m_wrap[i].m_pattern = new char[strlen(temp) + 1];

				// Swaps information
				strcpy(gift.m_wrap[i].m_pattern, temp);

				// Deallocation
				delete[] temp;
				temp = nullptr;
			}
			checkGift = true;
		}
		else
		{
			cout << "Gift is already wrapped!" << endl;
			checkGift = false;
		}
		return checkGift;
	}

	// This function unwrapped a valid wrapped gift
	bool unwrap(Gift& gift)
	{
		bool checkGift;
		if (gift.m_wrap != nullptr)
		{
			cout << "Gift being unwrapped." << endl;
			// Deallocation of wrap and all  to prevent leak
			for (int i = 0; i < gift.m_wrapLayers; i++)
			{
				delete[] gift.m_wrap[i].m_pattern;
				gift.m_wrap[i].m_pattern = nullptr;
			}
			delete[] gift.m_wrap;
			gift.m_wrap = nullptr;
			gift.m_wrapLayers = 0;
			checkGift = true;
		}
		else
		{
			cout << "Gift isn't wrapped! Cannott unwrap." << endl;
			checkGift = false;
		}
		return checkGift;
	}

}; // namespace sdds