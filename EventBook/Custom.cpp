#include "Custom.h"

Custom::Custom():Event()
{
	this->description = "We are going to the cinema today =)\n";
}

Custom::Custom(string description, Date eventDate, Time_ eventTime)
{
	this->description = description;

	this->eventDate = eventDate;
	this->eventTime = eventTime;
}

Custom::~Custom()
{
}

Date Custom::getEventDate() const&
{
	return this->eventDate;
}

Time_ Custom::getEventTime() const&
{
	return this->eventTime;
}

void Custom::setEventDate(Date eventDate)
{
	this->eventDate = eventDate;
}

void Custom::setEventTime(Time_ eventTime)
{
	this->eventTime = eventTime;
}

string Custom::getDescription()
{
	return this->description;
}

void Custom::setDescription(string description)
{
	if (description.length() > 0)
		this->description = description;
	else
		cout << "Error\n";
}

string Custom::toString() const&
{
	string str;

	str = "Description: ";
	str = str + this->description;

	return str;
}

string Custom::type() const&
{
	return "Custom";
}
