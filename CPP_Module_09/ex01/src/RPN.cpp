#include "../inc/RPN.hpp"

RPN::RPN() {
}

RPN::RPN(RPN const &other) {
    *this = other;
}

RPN &RPN::operator=(RPN const &other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {
}

void RPN::readInput(std::string input) {
    std::stringstream ss(input);
    std::string token;
    int i = 0;

    while(std::getline(ss, token,  ' ')) {
        if (token[1] != '\0') {
            std::cout << "Error: Invalid number." << std::endl;
            return ;
        }
        if (isdigit(token[0])) {
            if (_stack.size() > 2) {
                std::cout << "Error: Too many operands." << std::endl;
                return ;
            }
            this->_stack.push(std::stod(token));
            i = 1;
        } else {
            if (_stack.size() < 2) {
                std::cout << "Error: Too few operands." << std::endl;
                return ;
            }
            double b = _stack.top();
            _stack.pop();
            double a = _stack.top();
            _stack.pop();
            if (token == "+") {
                _stack.push(a + b);
            } else if (token == "-") {
                _stack.push(a - b);
            } else if (token == "*") {
                _stack.push(a * b);
            } else if (token == "/") {
                _stack.push(a / b);
            } else {
                std::cout << "Error: Invalid operator." << std::endl;
                return ;
            }
                i = 0;
        }
    }
    if (i) {
        std::cout << "Error: Can't end with an integer number." << std::endl;
        return ;
    }
    std::cout << _stack.top() << std::endl;
}
