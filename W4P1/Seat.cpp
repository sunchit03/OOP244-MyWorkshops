#include <iostream>
#include "Seat.h"
#include "Utils.h"
using namespace std;
namespace sdds {

   Seat info{};

   bool Seat::validate(int row, char letter) const {
      bool flag = false;

      if ((row >= 1 && row <= 4) && (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F')) {
         flag = true;
      }
      else if (((row >= 7 && row <= 15) || (row >= 20 && row <= 38)) &&
         (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F')) {
         flag = true;
      }

      return flag;
   }

   Seat& Seat::alAndCp(const char* str) {
      m_name = nullptr;

      if (str && str[0]) {
         m_name = new char[strlen(str) + 1];
         strcpy(m_name, str);
      }

      return *this;
      // TODO: insert return statement here
   }


   Seat& Seat::reset() {
      delete[] m_name;
      m_name = nullptr;
      m_rownum = 0;
      m_letter = 0;

      return *this;
      // TODO: insert return statement here
   }

   bool Seat::isEmpty() const {
      return m_name == nullptr;
   }

   bool Seat::assigned() const {
      return validate(m_rownum, m_letter);
   }

   Seat::Seat() {
      m_name = nullptr;
      reset();
   }

   Seat::Seat(const char* passengerName) {
      alAndCp(passengerName);
      m_rownum = 0;
      m_letter = 0;
   }

   Seat::Seat(const char* passengerName, int row, char letter) {
      alAndCp(passengerName);
      if (validate(row, letter)) {
         m_rownum = row;
         m_letter = letter;
      }
      else {
         m_rownum = 0;
         m_letter = 0;
      }
   }

   Seat::~Seat() {
      reset();
   }

   Seat& Seat::set(int row, char letter) {
      if (validate(row, letter)) {
         m_rownum = row;
         m_letter = letter;
      }
      else {
         m_rownum = 0;
         m_letter = 0;
      }

      return *this;
   }

   int Seat::row()const {
      return m_rownum;
   }

   char Seat::letter()const {
      return m_letter;
   }

   const char* Seat::passenger()const {
      return m_name;
   }

   std::ostream& Seat::display(std::ostream& coutRef)const {
      if (isEmpty()) {
         cout << "Invalid Seat!";
      }
      else {
         char tempName[MAX_COLUMNS_CHARS + 1]{};
         strcpy(tempName, passenger(), MAX_COLUMNS_CHARS);

         cout.width(MAX_COLUMNS_CHARS);
         cout.fill('.');
         cout.setf(ios::left);
         cout << tempName;

         cout.fill(' ');
         cout.unsetf(ios::left);

         if (m_rownum == 0) {
            cout << " ___";
         }
         else {
            cout << " " << row() << letter();
         }
      }
      return coutRef;
   }

   std::istream& Seat::read(std::istream& cinRef) {

      reset();

      char tempName[71]{};
      int tempRownum = 0;
      char tempLetter = 0;

      if (!cinRef.eof()) {

      cinRef.getline(tempName, 70, ',');
      if (!cinRef.fail()) {
         cinRef >> tempRownum;
      }
      else {

      }

      if (!cinRef.fail()) {
         cinRef >> tempLetter;
      }

      if (!cinRef.fail()) {
         cinRef.ignore(10000, '\n');

         alAndCp(tempName);

         if (m_name && m_name[0]) {
            set(tempRownum, tempLetter);
         }
      }
   }
      return cinRef;
   }
}