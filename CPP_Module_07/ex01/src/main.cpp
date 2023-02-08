#include "../inc/iter.hpp"

#include <iostream>

void increment(int &element) {
    element++;
}

void toLower(char &element) {
    element = std::tolower(element);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "========= TEST INTEGER ARRAY=========" << std::endl;
    iter(arr, length, increment);
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << std::endl;
    }

    char strArr[] = {'A', 'B', 'C', 'D', 'E'};
    int lengthArr = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "========= TEST CHAR ARRAY =========" << std::endl;
    iter(strArr, lengthArr, toLower);
    for (int i = 0; i < lengthArr; i++) {
        std::cout << strArr[i] << std::endl;
    }
    std::cout << "===================================" << std::endl;
}
