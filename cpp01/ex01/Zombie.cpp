#include "Zombie.hpp"


void Zombie::setname(std::string nameZ)
{
    name = nameZ;
}

void Zombie::announce()
{
    std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

