#include "../inc/Fixed.hpp"

// Default constructor
Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->fixedPointNum = 0;
}

// Const integer value constructor
Fixed::Fixed(const int bitValue) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointNum = bitValue;
}

// Const float value constructor
Fixed::Fixed(const float bitValue) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointNum = bitValue;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

//Copy assignment operator constructor
Fixed& Fixed::operator=(const Fixed &fixedCopy) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (&fixedCopy != this) {
        this->fixedPointNum = fixedCopy.fixedPointNum;
    }
    return (*this);
}
