//
// Created by ojcch on 2/3/2021.
//

#ifndef SIMPLEDATE_H
#define SIMPLEDATE_H


#include <string>

/*
 * A simple class for  a date (with no time)
 */
class SimpleDate {

private:
    unsigned short year;
    unsigned short month;
    unsigned short day;
public:

    //each element is the number of days in a month. Position 0 is January, 1 is February, etc.
    static unsigned short monthLength[12];

    /*
     * Main constructor
     */
    SimpleDate(unsigned short monthParam, unsigned short dayParam, unsigned short yearParam);

    /*
     * Returns the next date
     */
    SimpleDate nextDate() const;

    /*
     * Returns the date in in mm/dd/yyyy format
     */
    std::string toString() const;

    /*
    * Checks if the year is leap (true) or not (false)
    */
    static bool isLeap(unsigned short yearParam);


};


#endif
