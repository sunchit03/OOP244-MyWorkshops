/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : October 3, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TAGLIST_H_
#define SDDS_TAGLIST_H_
#include "NameTag.h"

namespace sdds {

   class TagList {
      class NameTag* m_NT;

      int m_totalNames;

   public :
      void set();

      void set(int num);

      void add(const NameTag& nt);

      void print();

      void cleanup();
   };

}

#endif
