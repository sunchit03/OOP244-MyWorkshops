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

   CC;

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
      first = m_cardNo / 1000000000000;
      second = (m_cardNo % 1000000000000) / 100000000;
      third = (m_cardNo % 100000000) / 10000;
      fourth = m_cardNo % 10000;

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
      m_name = nullptr;
      m_cardNo = 0;
      m_CVV = 0;
      m_expM = 0;
      m_expY = 0;
   }

   void CC::cleanUp() {
      delete[] m_name;         // deallocates dynmaic memory if any
      set();
   }
   
   bool CC::isEmpty() const {
      //returns true if struct is empty
      return (m_name == nullptr);
   }

   void CC::set(const char* cc_name, unsigned long long cc_no, short m_cvv, short m_expMon, short m_expYear) {
      cleanUp();
      if (validate(cc_name, cc_no, m_cvv, m_expMon, m_expYear)) {
         m_name = new char[strlen(cc_name) + 1];
         strcpy(m_name, cc_name);

         m_cardNo = cc_no;
         m_CVV = m_cvv;
         m_expM = m_expMon;
         m_expY = m_expYear;
      }
   }

   bool CC::read() {
      char tempName[NAME_CHARS + 1] = "";
      short tempCVV;
      short tempExpMon;
      short tempExpYear;
      unsigned long long tempCardNo;

      cleanUp();

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
         set(tempName, tempCardNo, tempCVV, tempExpMon, tempExpYear);

         cin.ignore(10000, '\n');
      }
      else {
         cin.clear();
         cin.ignore(10000, '\n');
      }  
      
      return !isEmpty();
   }


   void CC::display(int row) const {

      if (isEmpty()) {
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


            char tempName[30 + 1] = "";
            strcpy(tempName, m_name, 30);
            cout.width(30);
            cout.fill(' ');
            cout.setf(ios::left);
            cout << tempName;

            cout.fill(' ');
            cout.unsetf(ios::left);


            // formatting name display
            /*if (strlen(m_name) >= 30) {
               cout.write(m_name, 30);
            }
            else {
               cout.width(30);
               cout.fill(' ');
               cout.setf(ios::left);
               cout << m_name;

               cout.fill(' ');
               cout.unsetf(ios::left);
            }*/
            cout << " | ";
            
            // formatting cc number display
            prnNumber();

            cout << " | " << m_CVV << " | ";


            // formatting expMonth and expYear display
            cout.width(2);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << m_expM << "/" << m_expY << " |" << endl;

            cout.fill(' ');
            cout.unsetf(ios::right);
         }
         else if (row <= 0)
         {
            cout << "Name: " << m_name << endl;
            cout << "Creditcard No: ";
            prnNumber();
            cout << endl;
            cout << "Card Verification Value: " << m_CVV << endl;


            cout << "Expiry Date: " << m_expM << "/" << m_expY << endl;
         }
      }
   }
}