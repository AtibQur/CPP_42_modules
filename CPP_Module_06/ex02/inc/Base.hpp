#pragma once

class Base
{
    private:

    public:
        virtual ~Base();

        Base* generate(void);
        void identify(Base* p);
        void identify(Base& p);
};

    class BaseA : public Base {};
    
    class BaseB : public Base {};
    
    class BaseC : public Base {};
