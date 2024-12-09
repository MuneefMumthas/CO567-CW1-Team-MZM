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
    void getProfileInfo(string& fName, string& sName, string& address);
    void getPaymentInfo();

protected:
    string fName;
    string sName;
    string address;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor

customer::customer()
{
    fName = "";
    sName = "";
    address = ""; // Initialise fName, sName, and address to empty strings
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Destructor

customer::~customer()
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Customer logs in

void customer::getLogin()
{
    string username; // In the real system, a set of usernames and passwords would be saved in a database file
    string password; // In this prototype, any username and password will be accepted



    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CUSTOMER LOGIN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "\n Welcome to the Bucks Centre for the Performing Arts ticket purchasing system!\n" << endl;

    cout << "                         Please Login                         " << endl;

    // Validate username (letters and numbers only, no spaces, not empty)
    while (true) {
        cout << "Enter Username: ";
        getline(cin, username);

        if (username.empty()) {
            cout << "Invalid input. Please enter a username." << endl;
        }
        else if (username.size() > 10) {
            cout << "Invalid input. Please enter a username with 10 or less than 10 characters." << endl;
        }
        else if (username.size() <= 2) {
            cout << "Invalid input. Please enter a username with atleast 3 characters." << endl;
		}
        else  {
            bool valid = true;
            for (char c : username) {
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

    // Validate password (letters and numbers only, no spaces, not empty) - Similar logic to username
    while (true) {
        cout << "Enter Password: ";
        getline(cin, password);

        if (password.empty()) {
            cout << "Invalid input. Please enter a password." << endl;
        }
        else if (password.size() <= 6) {
            cout << "Invalid input. Please enter a password with atleast 7 characters." << endl;
        }
        else if (password.size() > 20) {
            cout << "Invalid input. Please enter a password with 20 or less than 20 characters." << endl;
        }
        else {
            bool valid = true;
            for (char c : password) {
                if (isspace(c)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                break;
            }
            else {
                cout << "Invalid input. Please enter your password using only letters, numbers and symbols." << endl;
            }
        }
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Customer enters profile information

void customer::getProfileInfo(string& fName, string& sName, string& address)
{
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ENTER YOUR DETAILS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

    // prompt for first name
    while (true) {
        cout << "Enter your first name: ";
        getline(cin, fName);

		if (fName.empty()) { // Checking if first name is empty
            cout << "Invalid input. Please enter your first name using only letters." << endl;
        }
        else if (fName.size() <= 2) {
            cout << "Invalid input. Please enter a first name with atleast 3 characters." << endl;
		}
		else if (fName.size() > 20) {
			cout << "Invalid input. Please enter a first name with 20 or less than 20 characters." << endl;
		}
        else {
            bool valid = true;
            for (char c : fName) {
				if (!isalpha(c)) { // Checking if character is a letter for validation
                    valid = false;
                    break;
                }
            }
            if (valid) {
                break;
            }
            else {
                cout << "Invalid input. Please enter your first name using only letters." << endl;
            }
        }
    }

    // prompt for surname
    while (true) {
        cout << "Enter your surname: ";
        getline(cin, sName);

		if (sName.empty()) { // Checking if surname is empty
            cout << "Invalid input. Please enter your surname using only letters." << endl;
        }
		else if (sName.size() <= 2) {
			cout << "Invalid input. Please enter a surname with atleast 3 characters." << endl;
		}
        else if (sName.size() > 20) {
            cout << "Invalid input. Please enter a surname with 20 or less than 20 characters." << endl;
        }
        else {
            bool valid = true;
            for (char c : sName) {
				if (!isalpha(c)) { // Checking if character is a letter for validation
                    valid = false;
                    break;
                }
            }
            if (valid) {
                break;
            }
            else {
                cout << "Invalid input. Please enter your surname using only letters." << endl;
            }
        }
    }

    // prompt for address
    while (true) {
        cout << "Enter your address: ";
        getline(cin, address);

		if (address.empty()) { // Checking if address is empty
            cout << "Invalid input. Please enter your address using only letters and numbers." << endl;
        }
        else if (address.size() <= 4) {
            cout << "Invalid input. Please enter a address with atleast 5 characters." << endl;
        }
        else {
            bool valid = true;
            for (char c : address) {
				if (!isalnum(c) && !isspace(c)) { // Checking if character is a letter or number for validation
                    valid = false;
                    break;
                }
            }
            if (valid) {
                break;
            }
            else {
                cout << "Invalid input. Please enter your address using only letters and numbers." << endl;
            }
        }
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Customer enters payment information

void customer::getPaymentInfo()
{
	// Placeholder function to be implemented with payment input
}
