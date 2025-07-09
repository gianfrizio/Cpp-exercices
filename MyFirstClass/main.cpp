#include <iostream>
#include "Fixed.hpp"

void testComparisonOperators() {
    std::cout << "\n--- COMPARISON TESTS ---\n";

    Fixed a(10);
    Fixed b(10);
    Fixed c(20);

    std::cout << "a == b: " << (a == b) << "\n";  // 1
    std::cout << "a != c: " << (a != c) << "\n";  // 1
    std::cout << "a < c : " << (a < c) << "\n";   // 1
    std::cout << "c > a : " << (c > a) << "\n";   // 1
    std::cout << "a <= b: " << (a <= b) << "\n";  // 1
    std::cout << "c >= b: " << (c >= b) << "\n";  // 1
}

void testArithmeticOperators() {
    std::cout << "\n--- ARITHMETIC TESTS ---\n";

    Fixed a(5.5f);
    Fixed b(2.0f);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    std::cout << "a + b = " << a + b << "\n";     // 7.5
    std::cout << "a - b = " << a - b << "\n";     // 3.5
    std::cout << "a * b = " << a * b << "\n";     // 11.0
    std::cout << "a / b = " << a / b << "\n";     // 2.75
}

void testIncrementDecrement() {
    std::cout << "\n--- INCREMENT/DECREMENT TESTS ---\n";

    Fixed a;

    std::cout << "Initial a = " << a << "\n";

    std::cout << "++a = " << ++a << "\n"; // pre-increment
    std::cout << "a   = " << a << "\n";

    std::cout << "a++ = " << a++ << "\n"; // post-increment
    std::cout << "a   = " << a << "\n";

    std::cout << "--a = " << --a << "\n"; // pre-decrement
    std::cout << "a   = " << a << "\n";

    std::cout << "a-- = " << a-- << "\n"; // post-decrement
    std::cout << "a   = " << a << "\n";
}

void testMinMax() {
    std::cout << "\n--- MIN/MAX TESTS ---\n";

    Fixed a(10);
    Fixed b(42);

    const Fixed c(3.14f);
    const Fixed d(3.15f);

    std::cout << "min(a, b) = " << Fixed::min(a, b) << "\n";
    std::cout << "max(a, b) = " << Fixed::max(a, b) << "\n";

    std::cout << "min(c, d) = " << Fixed::min(c, d) << "\n";
    std::cout << "max(c, d) = " << Fixed::max(c, d) << "\n";
}

void testConversions() {
    std::cout << "\n--- CONVERSIONS TESTS ---\n";

    Fixed intFixed(123);
    Fixed floatFixed(123.456f);

    std::cout << "intFixed.toInt() = " << intFixed.toInt() << "\n";      // 123
    std::cout << "intFixed.toFloat() = " << intFixed.toFloat() << "\n";  // 123.0

    std::cout << "floatFixed.toInt() = " << floatFixed.toInt() << "\n";  // 123
    std::cout << "floatFixed.toFloat() = " << floatFixed.toFloat() << "\n";
}

int main() {
    testComparisonOperators();
    testArithmeticOperators();
    testIncrementDecrement();
    testMinMax();
    testConversions();
    return 0;
}
