#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "../inc/ClapTrap.hpp"

// Class ClapTrap is inherinced by ScavTrap
class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        ~FragTrap();

        FragTrap& operator=(const FragTrap& other);

        void    highFivesGuys( void );
    private:
};

#endif