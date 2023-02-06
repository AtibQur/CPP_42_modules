#include "../inc/Serialize.hpp"

void	check_leaks() {
	system ("leaks -q convert");
}

int main() {
    atexit(check_leaks);

    Data *data = new Data;
    data->val = "Amazing string";
    uintptr_t uPtr = serialize(data);

    std::cout << "=================================================" << std::endl;
    std::cout << "uPtr adress: " << &uPtr << std::endl;
    std::cout << "data adress: " << &data << std::endl;

    std::cout << std::endl;

    std::cout << "converting data value.." << std::endl;
    std::cout << "uPtr value:  " << uPtr << std::endl;

    std::cout << std::endl;

    data = deserialize(uPtr);
    std::cout << "deserialized value: " << data->val << std::endl;
    std::cout << "=================================================" << std::endl;

    delete data;
}
