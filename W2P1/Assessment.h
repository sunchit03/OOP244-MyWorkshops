/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 20, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_ASSESSMENT_H_
#define SDDS_ASSESSMENT_H_

namespace sdds {

   struct Assessment {
      double* m_mark;
      char* m_title;
   };

   bool read(int& value, FILE* fptr);

   bool read(double& value, FILE* fptr);

   bool read(char* cstr, FILE* fptr);

   bool read(Assessment& asmnt, FILE* fptr);

   void freeMem(Assessment*& aptr, int size);

   int read(Assessment*& aptr, FILE* fptr);
}

#endif
#pragma once
