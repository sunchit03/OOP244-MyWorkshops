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
         PCp.PC = new char(strlen(tempStr) + 1);
         PCp.population = new int(tempInt);

         strcpy(PCp.PC, tempStr);

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

}