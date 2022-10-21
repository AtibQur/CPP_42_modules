#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../inc/ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ~ScavTrap();

        ScavTrap& operator=(const ScavTrap& other);
        
        void    guardGate();
    private:
};

#endif