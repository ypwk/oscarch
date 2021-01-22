//including other code
#include <iostream>
#include "utilities/math/MathUtilities.h"

//including a namespace
using namespace std;

//the entry point of the program
int main() {

    //integer variables
    int n = 10, sum = 0;

    //for loop that sums the first n integers
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    //printing the result
    cout << "Sum = " << sum << endl;

    //compute the average
    float avg = MathUtilities().average(sum, n);
    cout << "Avg = " << avg << endl;

    return 0;
}
