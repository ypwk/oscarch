
#include <iostream>
#include <chrono>
#include <cmath>
#include "Lib.h"


using namespace std;
using namespace std::chrono;

int main() {

    char separator = ',';

    cout << "n" << separator << "TA(n)" << separator << "TB(n)" << separator << "TC(n)" << separator << "log(n)"
         << separator << "log(TA)" << separator << "log(TB)" << separator << "log(TC)" << endl;


    auto startOverall = steady_clock::now();

    int nIni = 100, nEnd = 3000, nStep = 100;
    for (auto n = nIni; n <= nEnd; n += nStep) {

        auto start = steady_clock::now();
        Lib::algorithmA(n);
        auto end = steady_clock::now();
        auto timeA = duration_cast<milliseconds>(end - start).count();

        start = steady_clock::now();
        Lib::algorithmB(n);
        end = steady_clock::now();
        auto timeB = duration_cast<milliseconds>(end - start).count();


        start = steady_clock::now();
        Lib::algorithmC(n);
        end = steady_clock::now();
        auto timeC = duration_cast<milliseconds>(end - start).count();

        float logN = log2(n);
        float logA = log2(timeA);
        float logB = log2(timeB);
        float logC = log2(timeC);

        cout << n << separator << timeA << separator << timeB << separator << timeC << separator << logN << separator
             << logA << separator << logB << separator << logC << endl;
    }

    auto endOverall = steady_clock::now();
    auto totalTime = duration_cast<minutes>(endOverall - startOverall).count();

    cout << "Time elapsed: " << totalTime << " mins" << endl;

    return 0;
}