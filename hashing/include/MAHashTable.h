//
// Created by ojcch on 3/21/2020.
//

#ifndef MLHASHTABLE_H
#define MLHASHTABLE_H

#include <vector>
#include "MailingAddress.h"

/*
 * A hash table of MailingAddresses that uses separate chaining for collision resolutions
 */
class MAHashTable {
public:

    //hash function parameters
    static const int M = 97; //table size
    static const int R = 31; //R parameter for hashing strings

    int N; //# of elements hashed in the table

    //the
    vector<vector<MailingAddress>> table;

    //default constructor
    MAHashTable();

    //--------------------------

    //inserts the address into the hash table
    void insert(const MailingAddress &address);

    //returns true if the address was hashed, otherwise false
    bool contains(MailingAddress address);

    //returns the load factor of the table
    float getLoadFactor() const;

    //prints the table in the following format:
    //    0->[]
    //    1->[{1470 S Washington St, North Attleboro, MA, 2760}]
    //    2->[{901 Route 110, Farmingdale, NY, 11735}]
    //    3->[{300 Colony Place, Plymouth, MA, 2360}; {450 Highland Ave, Salem, MA, 1970}]
    //    4->[{780 Lynnway, Lynn, MA, 1905}]
    //    5->[]
    //    6->[]
    //    …
    void print();


    //returns the hash of an integer
    static long hashInt(int i);

    //returns the hash of a string
    static long hashString(const string &s);

    //returns the hash of a MailingAddress
    static long hashAddress(const MailingAddress &address);

private:

    //helper method to print a slot of the hash table
    static void print(int i, const vector<MailingAddress> &vector);

};


#endif //MLHASHTABLE_H

