#include "../inc/ScavTrap.hpp"

/***********************************/
/*               OCCP              */
/***********************************/

ScavTrap::ScavTrap() {
    this->name = "Default";
    this->hitpoints = 100;
    this->energypoints = 50;
    this-> attackdmg = 20;
    std::cout << "ScavTrap " << this->name << " has been created" << std::endl;
}



ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destroyed itself." << std::endl;
}
