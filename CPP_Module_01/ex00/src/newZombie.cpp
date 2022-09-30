#include "../inc/Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *peter = new Zombie(name);
    return (peter);
}