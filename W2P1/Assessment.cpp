/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 20, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Assessment.h"
#include "Utils.h"

namespace sdds {

   bool read(int& value, FILE* fptr) {
      bool check{};
      check = (fscanf(fptr, "%d\n", &value) == 1);
      return check;
   }

   bool read(double& value, FILE* fptr) {
      bool check{};
      check = (fscanf(fptr, "%lf", &value) == 1);
      return check;
   }

   bool read(char* cstr, FILE* fptr) {
      bool check{};
      check = (fscanf(fptr, ",%60[^\n]\n", cstr) == 1);
      return check;
   }

   bool read(Assessment& asmnt, FILE* fptr) {
      bool check{}, check1{}, check2{};
      double mark;
      char title[61] = "";
      check1 = read(mark, fptr);
      check2 = read(title, fptr);

      check = check1 && check2;

      if (check) {
         asmnt.m_mark = new double(mark);
         asmnt.m_title = new char[strlen(title) + 1];
         strcpy(asmnt.m_title, title);
      }

      return check;
   }

   void freeMem(Assessment*& aptr, int size) {

      for (int i = 0; i < size; i++) {
         delete aptr[i].m_mark;
         aptr[i].m_mark = nullptr;

         delete[] aptr[i].m_title;
         aptr[i].m_title = nullptr;
      }

      delete[] aptr;
      aptr = nullptr;

   }

   int read(Assessment*& aptr, FILE* fptr) {
      int cnt;
      int lastval;
      int returnVal;
      bool check = true;

      read(cnt, fptr);
      aptr = new Assessment[cnt];

      for (int i = 0; i < cnt && check; i++) {
         check = read(aptr[i], fptr);
         lastval = i;
      }
      if (!check) {
         freeMem(aptr, lastval);

         returnVal = 0;
      }
      else {
         returnVal = cnt;
      }
      return returnVal;
   }
}