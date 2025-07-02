#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

// Declaration of bsp function
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    Point inside(5.0f, 5.0f);
    Point outside(10.0f, 10.0f);
    Point onEdge(5.0f, 0.0f);

    std::cout << "Inside point: " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
    std::cout << "Outside point: " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
    std::cout << "On edge point: " << (bsp(a, b, c, onEdge) ? "true" : "false") << std::endl;

    return 0;
}
