#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include "WellBalanced.h"

void fisher_yates(std::vector<int>& arr) {
    for (int i = arr.size() - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}

bool isWellBalanced(const std::vector<int>& arr) {
    int currentSum = 0;
    for (int x : arr) {
        currentSum += x;
        if (currentSum < 0) {
            return false;
        }
    }
    return currentSum == 0;
}
