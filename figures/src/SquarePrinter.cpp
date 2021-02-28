//
// Created by ojcch on 2/19/2021.
//

#include "SquarePrinter.h"
#include <iostream>

using namespace std;

void SquarePrinter::printFigure() {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "* ";
        }
        cout << endl;
    }
}
