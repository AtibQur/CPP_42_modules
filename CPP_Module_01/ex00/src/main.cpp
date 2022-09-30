#include "../inc/Zombie.hpp"

int main(void) {
    std::cout << "Creating the first zombie with the name Foo:" << std::endl;
    {
    	Zombie Foo("Foo");
	    Foo.announce();
    }
    std::cout << "Creating the second zombie \"Peter\"  with the fuction \"newZombie\":" << std::endl;
	{
		Zombie *peter = newZombie("Peter");
		peter->announce();
		delete peter;
	}
	std::cout << "Creating the third zombie \"Sab\" with randomChump and Sab will announce itself" << std::endl;
	{
		randomChump("Sab");
	}
    return (0);
}