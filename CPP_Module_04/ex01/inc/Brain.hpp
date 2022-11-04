#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
        Brain();
        Brain(const Brain& other);
        ~Brain();

        Brain& operator=(const Brain& other);

        static const int ideasN = 100;
        std::string _ideas[ideasN];
};

#endif