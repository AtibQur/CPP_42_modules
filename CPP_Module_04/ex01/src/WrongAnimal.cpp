#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->_type = "WrongAnimal";
    
    std::cout << "WrongAnimal: created with default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    *this = other;
    
    std::cout << "WrongAnimal: created with copy constructor." << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal: default destructor." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    this->_type = other._type;
    std::cout << this->_type << " has been created with copy assignement operator." << std::endl;
    return *this;
}

void    WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound: BOOOOOO AAAAA ZZZZ FAFADJLFNAD!!!" << std::endl;
}

const std::string& WrongAnimal::getType() const {
    return this->_type;
}