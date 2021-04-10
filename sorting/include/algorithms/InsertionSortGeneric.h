#ifndef SORTING_INSERTIONSORTGENERIC_H
#define SORTING_INSERTIONSORTGENERIC_H

#include <vector>

using namespace std;

/*
 * Insertion sort implementation for vectors of Comparable objects
 * Comparable is any type of object (e.g., string, int, MailingAddress, etc.)
 * IMPORTANT REQUIREMENT: Comparable *must* overload the operator <
 */
template <class Comparable>
class InsertionSortGeneric {
private:
    //the vector that insertion sort aims to sort
    vector<Comparable> array;
public:

    //constructor of the class
    explicit InsertionSortGeneric(vector<Comparable> inputArray) ;

    //sorts the elements from array in the order specified by the operator <
    //it returns a vector with the sorted elements
    vector<Comparable> sort() ;

};


#endif //SORTING_INSERTIONSORTGENERIC_H
