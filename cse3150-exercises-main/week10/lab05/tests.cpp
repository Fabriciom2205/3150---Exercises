#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "VectorLab.h"
#include <vector>

TEST_CASE("Testing Cosine Distance") {
    
    SUBCASE("Identical vectors should have no distance") {
        std::vector<double> v1 = {1.0, 2.0, 3.0};
        std::vector<double> v2 = {1.0, 2.0, 3.0};
        CHECK(VectorLab::getCosineDistance(v1, v2) == doctest::Approx(0.0));
    }

    SUBCASE("Orthogonal vectors distance = 1") {
        std::vector<double> v1 = {1.0, 0.0};
        std::vector<double> v2 = {0.0, 1.0};
        CHECK(VectorLab::getCosineDistance(v1, v2) == doctest::Approx(1.0));
    }

    SUBCASE("Opposite vectors distance = 2") {
        std::vector<double> v1 = {1.0, 1.0};
        std::vector<double> v2 = {-1.0, -1.0};
        CHECK(VectorLab::getCosineDistance(v1, v2) == doctest::Approx(2.0));
    }

    SUBCASE("Empty or null vectors should return 1.0") {
        std::vector<double> v1 = {0.0, 0.0};
        std::vector<double> v2 = {1.0, 1.0};
        CHECK(VectorLab::getCosineDistance(v1, v2) == 1.0);
    }
}