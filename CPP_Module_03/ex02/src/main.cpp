#include "../inc/FragTrap.hpp"

//Testing FragTraps
void    testFragTraps() {
    FragTrap *bas = new FragTrap();
    std::cout << std::endl;
    FragTrap *mar = new FragTrap("Mar");
    std::cout << std::endl;
    FragTrap *sab = new FragTrap(*bas);
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
    bas->highFivesGuys();
    mar->highFivesGuys();
    sab->highFivesGuys();
    std::cout << std::endl;
    delete bas;
    delete mar;
    delete sab;
}

//Creating FragTraps and delete them
void    createFragTraps() {
    FragTrap *bas = new FragTrap();
    std::cout << std::endl;

    FragTrap *mar = new FragTrap("Mar");
    std::cout << std::endl;

    FragTrap *sab = new FragTrap(*bas);
    std::cout << std::endl;

    delete bas;
    delete mar;
    delete sab;
}

int main(void) {
    // createFragTraps();
    testFragTraps();
    return 0;
}
