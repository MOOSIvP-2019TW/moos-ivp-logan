/************************************************************/
/*    NAME: logan                                              */
/*    ORGN: MIT                                             */
/*    FILE: testing.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef testing_HEADER
#define testing_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

class testing : public AppCastingMOOSApp
{
 public:
   testing();
   ~testing();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected: // Standard AppCastingMOOSApp function to overload 
   bool buildReport();

 protected:
   void registerVariables();

   //10.21experiment
   void ShowCompassHeading(bool active, double angle);


 private: // Configuration variables

  // 10.21
  double m_time;
  int counter;

 private: // State variables
};

#endif 
