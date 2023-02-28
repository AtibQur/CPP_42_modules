#include "../inc/Span.hpp"

int main()
{
    std::cout << "==================================================================" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    std::cout << "==================================================================" << std::endl;
    Span spMid = Span(15);
    spMid.addNumber(30);
    spMid.addNumber(60);
    spMid.addNumber(120);
    spMid.addNumber(240);
    spMid.addNumber(480);
    std::cout << "Shortest span: " << spMid.shortestSpan() << std::endl;
    std::cout << "Longest span: " << spMid.longestSpan() << std::endl;
    std::cout << "==================================================================" << std::endl;
    Span v1 = Span(15000);
    try {
        v1.addMore(12000);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Shortest span: " << v1.shortestSpan() << std::endl;
    std::cout << "Longest span: " << v1.longestSpan() << std::endl;
    std::cout << "==================================================================" << std::endl;

    return 0;
}
