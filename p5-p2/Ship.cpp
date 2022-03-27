
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           28/6/2020

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
      m_engines = nullptr;
      m_type = nullptr;
      m_engCnt = 0;

   }

   Ship::Ship(const char* type, Engine* engines, int cnt)
   {
      *this = Ship();

      if (type != nullptr && engines != nullptr && cnt > 0)
      {
         m_engCnt = cnt;
         m_type = nullptr;



         m_type = new char[strlen(type) + 1];
         strcpy(m_type, type);
         //cout << "Good 3" << endl;
         m_engines = nullptr;
         m_engines = new Engine[m_engCnt];

         //cout << "Good 4" << endl;
         for (int i = 0; i < m_engCnt; i++)
            m_engines[i] = engines[i];
      }

      else
      {

         m_engines = nullptr;
         m_type = nullptr;
         m_engCnt = 0;

      }
   }

   Ship::operator bool() const
   {
      //return true if the ship is valid(not empty)
      if (m_engines != nullptr && m_type != nullptr && m_engCnt > 0)
         return true;

      else
         return false;
   }

   Ship& Ship::operator+=(Engine e)
   {
      if (!*this)
      {
         std::cout << "The object is not valid! Engine cannot be added!" << std::endl;
         //return *this;
      }
      else {
         // creat temporary dynamic array of engine

         Engine* temp = new Engine[m_engCnt + 1];
         for (int i = 0; i < m_engCnt; i++) {
            temp[i] = m_engines[i];

         }
         temp[m_engCnt] = e;
         delete[] m_engines;
         m_engines = new Engine[m_engCnt + 1];
         for (int i = 0; i < (m_engCnt + 1); i++) {
            m_engines[i] = temp[i];

         }
         m_engCnt++;
         delete[] temp;


      }
      return *this;

   }

   double Ship::calculatorPower() const
   {
      double total_power = 0.0;
      //for each engine multiply power by 5
      for (int i = 0; i < m_engCnt; i++)
         total_power += (5 * (m_engines[i].get()));
      // add all the multiplied powers and return
      return total_power;
   }

   void Ship::display() const
   {

      if (m_engines != nullptr && m_type != nullptr && m_engCnt > 0)
      {


         cout << setprecision(2) << fixed;


         cout << m_type << " - " << setw(6) << calculatorPower() << endl;



         for (int i = 0; i < m_engCnt; i++)
         {

            m_engines[i].Engine::display();
         }
         cout << setprecision(3) << fixed;
      }
      else
      {
         cout << "No available data" << endl;

      }
   }

    
   Ship::~Ship() {

      delete[] m_type;
      m_type = nullptr;
      delete[] m_engines;
      m_engines = nullptr;

  }
     

   
   bool Ship::operator< (double power) const
   {
      //if the calculated ship power is less than power parameter, return true, otherwise return false
      if (calculatorPower() < power)
         return true;
      else
         return false;
   }

   bool operator< (double power, const Ship& theShip)
   {
      //if the power paramter is less than calculated theShip power, return true, otherwise return false
      if (power < theShip.calculatorPower())
         return true;
      else
         return false;
   }
}
