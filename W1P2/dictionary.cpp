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

   void DisplayWord(const char* word) {
      int flag = 0;
      for (int i = 0; i < Dictionary.m_totalWords && flag == 0; i++) {
         if (strcmp(word, Dictionary.m_words[i].m_word) == 0) {

            // FOUND: [X] has [Y] definitions:
            cout << "FOUND: [" << word << "] has [" << Dictionary.m_words[i].m_numberDefinitions << "] definitions:" << endl;
            for (int j = 0; j < Dictionary.m_words[i].m_numberDefinitions; j++) {

               // 1. {type} definition
               cout << j + 1 << ". {" << Dictionary.m_words[i].m_type[j] << "} " << Dictionary.m_words[i].m_definiton[j] << endl;
            }

            flag = 1;
         }
      }
      if (flag == 0) {

         // NOT FOUND: word [X] is not in the dictionary.
         cout << "NOT FOUND: word [" << word << "] is not in the dictionary." << endl;
      }
   }

   void AddWord(const char* word, const char* type, const char* definition) {
      int flag = 0;
      for (int i = 0; i < Dictionary.m_totalWords && flag == 0; i++) {
         if (strcmp(word, Dictionary.m_words[i].m_word) == 0) {      // Checking if the word is already in the dictionary
            int n = Dictionary.m_words[i].m_numberDefinitions++;     // Storing the value of the total number of defintions for the word and then incrementing it

            strcpy(Dictionary.m_words[i].m_type[n], type);           // Putting the new type at the first available index
            strcpy(Dictionary.m_words[i].m_definiton[n], definition);  // Putting the new definition at the first available index

            flag = 1;
         }
      }
      if (flag == 0) {

         int m = Dictionary.m_totalWords;
         int o = Dictionary.m_words[m].m_numberDefinitions;

         strcpy(Dictionary.m_words[m].m_word, word);                 // Putting the new word at the first available index
         strcpy(Dictionary.m_words[m].m_type[o], type);              // Putting the new type at the first available index
         strcpy(Dictionary.m_words[m].m_definiton[o], definition);   // Putting the new definition at the first available index

         Dictionary.m_totalWords++;                                  // Incrementing the total number of words in the dictionary
         Dictionary.m_words[m].m_numberDefinitions++;                // Incrementing the total number of definitions for the new word

         flag = 1;
      }
   }

   int UpdateDefinition(const char* word, const char* type, const char* definition) {
      int flag = 0;
      int update;
      for (int i = 0; i < Dictionary.m_totalWords && flag == 0; i++) {
         if (strcmp(word, Dictionary.m_words[i].m_word) == 0) {            // Checking if the word is in the dictionary
            if (Dictionary.m_words[i].m_numberDefinitions > 1) {           // Checking if the word has multiple definitions
               // The word [X] has multiple definitions:
               cout << "The word [" << word << "] has multiple definitions:" << endl;

               for (int j = 0; j < Dictionary.m_words[i].m_numberDefinitions; j++) {
                  // 1. {type} definition
                  cout << j + 1 << ". {" << Dictionary.m_words[i].m_type[j] << "} " << Dictionary.m_words[i].m_definiton[j] << endl;
               }
               cout << "Which one to update? ";
               cin >> update;

               strcpy(Dictionary.m_words[i].m_type[update - 1], type);
               strcpy(Dictionary.m_words[i].m_definiton[update - 1], definition);
            }
            else {                                                         // If the word has only one definition
               strcpy(Dictionary.m_words[i].m_type[Dictionary.m_words[i].m_numberDefinitions], type);
               strcpy(Dictionary.m_words[i].m_definiton[Dictionary.m_words[i].m_numberDefinitions], definition);
            }
            flag = 1;
         }
      }
      if (flag == 0) {                                                    // If the word is not in the dictionary 
         cout << "NOT FOUND: word [" << word << "] is not in the dictionary." << endl;
      }
      return flag;
   }
}