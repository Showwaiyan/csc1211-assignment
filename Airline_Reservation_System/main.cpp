#include <iostream>
#include <string>

using namespace std;

int acceptInput(string flag); // accepting user input
bool checkInput(string inputData, string flag); // viladation checking for user input

void intilizeArray(bool (&arr)[2][8], int row, int column);
int findAvailableSeat(bool arr[8], int size); // find non-taking seat


void clearScreen(); // Clear terminal or comand prompt 

int main() {
    const int NUMBER_OF_SECTION = 2;
    const int NUMBER_OF_SETAS_PER_SECTION = 8;
    bool seats[NUMBER_OF_SECTION][NUMBER_OF_SETAS_PER_SECTION];

    return 0;
}

int acceptInput(string flag) {
    string userInput;
    bool validInput = false;

    do {
        if (flag == "section-chosing") {
            cout << "Enter your dedicated airplane seciont seat.\n";
            cout << "Type '1' for Smoking section :\n";
            cout << "Type '2' for Non-smoking section :\n";
            cout << "Enter here: ";
            cin >> userInput;

            clearScreen();

            validInput = checkInput(userInput, flag);

        }
        else if (flag == "yesORno-chosing") {

        }
        else {
            cout << "Inavlid Flag!" << endl;
            return 0;
        }

    } while (!validInput);

    return stoi(userInput);
}

bool checkInput(string inputData, string flag) {

    if (flag == "section-chosing" || flag == "yesORno-chosing") {
        if (inputData.size() > 1) {
            // Valid input should be only one character
            // which is '1' and '2'
            // Otherwise, invalid input
            cout << "Please enter appropriate input that is descripted by program!\n" << endl;
            return false;
        }
        else if (inputData == "1" || inputData == "2") return true;
        else {
            cout << "Please enter only valid value options provided by the program\n" << endl;
            return false;
        }
    }
    return true;
}

void intilizeArray(bool (&arr)[2][8], int row, int column) {
    //intialization all element to zero
    for (int i=0; i < row; i++) {
        for (int j=0; j < column; j++) {
            arr[i][j] = 0;
        }
    }
}
int findAvailableSeat(bool arr[8], int size) {
    for (int i=0; i<size; i++) {
        if (arr[i] == 0) return i;
    }
    return -1
}

void clearScreen()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}