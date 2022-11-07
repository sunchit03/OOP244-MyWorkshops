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

using namespace std;
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
      ostream& write(ostream& os)const;
      istream& read(istream& in);
   };

   ostream& operator<< (ostream& os, const VehicleBasic& rightOperand);
   istream& operator>> (istream& in, VehicleBasic& rightOperand);

}

#endif

