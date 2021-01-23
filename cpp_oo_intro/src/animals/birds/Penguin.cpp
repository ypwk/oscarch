//
// Created by ojcch on 1/21/2021.
//

#include "animals/birds/Penguin.h"
#include "exceptions/FoodException.h"

Penguin::Penguin(string name) : Bird(name) {

}

void Penguin::eat(string &food) {
    if (food == "grass") {
        //an exception is thrown if the food is grass
        throw FoodException("Penguins do not eat grass");
    }
    cout << this->getName() << " is eating " << food << endl;
}

void Penguin::makeNoise() {
    cout << this->getName() << " is making noise as a penguin " << endl;
}
