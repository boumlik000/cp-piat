#include "Form.hpp"

Form::Form()
 :name_form("undef"),grade_signed_form(22),grade_exec_form(44),signedForm(false)
{
    std::cout << "default constructor Form" << std::endl;
}
Form::Form(std::string const f_name, int const f_grade_s, int const f_grade_ex)
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

Form::Form(const Form& obj)
:name_form(obj.name_form),grade_signed_form(obj.grade_signed_form),grade_exec_form(obj.grade_exec_form),signedForm(obj.signedForm)
{
    std::cout << "copy constructor Form" << std::endl;
}

Form& Form::operator=(const Form& obj)
{
    std::cout << "operator constructor Form" << std::endl;
    if (this != &obj)
        this->signedForm = obj.signedForm;
    return *this;
}

std::string Form::getNameForm()
{
    return this->name_form;
}

int Form::getExecute()
{
    return this->grade_exec_form;
}

int Form::getGradeSigned()
{
    return this->grade_signed_form;
}


const char*  Form::GradeTooHightException::what() const throw()
{
    return "form grade is too hight (Grade must be between 1 and 150)";
}
const char*  Form::GradeTooLowException::what() const throw()
{
    return "form grade is too low (Grade must be between 1 and 150)";
}

void Form::beSigned(Bureaucrat& b)
{

    if (b.getGrade() < this->grade_signed_form)
    {
        this->signedForm = true;
    }
}

bool Form::isSigned() const
{
    return this->signedForm;
}

Form::~Form()
{
    std::cout << "Deconstructor Form" << std::endl;
}

std::ostream& operator<<(std::ostream& os, Form& form)
{
    os << "Form Name: " << form.getNameForm() << ", Grade to sign: " 
       << form.getGradeSigned() << ", Grade to execute: " 
       << form.getExecute() << ", Signed: " 
       << (form.isSigned() ? "Yes" : "No") << std::endl;
    return os;
}

