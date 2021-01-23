//
// Created by ojcch on 1/22/2021.
//

#ifndef CPP_OO_INTRO_FOODEXCEPTION_H
#define CPP_OO_INTRO_FOODEXCEPTION_H

#include <exception>
#include <string>

/*
 * This is a simple programmer-defined exception class, which inherits from the exception class (C+ std. lib).
 *
 */
class FoodException : public std::exception {
private:
    //this is just the exception message
    std::string message;
public:
    explicit FoodException(string message) {
        this->message = message;
    }

    //the method what is a virtual method from the superclass that can be overridden here in the subclass
    virtual const char *what() const throw() {
        return message.c_str();
    }
};


#endif //CPP_OO_INTRO_FOODEXCEPTION_H
