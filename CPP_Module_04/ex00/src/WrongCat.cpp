#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() {
    this->_type = "WrongCat";

    std::cout << "WrongCat: created with default constructor." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
    *this = other;

    std::cout << "WrongCat: created with copy constructor." << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat: default destructor." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    this->_type = other._type;
    std::cout << this->_type << " has been created with the copy and assignment operator" << std::endl;
    return *this;
}

void    WrongCat::makeSound() const {
    std::cout << "WrongCat: meow, mow, mrow, meooow" << std::endl;
}

const std::string& WrongCat::getType() const {
    return this->_type;
}