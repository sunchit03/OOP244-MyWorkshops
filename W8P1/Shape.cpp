#include "Shape.h"

namespace sdds {

   std::ostream& operator<<(std::ostream& ostr, Shape& rightOperand) {
      return rightOperand.draw(ostr);
   }

   std::istream& operator>>(std::istream& istr, Shape& rightOperand) {
      return rightOperand.getSpecs(istr);
   }
}
