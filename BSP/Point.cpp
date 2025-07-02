#include "Point.hpp"

// Default constructor: x=0, y=0
Point::Point() : x(0), y(0) {}

// Constructor with floats
Point::Point(const float x_val, const float y_val) : x(x_val), y(y_val) {}

// Copy constructor
Point::Point(const Point& other) : x(other.x), y(other.y) {}

// Assignment operator
Point& Point::operator=(const Point& other) {
    // x and y sono const, quindi non possono essere assegnati dopo la costruzione
    // Perciò normalmente è consigliabile NON implementare operator= o lanciarlo come delete
    // Ma per la richiesta, possiamo lasciare vuoto o non implementare.
    (void)other;
    return *this;
}

// Destructor
Point::~Point() {}

// Getters
Fixed Point::getX() const { return x; }
Fixed Point::getY() const { return y; }
