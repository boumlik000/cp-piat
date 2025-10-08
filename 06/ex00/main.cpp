#include "Convert.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "dont forget to add an arrgument, smt to convert" << std::endl;
    }
    else
    {
        std::cout << "Converting " << av[1] <<std::endl;
        // std::string obj = av[1];
        ScalarConverter::Convert(av[1]);

    }
    return 0;
}
