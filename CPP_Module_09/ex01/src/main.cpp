#include "../inc/RPN.hpp"

int main(int argc, char const **argv) {

    if (argc != 2) {
        std::cout << "Error. Only 1 argument is allowed. Try again." << std::endl;
        return 1;
    }

    RPN rpn;
    rpn.readInput(argv[1]);

    return 0;
}
