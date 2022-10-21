#include "../inc/ClapTrap.hpp"

/***********************************/
/*               OCCP              */
/***********************************/

ClapTrap::ClapTrap() : 
    name("Default"),
    hitpoints(10),
    energypoints(10),
    attackdmg(0) {
    std::cout << "Claptrap" << this->name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
    name(name),
    hitpoints(10),
    energypoints(10),
    attackdmg(0) {
    std::cout << "Claptrap " << this->name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "Claptrap " << this->name << " COPY has been created" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    this->name = other.name;
    this->hitpoints = other.hitpoints;
    this->energypoints = other.energypoints;
    this->attackdmg = other.attackdmg;
    std::cout << "Claptrap " << this->name << " has been created and assigned" << std::endl;
    return *this;
}

/***********************************/
/*        ClapTrap functions       */
/***********************************/

void    ClapTrap::attack(const std::string& target) {
    if (this->energypoints <= 0) {
        std::cout << "Claptrap " << this->name << " is not able to attack due to lack of energy points." << std::endl;
        return ;
    }
    if (this->hitpoints <= 0) {
        std::cout << "Claptrap " << this->name << " is not able to attack due to lack of hitpoints." << std::endl;
        return ;
    }
    this->energypoints--;
    std::cout << "Claptrap " << this->name << " attacks " << target << ", causing " << this->attackdmg << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitpoints <= 0) {
        std::cout << "Claptrap " << this->name << " is already dead." << std::endl;
        return ;
    }

    if (amount > this->hitpoints)
        amount = this->hitpoints;
    this->hitpoints -= amount;
    std::cout << "Claptrap " << this->name << " has been damaged for " << amount << " damage and has " << this->hitpoints << " hitpoints left." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (this->energypoints <= 0) {
        std::cout << "Claptrap " << this->name << " is not able to repair due to lack of energy points." << std::endl;
        return ;
    }
    if (this->hitpoints <= 0) {
        std::cout << "Claptrap " << this->name << " is not able to repair due to lack of hitpoints." << std::endl;
        return ;
    }
    this->hitpoints += amount;
    std::cout << "Claptrap " << this->name << " repaired itself for " << amount << " hitpoints. " << this->name << " has " << this->hitpoints << " HP." << std::endl;
}
