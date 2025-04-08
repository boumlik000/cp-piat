#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
    {
        std::cerr << "need a number bigger than 0" << std::endl;
        return NULL;
    }
    
    Zombie *z = new Zombie[N];
    int i = 0;
    while (i < N)
    {
        z[i].setname(name);
        z[i].announce();
        i++;
    }
    return z;
}