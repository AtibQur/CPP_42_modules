#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
    Fixed();
    Fixed(const int bitValue);
    Fixed(const float bitValue);
    ~Fixed();

    Fixed &operator=(const Fixed &fixedCopy);

    private:
        int              fixedPointNum;
        static const int fractBits = 8;
};

#endif