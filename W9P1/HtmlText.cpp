/*
Name: Sunchit Singh
Email: sunchit-singh@myseneca.ca
Student ID: 169146214
Date: November 24, 2022
Section: OOP244NBB
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "HtmlText.h"
#include "Utils.h"
namespace sdds {
   HtmlText::HtmlText(const char* title) {
      m_title = alcpy(title);
   }

   HtmlText::HtmlText(const HtmlText& toCopyFrom): Text(toCopyFrom) {
      m_title = alcpy(toCopyFrom.m_title);
   }

   HtmlText& HtmlText::operator=(const HtmlText& toCopyFrom) {
      if (this != &toCopyFrom) {
         Text::operator=(toCopyFrom);

         delete[] m_title;
         m_title = alcpy(toCopyFrom.m_title);
      }
      return *this;
   }

   HtmlText::~HtmlText() {
      delete[] m_title;
      m_title = nullptr;
   }

   std::ostream& HtmlText::write(std::ostream& ostr) const
   {
      bool MS = false;
      ostr << "<html><head><title>";
      if (m_title) {
         ostr << m_title;
      }
      else {
         ostr << "No Title";
      }
      
      ostr << "</title></head>" << endl << "<body>" << endl;

      if (m_title) {
         ostr << "<h1>" << m_title << "</h1>" << endl;
      }

      int i = 0;
      while (operator[](i)) {
         char ch{};
         ch = operator[](i);
          if (ch == '<') {
            ostr << "&lt;";
            MS = false;
         }
         else if (ch == '>') {
            ostr << "&gt;";
            MS = false;
         }
         else if (ch == '\n') {
            ostr << "<br />" << endl;
            MS = false;
         }
         else if (ch == ' ') {
            if (MS) {
               ostr << "&nbsp;";
            }
            else {
               ostr << " ";
               MS = true;
            }
         }
         else {
            ostr << ch;
            MS = false;
         }
          i++;
      }



      /*for (int i = 0; i < m_length; i++) {
         if (operator[](i) == '<') {
            ostr << "&lt;";
            MS = false;
         }
         else if (operator[](i) == '>') {
            ostr << "&gt;";
            MS = false;
         }
         else if (operator[](i) == '\n') {
            ostr << "<br />" << endl;
            MS = false;
         }
         else if (operator[](i) == ' ') {
            if (MS) {
               ostr << "&nbsp;";
            }
            else {
               ostr << " ";
               MS = true;
            }
         }
         else {
            ostr << operator[](i);
            MS = false;
         }
      }*/

      ostr << "</body>" << endl << "</html>";

      return ostr;
   }
}