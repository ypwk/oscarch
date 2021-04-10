//
// Created by ojcch on 4/2/2020.
//

#include "algorithms/InsertionSortIntegers.h"

InsertionSortIntegers::InsertionSortIntegers(vector<int> inputArray) {
    //move avoids making a copy of the vector, which could be costly for large input arrays
    this->array = std::move(inputArray);
}

vector<int> InsertionSortIntegers::sort() {
    for (int p = 1; p < array.size(); p++) {
        int tmp = array[p];
        int j = p;
        for (; (j > 0) && (tmp < array[j - 1]); j--) {
            array[j] = array[j - 1];
        }
        array[j] = tmp;
    }
    return array;
}
