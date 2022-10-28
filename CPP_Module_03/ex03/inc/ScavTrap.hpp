#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../inc/ClapTrap.hpp"

// Class ClapTrap is inherinced by ScavTrap
class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        virtual ~ScavTrap();

        ScavTrap& operator=(const ScavTrap& other);
        
        virtual void    attack(std::string target);
        void    guardGate();
    private:
};

#endif