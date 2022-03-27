
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           10/6/2020
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Cargo.h"
#include "Train.h"

using namespace std;
namespace sdds {
   /*void initialize(const char* name, int id): a modifier that receives the train name and the id as parameters.
   If the parameters are invalid, set the object to an empty state (choose an empty state that makes sense;
   possible empty states could be a 0 or negative values for the id, or an empty string for the name).=If parameters are valid,
   copy them into the attributes.
   If the name is too long, accept only the first MAX_NAME characters. Make sure to initialize the cargo attribute to null.*/


   void Train::initialize(const char* newName, int newId)
   {
      if (newName == nullptr || newName[0] == '\0' || newId < 1) {
         name[0] = '\0';
         id = 0;

      }
      else {
         strcpy(name, newName);
         id = newId;
      }
      cargo = nullptr;


   }


   /// bool isValid() const: a query that returns true if the object contains valid data, false otherwise(check for empty state).



   bool Train::isValid() const
   {

      bool validCheck = false;

      if (id != 0) {
         validCheck = true;
      }
      return validCheck;


   }
   //void loadCargo(Cargo car) : stores the parameter in the current instance.
   //This function should dynamically allocate memory for a single instance of
   //Cargo to the cargo pointer data member then copy over the values from the parameter to it.

   void Train::loadCargo(Cargo car)
   {

      cargo = new Cargo;
      *cargo = car;


   }
   //removes the existing cargo from the train by deallocating the memory used. Then set the pointer to nullptr.

   void Train::unloadCargo()
   {
      delete cargo;
      cargo = nullptr;
   }

   void Train::display() const
   {
      cout << "***Train Summary***" << endl;
      if (!isValid()) {
         cout << "This is an invalid train." << endl;
      }
      else if (isValid() {
        
         
        // cout << "Name: " << name << endl;
         
         
         //cout<< " ID: " << id <<endl;
         
         if (cargo == nullptr) {
            cout << "No cargo on this train." << endl;
         }
         else
         {
            cout << "Cargo: " << cargo->description << endl <<" Weight: " << cargo->weight << endl;
         }
      }
   }
}