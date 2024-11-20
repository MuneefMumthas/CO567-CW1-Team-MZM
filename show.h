//show.h

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class show
{
	public:
		show();
		~show();
		void selectShow(string &showName, string &showDate);
		string selectTime();

	protected:
		string showName;
		string showDate;
		string showTime;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// constructor
show::show()
{
	showName = "";
	showDate = "";
	showTime = "";
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// destructor
show::~show()
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// customer selects upcoming show

void show::selectShow(string& showName, string& showDate)
{
	char ch;
	char terminator;

	system("CLS");

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT AN UPCOMING SHOW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "1. Star Wars: The Musical (20/05/2025)" << endl;
	cout << "2. The Phantom of the Opera (21/05/2025)" << endl;
	cout << "3. The Lion King (22/05/2025)" << endl;

	cin.clear();
	cin.ignore(100, '\n'); // ensures the buffer is completely empty (if say, the user has previously input a long string)

	cout << "\nPlease select a show by entering the corresponding number: ";
	cin.get(ch);

	while (ch != '1' && ch != '2' && ch != '3')
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input. Please enter a valid number: ";
		cin.get(ch);
	}

	switch (ch)
	{
	case '1':
		showName = "Star Wars: The Musical";
		showDate = "20/05/2025";
		break;

	case '2':
		showName = "The Phantom of the Opera";
		showDate = "21/05/2025";
		break;

	case '3':
		showName = "The Lion King";
		showDate = "22/05/2025";
		break;
	}

	this->showName = showName;
	this->showDate = showDate; // enters reference variables into class variables

	cin.get(terminator); // clears the buffer

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// customer selects 1pm or 7pm showtime

string show::selectTime()
{

}