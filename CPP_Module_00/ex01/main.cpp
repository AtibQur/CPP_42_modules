#include <iostream>
#include "./phonebook.hpp"

void	WelcomeMessage(void) {
	std::cout << 
			"\n\033[0;36m1. \"ADD\" to add a contact"\
			"\n\033[0;35m2. \"SEARCH\" to search a contact"\
			"\n\033[0;32m3. \"EXIT\" your phonebook \033[0;30m"; std::cout << std::endl;
}

int	main(void) {
	PhoneBook 	phonebook;
	std::string	option;
	int			i = 0;

	std::cout << "Welcome to your phonebook! Type one of the following options:"; 
	while (1)
	{
		WelcomeMessage();
		std::cin >> option;
		if (option == "ADD") {
			phonebook.add(i);
			i++;
			i = i%8;
		}
		else if (option == "SEARCH") {
			std::cout << "Index|  Firstname|   Lastname|   Nickname|" << std::endl;
			phonebook.search();
		}
		else if (option == "EXIT")
			return (0);
		else
			std::cout << "Wrong input, Would you like to ADD, SEARCH or EXIT?";
	}
}
