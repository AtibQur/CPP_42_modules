#include "../inc/DiamondTrap.hpp"

//Testing DiamondTraps
void    testDiamondTraps() {
    DiamondTrap *bas = new DiamondTrap("Tal");
    std::cout << std::endl;
    DiamondTrap *mar = new DiamondTrap("Mar");
    std::cout << std::endl;
    DiamondTrap *sab = new DiamondTrap("Lab");
    std::cout << std::endl;

    bas->attack("Testobject 1");
    mar->attack("Testobject 1");
    sab->attack("Testobject 1");
    std::cout << std::endl;
    bas->beRepaired(5);
    mar->beRepaired(10);
    sab->beRepaired(15);
    std::cout << std::endl;
    bas->takeDamage(15);
    mar->takeDamage(200);
    mar->takeDamage(200);
    sab->takeDamage(25);
    std::cout << std::endl;
    bas->whoAmI();
    mar->whoAmI();
    sab->whoAmI();
    std::cout << std::endl;
    delete bas;
    delete mar;
    delete sab;
}

//Creating DiamondTraps and delete them
void    createDiamondTraps() {
    DiamondTrap *bas = new DiamondTrap();
    std::cout << std::endl;

    DiamondTrap *mar = new DiamondTrap("Mar");
    std::cout << std::endl;

    DiamondTrap *sab = new DiamondTrap(*bas);
    std::cout << std::endl;

    delete bas;
    delete mar;
    delete sab;
}

int main(void) {
    // createDiamondTraps();
    testDiamondTraps();

    return 0;
}
