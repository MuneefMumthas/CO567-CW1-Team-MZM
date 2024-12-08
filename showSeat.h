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

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT SEATS INTERACTIVELY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

    displayFloorPlan(7, 6);
    cout << "\n" << endl;

    cout << " How many tickets would you like to purchase (Max. 8)?: ";


    string input;
    getline(cin, input);

    while (true) {
        bool valid = true;

        if (input.empty()) {
            valid = false;
        }
        else {
            for (char c : input) {
                if (!isdigit(c)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                numSeats = stoi(input);
                if (numSeats < 1 || numSeats > 8) {
                    valid = false;
                }
            }
        }

        if (!valid) {
            cout << "Invalid input. Please enter a number between 1 and 8: ";
            getline(cin, input);
        }
        else {
            break; // Exit the loop if input is valid
        }
    }

    cout << "\n" << endl;
    displayFloorPlan(7, 6);
	cout << "\n" << endl;

    return numSeats;
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
        while (true)
        {
            string inputRow, inputCol;

            // prompt for row
            cout << "Enter the row (1-7) for seat " << i + 1 << ": ";
            getline(cin, inputRow);

			// prompt for column
            cout << "Enter the column (1-6) for seat " << i + 1 << ": ";
            getline(cin, inputCol);

            bool validRow = true, validCol = true;

            // validating row input
            if (inputRow.empty()) {
                validRow = false;
            }
            else {
                for (char c : inputRow) {
                    if (!isdigit(c)) {
                        validRow = false;
                        break;
                    }
                }
                if (validRow) {
                    row = stoi(inputRow);
                    if (row < 1 || row > 7) {
                        validRow = false;
                    }
                }
            }

			// validating column input
            if (inputCol.empty()) {
                validCol = false;
            }
            else {
                for (char c : inputCol) {
                    if (!isdigit(c)) {
                        validCol = false;
                        break;
                    }
                }
                if (validCol) {
                    col = stoi(inputCol);
                    if (col < 1 || col > 6) {
                        validCol = false;
                    }
                }
            }

            if (validRow && validCol) {
                row--;
                col--; 

                if (floorPlan[row][col] != 'A') {
                    cout << "Seat already taken. Please try again." << endl;
                }
                else {
                    floorPlan[row][col] = 'X'; // Marking seat as taken
                    calculatePrice(totalPrice);
					cout << "\n" << endl;
                    displayFloorPlan(7, 6);
                    cout << "\n" << endl;
                    break; 
                }
            }
            else {
                cout << "Invalid input. Please enter numbers between 1-7 for row and 1-6 for column." << endl;
            }
        }
    }

    return totalPrice;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Calculates the price of the seats



void showSeat::calculatePrice(double& price)

{

    // Placeholder for the price calculation

}
