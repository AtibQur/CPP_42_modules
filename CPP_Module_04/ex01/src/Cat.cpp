#include "../inc/Cat.hpp"

Cat::Cat() {
    this->_type = "Cat";
    this->brain = new Brain;

    std::cout << "Cat: created with default constructor." << std::endl;
}

Cat::Cat(const Cat& other) {
    *this = other;

    std::cout << "Cat: created with copy constructor." << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat: default destructor." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    this->Animal::operator=(other);
    *this->brain = *other.brain; // deepcopy

    std::cout << this->_type << " has been created with the copy and assignment operator." << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "meow, mow, mrow, mrrr, prr, prrt, hh, mrrrrrrrrrrawr." << std::endl;
}

const std::string& Cat::getType() const {
    return this->_type;
}

Brain* Cat::getBrain() const {
    return this->brain;
}