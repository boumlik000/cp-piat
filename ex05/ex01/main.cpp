#include "form.hpp"

int main()
{
    form f2("form2",100,66);
    Bureaucrat bur0("mohamed",10);
    Bureaucrat bur1("ali",90);
    try
    {
        form f1("form1",151,66);
        bur1.gradeUP();
        f1.be_signed(bur1);

        f1.be_signed(bur0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
