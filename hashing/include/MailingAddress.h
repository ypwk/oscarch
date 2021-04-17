//
// Created by ojcch on 3/21/2020.
//

#ifndef MA_H
#define MA_H
#include <iostream>

using namespace std;

/*
 * A class representing a Mailing Address
 */
class MailingAddress {
public:

    //attributes
    string street;
    string city;
    string state;
    int zipCode = -1;

    //default constructor
    MailingAddress(string street, string city, string state, int zipCode);

    //returns true if addr is the exact same address as the current address, otherwise, it returns false.
    bool equals(const MailingAddress& a);

    // returns a string of the current address in the following format:
    //{1470 S Washington St, North Attleboro, MA, 2760}
    string toString();

};

#endif //MA_H

