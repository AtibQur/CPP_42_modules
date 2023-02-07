#pragma once

#include <iostream>
#include <chrono>
#include <ctime>

class Base
{
    public:
        virtual ~Base();
};

    class BaseA : public Base {};
    
    class BaseB : public Base {};
    
    class BaseC : public Base {};

    Base* generate(void);
    void identify(Base* p);
    void identify(Base& p);
