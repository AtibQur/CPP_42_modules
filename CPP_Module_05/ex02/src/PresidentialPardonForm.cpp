#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : Form("presidential form", 25, 5, "none")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : Form("presidential form", 25, 5, target) {
    std::cout << "presidential creation: form created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : Form(other.getName(), other.getSignGrade(), other.getExecGrade(), other.getTarget())
{
    *this = other;
    std::cout << "presidential creation: copy form created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "presidential creation form: operator assignement" << std::endl;
    if (this == &other) return *this;
    return *this;
}

void PresidentialPardonForm::executeAction() const {
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblerox" << std::endl;
}