/*
Name: Sunchit Singh
Email: sunchit-singh@myseneca.ca
Student ID: 169146214
Date: November 24, 2022
Section: OOP244NBB
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_HTMLTEXT_H_
#define SDDS_HTMLTEXT_H_
#include <iostream>
#include "Text.h"
using namespace std;
namespace sdds {

   class HtmlText : public Text {
   private:
      char* m_title{};

   public:
      HtmlText(const char* title = nullptr);
      HtmlText(const HtmlText& toCopyFrom);
      HtmlText& operator=(const HtmlText& toCopyFrom);
      virtual ~HtmlText();

      std::ostream& write(std::ostream& ostr = std::cout)const;
   };
}

#endif