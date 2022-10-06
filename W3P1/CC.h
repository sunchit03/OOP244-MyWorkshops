/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 30, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CC_H_
#define SDDS_CC_H_

namespace sdds {

   const int NAME_CHARS = 70;

   class CC {
      char* m_name;
      short m_CVV;
      short m_expM;
      short m_expY;
      unsigned long long m_cardNo;

   private:
      bool validate(const char* name,
         unsigned long long cardNo,
         short cvv,
         short expMon,
         short expYear)const;

      void prnNumber()const;

   public:
      // Sets the object to a safe empty state by setting
      // all the values to zero and nullptr.
      void set();

      // First, it will deallocate the cardholder's name 
      // and then calls the set() to set the object to a safe empty state.
      void cleanUp();

      // Returns if the CC object is in a safe empty state or not; 
      // by returning true if the cardholder name pointer attribute
      // of the object is nullptr, otherwise, it will return false.
      bool isEmpty() const;

      //First, it will cleanUp() the object.Then if all the arguments
      // are valid using validate(), it will dynamically keep a copy 
      // of the name in the name attributeand set the rest of the 
      // attributes to their corresponding values.
      // If any of the arguments are invalid, nothing will be set.
      void set(const char* cc_name,
         unsigned long long cc_no,
         short m_cvv,
         short m_expMon,
         short m_expYear);

      bool read();
      
      /// <summary>
      /// displays the CC info
      /// </summary>
      /// <param name="row"></param>
      void display(int row = 0) const;
   };

}

#endif