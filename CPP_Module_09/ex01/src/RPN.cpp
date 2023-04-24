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

    if (!checkAmount(input)) {
        std::cout << "Error: Invalid amount of numbers and operators." << std::endl;
        exit(1);
    }
    while(std::getline(ss, token,  ' ')) {
        if (token.empty())
            return ;
        if (token[1] != '\0') {
            std::cout << "Error: Invalid number." << std::endl;
            return ;
        }

        if (isdigit(token[0])) {
            this->_stack.push(std::stod(token));
            i = 1;
        } else {
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
    if (_stack.size() == 1)
        std::cout << _stack.top() << std::endl;
    else
        std::cout << "error" << std::endl;
}

bool RPN::checkAmount(std::string input) {
    int i = 0;
    int j = 0;
    int isTwo = 0;
    std::stringstream ss(input);
    std::string token;

    while(std::getline(ss, token,  ' ')) {
        if (isdigit(token[0]) && ss.eof())
            return false;
        if (isdigit(token[0])) {
            i++;
            isTwo++;
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (isTwo < 2)
                return false;
            j++;
        } else {
            std::cout << "Error: Invalid number or operator." << std::endl;
            exit(1);
        }
    }
    if (i - j != 1) {
        std::cout << "Error: Invalid amount of numbers and operators." << std::endl;
        exit(1);
    }
    return true;
}
