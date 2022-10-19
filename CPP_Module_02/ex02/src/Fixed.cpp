#include "../inc/Fixed.hpp"

/**********************************************/
/*                    OCCF                    */
/**********************************************/

// Default constructor
Fixed::Fixed() {
    this->rawBits = 0;
}

// Copy constructor
Fixed::Fixed(const Fixed &Copy) {
    this->rawBits = Copy.rawBits;
}

// Default constructor -- int
Fixed::Fixed(const int rawBits) {
    this->rawBits = rawBits;
}

// Default constructor -- float
Fixed::Fixed(const float rawBits) {
    this->rawBits = roundf(rawBits *(1 << Fixed::fractBits));
}

// Destuctor
Fixed::~Fixed() {
}

// Copy assignement operator
Fixed&  Fixed::operator=(const Fixed &Copy) {
    if (this != &Copy) {
        this->rawBits = Copy.rawBits;
    }
    return *this;
}

/**********************************************/
/*            comparison operators            */
/**********************************************/

bool    Fixed::operator>(const Fixed &Copy) const {
    return (this->rawBits > Copy.rawBits);
}

bool    Fixed::operator<(const Fixed &Copy) const {
    return (this->rawBits < Copy.rawBits);
}

bool    Fixed::operator>=(const Fixed &Copy) const {
    return (this->rawBits >= Copy.rawBits);
}

bool    Fixed::operator<=(const Fixed &Copy) const {
    return (this->rawBits <= Copy.rawBits);
}

bool    Fixed::operator==(const Fixed &Copy) const {
    return (this->rawBits == Copy.rawBits);
}

bool    Fixed::operator!=(const Fixed &Copy) const {
    return (this->rawBits != Copy.rawBits);
}

/**********************************************/
/*            Arithmetic operators            */
/**********************************************/

Fixed Fixed::operator+(const Fixed c1) const {
    return this->rawBits + c1.rawBits;
}

Fixed Fixed::operator-(const Fixed c1) const {
    return this->rawBits - c1.rawBits;
}

Fixed Fixed::operator*(const Fixed c1) const {
    return this->rawBits * c1.rawBits;
}

Fixed Fixed::operator/(const Fixed c1) const {
    return this->rawBits / c1.rawBits;
}

/**********************************************/
/*   pre/post increment/decrement operators   */
/**********************************************/

Fixed Fixed::operator++() {
    Fixed temp;
    temp.rawBits = ++rawBits;
    return temp;
}

Fixed Fixed::operator--() {
    Fixed temp;
    temp.rawBits = rawBits--;
    return temp;
}

Fixed Fixed::operator++(int) {
    Fixed temp;
    temp.rawBits = ++rawBits;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp;
    temp.rawBits = rawBits--;
    return temp;
}

/**********************************************/
/*        overloaded MIN/MAX functions        */
/**********************************************/

Fixed& Fixed::max(Fixed &c1, Fixed &c2) {
    if (c1 > c2)
        return (c1);
    else
        return (c2);
}

Fixed& Fixed::min(Fixed &c1, Fixed &c2) {
    if (c1 < c2)
        return (c1);
    else
        return (c2);
}

const Fixed& Fixed::max(const Fixed &c1, const Fixed &c2) {
    if (c1 > c2)
        return (c1);
    else
        return (c2);
}

const Fixed& Fixed::min(const Fixed &c1, const Fixed &c2) {
    if (c1 < c2)
        return (c1);
    else
        return (c2);
}

/**********************************************/
/*          convert toInt && toFloat          */
/**********************************************/

int   Fixed::toInt( void ) const {
    return this->rawBits >> this->fractBits;
}

float Fixed::toFloat( void ) const {
    return (float)this->rawBits / (1 << Fixed::fractBits);
}

/**********************************************/
/*       overload function << operator        */
/**********************************************/

std::ostream& operator<<(std::ostream& out, const Fixed &Copy) {
    out << Copy.toFloat();
    return out;
}