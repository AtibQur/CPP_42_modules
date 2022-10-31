#ifndef DOG_HPP
#define DOG_HPP

#include "../inc/Animal.hpp"

class Dog : virtual public Animal
{
    public:
        Dog();
        Dog(const Dog& other);
        ~Dog();
        
        Dog& operator=(const Dog& other);

        void    makeSound() const;
        const   std::string& getType() const;
};

#endif