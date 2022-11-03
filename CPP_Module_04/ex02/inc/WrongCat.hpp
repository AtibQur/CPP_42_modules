#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "../inc/WrongAnimal.hpp"

class WrongCat: virtual public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat& other);
        ~WrongCat();

        WrongCat& operator=(const WrongCat& other);

        void    makeSound() const;
        const   std::string& getType() const;
};

#endif