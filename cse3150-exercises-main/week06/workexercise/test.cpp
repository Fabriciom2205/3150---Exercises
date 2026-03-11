#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ComplexArray.h"

TEST_CASE("Edge Case: Zero Size") {
    ComplexArray empty(0);
    CHECK(empty.getSize() == 0);
}

TEST_CASE("Edge Case: Self-Assignment") {
    ComplexArray a(5);
    a = std::move(a);
    CHECK(a.getSize() == 5);
}

TEST_CASE("Move Logic") {
    ComplexArray a(10);
    ComplexArray b = std::move(a);
    CHECK(b.getSize() == 10);
    CHECK(a.getSize() == 0);
}