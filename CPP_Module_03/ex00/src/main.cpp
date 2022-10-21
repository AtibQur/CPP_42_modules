#include "../inc/ClapTrap.hpp"

int main(void) {
    ClapTrap *Claptrap1 = new ClapTrap("Mar");
    ClapTrap *Claptrap2 = new ClapTrap("Sab");
    ClapTrap *Claptrap3 = new ClapTrap(*Claptrap1);

    std::cout << std::endl;

    Claptrap1->attack("John");
    Claptrap2->attack("Peter");
    Claptrap3->attack("Bas");

    std::cout << std::endl;

    Claptrap1->takeDamage(5);
    Claptrap2->takeDamage(3);
    Claptrap3->takeDamage(6);

    std::cout << std::endl;

    Claptrap1->beRepaired(5);
    Claptrap2->beRepaired(10);
    Claptrap3->beRepaired(15);

    std::cout << std::endl;

    delete Claptrap1;
    delete Claptrap2;
    delete Claptrap3;

    return 0;
}
