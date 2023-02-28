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

unsigned int Span::getValuesSize() const {
    return _values.size();
}

unsigned int Span::getMaxSize() const {
    return _maxSize;
}

void Span::addNumber(int val) {
    if (this->_values.size() > this->_maxSize)
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

void Span::addMore(int val) {
    if (this->_values.size() + val > this->_maxSize)
        throw FullSpanException();
    std::vector<int> toAdd = getRandomVector(val);
    std::vector<int>::iterator it;

    for (it = toAdd.begin(); it != toAdd.end(); ++it) {
        this->_values.push_back(*it);
    }
}

static int getRandomNum() {
    return rand();
}

std::vector<int> Span::getRandomVector(int val) {
    std::srand(std::time(0));
    std::vector<int> v(val);
	std::generate_n(v.begin(), val, getRandomNum);
    return v;
}
