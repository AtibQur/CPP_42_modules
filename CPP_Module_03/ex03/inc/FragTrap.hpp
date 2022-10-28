#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "../inc/ClapTrap.hpp"

// Class ClapTrap is inherinced by ScavTrap
class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        virtual ~FragTrap();

        FragTrap& operator=(const FragTrap& other);

        void    attack(std::string target);
        void    highFivesGuys( void );
    private:
};

#endif