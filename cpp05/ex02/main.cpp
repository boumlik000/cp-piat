#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

    try
    {
        std::cout << "=== Creating Bureaucrats ===" << std::endl;

        Bureaucrat* gardener = new Bureaucrat("Alice", 137);
        Bureaucrat* engineer = new Bureaucrat("Bob", 44);
        Bureaucrat* president = new Bureaucrat("Charlie", 4);
        
        std::cout << "\n=== Creating Forms ===" << std::endl;

        ShrubberyCreationForm* gardenForm = new ShrubberyCreationForm("MyGarden");
        RobotomyRequestForm* robotForm = new RobotomyRequestForm("Target-X1");
        PresidentialPardonForm* pardonForm = new PresidentialPardonForm("Criminal-42");
        
        std::cout << "\n=== Signing Forms ===" << std::endl;

        gardener->signForm(*gardenForm);
        engineer->signForm(*robotForm);
        president->signForm(*pardonForm);
        
        std::cout << "\n=== Status Form ===" << std::endl;

        std::cout << *gardenForm;
        std::cout << *robotForm;
        std::cout << *pardonForm;
        
        std::cout << "\n=== Executing Forms ===" << std::endl;
        
        gardener->executeForm(*gardenForm);
        std::cout << "---" << std::endl;
        engineer->executeForm(*robotForm);
        std::cout << "---" << std::endl;
        president->executeForm(*pardonForm);
        
        std::cout << "\n=== Ewa baraka :) ===" << std::endl;
        
        delete gardener;
        delete engineer;
        delete president;
        delete gardenForm;
        delete robotForm;
        delete pardonForm;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}
