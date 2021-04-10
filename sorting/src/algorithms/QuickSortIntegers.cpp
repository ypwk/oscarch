//
// Created by ojcch on 4/7/2020.
//



#include <algorithms/QuickSortIntegers.h>

QuickSortIntegers::QuickSortIntegers(vector<int> inputArray) {
    //move avoids making a copy of the vector, which could be costly for large input arrays
    this->array = std::move(inputArray);
}

vector<int> QuickSortIntegers::sort() {
    //we call quick sort on the array
    quicksort(0, array.size() - 1);
    //we return the array
    return array;
}

void QuickSortIntegers::quicksort(int left, int right) {
    //IMPLEMENT THE ALGORITHM HERE
}
