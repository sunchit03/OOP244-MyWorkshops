#include "LblShape.h"
#include "Utils.h"
namespace sdds {

   const char* LblShape::label()const {
      return m_label;
   }

   LblShape::LblShape(const char* label) {
      m_label = new char[strlen(label) + 1];
      strcpy(m_label, label);
   }

   LblShape::~LblShape() {
      delete[] m_label;
      m_label = nullptr;
   }

   std::istream& LblShape::getSpecs(std::istream& istr) {
      char tempLabel[100 + 1]{};
      istr.getline(tempLabel, 100, ',');

      delete[] m_label;
      m_label = nullptr;
      m_label = new char[strlen(tempLabel) + 1];
      strcpy(m_label, tempLabel);

      return istr;
   }
}