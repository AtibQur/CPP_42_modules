#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) :
    _name(name),
    _grade(grade)
{}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    *this = other;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    this->_grade = other._grade;

    return *this;
}

std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::increment() {
    std::cout << "Increment grade by 1" << std::endl;
    checkGrade(this->_grade++);
}

void Bureaucrat::increment(int N) {
    std::cout << "Increment grade by " << N << std::endl;
    checkGrade(this->_grade + N);
    this->_grade += N;
}

void Bureaucrat::decrement() {
    std::cout << "Decrement grade by 1" << std::endl;
    checkGrade(this->_grade--);
}

void Bureaucrat::decrement(int N) {
    std::cout << "Decrement grade by " << N << std::endl;
    checkGrade(this->_grade - N);
    this->_grade -= N;
}

void Bureaucrat::checkGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException(); 
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Exception: grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Exception: grade is too low";
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &c) {
    out << c.getName();
    out << ", bureaucrat grade " << c.getGrade() << '.';
    return out;
}