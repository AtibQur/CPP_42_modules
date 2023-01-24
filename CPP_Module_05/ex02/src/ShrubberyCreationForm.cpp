#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("shrubbery form", 145, 137, "none")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form("shrubbery form", 145, 137, target) {
    std::cout << "Shrubbery creation: form created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : Form(other.getName(), other.getSignGrade(), other.getExecGrade(), other.getTarget())
{
    *this = other;
    std::cout << "Shrubbery creation: copy form created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "Shrubbery creation form: operator assignement" << std::endl;
    if (this == &other) return *this;
    return *this;
}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream out;

    out.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);
    out << std::endl;
    out << "oxoxoo    ooxoo     " << std::endl;
    out << " ooxoxo oo  oxoxooo " << std::endl;
    out << "oooo xxoxoo ooo ooox" << std::endl;
    out << "oxo o oxoxo  xoxxoxo" << std::endl;
    out << " oxo xooxoooo o ooo " << std::endl;
    out << "   ooo\\oo\\  /o/o    " << std::endl;
    out << "       \\  \\/ /      " << std::endl;
    out << "        |   /       " << std::endl;
    out << "        |  |        " << std::endl;
    out << "        | D|        " << std::endl;
    out << "        |  |        " << std::endl;
    out << "        |  |        " << std::endl;
    out << " ______/____\\____   " << std::endl;
    out.close();
}
