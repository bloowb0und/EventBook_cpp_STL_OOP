#include "BirthDay.h"

BirthDay::BirthDay()
{
	this->hero = "Nobody chosen";
	this->place = "None";
	this->age = 0;
}

BirthDay::BirthDay(string hero, string place, int age, Date eventDate, Time_ eventTime)
{
	this->eventDate = eventDate;
	this->eventTime = eventTime;
	this->hero = hero;
	this->place = place;
	this->age = age;
}

BirthDay::~BirthDay()
{
}

Date BirthDay::getEventDate() const&
{
	return this->eventDate;
}

Time_ BirthDay::getEventTime() const&
{
	return this->eventTime;
}

void BirthDay::setEventDate(Date eventDate)
{
	this->eventDate = eventDate;
}

void BirthDay::setEventTime(Time_ eventTime)
{
	this->eventTime = eventTime;
}

string BirthDay::getHero()
{
	return this->hero;
}

string BirthDay::getPlace()
{
	return this->place;
}

int BirthDay::getAge()
{
	return this->age;
}

void BirthDay::setHero(string hero)
{
	if (hero.length() > 0)
		this->hero = hero;
	else
		cout << "Error\n";
}

void BirthDay::setPlace(string place)
{
	if (place.length() > 0)
		this->place = place;
	else
		cout << "Error\n";
}

void BirthDay::setAge(int age)
{
	if (age > 0)
		this->age = age;
	else
		cout << "Error\n";
}

string BirthDay::toString() const&
{
	string str;
	
	str = "Hero: ";
	str = str + this->hero;
	str = str + " | Place: ";
	str = str + this->place;
	str = str + " | Age: ";
	str = str + to_string(this->age);

	return str;
}

string BirthDay::type() const&
{
	return "Birthday";
}
