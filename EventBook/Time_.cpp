#include "Time_.h"
#include <iostream>
using namespace std;

Time_::Time_()
{
	struct tm *tim = new tm;
	time_t tt = time(NULL);
	localtime_s(tim, &tt);
	strcpy_s(this->format, "utc");
	this->hour = tim->tm_hour;
	this->minutes = tim->tm_min;
	this->seconds = tim->tm_sec;
}

Time_::Time_(int hour, int minutes, int seconds, const char * format)
{
	strcpy_s(this->format, format);
	if(strcmp(this->format, "utc") == 0 && hour > 0 && hour < 25) this->hour = hour;
	else if (strcmp(this->format, "utc") != 0 && hour > 0 && hour < 13) this->hour = hour;
	this->minutes = minutes;
	this->seconds = seconds;
}

Time_::Time_(const Time_ & obj)
{
	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;
	strcpy_s(this->format, obj.format);
}

Time_::~Time_()
{

}

void Time_::setHour(int hour)
{
	if (strcmp(format, "utc") == 0) {
		if (hour > 0 && hour < 25) this->hour = hour;
	}
	else {
		if (hour < 13) {
			this->hour = hour;
			strcpy_s(this->format, "am");
		}
		else {
			this->hour = hour - 12;
			strcpy_s(this->format, "pm");
		}
	}
}

int Time_::getHour()
{
	return this->hour;
}

void Time_::setMinutes(int minutes)
{
	if (minutes >= 0 && minutes < 60) this->minutes = minutes;
}

int Time_::getMinutes()
{
	return this->minutes;
}

void Time_::setSeconds(int seconds)
{
	if (seconds >= 0 && seconds < 60) this->seconds = seconds;
}

int Time_::getSeconds()
{
	return this->seconds;
}

void Time_::setFormat(const char * format)
{
	if (strcmp(format, "utc") == 0) {
		if (strcmp(this->format, "pm") == 0) this->hour += 12;
		strcpy_s(this->format, format);
	}
	else if (strcmp(format, "am") == 0 || strcmp(format, "pm") == 0) {
		strcpy_s(this->format, format);
		if (this->hour > 12) this->hour -= 12;
	}
}

const char * Time_::getFormat()
{
	return this->format;
}

bool Time_::valid()
{
	if (strcmp(this->format, "utc") == 0) {
		if (this->hour > 0 && this->hour < 25 && this->minutes >= 0 && this->minutes < 60 && this->seconds >= 0 && this->seconds < 60) return true;
	}
	else if(strcmp(this->format, "am") == 0 || strcmp(this->format, "pm") == 0){
		if (this->hour > 0 && this->hour < 13 && this->minutes >= 0 && this->minutes < 60 && this->seconds >= 0 && this->seconds < 60) return true;
	}
	else return false;
}

void Time_::tickTime()
{
	this->seconds++;
	if (this->seconds >= 60) {
		this->minutes++;
		this->seconds = 0;
	}
	if (this->minutes >= 60) {
		this->hour++;
		this->minutes = 0;
	}
	if (this->hour >= 24 && strcmp(this->format, "utc") == 0) this->hour = 1;
	else if (this->hour >= 12 && strcmp(this->format, "am") == 0 || this->hour >= 12 && strcmp(this->format, "pm") == 0) this->hour = 1;
}

void Time_::backTime()
{
	this->seconds--;
	if (this->seconds < 0) {
		minutes--;
		seconds = 59;
	}
	else if (this->minutes < 0) {
		hour--;
		minutes = 59;
	}
	else if (this->hour < 1 && strcmp(this->format, "utc") == 0) {
		this->hour = 24;
	}
	else {
		this->hour = 12;
	}
}

void Time_::showTime()
{
	if (strcmp(this->format, "utc") == 0) cout << this->hour / 10 << this->hour % 10 << ":" << this->minutes / 10 << this->minutes % 10 << endl;
	else if (strcmp(this->format, "am") == 0) cout << this->hour / 10 << this->hour % 10 << " AM " << this->minutes / 10 << this->minutes % 10 << endl;
	else if (strcmp(this->format, "pm") == 0) cout << this->hour / 10 << this->hour % 10 << " PM " << this->minutes / 10 << this->minutes % 10 << endl;
	cout << "Seconds: " << this->seconds / 10 << this->seconds % 10 << endl; //I printed it also for myselve
}

