//
// Created by ojcch on 2/20/2020.
//

#ifndef MAILINGADDRESS_H
#define MAILINGADDRESS_H

#include <string>

using namespace std;

/*
 * A class that represents a Mailing Address.
 */
class MailingAddress {
private:
    string street;
    string city;
    string state;
    int zipCode = -1;

public:

    //default constructor
    MailingAddress(){};

    //constructor
    MailingAddress(string street, string city, string state, int zipCode);

    //returns true if this address is exactly the same as addr
    //returns false otherwise
    bool equals(const MailingAddress &addr);

    //returns this address as a string in the format {street, city, state, zipcode}
    string toString();

    //--------------------------------
    //getter methods

    string getStreet();

    string getCity();

    string getState();

    int getZipCode();
    //-------------------------------

    /*
     * The < operator is defined (or overloaded).
     *
     * returns true if this < addr.
     * returns false otherwise
     *
     * The order of the addresses is determined
     * first by street (in alphabetical order),
     * then by city  (in alphabetical order),
     * then by state  (in alphabetical order),
     * and then by zipcode  (in ascending numerical order).
     *
     *
    */
    bool operator<(MailingAddress const &addr);

    /*
     * The <= operator is defined (or overloaded).
     *
     * returns true if this < addr OR this == addr. returns false otherwise.
     *
     */
    bool operator<=(MailingAddress const &addr);

};

#endif //MAILINGADDRESS_H
