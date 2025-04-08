#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>



class Zombie
{
    std::string name;
    public:
    Zombie(std::string nameZ)
        {
            name = nameZ;
        }
        void announce()
        {
            std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
        }
        ~Zombie()
        {
            std::cout << name << " is dead" << std::endl;
        }
};
    
    Zombie *newZombie( std::string s );
    void randomChump( std::string name);
    
#endif // !ZOMBIE_HPP