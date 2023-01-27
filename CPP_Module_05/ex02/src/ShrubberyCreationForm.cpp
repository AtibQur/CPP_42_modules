#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form::Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form(other)
{
	this->_target = other._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
		throw ShrubberyCreationForm::UnsignedFormException();
	if (executor.getGrade() > this->getExecGrade())
        throw Bureaucrat::GradeTooLowException();

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
