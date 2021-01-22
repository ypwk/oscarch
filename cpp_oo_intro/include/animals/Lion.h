
#ifndef CPP_OO_INTRO_LION_H
#define CPP_OO_INTRO_LION_H

#include "animals/Animal.h"

/*
 * Class Lion, which inherits from Animal (i.e., a Lion is an Animal)
 */
class Lion:public Animal {
public:

    Lion(string name, string type);

    Lion(string type);

    //----------------------------
    //the virtual methods from the superclass will be implemented here in the subclass

    void eat(string &food);

    void makeNoise();

private:

    //helper method, which is private
    void roar();
};


#endif //CPP_OO_INTRO_LION_H
