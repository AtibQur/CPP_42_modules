#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(const Animal& other);
        virtual ~Animal();

        Animal& operator=(const Animal& other);
    
        void       makeSound() const;
        const std::string& getType() const;
    protected:
        std::string _type;
};


#endif