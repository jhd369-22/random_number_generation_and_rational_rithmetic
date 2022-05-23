#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <include/ra/random.hpp>


// catch2 test cases
TEST_CASE("ra::random::linear_congruential_generator::default_seed", "[ra::random::linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(123, 456, 789);
    REQUIRE(lcg.seed() == ra::random::linear_congruential_generator::default_seed());
}

TEST_CASE("ra::random::linear_congruential_generator::seed", "[ra::random::linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(123, 456, 789);
    lcg.seed(123);
    REQUIRE(lcg.seed() == 123);
}

TEST_CASE("ra::random::linear_congruential_generator::operator()", "[ra::random::linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(123, 456, 789);
    lcg.seed(123);
    for (int i = 0; i < 10; ++i) {
        REQUIRE(lcg() == i);
    }
}

TEST_CASE("ra::random::linear_congruential_generator::operator==", "[ra::random::linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(123, 456, 789);
    ra::random::linear_congruential_generator lcg2(123, 456, 789);
    REQUIRE(lcg == lcg2);
    lcg.seed(123);
    REQUIRE(lcg != lcg2);
}

TEST_CASE("ra::random::linear_congruential_generator::operator!=", "[ra::random::linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(123, 456, 789);
    ra::random::linear
