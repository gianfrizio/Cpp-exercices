#include "Fixed.hpp"
#include <cmath>

// Constructors, destructor, and methods as before...

// Default constructor: initializes fixed-point value to 0
Fixed::Fixed() : _fixedPointValue(0) {}

// Integer constructor: converts int to fixed-point representation
Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {}

// Float constructor: converts float to fixed-point representation
Fixed::Fixed(const float f) : _fixedPointValue(static_cast<int>(roundf(f * (1 << _fractionalBits)))) {}

// Copy constructor: copies value from another instance
Fixed::Fixed(const Fixed& other) { *this = other; }

// Copy assignment operator: assigns from another instance
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _fixedPointValue = other.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed() {}

// Returns the raw fixed-point value
int Fixed::getRawBits(void) const { return _fixedPointValue; }

// Sets the raw fixed-point value
void Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }

// Converts fixed-point value to float
float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

// Converts fixed-point value to int by shifting right
int Fixed::toInt(void) const { return _fixedPointValue >> _fractionalBits; }

// Comparison operators
bool Fixed::operator>(const Fixed& other) const { return _fixedPointValue > other._fixedPointValue; }
bool Fixed::operator<(const Fixed& other) const { return _fixedPointValue < other._fixedPointValue; }
bool Fixed::operator>=(const Fixed& other) const { return _fixedPointValue >= other._fixedPointValue; }
bool Fixed::operator<=(const Fixed& other) const { return _fixedPointValue <= other._fixedPointValue; }
bool Fixed::operator==(const Fixed& other) const { return _fixedPointValue == other._fixedPointValue; }
bool Fixed::operator!=(const Fixed& other) const { return _fixedPointValue != other._fixedPointValue; }

// Arithmetic operators

// Addition: add raw values and return new Fixed
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_fixedPointValue + other._fixedPointValue);
    return result;
}

// Subtraction: subtract raw values and return new Fixed
Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_fixedPointValue - other._fixedPointValue);
    return result;
}

// Multiplication: multiply raw values as 64-bit integer to avoid overflow, then shift right
Fixed Fixed::operator*(const Fixed& other) const {
    long long mul = static_cast<long long>(_fixedPointValue) * other._fixedPointValue;
    Fixed result;
    result.setRawBits(static_cast<int>(mul >> _fractionalBits));
    return result;
}

// Division: shift numerator to 64-bit for precision before dividing
Fixed Fixed::operator/(const Fixed& other) const {
    long long dividend = (static_cast<long long>(_fixedPointValue) << _fractionalBits);
    Fixed result;
    result.setRawBits(static_cast<int>(dividend / other._fixedPointValue));
    return result;
}

// Increment/decrement operators

// Pre-increment: increment raw value and return self
Fixed& Fixed::operator++() {
    ++_fixedPointValue;
    return *this;
}

// Post-increment: return old value, then increment
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++_fixedPointValue;
    return temp;
}

// Pre-decrement: decrement raw value and return self
Fixed& Fixed::operator--() {
    --_fixedPointValue;
    return *this;
}

// Post-decrement: return old value, then decrement
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --_fixedPointValue;
    return temp;
}

// Static min/max functions

// Returns reference to smaller of two Fixed objects (non-const)
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

// Returns reference to smaller of two const Fixed objects
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

// Returns reference to larger of two Fixed objects (non-const)
Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

// Returns reference to larger of two const Fixed objects
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Overload << operator to output fixed-point number as float
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
