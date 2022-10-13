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
      Apartment(int number, double balance);
      std::ostream& display()const;
      operator bool()const;
      operator int()const;
      operator double()const;
      bool operator~()const;
      Apartment& operator=(int rightOperand);
      Apartment& operator=(Apartment& rightOperand);
      Apartment& operator+=(double rightOperand);
      Apartment& operator-=(double rightOperand);
      Apartment& operator<<(Apartment& rightOperand);
      Apartment& operator>>(Apartment& rightOperand);
      double operator+(const Apartment& rightOperand)const;
      
   };
   double operator+=(double& leftOperand, const Apartment& rightOperand);
}

#endif // SDDS_APARTMENT_H_