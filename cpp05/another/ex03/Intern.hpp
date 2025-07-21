#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"

class AForm;


class Intern
{

    public:
        Intern(/* args */);
        Intern(const Intern& obj);
        Intern& operator=(const Intern& obj);
        ~Intern();
        AForm *makeForm(const std::string &FormName,const std::string &FormTarget);
        class FormNotFoundException : public std::exception
        {
            std::string msg ;
            public:
                FormNotFoundException(const std::string &message);
                virtual const char* what() const throw ();
                virtual ~FormNotFoundException() throw (){}
        };
        
        

};




#endif // !INTERN