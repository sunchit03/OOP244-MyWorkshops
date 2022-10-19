/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : October 17, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
using namespace std;
namespace sdds {
   class Numbers {
      double* m_numbers{};
      char* m_filename{};
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void deallocate();
      void setFilename(const char* filename);

      Numbers& sort(bool ascending);
   public:
      Numbers();
      Numbers(const char* filename);
      double average()const;
      double max()const;
      double min()const;
      ~Numbers();

      Numbers(const Numbers& toCopyFrom);
      Numbers& operator=(const Numbers& toCopyFrom);
      Numbers operator-()const;
      Numbers operator+()const;

      int numberCount()const;
      bool load();
      void save();

      Numbers& operator+=(const double leftOperand);
      ostream& display(ostream& ostr)const;
   };
   ostream& operator<<(ostream& os, const Numbers& N);
   istream& operator>>(istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

