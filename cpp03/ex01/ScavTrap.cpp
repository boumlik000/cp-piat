#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
    std::cout  << "Default Constructor ScavTrap called ScavTrap" << std::endl ;
    this->hit = 100;
    this->energy = 50;
    this->attack = 20; 
}
ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
    std::cout  << "parametred Constructor ScavTrap called ScavTrap" << std::endl ;
    this->hit = 100;
    this->energy = 50;
    this->attack = 20;   
}
ScavTrap::ScavTrap(const ScavTrap& obj): ClapTrap(obj)
{
    std::cout <<  "copy Constructor called ScavTrap" << std::endl ;
    *this=obj;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    std::cout << "assignement operator called ScavTrap" << std::endl ;
    if (this != &obj)
        ClapTrap::operator=(obj);
    return *this;
}

void ScavTrap::Attack(const std::string& target)
{  
    if (energy <= 0 || hit <= 0)
        std::cout << this->name << " can't attack,or repair itself. energy points are not enough" << std::endl ;
    else
    {
        energy -= 1;
        std::cout << "ScavTrap " << this->name  << " attack " << target
            << " causing " << attack << " damage" << std::endl;
        std::cout << "energy remains " << this->energy << " to " << this->name << std::endl;
        std::cout << "hit remains " << this->hit << " to " << this->name << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << " ScavTrap is now in Gatekeeper mode." << std::endl;
}


ScavTrap::~ScavTrap()
{
    std::cout  << "Deconstructor ScavTrap called " << std::endl ;
}