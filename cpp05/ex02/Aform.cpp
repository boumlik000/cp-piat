#include "Aform.hpp"

Aform::Aform(/* args */)
    :Aform_name("undef") ,grade_Aform(0),exec_Aform(0),signed_Aform(false)
{
    std::cout << "default constructor AForm" << std::endl;
}
Aform::Aform(const std::string f_name,const int f_grade,const int f_exec)
    :Aform_name(f_name) ,grade_Aform(f_grade),exec_Aform(f_exec),signed_Aform(false)
{
    std::cout << "Parametred Constuctor" << std::endl;
    if (this->grade_Aform < 1)
    {
        throw GradeTooHighException();
    }
    else if (this->grade_Aform > 150)
    {
        throw GradeTooLowException();
    }
}

Aform::Aform(const Aform& obj) 
 :Aform_name(obj.Aform_name),grade_Aform(obj.grade_Aform),exec_Aform(obj.exec_Aform),signed_Aform(obj.signed_Aform)
{
    std::cout << "copy Constuctor AForm" << std::endl;
}
Aform& Aform::operator=(const Aform& obj)
{
    std::cout << "operator called AForm" << std::endl;
    if(this != &obj)
        this->signed_Aform=obj.signed_Aform;
    return *this;
}
const char* Aform::GradeTooHighException::what() const throw() {
    return "Aform :Grade is too high! (Grade must be between 1 and 150)";
}

const char* Aform::GradeTooLowException::what() const throw() {
    return "Aform :Grade is too low! (Grade must be between 1 and 150)";
}

void Aform::be_signed(Bureaucrat& pers)
{
    if (pers.get_grade() < this->grade_Aform)
    {
        if (this->signed_Aform == false)
        {
            this->signed_Aform = true;
            pers.signForm();
        }
        else
            std::cout <<  pers.get_name() << " cant sign the Aform : " << this->Aform_name <<  " bc its already signed "<< std::endl;
    }
    else
    {
        throw GradeTooLowException();
    }
}
Aform::~Aform()
{
    std::cout << "Deconstructor AForm" << std::endl;

}
