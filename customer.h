// customer.h

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

class customer
{
	public:
		customer();
		~customer();
		void getLogin();
		void getProfileInfo(string &fName, string &sName, string &address);
		void getPaymentInfo();

	protected:
		string fName;
		string sName;
		string address;

};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// constructor

customer::customer()
{
	fName = "";
	sName = "";
	address = ""; //initialise fName, sName and address to empty strings
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// destructor
customer::~customer()
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// customer logs in

void customer::getLogin()
{
	string username; // in the real system, a set of usernames and passwords would be saved in a database file
	string password; // in this prototype, any username and password will be accepted

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CUSTOMER LOGIN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\n Welcome to the Bucks Centre for the Performing Arts ticket purchasing system!" << endl;

	cout << "                                Please Login                                " << endl;

	cout << "Enter Username: ";
	getline(cin, username);

	while (username.length() > 10)
	{
		cout << "Your username should be no more than 10 characters long." << endl;
		cout << "Please re-enter your username: ";
		getline(cin, username);
	}

	cout << "Enter Password: ";
	getline(cin, password);

	while (password.length() > 10)
	{
		cout << "Your password should be no more than 10 characters long." << endl;
		cout << "Please re-enter your password: ";
		getline(cin, password);
	}
	
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// customer enters profile information
void customer::getProfileInfo(string& fName, string& sName, string& address)
{

}