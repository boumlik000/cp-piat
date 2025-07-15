#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat b1("mohamed" , 0);
        b1.gradeUp();
        std::cout << b1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
