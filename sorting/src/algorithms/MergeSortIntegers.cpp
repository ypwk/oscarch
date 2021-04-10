//
// Created by ojcch on 3/30/2020.
//

#include <utility>
#include <vector>
#include <algorithms/MergeSortIntegers.h>

MergeSortIntegers::MergeSortIntegers(vector<int> inputArray) {
    //move avoids making a copy of the vector, which could be costly for large input arrays
    this->array = std::move(inputArray);
}

vector<int> MergeSortIntegers::sort() {
    //we create the temporary array for merging
    vector<int> temp = vector<int>(this->array.size());
    //we call merge sort on the entire array
    mergeSort(temp, 0, array.size() - 1);
    //return temp, which contains the sorted array
    return temp;
}

void MergeSortIntegers::mergeSort(vector<int> &temp, int left, int right) {
    //IMPLEMENT THE ALGORITHM HERE
}
