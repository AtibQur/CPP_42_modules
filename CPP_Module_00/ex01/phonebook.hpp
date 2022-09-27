/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:54:33 by hqureshi          #+#    #+#             */
/*   Updated: 2022/09/27 16:37:38 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

# define RED "\033[0;31m"
# define CYAN "\033[0;36m"
# define PURPLE "\033[0;35m"
# define RESET "\033[0;30m"

int	CheckCorrectAnswer(std::string str, std::string info, int num);

class PhoneBook
{
    public:
        // void    AddPhoneBook() {
            
        // }
        
    private:
        // int contacts[8];        
};

class Contact
{
    public:
        void    AddContactDetails() {
            ContactNumber++;
            
            std::cout << "Enter your first name:" << std::endl;
            std::cin >> FirstName;
            while (CheckCorrectAnswer(FirstName, "First name", 0) != 0) {
                std::cout << "Enter your first name:" << std::endl;
                std::cin >> FirstName;
            }
            std::cout << "Enter your last name:" << std::endl;
            std::cin >> LastName;
            while (CheckCorrectAnswer(LastName, "Last name", 0) != 0) {
                std::cout << "Enter your last name:" << std::endl;
                std::cin >> LastName;
            }
            std::cout << "Enter your nick name:" << std::endl;
            std::cin >> NickName;
            while (CheckCorrectAnswer(NickName, "Nick name", 0) != 0) {
                std::cout << "Enter your nick name" << std::endl;
                std::cin >> NickName;
            }
            std::cout << "Enter your phone number:" << std::endl;
            std::cin >> PhoneNumber;
            while (CheckCorrectAnswer(PhoneNumber, "Phone number", 1) != 0) {
                std::cout << "Enter your phone number:" << std::endl;
                std::cin >> PhoneNumber;
            }
            std::cout << "Enter your Darkest secret 😈:" << std::endl;
            std::cin >> DarkestSecret;
        }
        
    private:
        static int  ContactNumber;
        std::string	FirstName;
        std::string	LastName;
        std::string	NickName;
        std::string	PhoneNumber;
        std::string	DarkestSecret;
};

#endif