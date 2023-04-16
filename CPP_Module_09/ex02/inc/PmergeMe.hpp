#ifndef PMMERGEME_HPP
#define PMMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>
#include <exception>
#include <iomanip>

class PmergeMe {
 private:
    std::vector<int> intVec;
    std::list<int> intList;
 public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);

    void checkInput(int argc, char **argv);
    void checkDuplicates(int argc, char **argv);
    void initNums(int argc, char **argv);
    void printNums();

    class wrongInput : public std::exception {
        public:
            const char *what() const throw() { return "Input is wrong";}
    };

    class duplicateNum : public std::exception {
        public:
            const char *what() const throw() { return "Duplicated number";}
    };
};

#endif
