#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weaponA(weapon) {
    this->name = name;
    this->weaponA = weapon;
}

HumanA::~HumanA() {
}

void    HumanA::attack(void) {
    std::cout << name << " attacks with their " << this->weaponA.getType();
}