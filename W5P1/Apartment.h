/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : October 13, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
   class Apartment
   {
      int m_number = -1;
      double m_balance = 0.0;

   public:
      // sets the apartment number and balance to the incoming arguments only if both values are valid
      Apartment(int number, double balance);

      // Displays the apartment information
      std::ostream& display()const;

      // returns true if the apartment object is valid
      operator bool()const;

      // returns the apartment number
      operator int()const;

      // returns the rent balance value
      operator double()const;

      // returns true if the apartment balance is zero; otherwise, it returns false
      // Note: Balance is considered to be zero if it has a value less than 0.00001
      bool operator~()const;

      // set the apartment number of the apartment to the integer value.
      // If integer is invalid apartment number, set object to an invalid empty state
      Apartment& operator=(int rightOperand);

      // swap the rent balance and the apartment number of one apartment to another
      Apartment& operator=(Apartment& rightOperand);

      // the value of the double should be added to the rent balance
      Apartment& operator+=(double rightOperand);

      // the value of the balance should be reduced by the double value
      Apartment& operator-=(double rightOperand);

      // move the balance from the right apartment to the left apartment
      // the balance of the right apartment account will be zero
      Apartment& operator<<(Apartment& rightOperand);

      // move the balance from the left apartment to the right apartment
      // the balance of the left apartment account will be zero
      Apartment& operator>>(Apartment& rightOperand);

      // accepts a constant apartment reference on the left and another constant apartment reference on the right
      // The double value should be the sum of the balances of the two apartments accounts
      double operator+(const Apartment& rightOperand)const; 
   };

   // accepts a double reference on the left and a constant apartment reference on the right
   // The value of the rent balance of the right operand (apartment reference) should be added to the left operand and then the sum will be returned
   double operator+=(double& leftOperand, const Apartment& rightOperand);
}

#endif // SDDS_APARTMENT_H_