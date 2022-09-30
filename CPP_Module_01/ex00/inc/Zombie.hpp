#include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);

		void	announce(void);
		Zombie* newZombie( std::string name );

	private:
		std::string name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
