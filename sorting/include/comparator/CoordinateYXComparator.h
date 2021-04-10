//
// Created by ojcch on 4/3/2020.
//

#ifndef SORTING_COORDINATEYXCOMPARATOR_H
#define SORTING_COORDINATEYXCOMPARATOR_H

#include "Comparator.h"
#include "entity/Coordinate.h"

/*
 * A Comparator of Coordinates (x, y). It inherits from Comparator<Coordinate>
 *
 * It defines the following order for two coordinates:
 *  (x1, y1) < (x2, y2)
 * If:
 *   y1 < y2 OR ( y1 == y2 AND x1 < x2 )
 *
 *  In other words, the order is first determined by y and then by x
 *
 */
class CoordinateYXComparator: public Comparator<Coordinate> {


    //returns true if c1 < c2, when c1.y < c2.y OR ( c1.y == c2.y AND c1.x < c2.x)
    //returns false otherwise
    bool lessThan(Coordinate &c1, Coordinate &c2) override ;

    //returns true if c1 == c2, when  c1.x == c2.x AND  c1.y == c2.y
    //returns false otherwise
    bool equals(Coordinate &c1, Coordinate &c2) override;

};


#endif //SORTING_COORDINATEYXCOMPARATOR_H
