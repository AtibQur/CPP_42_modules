#include <iostream>

class Weapon 
{
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();
        std::string getType(void);
        void        setType(std::string setType);

    private:
        std::string type;

};

std::string getType(void);
void        setType(std::string setType);