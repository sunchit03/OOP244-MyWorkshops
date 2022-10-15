#ifndef SDDS_MARK_H_
#define SDDS_MARK_H

namespace sdds {

   class Mark {
      int m_value;

   public:
      Mark(int value = 0);
      operator int()const;
      operator double()const;
      operator char()const;
      operator bool()const;
      bool operator>(const Mark& rightOperand)const;
      bool operator<(const Mark& rightOperand)const;
      bool operator>=(const Mark& rightOperand)const;
      bool operator<=(const Mark& rightOperand)const;
      bool operator==(const Mark& rightOperand)const;
      bool operator!=(const Mark& rightOperand)const;
      Mark& operator++();
      Mark& operator--();
      Mark operator++(int);
      Mark operator--(int);
      bool operator~()const;
      Mark& operator=(int rightOperand);
      Mark& operator+=(int rightOperand);
      Mark& operator-=(int rightOperand);
      Mark& operator<<(Mark& rightOperand);
      Mark& operator>>(Mark& leftOperand);

      //int& operator+(const int leftOperand);
   };
   
   int operator+=(int& leftOperand, const Mark& rightOperand);
   int operator-=(int& leftOperand, const Mark& rightOperand);
   Mark operator+(const Mark& leftOperand, const Mark& rightOperand);
   int operator+(const int& leftOperand, const Mark& rightOperand);
   Mark operator+(const Mark& leftOperand, const int& rightOperand);
   
}

#endif