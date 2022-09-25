/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 25, 2022
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

   int actualReads = 0;
   
   bool load(const char* filename) {
      bool check = true;
      bool retVal{};
      int records;
      
      if (openFile(filename)) {                             // file successfully opened
         records = noOfRecords();
         PCpop = new PCpopulation[records];

         for (int i = 0; i < records && check; i++) {
            if (readFile(PCpop[i], filename)) {             // successfully read
               actualReads++;
               check = true;
            }
            else {                                          // failure
               check = false;
            }
         }

         if (actualReads != records && !check) {            // records do not match
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


      // arranging in ascending order of population
      for (int i = 0; i < actualReads; i++) {

         for (int j = i + 1; j < actualReads; j++) {
            if (*PCpop[i].m_population > *PCpop[j].m_population) {

               tempPop = *PCpop[i].m_population;
               *PCpop[i].m_population = *PCpop[j].m_population;
               *PCpop[j].m_population = tempPop;

               strcpy(tempPC, PCpop[i].m_PC);
               strcpy(PCpop[i].m_PC, PCpop[j].m_PC);
               strcpy(PCpop[j].m_PC, tempPC);
            }
            else if (*PCpop[i].m_population == *PCpop[j].m_population) {

               // in case of equal population
               //arranging in alphabetical order of postal code
               
               if (strcmp(PCpop[i].m_PC, PCpop[j].m_PC) > 0) {

                  strcpy(tempPC, PCpop[i].m_PC);
                  strcpy(PCpop[i].m_PC, PCpop[j].m_PC);
                  strcpy(PCpop[j].m_PC, tempPC);
               }
            }
         }
      }

      for (int i = 0; i < actualReads; i++) {
         cout << i + 1 << "- " << PCpop[i].m_PC << ":  " << *PCpop[i].m_population << endl;
         totalPop += *PCpop[i].m_population;
      }

      cout << "-------------------------" << endl;
      cout << "Population of Canada: " << totalPop << endl;
   }

   void deallocateMemory() {

      for (int i = 0; i < actualReads; i++) {
         delete PCpop[i].m_population;
         PCpop[i].m_population = nullptr;

         delete[] PCpop[i].m_PC;
         PCpop[i].m_PC = nullptr;

      }

      delete[] PCpop;
      PCpop = nullptr;
   }
}