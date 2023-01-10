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

    Bureaucrat *foo = new Bureaucrat("Foo", 148);
    try {
        std::cout << *foo << std::endl;
        foo->increment();
        foo->increment();
        std::cout << *foo << std::endl;
        foo->increment();
        std::cout << *foo << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    delete foo;

    /* Normal increment/decrement */
    // Bureaucrat *test = new Bureaucrat("Bas", 5);
    // try {
    //     std::cout << *test << std::endl;
    //     test->increment();
    //     std::cout << *test << std::endl;
    //     test->decrement(4);
    //     std::cout << *test << std::endl;
    // }
    // catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }

    return 0;
}