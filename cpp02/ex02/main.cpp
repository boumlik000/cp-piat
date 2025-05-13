#include "Fixed.hpp"

int main()
{
    // int i =5;
    // int j =1;
    // std::cout << i++ << std::endl;
    // std::cout << ++j << std::endl;


    Fixed a(15) , b(15);
    Fixed c(2) , d(15.4f);
    std::cout << (++c) << std::endl;
    std::cout << (a++) << std::endl;
    std::cout << (a < b) << std::endl;
    std::cout << (a * b) << std::endl;
    std::cout << (c * d) << std::endl;
    return 0;
}
