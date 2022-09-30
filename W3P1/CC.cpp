/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 30, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CC.h"
#include "Utils.h"

using namespace std;

namespace sdds {

   CC info{};

   bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
      bool retVal{};

      // name shouldn't be null and more than 2 characters long
      // cc number between 4000000000000000 and 4099999999999999
      // cvv should be 3 digits long (000-999)
      // expMonth between 1 and 12
      // expYear between 22 and 32
      if ((name != nullptr && strlen(name) > 2) && (cardNo >= 4000000000000000 && cardNo <= 4099999999999999)
         && (cvv >= 100 && cvv <= 999) && (expMon >= 1 && expMon <= 12) && (expYear >= 22 && expYear <= 32)) {
         retVal = true;
      }
      else {
         retVal = false;
      }

      return retVal;
   
   }

   void CC::prnNumber() const {
      int first, second, third, fourth;

      // dividing the 16 digit cc number into sets of 4
      first = info.m_cardNo / 1000000000000;
      second = (info.m_cardNo % 1000000000000) / 100000000;
      third = (info.m_cardNo % 100000000) / 10000;
      fourth = info.m_cardNo % 10000;

      cout << first << " ";

      // adding leading zeroes in case the set does not have 4 numbers
      cout.width(4);
      cout.fill('0');
      cout.setf(ios::right);
      cout << second << " ";

      cout.width(4);
      cout.fill('0');
      cout.setf(ios::right);
      cout << third << " ";

      cout.width(4);
      cout.fill('0');
      cout.setf(ios::right);
      cout << fourth;

      cout.fill(' ');
      cout.unsetf(ios::right);
   }

   void CC::set() {

      // safe initialization
      info.m_name = nullptr;
      info.m_cardNo = 0;
      info.m_CVV = 0;
      info.m_expMon = 0;
      info.m_expYear = 0;
   }

   void CC::cleanUp() {
      delete[] info.m_name;         // deallocates dynmaic memory if any
      info.set();
   }
   
   bool CC::isEmpty() const {
      //returns true if struct is empty
      return (info.m_name == nullptr);
   }

   void CC::set(const char* cc_name, unsigned long long cc_no, short m_cvv, short m_expMon, short m_expYear) {
      cleanUp();
      if (info.validate(cc_name, cc_no, m_cvv, m_expMon, m_expYear)) {
         info.m_name = new char[strlen(cc_name) + 1];
         strcpy(info.m_name, cc_name);

         info.m_cardNo = cc_no;
         info.m_CVV = m_cvv;
         info.m_expMon = m_expMon;
         info.m_expYear = m_expYear;
      }
   }

   bool CC::read() {
      char tempName[NAME_CHARS + 1] = "";
      short tempCVV;
      short tempExpMon;
      short tempExpYear;
      unsigned long long tempCardNo;

      info.cleanUp();

      cout << "Card holder name: ";
      cin.getline(tempName, NAME_CHARS);
      if (!cin.fail()) {
         cout << "Credit card number: ";
      }
      cin >> tempCardNo;

      if (!cin.fail()) {
         cout << "Card Verification Value (CVV): ";
      }
      cin >> tempCVV;

      if (!cin.fail()) {
         cout << "Expiry month and year (MM/YY): ";
      }
      cin >> tempExpMon;
      cin.ignore(1, ',');
      cin >> tempExpYear;

      if (!cin.fail()) {
         info.set(tempName, tempCardNo, tempCVV, tempExpMon, tempExpYear);

         cin.ignore(10000, '\n');
      }
      else {
         cin.clear();
         cin.ignore(10000, '\n');
      }  
      
      return !info.isEmpty();
   }


   void CC::display(int row) const {

      if (info.isEmpty()) {
         cout << "Invalid Credit Card Record" << endl;
      }
      else {
         if (row >= 1) {
            cout << "| ";
            
            // formatting row display
            cout.width(3);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << row << " | ";

            cout.fill(' ');
            cout.unsetf(ios::right);

            // formatting name display
            if (strlen(info.m_name) >= 30) {
               cout.write(info.m_name, 30);
            }
            else {
               cout.width(30);
               cout.fill(' ');
               cout.setf(ios::left);
               cout << info.m_name;

               cout.fill(' ');
               cout.unsetf(ios::left);
            }
            cout << " | ";
            
            // formatting cc number display
            info.prnNumber();

            cout << " | " << info.m_CVV << " | ";


            // formatting expMonth and expYear display
            cout.width(2);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << info.m_expMon << "/" << info.m_expYear << " |" << endl;

            cout.fill(' ');
            cout.unsetf(ios::right);
         }
         else if (row <= 0)
         {
            cout << "Name: " << info.m_name << endl;
            cout << "Creditcard No: ";
            info.prnNumber();
            cout << endl;
            cout << "Card Verification Value: " << info.m_CVV << endl;


            cout << "Expiry Date: " << info.m_expMon << "/" << info.m_expYear << endl;
         }
      }
   }
}