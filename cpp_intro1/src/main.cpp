//This program illustrates the main features of the C++ programming language.
//This program does not cover the object-oriented features of C++.


// this is a one-line comment

/*
This is a multi-line comment

 int main(){return 0;}
 */


/*
 * This is a another multi-line comment
 * see?
 */

#include <iostream> //include statement for shared libraries (e.g., C++ Standard Library)
//#include "myFunctions.cpp" // include statement for our own code (bad practice to include .cpp, we usually include .h files)
#include "myFunctions.h"


/************************************/
//function declarations (these are the signatures of the functions)
void arithmeticOperations();

void booleanComparisons();

void functionCalls();

void branchStatements();

void variablesAndTypes();

void singleDimensionArrays();

void loops();

void multidimensionalArrays();

void pointers();

void dynamicMemoryAllocation();

void printArrayOfIntegers(const int arraySize, const int *myArray);

void printArrayOfDoubles(int arraySize, double *array);

void inputAndOutput();

void typeModifiers();

void assignmentOperations();

void operatorPrecedence();

void references();

void functionPassByReference(int &integer);

int &functionThatReturnsAReference();
/************************************/


/************************************/
//namespace declaration

namespace csci303 {
    int integer3 = 10;
}

namespace csci311 {
    int integer3 = 10;
}

/************************************/

//using namespaces (so we can write 'integer3' in our code, rather than csci303::integer3)
using namespace csci303;
using namespace std; //this namespace is defined in the C++ standard library


//the main function is entry point of the program
int main() {

    //statements in C++ end with a semicolon: ;
    //blank spaces and comments in C++ are ignored by the compiler.
    //hence, we can have multiple statements in one line like this:
    //int a = 1; cout<<a<<endl; a = 123 * 23; cout<<a<<endl;

    //the functions below illustrate different types of elements of the C++ programming language
    //check these functions in order, from top to bottom

    inputAndOutput();

    variablesAndTypes();

    typeModifiers();

    arithmeticOperations();

    booleanComparisons();

    assignmentOperations();

    operatorPrecedence();

    functionCalls();

    branchStatements();

    singleDimensionArrays();

    loops();

    multidimensionalArrays();

    pointers();

    references();

    dynamicMemoryAllocation();

    //0 means the program terminated correctly.
    // Another value means an unexpected termination.
    return 0;
}

void inputAndOutput() {

    //this is a block with its own scope
    {
        float number;

        //print something in the terminal
        cout << "Hi, this is a test, give me an integer:" << endl;

        //ask for input from the user
        std::cin >> number;

        cout << "This is the number:" << number << endl;

    }

    //I can't use number because it is not declared in this scope, but in a different one (as shown above).
    //the compiler will detect the error for you.
    //number = 8 ;
}

void variablesAndTypes() {

    //all variables in C++ must be declared, i.e., they should have a type and a name.

    //while it is not mandatory to initialize the variables, it is **extremely** recommended to do so,
    //otherwise, this will likely lead to errors and bugs during the execution of the program.
    //if the variables are not initialized, they may contain rubbish values that would lead to program misbehavior.

    //this is a variable declaration, with no initialization
    int iAmAVariable;

    cout << iAmAVariable << endl;

    //this is a variable declaration and the variable is initialized with a value
    int integer2 = 10;

    //variables and types
    int integer = 45;
    short int smallerInteger = 56; //an integer of 2 bytes rather than 4 bytes
    bool boolean = true;
    bool boolean2 = false;
    float number = 45.64546;
    double morePreciseNumber = 45.5645645644564545;
    char character = 't';
    char aString[30] = "This is a string";
    string anotherString = "This is another string";

    //auto can be any type, however, auto variables must be initialized when declared.
    //the actual type is inferred by the compiler based on the initialization value
    auto anotherNumber = 12.56;

    //however, once the type is inferred, a variable can only hold values of that type during the whole program execution.
    //attempting to set values of another type will lead to compilation errors.
    //for example, this is not valid:
    //anotherNumber = anotherString;

    //this is a constant
    const int constant1 = 10;
    //not valid:
    //constant1 = 20;

    //variable assignment
    integer = integer3;
}

