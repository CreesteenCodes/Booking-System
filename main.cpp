#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include <limits>
#include <ctime>
#include <regex>
#include <iomanip>

using namespace std;

const int rows = 10;
const int cols = 15;
char seats[rows][cols];
int seatsBooked = 0;

class ticket {
    public:
    char cno[11];
} t;

class admin {
    private:
    string username;
    string password;

    public:
    admin(string uname,string pwd) : username(uname), password(pwd) {}

    bool isAdmin(string uname,string pwd) {
        return (username == uname && password == pwd);
    }
};

void printCurrent_Time_Date() {
    time_t currentTime = time(0);
    char* timeString = ctime(&currentTime);
    cout << timeString << endl;
}

void displayMenu() {
    cout << "-------------------------------------- \n";
    cout << "\tWelcome to Flix Ticket! \n";
    cout << "-------------------------------------- \n";
    cout << "Welcome Dear Customer! \n";
    cout << "<1> Ticket Booking \n";
    cout << "<2> Admin Login \n";
    cout << "<3> Contact Us \n";
    cout << "<4> Exit \n\n";
    cout << "Enter Choice:" << "\t";
}

int daysInMonth(int year,int month);
bool isValidDateFormat(const string&date);
bool isValidDate(const string&date);
bool isValidCno(const char*cno);
void initializedSeats();
void displaySeats();
bool bookSeat(int row,int col);
bool isExpDtValid (const string&expdt);
void payment(int);
int generateTicketNumber();

