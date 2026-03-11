#include "ComplexArray.h"
#include <iostream>

ComplexArray::ComplexArray(int s) : size(s) {
    if (size > 0) {
        data = new Complex[size];
    } else {
        data = nullptr;
    }
}

ComplexArray::~ComplexArray() {
    delete[] data;
}

ComplexArray::ComplexArray(ComplexArray&& other) noexcept 
    : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

ComplexArray& ComplexArray::operator=(ComplexArray&& other) noexcept {
    if (this != &other) {
        delete[] data;
        
        data = other.data;
        size = other.size;
        
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}