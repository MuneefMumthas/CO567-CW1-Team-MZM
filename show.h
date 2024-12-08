// show.h

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class show
{
public:
    show();
    ~show();
    void selectShow(string& showName, string& showDate);
    string selectTime();

protected:
    string showName;
    string showDate;
    string showTime;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Constructor

show::show()
{
    showName = "";
    showDate = "";
    showTime = "";
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Destructor

show::~show()
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Customer selects an upcoming show

void show::selectShow(string& showName, string& showDate)
{
    char ch;
    char terminator;

    system("CLS");

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT AN UPCOMING SHOW ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "1. Star Wars: The Musical (20/05/2025)" << endl;
    cout << "2. The Phantom of the Opera (21/05/2025)" << endl;
    cout << "3. The Lion King (22/05/2025)" << endl;

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
    this->showDate = showDate; // Enters reference variables into class variables

    cin.get(terminator); // Clears the buffer
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// show times

string show::selectTime()
{
    string input;

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SELECT SHOW TIME ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "1. 11.30 am" << endl;
    cout << "2. 5.30 pm" << endl;
    cout << "3. 7.30 pm" << endl;
    cout << "4. 9.30 pm" << endl;
    cout << "5. 10.00 pm" << endl;

    while (true) {
        cout << "\nPlease select a show time by entering the corresponding number: ";
        getline(cin, input);

        if (input.empty()) {
            cout << "Invalid input. Please enter a number." << endl;
        }
        else if (input.length() == 1 && isdigit(input[0]) && input[0] >= '1' && input[0] <= '5') {
            // Valid input: single digit between 1 and 5
            break;
        }
        else {
            cout << "Invalid input. Please enter a valid number between 1 and 5." << endl;
        }
    }

    switch (input[0]) { 
    case '1': return "11.30 am";
    case '2': return "5.30 pm";
    case '3': return "7.30 pm";
    case '4': return "9.30 pm";
    case '5': return "10.00 pm";
    default:  return "";
    }
}
