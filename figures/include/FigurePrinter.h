//
// Created by ojcch on 1/9/2021.
//

#ifndef FIGUREPRINTER_H
#define FIGUREPRINTER_H

/*
 * Abstract class that prints a figure using stars, whose size is defined by an integer n
 */
class FigurePrinter {

public:
    /*
     * Main constructor
     */
    FigurePrinter(int n);

    /*
     * Prints the figure
     */
    virtual void printFigure() = 0;

protected:
    int n;

};


#endif
