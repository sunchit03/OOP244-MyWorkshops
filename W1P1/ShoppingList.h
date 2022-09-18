// Re-submitting the part 1 of workshop 1 because I forgot to add the details mentioned below.

/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 13, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SHOPPINGLIST_H_
#define SDDS_SHOPPINGLIST_H_

namespace sdds {
   bool loadList();
   void displayList();
   void removeBoughtItems();
   void removeItem(int index);
   bool saveList();
   void clearList();
   void toggleBought();
   void addItemToList();
   void removeItemfromList();
   bool listIsEmpty();
}
#endif