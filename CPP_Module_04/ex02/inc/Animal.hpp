#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        virtual ~Animal();

        Animal& operator=(const Animal& other);
    
        virtual void       makeSound() const;
        const std::string& getType() const;
    protected:
        Animal();
        Animal(const Animal& other);
        std::string _type;
};

#endif