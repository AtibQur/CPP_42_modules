#include <iostream>

class Contact
{
    public:
        Contact();
        void InitContacts(void);
        void SearchContacts(void);

    private:
        std::string	FirstName;
        std::string	LastName;
        std::string	NickName;
        std::string	PhoneNumber;
        std::string	DarkestSecret;
};
