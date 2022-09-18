// Re-submitting the part 1 of workshop 1 because I forgot to add the details mentioned below.

/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 13, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SHOPPINGREC_H_
#define SDDS_SHOPPINGREC_H_

namespace sdds {
   const int MAX_TITLE_LENGTH = 50;

   struct ShoppingRec {
      char m_title[MAX_TITLE_LENGTH + 1];
      int m_quantity;
      bool m_bought;
   };

   ShoppingRec getShoppingRec();
   void displayShoppingRec(const ShoppingRec* shp);
   void toggleBoughtFlag(ShoppingRec* rec);
   bool isShoppingRecEmpty(const ShoppingRec* shp);
}
#endif