#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"
namespace sdds {

   class LblShape: public Shape {
   private:
      char* m_label = NULL;

   protected:
      const char* label()const;

   public:
      LblShape() = default;
      LblShape(const char* label);
      ~LblShape();

      LblShape(const LblShape& toCopyFrom) = delete;
      LblShape& operator=(const LblShape& toCopyFrom) = delete;

      virtual std::istream& getSpecs(std::istream& istr = std::cin);
   };
}

#endif