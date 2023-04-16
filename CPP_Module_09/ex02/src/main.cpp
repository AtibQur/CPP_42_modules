#include "../inc/PmergeMe.hpp"

int main(int argc, char **argv) {

    if (argc < 2) {
        std::cerr << "Error: need positive integer sequence as argument."  << std::endl;
        return 1;
    }

    PmergeMe PmergeMe;
    try {
        PmergeMe.checkInput(argc, argv);
        PmergeMe.initNums(argc, argv);
        PmergeMe.printNums();
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    
    return 0;
}
