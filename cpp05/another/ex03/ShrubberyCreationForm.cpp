#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(/* args */)
    :AForm("Shrubbery Creation Form", 145, 137),_target("undef")
{
    std::cout << "constructor ShrubberyCreationForm" << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    :AForm("Shrubbery Creation Form", 145, 137),_target(target)
{
    std::cout << "parametred constructor ShrubberyCreationForm" << std::endl; 
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
:AForm(obj),_target(obj._target)
{
    std::cout << "copy constructor ShrubberyCreationForm" << std::endl; 
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj);
        this->_target = obj._target;
    }
    return *this;
}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecute()) {
        throw GradeTooLowException();
    }

    std::ofstream file((_target + "_shrubbery").c_str());
    if(file.is_open()) {
        file << "       _-_\n"
        << "    /~~   ~~\\\n"
        << " /~~         ~~\\\n"
        << "{               }\n"
        << " \\  _-     -_  /\n"
        << "   ~  \\ //  ~\n"
        << "_- -   | | _- _\n"
        << "  _ -  | |   -_\n"
        << "      // \\\\\n"
        << std::endl;
        file.close();
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "destructor ShrubberyCreationForm" << std::endl;
}