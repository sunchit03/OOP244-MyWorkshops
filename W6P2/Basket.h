/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : October 17, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_
#include <iostream>
using namespace std;
namespace sdds {

   struct Fruit {
      char m_name[30 + 1]; // the name of the fruit
      double m_qty;        // quantity in kilograms
   };

   class Basket {
   private:
      Fruit* m_fruits{};
      int m_size = 0;
      double m_price = 0;

   public:
      Basket();
      Basket(Fruit fruitArr[], int size, double price);
      Basket(const Basket& toCopyFrom);
      Basket& operator=(const Basket& toCopyFrom);
      ~Basket();
      void setPrice(double price);
      operator bool();
      Basket& operator+=(const Fruit rightOperand);
      friend ostream& operator<<(ostream& istr, const Basket& rightOperand);
   };
   
}

#endif