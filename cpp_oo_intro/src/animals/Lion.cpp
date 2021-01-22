//
// Created by ojcch on 1/21/2021.
//

#include "animals/Lion.h"

//this is how the constructor of the superclass (Animal) is called
Lion::Lion(string name, string type) : Animal(name, type) {

}

Lion::Lion(string name) : Animal(name, "feline") {

}

void Lion::eat(string &food) {
    cout << this->getName() << " is devouring " << food << endl;
}

void Lion::makeNoise() {
    roar();
}

void Lion::roar() {
    cout << this->getName() << " is roaring " << endl;
}
