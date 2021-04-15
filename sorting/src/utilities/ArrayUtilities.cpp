//
// Created by ojcch on 4/2/2020.
//

#include "utilities/ArrayUtilities.h"
#include <iostream>

template<class Object>
void ArrayUtilities<Object>::printArray(vector<Object> &inputArray) {
    string str = "[";
    for (Object item  : inputArray) {
        str.append(toString(item));
        str.append(", ");
    }

    if (!inputArray.empty()) {
        str.erase(str.end() - 2, str.end());
    }
    str.append("]");
    cout << str << endl;
}

template<class Object>
string ArrayUtilities<Object>::toString(string &item) {
    return item;
}

template<class Object>
string ArrayUtilities<Object>::toString(int &item) {
    return to_string(item);
}

template<class Object>
string ArrayUtilities<Object>::toString(MailingAddress &item) {
    return item.toString();
}

template<class Object>
string ArrayUtilities<Object>::toString(Coordinate &item) {
    return item.toString();
}

template class ArrayUtilities<int>;
template class ArrayUtilities<Coordinate>;
template class ArrayUtilities<MailingAddress>;