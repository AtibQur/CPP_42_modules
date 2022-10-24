#include "../inc/ScavTrap.hpp"

//Testing ScavTraps
void    testScavTraps() {
    ScavTrap *bas = new ScavTrap();
    std::cout << std::endl;
    ScavTrap *mar = new ScavTrap("Mar");
    std::cout << std::endl;
    ScavTrap *sab = new ScavTrap(*bas);
    std::cout << std::endl;

    bas->attack("Testobject 1");
    mar->attack("Testobject 1");
    sab->attack("Testobject 1");
    std::cout << std::endl;
    bas->beRepaired(15);
    mar->beRepaired(20);
    sab->beRepaired(25);
    std::cout << std::endl;
    bas->takeDamage(15);
    mar->takeDamage(20);
    sab->takeDamage(25);
    std::cout << std::endl;
    bas->guardGate();
    mar->guardGate();
    sab->guardGate();
    std::cout << std::endl;
    delete bas;
    delete mar;
    delete sab;
}

//Creating ScavTraps and delete them
void    createScavTraps() {
    ScavTrap *bas = new ScavTrap();
    std::cout << std::endl;

    ScavTrap *mar = new ScavTrap("Mar");
    std::cout << std::endl;

    ScavTrap *sab = new ScavTrap(*bas);
    std::cout << std::endl;

    delete bas;
    delete mar;
    delete sab;
}

int main(void) {
    createScavTraps();
    // testScavTraps();
    return 0;
}
