/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : October 17, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"

using namespace std;
namespace sdds {

   Numbers::Numbers() {
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) {
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         deallocate();
         setEmpty();
         m_isOriginal = false;
      }
   }

   Numbers::~Numbers() {
      save();
      deallocate();
   }

   Numbers::Numbers(const Numbers& toCopyFrom) {
      setEmpty();
      operator=(toCopyFrom);
   }

   Numbers& Numbers::operator=(const Numbers& toCopyFrom) {
      if (this != &toCopyFrom) {
         delete[] m_numbers;
         setEmpty();
         m_isOriginal = false;
         m_numbers = new double[toCopyFrom.m_numCount];
         m_numCount = toCopyFrom.m_numCount;

         for (int i = 0; i < toCopyFrom.m_numCount; i++) {
            m_numbers[i] = toCopyFrom.m_numbers[i];
         }
      }
      return *this;
   }

   bool Numbers::isEmpty() const {
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() {
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::deallocate() {
      delete[] m_filename;
      delete[] m_numbers;
   }
   void Numbers::setFilename(const char* filename) {
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

   Numbers& Numbers::sort(bool ascending) {
      if (ascending) {
         double temp;
         //Sort the array in ascending order
         for (int i = 0; i < m_numCount; i++) {
            for (int j = i + 1; j < m_numCount; j++) {
               if (m_numbers[i] > m_numbers[j]) {
                  temp = m_numbers[i];
                  m_numbers[i] = m_numbers[j];
                  m_numbers[j] = temp;
               }
            }
         }
      }
      else {
         double temp;
         //Sort the array in descending order
         for (int i = 0; i < m_numCount; i++) {
            for (int j = i + 1; j < m_numCount; j++) {
               if (m_numbers[i] < m_numbers[j]) {
                  temp = m_numbers[i];
                  m_numbers[i] = m_numbers[j];
                  m_numbers[j] = temp;
               }
            }
         }
      }
      return *this;
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }

   Numbers Numbers::operator-() const {
      Numbers tempNum;
      tempNum = *this;
      /*tempNum.sort(false);
      return tempNum;*/
      return tempNum.sort(false);
   }

   Numbers Numbers::operator+() const {
      Numbers tempNum;
      tempNum = *this;
      tempNum.sort(true);
      return tempNum;
   }

   int Numbers::numberCount() const {
      ifstream ofile(m_filename);
      int counter = 0;
      char ch;
      while (ofile.get(ch)) {
         if (ch == '\n') {
            counter++;
         }
      }
      return counter;
   }

   bool Numbers::load() {
      int i = 0;
      if (m_numCount > 0) {
         m_numbers = new double[m_numCount];

         ifstream rfile(m_filename);
         while (rfile) {
            rfile >> m_numbers[i];
            if (rfile) {
               i++;
            }
         }
      }
      return i == m_numCount;
   }

   void Numbers::save() {
      if (m_isOriginal && !isEmpty()) {
         ofstream wfile(m_filename);
         for (int i = 0; i < m_numCount; i++) {
            wfile.setf(ios::fixed);
            wfile.precision(2);
            wfile << m_numbers[i] << endl;
         }
      }
   }

   Numbers& Numbers::operator+=(const double leftOperand) {
      if (!isEmpty()) {
         double* tempNumber = new double[m_numCount + 1];
         for (int i = 0; i < m_numCount; i++) {
            tempNumber[i] = m_numbers[i];
         }
         tempNumber[m_numCount] = leftOperand;

         m_numCount++;

         delete[] m_numbers;
         m_numbers = tempNumber;
      }
      return *this;
   }

   ostream& Numbers::display(ostream& ostr) const {
      if (isEmpty()) {
         ostr << "Empty list";
      }
      else {
         ostr << "=========================" << endl;
         if (m_isOriginal) {
            ostr << m_filename;
         }
         else {
            ostr << "*** COPY ***";
         }
         ostr << endl;

         for (int i = 0; i < m_numCount; i++) {
            if (i < m_numCount - 1) {
               ostr.setf(ios::fixed);
               ostr.precision(2);
               ostr << m_numbers[i] << ", ";
            }
            else {
               ostr << m_numbers[i] << endl;
            }
         }
         ostr << "-------------------------" << endl;
         ostr << "Total of " << m_numCount << " number(s)" << endl;
         ostr.width(strlen("Smallest number: "));
         ostr.fill(' ');
         ostr.setf(ios::left);
         ostr << "Largest number:";

         ostr.setf(ios::fixed);
         ostr.precision(2); 
         ostr << max() << endl;


         ostr.width(strlen("Smallest number: "));
         ostr.fill(' ');
         ostr.setf(ios::left);
         ostr << "Smallest number:";

         ostr.setf(ios::fixed);
         ostr.precision(2); 
         ostr << min() << endl;


         ostr.width(strlen("Smallest number: "));
         ostr.fill(' ');
         ostr.setf(ios::left);
         ostr << "Average:";

         ostr.setf(ios::fixed);
         ostr.precision(2); 
         ostr << average() << endl;
         ostr << "=========================";
      }
      return ostr;
   }

   ostream& operator<<(ostream& os, const Numbers& N) {
      return N.display(os);
   }

   istream& operator>>(istream& istr, Numbers& N) {
      double temp;
      istr >> temp;

      if (istr) {
         N += temp;
      }

      return istr;
   }

}
