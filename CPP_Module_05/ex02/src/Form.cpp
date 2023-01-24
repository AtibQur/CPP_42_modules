#include "../inc/Form.hpp"

// OOCP
Form::Form() :
	_name("Default"),
	_required_sign_grade(1),
	_required_exec_grade(1),
	_signed(false),
	_target("None")
{}

Form::Form(const std::string name, int grade, int execute, std::string target) :
	_name(name),
	_required_sign_grade(grade),
	_required_exec_grade(execute),
	_signed(false),
	_target(target) {
	checkGrade(_required_exec_grade);
	checkGrade(_required_sign_grade);
	std::cout << "Form created" << std::endl;
}

Form::Form(const Form& other) :
	_name(other._name),
	_required_sign_grade(other._required_sign_grade),
	_required_exec_grade(other._required_exec_grade),
	_signed(other._signed),
	_target(other._target)
{}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
    if (this == &other) return *this;
	return *this;
}

// GETTERS
std::string Form::getName() const {
    return _name;
}

std::string Form::getTarget() const {
	return _target;
}

bool        Form::getSigned() const {
	return _signed;
}

int			Form::getExecGrade() const {
	return _required_exec_grade;
}

int			Form::getSignGrade() const {
	return _required_sign_grade;
}

// CHECKGRADE
void Form::checkGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void Form::beExecuted(const Bureaucrat& Bureaucrat) const {
	if (this->_signed == false) {
		std::cout << Bureaucrat.getName() << " can't execute" << this->_name << std::endl;
		throw Form::NotSigned();
	}
	if (Bureaucrat.getGrade() > this->_required_exec_grade) {
		std::cout << Bureaucrat.getName() << " can't execute " << this->_name << std::endl;
		throw Form::GradeTooLowException();
	}
	std::cout << Bureaucrat.getName() << " has executed " << this->_name << std::endl;
}

// EXCEPTIONS
const char* Form::GradeTooHighException::what() const throw() {
    return ("Form: Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Form: Grade is too low");
}

const char* Form::NotSigned::what() const throw() {
	return ("Form: Could not be signed");
}

// SIGN FORM
void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_required_sign_grade) {
		this->_signed = true;
		std::cout << this->getName() << " has been signed by: " << bureaucrat.getName() << '.' << std::endl;
	} else {
		std::cout << this->getName() << " can't be signed " << bureaucrat.getName() << '.' << std::endl;
		throw Form::GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream &out, const Form &c) {
    out << c.getName();
    return out;
}
