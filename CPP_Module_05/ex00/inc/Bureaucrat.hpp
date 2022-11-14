#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat 
{
    public:
        // OCCP
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();

        Bureaucrat& operator=(const Bureaucrat& other);

        // GETTERS
        std::string getName() const;
        int         getGrade() const;

        // INCREMENT/DECREMENT
        void    increment();
        void    increment(int N);
        void    decrement();
        void    decrement(int N);

        void    checkGrade(int grade);

        // CHECK EXCEPTION
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
        int               _grade;

};
    std::ostream& operator<<(std::ostream &out, const Bureaucrat &c);

#endif