#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {

   const int PC_CHARS = 3;

   struct PCpopulation {
      char* PC;
      int* population;
   };

   bool load(const char* filename);
}
#endif // SDDS_POPULATION_H_