#include <iostream>
#include <date/SimpleDate.h>
#include "date/DateException.h"

/*
 * Throws an exception if the date is invalid, otherwise, it returns a SimpleDate
 */
SimpleDate validateDate(short month, short day, short year);

using namespace std;

//program that runs in O(1)
int main(int argc, char *argv[]) {

    //check the argument
    if (argc != 2) {
        cout << "Please provide a date in mm/dd/yyyy format" << endl;
        return 0;
    }

    string inputDate(argv[1]);

    try {
        //parse the input
        short month = stoi(inputDate.substr(0, 2));
        short day = stoi(inputDate.substr(3, 2));
        short year = stoi(inputDate.substr(6, 4));

        //validate the input
        SimpleDate date = validateDate(month, day, year);

        //next date
        SimpleDate next = date.nextDate();
        cout << next.toString() << endl;

    } catch (DateException &ex) {
        cerr << "The input date seems incorrect: ";
        cerr << ex.what() << endl;
    } catch (exception &ex) {
        cerr << "An error occurred when parsing the date: ";
        cerr << ex.what() << endl;
    } catch (...) {
        cerr << "Unexpected error";
    }

    return 0;
}

SimpleDate validateDate(short month, short day, short year) {

    if (year < 1812 || year > 2030) {
        throw DateException("Invalid year: " + to_string(year));
    }

    if (month < 1 || month > 12)
        throw DateException("Invalid month: " + to_string(month));

    int monthLastDay = SimpleDate::monthLength[month - 1];

    bool isLeap = SimpleDate::isLeap(year);

    if (month == 2 && isLeap) {
        monthLastDay++;
    }

    if (day > monthLastDay || day <= 0) {
        throw DateException("Invalid day: " + to_string(day));
    }

    return SimpleDate(month, day, year);
}
