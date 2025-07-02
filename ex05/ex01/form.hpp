#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class form
{
    const std::string form_name;
    const int grade_form;
    const int exec_form;
    bool signed_form;

    public:
        form(/* args */);
        form(const std::string f_name,const int f_grade,const int f_exec);
        form(const form& obj);
        form& operator=(const form& obj); 
        void be_signed( Bureaucrat& pers);
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        ~form();
};







#endif // !BUREAUCRAT_HPP