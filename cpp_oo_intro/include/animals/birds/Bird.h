//
// Created by ojcch on 1/21/2021.
//

#ifndef CPP_OO_INTRO_BIRD_H
#define CPP_OO_INTRO_BIRD_H


#include "animals/Animal.h"

/*
 * Bird, another abstract class, which inherits from Animal (i.e., a Bird is an Animal)
 */
class Bird: public Animal {

public:
    explicit Bird(string name);
    //the virtual methods from the class are overridden without an implementation in this class, this is what makes Bird an abstract class too.
    //we could have used "virtual", but "override" can be used as well.
    void eat(string &food) override = 0 ;
    void makeNoise() override = 0;

};


#endif //CPP_OO_INTRO_BIRD_H
