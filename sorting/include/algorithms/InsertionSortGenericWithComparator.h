//
// Created by ojcch on 4/2/2020.
//

#ifndef SORTING_INSERTIONSORTGENERICWITHCOMPARATOR_H
#define SORTING_INSERTIONSORTGENERICWITHCOMPARATOR_H

#include <vector>
#include "comparator/Comparator.h"

using namespace std;

/*
 * Insertion sort implementation for vectors of Comparable objects
 * Comparable is any type of object (e.g., string, int, MailingAddress, etc.)
 *
 * The sort method uses a Comparator which determines the order of Comparable objects
 */
template <class Comparable>
class InsertionSortGenericWithComparator {
private:
    //the vector that insertion sort aims to sort
    vector<Comparable> array;
public:

    //constructor of the class
    explicit InsertionSortGenericWithComparator(vector<Comparable> inputArray);

    //sorts the elements from array in the order specified by comparator
    //it returns a vector with the sorted elements
    vector<Comparable> sort(Comparator<Comparable>* comparator) ;

};


#endif //SORTING_INSERTIONSORTGENERICWITHCOMPARATOR_H
