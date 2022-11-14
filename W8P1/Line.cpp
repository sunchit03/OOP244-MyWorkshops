#include <iostream>
#include "Line.h"
#include "Utils.h"
using namespace std;
namespace sdds {

   Line::Line(): LblShape() {
      m_length = 0;
   }

   Line::Line(const char* label, int length): LblShape(label) {
      m_length = length;
   }

   std::istream& Line::getSpecs(std::istream& istr) {
      LblShape::getSpecs(istr);
      istr >> m_length;
      istr.ignore(1000, '\n');

      if (istr.fail()) {
         istr.clear();
         istr.ignore(1000, '\n');
      }
      return istr;
   }

   std::ostream& Line::draw(std::ostream& ostr) const {
      if (m_length > 0 && label()) {
         ostr << label();
         for (int i = 0; i < m_length - strlen(label()); i++) {
            ostr << "=";
         }
      } 
      return ostr;
   }
}