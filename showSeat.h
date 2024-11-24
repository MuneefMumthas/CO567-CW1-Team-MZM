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
    void calculatePrice(double& price); // Encapsulation - functions only accessed by this class

protected:
    char floorPlan[7][6];
    int numSeats;
    int rNum; // Used to calculate price
    double price;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor

showSeat::showSeat()
{
    for (int r = 0; r < 7; r++)
    {
        for (int c = 0; c < 6; c++)
        {
            floorPlan[r][c] = 'O'; // Allocates memory slots for floor plan array
        }
    }

    numSeats = 0;
    rNum = 0;
    price = 0; // Initialise remaining variables
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Destructor

showSeat::~showSeat()
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Initialise theatre floor plan

void showSeat::initialiseFloorPlan()
{
    for (int r = 0; r < 7; r++) // Prepares rows
    {
        for (int c = 0; c < 6; c++) // Prepares columns
        {
            floorPlan[r][c] = 'A'; // Populates array with 'A' to represent available seats
        }
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Gets user's number of seats

int showSeat::getNumSeats()
{
    //system("CLS");
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT SEATS INTERACTIVELY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

    do
    {

        cin.clear();
        cin.ignore(100, '\n');
        cout << "How many tickets would you like to purchase? (Max. 8): "; // Prompt to enter number of tickets
        cin >> numSeats;
        cout << endl;
    } while (numSeats < 1 || numSeats > 8); // Ensures user enters a valid number of tickets between 1 and 8

	displayFloorPlan(7, 6); // Displays theatre floor plan

    return numSeats; // Returns number of tickets
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Displays theatre floor plan

void showSeat::displayFloorPlan(int r, int c)
{
    cout << "  1 2 3 4 5 6" << endl;
    for (int r = 0; r < 7; r++)
    {
        cout << r + 1 << " ";
        for (int c = 0; c < 6; c++)
        {
            cout << floorPlan[r][c] << " ";
        }
        cout << endl;
    }

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Gets user's seat selection

double showSeat::getSeatSelection()
{
    int row, col;
    double totalPrice = 0.0;

    for (int i = 0; i < numSeats; i++)
    {
        do
        {
            cout << "Enter the row (1-7) for seat " << i + 1 << ": ";
            cin >> row;
            cout << "Enter the column (1-6) for seat " << i + 1 << ": ";
            cin >> col;

            row--; // Adjust for 0-based index
            col--; // Adjust for 0-based index

            if (row < 0 || row >= 7 || col < 0 || col >= 6 || floorPlan[row][col] != 'A')
            {
                cout << "Invalid selection or seat already taken. Please try again." << endl;
            }
            else
            {
                floorPlan[row][col] = 'X'; // Mark seat as taken
                calculatePrice(totalPrice); // Calculate price for the selected seat
				displayFloorPlan(7, 6); // Display updated floor plan
                break;
            }
        } while (true);
    }

    return totalPrice;
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Calculates the price of the seats

void showSeat::calculatePrice(double& price)
{
	// Placeholder for the price calculation
}
