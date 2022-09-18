#ifndef SDDS_WORD_H_
#define SDDS_WORD_H_

namespace sdds {

   const int MAX_DEFINITIONS = 8;
   const int MAX_WORD_CHARS = 64;
   const int MAX_DEFINITIONS_CHARS = 1024;

   struct word {
      char m_word[MAX_WORD_CHARS + 1] = "";
      int m_numberDefinitions = 0;
      char m_type[MAX_WORD_CHARS + 1] = "";
      char m_definiton[MAX_DEFINITIONS_CHARS + 1] = "";
   };

}


#endif
