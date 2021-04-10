//
// Created by ojcch on 4/2/2020.
//

#ifndef SORTING_ARRAYUTILITIES_H
#define SORTING_ARRAYUTILITIES_H

#include <string>
#include <vector>
#include <entity/MailingAddress.h>
#include <entity/Coordinate.h>

using namespace std;

/*
 * Class that contains utility methods for converting other classes to string and for printing arrays
 */
template <class Object>
class ArrayUtilities {
public:

    //prints inputArray in the terminal
    //it uses the format [a, b, c, ...]
    static void printArray(vector<Object> &inputArray);

    //utility method that returns item
    static string toString(string& item);

    //returns item as a string
    static string toString(int& item);

    //returns item as a string
    static string toString(MailingAddress& item);

    //returns item as a string
    static string toString(Coordinate& item);
};


#endif //SORTING_ARRAYUTILITIES_H
