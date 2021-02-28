//
// Created by ojcch on 1/9/2021.
//

#ifndef DIAMONDPRINTER_H
#define DIAMONDPRINTER_H


#include "FigurePrinter.h"
#include "TrianglePrinter.h"

/*
 * Prints a diamond whose with max width n
 */
class DiamondPrinter : public TrianglePrinter {

public:
    DiamondPrinter(int n);

    void printFigure();

private:
    void printUpwardTriangle();
};


#endif
