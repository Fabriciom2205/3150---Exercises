#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "WellBalanced.h"

TEST_CASE("Testing Balanced List Logic (Lab 2)") {
    SUBCASE("Valid Sequences") {
        CHECK(isWellBalanced({1, -1, 1, -1}) == true);
        CHECK(isWellBalanced({1, 1, -1, -1}) == true);
        CHECK(isWellBalanced({1, 1, 1, -1, -1, -1}) == true);
    }

    SUBCASE("Invalid Sequences") {
        CHECK(isWellBalanced({-1, 1, 1, -1}) == false); 
        CHECK(isWellBalanced({1, -1, -1, 1}) == false);
    }

    SUBCASE("Invalid Sequences") {
        CHECK(isWellBalanced({1, 1, -1}) == false);
        CHECK(isWellBalanced({1, 1}) == false);
    }
}