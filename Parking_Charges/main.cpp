#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string acceptInputString(); //Accept string input from user

bool checkInput(string inputData); // Check string is valid or not


int main() {


    return 0;
}



string acceptInputString() {
    bool validInput = false;
    string userInput;

    do {
        // Looping until user enter the vaild input string
        cout << "Enter 'Yes' or 'No': ";
        cin >> userInput;

            validInput = checkInput(userInput);

    } while (!validInput);

    return userInput; 
}


bool checkInput(string inputData) {
    string lowerCaseInput = "";

    for (int i=0; i<inputData.size(); i++) {
        // Chenking the string is letter or contains number and symbol

        if (!((inputData[i] >= 'a' && inputData[i] <= 'z') ||
            (inputData[i] >= 'A' && inputData[i] <= 'Z'))) {

                // if number or symbol contsin return false and out from this function
                cout << "\nInvalid input!\nEnter valid input provide by program discription.\n\n";
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
        cout << "\nPlase Enter the exect options of input provide by the program!\n\n";
        return false;
    };
}
