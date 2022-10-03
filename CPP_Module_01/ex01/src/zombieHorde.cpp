#include "../inc/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    
    int i = 0;

    if (N <= 0)
        return (NULL);
    Zombie *newzombie = new Zombie[N];
    while (i <= N) {
        newzombie[i].NewName(name);
        i++;
    }
    return (newzombie);
}