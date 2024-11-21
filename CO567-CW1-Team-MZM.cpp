#include <iostream>
#include <string>
#include "ticket.h"
#include "show.h"
#include "customer.h"
#include "showSeat.h"

int main()
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Initial variable declarations

	string a, b, c, d, e, f, g, h;

	int d;

	double e;

	char ch, terminator;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// create objects

	showSeat SEAT;
	customer CUST;
	show SHOW;
	ticket * TICK;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Deals with customer login

	CUST.getLogin();
	CUST.getProfileInfo(f, g, h);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Displays main menu, and allows customer to choose option

	system("CLS");

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAIN MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

	cout << "1. Buy tickets for upcoming shows" << endl;
	cout << "2. Log out\n" << endl;
	cout << "Please enter a menu choice number: ";
	cin.get(ch);

	while (ch != '1' && ch != '2')
	{
		cin.clear();
		cin.ignore(100, '\n'); // ensures the buffer is completely empty

		cout << "Invalid input. Please enter a valid menu choice number: ";
		cin.get(ch);
	}

	if (ch == '2')
	{
		return EXIT_SUCCESS;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Deals with selecting a show

	do
	{
		SHOW.selectShow(a, b);
		c = SHOW.selectTime();

		do
		{
			cout << "\nAre you happy with your choice? (Y = Yes, N = No): ";
			cin.get(ch);
		}
		while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');
		cin.get(terminator); //clears buffer
	}
	while (ch == 'N' || ch == 'n');

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Deals with selecting seat and calculating price of seats

	SEAT.initialiseFloorPlan();
	d = SEAT.getNumSeats();
	e = SEAT.getSeatSelection();

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Deals with discounts, payment and ticket generation
	

}

