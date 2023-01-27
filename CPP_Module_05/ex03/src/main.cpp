#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	Form* scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Tender");
	Form* ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Wender");

	Form* nef;
	nef = someRandomIntern.makeForm("not existing form", "Piet");

	std::cout << "\n-------------------------------------------------" << std::endl;
	std::cout << "Test if forms can still be signed and executed:" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	Bureaucrat bob("bob", 5);
	rrf->beSigned(bob);
	scf->beSigned(bob);
	ppf->beSigned(bob);
	bob.executeForm(*rrf);
	bob.executeForm(*scf);
	bob.executeForm(*ppf);
	delete rrf;
	delete scf;
	delete ppf;
	delete nef;
}
