#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP


#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    std::string  _target ;
    public:
        ShrubberyCreationForm(/* args */);
        ShrubberyCreationForm(const ShrubberyCreationForm& obj);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(const std::string target);
        void execute(Bureaucrat const & executor) const;
};




#endif // !SHRUBBERY_CREATION_FORM_HPP