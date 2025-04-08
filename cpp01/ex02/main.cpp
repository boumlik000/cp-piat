#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Address in memory of the string: " << &str << std::endl;
    std::cout << "Address in memory of the stringPTR: " << &stringPTR << std::endl;
    std::cout << "Address in memory of the stringREF: " << &stringREF << std::endl;

    std::cout << "Value of the string: " << str << std::endl;
    std::cout << "Value of the stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value of the stringREF: " << stringREF << std::endl;


    return 0;

}