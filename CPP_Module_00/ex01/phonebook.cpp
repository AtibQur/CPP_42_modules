/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:54:27 by hqureshi          #+#    #+#             */
/*   Updated: 2022/09/27 16:40:23 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	CheckCorrectAnswer(std::string str, std::string info, int num)
{
	int		i = 0;

	while (str[i] && num == 0) {
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) {
				std::cout << info << " should only contain characters" << std::endl;
			return (1);
		}
		i++;
	}
	while (str[i] && num == 1) {
		if (str[i] < '0' || str[i] > '9') {
				std::cout << info << " should only contain numbers" << std::endl;
			return (1);
		}
		i++;
	}
	return (0);
}

void	WelcomeMessage(void)
{
	std::cout << "Welcome to your phonebook! Type one of the following options:" \
	CYAN	"\n1. \"ADD\" to add a contact"\
	PURPLE	"\n2. \"SEARCH\" to search a contact"\
	RED		"\n3. \"EXIT\" your phonebook \033[0;30m"; std::cout << std::endl;
}

int	main(void) {

	std::string	option;
	Contact contact;
	
	
	WelcomeMessage();
	// while (1)
	// {
		std::cin >> option;
		if (option.compare("ADD") == 0)
			contact.AddContactDetails();
	// }

	return (0);
}
