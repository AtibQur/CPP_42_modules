#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe::~PmergeMe() {
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    (void)other;
    return *this;
}

void PmergeMe::checkInput(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        bool isNum = true;
        for (int j = 0; argv[i][j] != '\0'; ++j) {
            if (!std::isdigit(argv[i][j]) || std::stoi(argv[i]) < 0) {
                isNum = false;
                throw wrongInput();
            }
        }
    }
}

void PmergeMe::initNums(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        int num = std::stoi(argv[i]);
            this->intVec.push_back(num);
            this->intList.push_back(num);
    }
}

void PmergeMe::printNums() {
    std::cout << "VECTOR BEFORE | ";
    for (std::vector<int>::iterator it = intVec.begin(); it != intVec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "|" << std::endl;
    std::sort(intVec.begin(), intVec.end());
    
    std::cout << "*VECTOR AFTER | ";
    for (std::vector<int>::iterator it = intVec.begin(); it != intVec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "|" << std::endl;

    std::cout << "LIST   BEFORE | ";
    for (std::list<int>::iterator it = intList.begin(); it != intList.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "|" << std::endl;
    intList.sort();
    std::cout << "*LIST   AFTER | ";
    for (std::list<int>::iterator it = intList.begin(); it != intList.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "|" << std::endl;
}
