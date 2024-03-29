/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  File.cpp
// Version 1.0
// Date  2022/09/17
// Author   Fardad Soleimanloo
// Description
// This file is incomplete and to be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
#include "Utils.h"

namespace sdds {
   FILE* fptr;
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   // Finds and returns the number of records kept in the file 
   // to be used for the dynamic memory allocation of the records in the program
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   // Closes the open file
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   // Reads from the file and dynamically allocates in case of success
   bool readFile(PCpopulation& PCp, const char filename[]) {
      char tempStr[PC_CHARS + 1] = "";
      int tempInt = 0;
      bool retVal = false;

      if (fscanf(fptr, "%[^,],%d\n", tempStr, &tempInt) == 2) {            // successfully read and stored
         PCp.m_PC = new char[strlen(tempStr) + 1];                         // DMA
         PCp.m_population = new int(tempInt);                              // DMA
         strcpy(PCp.m_PC, tempStr);

         retVal = true;
      }
      return retVal;
   }
}