/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 28, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "NameTag.h"
#include "Utils.h"

using namespace std;
namespace sdds {

   NameTag nt;

   void sdds::NameTag::set(const char* name) {

      nt.cleanup();

      strcpy(m_name, name);
   }

   extern NameTag nt;

   void NameTag::cleanup() {
      strcpy(m_name, "");
   }

}


