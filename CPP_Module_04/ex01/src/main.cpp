#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Brain.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;


    delete j;//should not create a leak
    delete i;

    return 0;
}