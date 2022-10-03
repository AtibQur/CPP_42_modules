#include "../inc/Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(std::string type) {
    Weapon::type = type;
}

Weapon::~Weapon() {
}

std::string Weapon::getType(void) {
    return (type);
}

void        Weapon::setType(std::string setType) {
    Weapon::type = setType;
}