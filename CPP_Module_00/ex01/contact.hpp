#include <iostream>

class Contact
{
    public:
        Contact();
        void InitContacts(void);
        void SearchContacts(void);
        void ShowContacts(int i);

    private:
        std::string	FirstName;
        std::string	LastName;
        std::string	NickName;
        std::string	PhoneNumber;
        std::string	DarkestSecret;
};