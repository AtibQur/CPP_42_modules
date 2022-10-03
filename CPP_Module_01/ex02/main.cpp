#include <iostream>

int main(void) {
    std::string str = "HI THIS IS BRAIN!!!";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    
    // print all adresses from variables
    std::cout << "Adress of string 'str': " << &str << std::endl;
    std::cout << "Adress of 'stringPTR': " << stringPTR << std::endl;
    std::cout << "Adress of 'stringREF': " << &stringREF << std::endl;
    std::cout << std::endl;

    // print all values from variables
    std::cout << "Value of string 'str': " << str << std::endl;
    std::cout << "Value of string 'stringPTR': " << *stringPTR << std::endl;
    std::cout << "Value of string 'stringREF': " << stringREF << std::endl;

    return (0);
}