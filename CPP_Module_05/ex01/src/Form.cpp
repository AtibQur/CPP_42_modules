#include "../inc/Form.hpp"

// OOCP
Form::Form(const std::string name, int grade, int execute, std::string& target) :
	_name(name),
	_required_sign_grade(grade),
	_required_exec_grade(execute),
	_signed(false),
	_target(target) {
	checkGrade(_required_exec_grade);
	checkGrade(_required_sign_grade);
}

Form::Form(const Form& other) :
	_name(other._name),
	_required_sign_grade(other._required_sign_grade),
	_required_exec_grade(other._required_exec_grade),
	_signed(other._signed)
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

// EXCEPTIONS
const char* Form::GradeTooHighException::what() const throw() {
    return ("Form: Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Form: Grade is too low");
}

// SIGN FORM
void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() < this->_required_sign_grade) {
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
