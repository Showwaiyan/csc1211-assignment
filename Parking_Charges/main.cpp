#include <iostream>
#include <string>
#include <cmath>
#include <limits> // to clear the whole cin input stream if input is not valid

using namespace std;

string acceptInput(); //Accept string input from user
int acceptInput(string flag); // Accept int number input from user

bool checkInput(string inputData); // Check string is valid or not
bool checkInput(int inputData, string flag); // Check int is valid or not base on criteria flag

double calculateCharges(int hours,int minutes);
double roundToOneDecimal(double num); // Rounded the minutes result to one decimal
double combineHoursAndMinutes(int hours,int minutes); // Change minutes to decimal form and add to hours

void clearScreen(); // Clear the Terminal or Command Prompt;

int main() {
    clearScreen();
    int hours = acceptInput("hours-flag");
    int minutes = acceptInput("minutes-flag");
    cout << calculateCharges(hours, minutes) << endl;
    return 0;
}

//Accept Input functions

string acceptInput() {
    bool validInput = false;
    string userInput;

    do {
        // Looping until user enter the vaild input string
        cout << "Enter 'Yes' or 'No': ";
        cin >> userInput;
        clearScreen();

        validInput = checkInput(userInput);

    } while (!validInput);

    return userInput; 
}
int acceptInput(string flag) {
    bool validInput = false;
    int userInput;

    cout << "Enter Parking duration in format of Hours and minutes\n" << endl;

    cout << "Hours format - duration (1 hour to 24 hours)\n";
    cout << "If the duration is less than one hour, please enter zero(0)\n" << endl;

    cout << "Minutes format - duration (1 minute to 60 minutes)\n";
    cout << "If the duration is less than one minutes, please enter zero(0)\n" << endl;

    do {
        // Looping until user enter the vaild input string
        if (flag == "hours-flag") {
            cout << "Enter parking hours: ";
            cin >> userInput;
            clearScreen();
        }
        else if (flag == "minutes-flag") {
            cout << "Enter parking minutes: ";
            cin >> userInput;
            clearScreen();
        }

        if (cin.fail()) {
            // If user type letter insted of number
            // this code clear the input stream and ask the input from user again

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number!\n" << std::endl;
            
            continue;
        }

        validInput = checkInput(userInput,flag);

    } while (!validInput);

    return userInput;
}

// Check input funcitons

bool checkInput(string inputData) {
    string lowerCaseInput = "";

    for (int i=0; i<inputData.size(); i++) {
        // Checking the string is letter or contains number and symbol

        if (!((inputData[i] >= 'a' && inputData[i] <= 'z') ||
            (inputData[i] >= 'A' && inputData[i] <= 'Z'))) {

                // if number or symbol contain return false and out from this function
                cout << "Invalid input!\nEnter valid input provide by program discription.\n" << endl;
                return false;
        }

        // change input string letter to lowercase and add to the loweCaseInput string variable
        lowerCaseInput += tolower(inputData[i]);

    }
    
    if ((lowerCaseInput =="y" || lowerCaseInput == "n") || 
        (lowerCaseInput == "yes" || lowerCaseInput == "no")) {

        // If user enter vaild and available options input return true and out from this funtion
        return true;
    }
    else {
        //If user enter input that is out of range from vaild and available options
        // return fasle and out from this function
        cout << "Plase Enter the exect options of input provide by the program!\n" << endl;;
        return false;
    };
}
bool checkInput(int inputData, string flag) {

    if (flag == "hours-flag") {
        // If hours-flag
        // valid input number range is between 0 and 24, both include
        // Out of this range will ask the input from user again
        if (inputData < 0 || inputData > 24) {
            cout << "Please Enter valid 24-HOURS format\n" << endl;
            return false;
        }
    }
    else if (flag == "minutes-flag") {
        // If minutes-flag
        // valid input number range is between 0 and 60, both include
        // Out of this range will ask the input from user again
        if (inputData < 0 || inputData > 60) {
            cout << "Please Enter valid 60-MINUTES format\n" << endl;
            return false;
        }
    } 
    return true;
}

// Charges calculation functions

double calculateCharges(int hours, int minutes) {
    double hoursMinutes = combineHoursAndMinutes(hours,minutes); // decimal form of hours and minutes

    if (hoursMinutes <= 3.0) return 4.00;
    else if (hoursMinutes >= 3.0 && hoursMinutes < 15.00) return ((hoursMinutes - 3)*0.5)+4.00;
    else return 10.00;
}
double roundToOneDecimal(double num) {
    return ((double)((int)(num*10+0.5))/10);
}
double combineHoursAndMinutes(int hours,int minutes) {
    //Minutes is divided by 60 and change into decimal form and added to hours
    //and that make only signle hours value

    return (double) hours + roundToOneDecimal(minutes/60.00);
}

void clearScreen()
{
    // For clear visual and best user experience
    // clear the terminal screen base on the OS
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}