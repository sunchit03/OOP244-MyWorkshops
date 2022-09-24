/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 21, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Assessment.h"
#include "Utils.h"
namespace sdds {

   // reads the value at the top of the file indicating the number of records
   // returns true if read is successful, otherwise false
   bool read(int& value, FILE* fptr) {
      bool check{};
      check = (fscanf(fptr, "%d\n", &value) == 1);
      return check;
   }

   // reads the mark
   // returns true if read is successful, otherwise false
   bool read(double& value, FILE* fptr) {
      bool check{};
      check = (fscanf(fptr, "%lf", &value) == 1);
      return check;
   }

   // reads the course title
   // returns true if read is successful, otherwise false
   bool read(char* cstr, FILE* fptr) {
      bool check{};
      check = (fscanf(fptr, ",%60[^\n]\n", cstr) == 1);
      return check;
   }

   // reads values and allocates them dynamically
   // returns true if read is successful, otherwise false
   bool read(Assessment& asmnt, FILE* fptr) {
      bool check{};
      double mark;
      char title[61] = "";
      check = read(mark, fptr) && read(title, fptr);

      if (check) {
         asmnt.m_mark = new double(mark);
         asmnt.m_title = new char[strlen(title) + 1];
         strcpy(asmnt.m_title, title);
      }

      return check;
   }

   // deallocates the dynamic memory used
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

   // reads and returns the total number of records
   // in case of success, otherwise 0
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
      if (lastval != cnt && !check) {        // failure

         freeMem(aptr, lastval);
         returnVal = 0;
      }
      else {                                 // success
         returnVal = cnt;
      }
      return returnVal;
   }
}