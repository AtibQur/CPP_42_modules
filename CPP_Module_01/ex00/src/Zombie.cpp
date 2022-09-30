#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name) {
    Zombie::name = name;
}

Zombie::~Zombie() {
    std::cout << "Zombies had enough BraaaaaiinnzzzZ" << std::endl;
}

void    Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
