#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>
namespace sdds {

   class Shape {
   public:
      virtual std::ostream& draw(std::ostream& ostr = std::cout)const = 0;
      virtual std::istream& getSpecs(std::istream& istr = std::cin) = 0;

      virtual ~Shape() {};
   };

   std::ostream& operator<<(std::ostream& ostr, Shape& rightOperand);
   std::istream& operator>>(std::istream& istr, Shape& rightOperand);
}

#endif