#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "../inc/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        const int         _required_sign_grade;
        const int         _required_exec_grade;
        bool              _signed;

    public:
    // OOCF
        Form(const std::string name, int grade, int execute);
        Form(const Form& other);
        ~Form();
        Form& operator=(const Form& other);

    // GETTERS
        std::string getName() const;
        bool        getSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;

    // CHECK GRADE
        void        checkGrade(int grade);
    // SIGN FORM
        void        beSigned(const Bureaucrat& bureaucrat);

    // CHECK EXCEPTIONS
    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };
};

    std::ostream& operator<<(std::ostream &out, const Form &c);

#endif