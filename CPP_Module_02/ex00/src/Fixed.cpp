#include "../inc/Fixed.hpp"

// default constructor that initializes
// the fixed-point number value to 0;
Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    Fixed::fixedNum = 0;
}

// copy constructor
Fixed::Fixed(const Fixed &fixedcopy) {
    std::cout << "Copy constructor called" << std::endl;
    fixedNum = fixedcopy.fixedNum;
}

//Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// copy assignment operator overload
Fixed& Fixed::operator=(const Fixed &fixedCopy) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (&fixedCopy != this) {
        this->fixedNum = fixedCopy.fixedNum;
    }
    return (*this);

}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedNum);
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedNum = raw;
}