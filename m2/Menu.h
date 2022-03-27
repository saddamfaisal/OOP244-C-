
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           25/07/2020

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>

namespace sdds
{
   const int MAX_NO_OF_ITEMS{ 10 };

   class MenuItem
   {
      friend class Menu;

      char* menu_name{ nullptr };

      MenuItem();             
      MenuItem(const char*); 
      ~MenuItem(); 

      MenuItem(const MenuItem&) = delete;           
      MenuItem& operator=(const MenuItem&) = delete; 
      friend std::ostream& operator<<(std::ostream&, const MenuItem&); 
   };

   class Menu
   {
   private:
      char* menu_headlines{ nullptr };
      MenuItem items[MAX_NO_OF_ITEMS];
      int items_num{ 0 }; 
      int v_indet{ 0 };

   public:
      Menu();                     
      ~Menu();                     
      Menu(const char*, int = 0); 

      Menu(const Menu&);           
      Menu& operator=(const Menu&); 

      Menu operator=(const char*); 

      explicit operator bool() const; 
      bool isEmpty() const;           
      void display() const;          
      void add(const char*);         
      int run() const;                      
      operator int() const;        
   };
   Menu& operator<<(Menu&, const char*);
} 

#endif 