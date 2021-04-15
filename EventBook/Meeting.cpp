#include "Meeting.h"

Meeting::Meeting()
{
	person = "Vasiliy Vusokiy";
	place = "Naberejnaja 24";
}

Meeting::Meeting(string person, string place, Date eventDate, Time_ eventTime)
{
	this->person = person;
	this->place = place;

	this->eventDate = eventDate;
	this->eventTime = eventTime;
}

Meeting::~Meeting()
{
}

Date Meeting::getEventDate() const&
{
	return this->eventDate;
}

Time_ Meeting::getEventTime() const&
{
	return this->eventTime;
}

void Meeting::setEventDate(Date eventDate)
{
	this->eventDate = eventDate;
}

void Meeting::setEventTime(Time_ eventTime)
{
	this->eventTime = eventTime;
}

string Meeting::getPerson()
{
	return this->person;
}

string Meeting::getPlace()
{
	return this->place;
}

void Meeting::setPerson(string person)
{
	if (person.length() > 0)
		this->person = person;
	else
		cout << "Error\n";
}

void Meeting::setPlace(string place)
{
	if (place.length() > 0)
		this->place = place;
	else
		cout << "Error\n";
}

string Meeting::toString() const&
{
	string str;

	str = "Person: ";
	str = str + this->person;
	str = str + " | Place: ";
	str = str + this->place;

	return str;
}

string Meeting::type() const&
{
	return "Meeting";
}
