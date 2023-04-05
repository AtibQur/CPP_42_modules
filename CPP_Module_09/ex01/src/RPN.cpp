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

  // Print out the result
  std::cout << _stack.top() << std::endl;
}