void typeModifiers() {

    //the primitive types char, int, float, and double can use the modifiers: signed, unsigned, short, and long.
    //the modifiers are used to put constraints on the value range of the variables.

    char character = 'a'; //1 byte ; //-127 to 127 or 0 to 255
    unsigned char character2 = 'b'; //1 byte ; //0 to 255
    signed char character3 = 123; //1 byte ; //-127 to 127

    cout << character3 << endl; //it will print the character corresponding to the ascii 123: {

    //here it is shown how the modifiers are used and the respective amount of memory space the variable use as well as
    //the value range of each variable

    int integer1 = 2147483647; //4 bytes ; //-2147483648 to 2147483647
    unsigned int integer2 = 4294967295; //4 bytes ; //0 to 4294967295
    signed int integer3 = -2147483647; //4 bytes ; //-2147483648 to 2147483647
    short int integer4 = -32768; //2 bytes ; //-32768 to 32767
    unsigned short int integer5; //2 bytes ; //0 to 65,535
    signed short int integer6 = 32767; //2 bytes ; //-32768 to 32767
    long int integer7 = 2147483647; //8 bytes ; //-2,147,483,648 to 2,147,483,647
    signed long int integer8 = 2147483647; //8 bytes ; //same as long int
    unsigned long int integer9 = 4294967295; //8 bytes ; //0 to 4,294,967,295
    long long int integer10 = -9223372036854775807; //8 bytes ; //-(2^63) to (2^63)-1
    unsigned long long int integer11 = 1844674407370955161; //8 bytes ; //0 to 18,446,744,073,709,551,615

    cout << integer10 << endl;
    cout << integer11 << endl;


    float floatNumber = 4.45; //4 bytes ; //
    double doubleNumber = 3.40282347E+38; //8 bytes ; //
    long double doubleNumber2 = 1.79769313486231570E+308; //12 bytes ; //

    cout << floatNumber << endl;
    cout << doubleNumber << endl;
    cout << doubleNumber2 << endl;

    wchar_t wideChar = L'a'; //2 or 4  bytes ; //1 wide character
}

void arithmeticOperations() {
    int integer2 = 10, integer = 5;
    float number = 45.4;

    //arithmetic operations
    float number2 = integer - number;
    number2 = integer * number;
    number2 = integer / number;
    number2 = integer % integer2; //MODULO operation
    number2 = integer++; //integer is increment by 1 and then assigned to number2
    number2 = integer--; //integer is decremented by 1 and then assigned to number2
    number2 = -integer; //changing to the negative integer
    number2 = +integer; //changing to the positive integer
}

void booleanComparisons() {
    bool boolean = true;
    bool boolean2 = false;

    int integer2 = 10, integer = 5;

    //comparisons
    bool result = integer == integer2; //equals to
    result = integer != integer2; //different than
    result = integer < integer2;
    result = integer <= integer2; //less than or equals to
    result = integer > integer2;
    result = integer >= integer2; //greater than or equals to
    result = boolean && boolean2; //AND
    result = boolean || boolean2; //OR

    result = !result; //negation (not a comparison but a boolean operation)
}

void assignmentOperations() {

    int a = 2, b = 3;
    a += b; //a = a + b
    a -= b; //a = a - b
    a *= b; //a = a * b
    a /= b; //a = a / b
    a %= b; //a = a % b

}

