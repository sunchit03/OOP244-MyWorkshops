/*
Full Name: Sunchit Singh
Email    : sunchit-singh@myseneca.ca
StudentID: 169146214
Date     : October 10, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "TourBus.h"
#include "TourTicket.h"
using namespace std;
namespace sdds {

   TourBus::TourBus(int value) {
      m_size = value;
   }

   bool TourBus::validTour() const {
      return (m_size == privTour || m_size == miniTour || m_size == fullSize);
   }

   TourBus& TourBus::board() {
      char tempName[41];
      m_tt = new TourTicket[m_size];
      cout << "Boarding " << m_size << " Passengers:" << endl;
      for (int i = 0; i < m_size; i++) {
         cout << i + 1 << "/" << m_size << "- Passenger Name: ";
         cin.getline(tempName, 40);

         m_tt[i] = m_tt[i].issue(tempName);
        
      }
      return *this;
   }

   void TourBus::startTheTour() const {
      
      if (validTour()) {

         if (m_tt) {
            cout << "Starting the tour...." << endl;
            cout << "Passenger List:" << endl;
            cout << "|Row | Passenger Name                           | Num |" << endl;
            cout << "+----+------------------------------------------+-----+" << endl;

            for (int i = 0; i < m_size; i++) {
               cout << "|";
               cout.width(3);
               cout.fill(' ');
               cout.setf(ios::right);
               cout << i + 1 << " ";
               
               cout.unsetf(ios::right);

               m_tt[i].display() << endl;

            }

            cout << "+----+------------------------------------------+-----+" << endl;
            delete[] m_tt;
         }
         else {
            cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
         }
      }
   }
}