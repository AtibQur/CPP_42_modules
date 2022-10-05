#include "../inc/Weapon.hpp"
#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

int main()
{
    // HumanA bob gets a reference from club
    {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    std::cout << std::endl;
    club.setType("some other type of club");
    bob.attack();
    std::cout << std::endl;
    }
    // HumanB makes use of a pointer for the weapon
    {
    Weapon club = Weapon("wooden bat");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    std::cout << std::endl;
    club.setType("some other type of club");
    jim.attack();
    std::cout << std::endl;
    }
    // Sab does not use a weapon and instead gets to use fists
    {
    Weapon club = Weapon("");
    HumanB sab("Sab");
    sab.setWeapon(club);
    sab.attack();
    std::cout << std::endl;
    club.setType("");
    sab.attack();
    }
    return 0;
}
