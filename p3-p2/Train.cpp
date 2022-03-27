
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


   };


   /// bool isValid() const: a query that returns true if the object contains valid data, false otherwise(check for empty state).



   bool Train::isValid() const
   {

      bool validCheck = false;

      if (id != 0) {
         validCheck = true;
      }
      return validCheck;


   };
   //void loadCargo(Cargo car) : stores the parameter in the current instance.
   //This function should dynamically allocate memory for a single instance of
   


   
    void Train::loadCargo(Cargo car)
    {
      delete cargo;
      cargo = new Cargo;
     *cargo = car;
    };
   //removes the existing cargo from the train by deallocating the memory used. Then set the pointer to nullptr.
   //swap the cargo between the two trains only if both trains are 
   //valid and carry valid cargo. Return `true` if a change has 
   //been made, `false` otherwise.
   bool Train:: swapCargo(Train& swaptrain) {
   
      bool right = false;
      if (!(isValid() && swaptrain.isValid())) {

         Cargo temp;
         temp.initialize(Cargo->getDesc(), Cargo->getWeight());
         Cargo->initialize(swaptrain.Cargo->getDesc(), swaptrain.Cargo->getWeight());
         swaptrain.Cargo->initialize(temp.getDesc(), temp.getWeight());
      
         right = true;
      
      }
   
      return right;

   
   
   
   };

  // increases the carried cargo by `weight` tonnes** only** if
  // the current train is valid, carries valid cargoand the new weight 
   //doesn't exceed `MAX_WEIGHT`. If the new cargo exceeds the capcity,
   //do not accept more than capacity. Return `true` if a change has been made,
   //`false` otherwise.

   bool Train::increaseCargo(double weight) {

      bool right = false;
      {
         if (Cargo->getWeight() + weight > MAX_WEIGHT)
            Cargo->setWeight(MAX_WEIGHT);

         else
            Cargo->setWeight(newWei);
         right = true;
      }
   }
      return right;
   
   
   };



   bool  Train::decreaseCargo(double weight) {
      bool right = false;
      if (!isValid() && Cargo->getWeight() > MIN_WEIGHT) {
         if ((Cargo->getWeight() - weight) < MIN_WEIGHT)
         Cargo->setWeight(MIN_WEIGHT);
         else
            Cargo->setWeight(Cargo->getWeight() - weight);
         right = true;
      }

      return right;
   };

   void Train::unloadCargo()
   {
      delete cargo;
      cargo = nullptr;
   };

   /* a query that prints to the screen the content of the current object. 
   The information is printed as follow:
  - if the train is an invalid object, print
  ```txt
  ***Train Summary***
  This is an invalid train.
  ``` 
  - if the train carries no cargo, print
  ```txt
  ***Train Summary***
      Name: [NAME]
        ID: [ID]
  No cargo on this train.
  ```
  - otherwise, print
  ```txt
  ***Train Summary***
      Name: [NAME]
        ID: [ID]
     Cargo: [CARGO_DESCRIPTION]
    Weight: [WEIGHT]
  ```
  - The labels should be printed on a field of size 10 aligned to the right,
  and the weight should be printed with 2 significant digits.



   */
   void Train::display() const
   {
      cout << "***Train Summary***" << endl;
      if (isValid()) {
         cout << "This is an invalid train." << endl;
      }
      else {
         cout << "Name: " << name << endl << "ID: " << id << endl;
         if (cargo == nullptr) {
            cout << "No cargo on this train." << endl;
         }
         else
         {
            cout << "   Cargo: " << cargo->getDesc() << endl;
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << "  Weight: " << cargo->getWeight() << endl;
            cout.unsetf(ios::fixed);
            cout.precision(6);
         }
      }
   };
}

