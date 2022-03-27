//I have done all the coding by myself and only copied the code that my professor provided to complete my workshopsand assignments.

/***********************************************************************
// Workshop 2: Dynamic Memory & Function Overloading
// Version 2.0
// Date	2020/05/05
// Author Michael Huang
// Description
// Tests Gift module and provides a set of TODOs to complete
// which the main focuses are dynamic memory allocation
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
// Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           3/6/2020

#include <iostream>
#include "Gift.h"
#include "Gift.h" // Intentional
using namespace std;
using namespace sdds;

int main() {
    int No_gifts = 0; // Initial number of Gifts

    // TODO 1: declare a pointer for a dynamic array of Gifts (remember to initialize it)
    Gift* GIFTS = nullptr;
    // END TODO 1

    cout << "Enter number of Gifts to allocate: ";
    cin >> No_gifts;

    if (No_gifts < 1)
        return 1;

    // TODO 2: allocate dynamic memory for the gifts pointer using the No_gifts

    GIFTS = new Gift[No_gifts];

    // END TODO 2

    for (int i = 0; i < No_gifts; ++i)
    {
        cout << "Gift #" << i + 1 << ": " << endl;
        
        // TODO 3: utilizing the gifting functions, allow input for the gift's description
        gifting(GIFTS[i].g_description);
        // END TODO 3
        
        cin.ignore(2000, '\n'); // clear input buffer
        
        // TODO 4: utilizing the gifting functions, allow the user to input the gift's price
        gifting(GIFTS[i].g_price);
        // END TODO 4
        
        cin.ignore(2000, '\n'); // clear input buffer
        
        // TODO 5: utilizing the gifting functions, allow the user to input the units of gift
        gifting(GIFTS[i].g_units);
        // END TODO 5
        cin.ignore(2000, '\n');
        cout << endl;
    }



    // TODO 6: display the details of each gift using the Gifts module display function
    for (int i = 0; i < No_gifts; i++) {
        cout << "Gift #" << i + 1 << ": " << endl;
        display(GIFTS[i]);
    }
    // END TODO 6

    // TODO 7: deallocate the gifts pointer here to avoid memory as we are done with it
    delete[] GIFTS;
    // END TODO 7

    return 0;
}