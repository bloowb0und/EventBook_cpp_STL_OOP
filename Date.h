#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
	int year;
	int month;
	int day;
	bool isLeapYear(); //Проверка на високосный год
	int monthDays(); //Количество дней по месяцу
	void nextDate(); //Следующая дата
	void prevDate();


public:
	Date();
	Date(int year, int month, int day);
	~Date();
	Date(const Date& obj);
	//-------------

	void showDate();


	//------------------

	void setYear(int year);
	int getYear();
	void setMonth(int month);
	int getMonth();
	const char* getSMonth(const char* = "EN");
	void setDay(int day);
	int getDay();

	bool valid(); //Проверка даты на корректность

	//-----------------

	bool operator == (const Date& obj) const&;
	bool operator != (const Date& obj) const&;
	bool operator > (const Date& obj) const&;
	bool operator < (const Date& obj) const&;
	bool operator >= (const Date& obj) const&;
	bool operator <= (const Date& obj) const&;

	Date& operator = (const Date& obj);
	Date& operator += (int n);
	Date& operator -= (int n);

	Date operator + (int n);
	Date operator - (int n);

	Date& operator -- ();
	Date operator -- (int n);
	Date& operator ++ ();
	Date operator ++ (int n);

	friend ostream& operator << (ostream&os, const Date& t);
	friend istream& operator >> (istream& is, Date& t);


};

