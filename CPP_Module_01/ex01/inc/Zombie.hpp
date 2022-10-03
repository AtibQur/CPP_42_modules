#include <iostream>

class Zombie
{
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();

        Zombie* zombieHorde(int N, std::string name);
        void    NewName(std::string name);
        void    announce(void);

    private:
        std::string name;
};

Zombie* zombieHorde(int N, std::string name);
void    announce(void);