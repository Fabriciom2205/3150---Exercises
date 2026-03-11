#ifndef COMPLEXARRAY_H
#define COMPLEXARRAY_H

#include "Complex.h"

class ComplexArray {
private:
    Complex* data;
    int size;

public:
    ComplexArray(int s);
    ~ComplexArray();

    ComplexArray(const ComplexArray& other) = delete;
    ComplexArray& operator=(const ComplexArray& other) = delete;

    ComplexArray(ComplexArray&& other) noexcept;
    ComplexArray& operator=(ComplexArray&& other) noexcept;

    int getSize() const { return size; }
    Complex& operator[](int index) { return data[index]; }
};

#endif