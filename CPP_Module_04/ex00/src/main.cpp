#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

void    testWrongAnimals() {
    std::cout << "==============testWrongAnimals()=================" << std::endl;
    const WrongAnimal* animal = new WrongAnimal();
    const WrongAnimal* cat = new WrongCat();
    std::cout << "=================================================" << std::endl;
    std::cout << animal->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << "=================================================" << std::endl;
    animal->makeSound();
    cat->makeSound();
    std::cout << "=================================================" << std::endl;
    delete animal;
    delete cat;
    std::cout << "=================================================" << std::endl;
}

void    testAnimals() {
    std::cout << "==============testAnimals()=================" << std::endl;
    const Animal* animal = new Animal();
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();
    std::cout << "=================================================" << std::endl;
    std::cout << animal->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << "=================================================" << std::endl;
    animal->makeSound();
    cat->makeSound();
    dog->makeSound();
    std::cout << "=================================================" << std::endl;
    delete animal;
    delete cat;
    delete dog;
    std::cout << "=================================================" << std::endl;
}

int main() {
    testAnimals();
    // testWrongAnimals();
    return 0;
}