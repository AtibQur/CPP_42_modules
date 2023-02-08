#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
    private:
        T*           elements;
        unsigned int size;

    public:
        Array() : size(0), elements(nullptr) {}

        Array(unsigned int n) : size(n) {
            elements = new T[n];
        }

        ~Array();
};

#endif
