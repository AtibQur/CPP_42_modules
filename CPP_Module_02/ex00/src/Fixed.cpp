#include "../inc/Fixed.hpp"

// default constructor that initializes
// the fixed-point number value to 0;
Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    Fixed::fixedNum = 0;
}

// copy constructor
// is called when new object is created from existing one
Fixed::Fixed(const Fixed &fixedcopy) {
    std::cout << "Copy constructor called" << std::endl;
    fixedNum = fixedcopy.fixedNum;
}

//Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// copy assignment operator overload
// is called when an already initiliazed object is assigned a new value from
// another existing object
Fixed& Fixed::operator=(const Fixed &fixedCopy) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (&fixedCopy != this) {
        this->fixedNum = fixedCopy.getRawBits();
    }
    return (*this);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedNum);
}

void Fixed::setRawBits(int const rawBits) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedNum = rawBits;
}