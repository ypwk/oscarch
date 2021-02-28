#include <iostream>
#include <SquarePrinter.h>
#include "FigurePrinter.h"
#include "TrianglePrinter.h"
#include "DiamondPrinter.h"

using namespace std;

//program that runs in O(n^2) and uses O(1) of space
int main(int argc, char *argv[]) {

    //check the argument
    if (argc != 2) {
        cout << "Please provide a number" << endl;
        return 0;
    }

    try {
        //convert the number
        int n = stoi(argv[1]);

        std::cout << "The triangle: " << std::endl;
        FigurePrinter *printer = new TrianglePrinter(n);
        printer->printFigure();
        delete printer;

        std::cout << "The diamond: " << std::endl;
        printer = new DiamondPrinter(n);
        printer->printFigure();
        delete printer;

        std::cout << "The square: " << std::endl;
        printer = new SquarePrinter(n);
        printer->printFigure();
        delete printer;

    } catch (exception &ex) {
        cerr << "An error occurred: ";
        cerr << ex.what() << endl;
    } catch (...) {
        cerr << "Unexpected error";
    }

    return 0;
}