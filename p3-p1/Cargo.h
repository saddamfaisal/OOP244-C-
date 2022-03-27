
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           10/6/2020

#pragma once

#include <iostream>
#include <cstring> 

#ifndef SDDS_CARGO_H
#define SDDS_CARGO_H

namespace sdds {

   const int MAX_DESC = 20;
   struct Cargo {
      char description[MAX_DESC];
      double weight;
   };

}
#endif