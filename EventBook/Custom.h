#pragma once
#include "Event.h"

class Custom : public Event
{

protected:

	string description;

public:

	Custom();
	Custom(string description, Date eventDate, Time_ eventTime);
	~Custom();

	Date getEventDate() const&;
	Time_ getEventTime() const&;
	void setEventDate(Date eventDate);
	void setEventTime(Time_ eventTime);

	string getDescription();
	void setDescription(string description);

	virtual string toString() const& override;
	virtual string type() const& override;
};