#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "../inc/Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();

        void    attack(void);
    private:
        std::string name;
        Weapon      &weaponA;
};

#endif