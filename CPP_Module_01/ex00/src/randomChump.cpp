#include "../inc/Zombie.hpp"

void	randomChump( std::string name ) {
	Zombie rand = Zombie(name);
	rand.announce();
}