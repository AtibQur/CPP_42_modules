#include "../inc/Zombie.hpp"

int main(void) {
    std::cout << "Creating the first zombie with the name Foo: \n";
    Zombie Foo("Foo");
    Foo.announce();
    
    std::cout << "Creating the second zombie named Peter  with the fuction \"newZombie\":\n";
    Zombie *peter = newZombie("Peter");
    peter->announce();


    return (0);
}