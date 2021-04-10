//
// Created by ojcch on 4/2/2020.
//



#include <algorithms/InsertionSortGenericWithComparator.h>
#include <entity/Coordinate.h>
#include <entity/MailingAddress.h>

template<class Comparable>
InsertionSortGenericWithComparator<Comparable>::InsertionSortGenericWithComparator(vector <Comparable> inputArray) {
    //move avoids making a copy of the vector, which could be costly for large input arrays
    this->array = std::move(inputArray);
}

template<class Comparable>
vector <Comparable> InsertionSortGenericWithComparator<Comparable>::sort(Comparator<Comparable> *comparator) {
    for (int p = 1; p < array.size(); p++) {
        Comparable tmp = array[p];
        int j = p;
        // in the condition of the loop we are using the Comparator on Comparable objects
        for (; (j > 0) && (comparator->lessThan(tmp, array[j - 1])); j--) {
            array[j] = array[j - 1];
        }
        array[j] = tmp;
    }
    return array;
}

template class InsertionSortGenericWithComparator<int>;
template class InsertionSortGenericWithComparator<Coordinate>;
template class InsertionSortGenericWithComparator<MailingAddress>;