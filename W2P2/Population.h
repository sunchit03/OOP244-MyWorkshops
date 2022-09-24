/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 21, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
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

   bool load(const char* filename);

   void display(void);

   void deallocateMemory(void);

}
#endif // SDDS_POPULATION_H_