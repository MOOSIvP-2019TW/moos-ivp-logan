#include"Mode.h"

//------------------------------------------------------------
// Keepheading Mode
//------------------------------------------------------------
// Procedure: CalculateError
//   Purpose: Transform angle to the graph below and calculate error 
//
//   KeepHeading mode:              SetPoint mode:
//
//                                       foward         foward
//         left      0      right         left     0     right
//                   |                             |
//                   |                    -90      |      90
//         -90 ----- A ----- 90              ----- A -----       
//                   |                    -90      |      90           
//                   |                             |               
//              -180   180                left     0      right    
//                                      backward        backward   
void Keepheading::CalculateError()
{
	double error = geterror();
	if (error < -180)
	{
		error += 360;
	}
	else if (error > 180)
	{
		error -= 360;
	}
	seterror(error);
}

//------------------------------------------------------------
// Procedure: OutputThrust
//   Purpose: Notify thrust to MOOSDB based on different mode 
void Keepheading::Output(double thrust, double speed)
{
	setthrustl( thrust);
	setthrustr(-thrust);
}

//------------------------------------------------------------
// Forward Mode
//------------------------------------------------------------
// Procedure: CalculateError
//   Purpose: Transform angle to the graph below and calculate error 
//
//   KeepHeading mode:              SetPoint mode:
//
//                                       foward         foward
//         left      0      right         left     0     right
//                   |                             |
//                   |                    -90      |      90
//         -90 ----- A ----- 90              ----- A -----       
//                   |                    -90      |      90           
//                   |                             |               
//              -180   180                left     0      right    
//                                      backward        backward   
void Forward::CalculateError()
{	

	double error = geterror();
	if (error < -180)
	{
		error += 360;
	}
	else if (error > 180)
	{
		error -= 360;
	}
	seterror(error);
}

//------------------------------------------------------------
// Procedure: Output
//   Purpose: Notify thrust to MOOSDB based on different mode 
void Forward::Output(double thrust, double speed)
{
	setthrustl(speed + thrust);
	setthrustr(speed - thrust);
}

//------------------------------------------------------------
// Backward Mode
//------------------------------------------------------------
// Procedure: CalculateError
//   Purpose: Transform angle to the graph below and calculate error 
//
//   KeepHeading mode:              SetPoint mode:
//
//                                       foward         foward
//         left      0      right         left     0     right
//                   |                             |
//                   |                    -90      |      90
//         -90 ----- A ----- 90              ----- A -----       
//                   |                    -90      |      90           
//                   |                             |               
//              -180   180                left     0      right    
//                                      backward        backward   
void Backward::CalculateError()
{	

	double error = geterror();
	if (error < -180)
	{
		error += 360;
	}
	else if (error > 180)
	{
		error -= 360;
	}

	if(error < 180 && error > 90)
	{
		error = -error+180;
	}
	else if(error < -90 && error > -180)
	{
		error = -error-180;
	}
	seterror(error);
}

//------------------------------------------------------------
// Procedure: Output
//   Purpose: Notify thrust to MOOSDB based on different mode 
void Backward::Output(double thrust, double speed)
{
	setthrustl(-speed - thrust);
	setthrustr( speed + thrust);
}

