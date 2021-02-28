//
// Created by ojcch on 2/19/2021.
//

#ifndef FIGURES_SQUAREPRINTER_H
#define FIGURES_SQUAREPRINTER_H



#include "FigurePrinter.h"

/*
 * Prints a square of size n
 */
class SquarePrinter : public FigurePrinter {
public:
    explicit SquarePrinter(int n) : FigurePrinter(n) {}
    void printFigure() override;
};


#endif //FIGURES_SQUAREPRINTER_H
