#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <numeric>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
    private:
        std::vector<int>data_;
        unsigned int size_;

    public:
        Span(unsigned int N);
        ~Span();

        int shortestSpan();
        int longestSpan();
        void addNumber(int val);

    // exceptions
    class FullSpanException : public std::exception {
        public:
            const char* what() const throw();
    };

    class NoSpanException : public std::exception {
        public:
            const char* what() const throw();
    };
};

#endif
