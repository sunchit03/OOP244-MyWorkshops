#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"
namespace sdds {

   class Rectangle: public LblShape {
   private:
      int m_width;
      int m_height;

   public:
      Rectangle();
      Rectangle(const char* label, int width, int height);

      std::istream& getSpecs(std::istream& istr = std::cin);
      std::ostream& draw(std::ostream& ostr = std::cout)const;
   };
}

#endif