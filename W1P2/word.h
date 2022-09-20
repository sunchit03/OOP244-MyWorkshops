/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 19, 2022
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


   /// <summary>
   /// Search in the dictionary for the word and display all the definitions found.
   /// 
   /// Print "NOT FOUND: word [X] is not in the dictionary." if
   ///   the word doesn't exist in dictionary.
   /// </summary>
   /// <param name="word">The word to search and display.</param>
   void DisplayWord(const char* word);

   /// <summary>
   /// Adds a word to the dictionary.
   /// 
   /// If the dictionary already contains the word, add a new definition for it.
   /// </summary>
   /// <param name="word">The word to add to the dictionary.</param>
   /// <param name="type">The type of the word (noun, verb, adjective, etc.)</param>
   /// <param name="definition">The definition for the word.</param>
   void AddWord(const char* word, const char* type, const char* definition);

   /// <summary>
   /// Searches in the dictionary for a word and update its definition and type.
   ///   If the word contains multiple definitions, print the message
   ///   "The word [X] has multiple definitions:" followed by a list of existing
   ///   definitions, and asks user which one to update.  This function assumes that
   ///   the user's input is correct and doesn't require validation.
   /// 
   /// If the word is not in the dictionary, this function does nothing.
   /// </summary>
   /// <param name="word">The word to update.</param>
   /// <param name="type">The new type of the definition.</param>
   /// <param name="definition">The new definition.</param>
   /// <returns></returns>
   int UpdateDefinition(const char* word, const char* type, const char* definition);
}


#endif
