#include "../inc/Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span v1 = Span(15000);
    try {
        v1.addMore(12000);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << v1.shortestSpan() << std::endl;
    std::cout << v1.longestSpan() << std::endl;

    return 0;
}
