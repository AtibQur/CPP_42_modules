#include "../inc/Dog.hpp"

Dog::Dog() {
    this->_type = "Dog";
    this->brain = new Brain();

    std::cout << "Dog: created with default constructor." << std::endl;
}

Dog::Dog(const Dog& other) {
    *this = other;

    std::cout << "Dog: created with copy constructor." << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog: default destructor." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    this->Animal::operator=(other);
    *this->brain = *other.brain; // deep copy

    std::cout << this->_type << " has been created with the copy and assignment operator." << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof woof WOOF WoOf WOOOOF WOWOWOOOOFFFFFFF." << std::endl;
}

const std::string& Dog::getType() const {
    return this->_type;
}

Brain* Dog::getBrain() const {
    return this->brain;
}