#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template<typename T>
class Array
{
    private:
        T*           elements;
        unsigned int _size;

    public:
        Array() : _size(0), elements(NULL) {
            std::cout << "Empty array created with size: " << _size << std::endl;
        }

        Array(unsigned int n) : _size(n) {
            std::cout << "Array created with size: " << _size << std::endl;
            elements = new T[n];
        }

        Array(const Array& arr) : _size(arr._size) {
            elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                elements[i] = arr.elements[i];
            }
        }

        Array& operator=(const Array& arr) {
            if (this == arr) {
                delete[] elements;
                _size = arr._size;
                elements = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    elements[i] = arr.elements[i];
                }
            }
            return *this;
        }

        ~Array() {
            delete[] elements; 
        }

        T& operator[](unsigned int i) {
            if (i >= _size)
                throw std::out_of_range("Index out of bound");
            return elements[i];
        }

        unsigned int size() const {
            return _size;
        }
};

#endif
