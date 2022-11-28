/*
Name: Sunchit Singh
Email: sunchit-singh@myseneca.ca
Student ID: 169146214
Date: November 24, 2022
Section: OOP244NBB
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Text.h"

namespace sdds {

   const char& Text::operator[](int index) const {
      return m_content[index];
   }

   Text::Text() {
      m_content = nullptr;
   }

   Text::Text(const Text& toCopyFrom) {
      delete[] m_content;
      m_content = nullptr;
      operator=(toCopyFrom);
   }

   Text& Text::operator=(const Text& toCopyFrom) {
      if (this != &toCopyFrom) {
         delete[] m_content;
         m_content = nullptr;

         if (toCopyFrom.m_content && toCopyFrom.m_content[0]) {
            m_content = alcpy(toCopyFrom.m_content);
         }
      }
      return *this;
   }

   Text::~Text() {
      delete[] m_content;
      m_content = nullptr;
   }

   std::istream& Text::read(std::istream& istr) {
      delete[] m_content;
      m_content = nullptr;

      int length = getFileLength(istr);

      m_content = new char[length + 1];

      bool flag = true;
      for (int i = 0; i < length + 1 && flag; i++) {
         char ch = ' ';

         if (istr.get(ch)) {
            if (ch) {
               m_content[i] = ch;
            }
         }
         else {
            m_content[i] = 0;
            flag = false;
         }

      }

      if (m_content && m_content[0]) {
         istr.clear();
      }

      return istr;
   }

   std::ostream& Text::write(std::ostream& ostr) const {
      if (m_content) {
         ostr << m_content;
      }
      return ostr;
   }

   std::istream& operator>>(std::istream& istr, Text& rightOperand) {
      return rightOperand.read(istr);
   }

   std::ostream& operator<<(std::ostream& ostr, const Text& rightOperand) {
      return rightOperand.write(ostr);
   }
}

