#pragma once
#include <iostream>
using namespace std;

class Date
{
	int year;
	int month;
	int day;

	bool isLeapYear(); //Ïðîâåðêà íà âèñîêîñíûé ãîä
	int monthDays(); //Êîëè÷åñòâî äíåé ïî ìåñÿöó
	void nextDate(); //Ñëåäóþùàÿ äàòà
	void prevDate(); //Ïðåäûäóùàÿ äàòà

public:
	//---------ÊÎÍÑÒÐÓÊÒÎÐÛ è ÄÅÑÒÐÓÊÒÎÐ---------
	Date(); // Ïî óìîë÷àíèþ  - òåêóùàÿ äàòà
	Date(int year, int month, int day); //Ñ ïàðàìåòðàìè - çàäàííàÿ äàòà
	Date(const Date& obj); //Êîïèðîâàíèÿ
	~Date();// Äåñòðóêòîð

	void showInfo();

	//---------ÀÊÑÅÑÑÎÐÛ---------
	void setYear(int year);
	int getYear();
	void setMonth(int month);
	int getMonth();
	const char* getSMonth(const char* = "EN");
	void setDay(int day);
	int getDay();

	bool valid(); //Ïðîâåðêà äàòû íà êîððåêòíîñòü

	//--------- ÎÏÅÐÀÒÎÐÛ ÑÐÀÂÍÅÍÈß ---------
	bool operator == (const Date& obj) const&;
	bool operator != (const Date& obj) const&;
	bool operator > (const Date& obj) const&;
	bool operator < (const Date& obj) const&;
	bool operator >= (const Date& obj) const&;
	bool operator <= (const Date& obj) const&;

	//--------- ÎÏÅÐÀÒÎÐÛ ÏÐÈÑÂÎÅÍÈß ---------
	Date& operator = (const Date& obj);
	Date& operator += (int n);
	Date& operator -= (int n);

	//--------- ÀÐÈÔÌÅÒÈ×ÅÑÊÈÅ ÎÏÅÐÀÒÎÐÛ ---------
	Date operator + (int n);
	Date operator - (int n);
	int operator - (const Date &obj);
	//---------Èíêðèìåíòûá äèêðèìåíòû è-------------



	Date& operator -- ();
	Date operator -- (int n);
	Date& operator ++ ();
	Date operator ++ (int n);
	friend ostream& operator << (ostream& os, const Date& t);
	friend istream& operator >> (istream& is, Date& t);
};