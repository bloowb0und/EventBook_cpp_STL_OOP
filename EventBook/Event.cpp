#include "Event.h"

Event::Event()
{
	this->eventDate = Date();
	this->eventTime = Time_();
}

Event::Event(Date eventDate, Time_ eventTime)
{
	this->eventDate = eventDate;
	this->eventTime = eventTime;
}

Event::~Event()
{
}

Date Event::getEventDate() const&
{
	return this->eventDate;
}

Time_ Event::getEventTime() const&
{
	return this->eventTime;
}

void Event::setEventDate(Date eventDate)
{
	this->eventDate = eventDate;
}

void Event::setEventTime(Time_ eventTime)
{
	this->eventTime = eventTime;
}

string Event::toString() const&
{
	return string();
}

string Event::type() const&
{
	return "Event";
}

bool Event::operator==(const Event& obj) const&
{
	if (this->eventDate == obj.eventDate && this->eventTime == obj.eventTime)
		return true;
	else
		return false;
}

bool Event::operator!=(const Event& obj) const&
{
	if (this->eventDate != obj.eventDate && this->eventTime != obj.eventTime)
		return true;
	else
		return false;
}

bool Event::operator<(const Event& obj) const&
{
	if (this->eventDate < obj.eventDate || this->eventDate == obj.eventDate && this->eventTime < obj.eventTime)
		return true;
	else
		return false;
}

bool Event::operator<=(const Event& obj) const&
{
	if (this->eventDate <= obj.eventDate || this->eventDate == obj.eventDate && this->eventTime <= obj.eventTime)
		return true;
	else
		return false;
}

bool Event::operator>(const Event& obj) const&
{
	if (this->eventDate > obj.eventDate || this->eventDate == obj.eventDate && this->eventTime > obj.eventTime)
		return true;
	else
		return false;
}

bool Event::operator>=(const Event& obj) const&
{
	if (this->eventDate >= obj.eventDate || this->eventDate == obj.eventDate && this->eventTime >= obj.eventTime)
		return true;
	else
		return false;
}