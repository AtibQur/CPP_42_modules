#include "../inc/RobotomyRequestForm.hpp"

RobotoMyRequestForm::RobotoMyRequestForm()
    : Form("roboto form", 72, 45, "none")
{}

RobotoMyRequestForm::RobotoMyRequestForm(std::string target)
    : Form("roboto form", 72, 45, target) {
    std::cout << "roboto creation: form created" << std::endl;
}

RobotoMyRequestForm::RobotoMyRequestForm(const RobotoMyRequestForm& other)
    : Form(other.getName(), other.getSignGrade(), other.getExecGrade(), other.getTarget())
{
    *this = other;
    std::cout << "roboto creation: copy form created" << std::endl;
}

RobotoMyRequestForm::~RobotoMyRequestForm()
{}

RobotoMyRequestForm& RobotoMyRequestForm::operator=(const RobotoMyRequestForm& other) {
    std::cout << "roboto creation form: operator assignement" << std::endl;
    if (this == &other) return *this;
    return *this;
}

void RobotoMyRequestForm::executeAction() const {
    std::cout << "*drilling noises*" << std::endl;
    std::srand(std::time(NULL));

    if (std::rand() % 2)
        std::cout << this->getTarget() << " has been robotomized." << std::endl;
    else
        std::cout << this->getTarget() << " has failed" << std::endl;
}
