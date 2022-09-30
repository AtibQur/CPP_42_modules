#include "contact.hpp"
#include <iomanip>

void    Contact::ViewContact(int i) {
		std::cout << "Digit: [" << i << "]\n";
    	std::cout << "Firstname: "<< Contact::FirstName << "\n";
    	std::cout << "lastname: " << Contact::LastName << "\n";
		std::cout << "Nickname: " << Contact::NickName << "\n";
		std::cout << "Phonenumber: " << Contact::PhoneNumber << "\n";
		std::cout << "Darkest secret: " << Contact::DarkestSecret << "\n";
}

// if one of the names has more than 10 chars
// than truncate the last char and place a dot '.'
void	Contact::Truncate(std::string str) {

	for (int i = 0; i <= 9; i++)
		std::cout << str[i];
	std::cout << ".|";
}

void    Contact::ShowContacts(int i) {
    std::cout << std::setw(3) << '[' << i << "]|";
	if (Contact::FirstName.length() <= 10)
    	std::cout << std::setw(11) << Contact::FirstName << "|";
	else
		Truncate(Contact::FirstName);
	if (Contact::LastName.length() <= 10)
    	std::cout << std::setw(11) << Contact::LastName << "|";
	else
		Truncate(Contact::LastName);
	if (Contact::NickName.length() <= 10)
    	std::cout << std::setw(11) << Contact::NickName << "|" << std::endl;
	else {
		Truncate(Contact::NickName);
		std::cout << std::endl;
	}
}

Contact::Contact() {
    FirstName = "Empty";
    LastName = "Empty";
    NickName = "Empty";
	PhoneNumber = "Empty";
	DarkestSecret = "Empty";
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
