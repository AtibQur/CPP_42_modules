#include "../inc/Span.hpp"

 Span::Span(unsigned int N) : data_(N), size_(0)
{
    std::cout << "Span constructor made" << std::endl;
}

void Span::addNumber(int val) {
    if (size_ < data_.size()) {
        data_[size_++] = val;
    } else {
        throw Span::FullSpanException(); 
    }
}

Span::~Span() {
    std::cout << "Span destructor called" << std::endl;
}

int Span::shortestSpan() {
    if (data_.size() <= 1)
        throw Span::NoSpanException();
    std::vector<int> tmp = data_;
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
	return (*std::min_element(tmp.begin() + 1, tmp.end()));
}

int Span::longestSpan() {
    if (data_.size() <= 1)
        throw Span::NoSpanException();
    int lowestNum = data_[0];
    int highestNum = data_[0];
    for (unsigned int i = 0; i < size_; i++) {
        if (data_[i] < lowestNum)
            lowestNum = data_[i];
    }
    for (unsigned int i = 0; i < size_; i++) {
        if (data_[i] > highestNum)
            highestNum = data_[i];
    }
    lowestNum = highestNum - lowestNum;
    return lowestNum;
}

const char* Span::FullSpanException::what() const throw() {
    return ("Span is full");
}

const char* Span::NoSpanException::what() const throw() {
    return ("No span size found");
}
