#pragma once
#include "Event.h"

class BirthDay : public Event
{

protected:
	string hero;
	string place;
	int age;

public: 
	BirthDay();
	BirthDay(string hero, string place, int age, Date eventDate, Time_ eventTime);
	~BirthDay();

	Date getEventDate() const&;
	Time_ getEventTime() const&;
	void setEventDate(Date eventDate);
	void setEventTime(Time_ eventTime);

	string getHero();
	string getPlace();
	int getAge();

	void setHero(string hero);
	void setPlace(string place);
	void setAge(int age);

	virtual string toString() const& override;
	virtual string type() const& override;
};