/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 28, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_

namespace sdds {

   const int MAX_NAME_CHARS = 50;

   class NameTag {
   public:
      char m_name[MAX_NAME_CHARS + 1];

      void set(const char* name);

      void cleanup();
   };

   extern NameTag nt;

}

#endif
