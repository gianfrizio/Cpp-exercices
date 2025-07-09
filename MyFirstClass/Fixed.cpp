#include "Fixed.hpp"
#include <cmath>

// Constructors and Destructor
Fixed::Fixed() : _fixedPointValue(0) {}
Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {}
Fixed::Fixed(const float f) : _fixedPointValue(static_cast<int>(roundf(f * (1 << _fractionalBits)))) {}
Fixed::Fixed(const Fixed& other) { *this = other; }
Fixed::~Fixed() {}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _fixedPointValue = other._fixedPointValue;
    return *this;
}

// Raw value access
int Fixed::getRawBits(void) const { return _fixedPointValue; }
void Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }

// Conversions
float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

// Comparison Operators
bool Fixed::operator>(const Fixed& other) const { return _fixedPointValue > other._fixedPointValue; }
bool Fixed::operator<(const Fixed& other) const { return _fixedPointValue < other._fixedPointValue; }
bool Fixed::operator>=(const Fixed& other) const { return _fixedPointValue >= other._fixedPointValue; }
bool Fixed::operator<=(const Fixed& other) const { return _fixedPointValue <= other._fixedPointValue; }
bool Fixed::operator==(const Fixed& other) const { return _fixedPointValue == other._fixedPointValue; }
bool Fixed::operator!=(const Fixed& other) const { return _fixedPointValue != other._fixedPointValue; }

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result._fixedPointValue = _fixedPointValue + other._fixedPointValue;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result._fixedPointValue = _fixedPointValue - other._fixedPointValue;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long long product = static_cast<long long>(_fixedPointValue) * other._fixedPointValue;
    result._fixedPointValue = static_cast<int>(product >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    if (other._fixedPointValue == 0) {
        std::cerr << "Error: Division by zero.\n";
        return result;
    }
    long long numerator = static_cast<long long>(_fixedPointValue) << _fractionalBits;
    result._fixedPointValue = static_cast<int>(numerator / other._fixedPointValue);
    return result;
}

// Increment/Decrement Operators
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

// Min/Max Functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Stream operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
