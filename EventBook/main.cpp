#include "Events.h"

int main()
{
	Events events;
	string str;

	int menu = 0;

	do
	{
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- MENU -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
		cout << "1 | Add event\n";
		cout << "2 | Delete event\n";
		cout << "+-|-----------------------------\n";
		cout << "3 | Show all events\n";
		cout << "4 | Show events by Time\n";
		cout << "5 | Show events by Date\n";
		cout << "6 | Show events by Hero\n";
		cout << "7 | Show events by Place\n";
		cout << "8 | Show events by Description\n";
		cout << "+-|-----------------------------\n";
		cout << "9 | Save to events to file\n";
		cout << "10| Load events from file\n";
		cout << "+-|-----------------------------\n";
		cout << "0 | Exit\n";
		cout << "+------------------------------------------------------------------------+\n";

		cin >> menu;
		system("cls");

		switch (menu)
		{
		default: 
			cout << "Enter a different number\n";
			break;
		case 0: 
			cout << "Goodbye!\n";
			break;
		case 1:
			events.add();
			break;
		case 2:
			events.del();
			break;
		case 3:
			events.show();
			break;
		case 4:
			events.FindByTime();
			break;
		case 5:
			events.FindByDate();
			break;
		case 6:
			events.FindByHero();
			break;
		case 7:
			events.FindByPlace();
			break;
		case 8:
			events.FindByDescriptions();
			break;
		case 9:
			cout << "Enter file name: ";
			cin >> str;
			events.writeToFile(str);
			break;
		case 10:
			cout << "Enter file name: ";
			cin >> str;
			events.readFromFile(str);
			break;
		}

	} while (menu != 0);

	return 0;
}