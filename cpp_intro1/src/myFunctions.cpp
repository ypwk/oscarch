//
// functions implemented in another file
//

int function1() {
    return 0; //never forget to return a value! the compiler does not detect the error in some cases!
}

void function4() {

}

int function3(bool result, float number) {
    return result + number; //result gets converted into an integer: 1 if it is true, otherwise to 0
}

int function2(int i) {
    return i * 2;
}
