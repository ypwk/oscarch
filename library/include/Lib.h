//
// Created by ojcch on 2/12/2021.
//

#ifndef LIBRARY_LIB_H
#define LIBRARY_LIB_H

#include <vector>
using namespace std;

class Lib {
public:
    static void algorithmA(const int& n);
    static void algorithmB(const int& n);
    static void algorithmC(const int& n);

private:
    static int select1(vector<int> nums);
    static void sortDec(vector<int> &vec);
    static void sort(vector<int> &vec);
    static int select2(const vector<int> &nums);
    static void cubic(int n);
};


#endif //LIBRARY_LIB_H