void operatorPrecedence() {

    //operators have an order of evaluation/execution, which is defined by the C++ language specification.
    //the compiler will follow that order when parsing and compiling the code.
    //however, we can use parentheses to group expressions and explicitly define the order of evaluation/execution ourselves.

    int a = 2, b = 3, c = 6, result1 = 0, result2 = 0;

    //arithmetic operators.
    //operator precedence here is: * is first evaluated, then /, and then +
    result1 = a * b / c + a;
    result2 = ((a * b) / c) + a;

    //both result variables will have the same result.
    //the parentheses illustrate the order of execution of the expressions.
    cout << "Result1 is: " << result1 << endl;
    cout << "Result2 is: " << result2 << endl;

    //this is a different order of the operators. However, the operator precedence is honored: first  *, then /, and then +
    result1 = a / c * b + a;
    result2 = (a / (c * b)) + a;

    cout << "Result1 is: " << result1 << endl;
    cout << "Result2 is: " << result2 << endl;

    //logical/conditional operators

    bool d = true, e = false, f = true, result3 = false, result4 = false;

    //operator precedence in this case is: ==, then &&, and then ||
    //once again, the parentheses illustrate the order of execution of the expressions
    result3 = d || e && f == d && e || f;
    result4 = (d || (e && f)) == ((d && e) || f);

    //both result variables will have the same result
    cout << "Result3 is: " << result3 << endl;
    cout << "Result4 is: " << result4 << endl;

}

void functionCalls() {
    bool result = true;
    float number = 45.4;

    //function calls
    int integer = function1(); //calling a function with no parameters and a return
    integer = function2(12);
    integer = function3(result, number); //multiple parameters
    function4(); //a function that does not return anything (it is void)

    cout << "The result is: " << integer << endl;
}

void branchStatements() {
    //branching statements in C++ are if-else and switch statements

    //this is an if-else statement without braces, which can have only one statement inside the if or else branches
    int integer2 = 11;
    if (integer2 > 0)
        cout << "integer2 > 0" << endl;
        //cout << "bla bla"; //This is incorrect, sometimes the error is detected by the compiler, sometimes it is not
    else
        cout << "integer2 <= 0" << endl;

    //this is an if-else with braces, which can have multiple statements inside the branches
    if (integer2 > 0) {
        cout << "integer2 > 0" << endl;
        cout << "This is correct, I can have multiple statements here";
    } else {
        cout << "integer2 <= 0" << endl;
    }
    cout << endl;

    //this is if without an else
    if (integer2 > 0)
        cout << "integer2 > 0" << endl;

    cout << integer2 << endl;

    //this is a switch statement, which has multiple branches.
    //the execution of the program "jumps" to a case statement if the variable used in the switch is equals to the value of the case
    switch (integer2) {
        case 11: {
            cout << "integer2 is 11" << endl;
            cout << "Yay!" << endl;
            break; //the break statements must be used, otherwise, the next case statements will execute as well
        }
        case 1:
            cout << "integer2 is 1" << endl;
            break;
        case 2:
            cout << "integer2 is 2" << endl;
            break;
        case 3:
            cout << "integer2 is 3" << endl;
            break;
            //this is the "else" of the switch statement
        default:
            cout << "This is the default case" << endl;
            break;
    }

    //this is an if-else statement with multiple branches as well
    if (integer2 == 11) {
        cout << "integer2 is 11" << endl;
        cout << "Yay!" << endl;
    } else if (integer2 == 1) {
        cout << "integer2 is 1" << endl;
    } else if (integer2 == 2) {
        cout << "integer2 is 2" << endl;
    }
        //..
    else {
        cout << "This is the default case" << endl;
    }
}

void singleDimensionArrays() {

    //arrays are variables that hold contiguous values in memory.

    //the indices of the elements of arrays in C++ start with 0,
    // i.e., 0 is used to access the first element, 1 for the 2nd element, 2 for the 3rd, etc.

    int arrayOfIntegers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float arrayOfFloats[10] = {0.0};

    //printing an element
    cout << "arrayOfIntegers[0] is " << arrayOfIntegers[0] << endl;

    //setting an element
    arrayOfIntegers[0] = 20;
}

