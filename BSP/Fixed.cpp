#include "Fixed.hpp"
#include <cmath>

// Constructors
Fixed::Fixed() : _fixedPointValue(0) {}
Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {}
Fixed::Fixed(const float f) : _fixedPointValue(static_cast<int>(roundf(f * (1 << _fractionalBits)))) {}
Fixed::Fixed(const Fixed& other) { *this = other; }

// Assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _fixedPointValue = other.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return _fixedPointValue; }
void Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }

float Fixed::toFloat(void) const { return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits); }
int Fixed::toInt(void) const { return _fixedPointValue >> _fractionalBits; }

// Comparison operators
bool Fixed::operator>(const Fixed& other) const { return _fixedPointValue > other._fixedPointValue; }
bool Fixed::operator<(const Fixed& other) const { return _fixedPointValue < other._fixedPointValue; }
bool Fixed::operator>=(const Fixed& other) const { return _fixedPointValue >= other._fixedPointValue; }
bool Fixed::operator<=(const Fixed& other) const { return _fixedPointValue <= other._fixedPointValue; }
bool Fixed::operator==(const Fixed& other) const { return _fixedPointValue == other._fixedPointValue; }
bool Fixed::operator!=(const Fixed& other) const { return _fixedPointValue != other._fixedPointValue; }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    long long mul = static_cast<long long>(_fixedPointValue) * other._fixedPointValue;
    Fixed result;
    result.setRawBits(static_cast<int>(mul >> _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    long long dividend = (static_cast<long long>(_fixedPointValue) << _fractionalBits);
    Fixed result;
    result.setRawBits(static_cast<int>(dividend / other._fixedPointValue));
    return result;
}

// Increment/decrement operators
Fixed& Fixed::operator++() {
    ++_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++_fixedPointValue;
    return temp;
}

Fixed& Fixed::operator--() {
    --_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --_fixedPointValue;
    return temp;
}

// Static min/max functions
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

// Overload << operator for output
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
