#include <iostream>
#include "Fixed.hpp"

int main() {
    std::cout << "===== Arithmetic Operators =====" << std::endl;
    Fixed a(5.5f);
    Fixed b(2.25f);

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "a / b = " << a / b << std::endl;

    std::cout << "\n===== Comparison Operators =====" << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    std::cout << "\n===== Increment / Decrement =====" << std::endl;
    Fixed c;
    std::cout << "c: " << c << std::endl;
    std::cout << "++c: " << ++c << std::endl;
    std::cout << "c++: " << c++ << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "--c: " << --c << std::endl;
    std::cout << "c--: " << c-- << std::endl;
    std::cout << "c: " << c << std::endl;

    std::cout << "\n===== Min / Max =====" << std::endl;
    Fixed d(7.5f);
    Fixed e(9.25f);
    const Fixed f(10.5f);
    const Fixed g(4.75f);

    std::cout << "min(d, e): " << Fixed::min(d, e) << std::endl;
    std::cout << "max(d, e): " << Fixed::max(d, e) << std::endl;
    std::cout << "min(f, g): " << Fixed::min(f, g) << std::endl;
    std::cout << "max(f, g): " << Fixed::max(f, g) << std::endl;

    return 0;
}
