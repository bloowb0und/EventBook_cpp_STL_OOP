#pragma once
#include <time.h>
#include <iostream>
#include <cstring>
using namespace std;
class Time_
{
private:
	int hour;
	int minutes;
	int seconds;
	char format[4]; //am/pm and utc
public:
	Time_(); //current time
	Time_(int hour, int minutes, int seconds, const char*format = "utc");
	Time_(const Time_& obj);
	~Time_();

	//----------------------------------------------------------------------

	void setHour(int hour);
	int getHour();
	void setMinutes(int minutes);
	int getMinutes();
	void setSeconds(int seconds);
	int getSeconds();
	void setFormat(const char* format); // !!! to update time by the new format: utc
	const char* getFormat(); //utc/am/pm

	//-----------------------------------------------------------------------

	bool valid(); //time check
	void tickTime(); //every tick add one second
	void backTime();
	void showTime(); //show time by the format

	//--------- Comparison operators ---------
	bool operator == (const Time_& obj)const&;
	bool operator != (const Time_& obj)const&;
	bool operator > (const Time_& obj)const&;
	bool operator < (const Time_& obj)const&;
	bool operator >= (const Time_& obj)const&;
	bool operator <= (const Time_& obj)const&;

	//--------- Assignment operators ---------
	Time_& operator = (const Time_& obj);
	Time_& operator += (int n);
	Time_& operator -= (int n);

	//--------- Arithmetic operators ---------
	Time_ operator + (int n);
	Time_ operator - (int n);

	Time_& operator -- ();
	Time_& operator -- (int n);
	Time_& operator ++ ();
	Time_& operator ++ (int n);

	friend ostream& operator << (ostream& os, const Time_& t);
	friend istream& operator >> (istream& is, Time_& t);

};

