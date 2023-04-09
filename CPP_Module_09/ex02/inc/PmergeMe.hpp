#ifndef PMMERGEME_HPP
#define PMMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <algorithm>

class PmergeMe {
  private:
    std::vector<int> vec;
    std::list<int> lst;
  public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);

};

#endif
