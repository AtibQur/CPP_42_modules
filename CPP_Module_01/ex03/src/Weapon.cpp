#include "../inc/Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(std::string type) {
    if (type != "\0")
        Weapon::type = type;
    else
        Weapon::type = "fists";
}

Weapon::~Weapon() {
}

const std::string Weapon::getType(void) {
    return (this->type);
}

void        Weapon::setType(std::string setType) {
    if (setType != "\0")
        this->type = setType;
    else
        this->type = "fists";
}
