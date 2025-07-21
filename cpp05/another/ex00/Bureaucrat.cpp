#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
 :_name("undef") , _grade(0)
{
    std::cout << "default constructor Bureaucrat" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Deconstructor Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name,int grade)
:_name(name) , _grade(grade)
{
    std::cout << "Parametred constructor Bureaucrat" << std::endl;
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    
}


Bureaucrat::Bureaucrat(const Bureaucrat& obj)
    :_name(obj._name),_grade(obj._grade)
{
    std::cout << "copy constructor Bureaucrat" << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    std::cout << "operator constructor Bureaucrat" << std::endl;
    if (this != &obj)
        this->_grade = obj._grade;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
} 

int Bureaucrat::getGrade()
{
    return this->_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too Hight (Grade must be between 1 and 150)" ;
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too Low (Grade must be between 1 and 150)";
}

void Bureaucrat::gradeDown()
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}
void Bureaucrat::gradeUp()
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
}


std::ostream& operator<<(std::ostream& os, Bureaucrat& obj)
{
    os << "Bureaucrat name : " << obj.getName() 
    << " and its grade is : " << obj.getGrade() << std::endl;
    return os; 
}

