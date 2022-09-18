#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dictionary.h"
using namespace std;
namespace sdds {

   dictionary Dictionary = {0};

   FILE* sfptr = nullptr;

   //int LoadDictionary(const char* filename) {
   //   int flag;
   //   int out = 0;
   //   sfptr = fopen(filename, "r");
   //   if (sfptr != NULL) {
   //      flag = 0;

   //      for (int i = 0; i < MAX_WORDS; i++)
   //      {
   //         if (fscanf(sfptr, "%[^\n]", Dictionary.m_words[i].m_word) == 1) {
   //            int c1 = fgetc(sfptr);
   //            printf("%s\n", Dictionary.m_words[i].m_word);
   //            Dictionary.m_totalWords++;
   //            out = 0;

   //            for (int j = 0; j < MAX_DEFINITIONS && out == 0; j++) {
   //               {
   //                  if (fscanf(sfptr, "\t%[^:\n]: ", Dictionary.m_words[i].m_type[j]) == 1) {
   //                     //printf("%s\n", Dictionary.m_words[i].m_type[j]);

   //                     if (fscanf(sfptr, "%[^\n]", Dictionary.m_words[i].m_definiton[j]) == 1) {
   //                        int c2 = fgetc(sfptr);
   //                        int c3 = fgetc(sfptr);
   //                        if (c2 == '\n' && c3 == '\n')
   //                        {
   //                           out = 1;
   //                        }
   //                        //printf("%s\n", Dictionary.m_words[i].m_definiton[j]);

   //                        Dictionary.m_words[i].m_numberDefinitions++;
   //                     }
   //                  }
   //               }
   //            }
   //         }
   //      }
   //      cout << &Dictionary.m_words[1].m_type[0] << endl;
   //   }
   //   else {
   //      flag = 1;
   //   }
   //    
   //   return flag;
   //}

   int LoadDictionary(const char* filename) {
      int flag;
      int breakout = 0;
      int out = 0;
      char str1[MAX_WORD_CHARS + 1] = "";
      char str2[MAX_DEFINITIONS_CHARS + 1] = "";
      //char str3[MAX_DEFINITIONS_CHARS + 1] = "";

      sfptr = fopen(filename, "r");
      if (sfptr != NULL) {
         flag = 0;

         for (int i = 0; i < MAX_WORDS && breakout == 0; i++)
         {
            fgets(str1, MAX_WORD_CHARS + 1, sfptr);
            //sscanf(str1, "%[^\n]", Dictionary.m_words[i].m_word);

            if (sscanf(str1, "%[^\n]", Dictionary.m_words[i].m_word) == 1) {
               int c1 = fgetc(sfptr);
               printf("%s\n", Dictionary.m_words[i].m_word);
               Dictionary.m_totalWords++;
               out = 0;

               for (int j = 0; j < MAX_DEFINITIONS && out == 0; j++) {
                  {
                     fgets(str2, MAX_DEFINITIONS_CHARS + 1, sfptr);
                     //sscanf(str2, "\t%[^:\n]: ", &Dictionary.m_words[i].m_type[j]);

                     if (sscanf(str2, "%[^:]: %[^\n]", &Dictionary.m_words[i].m_type[j], &Dictionary.m_words[i].m_definiton[j]) == 2) {
                        printf("%s\n", &Dictionary.m_words[i].m_type[j]);


                        //fgets(str3, MAX_DEFINITIONS_CHARS, sfptr);
                        //sscanf(str3, "%[^\n]", &Dictionary.m_words[i].m_definiton[j]);


                        //if (sscanf(str3, "%[^\n]", &Dictionary.m_words[i].m_definiton[j]) == 1) {
                           
                           printf("%s\n", &Dictionary.m_words[i].m_definiton[j]);

                           Dictionary.m_words[i].m_numberDefinitions++;

                           int c2 = fgetc(sfptr);
              
                           if (c2 == '\n')
                           {
                              out = 1;
                           }
                           /*if (c3 == '\n' && c4 == '\n')
                           {
                              breakout = 1;
                           }*/
                        //}
                     }
                  }
               }
            }
         }
      }
      else {
         flag = 1;
      }

      return flag;
   }

   void SaveDictionary(const char* filename) {

   }

   void DisplayWord(const char* word) {
      int flag = 0;
      for (int i = 0; i < Dictionary.m_totalWords && flag == 0; i++) {
         if (strcmp(word, Dictionary.m_words[i].m_word) == 0) {

            cout << "FOUND [" << word << "] has [" << Dictionary.m_words[i].m_numberDefinitions << "] definitions:" << endl;
            for (int j = 0; j < Dictionary.m_words[i].m_numberDefinitions; j++) {

               //printf("%d. {%s} %s\n", j + 1, &Dictionary.m_words[i].m_type[j], &Dictionary.m_words[i].m_definiton[j]);
               cout << j + 1 << ". {" << &Dictionary.m_words[i].m_type[j] << "} " << &Dictionary.m_words[i].m_definiton[j] << endl;
            }
            flag = 1;
         }
      }
         
         if (flag == 0) {
            cout << "NOT FOUND: word [" << word << "] is not in the dictionary." << endl;
         }

   }

   void AddWord(const char* word, const char* type, const char* definition) {

   }

   int UpdateDefinition(const char* word, const char* type, const char* definition) {

      return 0;
   }
}