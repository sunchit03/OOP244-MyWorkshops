#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {

   PCpopulation* PCpop = nullptr;
   

   bool readPCP(PCpopulation& PCp, const char* filename) {
      char tempStr[PC_CHARS + 1] = "";
      int tempInt = 0;
      bool retVal = false;

      if (fscanf(fptr, "%[^,],%d\n", tempStr, &tempInt) == 2) {
         PCp.m_PC = new char[strlen(tempStr) + 1];
         PCp.m_population = new int(tempInt);
         strcpy(PCp.m_PC, tempStr);

         retVal = true;
      }
      return retVal;
   }


   bool load(const char* filename) {

      bool check = true;
      int count = 0;
      bool retVal{};
      int recCount;
      
      if (openFile(filename)) {
         recCount = noOfRecords();
         PCpop = new PCpopulation[recCount];

         for (int i = 0; i < recCount && check; i++) {
            check = readPCP(PCpop[i], filename);
            count = i;
         }

         if (count != recCount && !check) {
            cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            retVal = false;
         }
         else {
            retVal = true;
         }
      }
      else {
         cout << "Could not open data file : " << filename << endl;
         retVal = false;
      }
      return retVal;
   }

   void display() {
      //int recCount;
      int tempPop;
      int totalPop = 0;
      cout << "Postal Code : population" << endl;
      cout << "-------------------------" << endl;

      for (int i = 0; i < 15; i++) {

         for (int j = i + 1; j < 15; j++) {
            if (*PCpop[i].m_population > *PCpop[j].m_population) {

               tempPop = *PCpop[i].m_population;
               *PCpop[i].m_population = *PCpop[j].m_population;
               *PCpop[j].m_population = tempPop;
            }
         }
      }

      for (int i = 0; i < 15; i++) {
         cout << i + 1 << "- " << PCpop[i].m_PC << ":  " << *PCpop[i].m_population << endl;
         totalPop += *PCpop[i].m_population;
      }

      cout << "-------------------------" << endl;
      cout << "Population of Canada : " << totalPop << endl;
   }

   void deallocateMemory() {

      for (int i = 0; i < 15; i++) {
         delete[] PCpop[i].m_PC;
         PCpop[i].m_PC = nullptr;
         delete PCpop[i].m_population;
         PCpop[i].m_population = nullptr;
      }

      delete[] PCpop;
      PCpop = nullptr;
   }
}