// Re-submitting the part 1 of workshop 1 because I forgot to add the details mentioned below.

/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 13, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"

namespace sdds {
   FILE* sfptr = nullptr;
   bool openFileForRead() {
      sfptr = fopen(SHOPPING_DATA_FILE, "r");
      return sfptr != NULL;
   }

   bool openFileForOverwrite() {
      sfptr = fopen(SHOPPING_DATA_FILE, "w");
      return sfptr != NULL;
   }

   void closeFile() {
      if (sfptr) fclose(sfptr);
   }

   bool freadShoppingRec(ShoppingRec* rec) {
      int flag = 0;
      bool success = fscanf(sfptr, "%[^,],%d,%d\n",
         rec->m_title, &rec->m_quantity, &flag) == 3;
      rec->m_bought = !!flag;
      return success;
   }

   void fwriteShoppintRec(const ShoppingRec* rec) {
      fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
   }
}