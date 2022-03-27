


//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           25/07/2020


#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H

#include <iostream>

namespace sdds
{
   class ReadWritable
   {
   private:
      bool commaSepFlag = false;
   public:
      ReadWritable();

      bool isCsv()const;

      void setCsv(bool value);

      virtual ~ReadWritable();

      virtual std::istream& read(std::istream&) = 0;
      virtual std::ostream& write(std::ostream&) const = 0;

   };
   std::ostream& operator<<(std::ostream&, const ReadWritable&);

   std::istream& operator>>(std::istream&, ReadWritable&);
}

#endif 