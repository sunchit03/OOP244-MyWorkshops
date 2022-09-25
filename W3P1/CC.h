#ifndef SDDS_CC_H_
#define SDDS_CC_H_

namespace sdds {

   class CC {
      char* m_name;
      short m_CVV;
      short m_expMon;
      short m_expYear;
      unsigned long long cardNo;

   private:
      bool validate(const char* name,
         unsigned long long cardNo,
         short cvv,
         short expMon,
         short expYear)const;

      void prnNumber()const;

   public:
      void set();

      void cleanUp();

      bool isEmpty() const;

      void set(const char* cc_name,
         unsigned long long cc_no,
         short m_cvv,
         short m_expMon,
         short m_expYear);

      bool read();

      void display(int row = 0) const;
   };

}

#endif