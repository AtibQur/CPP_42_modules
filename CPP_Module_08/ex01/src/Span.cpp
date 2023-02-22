#include "../inc/Span.hpp"

Span::Span() : 
    _maxSize(0) 
{}

Span::Span(unsigned int n) :
    _maxSize(n)
{}

Span::Span(const Span& other) : _maxSize(other._maxSize)
{
    *this = other;
}

Span& Span::operator=(const Span& other) {
    this->_values = other._values;
    return *this;
}

Span::~Span()
{}

void Span::addNumber(int val) {
    if (this->_values.size() >= this->_maxSize)
        throw FullSpanException();
    this->_values.push_back(val);
}

int Span::longestSpan() {
    if (this->_values.size() <= 1)
        throw NoSpanException();
    int max = *max_element(_values.begin(), _values.end());
    int min = *min_element(_values.begin(), _values.end());
    return max - min;
}

int Span::shortestSpan() {
    if (this->_values.size() <= 1)
        throw NoSpanException();
    std::vector<int> temp = this->_values;
    std::sort(temp.begin(), temp.end());
    std::adjacent_difference(temp.begin(), temp.end(), temp.begin());
    return *std::min_element(temp.begin(), temp.end());
}
