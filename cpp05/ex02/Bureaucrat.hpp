#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
    const std::string name;
    int grade;
    public:
    Bureaucrat(/* args */);
    Bureaucrat(const std:: string& name,int grade);
    Bureaucrat(const Bureaucrat& obj);
    Bureaucrat& operator=(const Bureaucrat& obj);
    
    int get_grade();
    std::string get_name();
    void gradeUP();
    void gradeDown();
    void signForm();
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    ~Bureaucrat();
};

std::ostream& operator<<( std::ostream& os,  Bureaucrat& obj);



#endif // !BUREAUCRAT_HPP