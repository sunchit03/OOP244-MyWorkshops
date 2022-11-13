/*
Name: Sunchit Singh
Email: sunchit-singh@myseneca.ca
Student ID: 169146214
Date: November 7, 2022
Section: OOP244NBB
*/
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds
{
   class VehicleBasic {
   private:
      char m_license[9 + 1];
      char m_address[64 + 1];
      int m_year;

   public:
      VehicleBasic(const char* license, int year);
      void NewAddress(const char* address);
      std::ostream& write(std::ostream& os)const;
      std::istream& read(std::istream& in);
   };

   std::ostream& operator<< (std::ostream& os, const VehicleBasic& rightOperand);
   std::istream& operator>> (std::istream& in, VehicleBasic& rightOperand);

}

#endif

