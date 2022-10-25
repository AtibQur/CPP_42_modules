#include "../inc/ScavTrap.hpp"

/***********************************/
/*               OCCP              */
/***********************************/

ScavTrap::ScavTrap() {
    this->name = "Default";
    this->hitpoints = 100;
    this->energypoints = 50;
    this-> attackdmg = 20;
    std::cout << "ScavTrap " << this->name << " has been created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
    this->name = name;
    this->hitpoints = 100;
    this->energypoints = 50;
    this-> attackdmg = 20;
    std::cout << "ScavTrap " << this->name << " has been created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
    *this = other;
    std::cout << "Scavtrap " << this->name << " COPY has been created." << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " destroyed itself." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    this->name = other.name;
    this->hitpoints = other.hitpoints;
    this->energypoints = other.energypoints;
    this->attackdmg = other.attackdmg;
    std::cout << "ScavTrap " << this->name << " has been created with assignement operator." << std::endl;

    return *this;
}

/***********************************/
/*         member function         */
/***********************************/

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
