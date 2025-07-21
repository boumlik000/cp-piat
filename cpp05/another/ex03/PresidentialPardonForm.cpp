#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    :AForm("PresidentialPardonForm",25,5),_target("undef")
{
    std::cout << "default constructor PresidentialPardonForm" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target)
:AForm("PresidentialPardonForm",25,5),_target(target)
{
    std::cout << "Parametred constructor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
    :AForm(obj),_target(obj._target)
{
    std::cout << "copy constructor PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
    std::cout << "operator PresidentialPardonForm" << std::endl;
    if (this != &obj)
    {
        AForm::operator=(obj);
        this->_target = obj._target;
    }
    return *this;    
}


PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "deconstructor PresidentialPardonForm" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned())
    {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecute())
    {
        throw GradeTooLowException();
    }
    std::cout << "Informs that " << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    
}
