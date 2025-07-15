#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>

class Bureaucrat;


class AForm
{
    std::string const name_form;
    int const grade_signed_form;
    int const grade_exec_form;
    bool signedForm;
    public:
        AForm();
        AForm(std::string const f_name, int const f_grade_s, int const f_grade_ex);
        AForm(const AForm& obj);
        AForm& operator=(const AForm& obj);
        std::string getNameForm() const ;
        int getGradeSigned() const;
        int getExecute() const;
        void beSigned(Bureaucrat& b);
        bool isSigned() const;
        virtual void execute(Bureaucrat const &executor) const = 0;
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
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        virtual ~AForm();
};

std::ostream& operator<<(std::ostream& os, AForm& form);


#endif // !FORM_HPP