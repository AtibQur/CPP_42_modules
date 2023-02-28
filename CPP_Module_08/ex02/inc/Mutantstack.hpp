#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>


template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        // Default constructor
        MutantStack() : std::stack<T>() {}
        // Copy constructor
        MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
        // Assignement operator
        MutantStack& operator=(const MutantStack<T>& other) {
            std::stack<T>::operator=(other);
            return *this; 
        }
        // Destructor
        ~MutantStack() {}

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin() { return std::stack<T>::c.begin(); }
        iterator end() { return std::stack<T>::c.end(); }

};

#endif
