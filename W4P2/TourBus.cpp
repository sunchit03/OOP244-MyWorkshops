#include <iostream>
#include "TourBus.h"
#include "TourTicket.h"
using namespace std;
namespace sdds {


   TourBus::TourBus(int value) {
      m_size = value;
   }


   bool TourBus::validTour() const
   {
      //bool flag = false;

      return (m_size == 4 || m_size == 16 || m_size == 22);
   }


   TourBus& TourBus::board()
   {
      char tempName[41];
      m_tt = new TourTicket[m_size];
      cout << "Boarding " << m_size << " Passengers:" << endl;
      for (int i = 0; i < m_size; i++) {
         cout << i + 1 << "/" << m_size << "- Passenger Name: ";
         cin.getline(tempName, 40);

         m_tt[i] = m_tt[i].issue(tempName);
        
      }
      return *this;
      // TODO: insert return statement here
   }
   void TourBus::startTheTour() const {
      if (validTour()) {

         int flag = 0;
         for (int i = 0; i < m_size && flag == 0; i++) {
            if (!m_tt) {
               flag = 1;
            }
         }

         if (flag == 0) {
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