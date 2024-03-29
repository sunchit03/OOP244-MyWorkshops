/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : October 3, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "TagList.h"
#include "NameTag.h"
#include "Utils.h"

using namespace std;
namespace sdds {

   int added = 0;
   TagList tl;

   void TagList::set() {
      tl.m_NT = nullptr;
   }

   void TagList::set(int num) {
      tl.cleanup();

      tl.m_NT = new NameTag[num];

      tl.m_totalNames = num;
   }

   void TagList::add(const NameTag& nt) {
      
      strcpy(tl.m_NT[added].m_name, nt.m_name);

      added ++;

   }

   void TagList::print() { 

      int maxChars = strlen(tl.m_NT[0].m_name);

      for (int i = 0; i < tl.m_totalNames; i++) {

         if (maxChars < strlen(tl.m_NT[i].m_name)) {
            maxChars = strlen(tl.m_NT[i].m_name);
         }
      }

      for (int i = 0; i < tl.m_totalNames; i++) {

         for (int j = 0; j < maxChars + 4; j++) {
            cout << "*";
         }
         cout << endl;

         cout << "* ";

         cout.width(maxChars);
         cout.fill(' ');
         cout.setf(ios::left);
         cout << tl.m_NT[i].m_name << " *" << endl;

         cout.fill(' ');
         cout.unsetf(ios::left);


         for (int j = 0; j < maxChars + 4; j++) {
            cout << "*";
         }
         cout << endl;
      }
   }

   void TagList::cleanup() {
      delete[] tl.m_NT;

      tl.m_NT = nullptr;
      tl = {};
   }

}