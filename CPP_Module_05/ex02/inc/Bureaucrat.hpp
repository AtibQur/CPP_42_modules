#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "../inc/Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& other);

        std::string getName() const;
        int getGrade() const;

        void increment();
        void decrement();
        void increment(int num);
        void decrement(int num);

        void checkGrade(int grade);
        void signForm(Form& form);

        void executeForm(const Form& form) const;

    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };

    private:
        const std::string _name;
        int _grade;
};

    std::ostream& operator<<(std::ostream &out, const Bureaucrat &c);

#endif
