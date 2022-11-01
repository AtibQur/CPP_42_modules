#ifndef CAT_HPP
#define CAT_HPP

#include "../inc/Animal.hpp"

class Cat : virtual public Animal
{
    public:
        Cat();
        Cat(const Cat& other);
        ~Cat();
        
        Cat& operator=(const Cat& other);

        virtual void    makeSound() const;
        const   std::string& getType() const;
};


#endif