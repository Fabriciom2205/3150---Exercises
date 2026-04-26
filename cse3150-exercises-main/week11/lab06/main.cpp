#include <iostream>
#include <chrono>
#include "fraction.h"

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

int main() {
    int sizes[] = {10, 100, 1000, 10000, 100000};
    int numSizes = 5;

    int an = 999999;
    int ad = 888888;
    int bn = 777777;
    int bd = 666666;

    long long int lan = 999999999;
    long long int lad = 888888888;
    long long int lbn = 777777777;
    long long int lbd = 666666666;

    BigFraction a = {bigint("99999999999999999999"), bigint("88888888888888888888")};
    BigFraction b = {bigint("77777777777777777777"), bigint("66666666666666666666")};

    std::cout << "iterations\tint*int\t\tlong*long\tbigint*bigint\t(microseconds)" << std::endl;

    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];

        long long int result = 0;

        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++) {
            int num = an * bn;
            int den = ad * bd;
            result = num + den;
        }
        auto end = std::chrono::high_resolution_clock::now();
        long long intTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++) {
            long long int num = lan * lbn;
            long long int den = lad * lbd;
            result = num + den;
        }
        end = std::chrono::high_resolution_clock::now();
        long long longTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++) {
            fraction_multiply(a, b);
        }
        end = std::chrono::high_resolution_clock::now();
        long long bigintTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        std::cout << n << "\t\t" << intTime << "\t\t" << longTime << "\t\t" << bigintTime << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Where int fails (overflow)" << std::endl;

    int x = 2000000000;
    int y = 2000000000;
    int overflow_result = x + y;
    std::cout << "int max is around 2.1 billion" << std::endl;
    std::cout << "2000000000 + 2000000000 as int = " << overflow_result << " which is wrong" << std::endl;

    long long int lx = 9999999999999999LL;
    long long int ly = 9999999999999999LL;
    long long int ll_overflow = lx * ly;
    std::cout << "long long max is around 9.2 * 10^18" << std::endl;
    std::cout << "9999999999999999 * 9999999999999999 as long long = " << ll_overflow << " which is wrong" << std::endl;

    bigint bx("9999999999999999");
    bigint by("9999999999999999");
    std::cout << "Same multiply as bigint = " << (bx * by) << " which is correct" << std::endl;

    return 0;
}