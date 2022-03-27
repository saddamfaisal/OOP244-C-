
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           25/07/2020


#include <iostream>
#include <cstring>

#include "Parking.h"

namespace sdds
{
  
   Parking::Parking()
   {
      this->n_file = nullptr;
      this->m_indet = 0;
      this->parking_menu_options = Menu();
      this->vehicle_choosing_menu = Menu();
   }

   
   Parking::Parking(const char* arr)
   {
      if (arr == nullptr || arr[0] == '\0')
      {
         this->set_invalid();
      }
      else
      {
         int size = std::strlen(arr);
         this->n_file = new char[size + 1];
         std::strncpy(this->n_file, arr, size);
         this->n_file[size] = '\0';
      }

      if (this->load_data_file())
      {
         this->parking_menu_options = Menu("Parking Menu, select an action:", 0);

         this->parking_menu_options.add("Park Vehicle");
         this->parking_menu_options.add("Return Vehicle");
         this->parking_menu_options.add("List Parked Vehicles");
         this->parking_menu_options.add("Close Parking (End of day)");
         this->parking_menu_options.add("Exit Program");

         this->vehicle_choosing_menu = Menu("Select type of the vehicle:", 1);

         this->vehicle_choosing_menu.add("Car");
         this->vehicle_choosing_menu.add("Motorcycle");
         this->vehicle_choosing_menu.add("Cancel");
      }
      else
      {
         std::cout << "Error in data file" << std::endl;
         this->set_invalid();
      }
   }

   
   Parking::~Parking()
   {
      this->save_data_file();

      if (this->n_file != nullptr)
      {
         delete[] this->n_file;
         this->n_file = nullptr;
      }
   }

   int Parking::run()
   {
      if (!this->isEmpty()) 
      {
         bool esc = false;

         while (esc == false)
         {
            this->status();

            switch (this->parking_menu_options.run())
            {
            case 1:
               this->park_vehicle();
               continue;
            case 2:
               this->return_vehicle();
               continue;
            case 3:
               this->list_parked_vehicles();
               continue;
            case 4:
               if (this->close_parking())
               {
                  esc = true;
                  break;
               }
            case 5:
               if (!this->exit_parking_app())
               {
                  continue;
               }
               else
               {
                  esc = true;
                  break;
               }
            default:
               continue;
            }
         }

         return this->isEmpty() == true ? 1 : 0;
      }
      else
      {
         return 1;
      }
   }

  
   bool Parking::isEmpty() const
   {
      if (this->m_indet == -1)
      {
         return true;
      }
      else if (this->n_file != nullptr && this->m_indet >= 0)
      {
         return false;
      }
      else if (this->n_file == nullptr && this->m_indet == 0)
      {
         return false;
      }
      else
      {
         return true;
      }
   }

   void Parking::status() const
   {
      std::cout << "****** Seneca Valet Parking ******" << std::endl;
   }

  
   void Parking::park_vehicle() const
   {
      switch (this->vehicle_choosing_menu.run())
      {
      case 1:
         std::cout << "Parking Car" << std::endl;
         break;
      case 2:
         std::cout << "Parking Motorcycle" << std::endl;
         break;
      case 3:
         std::cout << "Cancelled parking" << std::endl;
         break;
      default:
         break;
      }
   }

   bool Parking::close_parking() const
   {
      std::cout << "Closing Parking" << std::endl;
      return true;
   }
  
   void Parking::return_vehicle() const
   {
      std::cout << "Returning Vehicle" << std::endl;
   }

  
   void Parking::list_parked_vehicles() const
   {
      std::cout << "Listing Parked Vehicles" << std::endl;
   }

  

   
   bool Parking::exit_parking_app() const
   {
      char response[16];

      std::cout << "This will terminate the program!" << std::endl;
      std::cout << "Are you sure? (Y)es/(N)o: ";

      while (std::cin.getline(response, 15, '\n'))
      {
         try
         {
            if (std::strlen(response) == 1)
            {
               if (std::strncmp(response, "Y", 1) == 0 ||
                  std::strncmp(response, "y", 1) == 0 ||
                  std::strncmp(response, "N", 1) == 0 ||
                  std::strncmp(response, "n", 1) == 0)
               {
                  throw true;
               }
               else
               {
                  throw false;
               }
            }
            else
            {
               throw false;
            }

         }
         catch (bool glove)
         {
            if (glove)
            {
               break;
            }
            else
            {
               std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
               continue;
            }
         }
         catch (const std::exception & st)
         {
            std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            continue;
         }
      }

      if (std::strncmp(response, "y", 1) == 0)
      {
         std::cout << "Exiting program!" << std::endl;
         return true;
      }
      else
      {
         return false;
      }

   }
   void Parking::save_data_file() const
   {
      if (!this->isEmpty())
      {
         std::cout << "Saving data into " << this->n_file << std::endl;
      }
   }

   void Parking::set_invalid()
   {
      this->m_indet = -1;
      this->parking_menu_options = Menu();
      this->parking_menu_options = Menu();
      this->n_file = nullptr;
   }

   
   bool Parking::load_data_file()
   {
      if (!this->isEmpty())
      {
         std::cout << "loading data from " << this->n_file << std::endl;
         return true;
      }
      else
      {
         return false;
      }
   }

   
  
}