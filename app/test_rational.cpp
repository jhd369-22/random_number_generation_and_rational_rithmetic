#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <ra/rational.hpp>
#include <random>


// catch2 template test cases
TEMPLATE_TEST_CASE("default constructor", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r;
    CHECK(r.numerator() == 0);
    CHECK(r.denominator() == 1);
}

TEMPLATE_TEST_CASE("constructor", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    CHECK(r.numerator() == 1);
    CHECK(r.denominator() == 2);

    ra::math::rational<TestType> r2(1, -2);
    CHECK(r2.numerator() == -1);
    CHECK(r2.denominator() == 2);

    ra::math::rational<TestType> r3(3, 6);
    CHECK(r3.numerator() == 1);
    CHECK(r3.denominator() == 2);

    ra::math::rational<TestType> r4(1, 0);
    CHECK(r4.numerator() == std::numeric_limits<TestType>::max());
    CHECK(r4.denominator() == 1);
}

TEMPLATE_TEST_CASE("copy constructor", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(r);
    CHECK(r2.numerator() == 1);
    CHECK(r2.denominator() == 2);
}

TEMPLATE_TEST_CASE("copy assignment operator", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    r2 = r;
    CHECK(r2.numerator() == 1);
    CHECK(r2.denominator() == 2);
}

TEMPLATE_TEST_CASE("move constructor", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(std::move(r));
    CHECK(r2.numerator() == 1);
    CHECK(r2.denominator() == 2);
}

TEMPLATE_TEST_CASE("move assignment operator", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    r2 = std::move(r);
    CHECK(r2.numerator() == 1);
    CHECK(r2.denominator() == 2);
}

TEMPLATE_TEST_CASE("operator+=", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    r += r2;
    CHECK(r.numerator() == 7);
    CHECK(r.denominator() == 6);
}

TEMPLATE_TEST_CASE("operator-=", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    r -= r2;
    CHECK(r.numerator() == -1);
    CHECK(r.denominator() == 6);
}

TEMPLATE_TEST_CASE("operator*=", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    r *= r2;
    CHECK(r.numerator() == 1);
    CHECK(r.denominator() == 3);
}

TEMPLATE_TEST_CASE("operator/=", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    r /= r2;
    CHECK(r.numerator() == 3);
    CHECK(r.denominator() == 4);
}

TEMPLATE_TEST_CASE("truncate", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    CHECK(r.truncate() == 0);
}

TEMPLATE_TEST_CASE("is_integer", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 3);
    CHECK(r.is_integer() == false);
    CHECK(r2.is_integer() == true);
}

TEMPLATE_TEST_CASE("operator!", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(0, 2);
    ra::math::rational<TestType> r2(6, 9);
    CHECK(!r == true);
    CHECK(!r2 == false);
    CHECK(r.operator!() == true);
    CHECK(r2.operator!() == false);
}

TEMPLATE_TEST_CASE("operator== & operator!=", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ra::math::rational<TestType> r3(6, 9);
    CHECK(r != r2);
    CHECK((r2 != r3) == false);
    CHECK(r2 == r3);
    CHECK((r == r3) == false);
}

TEMPLATE_TEST_CASE("operator< & operator<=", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ra::math::rational<TestType> r3(6, 9);
    CHECK(r < r2);
    CHECK(r2 <= r3);
    CHECK((r2 < r) == false);
    CHECK((r2 <= r) == false);
}

TEMPLATE_TEST_CASE("operator> & operator>=", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ra::math::rational<TestType> r3(6, 9);
    CHECK(r2 > r);
    CHECK(r3 >= r2);
    CHECK((r > r2) == false);
    CHECK((r >= r2) == false);
}

TEMPLATE_TEST_CASE("prefix and postfix operator++", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ++r;
    CHECK(r.numerator() == 3);
    CHECK(r.denominator() == 2);
    ++r2;
    CHECK(r2.numerator() == 5);
    CHECK(r2.denominator() == 3);
    r++;
    CHECK(r.numerator() == 5);
    CHECK(r.denominator() == 2);
    r2++;
    CHECK(r2.numerator() == 8);
    CHECK(r2.denominator() == 3);
}

TEMPLATE_TEST_CASE("prefix and postfix operator--", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    --r;
    CHECK(r.numerator() == -1);
    CHECK(r.denominator() == 2);
    --r2;
    CHECK(r2.numerator() == -1);
    CHECK(r2.denominator() == 3);
    r--;
    CHECK(r.numerator() == -3);
    CHECK(r.denominator() == 2);
    r2--;
    CHECK(r2.numerator() == -4);
    CHECK(r2.denominator() == 3);
}

// non member template unary operators
TEMPLATE_TEST_CASE("unary operator+", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);

    CHECK((+r).numerator() == 1);
    CHECK((+r).denominator() == 2);
}

TEMPLATE_TEST_CASE("unary operator-", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);

    CHECK((-r).numerator() == -1);
    CHECK((-r).denominator() == 2);
}

// non member template binary operators
TEMPLATE_TEST_CASE("operator+", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ra::math::rational<TestType> r3 = r + r2;
    CHECK(r3.numerator() == 7);
    CHECK(r3.denominator() == 6);
}

TEMPLATE_TEST_CASE("operator-", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ra::math::rational<TestType> r3 = r - r2;
    CHECK(r3.numerator() == -1);
    CHECK(r3.denominator() == 6);
}

TEMPLATE_TEST_CASE("operator*", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ra::math::rational<TestType> r3 = r * r2;
    CHECK(r3.numerator() == 1);
    CHECK(r3.denominator() == 3);
}

TEMPLATE_TEST_CASE("operator/", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ra::math::rational<TestType> r3 = r / r2;
    CHECK(r3.numerator() == 3);
    CHECK(r3.denominator() == 4);
}

TEMPLATE_TEST_CASE("operator<<", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    std::stringstream ss;
    ss << r;
    CHECK(ss.str() == "1/2");
}

TEMPLATE_TEST_CASE("operator>>", "[rational]", int, long, long long) {

    SECTION("correct input") {
        ra::math::rational<TestType> r;
        std::stringstream ss("1/2");
        REQUIRE(ss >> r);
        CHECK(r.numerator() == 1);
        CHECK(r.denominator() == 2);
    }

    SECTION("incorrect input") {
        ra::math::rational<TestType> r;
        std::stringstream ss("1 2");
        REQUIRE(!(ss >> r));
    }

    SECTION("incorrect input1") {
        ra::math::rational<TestType> r;
        std::stringstream ss("a/2");
        REQUIRE(!(ss >> r));
    }

    SECTION("incorrect input2") {
        ra::math::rational<TestType> r;
        std::stringstream ss("1/a");
        REQUIRE(!(ss >> r));
    }

    SECTION("incorrect input3") {
        ra::math::rational<TestType> r;
        std::stringstream ss("a/a");
        REQUIRE(!(ss >> r));
    }
}