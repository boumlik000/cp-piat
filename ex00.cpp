#include <iostream>


int main(int ac,char **av)
{
    if(ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    int i = 0;
    int j = 1;

    while (j < ac)
    {
        while (av[j][i])
        {
            av[j][i] = std::toupper(av[j][i]);
            i++;
        }
        std::cout << av[j];
        if (j < ac -1)
            std::cout << " ";
        j++;
    }
    std::cout << std::ends;
    
    
    return 0;
}
