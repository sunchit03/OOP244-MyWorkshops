/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 18, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "dictionary.h"
using namespace std;
namespace sdds {

   dictionary Dictionary = {};

   FILE* sfptr = nullptr;

   int LoadDictionary(const char* filename) {
      int flag;
      int out = 0;
      sfptr = fopen(filename, "r");
      if (sfptr != NULL) {
         flag = 0;

         for (int i = 0; i < MAX_WORDS; i++) {
            if (fscanf(sfptr, "%s\n", Dictionary.m_words[i].m_word) == 1) {      // word
               Dictionary.m_totalWords++;
               out = 0;
               for (int j = 0; j < MAX_DEFINITIONS && out == 0; j++) {
                  if (fscanf(sfptr, "\t%[^:\n]: ", Dictionary.m_words[i].m_type[j]) == 1) {        // type
                     if (fscanf(sfptr, "%[^\n]", Dictionary.m_words[i].m_definiton[j]) == 1) {     // definition
                        int c1 = fgetc(sfptr);
                        int c2 = fgetc(sfptr);
                        if (c1 == '\n' && c2 == '\n') {       // signifying end of one set
                           out = 1;
                        }
                        Dictionary.m_words[i].m_numberDefinitions++;
                     }
                  }
               }
            }
         }
         fclose(sfptr);
      }
      else {
         flag = 1;
      }
      return flag;
   }

   void SaveDictionary(const char* filename) {

      sfptr = fopen(filename, "w");

      /*word
           type: definition
      */

      for (int i = 0; i < Dictionary.m_totalWords; i++) {
         fprintf(sfptr, "%s\n", Dictionary.m_words[i].m_word);          // word

         for (int j = 0; j < Dictionary.m_words[i].m_numberDefinitions; j++) {
            fprintf(sfptr, "\t%s: %s\n", Dictionary.m_words[i].m_type[j], Dictionary.m_words[i].m_definiton[j]);        // type and definition
         }
         fputs("\n", sfptr);
      }

      fclose(sfptr);

      Dictionary = {};           // Unloading the dictionary after successful save
   }
}