#include "Point.hpp"

// Calculates the absolute area of the triangle formed by 3 points using the determinant
static Fixed area(Point const a, Point const b, Point const c) {
    Fixed res = (a.getX() * (b.getY() - c.getY())) +
                (b.getX() * (c.getY() - a.getY())) +
                (c.getX() * (a.getY() - b.getY()));
    if (res < Fixed(0))
        res = Fixed(0) - res;
    return res;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);

    // Checks that A is the sum of the other three and that none of them is zero (no edge or vertex)
    if (A == A1 + A2 + A3 && A1 != Fixed(0) && A2 != Fixed(0) && A3 != Fixed(0))
        return true;
    else
        return false;
}
