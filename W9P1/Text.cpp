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
      /*char retVal{};
      if (m_content[index]) {
         retVal = m_content[index];
      }*/
      return m_content[index];
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
            m_content = alcpy(toCopyFrom.m_content);
            /*m_content = new char[strlen(toCopyFrom.m_content) + 1];
            strcpy(m_content, toCopyFrom.m_content);*/
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

      int length = getFileLength(istr);
      
      char* tempContent = new char[length + 1];

      //m_content = new char [length + 1];
      int index = -1;
      for (int i = 0; i < length && index < 0; i++) {
         char ch = ' ';
         
         if (istr.get(ch)) {
            tempContent[i] = ch;
            //m_content[i] = ch;
         }
         else {
            index = i;
         }
      }
      if (index >= 0) {
         tempContent[index] = 0;
         //m_content[index] = '\0';
      }
      else {
         tempContent[length - 1] = 0;
         //m_content[length - 1] = '\0';
      }

      m_content = alcpy(tempContent);
      /*for (int i = 0; tempContent && i < strlen(tempContent); i++) {
         m_content[i] = tempContent[i];
      }*/
 
      delete[] tempContent;
      tempContent = nullptr;

      if (m_content && m_content[0]) {
         istr.clear();
      }

      return istr;
   }

   std::ostream& Text::write(std::ostream& ostr) const {
      if (m_content) {
         for (int i = 0; i < strlen(m_content); i++) {
            ostr << m_content[i];
         }
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

