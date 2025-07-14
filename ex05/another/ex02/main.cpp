#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

    try
    {
        std::cout << "=== Creating Bureaucrats ===" << std::endl;
        
        // Create bureaucrats with different grades
        Bureaucrat* gardener = new Bureaucrat("Alice", 137);
        Bureaucrat* engineer = new Bureaucrat("Bob", 44);
        Bureaucrat* president = new Bureaucrat("Charlie", 6);
        
        std::cout << "\n=== Creating Forms ===" << std::endl;
        
        // Create forms dynamically
        ShrubberyCreationForm* gardenForm = new ShrubberyCreationForm("MyGarden");
        RobotomyRequestForm* robotForm = new RobotomyRequestForm("Target-X1");
        PresidentialPardonForm* pardonForm = new PresidentialPardonForm("Criminal-42");
        
        std::cout << "\n=== Signing Forms ===" << std::endl;
        
        // Each bureaucrat signs their own form
        gardener->signForm(*gardenForm);
        engineer->signForm(*robotForm);
        president->signForm(*pardonForm);
        
        std::cout << "\n=== Form Status ===" << std::endl;
        
        // Display form status
        std::cout << *gardenForm;
        std::cout << *robotForm;
        std::cout << *pardonForm;
        
        std::cout << "\n=== Executing Forms ===" << std::endl;
        
        // Each bureaucrat executes their own form
        gardener->executeForm(*gardenForm);
        engineer->executeForm(*robotForm);
        president->executeForm(*pardonForm);
        
        // Clean up memory
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
