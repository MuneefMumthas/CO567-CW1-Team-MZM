//ticket.h

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class ticket
{
	public:
		ticket();
		~ticket();
		void setPrice(double price);
		void printTicket(string showName, string showDate, string showTime, int numSeats, string fName, string sName, string address);
		virtual double cost() = 0; //virtual function used by derived classes

	protected:
		double totalCost;

};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// constructor

ticket::ticket()
{
	totalCost = 0; //initialise totalCost to 0
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// destructor

ticket::~ticket()
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//calculate discount cost from total price

void ticket::setPrice(double price)
{
	totalCost = price;
	cout << "\nThe total price of your tickets (including any applicable discount) is"
		 << (char)156 << this->cost() << ".\n" << endl;
	system("PAUSE");
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// prints ticket using data from derived classes

void ticket::printTicket(string showName, string showDate, string showTime, int numSeats, string fName, string sName, string address)
{
	system("CLS");

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ YOUR TICKETS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "============================================================================" << endl;
	cout << "================= The Bucks Centre for the Performing Arts =================" << endl;
	cout << "============================= Enjoy the show! ==============================" << endl;
	
	cout << "Show: " << showName << endl;
	cout << "Date: " << showDate << endl;
	cout << "Time: " << showTime << endl;
	cout << "============================================================================" << endl;
	cout << "Number of seats: " << numSeats << endl;
	cout << "Total cost: " << (char)156 << this -> cost() << endl;
	cout << "Ticket Purchaser: " << fName << " " << sName << endl;
	cout << "Postal Address: " << address << endl;
	cout << "============================================================================" << endl;
	cout << "============================================================================\n\n" << endl;

}