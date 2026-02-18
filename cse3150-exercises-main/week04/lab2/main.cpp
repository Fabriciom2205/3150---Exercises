#include <iostream>
#include <ctime>
#include <iomanip>
#include "WellBalanced.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int n = 5, totalRuns = 10000, balancedCount = 0;
    std::vector<int> sequence(2 * n);
    for (int i = 0; i < n; ++i) sequence[i] = 1;
    for (int i = n; i < 2 * n; ++i) sequence[i] = -1;

    for (int i = 0; i < totalRuns; ++i) {
        fisher_yates(sequence);
        if (isWellBalanced(sequence)) balancedCount++;
    }

    std::cout << "Apparent Ratio: " << std::fixed << std::setprecision(4) << (double)balancedCount / totalRuns << std::endl;
    std::cout << "Total Runs: " << totalRuns << std::endl;
    return 0;
}