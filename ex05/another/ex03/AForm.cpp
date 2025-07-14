#include "AForm.hpp"

AForm::AForm()
 :name_form("undef"),grade_signed_form(22),grade_exec_form(3),signedForm(false)
{
    std::cout << "default constructor Form" << std::endl;
}
AForm::AForm(std::string const f_name, int const f_grade_s, int const f_grade_ex)
    :name_form(f_name),grade_signed_form(f_grade_s),grade_exec_form(f_grade_ex),signedForm(false)
{
    std::cout << "Parametred constructor Form" << std::endl;
    if ((f_grade_s > 150) || (f_grade_ex > 150))
    {
        throw GradeTooLowException();
    }
    if ( (f_grade_s < 1)|| (f_grade_ex < 1) )
    {
        throw GradeTooHightException();
    } 
}

AForm::AForm(const AForm& obj)
:name_form(obj.name_form),grade_signed_form(obj.grade_signed_form),grade_exec_form(obj.grade_exec_form),signedForm(obj.signedForm)
{
    std::cout << "copy constructor Form" << std::endl;
}

AForm& AForm::operator=(const AForm& obj)
{
    std::cout << "operator constructor Form" << std::endl;
    if (this != &obj)
        this->signedForm = obj.signedForm;
    return *this;
}

std::string AForm::getNameForm() const
{
    return this->name_form;
}

int AForm::getExecute() const
{
    return this->grade_exec_form;
}

int AForm::getGradeSigned() const
{
    return this->grade_signed_form;
}


const char*  AForm::GradeTooHightException::what() const throw()
{
    return "form grade is too hight (Grade must be between 1 and 150)";
}
const char*  AForm::GradeTooLowException::what() const throw()
{
    return "form grade is too low ";
}
const char*  AForm::FormNotSignedException::what() const throw()
{
    return "form nor signed";
}

void AForm::beSigned(Bureaucrat& b)
{

    if (b.getGrade() <= this->grade_signed_form)
    {
        this->signedForm = true;
    }
    else
    {
        throw GradeTooLowException();
    }
}
bool AForm::isSigned() const
{
    return this->signedForm;
}
std::ostream& operator<<(std::ostream& os, AForm& form)
{
    os << "Form Name: " << form.getNameForm() << ", Grade to sign: " 
       << form.getGradeSigned() << ", Grade to execute: " 
       << form.getExecute() << ", Signed: " 
       << (form.isSigned() ? "Yes" : "No") << std::endl;
    return os;
}

AForm::~AForm()
{
    std::cout << "Deconstructor Form" << std::endl;
}



