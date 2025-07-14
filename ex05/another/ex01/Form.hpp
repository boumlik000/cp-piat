#ifndef FORM_HPP
#define FORM_HPP





#include "Bureaucrat.hpp"

class Bureaucrat;


class Form
{
    std::string const name_form;
    int const grade_signed_form;
    int const grade_exec_form;
    bool signedForm;
    public:
        Form();
        Form(std::string const f_name, int const f_grade_s, int const f_grade_ex);
        Form(const Form& obj);
        Form& operator=(const Form& obj);
        std::string getNameForm();
        int getGradeSigned();
        int getExecute();
        void beSigned(Bureaucrat& b);
        bool isSigned() const;
        class GradeTooHightException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        ~Form();
};

std::ostream& operator<<(std::ostream& os, Form& form);


#endif // !FORM_HPP