//
// Created by ojcch on 1/9/2021.
//

#include <iostream>
#include "TrianglePrinter.h"

void TrianglePrinter::printFigure() {
    printDownwardTriangle();
}

void TrianglePrinter::printDownwardTriangle() const {
    int numSpaces = 0;

    //reduce the number of stars by 2
    for (int numStars = n; numStars > 0; numStars = numStars - 2) {

        //prints the left-most spaces
        for (int j = 0; j <= numSpaces; j++)
            std::cout << " ";

        //prints the stars
        for (int j = 0; j < numStars; j++)
            std::cout << "*";

        std::cout << std::endl; //new line

        //increase the number of spaces by 1
        numSpaces++;
    }
}
