//
// Created by ojcch on 1/9/2021.
//

#ifndef TRIANGLEPRINTER_H
#define TRIANGLEPRINTER_H


#include "FigurePrinter.h"

/*
 * Prints a triangle of base n, pointing downwards
 */
class TrianglePrinter : public FigurePrinter {
public:
    explicit TrianglePrinter(int n) : FigurePrinter(n) {}

    void printFigure();

protected:
    void printDownwardTriangle() const;
};


#endif
