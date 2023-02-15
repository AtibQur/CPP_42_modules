#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>  
#include <vector>

class notFoundException: public std::exception
{
    public:
        const char* what() const throw() {
            return "Number not found.";
        }
};

template<typename T>
typename T::iterator easyfind(T& container, int n) {
    typename T::iterator it;
    it = find(container.begin(), container.end(), n);
    if (it == container.end())
        throw notFoundException();
    return it;
}
#endif
