#include "Base.hpp"


Base* generate(void)
{
    int randomNum = rand() % 3;
    if (randomNum == 0)
    {
        std::cout << "generate A" << std::endl;
        return new A;
    }
    else if (randomNum == 1)
    {
        std::cout << "generate B" << std::endl;
        return new B;
    } 
    else
    {   
        std::cout << "generate C" << std::endl;
        return new C;    
    }
}

int main()
{
    srand(time(0));
    // std::cout << bb << std::endl;
    Base *bb ;
    for (size_t i = 0; i < 10; i++)
    {
        bb = generate();
        std::cout << "with pointer :" ;
        identify(bb);
        std::cout << "with reference :" ;
        identify(*bb);        
    }
    
    return 0;
}
