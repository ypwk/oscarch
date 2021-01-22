//
// Created by ojcch on 1/21/2021.
//

#ifndef CPP_OO_INTRO_GIRAFFE_H
#define CPP_OO_INTRO_GIRAFFE_H

#include "animals/Animal.h"

/*
 * Class Giraffe, which inherits from Animal (i.e., a Giraffe is an Animal)
 */
class Giraffe : public Animal {

public:
    explicit Giraffe(string name);

    //this method is overridden from the method of the superclass, but because it is not virtual, it does not implement polymorphism
    void sleep();

    //----------------------------
    //the virtual methods from the superclass will be implemented here in the subclass
    void eat(string &food);

    void makeNoise();

};


#endif //CPP_OO_INTRO_GIRAFFE_H
