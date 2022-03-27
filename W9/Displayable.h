
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           28/07/2020


#include <iostream>

#ifndef SICT_DISPLAYABLE_H_
#define SICT_DISPLAYABLE_H_
namespace sict{
  class Displayable{
  public:
    virtual std::ostream& display(std::ostream& os)const = 0;
  };

  std::ostream& operator<<(std::ostream& os, const Displayable& D);
}

#endif
