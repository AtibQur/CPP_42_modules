#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name): name(name) {
}

HumanB::~HumanB() {
}

void    HumanB::attack(void) {
    std::cout << this->name << " attacks with their " << weaponB->getType();
}

void    HumanB::setWeapon(Weapon &weaponB) {
    this->weaponB = &weaponB;
}

void    HumanB::setType(Weapon *setType) {
    this->weaponB = setType;
}