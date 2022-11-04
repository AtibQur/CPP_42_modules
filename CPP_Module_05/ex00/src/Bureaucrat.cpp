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

std::ostream& operator<<(std::ostream &out, const Bureaucrat &c) {
    out << c.getName();
    out << ", bureaucrat grade " << c.getGrade() << '.';
    return out;
}