/************************************************************/
/*    NAME: logan                                              */
/*    ORGN: MIT                                             */
/*    FILE: testing.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"
#include "testing.h"

// 10.21experiment
#include "XYVector.h"
#include "ColorPack.cpp"

using namespace std;

//---------------------------------------------------------
// Constructor

testing::testing()
{
	m_time = MOOSTime();
	counter = 0;
}

//---------------------------------------------------------
// Destructor

testing::~testing()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool testing::OnNewMail(MOOSMSG_LIST &NewMail)
{
  AppCastingMOOSApp::OnNewMail(NewMail);

  MOOSMSG_LIST::iterator p;
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key    = msg.GetKey();

#if 0 // Keep these around just for template
    string comm  = msg.GetCommunity();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif

     if(key == "FOO") 
       cout << "great!";

     else if(key != "APPCAST_REQ") // handled by AppCastingMOOSApp
       reportRunWarning("Unhandled Mail: " + key);
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool testing::OnConnectToServer()
{
   registerVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool testing::Iterate()
{
  AppCastingMOOSApp::Iterate();
  // Do your thing here!
  double m_curr_time = MOOSTime();
  /*
  if(abs(m_curr_time - m_time > 1000))
  {
	ShowCompassHeading(false);
  }
  else 
  {
  }
  */
//	for (int i=0; i< 360; i++)
//	{
		ShowCompassHeading(true,counter);
		counter++;
		//ShowCompassHeading(false,0);
		
//	}
  //m_Comms.Notify("NAV_HEADING", 90);

  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool testing::OnStartUp()
{
  AppCastingMOOSApp::OnStartUp();

  STRING_LIST sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(!m_MissionReader.GetConfiguration(GetAppName(), sParams))
    reportConfigWarning("No config block found for " + GetAppName());

  STRING_LIST::iterator p;
  for(p=sParams.begin(); p!=sParams.end(); p++) {
    string orig  = *p;
    string line  = *p;
    string param = tolower(biteStringX(line, '='));
    string value = line;

    bool handled = false;
    if(param == "foo") {
      handled = true;
    }
    else if(param == "bar") {
      handled = true;
    }

    if(!handled)
      reportUnhandledConfigWarning(orig);

  }
  
  registerVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: registerVariables

void testing::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  // Register("FOOBAR", 0);
}


//------------------------------------------------------------
// Procedure: buildReport()

bool testing::buildReport() 
{
  m_msgs << "============================================" << endl;
  m_msgs << "File:                                       " << endl;
  m_msgs << "============================================" << endl;

  ACTable actab(4);
  actab << "Alpha | Bravo | Charlie | Delta";
  actab.addHeaderLines();
  actab << "one" << "two" << "three" << "four";
  m_msgs << actab.getFormattedString();

  return(true);
}
//------------------------------------------------------------
// Procedure: ShowCompassHeading
//   Purpose: Using VIEW_VECTOR to show compass heading on pMarineViewer

void testing::ShowCompassHeading(bool active=false, double angle = 0)
{
	XYVector vector(0, 0, 5, angle);
	vector.set_active(active);
	vector.set_label("COMPASS_HEADING");
	//vector.set_color("fill", "green");
	vector.set_vertex_size(5);
	vector.set_edge_size(5);
	vector.set_edge_color("green");
	vector.setHeadSize(2);
	string str = vector.get_spec();
	m_Comms.Notify("VIEW_VECTOR", str);
}



