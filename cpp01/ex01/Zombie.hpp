#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>


class Zombie
{
    std::string name;
    public:
        Zombie(){}
        void announce();
        void setname(std::string nameZ);

        ~Zombie()
        {
            std::cout << name << " is dead" << std::endl;
        }
};

Zombie* zombieHorde( int N, std::string name );

#endif