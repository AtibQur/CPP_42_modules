#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "../inc/Form.hpp"

class PresidentialPardonForm : public Form
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        
        void executeAction() const;
    private:
};

#endif