#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

bool non_neg_prefix_sum(int lst[], int size);
bool non_pos_prefix_sum(int lst[], int size);

TEST_CASE("Non-Negative Prefix Sums") {
    SUBCASE("Standard valid case: {1, -1, 1, -1}") {
        int lst[] = {1, -1, 1, -1};
        CHECK(non_neg_prefix_sum(lst, 4) == true);
    }

    SUBCASE("Invalid cases") {
        int lst[] = {1, -1, -1, 1};
        CHECK(non_neg_prefix_sum(lst, 4) == false);
    }

    SUBCASE("Starting with a negative number") {
        int lst[] = {-1, 1};
        CHECK(non_neg_prefix_sum(lst, 2) == false);
    }
}

TEST_CASE("Non-Positive Prefix Sums") {
    SUBCASE("Standard valid case: {-1, 1, -1, 1}") {
        int lst[] = {-1, 1, -1, 1};
        CHECK(non_pos_prefix_sum(lst, 4) == true);
    }

    SUBCASE("Invalid cases") {
        int lst[] = {-1, 1, 1, -1};
        CHECK(non_pos_prefix_sum(lst, 4) == false);
    }

    SUBCASE("Starting with a positive num") {
        int lst[] = {1, -1};
        CHECK(non_pos_prefix_sum(lst, 2) == false);
    }
}