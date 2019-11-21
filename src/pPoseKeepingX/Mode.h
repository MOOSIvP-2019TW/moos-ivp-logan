/************************************************************/
/*    NAME: Logan Zhang                                     */
/*    ORGN: MIT                                             */
/*    FILE: Mode.h                                          */
/*    DATE: October  23h, 2019                             */
/************************************************************/

#ifndef Mode_HEADER
#define Mode_HEADER

#include<iostream>
using namespace std;

class Mode
{
private:
    /* data */
    double m_curr_error = 0;
    string m_mode = "NULL";
    double m_thrust_r = 0;
    double m_thrust_l = 0;

public:
    // constructor & destructor
    Mode() {}
    Mode(double error){
	m_curr_error = error;
    }
    virtual ~Mode() {}
    // setter
    void seterror(double error)		{m_curr_error = error;}
    void setmode(string mode)		{m_mode = mode;}
    void setthrustr(double thrust)	{m_thrust_r = thrust;}
    void setthrustl(double thrust)	{m_thrust_l = thrust;}
    
    // getter
    double geterror() const	{return m_curr_error;}
    string getmode() const	{return m_mode;}
    double getthrustr() const	{return m_thrust_r;}
    double getthrustl() const	{return m_thrust_l;}

    // abstract functions
    virtual void CalculateError() = 0;
    virtual void Output(double, double) = 0;
};

class Keepheading: public Mode
{
public:
    Keepheading(double error): Mode(error) {
        setmode("Keepheading");
    }
    ~Keepheading() {}
    void CalculateError();
    void Output(double, double);
};

class Forward: public Mode
{
public:
    Forward(double error): Mode(error) {
        setmode("Forward");
    }
    ~Forward() {}
    void CalculateError();
    void Output(double, double);
};

class Backward: public Mode
{
public:
    Backward(double error): Mode(error) {
        setmode("Backward");
    }
    ~Backward() {}
    void CalculateError();
    void Output(double, double);
};

#endif 
