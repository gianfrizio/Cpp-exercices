#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c(10);
    Fixed const d(42.42f);
    Fixed e = c + d;
    Fixed f = d - c;
    Fixed g = d / c;
    Fixed h = c * d;

    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "b (5.05f * 2): " << b << std::endl;

    std::cout << "c (10): " << c << std::endl;
    std::cout << "d (42.42f): " << d << std::endl;

    std::cout << "e (c + d): " << e << std::endl;
    std::cout << "f (d - c): " << f << std::endl;
    std::cout << "g (d / c): " << g << std::endl;
    std::cout << "h (c * d): " << h << std::endl;

    std::cout << "Comparisons:" << std::endl;
    std::cout << "c > d: " << (c > d) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;

    std::cout << "Min and Max:" << std::endl;
    std::cout << "Min of c and d: " << Fixed::min(c, d) << std::endl;
    std::cout << "Max of c and d: " << Fixed::max(c, d) << std::endl;

    return 0;
}
