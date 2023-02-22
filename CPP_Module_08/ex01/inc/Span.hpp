#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
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
        std::vector<int> getValues() const;
        unsigned int getMaxSize() const;

        void addNumber(int val);
        int longestSpan();
        int shortestSpan();

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

};


#endif
