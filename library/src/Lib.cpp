//
// Created by ojcch on 2/12/2021.
//

#include "../Lib.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>



void Lib::sort(vector<int> &vec) { // bubble sort ascending
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (auto i = 1; i < vec.size(); i++) {
            if (vec[i - 1] > vec[i]) {
                swap(vec[i], vec[i - 1]);
                sorted = false;
            }
        }
    }
}

void Lib::sortDec(vector<int> &vec) { // bubble sort descending
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (auto i = 1; i < vec.size(); i++) {
            if (vec[i - 1] < vec[i]) {
                swap(vec[i], vec[i - 1]);
                sorted = false;
            }
        }
    }
}

int Lib::select1(vector<int> nums) {
    int k = (nums.size() + 1) / 2;
    Lib::sort(nums);
    return nums[k];
}

int Lib::select2(const vector<int> &nums) {
    int k = nums.size() / 2;
    vector<int> topK(nums.begin(), nums.begin() + k);

    Lib::sortDec(topK);
    for (auto i = k; i < nums.size(); i++) {
        if (nums[i] > topK[k - 1]) {
            for (auto j = k - 2; j >= 0; j--)
                if (nums[i] < topK[j]) {
                    topK[j + 1] = nums[i];
                    break;
                }
                else
                    topK[j + 1] = topK[j];
            if (topK[0] < nums[i])
                topK[0] = nums[i];
        }
    }
    return topK[k - 1];
}

void Lib::cubic(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                sum++;
            }
        }
    }
}


void Lib::algorithmA(const int &n) {
    vector<int> nums(n);
    int selected;

    srand(time(nullptr));

    // run 10 times
    for (auto i = 0; i < 10; i++) {
        for (auto j = 0; j < n; j++)
            nums[j] = rand() % (2 * n);
        selected = Lib::select1(nums);
    }
}


void Lib::algorithmB(const int &n) {
    vector<int> nums(n);
    int selected;

    srand(time(nullptr));

    // run 10 times
    for (auto i = 0; i < 10; i++) {
        for (auto j = 0; j < n; j++)
            nums[j] = rand() % (2 * n);
        selected = Lib::select2(nums);
    }
}

void Lib::algorithmC(const int &n) {
    Lib::cubic(n);
}
