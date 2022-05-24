#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <ra/rational.hpp>
#include <random>


// catch2 template test cases
TEMPLATE_TEST_CASE("default constructor", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r;
    REQUIRE(r.numerator() == 0);
    REQUIRE(r.denominator() == 1);
}

TEMPLATE_TEST_CASE("constructor", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    REQUIRE(r.numerator() == 1);
    REQUIRE(r.denominator() == 2);

    ra::math::rational<TestType> r2(1, -2);
    REQUIRE(r2.numerator() == -1);
    REQUIRE(r2.denominator() == 2);

    ra::math::rational<TestType> r3(3, 6);
    REQUIRE(r3.numerator() == 1);
    REQUIRE(r3.denominator() == 2);

    ra::math::rational<TestType> r4(1, 0);
    REQUIRE(r4.numerator() == std::numeric_limits<int_type>::max());
    REQUIRE(r4.denominator() == 1);
}

TEMPLATE_TEST_CASE("copy constructor", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(r);
    REQUIRE(r2.numerator() == 1);
    REQUIRE(r2.denominator() == 2);
}

TEMPLATE_TEST_CASE("copy assignment operator", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    r2 = r;
    REQUIRE(r2.numerator() == 1);
    REQUIRE(r2.denominator() == 2);
}

TEMPLATE_TEST_CASE("move constructor", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(std::move(r));
    REQUIRE(r2.numerator() == 1);
    REQUIRE(r2.denominator() == 2);
}

TEMPLATE_TEST_CASE("move assignment operator", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    r2 = std::move(r);
    REQUIRE(r2.numerator() == 1);
    REQUIRE(r2.denominator() == 2);
}

TEMPLATE_TEST_CASE("operator+=", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    r2 += r;
    REQUIRE(r2.numerator() == 7);
    REQUIRE(r2.denominator() == 6);
}

TEMPLATE_TEST_CASE("operator-=", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    r2 -= r;
    REQUIRE(r2.numerator() == -1);
    REQUIRE(r2.denominator() == 6);
}

TEMPLATE_TEST_CASE("operator*=", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    r2 *= r;
    REQUIRE(r2.numerator() == 1);
    REQUIRE(r2.denominator() == 3);
}

TEMPLATE_TEST_CASE("operator/=", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    r2 /= r;
    REQUIRE(r2.numerator() == 3);
    REQUIRE(r2.denominator() == 4);
}

TEMPLATE_TEST_CASE("truncate", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    REQUIRE(r.truncate() == 0);
}

TEMPLATE_TEST_CASE("is_integer", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 3);
    REQUIRE(r.is_integer() == false);
    REQUIRE(r2.is_integer() == true);
}

TEMPLATE_TEST_CASE("operator!", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(0, 2);
    ra::math::rational<TestType> r2(6, 9);
    REQUIRE(!r == true);
    REQUIRE(!r2 == false);
    REQUIRE(r.operator!() == true);
    REQUIRE(r2.operator!() == false);
}

TEMPLATE_TEST_CASE("operator== & operator!=", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ra::math::rational<TestType> r3(6, 9);
    REQUIRE(r != r2);
    REQUIRE((r2 != r3) == false);
    REQUIRE(r2 == r3);
    REQUIRE((r == r3) == false);
}

TEMPLATE_TEST_CASE("operator< & operator<=", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ra::math::rational<TestType> r3(6, 9);
    REQUIRE(r < r2);
    REQUIRE(r2 <= r3);
    REQUIRE((r2 < r) == false);
    REQUIRE((r2 <= r) == false);
}

TEMPLATE_TEST_CASE("operator> & operator>=", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ra::math::rational<TestType> r3(6, 9);
    REQUIRE(r2 > r);
    REQUIRE(r3 >= r2);
    REQUIRE((r > r2) == false);
    REQUIRE((r >= r2) == false);
}

TEMPLATE_TEST_CASE("prefix and postfix operator++", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ++r;
    REQUIRE(r.numerator() == 3);
    REQUIRE(r.denominator() == 2);
    ++r2;
    REQUIRE(r2.numerator() == 5);
    REQUIRE(r2.denominator() == 3);
    r++;
    REQUIRE(r.numerator() == 5);
    REQUIRE(r.denominator() == 2);
    r2++;
    REQUIRE(r2.numerator() == 8);
    REQUIRE(r2.denominator() == 3);
}

TEMPLATE_TEST_CASE("prefix and postfix operator--", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    --r;
    REQUIRE(r.numerator() == -1);
    REQUIRE(r.denominator() == 2);
    --r2;
    REQUIRE(r2.numerator() == -2);
    REQUIRE(r2.denominator() == 3);
    r--;
    REQUIRE(r.numerator() == -1);
    REQUIRE(r.denominator() == 1);
    r2--;
    REQUIRE(r2.numerator() == -4);
    REQUIRE(r2.denominator() == 3);
}

// non member template unary operators
TEMPLATE_TEST_CASE("unary operator+", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    r+;
    REQUIRE(r.numerator() == 1);
    REQUIRE(r.denominator() == 2);
}

TEMPLATE_TEST_CASE("unary operator-", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    r-;
    REQUIRE(r.numerator() == -1);
    REQUIRE(r.denominator() == 2);
}

// non member template binary operators
TEMPLATE_TEST_CASE("operator+", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ra::math::rational<TestType> r3 = r + r2;
    REQUIRE(r3.numerator() == 7);
    REQUIRE(r3.denominator() == 6);
}

TEMPLATE_TEST_CASE("operator-", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ra::math::rational<TestType> r3 = r - r2;
    REQUIRE(r3.numerator() == -1);
    REQUIRE(r3.denominator() == 6);
}

TEMPLATE_TEST_CASE("operator*", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ra::math::rational<TestType> r3 = r * r2;
    REQUIRE(r3.numerator() == 1);
    REQUIRE(r3.denominator() == 3);
}

TEMPLATE_TEST_CASE("operator/", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    ra::math::rational<TestType> r2(6, 9);
    ra::math::rational<TestType> r3 = r / r2;
    REQUIRE(r3.numerator() == 3);
    REQUIRE(r3.denominator() == 4);
}

TEMPLATE_TEST_CASE("operator<<", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    std::stringstream ss;
    ss << r;
    REQUIRE(ss.str() == "1/2");
}

TEMPLATE_TEST_CASE("operator>>", "[rational]", int, long, long long) {
    ra::math::rational<TestType> r(1, 2);
    std::stringstream ss;
    ss << r;
    ra::math::rational<TestType> r2;
    ss >> r2;
    REQUIRE(r2.numerator() == 1);
    REQUIRE(r2.denominator() == 2);
}