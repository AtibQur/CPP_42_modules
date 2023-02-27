#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <iterator>
#include <numeric> // std::adjacent_difference

class Span
{
    private:
        std::vector<int>        _values;
        const unsigned int     _maxSize;

    public:
        // OOCF
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        // GETTERS/SETTERS
        unsigned int getValuesSize() const;
        unsigned int getMaxSize() const;

        void addNumber(int val);
        int longestSpan();
        int shortestSpan();

        void addMore(int val);
        std::vector<int> getRandomVector(int val);
        // EXCEPTIONS
        class FullSpanException : public std::exception
        {
            public:
                const char *what() const throw() { return "Error: Span is full"; }
        };
    
        class NoSpanException : public std::exception
        {
            public:
                const char *what() const throw() { return "Error: Span is empty"; }
        };

        int operator[](unsigned int i) {
            if (i >= _maxSize)
                throw std::out_of_range("Index out of bound");
            return (i);
        }
};


#endif
