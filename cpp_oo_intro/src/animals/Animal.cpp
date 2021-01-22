//
// This is the implementation of the class Animal
//

#include "animals/Animal.h"

//static attributes are initialized like this:
string Animal::kingdom = "Animal kingdom";

//this is the static method, which can also use static members
void Animal::printKingdom() {
    cout << "Kingdom: " << kingdom << endl;
}

//----------------------------------------------

//getters and setters

const string &Animal::getName() {
    return name;
}

void Animal::setName(const string &name) {
    Animal::name = name;
}

const string &Animal::getType() {
    return type;
}

void Animal::setType(const string &type) {
    Animal::type = type;
}

string *Animal::getWikipediaDescription() const {
    return wikipediaDescription;
}

void Animal::setWikipediaDescription(string *wikipediaDescription) {
    this->wikipediaDescription = wikipediaDescription;
}

const string &Animal::getLocation() const {
    return location;
}

void Animal::setLocation(const string &location) {
    this->location = location;
}

//----------------------------------------------
//constructors and destructors

Animal::Animal(string name, string type) {
    initialize(name, type);
}

Animal::Animal(string type) {
    initialize("Tom", type);
}

//initialize is a helper method for the constructors, in order to avoid code duplication
void Animal::initialize(string name, string type) {
    setName(name);
    setType(type);
    this->location = "Unknown";
    setWikipediaDescription(nullptr);
}

Animal::~Animal() {
    cout << "Destroying the animal: " << getName() << endl;
    delete wikipediaDescription; //here we make sure we deallocate the variable from the Heap
}

//----------------------------------------------

void Animal::sleep() {
    cout << name << " just fell asleep" << endl;
}

void Animal::run() {
    cout << name << " is running using its four legs" << endl;
}


void Animal::whereIs() {
    cout << name << " is in " << getLocation() << endl;
}

//----------------------------------------------
