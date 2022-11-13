/*
Name: Sunchit Singh
Email: sunchit-singh@myseneca.ca
Student ID: 169146214
Date: November 7, 2022
Section: OOP244NBB
*/
#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"

namespace sdds
{
	Dumper::Dumper(const char* license, int year, double capacity, const char* address): VehicleBasic(license, year) {
		m_capacity = capacity;
		m_load = 0;
		NewAddress(address);
	}

	bool Dumper::loaddCargo(double cargo) {
		bool retVal = false;
		if (m_capacity >= m_load + cargo) {
			m_load += cargo;
			retVal = true;
		}
		return retVal;
	}

	bool Dumper::unloadCargo() {
		bool retVal = false;
		if (m_load > 0) {
			m_load = 0;
			retVal = true;
		}
		return retVal;
	}

	ostream& Dumper::write(ostream& os)	const{
		VehicleBasic::write(os);
		os << " | " << m_load << "/" << m_capacity;
		return os;
	}

	istream& Dumper::read(istream& in) {
		VehicleBasic::read(in);
		cout << "Capacity: ";
		in >> m_capacity;

		if (!in.fail()) {
			in.ignore(1000, '\n');
			in.clear();

			cout << "Cargo: ";
			in >> m_load;
		}
		return in;
	}



	ostream& operator<<(ostream& os, const Dumper& rightOperand) {
		rightOperand.write(os);
		return os;
	}

	istream& operator>>(istream& in, Dumper& rightOperand) {
		rightOperand.read(in);
		return in;
	}

}

