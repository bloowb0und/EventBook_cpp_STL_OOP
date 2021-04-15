#pragma once
#include "Event.h"
#include <set>
#include <algorithm>
#include "BirthDay.h"
#include "Custom.h"
#include "Meeting.h"
#include <fstream>
using namespace std;

class Events
{
	set<Event*, compare> events;

public:
	void add();
	void del();
	void show();

	void FindByTime();
	void FindByDate();
	void FindByHero();
	void FindByPlace();
	void FindByDescriptions();

	set<Event*, compare> readFromFile(string s1);
	void writeToFile(string s1);
};