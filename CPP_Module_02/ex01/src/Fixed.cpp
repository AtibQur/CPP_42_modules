#include "../inc/Fixed.hpp"

// Default constructor
Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->fixedPointNum = 0;
}

// Const integer value constructor
Fixed::Fixed(const int bitValue) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointNum = bitValue << Fixed::fixedPointNum;
}

// Const float value constructor
Fixed::Fixed(const float bitValue) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointNum = roundf(2.3 bitValue);
}

Fixed::Fixed(const Fixed &fixedcopy) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointNum = fixedcopy.fixedPointNum;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}



float Fixed::toFloat(void) const {
    return (float(this->fixedPointNum));
}

std::ostream &operator << (std::ostream &out, const Fixed &obj) {
    out << obj.toFloat();
    return (out);
}