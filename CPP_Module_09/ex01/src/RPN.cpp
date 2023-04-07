#include "../inc/RPN.hpp"

RPN::RPN() {
    std::cout << "RPN constructor called" << std::endl;
}

RPN::RPN(RPN const &other) {
    std::cout << "RPN copy constructor called" << std::endl;
    *this = other;
}

RPN &RPN::operator=(RPN const &other) {
    std::cout << "RPN assignation operator called" << std::endl;
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {
    std::cout << "RPN destructor called" << std::endl;
}

void RPN::readInput(std::string input) {
    std::stringstream ss(input);
    std::string token;

    while(std::getline(ss, token,  ' ')) {
        if (isdigit(token[0])) {
            if (_stack.size() > 2) {
                std::cout << "Error. Too many operands." << std::endl;
                return;
            }
            this->_stack.push(std::stod(token));
        } 
        // double firstToken = 
    }


}

