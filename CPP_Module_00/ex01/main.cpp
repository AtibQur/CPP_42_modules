#include <iostream>
#include "./phonebook.hpp"

void	WelcomeMessage(void) {
	// std::cout << "Welcome to your phonebook! Type one of the following options:" \
	// CYAN	"\n1. \"ADD\" to add a contact"\
	// PURPLE	"\n2. \"SEARCH\" to search a contact"\
	// RED		"\n3. \"EXIT\" your phonebook \033[0;30m"; std::cout << std::endl;
	std::cout << "You can start!" << std::endl;
}

int	main(void) {
	PhoneBook 	phonebook;
	std::string	option;
	int			i = 0;

	WelcomeMessage();
	while (1)
	{
		std::cin >> option;
		if (option == "ADD") {
			phonebook.add(i);
			i++;
		}
		if (option == "SEARCH") {
			std::cout << "Index     Firstname     Lastname      Nickname" << std::endl;
			phonebook.search();
			return (0);
		}
	}
	return (0);
}