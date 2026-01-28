#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 

#include "../include/doctest.h" 
#include "isPrimeFunction.h"

TEST_CASE("Negative numbers aren't prime") { 
    CHECK_FALSE(isPrimeInteger(-5));   
    CHECK_FALSE(isPrimeInteger(-1));   
    CHECK_FALSE(isPrimeInteger(-100));   
}

TEST_CASE("Zero and one are not prime") { 
    CHECK_FALSE(isPrimeInteger(0));   
    CHECK_FALSE(isPrimeInteger(1));   
}

TEST_CASE("Two is prime") { 
    CHECK(isPrimeInteger(2));   
}

TEST_CASE("Even numbers are not prime") { 
    CHECK_FALSE(isPrimeInteger(4));   
    CHECK_FALSE(isPrimeInteger(6));   
    CHECK_FALSE(isPrimeInteger(8));   
    CHECK_FALSE(isPrimeInteger(10));   
}

TEST_CASE("Larger prime numbers") {    
    CHECK(isPrimeInteger(47));   
    CHECK(isPrimeInteger(97));   
    CHECK(isPrimeInteger(101));   
}
