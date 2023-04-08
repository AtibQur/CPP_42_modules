#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {
    std::cout << "PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    std::cout << "PmergeMe copy constructor called" << std::endl;
    *this = other;
}

PmergeMe::~PmergeMe() {
    std::cout << "PmergeMe destructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    std::cout << "PmergeMe assignation operator called" << std::endl;
    return *this;
}

