#include "Bureaucrat.hpp"


int main()
{
	Bureaucrat persone("mohamed" ,0);
    try
    {
       //Bureaucrat persone("mohamed" , 0);
        persone.gradeUP();
        std::cout << persone;
        persone.gradeUP();
        std::cout << persone;
        persone.gradeUP();
        std::cout << persone;
        persone.gradeUP();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // catch(Bureaucrat::GradeTooLowException& e)
    // {
    //     std::cerr << "Error :: " << e.what() << '\n';
    // }    
    // catch(Bureaucrat::GradeTooHighException& e)
    // {
    //     std::cerr << "Error :: " << e.what() << '\n';
    // }
    // catch(Bureaucrat::Outofrange& e)
    // {
    //     std::cerr << "Error :: " << e.what() << '\n';
    // }

    return 0;
}
