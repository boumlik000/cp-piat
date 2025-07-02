#include <iostream>
#include <cstring>
#include <cmath>



int main()
{
    double x ;
    std::cout << "ara chi double : ";
    std::cin >> x;
    try
    {
        if (x < 0.0)
            throw "we bneed positive number not a negative one !";
        if (x > 10)
            throw "we bneed  number mabin one  and  10!";
        
        std::cout << "The sqrt of " << x << " is " << std::sqrt(x) << '\n';
    }
    catch(const char* e)
    {
        std::cerr << "Error :" << e <<  '\n';
    }
    

    
    return 0;
}
