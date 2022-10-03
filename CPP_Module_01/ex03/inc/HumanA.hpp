#include <iostream>
#include "../inc/Weapon.hpp"

class HumanA
{
    public:
        HumanA();
        HumanA(std::string name, Weapon weapon);
        ~HumanA();

        void    attack(void);
    private:
        std::string name;
        Weapon      weapon;
};