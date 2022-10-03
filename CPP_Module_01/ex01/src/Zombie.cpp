#include "../inc/Zombie.hpp"

Zombie::Zombie() {
}

Zombie::Zombie(std::string name) {
    Zombie::name = name;
}

Zombie::~Zombie() {
    std::cout << "Zombies had enough BraaaaaiinnzzzZ" << std::endl;
}

void    Zombie::announce(void) {
    std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::NewName(std::string name) {
    Zombie::name = name;
}