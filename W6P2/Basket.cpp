/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : October 17, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Basket.h"
#include "Utils.h"
namespace sdds {
   Basket::Basket() {
      m_fruits = nullptr;
      m_size = 0;
      m_price = 0;
   }

   Basket::Basket(Fruit fruitArr[], int size, double price) {
      if (fruitArr && size >= 2 && size <= 16 && price > 0) {
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
      operator=(toCopyFrom);
   }

   Basket& Basket::operator=(const Basket& toCopyFrom) {
      if (this != &toCopyFrom) {
         delete[] m_fruits;
         m_fruits = nullptr;
         m_price = toCopyFrom.m_price;
         m_size = toCopyFrom.m_size;

         m_fruits = new Fruit[m_size];
         for (int i = 0; i < m_size; i++) {
            strcpy(m_fruits[i].m_name, toCopyFrom.m_fruits[i].m_name);
            m_fruits[i].m_qty = toCopyFrom.m_fruits[i].m_qty;
         }
      }
      return *this;
   }

   Basket::~Basket() {
      delete[] m_fruits;
   }

   void Basket::setPrice(double price) {
      m_price = price;
   }

   Basket::operator bool() {
      return m_fruits && m_size >= 2 && m_size <= 16 && m_price > 0;
   }

   Basket& Basket::operator+=(const Fruit rightOperand) {
      Fruit* tempFruits = new Fruit[m_size + 1];
      
      for (int i = 0; i < m_size; i++) {
         strcpy(tempFruits[i].m_name, m_fruits[i].m_name);
         tempFruits[i].m_qty = m_fruits[i].m_qty;
      }
      delete[] m_fruits;

      strcpy(tempFruits[m_size].m_name, rightOperand.m_name);
      tempFruits[m_size].m_qty = rightOperand.m_qty;

      m_size++;

      m_fruits = tempFruits;

      return *this;
   }


   ostream& operator<<(ostream& istr, const Basket& rightOperand)
   {
      if (rightOperand.m_size) {
         istr << "Basket Content:" << endl;

         for (int i = 0; i < rightOperand.m_size; i++) {
            istr.width(10);
            istr.fill(' ');
            istr.setf(ios::right);
            istr << rightOperand.m_fruits[i].m_name << ": ";
            istr.unsetf(ios::right);

            istr.setf(ios::fixed);
            istr.precision(2);
            istr << rightOperand.m_fruits[i].m_qty << "kg" << endl;
         }
         istr.setf(ios::fixed);
         istr.precision(2);
         istr << "Price: " << rightOperand.m_price << endl;;
      }
      else {
         istr << "The basket is empty!" << endl;
      }
      return istr;
   }

}