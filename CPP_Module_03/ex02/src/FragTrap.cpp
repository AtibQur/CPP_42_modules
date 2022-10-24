#include "../inc/FragTrap.hpp"

/***********************************/
/*               OCCP              */
/***********************************/

FragTrap::FragTrap() {
    this->name = "Default";
    this->hitpoints = 100;
    this->energypoints = 100;
    this->attackdmg = 30;
    std::cout << "FragTrap " << this->name << " has been created." << std::endl;
}

FragTrap::FragTrap(std::string name) {
    this->name = name;
    this->hitpoints = 100;
    this->energypoints = 100;
    this->attackdmg = 30;
    std::cout << "FragTrap " << this->name << " has been created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) {
    *this = other;
    std::cout << "FragTrap " << this->name << " COPY has been made." << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name << " destroyed itself." << std::endl; 
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    this->name = other.name;
    this->hitpoints = other.hitpoints;
    this->energypoints = other.energypoints;
    this->attackdmg = other.attackdmg;
    std::cout << "FragTrap " << this->name << " has been created with assignement operator." << std::endl; 

    return *this;
}

/***********************************/
/*         member functions        */
/***********************************/

void    FragTrap::highFivesGuys( void ) {
    std::cout << this->name << ": AYYYY GUYS GIVE ME A HIGH FIVE 🙌" << std::endl;
}
