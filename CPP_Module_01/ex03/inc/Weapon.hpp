#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon 
{
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();

        const std::string getType(void);
        void        setType(std::string setType);

    private:
        std::string type;
};

    const std::string getType(void);
    void        setType(std::string setType);

#endif