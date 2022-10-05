#include "contact.hpp"
#include <iomanip>

Contact::Contact() {
    this->FirstName = "Empty";
    this->LastName = "Empty";
    this->NickName = "Empty";
	this->PhoneNumber = "Empty";
	this->DarkestSecret = "Empty";
}

void    Contact::ViewContact(int i) {
		std::cout << "############################################################\n";
		std::cout << std::setw(16) << "Digit: [" << i << "]\n";
    	std::cout << std::setw(15) << "Firstname: " << Contact::FirstName << "\n";
    	std::cout<< std::setw(15)  << "Lastname: " << Contact::LastName << "\n";
		std::cout << std::setw(15) << "Nickname: " << Contact::NickName << "\n";
		std::cout << std::setw(15) << "Phonenumber: " << Contact::PhoneNumber << "\n";
		std::cout << std::setw(15) << "Dark secret: " << Contact::DarkestSecret << "\n";
		std::cout << "############################################################\n";
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

int	CheckCorrectAnswer(std::string str, std::string info, int num)
{
	int		i = 0;

	if (str.length() == 0) {
		std::cout << "Please try again" << std::endl;
		return (1);
	}
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
		std::getline(std::cin, Contact::FirstName);
        while (CheckCorrectAnswer(this->FirstName, "First name", 0) != 0) {
            std::cout << "Enter your first name:" << std::endl;
            std::getline(std::cin, this->FirstName);
        }
        std::cout << "Enter your last name:" << std::endl;
		std::getline(std::cin, this->LastName);
        while (CheckCorrectAnswer(this->LastName, "Last name", 0) != 0) {
            std::cout << "Enter your last name:" << std::endl;
            std::getline(std::cin, this->LastName);
        }
        std::cout << "Enter your nick name:" << std::endl;
		std::getline(std::cin, this->NickName);
        while (CheckCorrectAnswer(this->NickName, "Nick name", 0) != 0) {
            std::cout << "Enter your nick name" << std::endl;
            std::getline(std::cin, this->NickName);
        }
        std::cout << "Enter your phone number:" << std::endl;
		std::getline(std::cin, this->PhoneNumber);
        while (CheckCorrectAnswer(this->PhoneNumber, "Phone number", 1) != 0) {
            std::cout << "Enter your phone number:" << std::endl;
            std::getline(std::cin, this->PhoneNumber);
        }
        std::cout << "Enter your Darkest secret 😈:" << std::endl;
		std::getline(std::cin, this->DarkestSecret);
}
