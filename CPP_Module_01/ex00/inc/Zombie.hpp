#include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);
		Zombie* newZombie( std::string name );
		void	announce(void);
		void randomChump( std::string name );
		~Zombie();
	private:
		std::string name;
};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );
