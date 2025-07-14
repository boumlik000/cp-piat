#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "Aform.hpp"

class PresidentialPardonForm : public Aform
{

    std::string target;
    public:
        PresidentialPardonForm(/* args */);
        PresidentialPardonForm(const PresidentialPardonForm& obj);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
        ~PresidentialPardonForm();

        PresidentialPardonForm(const std::string& target);
        void execute(Bureaucrat const &executor) const;
};

PresidentialPardonForm::PresidentialPardonForm()
 : Aform("PresidentialPardonForm",25,5),target("Undef")
{
    std::cout << "Presidential default parameter";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
    if (this != &obj) {
        Aform::operator=(obj);
        this->target = obj.target;
    }
    return *this;
    std::cout << "Presidential operator parameter";
    
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : Aform(obj)
{
    *this = obj;
    std::cout << "Presidential copy constructor parameter";
    
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : Aform("PresidentialPardonForm",25,5),target("Undef")
{


}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    
}


PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential deconstructor parameter";
}


#endif // !PRESIDENTIALPARDONFORM
