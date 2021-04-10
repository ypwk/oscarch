//
// Created by ojcch on 3/30/2020.
//

#ifndef SORTING_MERGESORT_H
#define SORTING_MERGESORT_H

#include <vector>

using namespace std;

/*
 * Mergesort implementation for integers only
 */
class MergeSortIntegers {

private:
    //the vector that mergesort aims to sort
    vector<int> array;

    //method that implements mergesort.
    //it receives a temporary array, used by the merging operation, and the left and right indices that
    //indicate the portion of the array that will be sorted
    void mergeSort(vector<int> &temp, int left, int right) ;
public:
    //constructor of the class
    explicit MergeSortIntegers(vector<int> inputArray) ;

    //sorts the elements from array
    //it returns a vector with the sorted elements
    vector<int> sort() ;

};


#endif //SORTING_MERGESORT_H
