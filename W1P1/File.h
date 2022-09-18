// Re-submitting the part 1 of workshop 1 because I forgot to add the details mentioned below.

/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 13, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include "ShoppingRec.h"

namespace sdds {
   const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";

   bool openFileForRead();
   bool openFileForOverwrite();
   void closeFile();
   bool freadShoppingRec(ShoppingRec* rec);
   void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif