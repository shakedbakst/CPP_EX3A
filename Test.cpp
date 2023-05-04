#include <iostream>
#include "doctest.h"
#include <sstream>
#include "Fraction.hpp"

using namespace std;
using namespace ariel;

//1
TEST_CASE("Fraction initialization") {
    Fraction f1;
    CHECK(f1.getNumerator() == 0);
    CHECK(f1.getDenominator() == 1);

    Fraction f2(1, 2);
    CHECK(f2.getNumerator() == 1);
    CHECK(f2.getDenominator() == 2);

    Fraction f3(-2, 4);
    CHECK(f3.getNumerator() == -1);
    CHECK(f3.getDenominator() == 2);
}

//2
TEST_CASE("Denominator cannot be zero") {
    Fraction frc(1,1);
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(frc.setDenominator(0));
}

//3
TEST_CASE("Addition operator") {
    Fraction f1(1, 2), f2(1, 3);
    Fraction f3 = f1 + f2;
    CHECK(f3.getNumerator() == 5);
    CHECK(f3.getDenominator() == 6);

    f1 = Fraction(1, 6);
    f2 = Fraction(2, 6);
    f3 = f1 + f2;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 2);
}

//4
TEST_CASE("Subtraction operator") {
    Fraction f1(1, 2), f2(1, 3);
    Fraction f3 = f1 - f2;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 6);

    f1 = Fraction(1, 3);
    f2 = Fraction(2, 6);
    f3 = f1 - f2;
    CHECK(f3.getNumerator() == -1);
    CHECK(f3.getDenominator() == 6);
}

//5
TEST_CASE("Multiplication operator") {
    Fraction f1(1, 2), f2(2, 3);
    Fraction f3 = f1 * f2;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 3);

    f1 = Fraction(2, 5);
    f2 = Fraction(1, 3);
    f3 = f1 * f2;
    CHECK(f3.getNumerator() == 2);
    CHECK(f3.getDenominator() == 15);
}

//6
TEST_CASE("Division operator") {
    Fraction f1(1, 2), f2(2, 3);
    Fraction f3 = f1 / f2;
    CHECK(f3.getNumerator() == 3);
    CHECK(f3.getDenominator() == 4);

    f1 = Fraction(2, 5);
    f2 = Fraction(1, 3);
    f3 = f1 / f2;
    CHECK(f3.getNumerator() == 6);
    CHECK(f3.getDenominator() == 5);
}

//7
TEST_CASE("Equality operator") {
    Fraction f1(1, 2), f2(2, 4), f3(2, 3);
    CHECK(f1 == f2);
    CHECK(!(f1 == f3));
}

//8
TEST_CASE("Comparison operators") {
    Fraction f1(1, 2), f2(2, 4), f3(2, 3);
    CHECK(f1 < f3);
    CHECK(f3 > f2);
    CHECK(f1 <= f2);
    CHECK(f2 >= f2);
}

//9
TEST_CASE("Pre and Postfix operators") {
    Fraction f1(1, 2), f2(2, 3);
    Fraction f3 = ++f1;
    CHECK(f1.getNumerator() == 3);
    CHECK(f1.getDenominator() == 2);
    CHECK(f3.getNumerator() == 3);
    CHECK(f3.getDenominator() == 2);

    f3 = f2++;
    CHECK(f2.getNumerator() == 5);
    CHECK(f2.getDenominator() == 3);
    CHECK(f3.getNumerator() == 2);  
    CHECK(f3.getDenominator() == 3);

    f3 = --f1;
    CHECK(f1.getNumerator() == 2);
    CHECK(f1.getDenominator() == 2);
    CHECK(f3.getNumerator() == 2);
    CHECK(f3.getDenominator() == 2);

    f3 = f2--;
    CHECK(f2.getNumerator() == 4);
    CHECK(f2.getDenominator() == 3);
    CHECK(f3.getNumerator() == 5);
    CHECK(f3.getDenominator() == 3);
}

//10
TEST_CASE("Output operator") {
    Fraction f1(1, 2);
    std::ostringstream stream;
    stream << f1;
    CHECK(stream.str() == "1/2");
}

//11
TEST_CASE("Input operator") {
    Fraction f1;
    std::istringstream stream("2 4");
    stream >> f1;
    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);

    stream = std::istringstream("3/6");
    stream >> f1;
    CHECK(f1.getNumerator() == 1);
    CHECK(f1.getDenominator() == 2);

    stream = std::istringstream("0.666");
    stream >> f1;
    CHECK(f1.getNumerator() == 2);
    CHECK(f1.getDenominator() == 3);
}

//12
TEST_CASE("Mixed arithmetic operations") {
    Fraction f1(1, 2), f2(2, 3), f3;
    float f = 0.5;
    f3 = f1 + f;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 1);

    f3 = f1 - f;
    CHECK(f3.getNumerator() == 0);
    CHECK(f3.getDenominator() == 2);

    f3 = f1 * f;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 4);

    f3 = f1 / f;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 1);

    f3 = f * f1;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 4);

    f3 = f2 + f;
    CHECK(f3.getNumerator() == 7);
    CHECK(f3.getDenominator() == 6);

    f3 = f2 - f;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 6);

    f3 = f2 * f;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 3);

    f3 = f2 / f;
    CHECK(f3.getNumerator() == 4);
    CHECK(f3.getDenominator() == 3);

    f3 = f * f2;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 3);
}

/*TEST_CASE("Mixed arithmetic operations") {
    Fraction f1(1, 2), f2(2, 3), f3;
    float f = 0.5;
    f3 = f1 + f;
    CHECK(f3.getNumerator() == 3);
    CHECK(f3.getDenominator() == 2);

    f3 = f1 - f;
    CHECK(f3.getNumerator() == 0);
    CHECK(f3.getDenominator() == 2);

    f3 = f1 * f;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 4);

    f3 = f1 / f;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 1);

    f3 = f * f1;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 1);

    f3 = f2 + f;
    CHECK(f3.getNumerator() == 8);
    CHECK(f3.getDenominator() == 3);

    f3 = f2 - f;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 3);

    f3 = f2 * f;
    CHECK(f3.getNumerator() == 1);
    CHECK(f3.getDenominator() == 3);

    f3 = f2 / f;
    CHECK(f3.getNumerator() == 2);
    CHECK(f3.getDenominator() == 1);

    f3 = f * f2;
    CHECK(f3.getNumerator() == 2);
    CHECK(f3.getDenominator() == 3);
}*/


