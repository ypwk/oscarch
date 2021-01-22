//
// Created by ojcch on 1/21/2021.
//

#ifndef CPP_OO_INTRO_PENGUIN_H
#define CPP_OO_INTRO_PENGUIN_H


#include "Bird.h"

/*
 * Class Penguin, which inherits from Bird (i.e., a Penguin is a Bird)
 */
class Penguin: public Bird {
public:
    explicit Penguin(string name);
    //----------------------------
    //the virtual methods from the superclass will be implemented here in the subclass
    void eat(string &food) ;
    void makeNoise();
};


#endif //CPP_OO_INTRO_PENGUIN_H
