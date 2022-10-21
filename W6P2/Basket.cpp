/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : October 17, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Basket.h"

namespace sdds {
   Basket::Basket() {
      m_fruits = nullptr;
      m_size = 0;
      m_price = 0;
   }

   Basket::Basket(Fruit fruitArr[], int size, double price) {
      if (fruitArr && size > 0 && price > 0) {
         m_size = size;
         m_price = price;
         m_fruits = new Fruit[m_size];
         
         for (int i = 0; i < size; i++) {
            strcpy(m_fruits[i].m_name, fruitArr[i].m_name);
            m_fruits[i].m_qty = fruitArr[i].m_qty;
         }
      }
   }

   Basket::Basket(const Basket& toCopyFrom) {

   }

   Basket& Basket::operator=(const Basket& toCopyFrom) {
      // TODO: insert return statement here
   }

   Basket::~Basket() {

   }

   void Basket::setPrice(double price) {

   }

   Basket::operator bool() {

   }

   Basket& Basket::operator+=(const Fruit rightOperand) {
      // TODO: insert return statement here
   }

   istream& operator<<(istream& istr, const Basket& rightOperand) {
      // TODO: insert return statement here
   }
}