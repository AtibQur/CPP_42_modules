#include "../inc/Cat.hpp"

Cat::Cat() {
    this->_type = "Cat";

    std::cout << "Cat: created with default constructor." << std::endl;
}

Cat::Cat(const Cat& other) {
    *this = other;

    std::cout << "Cat: created with copy constructor" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat: default destructor." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    this->_type = other._type;
    std::cout << this->_type << " has been created with the copy and assignment operator" << std::endl;
    return *this;
}

void    Cat::makeSound() const {
    std::cout << "meow, mow, mrow, mrrr, prr, prrt, hh, mrrrrrrrrrrawr, mew, rrrr, e-e-e-e-e-e" << std::endl;
}

const std::string& Cat::getType() const {
    return this->_type;
}