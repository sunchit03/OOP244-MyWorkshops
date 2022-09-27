#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "CC.h"
#include "Utils.h"

using namespace std;

namespace sdds {

   CC info{};

   bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
      bool retVal{};

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
      first = info.m_cardNo / 1000000000000;
      second = (info.m_cardNo % 1000000000000) / 100000000;
      third = (info.m_cardNo % 100000000) / 10000;
      fourth = info.m_cardNo % 10000;

      cout << right << setfill('0') << setw(4) << first << " ";
      cout << right << setfill('0') << setw(4) << second << " ";
      cout << right << setfill('0') << setw(4) << third << " ";
      cout << right << setfill('0') << setw(4) << fourth;
   }

   void CC::set() {
      info.m_name = nullptr;
      info.m_cardNo = 0;
      info.m_CVV = 0;
      info.m_expMon = 0;
      info.m_expYear = 0;
   }

   void CC::cleanUp() {
      delete[] info.m_name;
      info.set();
   }
   
   bool CC::isEmpty() const {
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
      cin.getline(tempName, 71);
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

         cin.ignore(1000, '\n');
      }
      else {
         cin.clear();
         cin.ignore(1000, '\n');
      }  
      
      return !info.isEmpty();
   }


   void CC::display(int row) const {

      if (info.isEmpty()) {
         cout << "Invalid Credit Card Record" << endl;
      }
      else {
         if (row >= 1) {

            cout << "| " << right << setfill(' ') << setw(3) << row << " | ";
            
            if (strlen(info.m_name) >= 30) {
               cout.write(info.m_name, 30);
            }
            else {
               cout << left << setfill(' ') << setw(30);
               cout << info.m_name;
            }
            cout << " | ";
            
            info.prnNumber();

            cout << " | " << info.m_CVV << " | " << right << setfill(' ') << setw(2) << info.m_expMon << "/" << info.m_expYear << " |" << endl;
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