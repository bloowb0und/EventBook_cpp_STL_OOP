#include "Events.h"

void Events::add()
{
	int eventType = 0;
	set<Event*, compare>::iterator item;

	string str1, str2, str3;
	Date d;
	Time_ t;
	int a;
	bool ifExists = false;

	cout << "What type of event do you want to add? (1 - birthday; 2 - meeting; 3 - custom)\n";
	cin >> eventType;

	cout << "Enter event date: ";
	cin >> d;

	cout << "Enter event time: ";
	cin >> t;

	for (item = events.begin(); item != events.end(); item++)
	{
		if ((*item)->getEventDate() == d && (*item)->getEventTime() == t)
		{
			ifExists == true;
			break;
		}
	}

	if (!ifExists)
	{
		switch (eventType)
		{
		default:
			cout << "Error while choosing event type\n";
			break;

		case 1:
			cout << "Enter hero: ";
			cin.get();
			getline(cin, str1);

			cout << "Enter place: ";
			getline(cin, str2);

			cout << "Enter age: ";
			cin >> a;

			events.insert(new BirthDay(str1, str2, a, d, t));

			break;

		case 2:
			cout << "Enter person: ";
			cin.get();
			getline(cin, str1);

			cout << "Enter place: ";
			getline(cin, str2);

			events.insert(new Meeting(str1, str2, d, t));

			break;

		case 3:
			cout << "Enter event description: ";
			cin.get();
			getline(cin, str1);

			events.insert(new Custom(str1, d, t));

			break;
		}
	}
	else
		cout << "There's an event planned for this date and time\n";
}

void Events::del()
{
	set<Event*, compare>::iterator item;
	set<Event*, compare>::iterator itemDel;

	string str1, str2, str3;
	Date d;
	Time_ t;
	int a;
	bool ifExists = false;

	cout << "Enter event date: ";
	cin >> d;

	cout << "Enter event time: ";
	cin >> t;

	for (item = events.begin(); item != events.end(); item++)
	{
		if ((*item)->getEventDate() == d && (*item)->getEventTime() == t)
		{
			ifExists = true;
			break;
		}
	}

	if (ifExists)
	{
		for (item = events.begin(); item != events.end();)
		{
			itemDel = item;
			item++;

			if ((*itemDel)->getEventDate() == d && (*itemDel)->getEventTime() == t)
			{
				events.erase(itemDel);

				break;
			}
		}
	}
	else
		cout << "There's no events planned for this date and time\n";
}

void Events::show()
{
	set<Event*, compare>::iterator item;

	if (!(this->events.empty()))
	{
		for (item = events.begin(); item != events.end(); item++)
		{
			cout << "-=Event Type=- " << (*item)->type() << endl;
			cout << (*item)->toString() <<  " | " << (*item)->getEventDate() <<  " | " << (*item)->getEventTime() << endl;
			cout << "---------------------------------------------\n";
		}
	}
	else
	{
		cout << "No events were added\n";
	}
}

void Events::FindByTime()
{
	Time_ time;
	cout << "Enter Time:";
	cin >> time;
	set<Event*>::iterator iter_time;
	for (iter_time = events.begin(); iter_time != events.end(); iter_time++)
	{
		if (time == (*iter_time)->getEventTime()) {
			cout << "-=Event Type=- " << (*iter_time)->type() << endl;
			cout << (*iter_time)->toString() <<  " | " << (*iter_time)->getEventDate() <<  " | " << (*iter_time)->getEventTime() << endl;
			cout << "---------------------------------------------\n";
		}
	}
}

void Events::FindByDate()
{
	Date date;
	cout << "Enter Date:";
	cin >> date;
	set<Event*>::iterator iter_date;

	for (iter_date = events.begin(); iter_date != events.end(); iter_date++)
	{
		if (date == (*iter_date)->getEventDate()) {
			cout << "-=Event Type=- " << (*iter_date)->type() << endl;
			cout << (*iter_date)->toString() <<  " | " << (*iter_date)->getEventDate() <<  " | " << (*iter_date)->getEventTime() << endl;
			cout << "---------------------------------------------\n";
		}
	}
}

void Events::FindByHero()
{
	set<BirthDay*> bday;
	set<BirthDay*>::iterator iter_bday;
	string hero;

	cout << "Enter hero:";
	cin.get();
	getline(cin, hero);

	set<Event*>::iterator iter_hero;

	for (iter_hero = events.begin(); iter_hero != events.end(); iter_hero++)
	{
		if ((*iter_hero)->type() == "Birthday") {
			bday.insert(((BirthDay*)(*iter_hero)));
		}
	}

	for (iter_bday = bday.begin(); iter_bday != bday.end(); iter_bday++)
	{
		if ((*iter_bday)->getHero() == hero)
		{
			cout << "-=Event Type=- " << (*iter_bday)->type() << endl;
			cout << (*iter_bday)->toString() <<  " | " << (*iter_bday)->getEventDate() <<  " | " << (*iter_bday)->getEventTime() << endl;
			cout << "---------------------------------------------\n";
		}
	}
}

