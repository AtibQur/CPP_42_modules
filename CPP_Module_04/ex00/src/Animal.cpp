#include "../inc/Animal.hpp"

Animal::Animal() {
    _type = "Animal";

    std::cout << "Animal: created with default constructor." << std::endl;
}

Animal::Animal(const Animal& other) {
    *this = other;

    std::cout << "Animal: created with copy constructor." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal: default destructor." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    this->_type = other._type;
    std::cout << this->_type << " has been created with copy assignement operator." << std::endl;
    return *this;
}

void    Animal::makeSound() const {
    std::cout << "Animal sound: ack-ack-ack-ackawoooo-ack-ack-ack!!!" << std::endl;
}

const std::string& Animal::getType() const {
    return this->_type;
}