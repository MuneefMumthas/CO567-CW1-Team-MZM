// showSeat.h

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class showSeat
{
public:
	showSeat();
	~showSeat();
	void initialiseFloorPlan();
	int getNumSeats();
	double getSeatSelection();

private:
	void displayFloorPlan(int r, int c);
	void calculatePrice(double& price); //encapsulation - functions only access by this class, and no other part of the program

protected:
	char floorPlan[7][6];
	int numSeats;
	int rNum; // used to calculate price
	double price;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// constructor

showSeat::showSeat()
{
	for (int r = 0; r < 7; r++)

for (int c = 0; c < 6; c++)
		
	floorPlan[r][c] = 'O'; //allocates memory slots for floor plan array

	numSeats = 0;
	rNum = 0;
	price = 0; //Initialise remaining variables
		
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// destructor

showSeat::~showSeat()
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// initialise theatre floor plan

void showSeat::initialiseFloorPlan()
{
	
	for (int r = 0; r < 7; r++) // prepares rows
		for (int c = 0; c < 6; c++) // prepares columns
			floorPlan[r][c] = 'A'; // populates array with 'A' to represent available seats

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// gets user's no. of seats

int showSeat::getNumSeats()
{
	system("CLS");

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT SEATS INTERACTIVELY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	do 
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "How many tickets would you like to purchase? (Max. 8): "; //prompt to enter number of tickets
		cin >> numSeats; 
		cout << endl;
	}

	while (numSeats != 1 && numSeats != 2 && numSeats != 3 && numSeats != 4 && numSeats != 5 && numSeats != 6 && numSeats != 7 && numSeats != 8); //ensures user enters a valid number of tickets

	return numSeats; //returns number of tickets
}


