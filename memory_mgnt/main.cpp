#include <iostream>

int globalVar = 1;

bool doSomething(int var2, int &var4, const float *pnt2) {
    int var3 = 5 + var2 + globalVar + *pnt2 + var4;
    auto *pointer3 = new std::string("Hi");
    var4 = 20;
    std::cout << "var3 is " << var3 << std::endl;

    delete pointer3;

    return false;
}

int main() {

    int var1 = 10;
    auto *pnt1 = new float(10);

    bool result = doSomething(var1, var1, pnt1);
    std::cout << "result is " << result << std::endl;
    std::cout << "var1 is " << var1 << std::endl;
    delete pnt1;

    return 0;
}
