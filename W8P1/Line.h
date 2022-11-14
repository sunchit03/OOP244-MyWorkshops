#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include "LblShape.h"
namespace sdds {

   class Line : public LblShape {
   private:
      int m_length;

   public:
      Line();
      Line(const char* str, int length);

      std::istream& getSpecs(std::istream& istr = std::cin);
      std::ostream& draw(std::ostream& ostr = std::cout)const;
   };
}
#endif
