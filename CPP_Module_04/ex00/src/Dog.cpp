#include "../inc/Dog.hpp"

Dog::Dog() {
    this->_type = "Dog";

    std::cout << "Dog: created with default constructor." << std::endl;
}

Dog::Dog(const Dog& other) {
    *this = other;

    std::cout << "Dog: created with copy constructor." << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog: default destructor." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    this->_type = other._type;
    std::cout << this->_type << " has been created with the copy and assignment operator." << std::endl;
    return *this;
}

void    Dog::makeSound() const {
    std::cout << "Woof woof WOOF WoOf WOOOOF WOWOWOOOOFFFFFFF." << std::endl;
}

const std::string& Dog::getType() const {
    return this->_type;
}