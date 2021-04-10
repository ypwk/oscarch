//
// Created by ojcch on 4/3/2020.
//


#include <comparator/CoordinateYXComparator.h>

bool CoordinateYXComparator::lessThan(Coordinate &c1, Coordinate &c2) {
    if (c1.y < c2.y) return true;
    return c1.y == c2.y && c1.x < c2.x;
}


bool CoordinateYXComparator::equals(Coordinate &c1, Coordinate &c2) {
    return c1.equals(c2);
}