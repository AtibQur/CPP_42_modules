#include "../inc/DiamondTrap.hpp"

/***********************************/
/*               OCCP              */
/***********************************/

DiamondTrap::DiamondTrap() {
    this->name = "Default";
    this->ClapTrap::name = this->name.append("_clap_name");
    this->hitpoints = 100;
    this->energypoints = 50;
    this->attackdmg = 30;
    std::cout << "DiamondTrap " << this->name << " has been created." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) {
    this->name = name;
    this->ClapTrap::name = name.append("_clap_name");
    this->hitpoints = 100;
    this->energypoints = 50;
    this->attackdmg = 30;
    std::cout << "DiamondTrap " << this->name << " has been created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
    *this = other;
    std::cout << "DiamondTrap " << this->name << " COPY has been created.";
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " has destroyed itself." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    this->name = other.name;
    this->hitpoints = other.hitpoints;
    this->energypoints = other.energypoints;
    this->attackdmg = other.attackdmg;
    std::cout << "DiamondTrap " << this->name << " has been created with the operator assignement." << std::endl;
    return *this;
}

/***********************************/
/*         member functions        */
/***********************************/

void    DiamondTrap::attack(std::string const target) {
    ScavTrap::attack(target); 
}

void    DiamondTrap::whoAmI( void ) {
    std::cout << "I am " << DiamondTrap::name << " and my ClapTrap name is " << ClapTrap::name << '.' << std::endl;
}
