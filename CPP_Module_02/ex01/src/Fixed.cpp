#include "../inc/Fixed.hpp"

// Default constructor
Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->fixedPointNum = 0;
}

// Const integer value constructor, bitshift to get right integer number
Fixed::Fixed(const int bitValue) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointNum = bitValue << 8;
}

// Const float value constructor, use bitshift to get float number
Fixed::Fixed(const float bitValue) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointNum = roundf(bitValue *(1 << Fixed::fractBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &fixedcopy) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointNum = fixedcopy.fixedPointNum;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Copy assignment constructor
Fixed& Fixed::operator=(const Fixed &fixedCopy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixedCopy) {
        this->fixedPointNum = fixedCopy.fixedPointNum;
    }
    return *this;
 }

int   Fixed::toInt(void) const {
    return this->fixedPointNum >> this->fractBits;
}

float Fixed::toFloat(void) const {
    return (float)this->fixedPointNum / (1 << Fixed::fractBits);
}

std::ostream &operator << (std::ostream &out, const Fixed &obj) {
    out << obj.toFloat();
    return out;
}