#include "PmergeMe.hpp"


bool check_av(char *av)
{
    int i = 0;
    while (av[i])
    {
        if (av[i] == '+')
            i++;
        
        if (!isdigit(av[i]))
        {
            std::cout << av << " is not a digit" << std::endl;
            return false;
        }
        i++;
    }    
    return true;
}



int main(int ac, char *av[])
{
    std::vector<int> vect;
    if (ac == 1)
    {
        std::cerr << "Error : pls enter arguments" << std::endl;
        return 0;
    }
    int i = 1;
    while (i < ac)
    {
        if (!check_av(av[i]))
        {
            std::cerr << "Error : wrong input , only positive numbers" << std::endl;
            return 0;
        }
        int x = atoi(av[i]);
        vect.push_back(x);
        i++;
    }

    std::vector<int>::iterator it;
    for(it = vect.begin(); it != vect.end() ; it++)
    {
        std::cout << "=> " << *it << std::endl;
    }
    
    
    return 0;
}