void loops() {

    //loops in C++.
    //there are four types of loop in C++: the 'for' loop, the 'while' loop, the 'do-while' loop, and the 'range-based for' loop

    //a for loop has the following syntax:
    //     for (initializer; condition; update){
    //         ....
    //     }
    // where initializer is an (optional) expression that initializes a variable (typically a counter),
    // the condition is an (optional) boolean expression that makes the loop to execute its internal code while the condition evaluates to true,
    // and the update is an (optional) arithmetic expression that increments or decrements the variable used in the initializer

    //this is a for loop with only the condition.
    //the for loop is executed until counter < 20 is false (i.e., it executes while counter < 20  is true)
    int counter = 10;
    for (/*initialization*/; counter < 20;/*update*/) {
        cout << "counter is " << counter << endl;
        counter++;
    }

    cout << "--------------------" << endl;

    //this a for loop with the condition and update statements
    counter = 10;
    for (/*initialization*/; counter < 20; counter++) {
        cout << "counter is " << counter << endl;
    }

    cout << "--------------------" << endl;

    //for loop with the initializer, condition, and update statements.
    //it prints an array in the format: [i1, i2, ...]
    int arrayOfIntegers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "arrayOfIntegers is [";
    for (int counter2 = 0; counter2 < 9; counter2++) {
        cout << arrayOfIntegers[counter2] << ", ";
    }
    cout << arrayOfIntegers[9] << "]" << endl;


    cout << "--------------------" << endl;

    //this is a while loop, which only has the condition
    counter = 10;
    while (counter < 20) {
        cout << "counter is " << counter << endl;
        counter++;
    }


    cout << "--------------------" << endl;

    //this is a do-while loop, which also has the condition only
    counter = 10;
    do {
        cout << "counter is " << counter << endl;
        counter++;
    } while (counter < 20);

    cout << "--------------------" << endl;

    //this is a range-based for loop, which is used to iterate arrays, vectors, and other objects that can be iterated
    for (const auto item : arrayOfIntegers) {
        cout << item << ", ";
    }

    cout << endl;

}

void multidimensionalArrays() {

    //we can define and use multidimensional arrays in C++, also known as matrices

    //multi dimensional arrays
    int matrix1[4][5] = {0}; //initialize all elements to zero

    // setting the elements of the matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            matrix1[i][j] = (i + 1) * (j + 1);
        }
    }

    cout << "--------------------" << endl;

    //printing the elements with a regular for loop
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix1[i][j] << ", ";
        }
        cout << endl;
    }

    cout << "--------------------" << endl;

    //printing the elements with a range-based for loop
    for (auto &i : matrix1) {
        for (int j : i) {
            cout << j << ", ";
        }
        cout << endl;
    }

}

void pointers() {

    //pointers are variables that hold the memory addresses of other variables.
    //they are useful to reference variables in the heap, and
    //to avoid having copies/duplicates of the variables whenever there are function calls.

    cout << "---------------------------" << endl;

    float number = 1003.45; //a regular local variable
    float *pointer = &number; //& gets the memory address of number, and it is stored in a pointer variable
    cout << "Memory address of number: " << pointer << endl;

    float number2 = *pointer; //here * obtains the value stored in the memory address, and it is assigned to number2
    cout << "Number2: " << number2 << endl;

    *pointer = 100.1;
    cout << "Value pointed by pointer is now: " << *pointer << endl;
    cout << "Number2 is still: " << number2 << endl;

    //arrays are related to pointers as seen here:
    const int arraySize = 10;
    int myArray[arraySize] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *myArrayPointer = myArray; //typically, array names decay into pointers (there are exceptions, though)

    //we can do pointer arithmetic to access the elements of the array, as follows:
    int secondElement = *(myArrayPointer + 1); //accessing the second element of the array
    cout << "secondElement: " << secondElement << endl;
    cout << "Memory address of the second element: " << myArrayPointer + 2 << " vs. " << &myArray[2] << endl;

    *(myArrayPointer + 1) = 45; //changing the 2nd element through the pointer
    cout << "secondElement: " << myArray[1] << endl;

    //printing the array
    cout << "arraySize is ";
    printArrayOfIntegers(arraySize, myArray);

    //we can have pointers of pointers (after all, pointers are also variables in memory)
    int **pointerToPointer = &myArrayPointer;
    cout << "Memory address of myArrayPointer: " << pointerToPointer << endl;

}

