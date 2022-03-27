//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           7/6/2020
#ifndef SHIP_H
#define SHIP_H

#define _CRT_SECURE_NO_WARNINGS
#include "Engine.h"

namespace sdds
{
const double MIN_STD_POWER = 90.111;
const double MAX_STD_POWER = 99.999;
const int NUM_OF_ENGINES = 10;

class Ship
{
private:
    Engine m_engines[NUM_OF_ENGINES];
    int m_engCnt;
    char m_type[TYPE_MAX_SIZE + 1];


public:
    Ship();
    Ship(const char* type, const Engine arr[], int size);
    operator bool() const;
    Ship& operator+=(Engine r);
    bool operator<(double power) const;
    double calculatorPower() const;
    void display() const;
};

bool operator<(double power, const Ship& theShip);
}

#endif // SHIP_H
