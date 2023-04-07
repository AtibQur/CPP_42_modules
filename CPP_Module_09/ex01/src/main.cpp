#include "../inc/RPN.hpp"

int main(int argc, char const **argv) {

    if (argc != 2) {
        std::cout << "Error. Only 1 argument is allowed. Try again." << std::endl;
        return 1;
    }
    try {
        RPN rpn;
        rpn.readInput(argv[1]);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
