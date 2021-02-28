//
// Created by ojcch on 2/3/2021.
//

#include "date/SimpleDate.h"

using namespace std;


bool SimpleDate::isLeap(unsigned short yearParam) {

    //not divisible by four --> non-leap year
    if (yearParam % 4 != 0)
        return false;

    //otherwise, divisible by 4, hence, it may be a leap year

    //not divisible by 100 --> leap year
    if (yearParam % 100 != 0)
        return true;

    //otherwise... year is divisible by 100

    //divisible by 400? --> leap year
    //otherwise --> non-leap year
    return yearParam % 400 == 0;

}

unsigned short SimpleDate::monthLength[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

SimpleDate SimpleDate::nextDate() const {

    int monthLastDay = monthLength[month - 1];

    bool isLeap = SimpleDate::isLeap(year);

    if (month == 2 && isLeap) {
        monthLastDay++;
    }

    unsigned short newMonth = 0;
    unsigned short newDay = 0;
    unsigned short newYear = 0;

    if (month == 12 && day == 31) { //end of year
        newMonth = 1;
        newDay = 1;
        newYear = year + 1;
    } else if (day == monthLastDay) { //end of month
        newMonth = month + 1;
        newDay = 1;
        newYear = year;
    } else { //regular day
        newMonth = month;
        newDay = day + 1;
        newYear = year;
    }

    return {newMonth, newDay, newYear};
}

SimpleDate::SimpleDate(unsigned short monthParam, unsigned short dayParam, unsigned short yearParam) :
        year(yearParam), month(monthParam), day(dayParam) {}

string SimpleDate::toString() const {
    string monthPrefix;
    string dayPrefix;
    if (month < 10) monthPrefix = "0";
    if (day < 10) dayPrefix = "0";

    return string(monthPrefix)
            .append(to_string(month))
            .append("/")
            .append(dayPrefix)
            .append(to_string(day))
            .append("/")
            .append(to_string(year));
}