#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);
        ~DiamondTrap();

        DiamondTrap& operator=(const DiamondTrap& other);

        void    attack(std::string target);
        void    whoAmI( void );

    private:
        std::string name;
};



#endif