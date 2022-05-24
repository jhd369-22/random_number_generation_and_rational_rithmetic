#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <ra/random.hpp>
#include <random>

using int_type = ra::random::int_type;

// catch2 test cases
TEST_CASE("constructor", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(1, 2, 3, 4);
    CHECK(lcg.multiplier() == 1);
    CHECK(lcg.increment() == 2);
    CHECK(lcg.modulus() == 3);
    CHECK(lcg.get_seed() == 4);
}

TEST_CASE("copy constructor", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(1, 2, 3, 4);
    ra::random::linear_congruential_generator lcg2(lcg);
    CHECK(lcg2.multiplier() == 1);
    CHECK(lcg2.increment() == 2);
    CHECK(lcg2.modulus() == 3);
    CHECK(lcg2.get_seed() == 4);
}

TEST_CASE("copy assignment operator", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(1, 2, 3, 4);
    ra::random::linear_congruential_generator lcg2(5, 6, 7, 8);
    lcg2 = lcg;
    CHECK(lcg2.multiplier() == 1);
    CHECK(lcg2.increment() == 2);
    CHECK(lcg2.modulus() == 3);
    CHECK(lcg2.get_seed() == 4);
}

TEST_CASE("move constructor", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(1, 2, 3, 4);
    ra::random::linear_congruential_generator lcg2(std::move(lcg));
    CHECK(lcg2.multiplier() == 1);
    CHECK(lcg2.increment() == 2);
    CHECK(lcg2.modulus() == 3);
    CHECK(lcg2.get_seed() == 4);
}

TEST_CASE("move assignment operator", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(1, 2, 3, 4);
    ra::random::linear_congruential_generator lcg2(5, 6, 7, 8);
    lcg2 = std::move(lcg);
    CHECK(lcg2.multiplier() == 1);
    CHECK(lcg2.increment() == 2);
    CHECK(lcg2.modulus() == 3);
    CHECK(lcg2.get_seed() == 4);
}

TEST_CASE("multiplier", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(1, 2, 3, 4);
    CHECK(lcg.multiplier() == 1);
}

TEST_CASE("increment", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(1, 2, 3, 4);
    CHECK(lcg.increment() == 2);
}

TEST_CASE("modulus", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(1, 2, 3, 4);
    CHECK(lcg.modulus() == 3);
}

TEST_CASE("default_seed", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(123, 456, 789);
    CHECK(ra::random::linear_congruential_generator::default_seed() == lcg.get_seed());
}

TEST_CASE("seed", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(123, 456, 789);
    lcg.seed(123);
    CHECK(lcg.get_x() == 123);
}

TEST_CASE("operator()", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(123, 456, 789, 1);
    std::linear_congruential_engine<ra::random::int_type, 123, 456, 789> gen(1);
    for (int i = 0; i < 10; ++i) {
        CHECK(lcg() == gen());
    }
}

TEST_CASE("operator== & operator!=", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(123, 456, 789);
    ra::random::linear_congruential_generator lcg2(123, 456, 789);
    CHECK(lcg == lcg2);
    lcg.seed(123);
    CHECK(lcg != lcg2);
}

TEST_CASE("discard", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(123, 456, 789, 1);
    std::linear_congruential_engine<ra::random::int_type, 123, 456, 789> gen(1);
    lcg.discard(10);
    gen.discard(10);
    for (int i = 0; i < 10; ++i) {
        CHECK(lcg() == gen());
    }
}

TEST_CASE("min", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(123, 456, 789, 1);
    std::linear_congruential_engine<ra::random::int_type, 123, 456, 789> gen(1);
    CHECK(lcg.min() == gen.min());
}

TEST_CASE("max", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(123, 456, 789, 1);
    std::linear_congruential_engine<ra::random::int_type, 123, 456, 789> gen(1);
    CHECK(lcg.max() == gen.max());
}

TEST_CASE("operator<<", "[linear_congruential_generator]") {
    ra::random::linear_congruential_generator lcg(123, 456, 789);
    std::stringstream ss;
    ss << lcg;
    CHECK(ss.str() == "123 456 789 1");
}
