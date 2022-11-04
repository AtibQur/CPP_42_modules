#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Brain.hpp"

int main() {

    std::cout << "=============== CREATING ANIMALS ===================" << std::endl;
    std::cout << std::endl;
    Dog* dog = new Dog();
    Cat* cat = new Cat();
    std::cout << std::endl;
    std::cout << "====================================================" << std::endl;

    std::cout << "========== CREATING ANIMALS IDEAS ==================" << std::endl;
    std::cout << std::endl;
    dog->getBrain()->_ideas[0] = "Dog likes playing in the grass.";
    dog->getBrain()->_ideas[1] = "Dog jumps in the water.";
    cat->getBrain()->_ideas[0] = "Cat does not like the dog.";
    cat->getBrain()->_ideas[1] = "Cat wants to be alone.";

    for (int i = 0; i < 2; i++) std::cout << "Dog [" << i << "]: " << dog->getBrain()->_ideas[i] << std::endl;
    for (int i = 0; i < 2; i++) std::cout << "Cat [" << i << "]: " << cat->getBrain()->_ideas[i] << std::endl;
    std::cout << std::endl;
    std::cout << "====================================================" << std::endl;

    std::cout << "====== CREATING NEW DOG WITH DEEP COPY  ============" << std::endl;
    std::cout << std::endl;
    Dog* dog2 = new Dog();
    for (int i = 0; i < 2; i++) std::cout << "Dog2 [" << i << "]: " << dog2->getBrain()->_ideas[i] << std::endl;
    *dog2 = *dog;
    for (int i = 0; i < 2; i++) std::cout << "Dog2 [" << i << "]: " << dog2->getBrain()->_ideas[i] << std::endl;
    dog->getBrain()->_ideas[1] = "Dog does not like water anymore.";
    for (int i = 0; i < 2; i++) std::cout << "Dog [" << i << "]: " << dog->getBrain()->_ideas[i] << std::endl;
    for (int i = 0; i < 2; i++) std::cout << "Dog2 [" << i << "]: " << dog2->getBrain()->_ideas[i] << std::endl;

    std::cout << std::endl;
    std::cout << "====================================================" << std::endl;

    std::cout << "============ DELETING ANIMALS ======================" << std::endl;
    std::cout << std::endl;
    delete dog;//should not create a leak
    delete cat;
    delete dog2;
    std::cout << std::endl;
    std::cout << "====================================================" << std::endl;

    std::cout << "========= Subject HALF CAT/DOG BRAIN ===============" << std::endl;
    std::cout << std::endl;

    const int N = 10;
    Animal *animals[N];
    std::cout << std::endl;

    for (int i = 0; i < N; i++) {
        if (i < N / 2) 
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }
    std::cout << std::endl;

    for (int i = 0; i < N; i++) {
            animals[i]->makeSound();
    }
    std::cout << std::endl;

    for (int i = 0; i < N; i++) {
        delete animals[i];
    }
    std::cout << std::endl;
    std::cout << "====================================================" << std::endl;
    
    //EX02
    // Animal* test = new Animal();
    // test->makeSound();
    // Is not possible because of private default constructor

    return 0;
}

// int main() {
//     main1();
//     system("leaks -q animals");
// }