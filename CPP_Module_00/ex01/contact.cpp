#include "contact.hpp"

Contact::Contact() {
    FirstName = "Empty";
    LastName = "Empty";
    NickName = "Empty";
}

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

void    Contact::InitContacts(void)
{
        std::cout << "Enter your first name:" << std::endl;
        std::cin >> Contact::FirstName;
        while (CheckCorrectAnswer(FirstName, "First name", 0) != 0) {
            std::cout << "Enter your first name:" << std::endl;
            std::cin >> Contact::FirstName;
        }
        std::cout << "Enter your last name:" << std::endl;
        std::cin >> Contact::LastName;
        while (CheckCorrectAnswer(Contact::LastName, "Last name", 0) != 0) {
            std::cout << "Enter your last name:" << std::endl;
            std::cin >> Contact::LastName;
        }
        std::cout << "Enter your nick name:" << std::endl;
        std::cin >> Contact::NickName;
        while (CheckCorrectAnswer(Contact::NickName, "Nick name", 0) != 0) {
            std::cout << "Enter your nick name" << std::endl;
            std::cin >> Contact::NickName;
        }
        std::cout << "Enter your phone number:" << std::endl;
        std::cin >> Contact::PhoneNumber;
        while (CheckCorrectAnswer(Contact::PhoneNumber, "Phone number", 1) != 0) {
            std::cout << "Enter your phone number:" << std::endl;
            std::cin >> Contact::PhoneNumber;
        }
        std::cout << "Enter your Darkest secret 😈:" << std::endl;
        std::cin >> Contact::DarkestSecret;
}
