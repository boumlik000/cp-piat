#include "Whatever.hpp"

int main()
{
    int a =3 , b=6;
    double c =3.2 , d=5.13;
    Swap(a,b);
    std::cout << "a : " <<  a  << " | b : " << b << std::endl;
    std::cout << "min : " <<  min(a,b)   << std::endl;
    std::cout << "max : " <<  max(a,b)   << std::endl;
    std::cout << "-----------------------------" << std::endl;
    Swap(c,d);
    std::cout << "c : " <<  c << " | d : " << d << std::endl;
    std::cout << "min : " <<  min(c,d)   << std::endl;
    std::cout << "max : " <<  max(c,d)   << std::endl;
    std::cout << "-----------------------------" << std::endl;
    Swap(a,b);
    std::cout << "a : " <<  a  << " | b : " << b << std::endl;

    return 0;
}
