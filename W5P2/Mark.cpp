#include "Mark.h"

namespace sdds {

   Mark::Mark(int value) {
      if (value >= 0 && value <= 100) {
         m_value = value;
      }
      else {
         m_value = -1;
      }
   }

   Mark::operator int() const {
      int retVal;
      if (m_value >= 0 && m_value <= 100) {
         retVal = m_value;
      }
      else {
         retVal = 0;
      }
      return retVal;
   }

   Mark::operator double() const {
      double retVal;
      if (m_value >= 80 && m_value <= 100) {
         retVal = 4.0;
      }
      else if (m_value < 80 && m_value >= 70) {
         retVal = 3.0;
      }
      else if (m_value < 70 && m_value >= 60) {
         retVal = 2.0;
      }
      else if (m_value < 60 && m_value >= 50) {
         retVal = 1.0;
      }
      else {
         retVal = 0.0;
      }
      return retVal;
   }

   Mark::operator char() const {
      char retVal;
      if (m_value >= 80 && m_value <= 100) {
         retVal = 'A';
      }
      else if (m_value < 80 && m_value >= 70) {
         retVal = 'B';
      }
      else if (m_value < 70 && m_value >= 60) {
         retVal = 'C';
      }
      else if (m_value < 60 && m_value >= 50) {
         retVal = 'D';
      }
      else if (m_value < 49 && m_value >= 0) {
         retVal = 'F';
      }
      else {
         retVal = 'X';
      }
      return retVal;
   }

   Mark::operator bool() const {
      return m_value >= 0 && m_value <= 100;
   }

   bool Mark::operator>(const Mark& rightOperand) const {
      return m_value > rightOperand.m_value;
   }

   bool Mark::operator<(const Mark& rightOperand) const {
      return m_value < rightOperand.m_value;
   }

   bool Mark::operator>=(const Mark& rightOperand) const {
      return m_value >= rightOperand.m_value;
   }

   bool Mark::operator<=(const Mark& rightOperand) const {
      return m_value <= rightOperand.m_value;
   }

   bool Mark::operator==(const Mark& rightOperand) const {
      return m_value == rightOperand.m_value;
   }

   bool Mark::operator!=(const Mark& rightOperand) const {
      return m_value != rightOperand.m_value;
   }

   Mark& Mark::operator++() {
      if (operator bool()) {
         m_value++;
      }
      return *this;
   }

   Mark& Mark::operator--() {
      if (operator bool()) {
         m_value--;
      }
      return *this;
   }

   Mark Mark::operator++(int) {
      if (operator bool()) {
         m_value++;
      }
      return Mark(m_value - 1);
   }

   Mark Mark::operator--(int) {
      if (operator bool()) {
         m_value--;
      }
      return Mark(m_value + 1);
   }

   bool Mark::operator~() const {
      return m_value >= 50 && m_value <= 100;
   }

   Mark& Mark::operator=(int rightOperand) {
      if (rightOperand >= 0 && rightOperand <= 100) {
         m_value = rightOperand;
      }
      else {
         m_value = -1;
      }
      return *this;
   }

   Mark& Mark::operator+=(int rightOperand) {
      int retVal = m_value + rightOperand;
      if (operator bool() && retVal >= 0 && retVal <= 100) {
         m_value = retVal;
      }
      else {
         m_value = -1;
      }
      return *this;
   }

   Mark& Mark::operator-=(int rightOperand) {
      int retVal = m_value - rightOperand;
      if (operator bool() && retVal >= 0 && retVal <= 100) {
         m_value = retVal;
      }
      else {
         m_value = -1;
      }
      return *this;
   }

   Mark& Mark::operator<<(Mark& rightOperand) {
      int val = m_value + rightOperand.m_value;
      if (operator bool() && rightOperand.operator bool() && val >= 0 && val <= 100) {
         m_value = val;
         rightOperand.m_value = 0;
      }
      return *this;
   }

   Mark& Mark::operator>>(Mark& leftOperand) {
      int val = m_value + leftOperand.m_value;
      if (operator bool() && leftOperand.operator bool() && val >= 0 && val <= 100) {
         leftOperand.m_value = val;
         m_value = 0;
      }
      return *this;
   }

   int operator+=(int& leftOperand, const Mark& rightOperand) {
      if (rightOperand.operator bool()) {
         leftOperand += rightOperand.operator int();
      }
      return leftOperand;
   }

   int operator-=(int& leftOperand, const Mark& rightOperand) {
      if (rightOperand.operator bool()) {
         leftOperand -= rightOperand.operator int();
      }
      return leftOperand;
   }

   Mark operator+(const Mark& leftOperand, const Mark& rightOperand) {
      int val = leftOperand.operator int() + rightOperand.operator int();
      int retVal = -1;
      if (leftOperand.operator bool() && rightOperand.operator bool() && val >= 0 && val <= 100) {
         retVal = val;
      }
      return Mark(retVal);
   }

   int operator+(const int& leftOperand, const Mark& rightOperand) {
      int val = leftOperand + rightOperand.operator int();
      int retVal = -1;
      if (rightOperand.operator bool() && val >= 0 && val <= 100) {
         retVal = val;
      }
      return retVal;
   }

   Mark operator+(const Mark& leftOperand, const int& rightOperand) {
      int val = leftOperand.operator int() + rightOperand;
      int retVal = -1;
      if (leftOperand.operator bool() && val >= 0 && val <= 100) {
         retVal = val;
      }
      return Mark(retVal);
   }
}