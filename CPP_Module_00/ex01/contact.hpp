#include <iostream>

class Contact
{
    public:
        Contact();
        void    InitContacts(void);
        void    SearchContacts(void);
        void    ViewContact(int i);
        void    ShowContacts(int i);
        void    Truncate(std::string str);

    private:
        std::string	FirstName;
        std::string	LastName;
        std::string	NickName;
        std::string	PhoneNumber;
        std::string	DarkestSecret;
};
