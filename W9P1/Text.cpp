/*
Name: Sunchit Singh
Email: sunchit-singh@myseneca.ca
Student ID: 169146214
Date: November 20, 2022
Section: OOP244NBB
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Text.h"

namespace sdds {

   const char& Text::operator[](int index) const {
      char retVal{};
      if (m_content[index]) {
         retVal = m_content[index];
      }
      return retVal;
   }

   Text::Text() {
      m_content = nullptr;
   }

   Text::Text(const Text& toCopyFrom) {
      delete[] m_content;
      operator=(toCopyFrom);
   }

   Text& Text::operator=(const Text& toCopyFrom) {
      if (this != &toCopyFrom) {
         delete[] m_content;
         m_content = nullptr;

         if (toCopyFrom.m_content && toCopyFrom.m_content[0]) {
            m_content = new char[strlen(toCopyFrom.m_content) + 1];
            strcpy(m_content, toCopyFrom.m_content);
         }
         //m_length = toCopyFrom.m_length;
      }
      return *this;
   }

   Text::~Text() {
      delete[] m_content;
   }

   std::istream& Text::read(std::istream& istr) {
      delete[] m_content;
      m_content = nullptr;
      //m_length = getFileLength(istr);
      m_content = new char [getFileLength(istr) + 1];
      int index = -1;
      for (int i = 0; i < getFileLength(istr) && index < 0; i++) {
         char ch = ' ';
         
         if (istr.get(ch)) {
            m_content[i] = ch;
         }
         else {
            index = i;
         }
      }
 
      m_content[index] = '\0';
 

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

