#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int main()
{
const Animal* animal = new Animal();
const Animal* cat = new Cat();
const Animal* dog = new Dog();
std::cout << std::endl;

std::cout << animal->getType() << " " << std::endl;
std::cout << cat->getType() << " " << std::endl;
std::cout << dog->getType() << " " << std::endl;
std::cout << std::endl;

animal->makeSound();
cat->makeSound();
dog->makeSound();
std::cout << std::endl;

delete animal;
delete cat;
delete dog;

return 0;
}