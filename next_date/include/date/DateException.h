//
// Created by ojcch on 2/18/2021.
//

#ifndef NEXTDATE_DATEEXCEPTION_H
#define NEXTDATE_DATEEXCEPTION_H

#include <iostream>

using namespace std;

class DateException: public exception {
private:
    //this is just the exception message
    std::string message;
public:
    explicit DateException(string message) {
        this->message = message;
    }

    //the method what is a virtual method from the superclass that can be overridden here in the subclass
    virtual const char *what() const throw() {
        return message.c_str();
    }
};


#endif
