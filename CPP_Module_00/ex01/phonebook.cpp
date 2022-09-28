#include "phonebook.hpp"

void    PhoneBook::add(int i) {
    contacts[i].InitContacts();
}

void    PhoneBook::search() {
    int i = 0;
    int option;

    while (i <= 7) {
        contacts[i].ShowContacts(i);
        i++;
    }
    i = 0;
    std::cout << "Which contact would you like to see?" << std::endl;
    std::cin >> option;
}