int main() {
    system("CLS");
    int ch,a,b,x;
    int ticketNumber = generateTicketNumber();
    char ans;
    string dt,name;
    string username,password;

    admin admin("admin","admin123");

    do {
        printCurrent_Time_Date();
        displayMenu();
        while (!(cin >> ch) || (ch < 1 || ch > 4)) {
            cout << "Invalid Input! Please enter a number between 1 and 4." << "\t";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
    switch(ch) {
        case 1:
            system("CLS");
            cout << "Now Showing!!! \n";
            cout << "\t1. Interstellar \n";
            cout << "\t\t English.2h49m \n";
            cout << "\t2. Gomburza \n";
            cout << "\t\t Filipino.1h52m \n";
            cout << "\t3. My Happy Marriage \n";
            cout << "\t\t Japanese.1h55m \n";
            cout << "\t4. The Moon \n";
            cout << "\t\t Korean.2h9m \n";
            cout << "\t5. Yesterday Once More \n";
            cout << "\t\t Mandarin.1h48m \n\n";
            cout << "Enter Choice:" << "\t";
            cin >> a;
            switch(a) {
                case 1:
                    system("CLS");
                    cout << "When do you wish to watch the movie? \n";
                    cout << "Input to this format [yyyy-mm-dd] \n\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter Date:" << "\t";
                    getline(cin,dt);
                        while (!isValidDateFormat(dt) || !isValidDate(dt)) {
                        cout << "Invalid date. Please enter a valid date in yyyy-mm-dd format:" << "\t";
                        getline(cin, dt);
                        }
                    cout << "\nSelect Timings \n";
                    cout << "1. 08:00 \n";
                    cout << "2. 12:00 \n";
                    cout << "3. 16:00 \n";
                    cout << "4. 20:00 \n\n";
                    cout << "Enter Choice:" << "\t";
                    cin >> b;
                    system("CLS");
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter Name:" << "\t";
                    getline(cin,name);
                    cout << "Enter Contact Number:" << "\t";
                    cin >> t.cno;
                        if (strlen(t.cno)!=11) {
                            cout << "Please enter a valid number. \n";
                            cin >> t.cno;
                        }
                    cout << "\nEnter the number of ticket/s you want to purchase:" << "\t";
                    cin >> x;
                    cout << endl;
                    initializedSeats();
                    displaySeats();
                        while (seatsBooked < x) {
                            cout << "\nNote: 'O' is an available seat, and 'X' is a booked seat. \n";
                            cout << "Enter row and column number to book a seat (e.g., A 1):" << "\t";
                            char row;
                            int col;
                            cin >> row >> col;
                            row = toupper(row);
                            int rowIndex = row - 'A';
                            int colIndex = col - 1;
                            if (bookSeat(rowIndex,colIndex)) {
                                system ("CLS");
                                displaySeats();
                            }
                        }
                    cout << "\n  All " << x << " seat/s have been booked. \n";
                    system ("PAUSE");
                    payment(x);
                    system("CLS");
                    cout << "\n  Your ticket is here: \n";
                    cout << "Name:" << "\t" << name << "\n";
                    cout << "Contact Number:" << "\t" << t.cno << "\n";
                    cout << "Ticket Number:" << "\t" << ticketNumber << "\n";
                    cout << "Movie:" << "\t";
                    switch (a) {
                        case 1: cout << "Interstellar";
                            break;
                        case 2: cout << "Gomburza";
                            break;
                        case 3: cout << "My Happy Marriage";
                            break;
                        case 4: cout << "The Moon";
                            break;
                        case 5: cout << "Yesterday Once More";
                            break;
                        default: cout << "Invalid Input!";
                    }
                    cout << "\nTime:" << "\t";
                    switch (b) {
                        case 1: cout << "08:00";
                            break;
                        case 2: cout << "12:00";
                            break;
                        case 3: cout << "16:00";
                            break;
                        case 4: cout << "20:00";
                            break;
                        default: cout << "Invalid Input!";
                    }
                    cout << "\n\nDo you want to choose another option? (y/n) ";
                    cin >> ans;
                    system("CLS");
                    break;
                case 2:
                    system("CLS");
                    cout << "When do you wish to watch the movie? \n";
                    cout << "Input to this format [yyyy-mm-dd] \n\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter Date:" << "\t";
                    getline(cin,dt);
                        while (!isValidDateFormat(dt) || !isValidDate(dt)) {
                            cout << "Invalid date. Please enter a valid date in yyyy-mm-dd format:" << "\t";
                            getline(cin,dt);
                        }
                    cout << "\nSelect Timings \n";
                    cout << "1. 09:00 \n";
                    cout << "2. 13:00 \n";
                    cout << "3. 17:00 \n";
                    cout << "4. 21:00 \n\n";
                    cout << "Enter Choice:" << "\t";
                    cin >> b;
                    system("CLS");
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter Name:" << "\t";
                    getline(cin,name);
                    cout << "Enter Contact Number:" << "\t";
                    cin >> t.cno;
                        if (strlen(t.cno)!=11) {
                            cout << "Please enter a valid number. \n";
                            cin >> t.cno;
                        }
                    cout << "\nEnter the number of ticket/s you want to purchase:" << "\t";
                    cin >> x;
                    cout << endl;
                    initializedSeats();
                    displaySeats();
                        while (seatsBooked < x) {
                            cout << "\nNote: 'O' is an available seat, and 'X' is a booked seat. \n";
                            cout << "Enter row and column number to book a seat (e.g., A 1):" << "\t";
                            char row;
                            int col;
                            cin >> row >> col;
                            row = toupper(row);
                            int rowIndex = row - 'A';
                            int colIndex = col - 1;
                            if (bookSeat(rowIndex,colIndex)) {
                                system ("CLS");
                                displaySeats();
                            }
                        }
                    cout << "\n  All " << x << " seat/s have been booked. \n";
                    system ("PAUSE");
                    payment(x);
                    system("CLS");
                    cout << "\n  Your ticket is here: \n";
                    cout << "Name:" << "\t" << name << "\n";
                    cout << "Contact Number:" << "\t" << t.cno << "\n";
                    cout << "Ticket Number:" << "\t" << ticketNumber << "\n";
                    cout << "Movie:" << "\t";
                    switch (a) {
                        case 1: cout << "Interstellar";
                            break;
                        case 2: cout << "Gomburza";
                            break;
                        case 3: cout << "My Happy Marriage";
                            break;
                        case 4: cout << "The Moon";
                            break;
                        case 5: cout << "Yesterday Once More";
                            break;
                        default: cout << "Invalid Input!";
                    }
                    cout << "\nTime:" << "\t";
                    switch (b) {
                        case 1: cout << "09:00";
                            break;
                        case 2: cout << "13:00";
                            break;
                        case 3: cout << "17:00";
                            break;
                        case 4: cout << "21:00";
                            break;
                        default: cout << "Invalid Input!";
                    }
                    cout << "\n\nDo you want to choose another option? (y/n) ";
                    cin >> ans;
                    system("CLS");
                    break;
                case 3:
                    system("CLS");
                    cout << "When do you wish to watch the movie? \n";
                    cout << "Input to this format [yyyy-mm-dd] \n\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter Date:" << "\t";
                    getline(cin,dt);
                        while (!isValidDateFormat(dt) || !isValidDate(dt)) {
                            cout << "Invalid date. Please enter a valid date in yyyy-mm-dd format:" << "\t";
                            getline(cin,dt);
                        }
                    cout << "\nSelect Timings \n";
                    cout << "1. 08:00 \n";
                    cout << "2. 12:00 \n";
                    cout << "3. 16:00 \n";
                    cout << "4. 20:00 \n\n";
                    cout << "Enter Choice:" << "\t";
                    cin >> b;
                    system("CLS");
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter Name:" << "\t";
                    getline(cin,name);
                    cout << "Enter Contact Number:" << "\t";
                    cin >> t.cno;
                        if (strlen(t.cno)!=11) {
                            cout << "Please enter a valid number. \n";
                            cin >> t.cno;
                        }
                    cout << "\nEnter the number of ticket/s you want to purchase:" << "\t";
                    cin >> x;
                    cout << endl;
                    initializedSeats();
                    displaySeats();
                        while (seatsBooked < x) {
                            cout << "\nNote: 'O' is an available seat, and 'X' is a booked seat. \n";
                            cout << "Enter row and column number to book a seat (e.g., A 1):" << "\t";
                            char row;
                            int col;
                            cin >> row >> col;
                            row = toupper(row);
                            int rowIndex = row - 'A';
                            int colIndex = col - 1;
                            if (bookSeat(rowIndex,colIndex)) {
                                system ("CLS");
                                displaySeats();
                            }
                        }
                    cout << "\n  All " << x << " seat/s have been booked. \n";
                    system ("PAUSE");
                    payment(x);
                    system("CLS");
                    cout << "\n  Your ticket is here: \n";
                    cout << "Name:" << "\t" << name << "\n";
                    cout << "Contact Number:" << "\t" << t.cno << "\n";
                    cout << "Ticket Number:" << "\t" << ticketNumber << "\n";
                    cout << "Movie:" << "\t";
                    switch (a) {
                        case 1: cout << "Interstellar";
                            break;
                        case 2: cout << "Gomburza";
                            break;
                        case 3: cout << "My Happy Marriage";
                            break;
                        case 4: cout << "The Moon";
                            break;
                        case 5: cout << "Yesterday Once More";
                            break;
                        default: cout << "Invalid Input!";
                    }
                    cout << "\nTime:" << "\t";
                    switch (b) {
                        case 1: cout << "08:00";
                            break;
                        case 2: cout << "12:00";
                            break;
                        case 3: cout << "16:00";
                            break;
                        case 4: cout << "20:00";
                            break;
                        default: cout << "Invalid Input!";
                    }
                    cout << "\n\nDo you want to choose another option? (y/n) ";
                    cin >> ans;
                    system("CLS");
                    break;
                case 4:
                    system("CLS");
                    cout << "When do you wish to watch the movie? \n";
                    cout << "Input to this format [yyyy-mm-dd] \n\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter Date:" << "\t";
                    getline(cin,dt);
                        while (!isValidDateFormat(dt) || !isValidDate(dt)) {
                            cout << "Invalid date. Please enter a valid date in yyyy-mm-dd format:" << "\t";
                            getline(cin,dt);
                        }
                    cout << "\nSelect Timings \n";
                    cout << "1. 09:00 \n";
                    cout << "2. 13:00 \n";
                    cout << "3. 17:00 \n";
                    cout << "4. 21:00 \n\n";
                    cout << "Enter Choice:" << "\t";
                    cin >> b;
                    system("CLS");
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter Name:" << "\t";
                    getline(cin,name);
                    cout << "Enter Contact Number:" << "\t";
                    cin >> t.cno;
                        if (strlen(t.cno)!=11) {
                            cout << "Please enter a valid number. \n";
                            cin >> t.cno;
                        }
                    cout << "\nEnter the number of ticket/s you want to purchase:" << "\t";
                    cin >> x;
                    cout << endl;
                    initializedSeats();
                    displaySeats();
                        while (seatsBooked < x) {
                            cout << "\nNote: 'O' is an available seat, and 'X' is a booked seat. \n";
                            cout << "Enter row and column number to book a seat (e.g., A 1):" << "\t";
                            char row;
                            int col;
                            cin >> row >> col;
                            row = toupper(row);
                            int rowIndex = row - 'A';
                            int colIndex = col - 1;
                            if (bookSeat(rowIndex,colIndex)) {
                                system ("CLS");
                                displaySeats();
                            }
                        }
                    cout << "\n  All " << x << " seat/s have been booked. \n";
                    system ("PAUSE");
                    payment(x);
                    system("CLS");
                    cout << "\n  Your ticket is here: \n";
                    cout << "Name:" << "\t" << name << "\n";
                    cout << "Contact Number:" << "\t" << t.cno << "\n";
                    cout << "Ticket Number:" << "\t" << ticketNumber << "\n";
                    cout << "Movie:" << "\t";
                    switch (a) {
                        case 1: cout << "Interstellar";
                            break;
                        case 2: cout << "Gomburza";
                            break;
                        case 3: cout << "My Happy Marriage";
                            break;
                        case 4: cout << "The Moon";
                            break;
                        case 5: cout << "Yesterday Once More";
                            break;
                        default: cout << "Invalid Input!";
                    }
                    cout << "\nTime:" << "\t";
                    switch (b) {
                        case 1: cout << "09:00";
                            break;
                        case 2: cout << "13:00";
                            break;
                        case 3: cout << "17:00";
                            break;
                        case 4: cout << "21:00";
                            break;
                        default: cout << "Invalid Input!";
                    }
                    cout << "\n\nDo you want to choose another option? (y/n) ";
                    cin >> ans;
                    system("CLS");
                    break;
                case 5:
                    system("CLS");
                    cout << "When do you wish to watch the movie? \n";
                    cout << "Input to this format [yyyy-mm-dd] \n\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter Date:" << "\t";
                    getline(cin,dt);
                        while (!isValidDateFormat(dt) || !isValidDate(dt)) {
                            cout << "Invalid date. Please enter a valid date in yyyy-mm-dd format:" << "\t";
                            getline(cin,dt);
                        }
                    cout << "\nSelect Timings \n";
                    cout << "1. 08:00 \n";
                    cout << "2. 12:00 \n";
                    cout << "3. 16:00 \n";
                    cout << "4. 20:00 \n\n";
                    cout << "Enter Choice:" << "\t";
                    cin >> b;
                    system("CLS");
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter Name:" << "\t";
                    getline(cin,name);
                    cout << "Enter Contact Number:" << "\t";
                    cin >> t.cno;
                        if (strlen(t.cno)!=11) {
                            cout << "Please enter a valid number. \n";
                            cin >> t.cno;
                        }
                    cout << "\nEnter the number of ticket/s you want to purchase:" << "\t";
                    cin >> x;
                    cout << endl;
                    initializedSeats();
                    displaySeats();
                        while (seatsBooked < x) {
                            cout << "\nNote: 'O' is an available seat, and 'X' is a booked seat. \n";
                            cout << "Enter row and column number to book a seat (e.g., A 1):" << "\t";
                            char row;
                            int col;
                            cin >> row >> col;
                            row = toupper(row);
                            int rowIndex = row - 'A';
                            int colIndex = col - 1;
                            if (bookSeat(rowIndex,colIndex)) {
                                system ("CLS");
                                displaySeats();
                            }
                        }
                    cout << "\n  All " << x << " seat/s have been booked. \n";
                    system("PAUSE");
                    payment(x);
                    system("CLS");
                    cout << "\n  Your ticket is here: \n";
                    cout << "Name:" << "\t" << name << "\n";
                    cout << "Contact Number:" << "\t" << t.cno << "\n";
                    cout << "Ticket Number:" << "\t" << ticketNumber << "\n";
                    cout << "Movie:" << "\t";
                    switch (a) {
                        case 1: cout << "Interstellar";
                            break;
                        case 2: cout << "Gomburza";
                            break;
                        case 3: cout << "My Happy Marriage";
                            break;
                        case 4: cout << "The Moon";
                            break;
                        case 5: cout << "Yesterday Once More";
                            break;
                        default: cout << "Invalid Input!";
                    }
                    cout << "\nTime:" << "\t";
                    switch (b) {
                        case 1: cout << "08:00";
                            break;
                        case 2: cout << "12:00";
                            break;
                        case 3: cout << "16:00";
                            break;
                        case 4: cout << "20:00";
                            break;
                        default: cout << "Invalid Input!";
                    }
                    cout << "\n\nDo you want to choose another option? (y/n) ";
                    cin >> ans;
                    system("CLS");
                    break;
                default: cout << "Invalid Input!";
            } break;

        case 2:
            system ("CLS");
            cout << "Enter Username:" << "\t";
            cin >> username;
            cout << "Enter Password:" << "\t";
            cin >> password;
                if (admin.isAdmin(username,password)) {
                    cout << "Admin Login Successful. \n";
                } else {
                    cout << "Invalid. Access Denied. \n";
                }
            cout << "\nDo you want to choose another option? (y/n) ";
            cin >> ans;
            system("CLS");
            break;

        case 3:
            system("CLS");
            cout << "For more inquiries, kindly send us an email at flixticket@capca.com or contact us at +123-456-7890. \n";
            cout << "\nDo you want to choose another option? (y/n) ";
            cin >> ans;
            system("CLS");
            break;

        case 4:
            system("CLS");
            cout << "Thank You and Come to Visit Again. \n";
            system("PAUSE");
            exit(0);
            break;
    }
    } while (ch != 4 && ans == 'y');

    return 0;
}

int daysInMonth(int year,int month) {
    switch (month) {
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 31;
    }
}

bool isValidDateFormat(const string&date) {
    regex pattern("\\b\\d{4}-\\d{2}-\\d{2}\\b");
    return regex_match(date, pattern);
}

bool isValidDate(const string&date) {
    int year = stoi(date.substr(0,4));
    int month = stoi(date.substr(5,2));
    int day = stoi(date.substr(8,2));
    if (year < 2024) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > daysInMonth(year, month)) {
        return false;
    }
    return true;
}

