#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &fixedCopy);
        ~Fixed();

        Fixed &operator=(const Fixed &fixedCopy);

        int getRawBits(void) const;
        void setRawBits(int const rawBits);

    private:
        int              fixedNum;
        static const int fractBits = 8;

};

#endif