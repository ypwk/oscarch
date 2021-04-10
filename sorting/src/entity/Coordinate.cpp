//
// Created by ojcch on 4/3/2020.
//


#include <entity/Coordinate.h>


Coordinate::Coordinate(int x, int y) {
    this->x = x;
    this->y = y;
}


bool Coordinate::operator<(Coordinate const &coor) const {
    if (this->x < coor.x) return true;
    return this->x == coor.x && this->y < coor.y;
}


bool Coordinate::operator<=(Coordinate const &coor) const {
    return *this < coor || this->equals(coor);
}

bool Coordinate::equals(Coordinate const &obj) const {
    return this->x == obj.x && this->y == obj.y;
}

string Coordinate::toString() const {
    return "(" + to_string(x) + ", " + to_string(y) + ")";
}