bool isValidCno(const char*cno) {
    int len = strlen(cno);
    if (len != 11)
        return false;
    if (strncmp(cno,"+639",4) != 0 && strncmp(cno,"09",2) !=0)
        return false;
    for (int i = 3; i < len; ++i) {
        if (!isdigit(cno[i]))
            return false;
    }
    return true;
}

void initializedSeats() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            seats[i][j] = 'O';
        }
    }
}

void displaySeats() {
    cout << "\t ---Screen this way--- \n\n";
    cout << " ";
    for (int i = 0; i < cols; i++) {
        cout << setw(3) << i + 1;
    }
    cout << endl;
    for (int i = 0; i < rows; ++i) {
        cout << char('A' + i) << " ";
        for (int j = 0; j < cols; ++j) {
            cout << setw(3) << seats[i][j];
        }
        cout << endl;
    }
}

bool bookSeat(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        cout << "Invalid seat selection. Please try again." << endl;
        return false;
    }
    if (seats[row][col] == 'X') {
        cout << "Sorry, the seat is already booked. Please select another seat." << endl;
        return false;
    }
    if (seatsBooked >= rows * cols) {
        cout << "All seats have been booked. Cannot book more." << endl;
        return false;
    }
    seats[row][col] = 'X';
    seatsBooked++;
    cout << "Seat booked successfully!" << endl;
    return true;
}

