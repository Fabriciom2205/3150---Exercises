#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fraction.h"
#include <sstream>

BigFraction fraction_add(BigFraction a, BigFraction b) {
    bigint numerator = (a.first * b.second) + (b.first * a.second);
    bigint denominator = a.second * b.second;
    return {numerator, denominator};
}

BigFraction fraction_multiply(BigFraction a, BigFraction b) {
    bigint numerator = a.first * b.first;
    bigint denominator = a.second * b.second;
    return {numerator, denominator};
}

std::string bigintToString(bigint n) {
    std::stringstream ss;
    ss << n;
    return ss.str();
}

TEST_CASE("multiply two simple fractions") {
    BigFraction a = {bigint(1), bigint(2)};
    BigFraction b = {bigint(2), bigint(3)};
    BigFraction result = fraction_multiply(a, b);
    CHECK(bigintToString(result.first) == "2");
    CHECK(bigintToString(result.second) == "6");
}

TEST_CASE("add two simple fractions") {
    BigFraction a = {bigint(1), bigint(2)};
    BigFraction b = {bigint(1), bigint(3)};
    BigFraction result = fraction_add(a, b);
    CHECK(bigintToString(result.first) == "5");
    CHECK(bigintToString(result.second) == "6");
}

TEST_CASE("adding zero does not change the fraction") {
    BigFraction a = {bigint(3), bigint(5)};
    BigFraction b = {bigint(0), bigint(1)};
    BigFraction result = fraction_add(a, b);
    CHECK(bigintToString(result.first) == "3");
    CHECK(bigintToString(result.second) == "5");
}

TEST_CASE("multiply works with large numbers") {
    BigFraction a = {bigint("99999999999999999999"), bigint("11111111111111111111")};
    BigFraction b = {bigint("22222222222222222222"), bigint("33333333333333333333")};
    BigFraction result = fraction_multiply(a, b);
    bigint expected_num = bigint("99999999999999999999") * bigint("22222222222222222222");
    bigint expected_den = bigint("11111111111111111111") * bigint("33333333333333333333");
    CHECK(bigintToString(result.first) == bigintToString(expected_num));
    CHECK(bigintToString(result.second) == bigintToString(expected_den));
}