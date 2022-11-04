#include "../inc/Brain.hpp"

Brain::Brain() {
    std::cout << "Brain: has been created with constructor" << std::endl;
}

Brain::Brain(const Brain& other) {
    *this = other;
    std::cout << "Brain: Copy has been made" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain: destructed" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    for(int i = 0; i < Brain::ideasN; i++)
        this->_ideas[i] = other._ideas[i];
    std::cout << "Brain: copy assignement operator" << std::endl;
    return *this;
}