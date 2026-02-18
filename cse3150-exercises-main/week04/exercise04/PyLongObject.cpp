#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <cmath>

const long long B = 1073741824; 

struct PyLongObject {
    int sign;
    int numDigits;
    bool fitsInLongLong; 
    long long iValue;
    unsigned int* digitsBase30;

    PyLongObject(long long val = 0) {
        sign = (val >= 0) ? 1 : -1;
        iValue = std::abs(val);
        fitsInLongLong = true;
        numDigits = 0;
        digitsBase30 = nullptr;
    }

    PyLongObject(const PyLongObject& other) {
        sign = other.sign;
        numDigits = other.numDigits;
        fitsInLongLong = other.fitsInLongLong;
        iValue = other.iValue;

        if (other.digitsBase30 != nullptr) {
            digitsBase30 = new unsigned int[other.numDigits];
            for (int i = 0; i < other.numDigits; i++) {
                digitsBase30[i] = other.digitsBase30[i];
            }
        } else {
            digitsBase30 = nullptr;
        }
    }

    ~PyLongObject() {
        delete[] digitsBase30;
    }

    PyLongObject operator+(const PyLongObject& other) const {
        if (this->fitsInLongLong && other.fitsInLongLong) {
            return PyLongObject((this->sign * this->iValue) + (other.sign * other.iValue));
        }
        return PyLongObject(0); 
    }

    bool operator==(const PyLongObject& other) const {
        // Correct check: Compare memory addresses first to avoid "Yipes!" recursion
        if (this == &other) return true; 

        if (fitsInLongLong && other.fitsInLongLong) {
            return (sign == other.sign && iValue == other.iValue);
        }
        return false; 
    }
};

TEST_CASE("Testing PyLongObject") {
    PyLongObject a(500);
    PyLongObject b(200);

    SUBCASE("Constructor and Value checks") {
        CHECK(a.iValue == 500);
        CHECK(a.sign == 1);
    }

    SUBCASE("Copy Constructor") {
        PyLongObject copy_a = a;
        CHECK(copy_a.iValue == a.iValue);
        CHECK(copy_a == a);
    }

    SUBCASE("Addition Logic") {
        PyLongObject sum = a + b;
        CHECK(sum.iValue == 700);
    }
}