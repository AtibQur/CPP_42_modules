#include "../inc/HumanA.hpp"

HumanA::HumanA() {
}

HumanA::~HumanA() {
}

HumanA::HumanA(std::string name, Weapon weapon) {
    HumanA::name = name;
    HumanA::weapon = weapon;
}

void    HumanA::attack(void) {
    std::cout << name << " attacks with their " << weapon.getType();
}