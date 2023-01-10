#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) :
    _name(name),
    _grade(grade)
{}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    *this = other;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    this->_grade = other._grade;

    return *this;
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::checkGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void Bureaucrat::increment() {
    std::cout << "Grade has been incremented." << std::endl;
    checkGrade(this->_grade + 1);
    this->_grade += 1;
}

void Bureaucrat::increment(int num) {
    std::cout << "Grade has been incremented by " << num << '.' << std::endl;
    checkGrade(this->_grade + num);
    this->_grade += num;
}

void Bureaucrat::decrement() {
    std::cout << "Grade has been decremented." << std::endl;
    checkGrade(this->_grade - 1);
    this->_grade -= 1;
}

void Bureaucrat::decrement(int num) {
    std::cout << "Grade has been decremented by " << num << '.' << std::endl;
    checkGrade(this->_grade - num);
    this->_grade -= num;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &c) {
    out << c.getName() << " bureaucrat grade " << c.getGrade() << '.';
    return out;
}
