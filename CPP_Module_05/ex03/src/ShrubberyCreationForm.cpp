#include <fstream>
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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw ShrubberyCreationForm::UnsignedFormException();
	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	std::ofstream myTrees(this->_target + "_shrubbery");
	myTrees << "	   _-_ "<<  std::endl;
	myTrees << "    /~~   ~~\\"<<  std::endl;
	myTrees << " /~~         ~~\\"<<  std::endl;
	myTrees << "{               }"<<  std::endl;
	myTrees << " \\  _-     -_  /"<<  std::endl;
	myTrees << "   ~  \\ //  ~"<<  std::endl;
	myTrees << "_- -   | | _- _"<<  std::endl;
	myTrees << "  _ -  | |   -_"<<  std::endl;
	myTrees << "      // \\"<<  std::endl;
	myTrees.close();
}
