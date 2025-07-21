#include "form.hpp"

form::form(/* args */)
    :form_name("undef") ,grade_form(0),exec_form(0),signed_form(false)
{
    std::cout << "default constructor Form" << std::endl;
}
form::form(const std::string f_name,const int f_grade,const int f_exec)
    :form_name(f_name) ,grade_form(f_grade),exec_form(f_exec),signed_form(false)
{
    std::cout << "Parametred Constuctor" << std::endl;
    if (this->grade_form < 1)
    {
        throw GradeTooHighException();
    }
    else if (this->grade_form > 150)
    {
        throw GradeTooLowException();
    }
}

form::form(const form& obj) 
 :form_name(obj.form_name),grade_form(obj.grade_form),exec_form(obj.exec_form),signed_form(obj.signed_form)
{
    std::cout << "copy Constuctor Form" << std::endl;
}
form& form::operator=(const form& obj)
{
    std::cout << "operator called Form" << std::endl;
    if(this != &obj)
        this->signed_form=obj.signed_form;
    return *this;
}
const char* form::GradeTooHighException::what() const throw() {
    return "form :Grade is too high! (Grade must be between 1 and 150)";
}

const char* form::GradeTooLowException::what() const throw() {
    return "form :Grade is too low! (Grade must be between 1 and 150)";
}

void form::be_signed(Bureaucrat& pers)
{
    if (pers.get_grade() < this->grade_form)
    {
        if (this->signed_form == false)
        {
            this->signed_form = true;
            pers.signForm();
        }
        else
            std::cout <<  pers.get_name() << " cant sign the form : " << this->form_name <<  " bc its already signed "<< std::endl;
    }
    else
    {
        throw GradeTooLowException();
    }
}
form::~form()
{
    std::cout << "Deconstructor Form" << std::endl;

}
