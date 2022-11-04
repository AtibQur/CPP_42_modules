#include "../inc/Bureaucrat.hpp"

int main() {
    Bureaucrat *test = new Bureaucrat("Atib", 5);

    std::cout << *test << std::endl;

    delete test;

    return 0;
}