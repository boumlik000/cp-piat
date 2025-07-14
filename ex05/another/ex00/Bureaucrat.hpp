#ifndef BUREAUCRAT
#define BUREAUCRAT


#include <iostream>
#include <exception>

class Bureaucrat
{
    std::string const _name;
    int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const name,int grade);
        Bureaucrat(const Bureaucrat& obj);
        Bureaucrat& operator=(const Bureaucrat& obj);
        std::string getName() const;
        int getGrade();
        void gradeUp();
        void gradeDown();
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        ~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);



#endif // !BUREAUCRAT