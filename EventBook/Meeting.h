#pragma once
#include "Event.h"
#include <iostream>
#include < string>
using namespace std;

class Meeting : public Event
{

protected:
    string person;
    string place;

public:
    Meeting();
    Meeting(string person, string place, Date eventDate, Time_ eventTime);
    ~Meeting();

    Date getEventDate() const&;
    Time_ getEventTime() const&;
    void setEventDate(Date eventDate);
    void setEventTime(Time_ eventTime);

    string getPerson();
    string getPlace();
    void setPerson(string person);
    void setPlace(string place);

    virtual string toString() const&  override;
    virtual string type() const& override;
};