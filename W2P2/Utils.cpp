/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 24, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "Utils.h"
#include "Population.h"
#include "File.h"
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

   bool readPCP(PCpopulation& PCp, const char* filename) {
      char tempStr[PC_CHARS + 1] = "";
      int tempInt = 0;
      bool retVal = false;

      if (fscanf(fptr, "%[^,],%d\n", tempStr, &tempInt) == 2) {
         PCp.m_PC = new char[strlen(tempStr) + 1];
         PCp.m_population = new int (tempInt);
         strcpy(PCp.m_PC, tempStr);

         retVal = true;
      }
      return retVal;
   }
}