#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "form.hpp"

class ShrubberyCreationForm
{
private:
    /* data */
public:
    ShrubberyCreationForm(/* args */);
    ShrubberyCreationForm(const ShrubberyCreationForm& obj);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
    ~ShrubberyCreationForm();
};

ShrubberyCreationForm::ShrubberyCreationForm(/* args */)
{
    std::cout << "ShrubberyCreationForm default parameter";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
    std::cout << "ShrubberyCreationForm operator parameter";
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
{
    std::cout << "ShrubberyCreationForm copy constructor parameter";
    
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm deconstructor parameter";
}


#endif // !PRESIDENTIALPARDONFORM
