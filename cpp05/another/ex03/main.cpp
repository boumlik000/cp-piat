#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{

     try {
        Bureaucrat bureaucrat("Alice", 1);
        Bureaucrat bureaucrat2("SIMO", 79);

        Intern lkatib_l3amm;
        AForm* shrubberyForm = lkatib_l3amm.makeForm("ShrubberyCreationForm", "garden");
        AForm* robotomyForm = lkatib_l3amm.makeForm("RobotomyRequestForm", "Bob");
        AForm* pardonForm = lkatib_l3amm.makeForm("PresidentialPardonForm", "Charlie");

        shrubberyForm->beSigned(bureaucrat);
        robotomyForm->beSigned(bureaucrat);
        pardonForm->beSigned(bureaucrat);

        std::cout << "Executing ShrubberyCreationForm via executeForm:" << std::endl;
        bureaucrat.executeForm(*shrubberyForm);

        std::cout << "Executing RobotomyRequestForm via executeForm:" << std::endl;
        bureaucrat.executeForm(*robotomyForm);

        std::cout << "Executing PresidentialPardonForm via executeForm:" << std::endl;
        bureaucrat.executeForm(*pardonForm);

        delete shrubberyForm;
        delete robotomyForm;
        delete pardonForm;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
