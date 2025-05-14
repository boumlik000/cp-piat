#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{
    std::cout  << "Default Constructor FragTrap called FragTrap" << std::endl ;
    this->hit = 100;
    this->energy = 100;
    this->attack = 30; 
}
FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
    std::cout  << "parametred Constructor FragTrap called FragTrap" << std::endl ;
    this->hit = 100;
    this->energy = 100;
    this->attack = 30;   
}
FragTrap::FragTrap(const FragTrap& obj): ClapTrap(obj)
{
    std::cout <<  "copy Constructor called FragTrap" << std::endl ;
    *this=obj;
}
FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    std::cout << "assignement operator called FragTrap" << std::endl ;
    if (this != &obj)
    {
        ClapTrap::operator=(obj);
    }
    return *this;
}

void FragTrap::Attack(const std::string& target)
{  
    if (energy <= 0 || hit <= 0)
        std::cout << this->name << " can't attack,or repair itself. energy points are not enough" << std::endl ;
    else
    {
        energy -= 1;
        std::cout << "FragTrap " << this->name  << " attack " << target
            << " causing " << attack << " damage" << std::endl;
        std::cout << "energy remains " << this->energy << " to " << this->name << std::endl;
        std::cout << "hit remains " << this->hit << " to " << this->name << std::endl;
    }
}

void FragTrap::highFivesGuys()
{
    std::cout << "high fives" << std::endl;
}


FragTrap::~FragTrap()
{
    std::cout  << "Deconstructor FragTrap called " << std::endl ;
}