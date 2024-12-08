// Main file for CO567-CW1-Team-MZM
// Team MZM: Muneef Mumthas, Zaigham Khan, Mehanathan Nackshayan

#include <iostream>
#include <string>
#include "ticket.h"
#include "show.h"
#include "customer.h"
#include "showSeat.h"

using namespace std;

int main()
{
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Initial variable declarations

    string a = "", b = "", c = "", d = "", e = "", f = "", g = "", h = "";

    int numSeats;
    double seatPrice;

    char ch;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Create objects

    showSeat SEAT;
    customer CUST;
    show SHOW;


    
    while (true) {
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Deals with customer login

        CUST.getLogin();
        CUST.getProfileInfo(f, g, h);

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Displays main menu, and allows customer to choose an option

        system("CLS");

        string menuChoice;

        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAIN MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
        cout << "1. Buy tickets for upcoming shows" << endl;
        cout << "2. Log out\n" << endl;
        cout << "Please enter a menu choice number: ";
        getline(cin, menuChoice);

        while (true) {

            if (menuChoice.empty()) {
                cout << "Invalid input. Please enter a number." << endl;
                getline(cin, menuChoice);
            }
            else if (menuChoice.length() == 1 && isdigit(menuChoice[0]) &&
                (menuChoice[0] == '1' || menuChoice[0] == '2')) {
                break;
            }
            else {
                cout << "Invalid input. Please enter 1 or 2." << endl;
                getline(cin, menuChoice);
            }
        }

        if (menuChoice[0] == '2') {
            cout << "\nThank you for using our online ticketing system!" << endl;
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
                cin.ignore(100, '\n');
            } while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');

        } while (ch == 'N' || ch == 'n');

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Deals with selecting seats and calculating the price of seats

        SEAT.initialiseFloorPlan();
        numSeats = SEAT.getNumSeats();
        seatPrice = SEAT.getSeatSelection();

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Deals with discounts, payment, and ticket generation
        // Payment prompt with validation
        string bankUsername, bankPassword;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PAYMENT DETAILS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
        cout << "Enter your bank username: ";

        while (true) {
            
            getline(cin, bankUsername);

            if (bankUsername.empty()) {
                cout << "Invalid input. Please enter a username." << endl;
            }
            else {
                bool valid = true;
                for (char c : bankUsername) {
                    if (!isalnum(c)) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    break;
                }
                else {
                    cout << "Invalid input. Please enter your username using only letters and numbers." << endl;
                }
            }
        }

        cout << "Enter your bank password: ";

        // Validate bank password
        while (true) {
            
            getline(cin, bankPassword);

            if (bankPassword.empty()) {
                cout << "Invalid input. Please enter a password." << endl;
            }
            else {
                bool valid = true;
                for (char c : bankPassword) {
                    if (!isalnum(c)) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    break;
                }
                else {
                    cout << "Invalid input. Please enter your password using only letters and numbers." << endl;
                }
            }
        }

        // Processing details
        cout << "\nProcessing payment...\n";
        cout << "\n" << endl;
        cout << "Payment successful!\n";


        ticket myTicket;
        myTicket.setPrice(numSeats);
        myTicket.printTicket(a, b, c, numSeats, f, g, h);

        string logoutChoice;

        while (true) {
            cout << "\nWould you like to logout (1) or logout and exit (2)?: ";
            getline(cin, logoutChoice);

            if (logoutChoice.empty()) {
                cout << "Invalid input. Please enter a number." << endl;
            }
            else if (logoutChoice.length() == 1 && isdigit(logoutChoice[0]) &&
                (logoutChoice[0] == '1' || logoutChoice[0] == '2')) {
                // Valid input: single digit (1 or 2)
                break;
            }
            else {
                cout << "Invalid input. Please enter 1 or 2." << endl;
            }
        }

        if (logoutChoice[0] == '2') {
            cout << "\nThank you for using our online ticketing system!" << endl;
            break; // Exit the main loop
        }
        else if (logoutChoice[0] == '1') {
            system("CLS"); // Clear the screen 
            continue; 
        }
    }

    return EXIT_SUCCESS;
}

