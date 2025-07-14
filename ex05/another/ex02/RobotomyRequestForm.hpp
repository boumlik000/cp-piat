#ifndef ROBOTO_HPP
#define ROBOTO_HPP

#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
    std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& obj);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
        ~RobotomyRequestForm();
        
        RobotomyRequestForm(std::string target);
        void execute(Bureaucrat const & executor) const;

};


#endif // !ROBOTO
