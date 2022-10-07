#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H
#include "TourTicket.h"
namespace sdds {

   class TourBus {
      class TourTicket* m_tt = {};
      int m_size;

   public :
      TourBus(int value = 0);

      bool validTour() const;

      TourBus& board();

      void startTheTour() const;
   };
}

#endif