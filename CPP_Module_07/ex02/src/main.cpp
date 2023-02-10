#include "../inc/Array.hpp"
#include <iostream>

void	check_leaks() {
	system ("leaks -q array");
}

int main(int, char**)
{
    atexit(check_leaks);

    int size = 5;
    Array<int> arrInt(size);
    Array<char> arrChar(size);
    Array<std::string> arrString(size);

    arrInt[0] = 1;
    arrInt[1] = 2;
    arrInt[2] = 3;
    arrInt[3] = 4;
    arrInt[4] = 5;

    arrChar[0] = 'a';
    arrChar[1] = 'b';
    arrChar[2] = 'c';
    arrChar[3] = 'd';
    arrChar[4] = 'e';

    arrString[0] = "Hello";
    arrString[1] = "Hola";
    arrString[2] = "Bonjour";
    arrString[3] = "Annyeong haseyo";
    arrString[4] = "Ohayou";

    std::cout << "=================================" << std::endl;
    std::cout << "========== BASIC TEST ===========" << std::endl;
    std::cout << "=================================" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Array int: " << arrInt[i] << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Array char: " << arrChar[i] << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Array string: " << arrString[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "ArrInt size:    " << arrInt.size() << std::endl;
    std::cout << "ArrChar size:   " << arrChar.size() << std::endl;
    std::cout << "ArrString size: " << arrString.size() << std::endl;
    std::cout << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << "========== COPY TEST ============" << std::endl;
    std::cout << "=================================" << std::endl;
    int* mirror = new int[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        const int value = rand();
        arrInt[i] = value;
        mirror[i] = value;
    }

    for (int i = 0; i < size; i++) {
        std::cout << "· Array  int: " << arrInt[i] << std::endl;
        std::cout << "  Mirror int: " << mirror[i] << std::endl;
    }
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "========= EXCEPTION TEST ===========" << std::endl;
    std::cout << "====================================" << std::endl;
    try
    {
        std::cout << "Array char: " << arrChar[1] << std::endl;
        arrChar[1] = 'S';
        std::cout << "Array char: " << arrChar[1] << std::endl;
        arrChar[-1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    try
    {
        std::cout << "String char: " << arrString[2] << std::endl;
        arrString[2] = "ALOHAAAAA";
        std::cout << "String char: " << arrString[2] << std::endl;
        arrString[-1] = "FAILURE";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "====================================" << std::endl;

    delete[] mirror;
    return 0;
}
