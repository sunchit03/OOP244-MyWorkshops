/*
Name: Sunchit Singh
Email: sunchit-singh@myseneca.ca
Student ID: 169146214
Date: November 20, 2022
Section: OOP244NBB
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TEXT_H_
#define SDDS_TEXT_H_
#include <iostream>
#include "Utils.h"
namespace sdds {
   class Text {
   private:
      char* m_content{};

   protected:
      const char& operator[](int index)const;
      //int m_length = 0;

   public:
      Text();
      Text(const Text& toCopyFrom);
      Text& operator=(const Text& toCopyFrom);
      virtual ~Text();

      std::istream& read(std::istream& istr = std::cin);
      virtual std::ostream& write(std::ostream& ostr = std::cout)const;
   };

   std::istream& operator>>(std::istream& istr, Text& rightOperand);
   std::ostream& operator<<(std::ostream& ostr, const Text& rightOperand);
}
#endif // !SDDS_TEXT_H_
