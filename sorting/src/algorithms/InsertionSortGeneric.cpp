//
// Created by ojcch on 4/2/2020.
//

#include <algorithms/InsertionSortGeneric.h>
#include <entity/Coordinate.h>
#include <entity/MailingAddress.h>

using namespace std;

template <class Comparable>
InsertionSortGeneric<Comparable>::InsertionSortGeneric(vector<Comparable> inputArray) {
    //move avoids making a copy of the vector, which could be costly for large input arrays
    this->array = std::move(inputArray);
}

template <class Comparable>
vector<Comparable> InsertionSortGeneric<Comparable>::InsertionSortGeneric::sort() {
    for (int p = 1; p < array.size(); p++) {
        Comparable tmp = array[p];
        int j = p;
        // in the condition of the loop we are using the < operator on Comparable objects,
        // so the Comparable class should overload this operator
        for (; (j > 0) && (tmp < array[j - 1]); j--) {
            array[j] = array[j - 1];
        }
        array[j] = tmp;
    }
    return array;
}


template class InsertionSortGeneric<int>;
template class InsertionSortGeneric<Coordinate>;
template class InsertionSortGeneric<MailingAddress>;