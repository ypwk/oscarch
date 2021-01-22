//This program illustrates the main object-oriented features of the C++ programming language:
//* classes, attributes, and methods
//* encapsulation
//* constructors and destructors
//* static attributes and methods
//* inheritance
//* runtime polymorphism (abstract vs concrete classes)

//including other code
#include <iostream>
#include <animals/Giraffe.h>
#include <animals/birds/Bird.h>
#include <animals/birds/Penguin.h>
#include "animals/Lion.h"

//including a namespace
using namespace std;

//the entry point of the program.
//argc and argv parameters of the main function hold the arguments of the program, given in the command line:
// argc is the number of arguments, and argv is the array of strings for the arguments
int main(int argc, char *argv[]) {

    //this illustrates how to check for the program arguments
    if (argc > 1) {
        cout << "Program arguments were provided:" << endl;
        cout << "The 1st element is always the executable file: " << string(argv[0]) << endl;
        cout << "The 2nd element is the 1st program argument: " << string(argv[1]) << endl;
    } else
        cout << "No program arguments were provided:" << endl;

    cout << "---------------------------" << endl;

    //abstract classes must be initialized with instances of their subclasses that are not abstract
    // (i.e., concrete classes), and the variables should be pointers (in order to achieve polymorphic behavior)
    Animal *alex = new Lion("Alex", "feline");

    string *description = nullptr; //this is how null pointers are initialized
    description = new string(
            "Alex the lion, enjoys showing off for the public and his celebrity status as \"the king of New York\"...");
    //when instances of classes are pointers, methods and attributes of the class are accessed through -> rather than .
    alex->setWikipediaDescription(description);
    alex->setLocation("Africa");


    //notice that the virtual methods of Animal are being called here (i.e., eat and makeNoise), but
    // during the execution, the program actually calls the methods of the subclass, depending on the instance type (in this case a Lion)
    alex->whereIs();
    alex->makeNoise();
    string food = "a buffalo";
    alex->eat(food);
    alex->sleep();
    cout << *alex->getWikipediaDescription() << endl;

    cout << "---------------------------" << endl;

    //a concrete class can be instantiated without a pointer.
    //notice how at the termination of the program, the destructor of the Animal class is called, because this variable
    //is deallocated from the Stack when the program ends.
    Lion simba("simba");

    //--------------------------------

    //another polymorphic instantiation of an Animal (i.e, a Giraffe)
    Animal *melman = new Giraffe("Melman");
    melman->setWikipediaDescription(
            new string("Melman, a hypochondriac reticulated giraffe who is afraid of germs..."));


    melman->whereIs();
    melman->makeNoise();
    string food2 = "grass";
    melman->eat(food2);
    melman->sleep();
    cout << *melman->getWikipediaDescription() << endl;

    cout << "---------------------------" << endl;


    //a polymorphic instantiation of a Bird (i.e, a Penguin)
    Bird *skipper = new Penguin("Skipper");
    skipper->setWikipediaDescription(
            new string("Skipper, the leader of the penguins..."));


    skipper->whereIs();
    skipper->makeNoise();
    string food3 = "a squid";
    skipper->eat(food3);
    skipper->sleep();
    cout << *skipper->getWikipediaDescription() << endl;

    cout << "---------------------------" << endl;

    //notice here that this is an array of Animals, which contains a Lion, Giraffe, and a Bird (a Penguin).
    //all of these are Animals.
    Animal *madagascarCharacters[3] = {alex, melman, skipper};

    //this loop illustrates runtime polymorphism again.
    //the particular makeNoise is called depending on the type of the instance (i.e., a Lion, Giraffe, or Penguin)
    for (Animal *animal: madagascarCharacters) {
        animal->makeNoise();
    }

    cout << "---------------------------" << endl;

    //this illustrates how to access the static members from Animal.
    //notice that the kingdom is the same for all animals.
    cout << "All animals share the same kingdom: " << Animal::kingdom << " == " << skipper->kingdom << " == "
         << melman->kingdom
         << endl;
    Bird::printKingdom();

    cout << "---------------------------" << endl;

    //this part illustrates how to call the destructor of the Animal class, which happens when memory is deallocated.
    //failing to delete the pointers may cause memory leaks
    for (auto &animal: madagascarCharacters)
        delete animal;


    cout << "Done!" << endl;

    return 0;
}
