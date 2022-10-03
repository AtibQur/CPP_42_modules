#include "../inc/Zombie.hpp"

int main(void) {
    
    int         size;
    std::string name;
    Zombie      *newZombie;
    
    name = "Zedd";
    size = 2;
    std::cout << "Spawning a zombie horde of " << size << ' ' << name << "'s zombies, BE PREPARED 🧟" << std::endl;
    newZombie = zombieHorde(size, name);
    for (int i = 0; i < size; i++) {
        std::cout << '[' << i << ']';
        newZombie[i].announce();
    }
        // delete[] newZombie;
    std::cout << std::endl;
    newZombie = zombieHorde(size, name);


    name = "Sabb";
    size = 5;
    std::cout << "Spawning a zombie horde of " << size << ' ' << name << "'s zombies, BE PREPARED 🧟‍♀️" << std::endl;
    newZombie = zombieHorde(size, name);
    for (int i = 0; i < size; i++) {
        std::cout << '[' << i << ']';
        newZombie[i].announce();
    }
    delete[] newZombie;
    std::cout << std::endl;

    std::cout << "Create your own zombie Horde!" << std::endl;
    std::cout << "What is the name of your horde?" << std::endl;
    std::cin >> name;
    std::cout << "What is the size of the horde?" << std::endl;
    std::cin >> size;
    std::cout << "Spawning a zombie horde of " << size << ' ' << name << "'s zombies, BE PREPARED 🧟🧟‍♀️" << std::endl;
    newZombie = zombieHorde(size, name);
    for (int i = 0; i < size; i++) {
        std::cout << '[' << i << ']';
        newZombie[i].announce();
    }
    delete[] newZombie;
    std::cout << std::endl;

    // check for leaks
    // Zombie *newzombies = new Zombie;
    // newzombies->announce();
    // system("leaks zombies");
    return (0);
}