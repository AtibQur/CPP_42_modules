#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form(void);
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form &other);
	Form &operator=(const Form &other);
	virtual ~Form(void);

	const std::string getName(void) const;
	bool getIsSigned(void) const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw() { return "Form grade too high"; }
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw() { return "Form grade too low"; }
	};

private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _execGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif