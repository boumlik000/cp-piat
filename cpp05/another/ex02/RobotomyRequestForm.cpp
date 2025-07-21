#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Roboto my Request Form",72,45),_target("undef")
{
    std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
    : AForm(obj),_target(obj._target)
{
    std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
    
    std::cout << "RobotomyRequestForm operator " << std::endl;
    if (this!= &obj)
    {
        AForm::operator=(obj);        
        this->_target=obj._target;
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
:AForm("Roboto my Request Form",72,45),_target(target)
{
    std::cout << "Parametred constructor RobotomyRequestForm" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm deconstructor" << std::endl;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecute()) {
        throw GradeTooLowException();
    }

    std::cout << "Drilling noises..." << std::endl;

    std::srand(std::time(0));
    if (std::rand() % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    }
    else {
        std::cout << "The robotomy failed." << std::endl;
    }
}
