//
// Created by ojcch on 4/2/2020.
//

#ifndef SORTING_COMPARATOR_H
#define SORTING_COMPARATOR_H

/*
 * An abstract class that compares two Comparable objects and determines their order. *
 */
template<class Comparable>
class Comparator {
public:

    //returns true if obj1 < obj2, according to some definition of <
    //returns false otherwise
    virtual bool lessThan(Comparable &obj1, Comparable &obj2) = 0;

    //returns true if obj1 == obj2, according to some definition of ==
    //returns false otherwise
    virtual bool equals(Comparable &obj1, Comparable &obj2) = 0;

    //returns true if obj1 <= obj2
    //returns false otherwise
    bool lessThanOrEqualTo(Comparable &obj1, Comparable &obj2);

};


#endif //SORTING_COMPARATOR_H
