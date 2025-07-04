#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed();                      // Default constructor
    Fixed(const Fixed& other);    // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed();                     // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
