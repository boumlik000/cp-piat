#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(/* args */)
{
    std::cout << "default Constructor" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "DeConstructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name,int grade)
    :name(name) ,grade(grade)
{
    std::cout << "Parametred Constuctor" << std::endl;
    if (this->grade < 1 || this->grade > 150)
    {
        throw Outofrange();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name), grade(obj.grade)
{
    std::cout << "copy Constuctor" << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) 
{
    std::cout << "operator called" << std::endl;
    if(this != &obj)
        this->grade = obj.grade;
    return *this;
}

int Bureaucrat::get_grade()
{
    return grade;
}
std::string Bureaucrat::get_name()
{
    return name;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! (Grade must be between 1 and 150)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! (Grade must be between 1 and 150)";
}

const char* Bureaucrat::Outofrange::what() const throw() {
    return "(Grade must be between 1 and 150)";
}



void Bureaucrat::gradeUP()
{

    if (this->grade == 1)
    {
        throw GradeTooHighException();
    }
    else
        this->grade--;  
}
void Bureaucrat::gradeDown()
{
        if (this->grade == 150)
        {
            throw GradeTooLowException();
        }
        else
            this->grade++;
}
std::ostream& operator<<( std::ostream& os,  Bureaucrat& obj)
{
    os << "Burocrate name : " << obj.get_name() << " and it' s grade : "<< obj.get_grade() << std::endl;
    return os;
}
