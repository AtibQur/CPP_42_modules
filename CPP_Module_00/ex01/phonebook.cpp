#include "phonebook.hpp"

void    PhoneBook::add(int i) {
    contacts[i].InitContacts();
}

void    PhoneBook::search() {
    int			i = 0;
    std::string	option;

    while (i <= 7) {
        contacts[i].ShowContacts(i);
        i++;
    }
    i = 0;
    std::cout << "Which contact would you like to see? Choose between 0 and 7:" << std::endl;
    std::cin >> option;
    if (option >= "0" && option <= "7")
		contacts[std::stoi(option)].ViewContact(std::stoi(option));
    else
		std::cout << option << " is not a valid option";
}