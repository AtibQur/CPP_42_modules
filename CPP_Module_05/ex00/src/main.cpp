#include "../inc/Bureaucrat.hpp"

int main() {
    Bureaucrat *Atib = new Bureaucrat("Atib", 15);
    try {
        std::cout << *Atib << std::endl;
        Atib->decrement();
        Atib->decrement();
        Atib->decrement();
        std::cout << *Atib << std::endl;
        Atib->decrement(15);
        std::cout << *Atib << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    delete Atib;

    std::cout << std::endl;

    Bureaucrat *Bie = new Bureaucrat("Bie", 140);
    try {
        std::cout << *Bie << std::endl;
        Bie->increment();
        Bie->increment();
        Bie->increment();
        std::cout << *Bie << std::endl;
        Bie->increment(10);
        std::cout << *Bie << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    delete Bie;
    Bureaucrat *test = new Bureaucrat("YO", 1);

    return 0;
}