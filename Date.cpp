#include "Date.h"
#include <iostream>
#include <ctime>
using namespace std;

Date::Date()
{
	struct tm* tim = new tm;
	time_t tt = time(NULL);
	localtime_s(tim, &tt);

	year = 1900 + tim->tm_year;
	month = 1 + tim->tm_mon;
	day = tim->tm_mday;
}

Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::~Date()
{
	
}

Date::Date(const Date & obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
}

void Date::showDate()
{
	cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year << endl;
}

void Date::setYear(int year)
{
	if (year > 0) this->year = year;
}

int Date::getYear()
{
	return this->year;
}

void Date::setMonth(int month)
{
	if (month > 0 && month < 13) this->month = month;
}

int Date::getMonth()
{
	return this->month;
}

const char * Date::getSMonth(const char * language)
{
	if (strcmp(language, "EN") == 0) {
		
		switch (month)
		{
		case 1: return "January";
		case 2: return "February";
		case 3: return "March";
		case 4: return "April";
		case 5: return "May";
		case 6: return "June";
		case 7: return "July";
		case 8: return "August";
		case 9: return "September";
		case 10: return "October";
		case 11: return "November";
		case 12: return "December";
		default: return "Undefined";
		}
	}
	if (strcmp(language, "RU") == 0) {

		switch (month)
		{
		case 1: return "Январь";
		case 2: return "Февраль";
		case 3: return "Март";
		case 4: return "Апрель";
		case 5: return "Май";
		case 6: return "Июнь";
		case 7: return "Июль";
		case 8: return "Август";
		case 9: return "Сентябрь";
		case 10: return "Октябрь";
		case 11: return "Ноябрь";
		case 12: return "Декабрь";
		default: return "Неопределен";
		}
	}
	return "Undefined";
}

void Date::setDay(int day)
{
	if (day > 0 && day <= monthDays()) this->day = day;
}

int Date::getDay()
{
	return this->day;
}

bool Date::valid()
{
	return day > 0 && day <= monthDays() && year > 0;
}

bool Date::operator==(const Date & obj) const&
{
	if (this->day == obj.day && this->month == obj.month && this->year == obj.year) return true;
	else return false;
}

bool Date::operator!=(const Date & obj) const&
{
	return !(*this == obj);
}

bool Date::operator>(const Date & obj) const&
{
	if (this->year > obj.year) return true;
	else if (this->year == this->year && this->month > obj.month) return true;
	else if (this->year == obj.year && this->month == obj.month && this->day > obj.day) return true;
	else return false;
}

bool Date::operator<(const Date & obj) const&
{
	return !(*this > obj) && *this != obj;
}

bool Date::operator>=(const Date & obj) const&
{
	return *this > obj || *this == obj;
}

bool Date::operator<=(const Date & obj) const&
{
	return *this < obj || *this == obj;
}

Date & Date::operator=(const Date & obj)
{
	this-> day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
	return *this;
}

Date & Date::operator+=(int n)
{
	for (int i = 0; i < n; i++)
	{
		nextDate();
	}
	return *this;
}

Date & Date::operator-=(int n)
{
	for (int i = 0; i < n; i++)
	{
		prevDate();
	}
	return *this;
}

Date Date::operator+(int n)
{
	Date tmp = *this;
	for (int i = 0; i < n; i++)
	{
		tmp.nextDate();
	}
	return tmp;
}

Date Date::operator-(int n)
{
	Date tmp = *this;
	for (int i = 0; i < n; i++)
	{
		tmp.prevDate();
	}
	return tmp;
}

Date & Date::operator--()
{
	this->prevDate();
	return *this;
}

Date Date::operator--(int n)
{
	Date tmp = *this;
	this->prevDate();
	return tmp;
}

Date & Date::operator++()
{
	this->nextDate();
	return *this;
}

Date Date::operator++(int n)
{
	Date tmp = *this;
	this->nextDate();
	return tmp;
}

bool Date::isLeapYear()
{
	if (year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0)) return true;
	else return false;
}

int Date::monthDays()
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	else if (month == 2) {
		return isLeapYear() ? 29 : 28;
	}
	return -1;
}

void Date::nextDate()
{
	if (month == 12 && day == 31) {
		day = 1; 
		month = 1;
		year++;
	}
	else if (day == monthDays()) {
		day = 1;
		month++;
	}
	else {
		day++;
	}
}

void Date::prevDate()
{
	if (month == 1 && day == 1) {
		day = 31;
		month = 12;
		year--;
	}
	else if (day == 1) {
		day = monthDays();
		month--;
	}
	else {
		day--;
	}
}

ostream & operator<<(ostream & os, const Date & t)
{
	os << t.day / 10 << t.day % 10 << "." << t.month / 10 << t.month % 10 << "." << t.year;
	return os;
}

istream & operator>>(istream & is, Date & t)
{
	
	do
	{
		cout << "DD MM YYYY: ";
		is >> t.day >> t.month >> t.year;
	} while (!(t.valid()));
	
	return is;
}
