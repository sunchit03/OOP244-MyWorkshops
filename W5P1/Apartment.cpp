/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : October 13, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{
   Apartment::Apartment(int number, double balance)
   {

      if (number >= 1000 && number <= 9999
         && balance >= 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Apartment::display() const
   {
      if (*this)
      {
         cout.width(4);
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else
      {
         cout << "Invld|  Apartment   ";
      }
      return cout;
   }

   Apartment::operator bool()const {
      return (m_number >= 1000 && m_number <= 9999 && m_balance >= 0);
   }

   Apartment::operator int()const {
      return m_number;
   }

   Apartment::operator double()const {
      return m_balance;
   }

   bool Apartment::operator~()const {
      return m_balance < 0.00001;
   }

   Apartment& Apartment::operator=(int rightOperand) {
      if (rightOperand >= 1000 && rightOperand <= 9999) {
         m_number = rightOperand;
      }
      else {
         m_number = -1;
         m_balance = 0.0;
      }
      return *this;
   }

   Apartment& Apartment::operator=(Apartment& rightOperand) {
      int tempNumber = m_number;
      m_number = rightOperand.m_number;
      rightOperand.m_number = tempNumber;

      double tempBalance = m_balance;
      m_balance = rightOperand.m_balance;
      rightOperand.m_balance = tempBalance;

      return *this;
   }

   Apartment& Apartment::operator+=(double rightOperand) {
      if (operator bool() && rightOperand >= 0) {
         m_balance += rightOperand;
      }
      return *this;
   }

   Apartment& Apartment::operator-=(double rightOperand) {
      if (operator bool() && rightOperand >= 0.0 && m_balance >= rightOperand) {
         m_balance -= rightOperand;
      }
      return *this;
   }

   Apartment& Apartment::operator<<(Apartment& rightOperand) {
      if (this != &rightOperand) {
         if (rightOperand.operator bool()) {
            operator+=(rightOperand.m_balance);
            rightOperand.m_balance = 0.0;
         }
      }
      return *this;
   }

   Apartment& Apartment::operator>>(Apartment& rightOperand) {
      if (this != &rightOperand) {
         if (operator bool()) {
            rightOperand.operator+=(m_balance);
            m_balance = 0.0;
         }
      }
      return *this;
   }

   double Apartment::operator+(const Apartment& rightOperand)const {
      double retVal = 0;
      if (operator bool() && rightOperand.operator bool()) {
         retVal = m_balance + rightOperand.m_balance;
      }
      return retVal;
   }

    double operator+=(double& leftOperand, const Apartment& rightOperand) {
       if (rightOperand.operator bool()) {
          leftOperand = leftOperand + rightOperand.operator double();
       }
       else {
          leftOperand = 0;
       }
       return leftOperand;
   }
}