bool isExpDtValid (const string&expdt) {
    time_t currentTime = time(nullptr);
    tm* now = localtime(&currentTime);
    int currentMonth = now->tm_mon + 1;
    int currentYear = now->tm_year + 1900;
    int expMonth,expYear;
    sscanf(expdt.c_str(), "%d/%d", &expMonth, &expYear);
        if (expYear > currentYear || (expYear == currentYear && expMonth >= currentMonth)) {
            return true;
        } else {
            return false;
        }
}

void payment(int x) {
    system("CLS");
    int amt,cvv[5];
    string cdh,crd,exp;
    amt = x * 300;
    cout << "Total cost for " << x << " tickets: Php " << amt << "\n";
    cout << "\n  Please enter your card details: \n";
    cout << "Name of the Card Holder:" << "\t";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,cdh);
    cout << "Enter the card number:" << "\t";
    cin >> crd;
        while (crd.length() < 16 || crd.length() > 19) {
            cout << "Invalid Card Number. \n";
            cout << "Enter again:" << "\t";
            cin >> crd;
        }
    cout << "Expiration Date [mm-yyyy]:" << "\t";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,exp);
        while (!isExpDtValid(exp)) {
            cout << "Error. Expiration date is invalid or has already passed. \n";
            cout << "Enter again:" << "\t";
            getline(cin,exp);
        }
    cout << "Enter the CVV:" << "\t";
        int i = 0;
        while (i < 4) {
            cvv[i] = getch();
            cout << "*";
            ++i;
        }
        cvv[i] = '\0';
    bool paymentAuthorized = true;
        if (paymentAuthorized) {
            cout << "\n\nPayment successful. \n";
        } else {
            cout << "\n\nPayment authorization failed.\n";
        }
    system("PAUSE");
}

int generateTicketNumber() {
    srand (static_cast<unsigned int>(time(nullptr)));
    return rand() % 400000 + 100000;
}
