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

    bool isLeapYear(int y) {
        return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    }

    int daysInMonth(int m, int y) {
        if (m == 2) return isLeapYear(y) ? 29 : 28;
        if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }

    bool isValidDate(int m, int d, int y) {
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > daysInMonth(m, y)) return false;
        return true;
    }

public:
    Date() {
        month = 1;
        day = 1;
        year = 2000;
    }

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

    void setDate(int m, int d, int y) {
        if (isValidDate(m, d, y)) {
            month = m;
            day = d;
            year = y;
        }
        else {
            cout << "Invalid date. No changes made." << endl;
        }
    }

    void printFormat1() {
        cout << month << "/" << day << "/" << year << endl;
    }

    void printFormat2() {
        string months[] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
        cout << months[month] << " " << day << ", " << year << endl;
    }

    void printFormat3() {
        string months[] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
        cout << day << " " << months[month] << " " << year << endl;
    }

    Date& operator++() {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    Date operator++(int) {
        Date temp = *this;
        ++(*this);
        return temp;
    }

    Date& operator--() {
        day--;
        if (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day = daysInMonth(month, year);
        }
        return *this;
    }

    Date operator--(int) {
        Date temp = *this;
        --(*this);
        return temp;
    }

    int operator-(const Date& other) const {
        auto countDays = [](int d, int m, int y) {
            int days = d;
            for (int i = 1; i < m; i++) {
                if (i == 2)
                    days += (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28;
                else if (i == 4 || i == 6 || i == 9 || i == 11)
                    days += 30;
                else
                    days += 31;
            }

            days += y * 365 + y / 4 - y / 100 + y / 400;
            return days;
            };

        return abs(countDays(day, month, year) - countDays(other.day, other.month, other.year));
    }

    friend ostream& operator<<(ostream& out, const Date& d) {
        string months[] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
        out << months[d.month] << "" << d.day << ", " << d.year;
        return out;
    }

    friend istream& operator>>(istream& in, Date& d) {
        int m, dy, y;
        cout << "Enter month, day, and year (MM DD YYYY): ";
        in >> m >> dy >> y;
        if (d.isValidDate(m, dy, y)) {
            d.month = m;
            d.day = dy;
            d.year = y;
        }
        else {
            cout << "Invalid date entered." << endl;
        }
        return in;
    }
};

int main() {
    Date date(12, 25, 2021);
    date.printFormat1();
    date.printFormat2();
    date.printFormat3();

    ++date;
    cout << "After prefix ++: " << date << endl;

    date++;
    cout << "After postfix ++: " << date << endl;

    --date;
    cout << "After prefix --: " << date << endl;

    date--;
    cout << "After postfix --: " << date << endl;

    Date d1(4, 18, 2014), d2(4, 10, 2014);
    cout << "Difference between d1 and d2: " << d1 - d2 << " days" << endl;

    Date inputDate;
    cin >> inputDate;
    cout << "You entered: " << inputDate << endl;

    return 0;
}