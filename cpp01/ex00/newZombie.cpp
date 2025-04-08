#include "Zombie.hpp"

Zombie *newZombie( std::string s )
{
    return new Zombie(s);
}