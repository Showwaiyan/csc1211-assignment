#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

int acceptInput(string flag); // accepting user input
bool checkInput(string inputData, string flag); // viladation checking for user input

void intilizeArray(bool (&arr)[], int size);
int findAvailableSeat(bool arr[], int size, int start); // find non-taking seat
void intilizeSeat(bool (&arr)[],int index); // Take seats in the array

void printSeat(int section, int seatNum, string arrival);


void clearScreen(); // Clear terminal or comand prompt 

int main() {
    clearScreen();

    string arrival;
    cout << "Enter the arrival port: ";
    getline(cin, arrival);
    cout << "\n";

    const int NUMBER_OF_ELEMENTS = 16;
    bool seats[NUMBER_OF_ELEMENTS];

    intilizeArray(seats, NUMBER_OF_ELEMENTS);

    int userInput;
    int seatNum;

    while (true) {

        userInput = acceptInput("section-chosing");

        switch(userInput) {
            case 1:
                seatNum = findAvailableSeat(seats, 8, 0);

                if (seatNum == -1) {
                    // change section
                    clearScreen();
                    cout << "Smoking section is full.\n\n";
                    cout << "Would you like to change Non-smoking section?\n" << endl;
                    userInput = acceptInput("yesORno-chosing");

                    if (userInput == 2) {
                        cout << "Thansk for using our airline.\n" << endl;
                        cout << "Next flight in 5 hours!" << endl;
                        return 0;
                    }

                    seatNum = findAvailableSeat(seats, 8, 8);
                    if (seatNum == -1) {
                        cout << "All seats are taken!\n";
                        cout << "Next flight in 5 hours!" << endl;
                        return 0;
                    }
                    else {
                        intilizeSeat(seats, seatNum);
                        printSeat(2, seatNum, arrival);
                    }
                }
                else {
                    intilizeSeat(seats, seatNum);
                    printSeat(1, seatNum, arrival); 
                    continue;
                }
               break;

            case 2:
                seatNum = findAvailableSeat(seats, 8, 8);
                if (seatNum == -1) {
                    // change section
                    clearScreen();
                    cout << "Non-Smoking section is full.\n\n";
                    cout << "Would you like to change smoking section?\n" << endl;
                    userInput = acceptInput("yesORno-chosing");

                    if (userInput == 2) {
                        cout << "Thansk for using our airline.\n" << endl;
                        cout << "Next flight in 5 hours!" << endl;
                        return 0;
                    }

                    seatNum = findAvailableSeat(seats, 8, 0);
                    if (seatNum == -1) {
                        cout << "All seats are taken!\n";
                        cout << "Next flight in 5 hours!" << endl;
                        return 0;
                    }
                    else {
                        intilizeSeat(seats, seatNum);
                        printSeat(1, seatNum, arrival);
                        continue;
                    }
                }
                else {
                    intilizeSeat(seats, seatNum);
                    printSeat(2, seatNum, arrival); 
                }
                break;

            default:
                cout << "Some error encounter!\n Please rerun the program." << endl;
                break; 
        }
    }
    return 0;
}

int acceptInput(string flag) {
    string userInput;
    bool validInput = false;

    do {
        if (flag == "section-chosing") {
            cout << "Enter your dedicated airplane section seat.\n\n";
            cout << "Type '1' for Smoking section :\n";
            cout << "Type '2' for Non-smoking section :\n\n";
            cout << "Enter here: ";
            cin >> userInput;
            cout << "\n";

            validInput = checkInput(userInput, flag);

        }
        else if (flag == "yesORno-chosing") {
            cout << "Type '1' for Yes,\n";
            cout << "Type '2' for No.\n" << endl;
            cout << "Enter here: ";
            cin >> userInput;
            cout << "\n";

            validInput = checkInput(userInput, flag);
        }
        else {
            cout << "Inavlid Flag!" << endl;
            return 0;
        }

    } while (!validInput);

    return stoi(userInput); // if valid change string to number, which is absolutely can after valiadation
}

bool checkInput(string inputData, string flag) {

    if (flag == "section-chosing" || flag == "yesORno-chosing") {
        if (inputData.size() > 1) {
            // Valid input should be only one character
            // which is '1' and '2'
            // Otherwise, invalid input
            cout << "\n***********************************************************************" << endl;
            cout << "Please enter appropriate input that is descripted by program!\n" << endl;
            return false;
        }
        else if (inputData == "1" || inputData == "2") return true;
        else {
            cout << "\n***********************************************************************" << endl;
            cout << "Please enter only valid value options provided by the program\n" << endl;
            return false;
        }
    }
    return true;
}

void intilizeArray(bool (&arr)[], int size) {
    //intialization all element to zero
    for (int i=0; i < size; i++) {
        arr[i] = 0;
    }
}
int findAvailableSeat(bool arr[], int size, int start) {
    for (int i=start; i<size+start; i++) {
        if (arr[i] == 0) return i;
    }
    return -1;
}
void intilizeSeat(bool (&arr)[], int index) {
    arr[index] = 1;
}

void printSeat(int section, int seatNum, string arrival) {
    // getting current time
    time_t now = time(0);
    char* dt = ctime(&now);

    cout << "\n*****************************************************************" << endl;
    switch (section) {

        case 1:
            // Date Time
            cout << setw(30) << left << "Register Date/Time";
            cout << setw(1) << " ";
            cout << setw(30) << right << "Section: Smoking" << endl;

            // Section Seat
            cout << setw(50) << left << dt;
            cout << setw(1) << " ";
            cout << setw(29) << right << "Seat No.: " << seatNum+1 << endl;

            // Dep Arrive
            cout << setw(15) << left << "Dep:";
            cout << setw(1) << " ";
            cout << setw(15) << left  << "Arival:" << endl;

            cout << setw(15) << left << "Kuala Lumpur";
            cout << setw(1) << " ";
            cout << setw(15) << left << arrival << "\n" << endl;
            
            break;      

        case 2:
            // Date Time
            cout << setw(30) << left << "Register Date/Time";
            cout << setw(1) << " ";
            cout << setw(30) << right << "Section: Non-Smoking" << endl;

            // Section Seat
            cout << setw(50) << left << dt;
            cout << setw(1) << " ";
            cout << setw(25) << right << "Seat No.: " << seatNum-7 << endl;

            // Dep Arrive 
            cout << setw(15) << left << "Dep:";
            cout << setw(1) << " ";
            cout << setw(15) << left  << "Arival:" << endl;

            cout << setw(15) << left << "Kuala Lumpur";
            cout << setw(1) << " ";
            cout << setw(15) << left << arrival << "\n" <<endl;

            break;
    }
    cout << "*****************************************************************\n" << endl;
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