#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "../inc/Form.hpp"

class ShrubberyCreationForm : public Form
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

        void executeAction() const;

    private:
};

#endif