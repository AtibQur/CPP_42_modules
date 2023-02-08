#include "../inc/Base.hpp"

void	check_leaks() {
	system ("leaks -q base");
}

int main() {
    atexit(check_leaks);
    std::cout << "============================================" << std::endl;
    std::cout << "CREATING RANDOM BASE OBJECTS" << std::endl;
    Base* baseA = generate();
    identify(baseA);
    identify(*baseA);

    std::cout << std::endl;

    Base* baseB = generate();
    identify(baseB);
    identify(*baseB);

    std::cout << std::endl;

    Base* baseC = generate();    
    identify(baseC);
    identify(*baseC);

    delete baseA;
    delete baseB;
    delete baseC;
    std::cout << "============================================" << std::endl;
}
