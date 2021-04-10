//
// Created by ojcch on 4/7/2020.
//

#ifndef SORTING_QUICKSORT_H
#define SORTING_QUICKSORT_H

#include <vector>

using namespace std;

/*
 * Quicksort implementation for integers only.
 * It users median-of-three to select the pivot.
 * It uses the partitioning strategy covered in the lecture.
 */
class QuickSortIntegers {
private:
    vector<int> array;

    //method that implements quicksort.
    //it receives the left and right indices that indicate the portion of the array that will be sorted
    void quicksort(int left, int right);
public:
    //constructor of the class
    explicit QuickSortIntegers(vector<int> inputArray) ;

    //sorts the elements from array
    //it returns a vector with the sorted elements
    vector<int> sort() ;


};

#endif //SORTING_QUICKSORT_H
