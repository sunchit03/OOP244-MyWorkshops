/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 18, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_WORD_H_
#define SDDS_WORD_H_

namespace sdds {

   const int MAX_DEFINITIONS = 8;
   const int MAX_WORD_CHARS = 64;
   const int MAX_DEFINITIONS_CHARS = 1024;

   struct word {
      char m_word[MAX_WORD_CHARS + 1] = "";
      int m_numberDefinitions = 0;
      char m_type[MAX_DEFINITIONS][MAX_WORD_CHARS + 1] = {};
      char m_definiton[MAX_DEFINITIONS][MAX_DEFINITIONS_CHARS + 1] = {};
   };

}


#endif
