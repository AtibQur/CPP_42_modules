#include "../inc/Fixed.hpp"

void    TestOperators() {
    Fixed Object1(10);
    Fixed Object2(9);

    if (Object1 > Object2)
        std::cout << "Object1 is greater!" << std::endl;
    else
        std::cout << "Object1 is not greater!" << std::endl;

    if (Object1 < Object2)
        std::cout << "Object1 is lower!" << std::endl;
    else
        std::cout << "Object1 is not lower!" << std::endl;

    std::cout << std::endl;

    if (Object1 >= Object2)
        std::cout << "Object1 is greater or equal!" << std::endl;
    else
        std::cout << "Object1 is not lower!" << std::endl;
    
    if (Object1 <= Object2)
        std::cout << "Object1 is lower or equal!" << std::endl;
    else
        std::cout << "Object1 is not lower or equal!" << std::endl;

    std::cout << std::endl;

    Fixed Object3(10);
    Fixed Object4(10);

    if (Object1 == Object2)
        std::cout << "Object3 is equal to Object4!" << std::endl;
    else
        std::cout << "Object3 is not equal to Object4!" << std::endl;
    
    if (Object1 != Object2)
        std::cout << "Object3 is equal to Object4!" << std::endl;
    else
        std::cout << "Object3 is not equal to Object4!" << std::endl;
}

void OverloadMemberTest() {
    Fixed test1(15.01f);
    Fixed test2(14.01f);
    std::cout << Fixed::max( test1, test2 ) << std::endl;

    Fixed const test3(15.01f);
    Fixed const test4(14.01f);
    std::cout << Fixed::max( test3, test4 ) << std::endl;

    Fixed test5(15.01f);
    Fixed test6(14.01f);
    std::cout << Fixed::min( test5, test6 ) << std::endl;

    Fixed const test7(15.01f);
    Fixed const test8(14.01f);
    std::cout << Fixed::min( test7, test8 ) << std::endl;
}

void    StandardTest() {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );


    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
}

int main( void ) {

    StandardTest();
    // OverloadMemberTest();
    // TestOperators();

    return 0;
}