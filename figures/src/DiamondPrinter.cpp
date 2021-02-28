//
// Created by ojcch on 1/9/2021.
//

#include <iostream>
#include "DiamondPrinter.h"

DiamondPrinter::DiamondPrinter(int n) : TrianglePrinter(n) {}

void DiamondPrinter::printFigure() {
    printUpwardTriangle();
    this->printDownwardTriangle();
}

void DiamondPrinter::printUpwardTriangle() {

    int numSpaces = n / 2 - (n + 1) % 2;

    //increase the number of stars by 2
    for (int numStars = 1 + (n + 1) % 2; numStars < n; numStars = numStars + 2) {

        //prints the left-most spaces
        for (int j = 0; j <= numSpaces; j++)
            std::cout << " ";

        //prints the stars
        for (int j = 0; j < numStars; j++)
            std::cout << "*";

        std::cout << std::endl; //new line

        //reduce the number of spaces
        numSpaces--;
    }
}

