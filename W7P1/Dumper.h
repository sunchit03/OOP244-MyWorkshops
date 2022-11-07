/*
Name: Sunchit Singh
Email: sunchit-singh@myseneca.ca
Student ID: 169146214
Date: November 7, 2022
Section: OOP244NBB
*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{
	class Dumper : public VehicleBasic {
	private:
		double m_capacity;
		double m_load;

	public:
		Dumper() = default;
		Dumper(const char* license, int year, double capacity, const char* address);
		bool loaddCargo(double cargo);
		bool unloadCargo();
		ostream& write(ostream& os)const;
		istream& read(istream& in);
	};

	ostream& operator<< (ostream& os, const Dumper& rightOperand);
	istream& operator>> (istream& in, Dumper& rightOperand);
	
}
#endif

