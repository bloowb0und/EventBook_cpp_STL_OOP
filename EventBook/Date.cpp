#include "Date.h"
#include <iostream>
#include <ctime>
using namespace std;

bool Date::isLeapYear()
{
	if (year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0))
		return true;
	else
		return false;
}

int Date::monthDays()
{
		if (month == 2 && !isLeapYear())
			return 28;
		else if (month == 2 && isLeapYear())
			return 29;
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			return 31;
		else if (month == 4 || month == 6 || month == 9 || month == 11)
			return 30;
		return -1;
}

void Date::nextDate()
{
	if (month == 12 && day == monthDays())
	{
		month = 1;
		day = 1;
		year++;
	}
	else if (day == monthDays())
	{
		month++;
		day = 1;
	}
	else
	{
		day++;
	}
}

void Date::prevDate()
{
	if (month == 1 && day == 1)
	{
		month = 12;
		day = monthDays();
		year--;
	}
	else if (day == 1)
	{
		month--;
		day = monthDays();
	}
	else
	{
		day--;
	}
}

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;

	struct tm *tim = new tm;
	time_t tt = time(NULL);
	localtime_s(tim, &tt);
	year = 1900 + tim->tm_year;
	month = 1 + tim->tm_mon;
	day = tim->tm_mday;
}

Date::Date(int year, int month, int day)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(const Date& obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
}

Date::~Date()
{
}

void Date::showInfo()
{
	cout << day / 10 << day % 10 << "/" << month / 10 << month % 10 << "/" << year << endl;
}

void Date::setYear(int year)
{
	if (year > 0)
	{
		this->year = year;
	}
}

int Date::getYear()
{
	return this->year;
}

void Date::setMonth(int month)
{
	if (month >= 1 && month <= 12)
	{
		this->month = month;
	}
}

int Date::getMonth()
{
	return this->month;
}

const char* Date::getSMonth(const char* lang)
{
	if (strcmp(lang, "EN") == 0 || strcmp(lang, "en") == 0 || strcmp(lang, "En") == 0 || strcmp(lang, "eN") == 0)
	{
		switch (this->month)
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
	else if (strcmp(lang, "RU") == 0 || strcmp(lang, "ru") == 0 || strcmp(lang, "Ru") == 0 || strcmp(lang, "rU") == 0)
	{
		switch (this->month)
		{
		case 1: return "Январь";
		case 2: return "Февраль";
		case 3: return "Март";
		case 4: return "Апрель";
		case 5: return "Март";
		case 6: return "Июнь";
		case 7: return "Июль";
		case 8: return "Август";
		case 9: return "Сентябрь";
		case 10: return "Октябрь";
		case 11: return "Ноябрь";
		case 12: return "Декабрь";
		default: return "Неопределено";
		}
	}
	return "No such language available. Try EN or RU";
}

void Date::setDay(int day)
{
	if (day >= 1 && day <= monthDays())
	{
		this->day = day;
	}
}

int Date::getDay()
{
	return this->day;
}

bool Date::valid()
{
	if (year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= monthDays())
		return true;
	else
		return false;
}

bool Date::operator==(const Date& obj) const&
{
	if (this->day == obj.day && this->month == obj.month && this->year == obj.year)
		return true;
	else
		return false;
}

bool Date::operator!=(const Date& obj) const&
{
	if (this->day == obj.day && this->month == obj.month && this->year == obj.year)
		return false;
	else
		return true;
}

bool Date::operator>(const Date& obj) const&
{
	if (this->year > obj.year)
		return true;
	else if (this->year == obj.year && this->month > obj.month)
		return true;
	else if (this->year == obj.year && this->month == obj.month && this->day > obj.month)
		return true;
	else
		return false;
}

bool Date::operator<(const Date& obj) const&
{
	if (*this != obj && !(*this > obj))
		return true;
	else
		return false;
}

bool Date::operator>=(const Date& obj) const&
{
	if (*this==obj || *this>obj)
		return true;
	else
		return false;
}

bool Date::operator<=(const Date& obj) const&
{
	if (!(*this>obj))
		return true;
	else
		return false;
}

Date& Date::operator=(const Date& obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
	return *this;
}

Date& Date::operator+=(int n)
{
	for (int i = 0; i < n; i++)
	{
		nextDate();
	}
	return *this;
}

Date& Date::operator-=(int n)
{
	for (int i = 0; i < n; i++)
	{
		prevDate();
	}
	return *this;
}

Date Date::operator+(int n)
{
	Date tmp;
	tmp = *this;
	for (int i = 0; i < n; i++)
	{
		tmp.nextDate();
	}
	return tmp;
}

Date Date::operator-(int n)
{
	Date tmp;
	tmp = *this;
	for (int i = 0; i < n; i++)
	{
		tmp.prevDate();
	}
	return tmp;
}

int Date::operator-(const Date& obj)
{
	int d = 0;
	Date tmp = *this;
	if (*this > obj) {
		while (tmp > obj) {
			tmp--;
			d++;
		}
	}
	else if (tmp < obj) {
		while (tmp < obj) {
			tmp++;
			d++;
		}
	}
	return d;
}

Date& Date::operator--()
{
	// TODO: insert return statement here
	this->prevDate();
	return *this;

}

Date Date::operator--(int n)
{
	// TODO: insert return statement here
	Date tmp = *this;
	this->prevDate();
	return tmp;
}

Date& Date::operator++()
{
	// TODO: insert return statement here
	this->nextDate();
	return *this;
}

Date Date::operator++(int n)
{
	Date tmp = *this;
	this->nextDate();
	return tmp;
	// TODO: insert return statement here
}

ostream& operator<<(ostream& os, const Date& t)
{
	// TODO: insert return statement here
	os << t.day / 10 << t.day % 10 << " " << t.month / 10 << t.month % 10 << " " << t.year;
	return os;
}

istream& operator>>(istream& is, Date& t)
{
	// TODO: insert return statement here
	cout << "DD MM YYYY: " << endl;
	is >> t.day >> t.month >> t.year;
	return is;
}
