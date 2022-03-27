
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           07/07/2020
#define _CRT_SECURE_NO_WARNINGS
#ifndef BASKET_H
#define BASKET_H
#include <iostream>
namespace sdds{

   struct Fruit
   {
      char m_name[30 + 1]; // the name of the fruit
      double m_qty;        // quantity in kilograms
   };


   class Basket {
      Fruit* m_fruits;
      int m_cnt;
      double m_price;
      public:
      Basket(); //default counstructor
      Basket(  Fruit* fruits, int cnt, double price); // custome counstructor
      operator bool() const;// bool convertor
      Basket& operator +=(Fruit fruits);
      Basket(const Basket& bas); // copy counstructor
      Basket& operator =(const Basket& basket); //cpy assignment operator
      void setPrice(double pr);
     
      std::ostream& display(std::ostream& os) const;
      ~Basket();
     
      bool isEmpty() const;


   };

   std::ostream& operator<<(std::ostream& os, const Basket& bsk);



}
#endif