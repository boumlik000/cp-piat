#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("mohamed" , 15);
        Bureaucrat b2("Ali" , 12);
        Form f1("Form1", 18,70);
        std::cout << f1;
        b1.signForm(f1);
        b2.signForm(f1);
        b1.gradeUp();
        std::cout << b1;
        std::cout << b2;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
