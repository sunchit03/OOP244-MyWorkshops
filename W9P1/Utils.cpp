/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : November 15, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <string>
#include "Utils.h"
using namespace std;
namespace sdds {
   int strlen(const char* str) {
      int len = 0;
      while (str[len]) {
         len++;
      }
      return len;
   }
   void strcpy(char* des, const char* src, int len) {
      int i;
      for (i = 0; src[i] && (len < 0 || i < len); i++) {
         des[i] = src[i];
      }
      des[i] = 0; // turning the char array des in to a cString by null terminating it.
   }
   int strcmp(const char* s1, const char* s2) {
      int i;
      for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
      return s1[i] - s2[i];
   }

   unsigned getFileLength(std::istream& is) {
      unsigned len{};
      if (is) {
         // save the current read position
         std::streampos cur = is.tellg();
         // go to the end
         is.seekg(0, std::ios::end);
         // tell what is the positions (end position = size)
         len = unsigned(is.tellg());
         // now go back to where you were.
         is.seekg(cur);
      }
      return len;
   }

   char* alcpy(const char* cstr) {
      char* newStr{};
      if (cstr) {
         newStr = new char[strlen(cstr) + 1];
         strcpy(newStr, cstr);
      }
      return newStr;
   }

   char* getDynCstr(std::istream& istr) {
      char* cstr{};
      string str;
      getline(istr, str, '\n');
      if (istr) cstr = alcpy(str.c_str());
      return cstr;
   }


}