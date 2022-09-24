#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#include "Utils.h"
namespace sdds {

   const int PC_CHARS = 3;
   const char FILE_NAME[] = "PCpopulations.csv";

   struct PCpopulation {
      char* m_PC;
      int *m_population;
   };

   struct Counter {
      int recordsCnt;
   };

   //extern struct PCpopulation *PCpop;

   bool readPCP(PCpopulation& PCp, const char* filename);

   bool load(const char* filename);

   void display(void);

   void deallocateMemory(void);

}
#endif // SDDS_POPULATION_H_