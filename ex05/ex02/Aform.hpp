#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Aform
{
    const std::string Aform_name;
    const int grade_Aform;
    const int exec_Aform;
    bool signed_Aform;

    public:
        Aform(/* args */);
        Aform(const std::string f_name,const int f_grade,const int f_exec);
        Aform(const Aform& obj);
        Aform& operator=(const Aform& obj); 
        void be_signed( Bureaucrat& pers);
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        ~Aform();
};







#endif // !BUREAUCRAT_HPP