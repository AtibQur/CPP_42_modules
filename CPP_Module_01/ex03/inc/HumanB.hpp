#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "../inc/Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();

        void    attack(void);
        void    setWeapon(Weapon &weaponB);
        void    setType(Weapon *setType);
    private:
        std::string name;
        Weapon      *weaponB;
};

        void    setWeapon(Weapon &weaponB);
        void    setType(Weapon *setType);

#endif