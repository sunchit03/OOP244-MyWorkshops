#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {

   const int PC_CHARS = 3;

   struct PCpopulation {
      char* PC;
      int* population;
   };

   bool readPCP(PCpopulation& PCp, const char* filename);

   bool load(const char* filename);

   void display(void);

   void deallocateMemory(void);
}
#endif // SDDS_POPULATION_H_