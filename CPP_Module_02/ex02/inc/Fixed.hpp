#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{

    public:
        Fixed();
        Fixed(const Fixed &Copy);
        Fixed(const int rawBits);
        Fixed(const float rawBits);
        ~Fixed();
        Fixed& operator=(const Fixed &Copy);

        bool operator>(const Fixed &Copy) const;
        bool operator<(const Fixed &Copy) const;
        bool operator>=(const Fixed &Copy) const;
        bool operator<=(const Fixed &Copy) const;
        bool operator==(const Fixed &Copy) const;
        bool operator!=(const Fixed &Copy) const;
        
        Fixed operator+(const Fixed c1) const;
        Fixed operator-(const Fixed c1) const;
        Fixed operator*(const Fixed c1) const;
        Fixed operator/(const Fixed c1) const;

        Fixed operator++();
        Fixed operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        static Fixed& max(Fixed &c1, Fixed &c2);
        static Fixed& min(Fixed &c1, Fixed &c2);
        static const Fixed& max(const Fixed &c1, const Fixed &c2);
        static const Fixed& min(const Fixed &c1, const Fixed &c2);

        int         toInt( void ) const;
        float       toFloat( void ) const;

    private:
        int               rawBits;
        static  const int fractBits = 8;

};

    std::ostream& operator<<(std::ostream& out, const Fixed &Copy);

#endif