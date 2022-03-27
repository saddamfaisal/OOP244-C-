


//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           28/07/2020



#ifndef VALIDATE_H
#define VALIDATE_H

template <typename T>
bool validate(const T&& min, const T testValue[], int element_number, bool results[])
{


   bool check = true;

   for (int index = 0; index < element_number; index++)
   {
      if (testValue[index] <= min)
      {
         check = false;
      }
      results[index] = (testValue[index] >= min);
   }

   return check;
}

#endif // VALIDATE_H #pragma once

