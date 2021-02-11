// By convention, the class declaration is placed in a .h file,
// while the class definition or implementation is placed in a .cpp file

#ifndef CPP_OO_INTRO_ANIMAL_H
#define CPP_OO_INTRO_ANIMAL_H

#include <iostream>

using namespace std;

/*
 * A class represents an object or entity from the domain of the program. For example, classes in the banking domain are:
 * Account, Transaction, User, etc.
 *
 * A class has internal data (attributes, field, or just variables) and operations that work on that data (methods or functions).
 *
 * A class can have multiple instances, with its own data.
 *
 * This is the abstract class Animal (this is the class declaration, the class implementation is found in Animal.cpp).
 * An abstract class represents an abstract concept that cannot be instantiated directly, but by using its subclasses.
 * Abstract class are those that have one or more virtual methods, e.g.:
 *                        virtual void eat(string &food) = 0;
 */
class Animal {

    /*
     * A class has one or more members, i.e., attributes (i.e., variables) and methods (i.e., functions)
     * The members can be private, protected, or public
     */

    //these are the private members of the class.
    //they can *only* be accessed and used from inside the class.
private:
    string name; //attribute
    string type; //attribute

    string *wikipediaDescription; //attribute

    void initialize(string name, string type); //method

    //these are the protected members of the class.
    //they can *only* be accessed and used from inside the class and from inside subclasses of this class.
protected:
    string location;

    //these are the public members of the class.
    //they can be accessed and used from inside and outside the class.
public:

    //--------------------------------------------------

    //this is a class constructor, which is in charge of initializing the attributes of the class.
    //the constructor is executed everytime one creates an instance of the class.
    Animal(string name, string type);

    //another class constructor
    Animal(string type);

    //class destructor
    ~Animal();

    //--------------------------------------------------

    //this is a static attribute, which means that it has the same value among all instances of the class, once it is initialized
    static string kingdom;

    //a static method can only use/call static members
    static void printKingdom();

    //--------------------------------------------------

    //these two are virtual functions, which are used to implement polymorphism in C++.
    //the "= 0" at the end of the methods indicates that they do not have definition/implementation in this class.
    //this is the main reason why we cannot instantiate this class directly, but through its subclasses.
    //the subclasses must declare and implement these methods, unless they are declared virtual again

    virtual void eat(string &food) = 0;

    virtual void makeNoise() = 0;

    //--------------------------------------------------

    //these are regular methods of the class

    void whereIs();

    void sleep();

    void run();

    //----------------------------------------

    //these are called setters and getters, i.e., methods that allow setting and getting the value of private attributes from outside the class

    const string &getName();

    void setName(const string &name);

    const string &getType();

    void setType(const string &type);

    string *getWikipediaDescription() const;

    void setWikipediaDescription(string *wikipediaDescription);

    const string &getLocation() const;

    void setLocation(const string &location);

};


#endif //CPP_OO_INTRO_ANIMAL_H
