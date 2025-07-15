#ifndef PRES_HPP
#define PRES_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& obj);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
        ~PresidentialPardonForm();
        
        PresidentialPardonForm(std::string target);
        void execute(Bureaucrat const & executor) const;

};


#endif // !PRES_HPP
