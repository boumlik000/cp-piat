#include "Intern.hpp"

Intern::Intern(/* args */)
{
    std::cout << "Default constructor INTERN" << std::endl;
}

Intern::Intern(const Intern& obj)
{
    (void)obj;
    std::cout << "copy constructor INTERN" << std::endl;

}

Intern& Intern::operator=(const Intern& obj)
{
    (void)obj;
    return *this;
}

Intern::FormNotFoundException::FormNotFoundException(const std::string &message): msg(message){}

const char* Intern::FormNotFoundException::what() const throw()
{
    return (msg.c_str()); 
}
AForm *Intern::makeForm(const std::string &FormName,const std::string &FormTarget)
{
    std::string Forms[]={"ShrubberyCreationForm","RobotomyRequestForm","PresidentialPardonForm"};
    int i = 0;
    while ((i < 3) && Forms[i] != FormName)
        i++;
    switch (i)
    {
        case 0:
            std::cout << "Intern creates " << FormName << std::endl;
            return new ShrubberyCreationForm(FormTarget);
        case 1:
            std::cout << "Intern creates " << FormName << std::endl;
            return new RobotomyRequestForm(FormTarget);
        case 2:
            std::cout << "Intern creates " << FormName << std::endl;
            return new PresidentialPardonForm(FormTarget);
        default:
            throw FormNotFoundException("Form not found: " + FormName);
            return NULL;
    }
    
}


Intern::~Intern()
{
    std::cout << "Deconstructor INTERN" << std::endl;
}