bool Time_::operator==(const Time_ & obj)const&
{
	if (this->hour == obj.hour && this->minutes == obj.minutes && this->seconds == obj.seconds && strcmp(this->format, obj.format) == 0) return true;
	else if (strcmp(this->format, "utc") == 0 && strcmp(obj.format, "pm") == 0) {
		if (this->hour == obj.hour + 12 && this->minutes == obj.minutes && this->seconds == obj.seconds) return true;
	}
	else if (strcmp(this->format, "pm") == 0 && strcmp(obj.format, "utc") == 0) {
		if (this->hour + 12 == obj.hour && this->minutes == obj.minutes && this->seconds == obj.seconds) return true;
	}
	return false;
}
bool Time_::operator!=(const Time_ & obj)const&
{
	return !(*this == obj);
}

bool Time_::operator>(const Time_ & obj)const&
{
	if (strcmp(this->format, obj.format) == 0 && strcmp(this->format, "utc") == 0) {
		if (this->hour > obj.hour) return true;
		else if (this->hour == obj.hour && this->minutes > obj.minutes) return true;
		else if (this->hour == obj.hour && this->minutes == obj.minutes && this->seconds > obj.seconds) return true;
		else return false;
	}
	else if (strcmp(this->format, "am") == 0 && strcmp(obj.format, "pm") == 0) return false;
	else if (strcmp(this->format, "pm") == 0 && strcmp(obj.format, "am") == 0) return true;
	else if (strcmp(this->format, "utc") == 0 && strcmp(obj.format, "pm") == 0) {
		if (this->hour > obj.hour + 12) return true;
		else if (this->hour == obj.hour + 12 && this->minutes > obj.minutes) return true;
		else if (this->hour == obj.hour + 12 && this->minutes == obj.minutes && this->seconds > obj.seconds) return true;
		else return false;
	}
	else if (strcmp(this->format, "pm") == 0 && strcmp(obj.format, "utc") == 0) {
		if (this->hour + 12 > obj.hour) return true;
		else if (this->hour + 12 == obj.hour && this->minutes > obj.minutes) return true;
		else if (this->hour + 12 == obj.hour && this->minutes == obj.minutes && this->seconds > obj.seconds) return true;
		else return false;
	}
}

bool Time_::operator<(const Time_ & obj)const&
{
	return !(*this > obj) && *this != obj;
}

bool Time_::operator>=(const Time_ & obj)const&
{
	return *this > obj || *this == obj;
}

bool Time_::operator<=(const Time_ & obj)const&
{
	return *this < obj || *this == obj;
}

Time_ & Time_::operator=(const Time_ & obj) 
{
	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;
	strcpy_s(this->format, obj.format);
	return *this;
}

Time_ & Time_::operator+=(int n)
{
	for (int i = 0; i < n; i++)
	{
		tickTime();
	}
	return *this;
}

Time_ & Time_::operator-=(int n)
{
	for (int i = 0; i < n; i++)
	{
		backTime();
	}
	return *this;
}

Time_ Time_::operator+(int n)
{
	Time_ tmp = *this;
	for (int i = 0; i < n; i++)
	{
		tmp.tickTime();
	}
	return tmp;
}

Time_ Time_::operator-(int n)
{
	Time_ tmp = *this;
	for (int i = 0; i < n; i++)
	{
		tmp.backTime();
	}
	return tmp;
}

Time_ & Time_::operator--()
{
	this->backTime();
	return *this;
}

Time_ & Time_::operator--(int n)
{
	Time_ tmp = *this;
	tmp.backTime();
	return tmp;
}

Time_ & Time_::operator++()
{
	this->tickTime();
	return *this;
}

Time_ & Time_::operator++(int n)
{
	Time_ tmp = *this;
	tmp.tickTime();
	return tmp;
}

ostream & operator<<(ostream & os, const Time_ & t)
{
	if (strcmp(t.format, "utc") == 0) os << t.hour / 10 << t.hour % 10 << " " << t.minutes / 10 << t.minutes % 10;
	else if (strcmp(t.format, "am") == 0) os << t.hour / 10 << t.hour % 10 << " AM " << t.minutes / 10 << t.minutes % 10;
	else if (strcmp(t.format, "pm") == 0) os << t.hour / 10 << t.hour % 10 << " PM " << t.minutes / 10 << t.minutes % 10;
	os << " " << t.seconds / 10 << t.seconds % 10;
	return os;
}

istream & operator>>(istream & is, Time_ & t)
{	
	do
	{
		cout << "Input hours, minutes, seconds: ";
		is >> t.hour >> t.minutes >> t.seconds;
		strcpy_s(t.format, 4, "utc");
	} while (!(t.valid()));
	return is;
}
