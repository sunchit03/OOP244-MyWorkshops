/*
Name: Sunchit Singh
Email: sunchit-singh@myseneca.ca
Student ID: 169146214
Date: November 7, 2022
Section: OOP244NBB
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{
	
	VehicleBasic::VehicleBasic(const char* license, int year) {
		strcpy(m_license, license);
		strcpy(m_address, "Factory");
		m_year = year;

	}

	void VehicleBasic::NewAddress(const char* address) {
		if (strcmp(m_address, address) != 0) {

			cout << "|";
			cout.width(8);
			cout.setf(ios::right);
			cout << m_license << "| |";
			cout.unsetf(ios::right);

			cout.width(20);
			cout.setf(ios::right);
			cout << m_address << " ---> ";
			cout.unsetf(ios::right);

			cout.width(20);
			cout.setf(ios::left);
			cout << address << "|" << endl;
			cout.unsetf(ios::left);

			strcpy(m_address, address);
		}
	}

	ostream& VehicleBasic::write(ostream& os)	const {
		os << "| "<< m_year <<" | " << m_license << " | " << m_address;
		return os;
	}

	istream& VehicleBasic::read(istream& in) {
		cout << "Built year: ";
		in >> m_year;
		if (!in.fail()) {
			in.ignore(1000, '\n');
			in.clear();
			cout << "License plate: ";
			in.getline(m_license, 9, '\n');
		}
		cout << "Current location: ";
		in.getline(m_address, 64, '\n');
		return in;
	}

	ostream& operator<<(ostream& os, const VehicleBasic& rightOperand) {
		rightOperand.write(os);
		return os;
	}

	istream& operator>>(istream& in, VehicleBasic& rightOperand) {
		rightOperand.read(in);
		return in;
	}

}
