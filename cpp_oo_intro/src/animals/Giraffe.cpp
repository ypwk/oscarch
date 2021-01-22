//
// Created by ojcch on 1/21/2021.
//

#include "animals/Giraffe.h"


Giraffe::Giraffe(string name) : Animal(name, "giraffe") {

}

void Giraffe::eat(string &food) {
    cout << this->getName() << " is chewing " << food << endl;
}

void Giraffe::makeNoise() {
    cout << this->getName() << " is just making noise " << endl;
}

//this is the overridden, non-polymorphic method implementation
void Giraffe::sleep() {
    cout << this->getName() << " is taking a standing sleep " << endl;
}
