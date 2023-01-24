#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include "../inc/Form.hpp"

class RobotoMyRequestForm : public Form
{
    public:
        RobotoMyRequestForm();
        RobotoMyRequestForm(std::string target);
        RobotoMyRequestForm(const RobotoMyRequestForm& other);
        virtual ~RobotoMyRequestForm();
        RobotoMyRequestForm& operator=(const RobotoMyRequestForm& other);

        void executeAction() const;
    private:
};

#endif