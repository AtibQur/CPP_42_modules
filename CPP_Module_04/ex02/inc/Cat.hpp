#ifndef CAT_HPP
#define CAT_HPP

#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& other);
        ~Cat();
        
        Cat& operator=(const Cat& other);

        void makeSound() const;

        const std::string& getType() const;
        Brain* getBrain() const;

        private:
            Brain* brain;
};

#endif