void Events::FindByPlace()
{
	set<Meeting*> place;
	set<Meeting*>::iterator iter_place;
	set<BirthDay*> bday;
	set<BirthDay*>::iterator iter_bday;
	string place1;

	cout << "Enter place: ";
	cin.get();
	getline(cin, place1);

	set<Event*>::iterator iter_plc;

	for (iter_plc = events.begin(); iter_plc != events.end(); iter_plc++)
	{
		if ((*iter_plc)->type() == "Meeting") {
			place.insert(((Meeting*)(*iter_plc)));
		}
		else if ((*iter_plc)->type() == "Birthday") {
			bday.insert(((BirthDay*)(*iter_plc)));
		}
	}

	for (iter_place = place.begin(); iter_place != place.end(); iter_place++) {
		if ((*iter_place)->getPlace() == place1)
		{
			cout << "-=Event Type=- " << (*iter_place)->type() << endl;
			cout << (*iter_place)->toString() <<  " | " << (*iter_place)->getEventDate() <<  " | " << (*iter_place)->getEventTime() << endl;
			cout << "---------------------------------------------\n";
		}
	}

	for (iter_bday = bday.begin(); iter_bday != bday.end(); iter_bday++)
	{
		if ((*iter_bday)->getPlace() == place1)
		{
			cout << "-=Event Type=- " << (*iter_bday)->type() << endl;
			cout << (*iter_bday)->toString() <<  " | " << (*iter_bday)->getEventDate() <<  " | " << (*iter_bday)->getEventTime() << endl;
			cout << "---------------------------------------------\n";
		}
	}
}

void Events::FindByDescriptions()
{
	set<Custom*> desc;
	set<Custom*>::iterator iter_desc;
	string desc1;

	cout << "Enter descriptions: ";
	cin.get();
	getline(cin, desc1);

	set<Event*>::iterator iter_dsc;

	for (iter_dsc = events.begin(); iter_dsc != events.end(); iter_dsc++)
	{
		if ((*iter_dsc)->type() == "Custom") {
			desc.insert(((Custom*)(*iter_dsc)));
		}
	}

	for (iter_desc = desc.begin(); iter_desc != desc.end(); iter_desc++)
	{
		if ((*iter_desc)->getDescription() == desc1)
		{
			cout << "-=Event Type=- " << (*iter_desc)->type() << endl;
			cout << (*iter_desc)->toString() << " | " << (*iter_desc)->getEventDate() <<  " | " << (*iter_desc)->getEventTime() << endl;
			cout << "---------------------------------------------\n";
		}
	}
}

set<Event*, compare> Events::readFromFile(string s1)
{
	ifstream file1(s1);
	set <Event*, compare> tmp;

	if (!file1.is_open())
	{
		cout << "There was an error opening a file.\n";
	}
	else
	{
		string type;
		string str1, str2, str3;
		Date d;
		Time_ t;
		int a;

		while (!file1.eof())
		{
			system("cls");
			getline(file1, type);

			if (type == "Birthday")
			{
				system("cls");
				file1 >> d;
				file1 >> t;
				file1 >> str1;
				file1 >> str2;
				file1 >> a;

				tmp.insert(new BirthDay(str1, str2, a, d, t));
			}
			else if (type == "Meeting")
			{
				system("cls");
				file1 >> d;
				file1 >> t;
				file1 >> str1;
				file1 >> str2;

				tmp.insert(new Meeting(str1, str2, d, t));
			}
			else if (type == "Custom")
			{
				system("cls");
				file1 >> d;
				file1 >> t;
				file1 >> str1;

				tmp.insert(new Custom(str1, d, t));
			}
		}
		file1.close();

		this->events = tmp;
		system("cls");
		cout << "Data loaded successfully\n";
		return tmp;
	}
	return tmp;
}

void Events::writeToFile(string s1)
{
	ofstream file1(s1);
	set <Event*, compare> tmp;
	set <Event*, compare>::iterator item;

	if (!file1.is_open())
	{
		cout << "There was an error opening a file!\n";
	}
	else
	{
		string type;
		string str1, str2, str3;
		Date d;
		Time_ t;
		int a;

		int counter = 0;
		for (item = events.begin(); item != events.end(); item++)
		{
			if (counter == 0)
			{
				counter++;

				file1 << (*item)->type();
				file1 << endl << (*item)->getEventDate();
				file1 << endl << (*item)->getEventTime();
				if ((*item)->type() == "Meeting")
				{
					file1 << endl << ((Meeting*)(*item))->getPerson();
					file1 << endl << ((Meeting*)(*item))->getPlace();
				}
				else if ((*item)->type() == "Custom")
				{
					file1 << endl << ((Custom*)(*item))->getDescription();
				}
				else if ((*item)->type() == "Birthday")
				{
					file1 << endl << ((BirthDay*)(*item))->getHero();
					file1 << endl << ((BirthDay*)(*item))->getPlace();
					file1 << endl << ((BirthDay*)(*item))->getAge();
				}

			}
			else
			{
				file1 << endl << (*item)->type();
				
				file1 << endl << (*item)->getEventDate();
				file1 << endl << (*item)->getEventTime();
				if ((*item)->type() == "Meeting")
				{
					file1 << endl << ((Meeting*)(*item))->getPerson();
					file1 << endl << ((Meeting*)(*item))->getPlace();
				}
				else if ((*item)->type() == "Custom")
				{
					file1 << endl << ((Custom*)(*item))->getDescription();
				}
				else if ((*item)->type() == "Birthday")
				{
					file1 << endl << ((BirthDay*)(*item))->getHero();
					file1 << endl << ((BirthDay*)(*item))->getPlace();
					file1 << endl << ((BirthDay*)(*item))->getAge();
				}
			}
		}
		file1.close();
		cout << "Events were written to " << s1 << ".txt\n";
	}
}