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

        bool operator>(const Fixed &Copy);
        bool operator<(const Fixed &Copy);
        bool operator>=(const Fixed &Copy);
        bool operator<=(const Fixed &Copy);
        bool operator==(const Fixed &Copy);
        bool operator!=(const Fixed &Copy);
        
        Fixed operator+(const Fixed c1);
        Fixed operator-(const Fixed c1);
        Fixed operator*(const Fixed c1);
        Fixed operator/(const Fixed c1);

        Fixed operator++();
        Fixed operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        int     toInt( void ) const;
        float   toFloat( void ) const;

    private:
        int               rawBits;
        static  const int fractBits = 8;

};

    std::ostream& operator<<(std::ostream& out, const Fixed &Copy);

#endif