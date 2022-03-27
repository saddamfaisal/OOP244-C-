


//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           25/07/2020

#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include "Menu.h"

namespace sdds
{
   class Parking
   {
   private:
      char* n_file{ nullptr };
      int m_indet{ 0 };
      Menu parking_menu_options{ Menu() };
      Menu vehicle_choosing_menu{ Menu() };

      bool isEmpty() const;
      void status() const;
      void park_vehicle() const;
      void return_vehicle() const;
      void list_parked_vehicles() const;
      bool close_parking() const;
      bool exit_parking_app() const;
      bool load_data_file();
      void save_data_file() const;

      void set_invalid();

   public:
      Parking();
      Parking(const char*);
      ~Parking();

      Parking(const Parking&) = delete;
      Parking& operator=(const Parking&) = delete;

      int run();
   };
} 

#endif 