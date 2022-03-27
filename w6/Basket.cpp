
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           o7/07/2020
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Basket.h"

using namespace std;

namespace sdds {



   Basket::Basket() {
      m_fruits = nullptr;
      m_cnt = 0;
      m_price = 0;
   }

   Basket::Basket(Fruit* fruits, int cnt, double price) {
   
      m_fruits = nullptr;
      m_cnt = 0;
      m_price = 0;
      if (fruits != nullptr && cnt > 0 && price > 0) {


         //  m_fruits = fruits;
           m_cnt = cnt;
           m_price = price;
         m_fruits = nullptr;
         m_fruits = new Fruit[m_cnt];


         for (int i = 0; i < m_cnt; i++)
            m_fruits[i] = fruits[i];
         if (m_cnt > 0) {
            m_cnt = cnt;
            setPrice(price);
         }

      }
      else {
         m_fruits = nullptr;
         m_cnt = 0;
         m_price = 0;
      }
      
   }


   void Basket::setPrice(double prc) {
     
         m_price = prc;
      
   }


   Basket::operator bool() const
   {
      //bool convertor
      if (m_fruits != nullptr && m_cnt > 0 && m_price > 0)
         return true;

      else
         return false;
   }
   Basket& Basket::operator+=(Fruit fruits) {

      Fruit* temp = new Fruit[m_cnt + 1];
      for (int i = 0; i < m_cnt; i++) {

         temp[i] = m_fruits[i];

      }
     
      delete[] m_fruits;
      m_fruits = temp;
      temp = nullptr;

      m_fruits[m_cnt++] = fruits;
      return *this;



   }
   Basket::Basket(const Basket& bas) {

      //shallow copies
      m_cnt = bas.m_cnt;
      m_price = bas.m_price;
      //allocate dym memory for 
      if (bas.m_fruits != nullptr) {
         m_fruits = nullptr;
         m_fruits = new Fruit[m_cnt];
         for (int i = 0; i < m_cnt; i++)
            this->m_fruits[i] = bas.m_fruits[i];
      }
      else {
         m_fruits = nullptr;


      }
   }
   Basket& Basket::operator=(const Basket& basket) {


      if (this != &basket) { //check self assignment
         m_cnt = basket.m_cnt;
         m_price = basket.m_price;
         //deallocate previous allocate
         delete[] m_fruits;
         //allocate new dynamic memory
         if (basket.m_fruits != nullptr) {
            //setName(basket.m_fruits);
            
            m_fruits = new Fruit[basket.m_cnt];
            for (int i = 0; i < m_cnt; i++)
               this->m_fruits[i] = basket.m_fruits[i];
         }
         else {
            m_fruits = nullptr;
         }
      }
      return *this;


   }


   bool Basket::isEmpty() const {
      bool empty = false;
      if (m_fruits == nullptr && m_cnt == 0 && m_price == 0)
      {
         empty = true;
      }
      return empty;
   }
   std::ostream& Basket::display(std::ostream& os) const {
      if (isEmpty()) {
         os << "The basket is empty!" << std::endl;
      }
      else {
         os << "Basket Content:" << std::endl;
         
         for (int i = 0; i < m_cnt; i++) {
            os << setw(10) << right << m_fruits[i].m_name << ": ";
            os << setprecision(2) << fixed << m_fruits[i].m_qty << "kg" << std::endl;
         }
         
         os << setprecision(2);
         os << fixed;
         os << "Price: " << m_price << std::endl;
      }
      return os;
   }
    std::ostream& operator<<(std::ostream& os, const Basket& bsk) {
      bsk.display(os);
      return os;
   }


    Basket::~Basket() {
       delete[] m_fruits;
       m_fruits = nullptr;
    }
}