#include <iostream>
#include <utility>
#include "ComplexArray.h"

int main() {
    int count;
    std::cout << "How many ComplexNumbers will be entered? ";
    std::cin >> count;

    ComplexArray arr1(count);
    for (int i = 0; i < count; ++i) {
        double r, im;
        std::cout << "Enter real and imaginary numbers " << i + 1 << ": ";
        std::cin >> r >> im;
        arr1[i].setReal(r);
        arr1[i].setImag(im);
    }

    std::cout << "\nMove Constructor\n";
    ComplexArray arr2 = std::move(arr1); 
    std::cout << "arr2 size: " << arr2.getSize() << ", arr1 size after move: " << arr1.getSize() << "\n";

    std::cout << "\nMove Assignment\n";
    ComplexArray arr3(0);
    arr3 = std::move(arr2);
    std::cout << "arr3 size: " << arr3.getSize() << ", arr2 size after move: " << arr2.getSize() << "\n";

    return 0;
}