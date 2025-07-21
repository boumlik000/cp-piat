#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b1("mohamed" , 0);
    try
    {
        b1.gradeUp();
        std::cout << b1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
