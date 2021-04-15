#pragma once
#include <string>
#include <iostream>
#include "Date.h"
#include "Time_.h"
using namespace std;

class Event
{
protected:

	Date eventDate;
	Time_ eventTime;

public:
	Event();
	Event(Date eventDate, Time_ eventTime);
	~Event();

	Date getEventDate() const&;
	Time_ getEventTime() const&;
	void setEventDate(Date eventDate);
	void setEventTime(Time_ eventTime);

	virtual string toString() const&;

	virtual string type() const&;

	bool operator ==(const Event& obj) const&;
	bool operator !=(const Event& obj) const&;
	bool operator <(const Event& obj) const&;
	bool operator <=(const Event& obj) const&;
	bool operator >(const Event& obj) const&;
	bool operator >=(const Event& obj) const&;
	//friend bool operator < (const Event* a, const Event*b);
};

struct compare:public Event {
	bool operator()(const Event* a, const Event* b) const
	{
		return a->getEventDate() < b->getEventDate() || a->getEventDate() == b->getEventDate() && a->getEventTime() < b->getEventTime();
	};
};