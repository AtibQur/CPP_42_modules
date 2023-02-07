#include "../inc/Base.hpp"

Base::~Base() {}

Base* generate(void) {
    int randNum = (std::chrono::system_clock::now().time_since_epoch().count() % 3) + 1;
    std::cout << randNum << std::endl;
    if (randNum == 1) {
        std::cout << "Generated BaseA" << std::endl;
        return new BaseA;
    }
    else if (randNum == 2) {
        std::cout << "Generated BaseB" << std::endl;
        return new BaseB;
    }
    else {
        std::cout << "Generated BaseC" << std::endl;
        return new BaseC;
    }
}

// DYNAMIC CASTING
// If the cast is successful, dynamic_cast returns a value of type new-type.
// If the cast fails and new-type is a pointer type, it returns a null pointer of that type. 
// If the cast fails and new-type is a reference type, 
// it throws an exception that matches a handler of type std::bad_cast

void identify(Base* p) {
    BaseA* a = dynamic_cast<BaseA*>(p);
    BaseB* b = dynamic_cast<BaseB*>(p);
    BaseC* c = dynamic_cast<BaseC*>(p);

    if (a)
        std::cout << "*p = A" << std::endl;
    else if (b)
        std::cout << "*p = B" << std::endl;
    else if (c)
        std::cout << "*p = C" << std::endl;
    else
        std::cout << "Not identifiable" << std::endl;
}

void identify(Base& p) {
    try {
        BaseA a = dynamic_cast<BaseA&>(p);
        std::cout << "&p = A" << std::endl;
    } catch (std::exception &e) {}

    try {
        BaseB b = dynamic_cast<BaseB&>(p);
        std::cout << "&p = B" << std::endl;
    } catch (std::exception &e) {}

    try {
        BaseC c = dynamic_cast<BaseC&>(p);
        std::cout << "&p = C" << std::endl;
    } catch (std::exception &e) {}
}
