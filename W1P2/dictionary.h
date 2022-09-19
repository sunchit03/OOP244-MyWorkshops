/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : September 18, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_DICTIONARY_H_
#define SDDS_DICTIONARY_H_
#include "word.h"
namespace sdds {

   const int MAX_WORDS = 100;

   struct dictionary {
      int m_totalWords = 0;
      word m_words[MAX_WORDS];
   };

   extern dictionary Dictionary;

   /// <summary>
/// Load from a file a set of words with their definition.  Any previous
///   existing dictionary is discarded, regardless of the result of the load.
/// </summary>
/// <param name="filename">The name of the file containing the dictionary.</param>
/// <returns>0 if data has been loaded from the file, non-zero otherwise
///   (null parameter, empty parameter, missing file).</returns>
   int LoadDictionary(const char* filename);

   /// <summary>
   /// Save all the words existing in the dictionary into a file.  The functions
   ///   "LoadDictionary" should be able to load from this after the save finished.
   /// </summary>
   /// <param name="filename">The name of the file where to save.</param>
   void SaveDictionary(const char* filename);

   
}

#endif