
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           25/07/2020

#include "Menu.h"

namespace sdds
{
   
   MenuItem::MenuItem()
   {
      this->menu_name = nullptr;
   }

   
   MenuItem::MenuItem(const char* m_data)
   {
      if (m_data == nullptr)
      {
         this->menu_name = nullptr;
      }
      else
      {
         int str_size = std::strlen(m_data);
         this->menu_name = new char[str_size + 1];
         std::strncpy(this->menu_name, m_data, str_size);
         this->menu_name[str_size] = '\0';
      }
   }

  
   MenuItem::~MenuItem()
   {
      if (this->menu_name != nullptr)
      {
         delete[] this->menu_name;
         this->menu_name = nullptr;
      }
   }

  
   std::ostream& operator<<(std::ostream& os, const MenuItem& tr)
   {
      os << tr.menu_name << std::endl;
      return os;
   }

  
   Menu::Menu()
   {
      this->menu_headlines = nullptr;
      this->items[0].menu_name = nullptr;
      this->items_num = 0;
      this->v_indet = 0;
   }

  
   Menu::~Menu()
   {
      if (this->menu_headlines != nullptr)
      {
         delete[] this->menu_headlines;
         this->menu_headlines = nullptr;
      }
   }

   
   Menu::Menu(const char* incoming_str, int incoming_size)
   {
      if (incoming_size > 0)
      {
         this->v_indet = incoming_size;
      }

      this->menu_headlines = new char[std::strlen(incoming_str) + 1];
      std::strncpy(this->menu_headlines, incoming_str, std::strlen(incoming_str));
      this->menu_headlines[std::strlen(incoming_str)] = '\0';
   }

  
   Menu::Menu(const Menu& incoming_obj)
   {
      this->menu_headlines = nullptr;
      *this = incoming_obj;
   }

  
   Menu& Menu::operator=(const Menu& m_taregt)
   {
      if (this != &m_taregt)
      {
         if (this->menu_headlines != nullptr)
         {
            delete[] this->menu_headlines;
            this->menu_headlines = nullptr;
         }

         if (m_taregt.isEmpty()) 
         {
            this->items_num = 0;
            this->v_indet = 0;

            for (int index = 0; index < MAX_NO_OF_ITEMS; index++)
            {
               if (this->items[index].menu_name != nullptr)
               {
                  delete[] this->items[index].menu_name;
                  this->items[index].menu_name = nullptr;
               }
            }
         }
         else
         {
            this->v_indet = m_taregt.v_indet;

            if (m_taregt.menu_headlines != nullptr)
            {
               if (this->menu_headlines != nullptr)
               {
                  delete[] this->menu_headlines;
                  this->menu_headlines = nullptr;
               }

               this->menu_headlines = new char[std::strlen(m_taregt.menu_headlines) + 1];
               std::strncpy(this->menu_headlines, m_taregt.menu_headlines, std::strlen(m_taregt.menu_headlines));
               this->menu_headlines[std::strlen(m_taregt.menu_headlines)] = '\0';
            }

            if (m_taregt.items_num > 0)
            {
               for (int index = 0; index < m_taregt.items_num; index++)
               {
                  if (this->items[index].menu_name != nullptr)
                  {
                     delete[] this->items[index].menu_name;
                     this->items[index].menu_name = nullptr;
                  }

                  this->items[index].menu_name = new char[std::strlen(m_taregt.items[index].menu_name) + 1];
                  std::strncpy(this->items[index].menu_name, m_taregt.items[index].menu_name, std::strlen(m_taregt.items[index].menu_name));
                  this->items[index].menu_name[std::strlen(m_taregt.items[index].menu_name)] = '\0';
               }
            }
            else
            {
               for (int index = 0; index < MAX_NO_OF_ITEMS; index++)
               {
                  if (this->items[index].menu_name != nullptr)
                  {
                     delete[] this->items[index].menu_name;
                     this->items[index].menu_name = nullptr;
                  }
               }
            }
            this->items_num = m_taregt.items_num;
         }
      }

      return *this;
   }

  
   Menu Menu::operator=(const char* on_obt)
   {
      if (this->menu_headlines != nullptr)
      {
         delete[] this->menu_headlines;
         this->menu_headlines = nullptr;
      }

      this->menu_headlines = new char[std::strlen(on_obt) + 1];
      std::strncpy(this->menu_headlines, on_obt, std::strlen(on_obt));
      this->menu_headlines[std::strlen(on_obt)] = '\0';

      return *this;
   }

   
   Menu::operator bool() const
   {
      if (this->menu_headlines != nullptr && (this->items_num > 0 && this->items[0].menu_name != nullptr))
      {
         return true;
      }
      else
      {
         return false;
      }
   }

   bool Menu::isEmpty() const
   {
      return (this->menu_headlines == nullptr && this->items_num <= 0);
   }

  
   void Menu::display() const
   {
      int indent = this->v_indet * 4;
      if (this->isEmpty())
      {
         std::cout << "Invalid Menu!" << std::endl;
      }
      else
      {
         std::cout << std::setw(indent) << "";
         std::cout << this->menu_headlines << std::endl;

         if (this->items_num == 0)
         {
            std::cout << "No Items to display!" << std::endl;
         }
         else
         {
            indent = indent == 0 ? 0 : indent + 1;

            for (int index = 0; index < items_num; index++)
            {
               std::cout << std::setw(indent) << index + 1 << "- ";
               std::cout << this->items[index];
            }

            indent = indent == 0 ? 0 : indent + 1;
            std::cout << std::setw(indent) << "> "; 
         }
      }
   }

   
   void Menu::add(const char* m_sub)
   {
      if (!this->isEmpty())
      {
         if (m_sub == nullptr)
         {
            delete[] this->menu_headlines;
            this->menu_headlines = nullptr;

            this->items_num = 0;
            this->v_indet = 0;

            for (int index = 0; index < MAX_NO_OF_ITEMS; index++)
            {
               if (this->items[index].menu_name != nullptr)
               {
                  delete[] this->items[index].menu_name;
                  this->items[index].menu_name = nullptr;
               }
            }
         }
         else if (this->items_num < MAX_NO_OF_ITEMS)
         {
            new (&this->items[this->items_num++]) MenuItem(m_sub);
         }
      }
   }

  
   int Menu::run() const
   {
      this->display();

      if (this->items_num > 0)
      {
         int choice = 0;

         while (choice <= 0 || choice > this->items_num)
         {
            std::cin >> choice;

            if (!std::cin)
            {
               std::cout << "Invalid Integer, try again: ";
               std::cin.clear();
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (choice <= 0 || choice > this->items_num)
            {
               std::cout << "Invalid selection, try again: ";

               if (!std::cin) 
               {
                  std::cin.clear();
                  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               }
            }
         }

         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         return choice;
      }
      else
      {
         return 0;
      }
   }

  
   Menu::operator int() const
   {
      return this->run();
   }

  
   Menu& operator<<(Menu& st, const char* obt)
   {
      st.add(obt);
      return st;
   }

} 