#include <iostream>
#include "Rectangle.h"
#include "Utils.h"
using namespace std;
namespace sdds {

   Rectangle::Rectangle(): LblShape() {
      m_width = 0;
      m_height = 0;
   }

   Rectangle::Rectangle(const char* label, int width, int height): LblShape(label) {
      m_width = width;
      m_height = height;

      if (m_height < 3 || m_width < strlen(LblShape::label()) + 2) {
         m_width = 0;
         m_height = 0;
      }
   }

   std::istream& Rectangle::getSpecs(std::istream& istr) {
      LblShape::getSpecs(istr);
      istr >> m_width;
      istr.ignore(1, ',');
      if (istr.fail()) {
         istr.clear();
         istr.ignore(1000, '\n');
      }

      istr >> m_height;
      istr.ignore(1000, '\n');

      return istr;
   }

   std::ostream& Rectangle::draw(std::ostream& ostr) const {
      if (m_height > 0 && m_width > 0) {

         ostr << "+";
         for (int i = 0; i < m_width - 2; i++) {
            ostr << "-";
         }
         ostr << "+" << endl;

         ostr << "|";
         ostr.width(m_width - 2);
         ostr.setf(ios::left);
         ostr << label();
         ostr.unsetf(ios::left);
         ostr << "|" << endl;

         for (int i = 0; i < m_height - 3; i++) {
            ostr << "|";
            for (int j = 0; j < m_width - 2; j++) {
               ostr << " ";
            }
            ostr << "|" << endl;
         }

         ostr << "+";
         for (int i = 0; i < m_width - 2; i++) {
            ostr << "-";
         }
         ostr << "+";
      }
      return ostr;
   }
}