void printArrayOfIntegers(const int arraySize, const int *myArray) {
    //this function prints an array of inters in the format: [i1, i2, ..., in]
    cout << "[";
    for (int counter2 = 0; counter2 < arraySize - 1; counter2++) {
        cout << myArray[counter2] << ", ";
    }
    cout << myArray[arraySize - 1] << "]" << endl;
}

void references() {
    //there are variables that are called references.
    //we declare them by using & right after the variable type

    //references act as aliases of other variables.
    //the main use of references is when passing variables to functions, in order to reduce memory consumption,
    //by avoiding making copies of the variables at each function call

    //references and pointers are similar (they store memory addresses of other variables)

    int integer = 23;
    int &refToInteger = integer;

    cout << "integer and refToInteger are: " << integer << " and " << refToInteger << endl;

    refToInteger = 45;
    cout << "integer and refToInteger are: " << integer << " and " << refToInteger << endl;

    //I can't do this, because a reference has to be declared and initialized at the same time
    //int &refToInteger2;

    //passing a regular variable "by reference"
    functionPassByReference(integer);
    cout << "integer was modified by the function: " << integer << endl;

    int &ref2 = functionThatReturnsAReference();
    //attempting to use the reference here will lead to a program crash
    //cout << "ref2 is " << ref2 << endl;

}

int &functionThatReturnsAReference() {
    //we can return references in a function, but...
    //you should not return a reference of a local variable because once the function returns,
    //the variable is destroyed (i.e., deallocated from the memory Stack),
    //and attempting to use the reference somewhere else will lead to a program crash.
    int variable = 24;
    return variable;
}

void functionPassByReference(int &integer) {
    //modifying a reference (i.e., setting a value) here will modify the variable of the original variable.
    //a reference variable is set as a regular variable (with the operator =).
    integer = 67;
}

void dynamicMemoryAllocation() {

    //pointers and the "new" operator are used to allocate memory dynamically in the Heap.
    //the "delete" operator is used to deallocate variables from the Heap.

    int *pointer = new int(2); //new creates the integer 2 in the heap, rather than in the stack
    int *pointer2 = new int[10]; //allocates 10 contiguous integers in the heap (this is an array!)
    delete pointer; //memory is released

    //if you forget to delete local variables in this function, then you will create a memory leak
    //memory leaks happen when variables are never deallocated, and they are not used anymore in the program

    //while the following compiles, it is incorrect, because we reference a memory space that is deallocated.
    //in some cases, this will crash the program:
    //int number2 = *pointer;
    //cout << number2<< endl;

    *(pointer2 + 4) = -23; //set the 5th element as -23
    pointer2[3] = 23; //set the 4th element as 23
    printArrayOfIntegers(10, pointer2);//print array
    delete[] pointer2; //free up memory

    //initializing a multi-dimensional array with zeros, in the heap, and with pointers, rather than with [][]
    double **matrix = new double *[4];
    for (int i = 0; i < 4; i++) {
        matrix[i] = new double[5];
        for (int j = 0; j < 5; j++)
            matrix[i][j] = 0.0;
    }

    //print the matrix
    for (int i = 0; i < 4; i++)
        printArrayOfDoubles(5, matrix[i]);

    //free up memory
    for (int i = 0; i < 4; i++)
        delete[] matrix[i];
    delete[] matrix;

}

void printArrayOfDoubles(int arraySize, double *myArray) {
    //this function prints an array of doubles in the format: [d1, d2, ..., dn]
    cout << "[";
    for (int counter2 = 0; counter2 < arraySize - 1; counter2++) {
        cout << myArray[counter2] << ", ";
    }
    cout << myArray[arraySize - 1] << "]" << endl;
}