/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 21, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"
#include "Utils.h"

using namespace std;
namespace sdds {

   PCpopulation* PCpop = nullptr;
   Counter cnt{};
   

   //bool readPCP(PCpopulation& PCp, const char* filename) {
   //   char tempStr[PC_CHARS + 1] = "";
   //   int tempInt = 0;
   //   bool retVal = false;

   //   if (fscanf(fptr, "%[^,],%d\n", tempStr, &tempInt) == 2) {
   //      PCp.m_PC = new char[strlen(tempStr) + 1];
   //      PCp.m_population = new int(tempInt);
   //      strcpy(PCp.m_PC, tempStr);

   //      retVal = true;
   //   }
   //   return retVal;
   //}


   bool load(const char* filename) {

      bool check = true;
      int count = 0;
      bool retVal{};
      //int recCount;
      
      if (openFile(filename)) {
         cnt.recordsCnt = noOfRecords();
         PCpop = new PCpopulation[cnt.recordsCnt];

         for (int i = 0; i < cnt.recordsCnt && check; i++) {
            check = readPCP(PCpop[i], filename);
            count = i;
         }

         if (count != cnt.recordsCnt && !check) {
            cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            retVal = false;
         }
         else {
            retVal = true;
         }

         closeFile();
      }
      else {
         cout << "Could not open data file : " << filename << endl;
         retVal = false;
      }
      return retVal;
   }

   void display() {
      int tempPop;
      char tempPC[PC_CHARS + 1] = "";
      int totalPop = 0;

      cout << "Postal Code: population" << endl;
      cout << "-------------------------" << endl;

      for (int i = 0; i < cnt.recordsCnt; i++) {

         for (int j = i + 1; j < cnt.recordsCnt; j++) {
            if (*PCpop[i].m_population > *PCpop[j].m_population) {

               tempPop = *PCpop[i].m_population;
               *PCpop[i].m_population = *PCpop[j].m_population;
               *PCpop[j].m_population = tempPop;

               strcpy(tempPC, PCpop[i].m_PC);
               strcpy(PCpop[i].m_PC, PCpop[j].m_PC);
               strcpy(PCpop[j].m_PC, tempPC);
            }
            else if (*PCpop[i].m_population == *PCpop[j].m_population) {

               if (strcmp(PCpop[i].m_PC, PCpop[j].m_PC) > 0) {

                  strcpy(tempPC, PCpop[i].m_PC);
                  strcpy(PCpop[i].m_PC, PCpop[j].m_PC);
                  strcpy(PCpop[j].m_PC, tempPC);
               }
            }
         }
      }

      for (int i = 0; i < cnt.recordsCnt; i++) {
         cout << i + 1 << "- " << PCpop[i].m_PC << ":  " << *PCpop[i].m_population << endl;
         totalPop += *PCpop[i].m_population;
      }

      cout << "-------------------------" << endl;
      cout << "Population of Canada: " << totalPop << endl;
   }

   void deallocateMemory() {

      for (int i = 0; i < cnt.recordsCnt; i++) {
         delete PCpop[i].m_population;
         PCpop[i].m_population = nullptr;

         delete[] PCpop[i].m_PC;
         PCpop[i].m_PC = nullptr;

      }

      delete[] PCpop;
      PCpop = nullptr;
   }
}