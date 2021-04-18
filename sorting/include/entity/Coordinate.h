//
// Created by ojcch on 4/3/2020.
//

#ifndef SORTING_COORDINATE_H
#define SORTING_COORDINATE_H

#include <string>

using namespace std;

/*
 * A class that represents a Coordinate (x, y)
 */
class Coordinate {
public:
    //the coordinate components
    int x = -1;
    int y = -1;

    //default constructor
    Coordinate(){}

    //constructor
    Coordinate(int x, int y);

    /*
     * The < operator is defined (or overloaded) as:
     *
     * returns true if this < coor, when this.x < coor.x OR ( this.x == coor.x AND this.y < coor.y)
     * returns false otherwise
     *
     */
    bool operator<(Coordinate const &coor) const;

    /*
     * The <= operator is defined (or overloaded).
     *
     * returns true if this < coor OR this == coor. returns false otherwise.
     *
     */
    bool operator<=(Coordinate const &coor) const;

    //returns true if this coordinate == obj, when this.x == coor.x AND  this.y == coor.y
    //returns false otherwise
    bool equals(Coordinate const &obj) const;

    //return the coordinate as a string in the format (x, y)
    string toString() const;
};

#endif //SORTING_COORDINATE_H
