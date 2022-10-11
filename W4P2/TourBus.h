/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : October 10, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H
#include "TourTicket.h"
namespace sdds {

   const int privTour = 4;
   const int miniTour = 16;
   const int fullSize = 22;

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