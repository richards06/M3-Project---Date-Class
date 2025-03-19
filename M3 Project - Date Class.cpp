/*
Program Title: Date Class
Programmer: Josh Richards
Date: March 18, 2025
Requirements:

Design a class called Date. The class should store a date in three integers: month, day, and year. 
There should be member functions to print the date in the following forms: 
• 12/25/2021 
• December 25, 2021 
• 25 December 2021 

Demonstrate the class by writing a complete program implementing it. 

Input Validation: Do not accept values for the day greater than the last day of the month or less than 1. 
Do not accept values for the month greater than 12 or less than 1. Design Details (algorithm, pseudocode, or flowchart)

*/

#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int month, day, year;

    bool isValidDate(int m, int d, int y) {
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > daysInMonth(m, y)) return false;
        return true;
    }

    int daysInMonth(int m, int y) {
        if (m == 2) return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28;
            if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }

public:
    Date(int m, int d, int y) {
        if (isValidDate(m, d, y)) {
            month = m;
            day = d;
            year = y;
        }
        else {
            cout << "Invalid date. Setting to default 01/01/2000" << endl;
            month = 1;
            day = 1;
            year = 2000;
        }
    }

    void printFormat1() {
        cout << month << "/" << day << "/" << year << endl;
    }

    void printFormat2() {
        string months[] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        cout << months[month] << " " << day << ", " << year << endl;
    }

    void printFormat3() {
        string months[] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
        cout << day << " " << months[month] << " " << year << endl;
    }
};

int main() {
    Date date(12, 25, 2021);
    date.printFormat1();
    date.printFormat2();
    date.printFormat3();

    return 0;
}


