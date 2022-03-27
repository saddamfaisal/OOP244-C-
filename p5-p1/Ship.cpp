//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           7/6/2020

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Ship.h"

using namespace std;

namespace sdds
{
Ship::Ship()
{
    strcpy(m_type,"");
    m_engCnt = 0;
    for(int i=0; i < NUM_OF_ENGINES; i++)
        m_engines[i].set(0,"\0");
}

Ship::Ship(const char* type, const Engine engines[], int cnt)
{
    //cout << "Good 1" << endl;
    if (strcmp(type,"") != 0 && cnt > 0 && cnt < NUM_OF_ENGINES)

    {
        //create a valid ship
        //cout << "Good 2" << endl;
        strcpy(m_type, type);
        //cout << "Good 3" << endl;
        m_engCnt = cnt;
        //cout << "Good 4" << endl;
        for(int i = 0; i < m_engCnt; i++)
            m_engines[i] = engines[i];
    }

    else
    {
        //create an empty ship
        //cout << "Good ~2" << endl;
        m_type[0] = '\0';
        //cout << "Good ~3" << endl;
        m_engCnt = 0;
    }
}

Ship::operator bool() const
{
    //return true if the ship is valid(not empty)
    if ((strcmp(m_type, "") != 0) && (m_engCnt != 0))
        return true;

    else
        return false;
}

Ship& Ship::operator+=(Engine e)
{
    if (!*this)
    {
        std::cout << "The object is not valid! Engine cannot be added!" << std::endl;
        return *this;
    }
    //if the maximum is already reached return *this;
    if(m_engCnt >= NUM_OF_ENGINES && m_engCnt >=0)
        return *this;
    else
    {
        m_engines[m_engCnt].set_engine(e);
        m_engCnt++;
        return *this;
    }
    //update the array of engines and the counter of engines
}

double Ship::calculatorPower() const
{
    double total_power = 0.0;
    //for each engine multiply power by 5
    for(int i = 0; i < m_engCnt; i++)
        total_power += (5*(m_engines[i]. get()));
    // add all the multiplied powers and return
    return total_power;
}

void Ship::display() const
{
    if (m_engCnt != 0)
    {
        //display all the info about a ship according to the workshop documentation
        cout << m_type << " - " << calculatorPower() << endl;
        for(int i =0; i< m_engCnt; i++)
          m_engines[i].display();
    }
    else
        cout << "No available data" << endl;
}

bool Ship::operator< (double power) const
{
    //if the calculated ship power is less than power parameter, return true, otherwise return false
    if(power > calculatorPower())
        return true;
    else
        return false;
}

bool operator< (double power, const Ship& theShip)
{
    //if the power paramter is less than calculated theShip power, return true, otherwise return false
    if(power < theShip.calculatorPower())
        return true;
    else
        return false;
}
}