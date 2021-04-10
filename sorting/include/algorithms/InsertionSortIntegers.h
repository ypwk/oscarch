//
// Created by ojcch on 4/2/2020.
//

#ifndef SORTING_INSERTIONSORT_H
#define SORTING_INSERTIONSORT_H

#include <vector>

using namespace std;

/*
 * Insertion sort implementation for integers only
 */
class InsertionSortIntegers {
private:
    //the vector that insertion sort aims to sort
    vector<int> array;
public:
    //constructor of the class
    explicit InsertionSortIntegers(vector<int> inputArray);

    //sorts the elements from array
    //it returns a vector with the sorted elements
    vector<int> sort() ;

};


#endif //SORTING_INSERTIONSORT_H
