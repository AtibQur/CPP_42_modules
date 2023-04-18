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

    // Error management
    void checkInput(int argc, char **argv);
    void checkDuplicates(int argc, char **argv);
    void initNums(int argc, char **argv);

    // Insert sorting Vector
    void insertionSortVec(std::vector<int>& data, int start, int end);
    void mergeVec(std::vector<int>& data, int start, int mid, int end);
    void mergeSortVec(std::vector<int>& data, int start, int end, int k);

    // Insert sorting List
    void	mergeList(std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right);
    void	mergeInsertionSortList(std::list<int>& lst, std::list<int>::iterator left, std::list<int>::iterator right, int k);


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
