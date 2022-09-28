#include "contact.hpp"

class PhoneBook
{
    public:
        void add(int i);
        void search();
        void exit();
        
    private:
        Contact contacts[8];
};
